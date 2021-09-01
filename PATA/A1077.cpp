#include <cstdio>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    char str[n+1][266];
    int minlen = 256;
    getchar();
    for (int i = 0; i < n; i++)
    {
        fgets(str[i],266,stdin);
        int len = strlen(str[i]);
        str[i][len - 1] = '\0';
        len = len - 1;
        minlen = len < minlen?len:minlen;
        for (int j = 0; j < len/2; j++)
        {
            char temp = str[i][j];
            str[i][j] = str[i][len - 1 - j];
            str[i][len - 1 - j] = temp;
        }
    }
    int maxlen = 0;
    int flag = 0;
    for (int i = 0; i < minlen; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (str[j-1][i] == str[j][i])
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
        else
        {
            maxlen++;
        }
    }
    for (int i = 0; i < maxlen; i++)
    {
        printf("%c",str[0][maxlen - 1 - i]);
    }
}
// 求后缀 == 字符串倒置 == 相同前缀 == 整齐下标，方便操作 ，学到了！