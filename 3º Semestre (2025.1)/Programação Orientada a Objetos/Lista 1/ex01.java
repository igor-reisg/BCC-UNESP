import java.util.Scanner;

public class ex01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o coeficientes a, b e c da equacao (separados por espaco): ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();

        double delta = b * b - 4 * a * c;

        if (delta > 0) {
            double x1 = (-b + Math.sqrt(delta)) / (2 * a);
            double x2 = (-b - Math.sqrt(delta)) / (2 * a);
            System.out.println("As raizes da equacao sao:\nx1 = " + x1 + "\nx2 = " + x2);
        } else if (delta == 0){
            double x = -b / (2 * a);
            System.out.println("A equacao possui uma raiz unica real de:\nx1 = " + x);
        } else {
            System.out.println("A equacao nao possui raizes reais.\n");
        }
        sc.close();
    }
}