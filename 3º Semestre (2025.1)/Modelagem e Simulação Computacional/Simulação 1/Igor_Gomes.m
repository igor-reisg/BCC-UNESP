tempo_simulacao = 360;      % tempo total da simulação
numero_simulacoes = 30;     % quantidade de simulações realizadas

medias = zeros(1, numero_simulacoes);
maximos = zeros(1, numero_simulacoes); 
restos = zeros(1, numero_simulacoes);

for simulacoes = 1 : numero_simulacoes
    fila = [];
    caixa_vazio = 1;            % 1 = caixa livre, 0 = caixa ocupado
    contagem_caixa = 0;         % contador de tempo de atendimento
    tamanhoFila = zeros(1, tempo_simulacao);  % vetor para armazenar o tamanho da fila a cada tempo
    tempo_de_servico = 0;       % inicializacao da contagem de tempo para atendimento de uma pessoa

    for tempo = 1 : tempo_simulacao
        % Chegada de pessoas (Poisson)
        n_entradas_pessoas = poissrnd(1);
        for n = 1 : n_entradas_pessoas
            fila = [fila, 1]; % adiciona pessoa na fila
        end

        % Atualiza tempo de atendimento
        if (~caixa_vazio)
            contagem_caixa = contagem_caixa + 1;
            if contagem_caixa >= tempo_de_servico
                caixa_vazio = 1;     % atendimento terminou, caixa livre
                contagem_caixa = 0;  % atendimento da pessoa finalizado
            end
        end
    
        % Atender se o caixa está livre e houver pessoas na fila
        if (~isempty(fila) && caixa_vazio)
            tempo_de_servico = 1;    % tempo necessário para atender uma pessoa
            fila(1) = [];                   % remove pessoa da fila
            caixa_vazio = 0;                % caixa agora está ocupado
            contagem_caixa = 0;             % começa o atendimento
        end
    
        % Armazena o tamanho da fila neste tempo
        tamanhoFila(tempo) = length(fila);
    end
    
    medias(simulacoes) = mean(tamanhoFila);     % media do tamanho da fila ao final da simulação
    maximos(simulacoes) = max(tamanhoFila);     % maior valor absoluto encontrado na simulação
    restos(simulacoes) = length(fila);          % pessoas restando na fila ao final da simulação
end

media_das_medias = mean(medias);
desvio_padrao = std(medias);
coeficiente_variacao = (desvio_padrao / media_das_medias) * 100;
maior_valor_absoluto = max(maximos);
maior_resto_final = max(restos);

% Impressão dos resultados
fprintf('Média das médias do tamanho da fila: %.2f\n', media_das_medias);
fprintf('Desvio padrão: %.2f\n', desvio_padrao);
fprintf('Coeficiente de variação: %.2f%%\n', coeficiente_variacao);
fprintf('Maior valor absoluto encontrado: %.0f\n', maior_valor_absoluto);
fprintf('Maior resto de fila no encerramento: %d\n', maior_resto_final);

% Gráfico 1: Tamanho médio das filas
figure;
bar(1:numero_simulacoes, medias);
xlabel('Número do Experimento');
ylabel('Tamanho Médio da Fila');
title('Tamanho Médio das Filas');

% Gráfico 2: Maior tamanho absoluto de fila
figure;
bar(1:numero_simulacoes, maximos);
xlabel('Número do Experimento');
ylabel('Maior Tamanho da Fila');
title('Maior Tamanho Absoluto de Fila');

% Gráfico 3: Tamanho da fila ao final
figure;
bar(1:numero_simulacoes, restos);
xlabel('Número do Experimento');
ylabel('Fila Restante no Final');
title('Tamanho da Fila no Encerramento');
