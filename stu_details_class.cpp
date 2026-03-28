//Program to Display Student Details (Multiple Objects)
#include <iostream>
using namespace std;
class Student { 
    private:
        string name;
        int age;
        string grade;
    public:
        void setDetails(string n, int a, string g) {
            name = n;
            age = a;
            grade = g;
        }
        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Grade: " << grade << endl;
        }
};
int main() {
    Student student1, student2;
    student1.setDetails("Alice", 20, "A");
    student2.setDetails("Bob", 22, "B");
    cout << "Student 1 Details:" << endl;
    student1.displayDetails();
    cout << endl;
    cout << "Student 2 Details:" << endl;
    student2.displayDetails();          
    return 0;
}
