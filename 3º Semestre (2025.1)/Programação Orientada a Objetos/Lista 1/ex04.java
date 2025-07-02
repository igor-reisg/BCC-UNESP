import java.util.Scanner;

public class ex04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite a dimensao das matrizes: ");
        int n = sc.nextInt();

        int mat1[][] = new int[n][n];
        int mat2[][] = new int[n][n];

        System.out.println("Digite os elementos da matriz 1: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat1[i][j] = sc.nextInt();
            }
        }

        System.out.println("Digite os elementos da matriz 2: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat2[i][j] = sc.nextInt();
            }
        }

        System.out.println("Soma das matrizes: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat1[i][j] += mat2[i][j];
                System.out.print(mat1[i][j]+ " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
