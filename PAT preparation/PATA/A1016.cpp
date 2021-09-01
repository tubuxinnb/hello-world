#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct record
{
    char name[30];
    int date[4];
    bool line;

}rec[1100];
int rate[24];
int total_rate = 0;
bool cmp(record a,record b)
{
    if (strcmp(a.name,b.name)!=0)
    {
        return strcmp(a.name,b.name)<0;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (a.date[i] != b.date[i])
            {
                return a.date[i] < b.date[i];
            }
        }
        return a.line;
    }    
}
float total_money(record a,record b)
{
    float sum = 0;
    int d = a.date[1] - b.date[1];
    sum += 60*d*total_rate;
    if (a.date[2] < b.date[2])
    {
        record temp = a;
        a = b;
        b = temp;
    }
    for (int i = 0; ; i++)
    {
        for (int j = 1; j <= 60; j++)
        {
            sum += rate[b.date[2]];
            ++b.date[3];
            if (b.date[3] == a.date[3] && b.date[2] == a.date[2])
            {
                break;
            }
            else if (b.date[3] == 60)
            {
                b.date[3] = 0;
                b.date[2]++;
                break;
            }
        }

        if (b.date[2] == a.date[2] && b.date[3] == a.date[3])
        {
            break;
        }
    }
    sum /= 100;
    return sum;
}
int total_min(record a,record b)
{
    return (a.date[1] - b.date[1])*24*60 + (a.date[2] - b.date[2])*60 + (a.date[3] - b.date[3]);
}
int main(){
    int n;
    char str[10];
    for (int i = 0; i < 24; i++)
    {
        scanf("%d",&rate[i]);
        total_rate += rate[i];
    }
    
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",rec[i].name);
        scanf("%02d:%02d:%02d:%02d",&rec[i].date[0],&rec[i].date[1],&rec[i].date[2],&rec[i].date[3]);
        scanf("%s",str);
        if (strcmp(str,"on-line") == 0)
        {
            rec[i].line = true;
        }
        else
        {
            rec[i].line = false;
        }
    }
    sort(rec,rec+n,cmp);
    record temp;
    int flag = 0,sum1 = 0;
    float sum2 = 0.0;
    temp = rec[0];
    printf("%s %02d\n",temp.name,temp.date[0]);
    for (int i = 0; i < n; i++)
    {
        int amount;
        if (strcmp(temp.name,rec[i].name) == 0)
        {
            if (rec[i].line)
            {
                temp = rec[i];
                flag = 1;
            }
            else if (temp.line && flag == 1)
            {
                amount = total_min(rec[i],temp);
                sum2 += total_money(rec[i],temp);
                printf("%02d:%02d:%02d",temp.date[1],temp.date[2],temp.date[3]);
                printf(" %02d:%02d:%02d %d $%.02f\n",rec[i].date[1],rec[i].date[2],rec[i].date[3],amount,total_money(rec[i],temp));
                flag = 0;
                temp = rec[i];
            }
        }
        else
        {
            printf("Total amount: $%.02f\n",sum2);
            temp = rec[i];
            printf("%s %02d\n",temp.name,temp.date[0]);
            flag = 0;
            if (temp.line)
            {
                flag = 1;
            }
            sum2 = 0;
        }
        if (i == n - 1)
        {
            printf("Total amount: $%.02f\n",sum2);
            temp = rec[i];
        }
    }
}