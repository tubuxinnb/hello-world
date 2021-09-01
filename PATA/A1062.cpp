#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct person  
{
    char ID_Number[20];
    int Virture_Grade;
    int Talent_Grade;
    int Total_Grade;
    int level;
}people[100010];
bool cmp(person a, person b)
{
    if (a.level == b.level)
    {
        if (a.Total_Grade == b.Total_Grade)
        {
            if (a.Virture_Grade == b.Virture_Grade)
            {
                return strcmp(a.ID_Number,b.ID_Number) < 0;
            }
            else
            {
                return a.Virture_Grade > b.Virture_Grade;
            }
        }
        else
        {
            return a.Total_Grade > b.Total_Grade;
        }
    }
    else
    {
        return a.level < b.level;
    }
}
//N:total num, L:low bound, H higher line for sage
int main(){
    int N,L,H,num = 0;
    scanf("%d %d %d",&N,&L,&H);
    for (int i = 0; i < N; i++)
    {
        person temp;
        scanf("%s %d %d",temp.ID_Number,&temp.Virture_Grade,&temp.Talent_Grade);
        temp.Total_Grade = temp.Virture_Grade + temp.Talent_Grade;
        if (temp.Virture_Grade < L || temp.Talent_Grade < L)
        {
            continue;
        }
        else if (temp.Virture_Grade < H && temp.Talent_Grade < H)
        {
            if (temp.Virture_Grade >= temp.Talent_Grade)
            {
                temp.level = 3;
                people[num] = temp;
            }
            else
            {
                temp.level = 4;
                people[num] = temp;
            }
        }
        else if (temp.Talent_Grade < H && temp.Virture_Grade >= H)
        {
            temp.level = 2;
            people[num] = temp;
        }
        else if (temp.Talent_Grade >= H && temp.Virture_Grade < H)
        {
            temp.level = 4;
            people[num] = temp;
        }
        else
        {
            temp.level = 1;
            people[num] = temp;
        }
        num++;
    }
    printf("%d\n",num);
    sort(people,people + num,cmp);
    for (int i = 0; i < num; i++)
    {
        printf("%s %d %d\n",people[i].ID_Number,people[i].Virture_Grade,people[i].Talent_Grade);
    }
}