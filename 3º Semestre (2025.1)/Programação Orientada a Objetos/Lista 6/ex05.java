import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int p = scanner.nextInt();
            int a = scanner.nextInt();
            int r = scanner.nextInt();
            
            if (p == 0 && a == 0 && r == 0) {
                break;
            }

            scanner.nextLine();  

            Set<String> perolas = new HashSet<>();
            for (int i = 0; i < p; i++) {
                perolas.add(scanner.nextLine().trim());
            }

            Map<String, Integer> perolasPorAluno = new HashMap<>();

            for (int i = 0; i < a; i++) {
                String nomeAluno = scanner.nextLine().trim();
                int contadorPerolas = 0;

                for (int j = 0; j < r; j++) {
                    String resposta = scanner.nextLine().trim();
                    if (perolas.contains(resposta)) {
                        contadorPerolas++;
                    }
                }

                perolasPorAluno.put(nomeAluno, contadorPerolas);
            }

            int maxPerolas = Collections.max(perolasPorAluno.values());

            List<String> alunosComMaisPerolas = new ArrayList<>();
            for (Map.Entry<String, Integer> entry : perolasPorAluno.entrySet()) {
                if (entry.getValue() == maxPerolas) {
                    alunosComMaisPerolas.add(entry.getKey());
                }
            }

            Collections.sort(alunosComMaisPerolas);

            System.out.println(String.join(", ", alunosComMaisPerolas));
        }

        scanner.close();
    }
}