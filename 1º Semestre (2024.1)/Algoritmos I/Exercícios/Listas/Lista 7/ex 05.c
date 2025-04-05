#include <stdio.h>

int main () {

	int n = 1, num, soma = 0, i, teste = 1;

	while (n != 0) {
		
		scanf("%d", &n);

		for (i = 0; i < n; i++) {

			scanf("%d", &num);
			
            soma += num;
		}

		printf("Teste %d\n%d\n\n", teste++, soma);

        soma = 0;
	}
}