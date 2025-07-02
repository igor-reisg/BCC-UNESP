import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        List<Integer> students = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            students.add(scanner.nextInt());
        }
        
        Collections.sort(students);
        
        int total = 0;
        
        for (int i = 0; i < n - 1; i += 2) {
            total += students.get(i + 1) - students.get(i);
        }
        
        System.out.println(total);
        
        scanner.close();
    }
}