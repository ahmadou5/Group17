import java.io.*;
import java.nio.file.*;

class DivisionByZeroException extends Exception {
    public DivisionByZeroException(String message) {
        super(message);
    }
}

public class ExceptionHandling {
    
    public static double divide(double a, double b) throws DivisionByZeroException {
        if (b == 0) {
            throw new DivisionByZeroException("Division by zero is not allowed");
        }
        return a / b;
    }
    
    public static void readFile(String filename) throws IOException {
        String content = Files.readString(Paths.get(filename));
        System.out.println(content);
    }
    
    public static void demonstrateMultipleExceptions() {
        try {
            // This might throw NumberFormatException
            int number = Integer.parseInt("abc");
            
            // This might throw ArrayIndexOutOfBoundsException
            int[] array = {1, 2, 3};
            System.out.println(array[5]);
            
        } catch (NumberFormatException e) {
            System.err.println("Number format error: " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.err.println("Array index error: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Unexpected error: " + e.getMessage());
        } finally {
            System.out.println("Finally block always executes");
        }
    }
    
    public static void main(String[] args) {
        // Division example with exception handling
        System.out.println("Division Examples:");
        
        try {
            double result = divide(10.0, 2.0);
            System.out.println("10 / 2 = " + result);
            
            result = divide(10.0, 0.0); // This will throw an exception
            System.out.println("10 / 0 = " + result);
            
        } catch (DivisionByZeroException e) {
            System.err.println("Error: " + e.getMessage());
        }
        
        // File operation with exception handling
        System.out.println("\nFile Operation Example:");
        try {
            readFile("nonexistent.txt");
        } catch (IOException e) {
            System.err.println("File error: " + e.getMessage());
        }
        
        // Multiple exception types
        System.out.println("\nMultiple Exception Example:");
        demonstrateMultipleExceptions();
    }
}