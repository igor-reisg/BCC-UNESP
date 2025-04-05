/*
TRABALHO 1 - AlGORITMOS I

INTEGRANTES: FERNANDO HIROSHI MURUSAKI e IGOR DOS REIS GOMES
*/

#include <stdio.h>
#include <math.h>

int main() {
    int cod1, cod2, cod3, x=1;
    double resultado, angulo, radiano;

    printf("--CALCULADORA DE FUNCOES TRIGONOMETRICAS--\n\nDIGITE O CODIGO DA OPERACAO DESEJADA\n");
    while (x != 0) {
        printf("\n1-SENO\n2-COSSENO\n3-TANGENTE\n4-SECANTE\n5-COSSECANTE\n6-COTANGENTE\n7-ARCO SENO\n8-ARCO COSSENO\n9-ARCO TANGENTE\n\n");
        scanf("%d", &cod1);
        switch (cod1) {
            case 1:
                printf("\nSENO. GOSTARIA DE INFORMAR O VALOR EM RADIANOS OU EM GRAUS?\n1-RADIANOS\n2-GRAUS\n\n");
                scanf("%d", &cod2);
                switch (cod2) {
                    case 1:
                        printf("\nDIGITE O ANGULO EM RADIANOS\n\n");
                        scanf("%lf", &angulo);
                        resultado = sin(angulo);
                        printf("\nSENO DE %.2lf rad = %.2lf\n\n", angulo, resultado);
                        break;
                    case 2:
                        printf("\nDIGITE O ANGULO EM GRAUS\n\n");
                        scanf("%lf", &angulo);
                        radiano = angulo * M_PI / 180;
                        resultado = sin(radiano);
                        printf("\nSENO DE %.2lf graus = %.2lf\n\n", angulo, resultado);
                        break;
                    default:
                        printf("\nCODIGO INVALIDO.\n\n");
                        break;
                }
                break;
            case 2:
                printf("\nCOSSENO. GOSTARIA DE INFORMAR O VALOR EM RADIANOS OU EM GRAUS?\n1-RADIANOS\n2-GRAUS\n\n");
                scanf("%d", &cod2);
                switch (cod2) {
                    case 1:
                        printf("\nDIGITE O ANGULO EM RADIANOS\n\n");
                        scanf("%lf", &angulo);
                        resultado = cos(angulo);
                        printf("\nCOSSENO DE %.2lf rad = %.2lf\n\n", angulo, resultado);
                        break;
                    case 2:
                        printf("\nDIGITE O ANGULO EM GRAUS\n\n");
                        scanf("%lf", &angulo);
                        radiano = angulo * M_PI / 180;
                        resultado = cos(radiano);
                        printf("\nCOSSENO DE %.2lf graus = %.2lf\n\n", angulo, resultado);
                        break;
                    default:
                        printf("\nCODIGO INVALIDO.\n\n");
                        break;
                }
                break;
            case 3:
                printf("\nTANGENTE. GOSTARIA DE INFORMAR O VALOR EM RADIANOS OU EM GRAUS?\n1-RADIANOS\n2-GRAUS\n\n");
                scanf("%d", &cod2);
                switch (cod2) {
                    case 1:
                        printf("\nDIGITE O ANGULO EM RADIANOS\n\n");
                        scanf("%lf", &angulo);
                        resultado = tan(angulo);

                        if (angulo == 1.57 || angulo == 4.71) {
                            printf("\nTANGENTE DE %.2lf rad NAO EXISTE\n\n", angulo);
                        }
                        else
                            printf("\nTANGENTE DE %.2lf rad = %.2lf\n\n", angulo, resultado);
                        break;
                    case 2:
                        printf("\nDIGITE O ANGULO EM GRAUS\n\n");
                        scanf("%lf", &angulo);
                        radiano = angulo * M_PI / 180;
                        resultado = tan(radiano);

                        if (angulo == 90 || angulo == 270) {
                            printf("\nTANGENTE DE %.2lf rad NAO EXISTE\n\n", angulo);
                        }
                        else
                            printf("\nTANGENTE DE %.2lf graus = %.2lf\n\n", angulo, resultado);
                        break;
                    default:
                        printf("\nCODIGO INVALIDO.\n\n");
                        break;
                }
                break;
            case 4:
                printf("\nSECANTE. GOSTARIA DE INFORMAR O VALOR EM RADIANOS OU EM GRAUS?\n1-RADIANOS\n2-GRAUS\n\n");
                scanf("%d", &cod2);
                switch (cod2) {
                    case 1:
                        printf("\nDIGITE O ANGULO EM RADIANOS\n\n");
                        scanf("%lf", &angulo);
                        if (cos(angulo) == 0) {
                            printf("\nVALOR INVALIDO. O COSSENO DO ANGULO NAO PODE SER ZERO.\n\n");
                        } else {
                            resultado = 1/cos(angulo);
                            printf("\nSECANTE DE %.2lf rad = %.2lf\n\n", angulo, resultado);
                        }
                        break;
                    case 2:
                        printf("\nDIGITE O ANGULO EM GRAUS\n\n");
                        scanf("%lf", &angulo);
                        radiano = angulo * M_PI / 180;
                        if (cos(radiano) == 0) {
                            printf("\nVALOR INVALIDO. O COSSENO DO ANGULO NAO PODE SER ZERO.\n\n");
                        } else {
                            resultado = 1/cos(radiano);
                            printf("\nSECANTE DE %.2lf graus = %.2lf\n\n", angulo, resultado);
                        }
                        break;
                    default:
                        printf("\nCODIGO INVALIDO.\n\n");
                        break;
                }
                break;
            case 5:
                printf("\nCOSSECANTE. GOSTARIA DE INFORMAR O VALOR EM RADIANOS OU EM GRAUS?\n1-RADIANOS\n2-GRAUS\n\n");
                scanf("%d", &cod2);
                switch (cod2) {
                    case 1:
                        printf("\nDIGITE O ANGULO EM RADIANOS\n\n");
                        scanf("%lf", &angulo);
                        if (sin(angulo) == 0) {
                            printf("\nVALOR INVALIDO. O SENO DO ANGULO NAO PODE SER ZERO.\n\n");
                        } else {
                            resultado = 1/sin(angulo);
                            printf("\nCOSSECANTE DE %.2lf rad = %.2lf\n\n", angulo, resultado);
                        }
                        break;
                    case 2:
                        printf("\nDIGITE O ANGULO EM GRAUS\n\n");
                        scanf("%lf", &angulo);
                        radiano = angulo * M_PI / 180;
                        if (sin(radiano) == 0) {
                            printf("\nVALOR INVALIDO. O SENO DO ANGULO NAO PODE SER ZERO.\n\n");
                        } else {
                            resultado = 1/sin(radiano);
                            printf("\nCOSSECANTE DE %.2lf graus = %.2lf\n\n", angulo, resultado);
                        }
                        break;
                    default:
                        printf("\nCODIGO INVALIDO.\n\n");
                        break;
                }
                break;
            case 6:
                printf("\nCOTANGENTE. GOSTARIA DE INFORMAR O VALOR EM RADIANOS OU EM GRAUS?\n1-RADIANOS\n2-GRAUS\n\n");
                scanf("%d", &cod2);
                switch (cod2) {
                    case 1:
                        printf("\nDIGITE O ANGULO EM RADIANOS\n\n");
                        scanf("%lf", &angulo);
                        if (tan(angulo) == 0) {
                            printf("\nVALOR INVALIDO. A TANGENTE DO ANGULO NAO PODE SER ZERO.\n\n");
                        } else {
                            resultado = 1/tan(angulo);
                            
                            if (angulo == 3.14 || angulo == 0 || angulo == 6.28) {
                                printf("\nCOTANGENTE DE %.2lf rad NAO EXISTE\n\n", angulo);
                            }
                            else
                                printf("\nCOTANGENTE DE %.2lf rad = %.2lf\n\n", angulo, resultado);
                        }
                        break;
                    case 2:
                        printf("\nDIGITE O ANGULO EM GRAUS\n\n");
                        scanf("%lf", &angulo);
                        radiano = angulo * M_PI / 180;
                        if (tan(radiano) == 0) {
                            printf("\nVALOR INVALIDO. A TANGENTE DO ANGULO NAO PODE SER ZERO.\n\n");
                        } else {
                            resultado = 1/tan(radiano);

                            if (angulo == 0 || angulo == 180 || angulo == 360) {
                                printf("\nCOTANGENTE DE %.2lf rad NAO EXISTE\n\n", angulo);
                            }
                            else
                                printf("\nCOTANGENTE DE %.2lf graus = %.2lf\n\n", angulo, resultado);
                        }
                        break;
                    default:
                        printf("\nCODIGO INVALIDO\n\n");
                        break;
                }
                break;
            case 7:
                printf("\nARCO SENO. DIGITE UM VALOR ENTRE -1 E 1.\n\n");
                scanf("%lf", &angulo);
                if (angulo < -1 || angulo > 1) {
                    printf("\nVALOR INVALIDO. DIGITE UM VALOR ENTRE -1 E 1.\n\n");
                } else {
                    resultado = asin(angulo);
                    printf("\nARCO SENO DE %.2lf = %.2lf rad\n\n", angulo, resultado);
                }
                break;
            case 8:
                printf("\nARCO COSSENO. DIGITE UM VALOR ENTRE -1 E 1.\n\n");
                scanf("%lf", &angulo);
                if (angulo < -1 || angulo > 1) {
                    printf("\nVALOR INVALIDO. DIGITE UM VALOR ENTRE -1 E 1.\n\n");
                } else {
                    resultado = acos(angulo);
                    printf("\nARCO COSSENO DE %.2lf = %.2lf rad\n\n", angulo, resultado);
                }
                break;
            case 9:
                printf("\nARCO TANGENTE. DIGITE UM VALOR.\n\n");
                scanf("%lf", &angulo);
                resultado = atan(angulo);
                printf("\nARCO TANGENTE DE %.2lf = %.2lf rad\n\n", angulo, resultado);
                break;
            default:
                printf ("\nCODIGO INVALIDO.\n\n");
                break;
        }
        printf("\nGOSTARIA DE USAR NOVAMENTE?\n1-SIM\n2-NAO\n\n");
        scanf("%d", &cod3);
        
        while (cod3 != 1 && cod3 != 2){
            printf("CODIGO INVALIDO. DIGITE NOVAMENTE: ");
            scanf("%d", &cod3);
        }

        if (cod3 == 1) {
            x = 1;
        }
        else if (cod3 != 1) {
            x = 0;
            printf("\nBYE BYEE!!\n");
        }
    }
    return 0;
}