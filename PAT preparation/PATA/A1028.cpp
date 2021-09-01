#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int C,N;
struct student 
{
    int id;
    char name[9];
    int grade;
} stu[100100];
bool cmp(student a, student b)
{
    if (C == 1)
    {
        if (a.id != b.id)
        {
            return a.id < b.id;
        }
    }
    else if (C == 2)
    {
        if (strcmp(a.name,b.name) != 0)
        {
            return strcmp(a.name,b.name) < 0;
        }
    }
    else
    {
        if (a.grade != b.grade)
        {
            return a.grade < b.grade;
        }
    }
    return  a.id < b.id;
}

int main(void)
{
    scanf("%d %d",&N,&C);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s %d",&stu[i].id,&stu[i].name,&stu[i].grade);
    }
    sort(stu,stu+N,cmp);
    for (int i = 0; i < N; i++)
    {
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    }
    return 0;
}