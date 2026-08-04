import java.util.Scanner;

public class student {
    int regno;
    String name;

    student (int regno,String name){
        this.regno=regno;
        this.name=name;
    }

    public void display(){
        System.out.println("Regno: "+regno);
        System.out.println("Name: "+name);
    }



}
public class engineeringstudent extends student{
   String deptname;
   int sem;
   engineeringstudent(int regno,String name,String deptname,int sem){
       super(regno,name);
       this.deptname=deptname;
       this.sem=sem;
   }

   @Override
   public void display(){
       super.display();
       System.out.println("Department: "+deptname);
       System.out.println("Semester: "+sem);
   }
}

public class finalyearstudent extends engineeringstudent{
    int projectmarks;
    finalyearstudent(int regno,String name,String deptname,int sem,int projectmarks){
        super(regno,name,deptname,sem);
        this.projectmarks=projectmarks;
    }

    @Override
    public void display(){
        super.display();
        System.out.println("Project Marks: "+projectmarks);
    }
}

public class Student {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter registration number: ");
        int regno = sc.nextInt();
        sc.nextLine(); 
        System.out.print("Enter name: ");
        String name = sc.nextLine();
        System.out.print("Enter department name: ");
        String deptname = sc.nextLine();
        System.out.print("Enter semester: ");
        int sem = sc.nextInt();
        System.out.print("Enter project marks: ");
        int projectmarks = sc.nextInt();

        finalyearstudent fys = new finalyearstudent(regno, name, deptname, sem, projectmarks);
        fys.display();
    }
}