#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct people
{
    char name[10];
    int age;
    int net_worth;
}per[101000],val[30000];
bool cmp_case(people a, people b)
{
    if (a.net_worth != b.net_worth)
    {
        return a.net_worth > b.net_worth;
    }
    else if (a.age != b.age)
    {
        return a.age < b.age;
    }
    else
    {
        return strcmp(a.name,b.name)<0;
    }
}
int main(){
    int N,K,Age[200] = {0};
    scanf("%d %d",&N,&K);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d",per[i].name,&per[i].age,&per[i].net_worth);
    }
    int num = 0;
    sort(per,per+N,cmp_case);
    for (int i = 0; i < N; i++)
    {
        if (Age[per[i].age] < 100)
        {
            Age[per[i].age]++;
            val[num++] = per[i];
        }
    }
    int M,Amin,Amax;
    for (int i = 0; i < K; i++)
    {
        int printnum = 0;
        scanf("%d %d %d",&M,&Amin,&Amax);
        printf("Case #%d:\n",i+1);
        for (int j = 0; j < num && printnum < M; j++)
        {
            if ( Amin<=val[j].age && Amax>=val[j].age)
            {
                printf("%s %d %d\n",val[j].name,val[j].age,val[j].net_worth);
                printnum++;
            }
        }
        if (printnum == 0)
        {
            printf("None\n");
        }
    }
    return 0;
}