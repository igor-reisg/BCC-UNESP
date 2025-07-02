import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

class Aluno {
    private String nome;
    private String rg;
    private String endereco;
    private String telefone;
    private int ra;
    private double cr;
    private int diaNascimento, mesNascimento, anoNascimento;

    public Aluno(String nome, int diaNascimento, int mesNascimento, int anoNascimento,
                 String rg, String endereco, String telefone, int ra, double cr) {
        this.nome = nome;
        this.diaNascimento = diaNascimento;
        this.mesNascimento = mesNascimento;
        this.anoNascimento = anoNascimento;
        this.rg = rg;
        this.endereco = endereco;
        this.telefone = telefone;
        this.ra = ra;
        this.cr = cr;
    }

    public int getRA() {
        return ra;
    }

    public String getNome() {
        return nome;
    }

    public double getCR() {
        return cr;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setRG(String rg) {
        this.rg = rg;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public void setRA(int ra) {
        this.ra = ra;
    }

    public void setCR(double cr) {
        this.cr = cr;
    }

    public void setDataNascimento(int dia, int mes, int ano) {
        this.diaNascimento = dia;
        this.mesNascimento = mes;
        this.anoNascimento = ano;
    }

    public void imprimirDados() {
        System.out.println("Nome: " + nome);
        System.out.println("Data de Nascimento: " + diaNascimento + "/" + mesNascimento + "/" + anoNascimento);
        System.out.println("RG: " + rg);
        System.out.println("Endereço: " + endereco);
        System.out.println("Telefone: " + telefone);
        System.out.println("RA: " + ra);
        System.out.println("CR: " + cr);
        System.out.println("-------------------------");
    }
}

class CadastroAlunos {
    private static Aluno[] alunos = new Aluno[100];
    private static int qtdAluno = 0;

    public static void inserirAluno(Scanner scanner) {
        if (qtdAluno >= 100) {
            System.out.println("Cadastro cheio!");
            return;
        }

        System.out.print("Nome: ");
        String nome = scanner.nextLine();
        System.out.print("Data de nascimento (dia mes ano): ");
        int dia = scanner.nextInt();
        int mes = scanner.nextInt();
        int ano = scanner.nextInt();
        scanner.nextLine();
        System.out.print("RG: ");
        String rg = scanner.nextLine();
        System.out.print("Endereço: ");
        String endereco = scanner.nextLine();
        System.out.print("Telefone: ");
        String telefone = scanner.nextLine();
        System.out.print("RA: ");
        int ra = scanner.nextInt();
        System.out.print("CR (0 a 10): ");
        double cr = scanner.nextDouble();
        scanner.nextLine();

        alunos[qtdAluno] = new Aluno(nome, dia, mes, ano, rg, endereco, telefone, ra, cr);
        qtdAluno++;
        System.out.println("Aluno cadastrado com sucesso!");
    }

    public static void buscarPorRA(Scanner scanner) {
        System.out.print("Digite o RA: ");
        int ra = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < qtdAluno; i++) {
            if (alunos[i].getRA() == ra) {
                alunos[i].imprimirDados();
                return;
            }
        }
        System.out.println("Aluno nao encontrado.");
    }

    public static void imprimirAlunos(int opcaoOrdenacao) {
        if (qtdAluno == 0) {
            System.out.println("Nenhum aluno cadastrado.");
            return;
        }

        Aluno[] copiaLista = new Aluno[qtdAluno];

        for (int i = 0; i < qtdAluno; i++) {
            copiaLista[i] = alunos[i];
        }

        switch (opcaoOrdenacao) {
            case 1:
                Arrays.sort(copiaLista, Comparator.comparingInt(Aluno::getRA));
                break;
            case 2:
                Arrays.sort(copiaLista, Comparator.comparing(Aluno::getNome));
                break;
            case 3:
                Arrays.sort(copiaLista, Comparator.comparingDouble(Aluno::getCR).reversed());
                break;
            default:
                System.out.println("Opcao invalida.");
                return;
        }

        for (int i = 0; i < copiaLista.length; i++) {
            copiaLista[i].imprimirDados();
        }
    }

    public static void alterarAluno(Scanner scanner) {
        System.out.print("Digite o nome do aluno que deseja alterar: ");
        String nomeBusca = scanner.nextLine();
        Aluno alunoEncontrado = null;

        for (int i = 0; i < qtdAluno; i++) {
            if (alunos[i].getNome().equalsIgnoreCase(nomeBusca)) {
                alunoEncontrado = alunos[i];
                break;
            }
        }

        if (alunoEncontrado == null) {
            System.out.println("Aluno nao encontrado.");
            return;
        }

        System.out.println("Aluno encontrado! Insira os novos dados:");

        System.out.print("Nome: ");
        alunoEncontrado.setNome(scanner.nextLine());

        System.out.print("Data de nascimento (dia mes ano): ");
        int dia = scanner.nextInt();
        int mes = scanner.nextInt();
        int ano = scanner.nextInt();
        scanner.nextLine();
        alunoEncontrado.setDataNascimento(dia, mes, ano);

        System.out.print("RG: ");
        alunoEncontrado.setRG(scanner.nextLine());

        System.out.print("Endereço: ");
        alunoEncontrado.setEndereco(scanner.nextLine());

        System.out.print("Telefone: ");
        alunoEncontrado.setTelefone(scanner.nextLine());

        System.out.print("RA: ");
        alunoEncontrado.setRA(scanner.nextInt());

        System.out.print("CR (0 a 10): ");
        alunoEncontrado.setCR(scanner.nextDouble());
        scanner.nextLine();

        System.out.println("Aluno alterado com sucesso!");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Inserir aluno");
            System.out.println("2. Buscar aluno por RA");
            System.out.println("3. Imprimir alunos");
            System.out.println("4. Alterar aluno por nome");
            System.out.println("5. Sair");
            System.out.print("Escolha uma opcao: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    inserirAluno(scanner);
                    break;
                case 2:
                    buscarPorRA(scanner);
                    break;
                case 3:
                    System.out.println("Ordenar por: 1-RA  2-Nome  3-CR");
                    int ordem = scanner.nextInt();
                    scanner.nextLine();
                    imprimirAlunos(ordem);
                    break;
                case 4:
                    alterarAluno(scanner);
                    break;
                case 5:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opcao invalida.");
            }
        } while (opcao != 5);
    }
}
