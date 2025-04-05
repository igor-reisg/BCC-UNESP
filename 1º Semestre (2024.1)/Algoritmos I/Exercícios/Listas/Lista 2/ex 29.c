#include <stdio.h>
#include<math.h>

int main()
{
    
    float a, b, elev;
    
    printf("Digite 2 números: ");
    scanf("%f %f", &a, &b);
    
    elev = pow(a, b);
    
    printf("%.2f elevado a %.2f é %.2f", a, b, elev);

    return 0;
}
