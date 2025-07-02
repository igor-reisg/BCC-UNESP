import java.util.Scanner;

public class ex002 {
    static int[][] matrizA;
    static int[][] matrizB;
    static int[][] resultado;
    static int N;
    
    public static void preencherMatriz(int[][] matriz, Scanner scanner) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print("Matriz[" + i + "][" + j + "]: ");
                matriz[i][j] = scanner.nextInt();
            }
        }
    }

    static class SomaQuadrante implements Runnable {
        int inicioX, fimX, inicioY, fimY;
        
        SomaQuadrante(int inicioX, int fimX, int inicioY, int fimY) {
            this.inicioX = inicioX;
            this.fimX = fimX;
            this.inicioY = inicioY;
            this.fimY = fimY;
        }

        @Override
        public void run() {
            for (int i = inicioX; i < fimX; i++) {
                for (int j = inicioY; j < fimY; j++) {
                    resultado[i][j] = matrizA[i][j] + matrizB[i][j];
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o tamanho N da matriz (NxN): ");
        N = scanner.nextInt();
        
        matrizA = new int[N][N];
        matrizB = new int[N][N];
        resultado = new int[N][N];
        
        System.out.println("Preencha a Matriz A:");
        preencherMatriz(matrizA, scanner);
        System.out.println("Preencha a Matriz B:");
        preencherMatriz(matrizB, scanner);
        
        Thread t1 = new Thread(new SomaQuadrante(0, N / 2, 0, N / 2));
        Thread t2 = new Thread(new SomaQuadrante(0, N / 2, N / 2, N));
        Thread t3 = new Thread(new SomaQuadrante(N / 2, N, 0, N / 2));
        Thread t4 = new Thread(new SomaQuadrante(N / 2, N, N / 2, N));

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        } catch (InterruptedException e) { }

        System.out.println("\nMatriz (A + B):");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(resultado[i][j] + " ");
            }
            System.out.println();
        }
        scanner.close();
    }
}
