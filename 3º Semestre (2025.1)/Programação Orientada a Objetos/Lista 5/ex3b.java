import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class ex3b extends JFrame implements KeyListener {
    JLabel texto;

    ex3b() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 100);
        setLocationRelativeTo(null);

        texto = new JLabel("Digite algo:");
        add(texto);
        addKeyListener(this);

        setLayout(new FlowLayout());
        setVisible(true);
    }

    public void keyPressed(KeyEvent e) {
        texto.setText("Tecla pressionada: " + e.getKeyChar());
    }

    public void keyReleased(KeyEvent e) {}
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        new ex3b();
    }
}

