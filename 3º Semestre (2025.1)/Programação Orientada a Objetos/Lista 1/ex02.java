import java.util.Scanner;

public class ex02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite um valor para n: ");
        int n = sc.nextInt();

        if (n > 0) {
            double res = fibonnaci(n);
            System.out.println("O " + n + " termo da sequencia de fibonnaci eh: " + res);
        } else {
            System.out.println("Digite um valor maior que zero.");
        }
        sc.close();
    }

    public static double fibonnaci(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }

        double ant = 1, atual = 1;
        for (int i = 3; i <= n; i++) {
            double prox = ant + atual;
            ant = atual;
            atual = prox;
        }
        return atual;
    }
    
}