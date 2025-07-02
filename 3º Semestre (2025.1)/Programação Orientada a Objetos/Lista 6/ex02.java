import java.util.*;

public class ex02 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
       
        System.out.print("Digite o numero de alunos: ");
        int n = scanner.nextInt();
        
        scanner.nextLine();
        
        Set<String> alunos = new TreeSet<>();
        
        System.out.println("Digite os nomes dos alunos:");
        for (int i = 0; i < n; i++) {
            String nome = scanner.nextLine();
            alunos.add(nome);
        }
        
        System.out.println("\nLista de alunos ordenada:");
        for (String aluno : alunos) {
            System.out.println(aluno);
        }
        
        scanner.close();
    }
}
