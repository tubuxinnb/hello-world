#include <cstdio>
#include <math.h>
int main(){
    float rate[3];
    float max = 0.0;
    float sum = 1.0;
    char x[4];
    char WTL[4] = "WTl";
    for (int i = 0; i < 3; i++)
    {
        scanf("%f %f %f",&rate[0],&rate[1],&rate[2]);
        for (int j = 0; j < 3; j++)
        {
            if (rate[j] > max)
            {
                max = rate[j];
                x[i] = WTL[j];
            }
        }
        sum *= max;
    }
    sum = (sum*0.65-1)*2;
    printf("%c %c %c %.2f",x[0],x[1],x[2],round(sum*100)/100);
}