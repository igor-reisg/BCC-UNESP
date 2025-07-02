import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ex2a extends JFrame implements ActionListener {
    JButton soma, subtrai, multiplica, divide;
    JTextField texto1, texto2;
    JLabel igual, resultado;

    ex2a() {
        super("Calculadora");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 155);
        setLocationRelativeTo(null); 

        JPanel painel = new JPanel(new FlowLayout(FlowLayout.CENTER));

        texto1 = new JTextField(10);
        texto2 = new JTextField(10);

        JPanel botoesPanel = new JPanel(new GridLayout(4, 1));
        soma = new JButton("Soma");
        subtrai = new JButton("Subtrai");
        multiplica = new JButton("Multiplica");
        divide = new JButton("Divide");

        botoesPanel.add(soma);
        botoesPanel.add(subtrai);
        botoesPanel.add(multiplica);
        botoesPanel.add(divide);

        igual = new JLabel(" = ");
        resultado = new JLabel("     0");

        painel.add(texto1);
        painel.add(botoesPanel);
        painel.add(texto2);
        painel.add(igual);
        painel.add(resultado);

        soma.addActionListener(this);
        subtrai.addActionListener(this);
        multiplica.addActionListener(this);
        divide.addActionListener(this);

        add(painel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            double n1 = Double.parseDouble(texto1.getText());
            double n2 = Double.parseDouble(texto2.getText());
            double res = 0;

            if (e.getSource() == soma) res = n1 + n2;
            else if (e.getSource() == subtrai) res = n1 - n2;
            else if (e.getSource() == multiplica) res = n1 * n2;
            else if (e.getSource() == divide) res = n1 / n2;

            resultado.setText("  " + res);
        } catch (NumberFormatException ex) {
            resultado.setText("  Erro");
        }
    }

    public static void main(String[] args) {
        new ex2a();
    }
}
