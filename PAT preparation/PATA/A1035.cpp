#include <cstdio>
#include <string.h>
struct account
{
    char username[12];
    char password[12];
    bool modified;
};
int main(){
    int n;
    scanf("%d",&n);
    struct account user[n];
    int m = 0;
    for (int j = 0; j < n; j++)
    {
        scanf("%s %s",user[j].username,user[j].password);
        user[j].modified = false;
        for (int i = 0; i < strlen(user[j].password); i++)
        {
            if(user[j].password[i] == '0')
            {
                user[j].password[i] = '%';
                user[j].modified = true;
            }
            else if (user[j].password[i] == 'l')
            {
                user[j].password[i] = 'L';
                user[j].modified = true;
            }
            else if (user[j].password[i] == 'O')
            {
                user[j].password[i] = 'o';
                user[j].modified = true;
            }
            else if (user[j].password[i] == '1')
            {
                user[j].password[i] = '@';
                user[j].modified = true;
            }
        }
        if (user[j].modified == true)
            {
                m++;
            }
    }
    if (m != 0)
    {
        printf("%d\n",m);
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            if (user[j].modified)
            {
                printf("%s %s",user[j].username,user[j].password);
                ++num;
                if (num < m)
                {
                    printf("\n");
                }
            }
        }
    }
    else if (n == 1)
    {
        printf("There is 1 account and no account is modified");
    }
    else
    {
        printf("There are %d accounts and no account is modified",n);
    }
    return 0;
}