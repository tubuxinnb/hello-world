#include <cstdio>
#include <math.h>
int main(){
    int M[50];
    int N,b,num = 0,p = 2;
    scanf("%d %d",&N,&b);
    do
    {
        M[num++] = N%b;
        N /= b;
    } while (N != 0);
    for (int i = 0; i < num/2+1; i++)
    {
        if (M[i] != M[num-i-1])
        {
            printf("No\n");
            break;
        }
        if (i == num/2)
        {
            printf("Yes\n");
        }
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d",M[num-i-1]);
        if(i != num - 1) printf(" ");
    }
    return 0;
}