#include <cstdio>
#include <string.h>
int main(){
    char num[12];
    int flag1 = 0,flag2 = 0,flag3 = 0;
    char pinyin[10][15] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char base[5][10] = {"Shi","Bai","Qian"};
    while(scanf("%s",num)!=EOF)
    {
    int len = strlen(num);
    if (num[0] == '-')
    {
        printf("Fu ");
        for (int i = 0; i < len; i++)
        {
            num[i] = num[i+1];
        }
        len -= 1;
    }
    int lens = len;
    int out = 0;
    if (len == 9)
    {
        printf("%s Yi",pinyin[num[0]-'0']);
        len -= 1;
        flag1 = 1;
        flag3 = 1;
    }
    if (len < 9 && len >=5)
    {
        do
        {
            if (num[lens - len] != '0' && flag1 == 1)
            {
                printf(" %s",pinyin[num[lens - len] - '0']);
                out = 1;
                if (len >= 6)
                {
                    printf(" %s",base[len - 6]);
                }
            }
            else if (num[lens - len] != '0' && flag1 == 0 && flag2 == 1)
            {
                printf(" ling %s",pinyin[num[lens - len] - '0']);
                out = 1;
                if (len >= 6)
                {
                    printf(" %s",base[len - 6]);
                }
                flag1 = 1;
            }
            
            else if (num[lens - len] != '0' && flag1 == 0 && flag2 == 0)
            {
                printf("%s",pinyin[num[lens - len] - '0']);
                out = 1;
                if (len >= 6)
                {
                    printf(" %s",base[len - 6]);
                }
                flag1 = 1;
            }

            else if (num[lens - len] == '0' && flag1 == 1)
            {
                flag1 = 0;
                flag2 = 1;
            }
            else if (num[lens - len] != '0' && flag1 == 0)
            {
                continue;
            }
            --len;
        } while (len > 4);
        if (out  == 1)
        {
            printf(" Wan");
            flag3 = 1;
            flag1 = 1;
        }
        
    }
    if (len <=4 && len > 0)
    {
        do
        {
            if (num[lens - len] != '0' && flag1 == 1)
            {
                printf(" %s",pinyin[num[lens - len] - '0']);
                flag3 = 1;
                if (len >= 2)
                {
                    printf(" %s",base[len - 2]);
                }
            }
            else if (num[lens - len] != '0' && flag1 == 0 && flag2 == 1)
            {
                printf(" ling %s",pinyin[num[lens - len] - '0']);
                flag3 = 1;
                if (len >= 2)
                {
                    printf(" %s",base[len - 2]);
                }
                flag1 = 1;
            }
            
            else if (num[lens - len] != '0' && flag1 == 0 && flag2 == 0)
            {
                printf("%s",pinyin[num[lens - len] - '0']);
                flag3 = 1;
                if (len >= 2)
                {
                    printf(" %s",base[len - 2]);
                }
                flag1 = 1;
            }
            else if (num[lens - len] == '0' && flag1 == 1)
            {
                flag1 = 0;
                flag2 = 1;
            }
            else if (num[lens - len] != '0' && flag1 == 0)
            {
                continue;
            }
            --len;
        } while (len != 0);
    }
    if (flag3 == 0)
    {
        printf("ling");
    }
    }
}