import javax.swing.*;
import java.awt.event.*;

public class ex3a extends JFrame implements ActionListener {
    JButton botao;
    int cont = 0;

    ex3a() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(200, 100);
        setLocationRelativeTo(null);

        botao = new JButton("Clique");
        add(botao);
        botao.addActionListener(this);

        setLayout(null);
        botao.setBounds(50, 20, 100, 30);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        cont++;
        System.out.println(cont);
    }

    public static void main(String[] args) {
        new ex3a();
    }
}
