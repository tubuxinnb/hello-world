#include <cstdio>
#include <string.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int c = a+b;
    char str[10];
    char str2[15];
    sprintf(str,"%d",c);
    int len = strlen(str);
    if (str[0] != '-')
    {
        for (int i = 0; i < len; i++)
        {
            printf("%c",str[i]);
            if (len - i == 7 && len > 6)
            {
                printf(",");
            }
            if (len - i == 4 && len > 3)
            {
                printf(",");
            }
        }
    }
    if (str[0] == '-')
    {
        printf("-");
        for (int i = 1; i < len; i++)
        {
            printf("%c",str[i]);
            if (len - i == 7 && len > 7)
            {
                printf(",");
            }
            if (len - i == 4 && len > 4)
            {
                printf(",");
            }
        }
    }
}