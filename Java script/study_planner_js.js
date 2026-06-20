<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Study Planner</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <style>
    body { font-family: Arial, sans-serif; background:#f9f9f9; padding:20px; }
    h2 { margin-top:20px; margin-bottom:10px; }
    .section { margin-bottom:20px; }
    table { font-size:14px; }
    canvas { max-width:400px; margin:20px auto; }
  </style>
</head>
<body>
  <div class="container">
    <h1 class="text-center">Study Planner</h1>

    <div id="subjectSection" class="section"></div>
    <div id="moduleSection" class="section"></div>
    <div id="hoursSection" class="section"></div>
    <div id="dateSection" class="section"></div>
    <div id="planSection" class="section"></div>
  </div>

  <script>
    const subjectFiles = {
      "Calculus & Analytical Geometry": null,
      "Chemistry": null,
      "Physics": null,
      "Python": null
    }

    let syllabusData = []

    function makeSubjects() {
      const div = document.getElementById('subjectSection')
      div.innerHTML = '<h2>Select Subjects</h2>'
      Object.keys(subjectFiles).forEach(subj => {
        const id = subj.replace(/\s+/g, '')
        div.innerHTML += `
          <div class="form-check">
            <input class="form-check-input" type="checkbox" value="${subj}" id="${id}">
            <label class="form-check-label" for="${id}">${subj}</label>
            <input type="file" id="file_${id}" accept=".csv" class="form-control form-control-sm mt-1">
          </div>`
      })
      div.innerHTML += '<button class="btn btn-primary mt-3" onclick="loadSubjects()">Next → Modules</button>'
    }

    function cleanCsvColumns(row, subj) {
      let module = row["Module"] || row["module"] || subj
      let topic = row["Topic"] || row["topic"] || module
      let hours = parseFloat(row["Hours"] || row["RequiredHours"] || 1)
      let priority = parseFloat(row["Priority"] || 9999)
      return { Subject: subj, Module: module, Topic: topic, Hours: hours, Priority: priority }
    }

    function parseCsv(text, subj) {
      const lines = text.split(/\r?\n/)
      const headers = lines[0].split(',')
      return lines.slice(1).map(line => {
        if (!line.trim()) return null
        const values = line.split(',')
        let obj = {}
        headers.forEach((h, i) => obj[h.trim()] = values[i]?.trim())
        return cleanCsvColumns(obj, subj)
      }).filter(x => x)
    }

    function loadSubjects() {
      syllabusData = []
      Object.keys(subjectFiles).forEach(subj => {
        const id = subj.replace(/\s+/g, '')
        if (document.getElementById(id).checked) {
          const fileInput = document.getElementById(`file_${id}`)
          if (fileInput.files.length > 0) {
            const reader = new FileReader()
            reader.onload = e => {
              syllabusData = syllabusData.concat(parseCsv(e.target.result, subj))
              makeModules()
            }
            reader.readAsText(fileInput.files[0])
          }
        }
      })
    }

    function makeModules() {
      const div = document.getElementById('moduleSection')
      div.innerHTML = '<h2>Select Modules</h2>'
      const modules = [...new Set(syllabusData.map(x => x.Module))]
      modules.forEach(m => {
        const id = m.replace(/\s+/g, '')
        div.innerHTML += `
          <div class="form-check">
            <input class="form-check-input" type="checkbox" value="${m}" id="${id}" checked>
            <label class="form-check-label" for="${id}">${m}</label>
          </div>`
      })
      div.innerHTML += '<button class="btn btn-primary mt-3" onclick="makeHours()">Next → Study Hours</button>'
    }

    function makeHours() {
      const div = document.getElementById('hoursSection')
      div.innerHTML = '<h2>Enter Study Hours</h2>'
      const days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
      days.forEach(d => {
        div.innerHTML += `
          <div class="input-group mb-2">
            <span class="input-group-text">${d}</span>
            <input type="number" class="form-control" id="hours_${d}" value="0">
          </div>`
      })
      div.innerHTML += '<button class="btn btn-primary mt-3" onclick="makeDate()">Next → Exam Date</button>'
    }

    function makeDate() {
      const div = document.getElementById('dateSection')
      div.innerHTML = '<h2>Enter Exam Date</h2>'
      div.innerHTML += '<input type="date" id="examDate" class="form-control" style="max-width:200px">'
      div.innerHTML += '<button class="btn btn-success mt-3" onclick="makePlan()">Generate Plan</button>'
    }

    function makePlan() {
      const chosenModules = syllabusData.filter(x => document.getElementById(x.Module.replace(/\s+/g, '')).checked)
      const studyHours = {}
      ;["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"].forEach(d => {
        studyHours[d] = parseInt(document.getElementById(`hours_${d}`).value) || 0
      })
      const examDate = new Date(document.getElementById('examDate').value)
      const today = new Date()
      const daysLeft = Math.floor((examDate - today)/(1000*60*60*24))
      let df = [...chosenModules].sort((a,b)=>a.Priority-b.Priority)
      let plan = []
      let currentDate = new Date(today)

      for (let i=0;i<daysLeft;i++) {
        let weekday = currentDate.toLocaleDateString('en-US',{weekday:'long'})
        let hoursToday = studyHours[weekday] || 0
        while (hoursToday>0 && df.length>0) {
          let row = df[0]
          let need = row.Hours
          let allocate = Math.min(need, hoursToday)
          plan.push({Date:currentDate.toISOString().split('T')[0],Weekday:weekday,Subject:row.Subject,Module:row.Module,Topic:row.Topic,Hours:allocate})
          hoursToday -= allocate
          row.Hours -= allocate
          if (row.Hours<=0) df.shift()
        }
        currentDate.setDate(currentDate.getDate()+1)
      }

      showPlan(plan, df, chosenModules)
    }

    function showPlan(plan, remaining, chosen) {
      const div = document.getElementById('planSection')
      div.innerHTML = '<h2>Generated Study Plan</h2>'

      let table = '<table class="table table-bordered"><thead><tr><th>Date</th><th>Day</th><th>Subject</th><th>Module</th><th>Topic</th><th>Hours</th></tr></thead><tbody>'
      plan.forEach(r => {
        table += `<tr><td>${r.Date}</td><td>${r.Weekday}</td><td>${r.Subject}</td><td>${r.Module}</td><td>${r.Topic}</td><td>${r.Hours}</td></tr>`
      })
      table += '</tbody></table>'
      div.innerHTML += table

      let totalHours = plan.reduce((a,b)=>a+b.Hours,0)
      div.innerHTML += `<h4 class="text-success">Total Study Hours Scheduled: ${totalHours}</h4>`

      let studied = 0
      let scheduled = new Set(plan.map(r=>r.Topic)).size
      let uncovered = remaining.length
      let totalTopics = studied + scheduled + uncovered
      let marks = totalTopics>0 ? ((studied+scheduled)/totalTopics*100).toFixed(1) : 0

      div.innerHTML += `<h4 class="text-primary">Estimated Marks: ~${marks}%</h4>`

      const ctx = document.createElement('canvas')
      div.appendChild(ctx)
      new Chart(ctx,{type:'pie',data:{labels:['Scheduled','Uncovered'],datasets:[{data:[scheduled,uncovered],backgroundColor:['blue','red']}]}})

      const csv = [Object.keys(plan[0]).join(',')].concat(plan.map(r=>Object.values(r).join(','))).join('\n')
      const blob = new Blob([csv],{type:'text/csv'})
      const link = document.createElement('a')
      link.href = URL.createObjectURL(blob)
      link.download = 'study_plan.csv'
      link.textContent = 'Download CSV'
      link.className = 'btn btn-outline-dark mt-3'
      div.appendChild(link)
    }

    makeSubjects()
  </script>
</body>
</html>
