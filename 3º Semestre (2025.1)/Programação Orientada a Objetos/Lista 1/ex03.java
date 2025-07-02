import java.util.Scanner;
import java.util.Arrays;

public class ex03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o tamanho do vetor: ");
        int tam = sc.nextInt();

        int vet[] = new int[tam];

        System.out.println("Digite " + tam + " numeros inteiros:");
        for (int i = 0; i < tam; i++) {
            vet[i] = sc.nextInt();
        }

        Arrays.sort(vet);

        System.out.println("Vetor ordenado: " + Arrays.toString(vet));

        sc.close();
    }
}