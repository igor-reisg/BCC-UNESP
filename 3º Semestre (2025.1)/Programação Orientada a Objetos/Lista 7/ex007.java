import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class ex007 extends JFrame {
    private JTextField campo1 = new JTextField(5);
    private JTextField campo2 = new JTextField(5);
    private JTextField campo3 = new JTextField(5);
    private JButton jogar = new JButton("Jogar");

    private boolean[] terminado = new boolean[3];
    private int[] resultados = new int[3];

    public ex007() {
        super("Caça-Níquel");
        setLayout(new FlowLayout());

        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        campo1.setEditable(false);
        campo2.setEditable(false);
        campo3.setEditable(false);

        add(campo1);
        add(campo2);
        add(campo3);
        add(jogar);

        jogar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                jogar.setEnabled(false);
                terminado[0] = terminado[1] = terminado[2] = false;

                Thread t1 = new Thread(new rodarValor(0, campo1));
                Thread t2 = new Thread(new rodarValor(1, campo2));
                Thread t3 = new Thread(new rodarValor(2, campo3));

                t1.start();
                t2.start();
                t3.start();
            }
        });

        setVisible(true);
    }

    class rodarValor implements Runnable {
        private int index;
        private JTextField campo;
        private Random random = new Random();

        rodarValor(int index, JTextField campo) {
            this.index = index;
            this.campo = campo;
        }

        public void run() {
            int valor = 0;
            for (int i = 0; i < 150; i++) {
                valor = random.nextInt(7) + 1;
                final int finalValor = valor;

                SwingUtilities.invokeLater(new Runnable() {
                    public void run() {
                        campo.setText(String.valueOf(finalValor));
                    }
                });

                try {
                    Thread.sleep(10 + random.nextInt(20));
                } catch (InterruptedException e) {}
            }

            resultados[index] = valor;
            terminado[index] = true;

            if (terminado[0] && terminado[1] && terminado[2]) {
                SwingUtilities.invokeLater(new Runnable() {
                    public void run() {
                        if (resultados[0] == resultados[1] && resultados[1] == resultados[2]) {
                            JOptionPane.showMessageDialog(null, "Parabéns! Você venceu!");
                        } 
                        else
                            JOptionPane.showMessageDialog(null, "Você perdeu! Tente novamente.");
                        
                        jogar.setEnabled(true);
                    }
                });
            }
        }
    }

    public static void main(String[] args) {
        new ex007();
    }
}
