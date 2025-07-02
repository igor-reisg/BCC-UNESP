% Igor dos Reis Gomes
% 24/04/2025
% Modelagem e Simulação Computacional - Trabalho 3
% Objetivo:
% O programa realiza uma simulação de um sistema de fila de banco
% com resolução de 1 segundo por tique. O sistema considera chegadas de usuários
% com uma distribuição discreta de probabilidades (poisscdf) e tempo de atendimento com
% distribuição Normal (média=90s, desvio padrão=10s).
% O tempo de simulação é de 6 horas e depois continua atendendo até esvaziar a fila.

% Parâmetros da simulação
tempo_simulacao = 6 * 60 * 60;        % 6 horas em segundos
numero_simulacoes = 30;               % quantidade de simulações realizadas

% Inicialização das variáveis para armazenar resultados
medias_tamanho_fila = zeros(1, numero_simulacoes);
maximos_tamanho_fila = zeros(1, numero_simulacoes);
tamanho_fila_fechamento = zeros(1, numero_simulacoes);
media_tempo_ocupacao_servidor = zeros(1, numero_simulacoes);
tempo_ocioso_medio = zeros(1, numero_simulacoes);
tempo_desocupado_maximo = zeros(1, numero_simulacoes);
media_tempo_fila = zeros(1, numero_simulacoes);
maior_tempo_espera = zeros(1, numero_simulacoes);
tempo_extra_funcionamento = zeros(1, numero_simulacoes);

for simulacao = 1:numero_simulacoes
    fila = [];                              % fila de usuários
    tempo_entrada_fila = [];                % momentos de entrada na fila
    tempos_espera = [];                     % tempos de espera de cada usuário
    servidor_livre = true;                  % status do servidor (true = livre, false = ocupado)
    tempo_atendimento_atual = 0;            % tempo restante de atendimento
    tamanho_fila = zeros(1, tempo_simulacao); % tamanho da fila ao longo da simulação
    tempos_atendimento = [];                % tempos individuais de atendimento
    pessoas_atendidas = 0;                  % contador de pessoas atendidas
    tempo_livre_atual = 0;                  % contador de tempo livre atual
    tempos_livre = [];                      % períodos que o servidor ficou livre
    tempo_fechamento = tempo_simulacao;     % momento em que o banco fecha (6h)
    
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

        % Atualiza atendimento se o servidor ainda estiver trabalhando
        if ~servidor_livre
            tempo_atendimento_atual = tempo_atendimento_atual - 1;
            if tempo_atendimento_atual <= 0
                servidor_livre = true; % caso o tempo de atendimento acabe, o servidor fica livre
            end
        end

        % Atende pessoa se o servidor estiver livre
        if servidor_livre && ~isempty(fila)
            tempo_servico = max(1, round(normrnd(90, 10))); % atendimento >= 1s
            tempo_atendimento_atual = tempo_servico;        % o tempo de atendimento do servidor atual sera o tempo de servico gerado
            servidor_livre = false;                         % atualiza o servidor 

            espera = tempo_corrente - tempo_entrada_fila(1); % Calcula o tempo de espera da pessoa que está sendo atendida
            tempos_espera = [tempos_espera, espera];         % armazena o tempo de espera
            tempo_entrada_fila(1) = [];                      % remove a pessoa que acabou de ser atendida
            fila(1) = [];                                    % remove a pessoa da fila
            pessoas_atendidas = pessoas_atendidas + 1;       % aumenta o numero de pessoas que foram atendidas

            tempos_atendimento = [tempos_atendimento, tempo_servico];   % armazena o tempo de atendimento da pessoa

            if tempo_livre_atual > 0                                     % Se havia um tempo livre antes do atendimento, registra esse tempo
                tempos_livre = [tempos_livre, tempo_livre_atual];
                tempo_livre_atual = 0;
            end
        end

        % Se fila vazia e servidor livre, conta tempo ocioso
        if servidor_livre && isempty(fila)
            tempo_livre_atual = tempo_livre_atual + 1;
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

        if ~servidor_livre
            tempo_atendimento_atual = tempo_atendimento_atual - 1;
            if tempo_atendimento_atual <= 0
                servidor_livre = true;
            end
        end

        % Atende pessoa se o servidor estiver livre, mesma lógica de quando estava no horario de atendimento
        if servidor_livre && ~isempty(fila)
            tempo_servico = max(1, round(normrnd(90, 10)));
            tempo_atendimento_atual = tempo_servico;
            servidor_livre = false;

            espera = tempo_fechamento + tempo_extra - tempo_entrada_fila(1);
            tempos_espera = [tempos_espera, espera];
            tempo_entrada_fila(1) = [];
            fila(1) = [];
            pessoas_atendidas = pessoas_atendidas + 1;

            tempos_atendimento = [tempos_atendimento, tempo_servico];
        end
    end

    % Estatísticas da simulação
    medias_tamanho_fila(simulacao) = mean(tamanho_fila(1:tempo_fechamento));
    maximos_tamanho_fila(simulacao) = max(tamanho_fila);
    media_tempo_ocupacao_servidor(simulacao) = mean(tempos_atendimento);
    tempo_extra_funcionamento(simulacao) = tempo_extra;

    if ~isempty(tempos_livre)        % Verifica se houve tempo livre do servidor
        tempo_ocioso_medio(simulacao) = mean(tempos_livre);
        tempo_desocupado_maximo(simulacao) = max(tempos_livre);
    end

    if ~isempty(tempos_espera)      % Verifica se existe tempos de espera armazenados
        media_tempo_fila(simulacao) = mean(tempos_espera);
        maior_tempo_espera(simulacao) = max(tempos_espera);
    end
end

% Impressão do relatório 3
fprintf('\n\nRELATÓRIO TRABALHO 3\n\n');
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

fprintf('\n***************************************************\n');
fprintf('ANÁLISE DO SERVIDOR\n');
fprintf('Tempo médio de ocupação do servidor por pessoa: %.2f minutos\n', mean(media_tempo_ocupacao_servidor) / 60);
fprintf('Desvio padrão: %.2f\n', std(media_tempo_ocupacao_servidor));
fprintf('Coeficiente de Variação: %.2f%%\n', (std(media_tempo_ocupacao_servidor) / mean(media_tempo_ocupacao_servidor)) * 100);

fprintf('\nTempo médio de desocupação do servidor: %.2f minutos\n', mean(tempo_ocioso_medio) / 60);
fprintf('Desvio padrão: %.2f\n', std(tempo_ocioso_medio));
fprintf('Coeficiente de Variação: %.2f%%\n', (std(tempo_ocioso_medio) / mean(tempo_ocioso_medio)) * 100);
fprintf('\nMaior tempo absoluto de desocupação do servidor: %.2f minutos\n', max(tempo_desocupado_maximo) / 60);

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
