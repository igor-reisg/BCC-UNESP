#include <stdio.h>
#include <string.h>

int main () {

    int i, v[6] = {0, 0, 1, 1, 4, 5};
    char c[6][4];
    
    strcpy (c[0],"seg");
    strcpy (c[1],"ter");
    strcpy (c[2],"qua");
    strcpy (c[4],"sex");
    strcpy (c[5],"sab");
    
    i = 0;
    
    while (i < 6) {
        printf ("%s\n",c[v[i]]);
        i += 2;
    }
    printf ("%s\n",c[v[v[2]]]);
}

/* 
No programa será impresso:

seg
ter
sex
seg

*/