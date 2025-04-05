#include <stdio.h>
#include <math.h>

int main () {

    float r, vol;

    for (r = 0; r <= 20; r += 0.5) {
        
        vol = (float)4/3*M_PI*pow(r, 3);

        printf("raio de %.1f cm:\nvolume = %.2f cm\n", r, vol);
    }
}