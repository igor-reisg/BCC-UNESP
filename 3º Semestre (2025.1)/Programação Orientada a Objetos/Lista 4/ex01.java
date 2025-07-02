import java.awt.*;
import javax.swing.*;

class ex01 extends JFrame {
    JButton Abrir, Salvar, SalvarComo, Fechar;
    JTextArea textArea;

    ex01() {
        super("Editor de Texto");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 300);
        setLocationRelativeTo(null);

        JPanel painel = new JPanel(new BorderLayout());
        JPanel lateral = new JPanel(new BorderLayout());
        JPanel botoes = new JPanel();

        botoes.setLayout(new GridLayout(4, 1));
        Abrir = new JButton("Abrir");
        Salvar = new JButton("Salvar");
        SalvarComo = new JButton("Salvar Como");
        Fechar = new JButton("Fechar");

        botoes.add(Abrir);
        botoes.add(Salvar);
        botoes.add(SalvarComo);
        botoes.add(Fechar);

        textArea = new JTextArea("Digite o texto nesta área");

        lateral.add(botoes, BorderLayout.NORTH);
        painel.add(lateral, BorderLayout.WEST);
        painel.add(textArea, BorderLayout.CENTER);

        add(painel);
        setVisible(true);
    }

    public static void main(String[] args) {
        new ex01();
    }
}