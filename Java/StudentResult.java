public class StudentResult {
    public static void main(String[] args) {
        String name = args[0];
        String rollNumber = args[1];

        double totalMarks = Double.parseDouble(args[2]);
        double maxMarks = Double.parseDouble(args[3]);

        double percentage = (totalMarks / maxMarks) * 100;
        String status = (percentage >= 50.0) ? "Pass" : "Fail";

        System.out.println("Student Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Max Marks: " + maxMarks);
        System.out.printf("Percentage: %.2f%%\n", percentage);
        System.out.println("Status: " + status);
    }
}
