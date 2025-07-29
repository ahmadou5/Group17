import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class ArrayManipulation {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>(Arrays.asList(10, 25, 8, 42, 15, 33, 7));
        
        // Calculate sum
        int sum = numbers.stream().mapToInt(Integer::intValue).sum();
        
        // Calculate average
        double average = numbers.stream().mapToInt(Integer::intValue).average().orElse(0.0);
        
        // Find maximum
        int max = Collections.max(numbers);
        
        System.out.println("Array: " + numbers);
        System.out.println("Sum: " + sum);
        System.out.println("Average: " + average);
        System.out.println("Maximum: " + max);
    }
}