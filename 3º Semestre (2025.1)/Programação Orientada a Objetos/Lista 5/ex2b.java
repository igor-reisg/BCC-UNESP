import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class ex2b extends JFrame implements ActionListener {
    JButton calcular;
    JTextField texto1, texto2;
    JLabel igual, resultado;
    JComboBox<String> operacoes;

    ex2b() {
        super("Calculadora");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 100);
        setLocationRelativeTo(null); 

        JPanel painel = new JPanel(new BorderLayout());
        JPanel painelCima = new JPanel(new FlowLayout(FlowLayout.CENTER));

        texto1 = new JTextField(10);
        texto2 = new JTextField(10);

        operacoes = new JComboBox<>();
        operacoes.addItem("Soma");
        operacoes.addItem("Subtrai");
        operacoes.addItem("Multiplica");
        operacoes.addItem("Divide");

        resultado = new JLabel("     0");
        igual = new JLabel(" = ");

        painelCima.add(texto1);
        painelCima.add(operacoes);
        painelCima.add(texto2);
        painelCima.add(igual);
        painelCima.add(resultado);

        calcular = new JButton("Calcular");
        calcular.addActionListener(this);

        painel.add(painelCima, BorderLayout.NORTH);
        painel.add(calcular, BorderLayout.SOUTH);
       
        add(painel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            double n1 = Double.parseDouble(texto1.getText());
            double n2 = Double.parseDouble(texto2.getText());
            double res = 0;
            String op = (String) operacoes.getSelectedItem();

            switch (op) {
                case "Soma": res = n1 + n2; break;
                case "Subtrai": res = n1 - n2; break;
                case "Multiplica": res = n1 * n2; break;
                case "Divide": res = n1 / n2; break;
            }

            resultado.setText("   " + res);
        } catch (NumberFormatException ex) {
            resultado.setText("   Erro");
        }
    }

    public static void main(String[] args) {
        new ex2b();
    }
}
