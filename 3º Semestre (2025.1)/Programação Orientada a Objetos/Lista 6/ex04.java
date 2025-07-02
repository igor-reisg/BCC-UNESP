import java.util.*;

public class Main {
    public static int contaDiamantes(String expressao) {
        Stack<Character> pilha = new Stack<>();
        int diamante = 0;

        for (int i = 0; i < expressao.length(); i++) {
            if (expressao.charAt(i) == '<') {
                pilha.push('<');
            } else if (expressao.charAt(i) == '>') {
                if (!pilha.isEmpty()) {
                    pilha.pop();
                    diamante++;
                }
            }
        }
        return diamante;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String expressao = scanner.nextLine();
            System.out.println(contaDiamantes(expressao));
        }
        scanner.close();
    }
}
