import java.io.*;
import java.net.*;
import java.util.*;

public class Servidor {
    public static PrintStream[] clientes = new PrintStream[2];
    public static char[][] tabuleiro = new char[3][3];
    public static int vez = 0;

    public static void main(String[] args) {
        ServerSocket servidor = null;

        try {
            servidor = new ServerSocket(1234);
        } catch (IOException e) {
            System.out.println("Erro no servidor: " + e);
        }
        System.out.println("Servidor iniciado. Aguardando outro jogador...");

        for (int i = 0; i < 2; i++) {
            try {
                Socket socket = servidor.accept();
                clientes[i] = new PrintStream(socket.getOutputStream(), true);
                new Jogador(socket, i).start();
            } catch (IOException e) {
                System.out.println("Erro ao aceitar: " + e);
                System.exit(1);
            }
        }

        iniciarTabuleiro();
        clientes[0].println("X");
        clientes[1].println("O");
        clientes[0].println("SUA_VEZ");
    }

    public static boolean fazerJogada(int jogador, int i, int j) {
        if (tabuleiro[i][j] == ' ') {
            tabuleiro[i][j] = jogador == 0 ? 'X' : 'O';
            for (PrintStream out : clientes) {
                out.println("JOGADA " + i + " " + j + " " + tabuleiro[i][j]);
            }
            return true;
        }
        return false;
    }

    public static void iniciarTabuleiro() {
        for (int i = 0; i < 3; i++)
            Arrays.fill(tabuleiro[i], ' ');
    }

    public static boolean verificarVitoria(char s) {
        for (int i = 0; i < 3; i++)
            if ((tabuleiro[i][0] == s && tabuleiro[i][1] == s && tabuleiro[i][2] == s) ||
                (tabuleiro[0][i] == s && tabuleiro[1][i] == s && tabuleiro[2][i] == s))
                return true;

        return (tabuleiro[0][0] == s && tabuleiro[1][1] == s && tabuleiro[2][2] == s) ||
               (tabuleiro[0][2] == s && tabuleiro[1][1] == s && tabuleiro[2][0] == s);
    }

    public static boolean verificarEmpate() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (tabuleiro[i][j] == ' ') return false;
        return true;
    }
}

class Jogador extends Thread {
    private Socket socket;
    private int id;
    private Scanner entrada;

    public Jogador(Socket socket, int id) {
        this.socket = socket;
        this.id = id;
    }

    @Override
    public void run() {
        try {
            entrada = new Scanner(socket.getInputStream());

            while (true) {
                String linha = entrada.nextLine();
                String[] partes = linha.split(" ");
                int i = Integer.parseInt(partes[0]);
                int j = Integer.parseInt(partes[1]);

                synchronized (Servidor.class) {
                    if (id != Servidor.vez) continue;
                    if (!Servidor.fazerJogada(id, i, j)) continue;

                    if (Servidor.verificarVitoria(Servidor.tabuleiro[i][j])) {
                        Servidor.clientes[id].println("VITORIA");
                        Servidor.clientes[1 - id].println("DERROTA");
                        break;
                    } else if (Servidor.verificarEmpate()) {
                        for (PrintStream out : Servidor.clientes) out.println("EMPATE");
                        break;
                    } else {
                        Servidor.vez = 1 - Servidor.vez;
                        Servidor.clientes[Servidor.vez].println("SUA_VEZ");
                    }
                }
            }
            socket.close();
        } catch (IOException | NoSuchElementException e) {
            System.out.println("Conexão com jogador " + id + " encerrada.");
        }
    }
}