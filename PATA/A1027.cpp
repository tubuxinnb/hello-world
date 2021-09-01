#include <cstdio>
#include <math.h>
int main(){
    int color[3];
    char MRGB[10];
    char T[15] = "0123456789ABC";
    scanf("%d %d %d",&color[0],&color[1],&color[2]);
    for (int i = 0; i < 3; i++)
    {
        int a = color[i]%13;
        int b = color[i]/13;
        MRGB[2*i] = T[b];
        MRGB[2*i+1] = T[a];
    }
    MRGB[7] = '\0';
    printf("#%s",MRGB);
}