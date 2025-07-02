% Igor dos Reis Gomes
% 11/04/2025
% Trabalho 2 - Modelagem e Simulação Computacional
% Objetivo:
% Este programa realiza uma simulação de um sistema de fila simples similar ao trabalho 1,
% com resolução de 0.5 minuto por tique. O sistema considera chegadas de usuários com distribuição
% de Poisson e tempo de atendimento aleatório entre 0.5 e 2 minutos
% Os resultados coletados são os seguintes:
% - Tamanho médio da fila, maior tamanho observado e fila restante ao fim da simulação
% - Tempo médio que o servidor ficou ocupado e ocioso (total e por pessoa)
% - Tempo médio de espera na fila por usuário
% - Desvios padrão e coeficientes de variação dos resultados coletados
% - Maior e menor tempo de espera individual na fila

tempo_simulacao = 720;      % tempo total da simulação (720 tiques de 0.5 minuto = 360 minutos)
numero_simulacoes = 30;     % quantidade de simulações realizadas

medias = zeros(1, numero_simulacoes);                  % média do tamanho da fila
maximos = zeros(1, numero_simulacoes);                 % maior tamanho existente na fila
restos = zeros(1, numero_simulacoes);                  % pessoas ainda na fila ao fim da simulação
media_tempo_ocupacao = zeros(1, numero_simulacoes);    % tempo médio de atendimento por pessoa
media_tempo_livre = zeros(1, numero_simulacoes);       % tempo que o servidor ficou ocioso
media_tempo_fila = zeros(1, numero_simulacoes);        % tempo médio de espera na fila
desvio_padrao_fila = zeros(1, numero_simulacoes);      % desvio padrão do tempo de fila
coef_var_fila = zeros(1, numero_simulacoes);           % coeficiente de variação do tempo de fila
maior_tempo_espera = zeros(1, numero_simulacoes);      % maior tempo individual de espera
menor_tempo_espera = zeros(1, numero_simulacoes);      % menor tempo individual de espera
tempo_ocupado_total = zeros(1, numero_simulacoes);     % tempo total que o servidor ficou ocupado

for simulacoes = 1 : numero_simulacoes
   fila = [];                        % fila de usuários
   tempo_fila_inicio = [];           % momentos de entrada na fila
   tempo_fila = [];                  % tempos de espera de cada usuário
   caixa_vazio = 1;                  % status do servidor (1 = livre, 0 = ocupado)
   contagem_caixa = 0;               % tempo atual de atendimento
   tamanhoFila = zeros(1, tempo_simulacao);   % tamanho da fila ao longo da simulação
   tempo_de_servico = 0;                        % inicializacao da contagem de tempo para atendimento de uma pessoa
   tempo_ocupacao = zeros(1, tempo_simulacao);  % vetor binário para ocupação do caixa
   tempo_livre = zeros(1, tempo_simulacao);     % vetor binário para ociosidade do caixa
   tempos_de_servico_pessoas = [];              % tempos individuais de atendimento
   pessoas_atendidas = 0;

   for tempo = 1 : tempo_simulacao
       if (mod(tempo, 2))  % a cada minuto (2 tiques), geramos chegada de clientes
           n_entradas_pessoas = poissrnd(1);  % distribuição de Poisson (média = 1)
           for n = 1 : n_entradas_pessoas
               fila = [fila, 1];
               tempo_fila_inicio = [tempo_fila_inicio, tempo];
           end
       end

        % Atualiza tempo de atendimento
       if (~caixa_vazio)
           contagem_caixa = contagem_caixa + 1;
           if contagem_caixa >= tempo_de_servico
               espera = (tempo - tempo_fila_inicio(1)) * 0.5;  % tempo de espera da pessoa na fila
               tempo_fila = [tempo_fila, espera];              % guarda o tempo de espara da pessoa no vetor
               tempo_fila_inicio(1) = [];                      % retira a pessoa da fila de contagem de tempo
               caixa_vazio = 1;              % atendimento terminou, caixa livre
               contagem_caixa = 0;           % atendimento da pessoa finalizado
           end
       end

       % Atender se o caixa está livre e houver pessoas na fila
       if (~isempty(fila) && caixa_vazio)
           tempo_de_servico = randi(4);  % atendimento aleatório entre 1 a 4 tiques (0.5 a 2 min)
           tempos_de_servico_pessoas = [tempos_de_servico_pessoas, tempo_de_servico * 0.5]; % Tempo de atendimento por pessoa
           fila(1) = [];                    % remove pessoa da fila
           caixa_vazio = 0;                 % caixa agora está ocupado
           contagem_caixa = 0;              % começa o atendimento
           pessoas_atendidas = pessoas_atendidas + 1;   % contagem de pessoas atendidas
       end

       % Registro da ocupação e ociosidade do servidor
       if (caixa_vazio)
           tempo_livre(tempo) = 1;
       else
           tempo_ocupacao(tempo) = 1;
       end

       % Tamanho atual da fila
       tamanhoFila(tempo) = length(fila);
   end

   % Armazenamento dos dados por simulação
   medias(simulacoes) = mean(tamanhoFila);
   maximos(simulacoes) = max(tamanhoFila);
   restos(simulacoes) = length(fila);
   media_tempo_livre(simulacoes) = sum(tempo_livre) * 0.5;
   tempo_ocupado_total(simulacoes) = sum(tempo_ocupacao) * 0.5;
   media_tempo_ocupacao(simulacoes) = mean(tempos_de_servico_pessoas);
   media_tempo_fila(simulacoes) = mean(tempo_fila);
   desvio_padrao_fila(simulacoes) = std(tempo_fila);
   coef_var_fila(simulacoes) = (std(tempo_fila) / mean(tempo_fila)) * 100;

   if ~isempty(tempo_fila)
       maior_tempo_espera(simulacoes) = max(tempo_fila);
       menor_tempo_espera(simulacoes) = min(tempo_fila);
   end
end

% Estatísticas finais
media_tempo_ocupado_total = mean(tempo_ocupado_total);
desvio_tempo_ocupado_total = std(tempo_ocupado_total);
variacao_tempo_ocupado_total = (desvio_tempo_ocupado_total / media_tempo_ocupado_total) * 100;

media_das_medias_tempo_livre = mean(media_tempo_livre);
desvio_padrao_tempo_livre = std(media_tempo_livre);
variacao_tempo_livre = (desvio_padrao_tempo_livre / media_das_medias_tempo_livre) * 100;

media_das_medias_tempo_ocupado = mean(media_tempo_ocupacao);
desvio_padrao_tempo_ocupado = std(media_tempo_ocupacao);
variacao_tempo_ocupado = (desvio_padrao_tempo_ocupado / media_das_medias_tempo_ocupado) * 100;

media_das_medias_tempo_fila = mean(media_tempo_fila);
desvio_padrao_tempo_fila = std(media_tempo_fila);
variacao_tempo_fila = (desvio_padrao_tempo_fila / media_das_medias_tempo_fila) * 100;

media_das_medias = mean(medias);
desvio_padrao = std(medias);
coeficiente_variacao = (desvio_padrao / media_das_medias) * 100;
maior_valor_absoluto = max(maximos);
maior_resto_final = max(restos);

% Impressão formatada do relatório
fprintf('\n\nRELATÓRIO DO TRABALHO 2\n\n');
fprintf('***************************************************\n');
fprintf('ANÁLISE DE TAMANAHO DE FILA\n');
fprintf('Tamanho médio da fila: %.2f\n', media_das_medias);
fprintf('Desvio padrão: %.2f\n', desvio_padrao);
fprintf('Coeficiente de Variação: %.2f%%\n', coeficiente_variacao);
fprintf('Maior valor absoluto da fila: %.0f\n', maior_valor_absoluto);
fprintf('Maior tamanho de fila no encerramento: %d\n', maior_resto_final);

fprintf('\n***************************************************\n');
fprintf('ANÁLISE DO TEMPO DE USUÁRIOS NA FILA\n');
fprintf('Tempo médio em fila: %.2f min\n', media_das_medias_tempo_fila);
fprintf('Desvio padrão: %.2f min\n', desvio_padrao_tempo_fila);
fprintf('Coeficiente de Variação: %.2f%%\n', variacao_tempo_fila);
fprintf('Maior valor absoluto: %.2f min\n', max(maior_tempo_espera));
fprintf('Menor valor absoluto: %.2f min\n', min(menor_tempo_espera));

fprintf('\n***************************************************\n');
fprintf('ANÁLISE DO TEMPO DE OCUPAÇÃO DO SERVIDOR\n');
fprintf('Tempo médio de ocupação do servidor (total): %.2f min\n', media_tempo_ocupado_total);
fprintf('Desvio padrão: %.2f min\n', desvio_tempo_ocupado_total);
fprintf('Coeficiente de Variação: %.2f%%\n', variacao_tempo_ocupado_total);
fprintf('Tempo médio de ocupação do servidor por pessoa: %.2f min\n', media_das_medias_tempo_ocupado);
fprintf('Desvio padrão: %.2f min\n', desvio_padrao_tempo_ocupado);
fprintf('Coeficiente de Variação: %.2f%%\n', variacao_tempo_ocupado);
fprintf('Tempo médio do servidor livre: %.2f min\n', media_das_medias_tempo_livre);
fprintf('Desvio padrão: %.2f min\n', desvio_padrao_tempo_livre);
fprintf('Coeficiente de Variação: %.2f%%\n', variacao_tempo_livre);
