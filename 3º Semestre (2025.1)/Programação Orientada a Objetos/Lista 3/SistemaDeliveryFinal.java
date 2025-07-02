import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class SistemaDeliveryFinal {
    public static void main(String[] args) {
        SistemaDelivery sistema = new SistemaDelivery();
        sistema.rodar();
    }
    
    public static final String RESET = "\033[0m";
    public static final String VERDE = "\033[1;32m";
    public static final String AZUL = "\033[1;34m";
    public static final String AMARELO = "\033[1;33m";
    public static final String VERMELHO = "\033[1;31m";
    public static final String ROXO = "\033[1;35m";
    public static final String CIANO = "\033[1;36m";

    abstract static class Usuario {
        int id;
        String nome, email;

        public Usuario(int id, String nome, String email) {
            this.id = id;
            this.nome = nome;
            this.email = email;
        }

        public void visualizaPerfil() {
            System.out.println(CIANO + "ID: " + RESET + id);
            System.out.println(CIANO + "Nome: " + RESET + nome);
            System.out.println(CIANO + "Email: " + RESET + email);
        }
    }

    static class Cliente extends Usuario {
        public Cliente(int id, String nome, String email) {
            super(id, nome, email);
        }

        @Override
        public void visualizaPerfil() {
            System.out.println(VERDE + "\n=== PERFIL CLIENTE ===" + RESET);
            super.visualizaPerfil();
        }
    }

      static class Entregador extends Usuario {
        String meioDeTransporte;
        boolean statusDisponivel;

        public Entregador(int id, String nome, String email, String meioDeTransporte) {
            super(id, nome, email);
            this.meioDeTransporte = meioDeTransporte;
            this.statusDisponivel = true;
        }

        @Override
        public void visualizaPerfil() {
            System.out.println(AZUL + "\n=== PERFIL ENTREGADOR ===" + RESET);
            super.visualizaPerfil();
            System.out.println(CIANO + "Meio de Transporte: " + RESET + meioDeTransporte);
            System.out.println(CIANO + "Disponível: " + RESET + (statusDisponivel ? "Sim" : "Não"));
        }
    }

    static class Restaurante extends Usuario {
        List<String> cardapio;
        String nomeFantasia;

        public Restaurante(int id, String nome, String email, String nomeFantasia, List<String> cardapio) {
            super(id, nome, email);
            this.cardapio = cardapio;
            this.nomeFantasia = nomeFantasia;
        }

        @Override
        public void visualizaPerfil() {
            System.out.println(ROXO + "\n=== PERFIL RESTAURANTE ===" + RESET);
            super.visualizaPerfil();
            System.out.println(CIANO + "Nome Fantasia: " + RESET + nomeFantasia);
            System.out.println(CIANO + "Cardápio: " + RESET);
            for (String item : cardapio) {
                System.out.println("  - " + item);
            }
        }
    }

    static class Pedido {
        enum Status {
            REALIZADO, EM_PREPARO, EM_ENTREGA, ENTREGUE
        }

        private Cliente cliente;
        private Restaurante restaurante;
        private Entregador entregador;
        private List<String> itens;
        private Status status;

        public Pedido(Cliente cliente, Restaurante restaurante, List<String> itens) {
            this.cliente = cliente;
            this.restaurante = restaurante;
            this.itens = itens;
            this.status = Status.REALIZADO;
        }

        public void atualizarStatus(Status novoStatus) {
            this.status = novoStatus;
        }

        public void atribuirEntregador(Entregador entregador) {
            this.entregador = entregador;
            entregador.statusDisponivel = false;
        }

        public Status getStatus() {
            return status;
        }

        public Entregador getEntregador() {
            return entregador;
        }

        public Cliente getCliente() {
            return cliente;
        }

        public Restaurante getRestaurante() {
            return restaurante;
        }

        public void resumoDoPedido() {
            System.out.println(AMARELO + "\n=== RESUMO DO PEDIDO ===" + RESET);
            System.out.println(CIANO + "Cliente: " + RESET + cliente.nome);
            System.out.println(CIANO + "Restaurante: " + RESET + restaurante.nomeFantasia);
            System.out.println(CIANO + "Itens:" + RESET);
            for (String item : itens) {
                System.out.println("  - " + item);
            }
            System.out.println(CIANO + "Entregador: " + RESET + 
                (entregador != null ? entregador.nome : "Entregador não atribuído"));
            System.out.println(CIANO + "Status: " + RESET + status);
        }
    }

    static class SistemaDelivery {
        private List<Cliente> clientes = new ArrayList<>();
        private List<Entregador> entregadores = new ArrayList<>();
        private List<Restaurante> restaurantes = new ArrayList<>();
        private List<Pedido> pedidos = new ArrayList<>();

        public void cadastrarCliente(Cliente cliente) {
            clientes.add(cliente);
        }

        public void cadastrarRestaurante(Restaurante restaurante) {
            restaurantes.add(restaurante);
        }

        public void cadastrarEntregador(Entregador entregador) {
            entregadores.add(entregador);
        }

        public Pedido criarPedido(Cliente cliente, Restaurante restaurante, List<String> itens) {
            Pedido pedido = new Pedido(cliente, restaurante, itens);
            pedidos.add(pedido);
            return pedido;
        }

        public void listarTodosPedidos() {
            limparTela();
            System.out.println(VERDE + "=== TODOS OS PEDIDOS ===" + RESET);
            for (Pedido p : pedidos) {
                p.resumoDoPedido();
                System.out.println(VERDE + "------------------------" + RESET);
            }
            aguardarEnter();
        }

        public void novoPedido(Scanner sc) {
            limparTela();
            if (clientes.isEmpty() || restaurantes.isEmpty()) {
                System.out.println(VERMELHO + "É necessário ter pelo menos um cliente e um restaurante cadastrado!" + RESET);
                aguardarEnter();
                return;
            }

            System.out.println(AZUL + "=== NOVO PEDIDO ===" + RESET);
            System.out.println(CIANO + "Clientes disponíveis:" + RESET);
            for (Cliente c : clientes) {
                System.out.println(c.id + " - " + c.nome);
            }
            System.out.print(AMARELO + "Selecione o ID do cliente: " + RESET);
            int idCliente = sc.nextInt();
            sc.nextLine();

            System.out.println(CIANO + "\nRestaurantes disponíveis:" + RESET);
            for (Restaurante r : restaurantes) {
                System.out.println(r.id + " - " + r.nomeFantasia);
            }
            System.out.print(AMARELO + "Selecione o ID do restaurante: " + RESET);
            int idRestaurante = sc.nextInt();
            sc.nextLine();

            Cliente clienteSelecionado = clientes.stream().filter(c -> c.id == idCliente).findFirst().orElse(null);
            Restaurante restauranteSelecionado = restaurantes.stream().filter(r -> r.id == idRestaurante).findFirst().orElse(null);

            if (clienteSelecionado == null || restauranteSelecionado == null) {
                System.out.println(VERMELHO + "\nCliente ou restaurante não encontrado!" + RESET);
                aguardarEnter();
                return;
            }

            List<String> itens = new ArrayList<>();
            System.out.println(CIANO + "\nCardápio do restaurante:" + RESET);
            for (int i = 0; i < restauranteSelecionado.cardapio.size(); i++) {
                System.out.println((i + 1) + " - " + restauranteSelecionado.cardapio.get(i));
            }
            System.out.print(AMARELO + "\nDigite os números dos itens desejados (separados por vírgula): " + RESET);
            String[] itensSelecionados = sc.nextLine().split(",");

            for (String item : itensSelecionados) {
                try {
                    int index = Integer.parseInt(item.trim()) - 1;
                    if (index >= 0 && index < restauranteSelecionado.cardapio.size()) {
                        itens.add(restauranteSelecionado.cardapio.get(index));
                    }
                } catch (NumberFormatException e) {
                   
                }
            }

            if (itens.isEmpty()) {
                System.out.println(VERMELHO + "\nNenhum item válido selecionado!" + RESET);
                aguardarEnter();
                return;
            }

            Pedido novoPedido = criarPedido(clienteSelecionado, restauranteSelecionado, itens);
            System.out.println(VERDE + "\nPedido criado com sucesso! ID: " + pedidos.indexOf(novoPedido) + RESET);
            aguardarEnter();
        }

        public void atribuirPedido(Scanner sc) {
            limparTela();
            if (pedidos.isEmpty()) {
                System.out.println(VERMELHO + "Não há pedidos cadastrados!" + RESET);
                aguardarEnter();
                return;
            }

            if (entregadores.isEmpty()) {
                System.out.println(VERMELHO + "Não há entregadores cadastrados!" + RESET);
                aguardarEnter();
                return;
            }

            System.out.println(AZUL + "=== ATRIBUIR PEDIDO ===" + RESET);
            System.out.println(CIANO + "Pedidos disponíveis para atribuição:" + RESET);
            for (int i = 0; i < pedidos.size(); i++) {
                Pedido p = pedidos.get(i);
                if (p.getEntregador() == null) {
                    System.out.println(i + " - Cliente: " + p.getCliente().nome + ", Restaurante: " + p.getRestaurante().nomeFantasia);
                }
            }
            System.out.print(AMARELO + "Selecione o ID do pedido: " + RESET);
            int idPedido = sc.nextInt();
            sc.nextLine();

            if (idPedido < 0 || idPedido >= pedidos.size()) {
                System.out.println(VERMELHO + "\nPedido inválido!" + RESET);
                aguardarEnter();
                return;
            }

            Pedido pedidoSelecionado = pedidos.get(idPedido);
            if (pedidoSelecionado.getEntregador() != null) {
                System.out.println(VERMELHO + "\nEste pedido já tem um entregador atribuído!" + RESET);
                aguardarEnter();
                return;
            }

            System.out.println(CIANO + "\nEntregadores disponíveis:" + RESET);
            for (Entregador e : entregadores) {
                if (e.statusDisponivel) {
                    System.out.println(e.id + " - " + e.nome + " (" + e.meioDeTransporte + ")");
                }
            }
            System.out.print(AMARELO + "Selecione o ID do entregador: " + RESET);
            int idEntregador = sc.nextInt();
            sc.nextLine();

            Entregador entregadorSelecionado = entregadores.stream().filter(e -> e.id == idEntregador && e.statusDisponivel).findFirst().orElse(null);
            if (entregadorSelecionado == null) {
                System.out.println(VERMELHO + "\nEntregador não encontrado ou não disponível!" + RESET);
                aguardarEnter();
                return;
            }

            pedidoSelecionado.atribuirEntregador(entregadorSelecionado);
            System.out.println(VERDE + "\nEntregador atribuído com sucesso ao pedido!" + RESET);
            aguardarEnter();
        }

        public void atualizarPedidos(Scanner sc) {
            limparTela();
            if (pedidos.isEmpty()) {
                System.out.println(VERMELHO + "Não há pedidos cadastrados!" + RESET);
                aguardarEnter();
                return;
            }

            System.out.println(AZUL + "=== ATUALIZAR PEDIDOS ===" + RESET);
            System.out.println(CIANO + "Pedidos disponíveis para atualização:" + RESET);
            for (int i = 0; i < pedidos.size(); i++) {
                Pedido p = pedidos.get(i);
                System.out.println(i + " - Cliente: " + p.getCliente().nome + ", Status: " + p.getStatus());
            }
            System.out.print(AMARELO + "Selecione o ID do pedido: " + RESET);
            int idPedido = sc.nextInt();
            sc.nextLine();

            if (idPedido < 0 || idPedido >= pedidos.size()) {
                System.out.println(VERMELHO + "\nPedido inválido!" + RESET);
                aguardarEnter();
                return;
            }

            Pedido pedidoSelecionado = pedidos.get(idPedido);

            System.out.println(CIANO + "\nStatus atual: " + RESET + pedidoSelecionado.getStatus());
            System.out.println(CIANO + "Novos status disponíveis:" + RESET);
            for (Pedido.Status s : Pedido.Status.values()) {
                System.out.println(s.ordinal() + " - " + s);
            }
            System.out.print(AMARELO + "Selecione o novo status: " + RESET);
            int novoStatus = sc.nextInt();
            sc.nextLine();

            if (novoStatus < 0 || novoStatus >= Pedido.Status.values().length) {
                System.out.println(VERMELHO + "\nStatus inválido!" + RESET);
                aguardarEnter();
                return;
            }

            pedidoSelecionado.atualizarStatus(Pedido.Status.values()[novoStatus]);
            System.out.println(VERDE + "\nStatus atualizado com sucesso!" + RESET);
            aguardarEnter();
        }

        private void limparTela() {
            try {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } catch (Exception e) {
                System.out.println("\n\n\n\n\n\n\n\n\n\n"); 
            }
        }

        private void aguardarEnter() {
            System.out.print(CIANO + "\nPressione ENTER para continuar..." + RESET);
            try {
                System.in.read();
            } catch (Exception e) {}
        }

        private void exibirCabecalho() {
            System.out.println(CIANO + "===============================");
            System.out.println("||   SISTEMA DE DELIVERY   ||");
            System.out.println("===============================\n" + RESET);
            System.out.println("Um trabalho de:");
            System.out.println("Fernando Hiroshi Murusaki");
            System.out.println("Igor dos Reis\n");
        }

        public void rodar() {
            Scanner sc = new Scanner(System.in);
            SistemaDelivery sistema = new SistemaDelivery();

            int opcao;
            int IdClientes = 1, IdEntregadores = 1, IdRestaurantes = 1;

            while(true) {
                sistema.limparTela();
                sistema.exibirCabecalho();
                System.out.println("\n" + CIANO + "Selecione uma opção:\n" + RESET);
                System.out.println(VERMELHO + "1." + RESET + " CADASTRAR CLIENTE");
                System.out.println(VERMELHO + "2." + RESET + " CADASTRAR RESTAURANTE");
                System.out.println(VERMELHO + "3." + RESET + " CADASTRAR ENTREGADOR");
                System.out.println(VERMELHO + "4." + RESET + " NOVO PEDIDO");
                System.out.println(VERMELHO + "5." + RESET + " ATRIBUIR PEDIDO A ENTREGADOR");
                System.out.println(VERMELHO + "6." + RESET + " ATUALIZAR STATUS PEDIDOS");
                System.out.println(VERMELHO + "7." + RESET + " LISTAR PEDIDOS");
                System.out.println(VERMELHO + "8." + RESET +" SAIR");
                System.out.print("\n" + CIANO + "Opção: " + RESET);

                opcao = sc.nextInt();
                sc.nextLine();
                switch(opcao){
                    case 1:
                        sistema.limparTela();
                        sistema.exibirCabecalho();
                        System.out.println("\n" + VERDE + "=== CADASTRO DE CLIENTE ===" + RESET);
                        System.out.print(CIANO + "Nome do cliente: " + RESET);
                        String nomeCliente = sc.nextLine();

                        System.out.print(CIANO + "Email do cliente: " + RESET);
                        String emailCliente = sc.nextLine();

                        sistema.cadastrarCliente(new Cliente(IdClientes++, nomeCliente, emailCliente));
                        System.out.println(VERDE + "\nCliente cadastrado com sucesso!" + RESET);
                        sistema.aguardarEnter();
                        break;

                    case 2:
                        sistema.limparTela();
                        sistema.exibirCabecalho();
                        System.out.println("\n" + AZUL + "=== CADASTRO DE RESTAURANTE ===" + RESET);
                        System.out.print(CIANO + "Nome do restaurante (razão social): " + RESET);
                        String nomeRestaurante = sc.nextLine();

                        System.out.print(CIANO + "Nome fantasia: " + RESET);
                        String nomeFantasia = sc.nextLine();

                        System.out.print(CIANO + "Email do restaurante: " + RESET);
                        String emailRestaurante = sc.nextLine();

                        List<String> cardapio = new ArrayList<>();
                        System.out.print(CIANO + "Quantos itens seu cardápio terá? " + RESET);
                        int qtdItens = sc.nextInt();
                        sc.nextLine();

                        for (int i = 0; i < qtdItens; i++) {
                            System.out.print(CIANO + "Item " + (i + 1) + ": " + RESET);
                            cardapio.add(sc.nextLine());
                        }
                        sistema.cadastrarRestaurante(new Restaurante(IdRestaurantes++, nomeRestaurante, emailRestaurante, nomeFantasia, cardapio));
                        System.out.println(VERDE + "\nRestaurante cadastrado com sucesso!" + RESET);
                        sistema.aguardarEnter();
                        break;

                    case 3:
                        sistema.limparTela();
                        sistema.exibirCabecalho();
                        System.out.println("\n" + AMARELO + "=== CADASTRO DE ENTREGADOR ===" + RESET);
                        System.out.print(CIANO + "Nome do entregador: " + RESET);
                        String nomeEntregador = sc.nextLine();

                        System.out.print(CIANO + "Email do entregador: " + RESET);
                        String emailEntregador = sc.nextLine();

                        System.out.print(CIANO + "Tipo de transporte: " + RESET);
                        String transporteEntregador = sc.nextLine();

                        sistema.cadastrarEntregador(new Entregador(IdEntregadores++, nomeEntregador, emailEntregador, transporteEntregador));
                        System.out.println(VERDE + "\nEntregador cadastrado com sucesso!" + RESET);
                        sistema.aguardarEnter();
                        break;

                    case 4:
                        sistema.novoPedido(sc);
                        break;
                    case 5:
                        sistema.atribuirPedido(sc);
                        break;

                    case 6:
                        sistema.atualizarPedidos(sc);
                        break;

                    case 7:
                        sistema.listarTodosPedidos();
                        break;
                    case 8:
                        sistema.limparTela();
                        System.out.println(VERDE + "\nSaindo do sistema... Obrigado por usar nosso Delivery!" + RESET);
                        sc.close();
                        System.exit(0);
                    default:
                        System.out.println(VERMELHO + "\nOpção inválida!" + RESET);
                        sistema.aguardarEnter();
                        break;
                }
            }
        }
    }
}