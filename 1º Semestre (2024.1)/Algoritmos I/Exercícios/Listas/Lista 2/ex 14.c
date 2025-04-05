#include <stdio.h>

int main () {
	float x, y;

	printf ("\n Digite dois numeros: ");
	scanf ("%f %f", &x, &y);

	printf ( "\n O produto de %4.3f e %4.3f eh %4.3f ", x, y, x*y );
	printf ( "\n O quociente de %4.3f e %4.3f eh %4.3f ", x, y, x/y);
}

