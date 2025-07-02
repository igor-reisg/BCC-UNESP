import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.util.*;

public class Cliente extends JFrame implements Runnable, ActionListener {
    private JButton[][] botoes = new JButton[3][3];
    private PrintStream os;
    private Scanner is;
    private Socket socket;
    private String simbolo;
    private boolean minhaVez = false;

    public Cliente() {
        super("Jogo da Velha");
        setLayout(new GridLayout(3, 3));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j] = new JButton("");
                botoes[i][j].addActionListener(this);
                add(botoes[i][j]);
            }
        }

        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        Cliente cliente = new Cliente();
        new Thread(cliente).start();
    }

    public void run() {
        try {
            socket = new Socket("127.0.0.1", 1234);
            os = new PrintStream(socket.getOutputStream(), true);
            is = new Scanner(socket.getInputStream());

            simbolo = is.nextLine();
            setTitle("Voce eh o jogador " + simbolo);

            while (is.hasNextLine()) {
                String msg = is.nextLine();

                if (msg.equals("SUA_VEZ")) {
                    minhaVez = true;
                } else if (msg.startsWith("JOGADA")) {
                    String[] partes = msg.split(" ");
                    int i = Integer.parseInt(partes[1]);
                    int j = Integer.parseInt(partes[2]);
                    String s = partes[3];
                    botoes[i][j].setText(s);
                    botoes[i][j].setEnabled(false);
                } else if (msg.equals("VITORIA")) {
                    JOptionPane.showMessageDialog(this, "Voce venceu!");
                    break;
                } else if (msg.equals("DERROTA")) {
                    JOptionPane.showMessageDialog(this, "Voce perdeu!");
                    break;
                } else if (msg.equals("EMPATE")) {
                    JOptionPane.showMessageDialog(this, "Empate!");
                    break;
                }
            }

            os.close();
            is.close();
            socket.close();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Erro: " + e);
        }
    }

    public void actionPerformed(ActionEvent e) {
    if (!minhaVez) {
        System.out.println("Nao e sua vez ainda!");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (e.getSource() == botoes[i][j]) {
                os.println(i + " " + j);
                minhaVez = false;
            }
        }
    }
}
}