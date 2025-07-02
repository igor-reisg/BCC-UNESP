% Igor dos Reis Gomes
% 29/04/2025
% Modelagem e Simulação Computacional - Trabalho 4
% Objetivo:
% O programa realiza uma simulação de um sistema de fila de banco
% com resolução de 1 segundo por tique. O sistema considera chegadas de usuários
% com uma distribuição discreta de probabilidades (poisscdf) e tempo de atendimento
% de cada servidor com distribuição Normal (média=90s, desvio padrão=10s). 
% O T4 é uma adaptação do T3, porém agora será usado 3 servidores, ao invés de apenas 1
% O tempo de simulação é de 6 horas e depois continua atendendo até esvaziar a fila.

% Parâmetros da simulação
tempo_simulacao = 6 * 60 * 60;        % 6 horas em segundos
numero_simulacoes = 30;               % quantidade de simulações realizadas
num_servidores = 3;                   % quantidade de servidores que são utilizados

% Inicialização das variáveis para armazenar resultados
medias_tamanho_fila = zeros(1, numero_simulacoes);
maximos_tamanho_fila = zeros(1, numero_simulacoes);
tamanho_fila_fechamento = zeros(1, numero_simulacoes);
media_tempo_ocupacao_servidor = zeros(numero_simulacoes, num_servidores);
tempo_ocioso_medio = zeros(numero_simulacoes, num_servidores);
tempo_desocupado_maximo = zeros(numero_simulacoes, num_servidores);
media_tempo_fila = zeros(1, numero_simulacoes);
maior_tempo_espera = zeros(1, numero_simulacoes);
tempo_extra_funcionamento = zeros(1, numero_simulacoes);

for simulacao = 1:numero_simulacoes
    fila = [];                                              % fila de usuários
    tempo_entrada_fila = [];                                % momentos de entrada na fila
    tempos_espera = [];                                     % tempos de espera de cada usuário
    servidores_livre = true(1, num_servidores);             % status dos servidores (true = livre, false = ocupado)
    tempo_atendimento_atual = zeros(1, num_servidores);     % tempo restante de atendimento
    tamanho_fila = zeros(1, tempo_simulacao);               % tamanho da fila ao longo da simulação
    tempos_atendimento = cell(1, num_servidores);           % tempos individuais de atendimento para cada servidor (eu uso o cell para que consiga armazenar vetores de tamanhos diferentes)
    tempo_livre_atual = zeros(1, num_servidores);           % contadores de tempo livre atual para cada servidor
    tempos_livre = cell(1, num_servidores);                 % períodos que os servidores ficaram livres
    tempo_fechamento = tempo_simulacao;                     % momento em que o banco fecha (6h)
    
    % Loop principal da simulação (antes do fechamento)
    for tempo_corrente = 1:tempo_fechamento
        % Geração de chegada de pessoas com base na função poisscdf
        n = rand(1);
        switch true
            case n <= 0.00617
                num_chegadas = 0;
            case n <= 0.01234
                num_chegadas = 1;
            case n <= 0.01537
                num_chegadas = 2;
            case n <= 0.01639
                num_chegadas = 3;
            case n <= 0.01665
                num_chegadas = 4;
            case n <= 0.01668
                num_chegadas = 5;
            otherwise
                num_chegadas = 0;
        end

        % Adiciona as chegadas à fila
        for i = 1:num_chegadas
            fila = [fila, 1];
            tempo_entrada_fila = [tempo_entrada_fila, tempo_corrente];
        end

        % caso o tempo de atendimento acabe, o servidor fica livre
        for s = 1:3
            if ~servidores_livre(s)
                tempo_atendimento_atual(s) = tempo_atendimento_atual(s) - 1;
                if tempo_atendimento_atual(s) <= 0
                    servidores_livre(s) = true; % Atualiza atendimento do servidor que ainda estiver trabalhando
                end
            end
        end

        % Atende pessoa se algum dos servidores estiverem livres
        for s = 1:3
            if servidores_livre(s) && ~isempty(fila)
                tempo_servico = max(1, round(normrnd(90, 10))); % atendimento >= 1s
                tempo_atendimento_atual(s) = tempo_servico;        % o tempo de atendimento dos servidores atual sera o tempo de servico gerado
                servidores_livre(s) = false;                         % atualiza o servidor 

                espera = tempo_corrente - tempo_entrada_fila(1); % Calcula o tempo de espera da pessoa que está sendo atendida
                tempos_espera = [tempos_espera, espera];         % armazena o tempo de espera
                tempo_entrada_fila(1) = [];                      % remove a pessoa que acabou de ser atendida
                fila(1) = [];                                    % remove a pessoa da fila

                tempos_atendimento{s} = [tempos_atendimento{s}, tempo_servico];   % armazena o tempo de atendimento da pessoa

                if tempo_livre_atual(s) > 0                                     % Se havia um tempo livre antes do atendimento, registra esse tempo
                    tempos_livre{s} = [tempos_livre{s}, tempo_livre_atual(s)];
                    tempo_livre_atual(s) = 0;
                end
            end
        end

        % Se fila vazia e algum dos servidores livre, conta tempo ocioso
        for s = 1:num_servidores
            if servidores_livre(s) && isempty(fila)
                tempo_livre_atual(s) = tempo_livre_atual(s) + 1;
            end
        end

        % Registro do tamanho da fila
        tamanho_fila(tempo_corrente) = length(fila);
    end

    % Tamanho da fila no fechamento
    tamanho_fila_fechamento(simulacao) = length(fila);

    % Atendimento após o fechamento
    tempo_extra = 0;
    while ~isempty(fila)
        tempo_extra = tempo_extra + 1;

        for s = 1:num_servidores
            if ~servidores_livre(s)
                tempo_atendimento_atual(s) = tempo_atendimento_atual(s) - 1;
                if tempo_atendimento_atual(s) <= 0
                    servidores_livre(s) = true;
                end
            end
        end

        % Atende pessoa se algum dos servidores estiverem livres, mesma lógica de quando estava no horario de atendimento
        for s = 1:num_servidores
            if servidores_livre(s) && ~isempty(fila)
                tempo_servico = max(1, round(normrnd(90, 10)));
                tempo_atendimento_atual(s) = tempo_servico;
                servidores_livre(s) = false;

                espera = tempo_fechamento + tempo_extra - tempo_entrada_fila(1);
                tempos_espera = [tempos_espera, espera];
                tempo_entrada_fila(1) = [];
                fila(1) = [];

                tempos_atendimento{s} = [tempos_atendimento{s}, tempo_servico];
            end
        end
    end

    % Estatísticas da simulação
    medias_tamanho_fila(simulacao) = mean(tamanho_fila(1:tempo_fechamento));
    maximos_tamanho_fila(simulacao) = max(tamanho_fila);
    tempo_extra_funcionamento(simulacao) = tempo_extra;

    for s = 1:num_servidores
        media_tempo_ocupacao_servidor(simulacao, s) = mean(tempos_atendimento{s});
        if ~isempty(tempos_livre{s})     % Verifica se houve tempo livre do servidor
            tempo_ocioso_medio(simulacao, s) = mean(tempos_livre{s});
            tempo_desocupado_maximo(simulacao, s) = max(tempos_livre{s});
        end
    end

    if ~isempty(tempos_espera)      % Verifica se existe tempos de espera armazenados
        media_tempo_fila(simulacao) = mean(tempos_espera);
        maior_tempo_espera(simulacao) = max(tempos_espera);
    end
end

% Impressão do relatório 3
fprintf('\n\nRELATÓRIO TRABALHO 4\n\n');
fprintf('***************************************************\n');
fprintf('ANÁLISE DE TAMANHO DE FILA\n');
fprintf('Tamanho médio da fila: %.2f pessoas\n', mean(medias_tamanho_fila));
fprintf('Desvio padrão: %.2f\n', std(medias_tamanho_fila));
fprintf('Coeficiente de Variação: %.2f%%\n', (std(medias_tamanho_fila) / mean(medias_tamanho_fila)) * 100);

fprintf('\nTamanho médio da fila no fechamento (6h): %.2f pessoas\n', mean(tamanho_fila_fechamento));
fprintf('Desvio padrão: %.2f\n', std(tamanho_fila_fechamento));
fprintf('Coeficiente de Variação: %.2f%%\n', (std(tamanho_fila_fechamento) / mean(tamanho_fila_fechamento)) * 100);
fprintf('\nMaior tamanho absoluto da fila no fechamento: %d pessoas\n', max(tamanho_fila_fechamento));
fprintf('Maior tamanho absoluto da fila durante toda simulação: %d pessoas\n', max(maximos_tamanho_fila));

fprintf('\nANÁLISE DE CADA SERVIDOR\n');
for s = 1:num_servidores
    fprintf('\nSERVIDOR %d \n', s);
    fprintf('Tempo médio de ocupação por pessoa: %.2f minutos\n', mean(media_tempo_ocupacao_servidor(:,s)) / 60);
    fprintf('Desvio padrão: %.2f\n', std(media_tempo_ocupacao_servidor(:,s)));
    fprintf('Coeficiente de Variação: %.2f%%\n', (std(media_tempo_ocupacao_servidor(:,s)) / mean(media_tempo_ocupacao_servidor(:,s))) * 100);

    fprintf('\nTempo médio de desocupação: %.2f minutos\n', mean(tempo_ocioso_medio(:,s)) / 60);
    fprintf('Desvio padrão: %.2f\n', std(tempo_ocioso_medio(:,s)));
    fprintf('Coeficiente de Variação: %.2f%%\n', (std(tempo_ocioso_medio(:,s)) / mean(tempo_ocioso_medio(:,s))) * 100);
    fprintf('Maior tempo absoluto de desocupação: %.2f minutos\n', max(tempo_desocupado_maximo(:,s)) / 60);
end

fprintf('\n***************************************************\n');
fprintf('ANÁLISE DO TEMPO DE USUÁRIOS NA FILA\n');
fprintf('Tempo médio de espera na fila: %.2f minutos\n', mean(media_tempo_fila) / 60);
fprintf('Desvio padrão: %.2f\n', std(media_tempo_fila));
fprintf('Coeficiente de Variação: %.2f%%\n', (std(media_tempo_fila) / mean(media_tempo_fila)) * 100);
fprintf('Maior tempo absoluto que alguém ficou na fila: %.2f minutos\n', max(maior_tempo_espera) / 60);

fprintf('\n***************************************************\n');
fprintf('ANÁLISE DO TEMPO EXTRA DE FUNCIONAMENTO\n');
fprintf('Tempo médio extra de funcionamento: %.2f minutos\n', mean(tempo_extra_funcionamento) / 60);
fprintf('Desvio padrão: %.2f\n', std(tempo_extra_funcionamento));
fprintf('Coeficiente de Variação: %.2f%%\n', (std(tempo_extra_funcionamento) / mean(tempo_extra_funcionamento)) * 100);
fprintf('Maior tempo absoluto extra de funcionamento: %.2f minutos\n', max(tempo_extra_funcionamento) / 60);
