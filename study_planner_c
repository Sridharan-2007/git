#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TOPICS 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char subject[50];
    char module[50];
    char topic[100];
    double hours;
    int priority;
} StudyTopic;

int load_syllabus(const char* filename, const char* subject_name, StudyTopic* topics, int count) {
    FILE* file = fopen(filename, "r");
    if (!file) return count;

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file); 

    while (fgets(line, MAX_LINE_LENGTH, file) && count < MAX_TOPICS) {
        char *token;
        strcpy(topics[count].subject, subject_name);

        token = strtok(line, ",");
        if (token) strcpy(topics[count].module, token);

        token = strtok(NULL, ",");
        if (token) strcpy(topics[count].topic, token);

        token = strtok(NULL, ",");
        topics[count].hours = (token) ? atof(token) : 1.0;

        token = strtok(NULL, ",");
        topics[count].priority = (token) ? atoi(token) : 999;

        count++;
    }
    fclose(file);
    return count;
}

int compare_priority(const void* a, const void* b) {
    StudyTopic* t1 = (StudyTopic*)a;
    StudyTopic* t2 = (StudyTopic*)b;
    return (t1->priority - t2->priority);
}

void generate_plan(StudyTopic* topics, int topic_count, double* hours_per_day, int days_left) {
    time_t t = time(NULL);
    struct tm current_date = *localtime(&t);

    printf("\n%-15s | %-10s | %-25s | %-5s\n", "Date", "Day", "Topic", "Hrs");
    printf("----------------------------------------------------------------------\n");

    int topic_idx = 0;
    for (int d = 0; d < days_left && topic_idx < topic_count; d++) {
        int weekday = current_date.tm_wday;
        double available_today = hours_per_day[weekday];

        char date_str[20];
        char day_name[15];
        strftime(date_str, 20, "%Y-%m-%d", &current_date);
        strftime(day_name, 15, "%A", &current_date);

        while (available_today > 0 && topic_idx < topic_count) {
            double need = topics[topic_idx].hours;
            double allocate = (need < available_today) ? need : available_today;

            printf("%-15s | %-10s | %-25.25s | %.1f\n", 
                   date_str, day_name, topics[topic_idx].topic, allocate);

            available_today -= allocate;
            topics[topic_idx].hours -= allocate;

            if (topics[topic_idx].hours <= 0) {
                topic_idx++;
            }
        }

        current_date.tm_mday += 1;
        mktime(&current_date);
    }
}

int main() {
    StudyTopic syllabus[MAX_TOPICS];
    int total_topics = 0;

    total_topics = load_syllabus("calculus.csv", "Math", syllabus, total_topics);
    total_topics = load_syllabus("physics.csv", "Physics", syllabus, total_topics);
    total_topics = load_syllabus("chemistry.csv", "Chemistry", syllabus, total_topics);
    total_topics = load_syllabus("python.csv", "Python", syllabus, total_topics);

    qsort(syllabus, total_topics, sizeof(StudyTopic), compare_priority);

    double hours_per_day[7] = {2.0, 4.0, 4.0, 4.0, 4.0, 4.0, 6.0};
    int days_until_exam = 14;

    generate_plan(syllabus, total_topics, hours_per_day, days_until_exam);

    return 0;
}