import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;

class ex1 extends JFrame implements ActionListener {
    JButton Abrir, Salvar, SalvarComo, Fechar;
    JTextArea textArea;
    String nomeArquivo = null;

    ex1() {
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

        Abrir.addActionListener(this);
        Salvar.addActionListener(this);
        SalvarComo.addActionListener(this);
        Fechar.addActionListener(this);

        botoes.add(Abrir);
        botoes.add(Salvar);
        botoes.add(SalvarComo);
        botoes.add(Fechar);

        textArea = new JTextArea("Digite o texto nesta área");

        lateral.add(botoes, BorderLayout.NORTH);
        painel.add(lateral, BorderLayout.WEST);
        painel.add(new JScrollPane(textArea), BorderLayout.CENTER);

        add(painel);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == Abrir) {
            String nomeArq = JOptionPane.showInputDialog(this, "Nome do arquivo para abrir:");
            if (nomeArq != null) {
                try {
                    FileInputStream in = new FileInputStream(nomeArq);
                    Scanner sin = new Scanner(in);
                    StringBuffer txt = new StringBuffer();
                    while (sin.hasNextLine()) {
                        txt.append(sin.nextLine());
                        txt.append("\n");
                    }
                    textArea.setText(txt.toString());
                    sin.close();
                    nomeArquivo = nomeArq;
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Erro ao abrir o arquivo.");
                }
            }
        } else if (e.getSource() == Salvar) {
            if (nomeArquivo == null) {
                nomeArquivo = JOptionPane.showInputDialog(this, "Nome do arquivo para salvar:");
            }
            if (nomeArquivo != null) {
                try {
                    FileOutputStream out = new FileOutputStream(nomeArquivo);
                    out.write(textArea.getText().getBytes());
                    out.close();
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Erro ao salvar o arquivo.");
                }
            }
        } else if (e.getSource() == SalvarComo) {
            String nomeArq = JOptionPane.showInputDialog(this, "Salvar como:");
            if (nomeArq != null) {
                try {
                    FileOutputStream out = new FileOutputStream(nomeArq);
                    out.write(textArea.getText().getBytes());
                    out.close();
                    nomeArquivo = nomeArq;
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Erro ao salvar o arquivo.");
                }
            }
        } else if (e.getSource() == Fechar) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new ex1();
    }
}
