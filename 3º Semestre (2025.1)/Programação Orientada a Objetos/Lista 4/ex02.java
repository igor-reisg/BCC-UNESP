import java.awt.*;
import javax.swing.*;

public class ex02 extends JFrame {
    JButton soma, subtrai, multiplica, divide;
    JTextField texto1, texto2;
    JLabel igual, resultado;

    ex02() {
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
        resultado = new JLabel("0");

        painel.add(texto1);
        painel.add(botoesPanel);
        painel.add(texto2);
        painel.add(igual);
        painel.add(resultado);

        add(painel);
        setVisible(true);
    }

    public static void main(String[] args) {
        new ex02();
    }
}
