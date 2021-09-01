#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student
{
    int id;
    int grade[4];
    int best_rank;
    int cur_rank;
    int best_lesson;
} stu[2010];
char dic[5] = "ACME";
int now = 0;
bool cmp(student a,student b)
{
    return a.grade[now] > b.grade[now];
}
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for (int i = 0; i < N; i++)
    {
        int a,b,c,d,e;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        stu[i].id = a;
        e = (b+c+d)/3;
        stu[i] = {a,{e,b,c,d},9999,0};
    }
    while (now <= 3)
    {
        sort(stu,stu+N,cmp);
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                stu[i].cur_rank = 1;
            }
            else if (stu[i].grade[now] == stu[i-1].grade[now])
            {
                stu[i].cur_rank = stu[i-1].cur_rank;
            }
            else
            {
                stu[i].cur_rank = i + 1;
            }
            if (stu[i].cur_rank < stu[i].best_rank)
            {
                stu[i].best_rank = stu[i].cur_rank;
                stu[i].best_lesson = now;
            }
        }
        now++;
    }
    for (int i = 0; i < M; i++)
    {
        int temp;
        scanf("%d",&temp);
        for (int j = 0; j < N; j++)
        {
            if (temp == stu[j].id)
            {
                printf("%d %c\n",stu[j].best_rank,dic[stu[j].best_lesson]);
                break;
            }
            else if (j == N - 1)
            {
                printf("N/A\n");
            }
        }
    }
}