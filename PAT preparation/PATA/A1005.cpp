#include <cstdio>
#include <string.h>
int main(){
    char N[110];
    scanf("%s",N);
    int len = strlen(N);
    int sum = 0;
    int bases[5] = {0};
    char M[5][15];
    int num = 0;
    char ENG[15][15] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i = 0; i < len; i++)
    {
        sum += (N[i] - '0');
    }
    do
    {
        strcpy(M[num++] , ENG[sum%10]);
        sum /= 10;
    } while (sum != 0);
    for (int i = 0; i < num; i++)
    {
        printf("%s",M[num - 1 - i]);
        if (i < num - 1)
        {
            printf(" ");
        }
    }
}