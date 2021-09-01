#include <cstdio>
#include <math.h>
#include <string.h>
int main(){
    char str[10010];
    char str1[10010];
    char str2[10];
    scanf("%s",str);
    char a = str[0];
    int  b = str[1] - '0';
    char c;
    int num = 3;
    int len = strlen(str);
    for (;str[num] != 'E'; num++)
    {
        str1[num - 3] = str[num];
    }
    num = num + 1;
    c = str[num++];
    for (int i = num; i < len; i++)
    {
        str2[i - num] = str[i];
    }
    // a,c:两个符号, b:整数部分, str1 小数部分, str2 指数部分
    int y = strlen(str1);
    int len2 = strlen(str2);
    int x = 0;
    for (int i = 0; i < len2; i++)
    {
        int temp = (str2[i] - '0')*pow(10,len2 - i - 1);
        x+= temp;
    }
    if (a == '-')
    {
        printf("-");
    }
    if (c == '-')
    {
        if (x == 1)
        {
            printf("0.%d%s",b,str1);
        }
        else if (x > 1)
        {
            printf("0.");
            for (int i = 0; i < x - 1; i++)
            {
                printf("0");
            }
            printf("%d%s",b,str1);
        }
    }
    else if (c == '+')
    {
        printf("%d",b);
        if (y - x > 0)
        {
            
            for (int i = 0; i < y; i++)
            {
                if (i == x)
                {
                    printf(".");
                }
                printf("%c",str1[i]);
            }
        }
        else if (y - x == 0)
        {
            printf("%s",str1);
        }
        else
        {
            printf("%s",str1);
            for (int i = 0; i < x - y; i++)
            {
                printf("0");
            }
        }
    }
}