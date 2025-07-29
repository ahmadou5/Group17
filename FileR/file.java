import java.io.*;
import java.nio.file.*;

public class FileOperations {
    public static void main(String[] args) {
        String filename = "example.txt";
        String data = "Hello, World!\nThis is a file write operation in Java.\nLine 3 of the file.";
        
        try {
            // Write to file
            Files.write(Paths.get(filename), data.getBytes());
            System.out.println("Data written to file successfully.");
            
            // Read from file
            String content = Files.readString(Paths.get(filename));
            System.out.println("\nReading from file:");
            System.out.println(content);
            
            // Alternative: Read line by line
            System.out.println("\nReading line by line:");
            Files.lines(Paths.get(filename))
                 .forEach(System.out::println);
            
        } catch (IOException e) {
            System.err.println("File operation error: " + e.getMessage());
        } finally {
            // Clean up
            try {
                Files.deleteIfExists(Paths.get(filename));
            } catch (IOException e) {
                System.err.println("Error deleting file: " + e.getMessage());
            }
        }
    }
}