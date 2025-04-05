#include <stdio.h>

int main() {

    int sim = 0, masc = 0, mascnao = 0;
    char sexo, resp;
    float porcmascnao;

    for (int i = 0; i < 15; i++) {
        printf("Informe o sexo do entrevistado (M/F): ");
        scanf(" %c", &sexo);

        printf("Resposta do entrevistado (S/N): ");
        scanf(" %c", &resp);

        if (resp == 'S' || resp == 's') {
            sim++;
            if (sexo == 'M' || sexo == 'm') {
                masc++;
            }
        } else if (sexo == 'M' || sexo == 'm') {
            mascnao++;
        }
    }

    printf("Número de pessoas que responderam sim: %d\n", sim);
    
    if (masc > 0) {
        porcmascnao = (float)mascnao / masc * 100;
        printf("Porcentagem de pessoas do sexo masculino que responderam nao: %.2f%%\n", porcmascnao);
    } else {
        printf("Não houve respostas do sexo masculino.\n");
    }
}
