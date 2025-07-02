import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class ex3c extends JFrame implements MouseListener {
    JLabel label;
    int cont = 0;

    ex3c() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 100);
        setLocationRelativeTo(null);

        label = new JLabel("Clique aqui");
        add(label);
        label.addMouseListener(this);

        setLayout(new FlowLayout());
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        cont++;
        System.out.println(cont);
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}

    public static void main(String[] args) {
        new ex3c();
    }
}
