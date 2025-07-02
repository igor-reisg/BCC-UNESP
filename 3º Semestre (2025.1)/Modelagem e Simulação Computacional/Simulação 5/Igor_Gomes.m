% Igor dos Reis Gomes
% 09/05/2025
% Modelagem e Simulação Computacional - Trabalho 5
% Objetivo:
% Realizar uma simulação de rede de interconecção  modelo Shared-Bus protocolo TDM

tempo_simulacao = 18000; % Tempo total de simulação (18000 seg = 5 horas)
numero_simulacoes = 30;  % Numero de simulações realizadas

% Variáveis para guardar os tamanhos as filas de cada processador
medias_tamanhos_filaNo1 = [];
medias_tamanhos_filaNo2 = [];
medias_tamanhos_filaNo3 = [];

tamanhos_filaNo1 = zeros(1, tempo_simulacao);
tamanhos_filaNo2 = zeros(1, tempo_simulacao);
tamanhos_filaNo3 = zeros(1, tempo_simulacao);

tamanhoFilaNo1_Max = zeros(1, numero_simulacoes);
tamanhoFilaNo2_Max = zeros(1, numero_simulacoes);
tamanhoFilaNo3_Max = zeros(1, numero_simulacoes);

tic; %Inicio da contagem de tempo de execução do programa

% Loop de simulações realizadas
for simulacao = 1 : numero_simulacoes
    % Inicialização das filas para cada processador
    fila_processador1 = [];
    fila_processador2 = [];
    fila_processador3 = [];
    conta_tique = 0; % Contador para verificar qual tique corresponde a qual processador

    % Loop principal do programa
    for tempo = 1 : tempo_simulacao
      conta_tique = conta_tique + 1;

      % Reinicia o ciclo caso tenha passado de 3
      if conta_tique == 4
        conta_tique = 1;
      endif

      % A cada 5 segundos (ou no tempo 1), chegam novos pacotes nos nós
      if mod(tempo, 5) == 0 || tempo == 1
          noP1 = poissrnd(2);
          noP2 = poissrnd(1);
          noP3 = poissrnd(1);

          % Adiciona os pacotes nas filas correspondentes
          for i = 1 : noP1
              fila_processador1 = [fila_processador1, 1];
          endfor
          for i = 1 : noP2
              fila_processador2 = [fila_processador2, 1];
          endfor
          for i = 1 : noP3
              fila_processador3 = [fila_processador3, 1];
          endfor
      endif

      % Caso esteja no seu tique, retira o pacote da fila
      if conta_tique == 1 && ~isempty(fila_processador1)
          fila_processador1(1) = [];  % Transmite 1 pacote do nó 1
      elseif conta_tique == 2 && ~isempty(fila_processador2)
          fila_processador2(1) = [];  % Transmite 1 pacote do nó 2
      elseif conta_tique == 3 && ~isempty(fila_processador3)
          fila_processador3(1) = [];  % Transmite 1 pacote do nó 3
      endif

      % Registra o tamanho da fila atual de cada nó
      tamanhos_filaNo1(tempo) = length(fila_processador1);
      tamanhos_filaNo2(tempo) = length(fila_processador2);
      tamanhos_filaNo3(tempo) = length(fila_processador3);

    endfor

    % Calcula e armazena a média do tamanho da fila durante toda a simulação
    medias_tamanhos_filaNo1 = [medias_tamanhos_filaNo1, mean(tamanhos_filaNo1)];
    medias_tamanhos_filaNo2 = [medias_tamanhos_filaNo2, mean(tamanhos_filaNo2)];
    medias_tamanhos_filaNo3 = [medias_tamanhos_filaNo3, mean(tamanhos_filaNo3)];

    % Armazena o maior tamanho absoluto da fila durante a simulação
    tamanhoFilaNo1_Max(simulacao) = max(tamanhos_filaNo1);
    tamanhoFilaNo2_Max(simulacao) = max(tamanhos_filaNo2);
    tamanhoFilaNo3_Max(simulacao) = max(tamanhos_filaNo3);

endfor

% Relatório do Trabalho 5
printf("\nRelatório com a média das médias dos 30 experimentos:\n\n");
printf("Fila 1: Média = %.2f,  Desvio padrão = %.2f,  Cv = %.2f,  Máximo absoluto = %d\n", mean(medias_tamanhos_filaNo1), std(medias_tamanhos_filaNo1), std(medias_tamanhos_filaNo1)/mean(medias_tamanhos_filaNo1), max(tamanhoFilaNo1_Max));
printf("Fila 2: Média = %.2f,  Desvio padrão = %.2f,  Cv = %.2f,  Máximo absoluto = %d\n", mean(medias_tamanhos_filaNo2), std(medias_tamanhos_filaNo2), std(medias_tamanhos_filaNo2)/mean(medias_tamanhos_filaNo2), max(tamanhoFilaNo2_Max));
printf("Fila 3: Média = %.2f,  Desvio padrão = %.2f,  Cv = %.2f,  Máximo absoluto = %d\n", mean(medias_tamanhos_filaNo3), std(medias_tamanhos_filaNo3), std(medias_tamanhos_filaNo3)/mean(medias_tamanhos_filaNo3), max(tamanhoFilaNo3_Max));
printf("\nTempo de processamento: %.2f segundos\n", toc);
