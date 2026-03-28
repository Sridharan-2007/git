#include <stdio.h>

struct Student {
    char name[50];
    int id;
    int present;
    int absent;
    float percentage;
};

void calcAttendance(struct Student *s) {
    s->percentage = ((float)s->present / (s->present + s->absent)) * 100;
}

int main() {
    struct Student s[5];

    for(int i = 0; i < 5; i++) {
        printf("Enter Name, ID, Days Present, Days Absent for Student %d: ", i + 1);
        scanf("%s %d %d %d", s[i].name, &s[i].id, &s[i].present, &s[i].absent);
        calcAttendance(&s[i]);
    }

    printf("\n--- Attendance Report ---\n");
    for(int i = 0; i < 5; i++) {
        printf("Name: %s | Attendance: %.2f%% | Status: %s\n", 
               s[i].name, s[i].percentage, (s[i].percentage >= 75) ? "Pass" : "Fail");
    }

    return 0;
}