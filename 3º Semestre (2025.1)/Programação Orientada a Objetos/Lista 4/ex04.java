import java.awt.*;
import javax.swing.*;

class ex04 extends JFrame {
    JButton calcular;
    JTextField texto1, texto2;
    JLabel igual, resultado;
    JComboBox<String> operacoes;

    ex04() {
        super("Calculadora");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 105);
        setLocationRelativeTo(null); 

        JPanel painel = new JPanel(new BorderLayout());
        JPanel painelCima = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JPanel painelBotao = new JPanel(new FlowLayout(FlowLayout.CENTER));

        texto1 = new JTextField(10);
        texto2 = new JTextField(10);

        JComboBox<String> operacoes = new JComboBox<>();
        operacoes.addItem("Soma");
        operacoes.addItem("Subtrai");
        operacoes.addItem("Multiplica");
        operacoes.addItem("Divide");

        resultado = new JLabel("0");
        igual = new JLabel(" = ");

        painelCima.add(texto1);
        painelCima.add(operacoes);
        painelCima.add(texto2);
        painelCima.add(igual);
        painelCima.add(resultado);

        calcular = new JButton("Calcular");
        
        painelBotao.add(calcular);

        painel.add(painelCima, BorderLayout.NORTH);
        painel.add(painelBotao, BorderLayout.SOUTH);
       
        add(painel);
        setVisible(true);
    }
    public static void main(String[] args) {
        new ex04();
    }
}