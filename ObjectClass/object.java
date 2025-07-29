public class Student {
    private String name;
    private int id;
    private double gpa;
    
    // Constructor
    public Student(String name, int id, double gpa) {
        this.name = name;
        this.id = id;
        this.gpa = gpa;
    }
    
    // Getter methods
    public String getName() { return name; }
    public int getId() { return id; }
    public double getGPA() { return gpa; }
    
    // Setter methods
    public void setGPA(double newGPA) {
        this.gpa = newGPA;
        System.out.println("GPA updated to " + newGPA + " for " + name);
    }
    
    // Method to display student information
    public void display() {
        System.out.println("Student: " + name + " (ID: " + id + ", GPA: " + gpa + ")");
    }
    
    // Method to check if student is honor student
    public boolean isHonorStudent() {
        return gpa >= 3.5;
    }
    
    @Override
    public String toString() {
        return "Student{name='" + name + "', id=" + id + ", gpa=" + gpa + "}";
    }
    
    public static void main(String[] args) {
        Student student1 = new Student("Alice Johnson", 12345, 3.8);
        
        student1.display();
        
        if (student1.isHonorStudent()) {
            System.out.println(student1.getName() + " is an honor student!");
        }
        
        student1.setGPA(3.9);
        student1.display();
    }
}