import java.util.Scanner;
class Student {
    protected String name;
    protected int age;
}

class CollegeStudent extends Student{
    protected String collegeName;
    protected int year;

    public CollegeStudent(String name, int age, String collegeName, int year) {
        this.name = name;
        this.age = age;
        this.collegeName = collegeName;
        this.year = year;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("College Name: " + collegeName);
        System.out.println("Year: " + year);
    }
}

public class Inheritance {
    public static void main(String args [])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: ");
        String name = sc.nextLine();
        System.out.print("Enter age: ");
        int age = sc.nextInt();
        sc.nextLine(); 
        System.out.print("Enter college name: ");
        String collegeName = sc.nextLine();
        System.out.print("Enter year: ");
        int year = sc.nextInt();

        CollegeStudent student = new CollegeStudent(name, age, collegeName, year);
        student.displayInfo();
    }}
