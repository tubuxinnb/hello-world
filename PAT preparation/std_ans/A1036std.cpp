#include <cstdio>
#include <string.h>
struct stu
{
    char name[15];
    char gender;
    char ID[15];
    int grade;
};

int main(){
    int N = 0;
    stu temp,fh,ml;
    fh.grade = -1;
    ml.grade = 101;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %c %s %d",temp.name,&temp.gender,temp.ID,&temp.grade);
        if (temp.gender == 'F')
        {
            if (temp.grade > fh.grade)
            {
                fh = temp;
            }
        }
        else if (temp.gender == 'M')
        {
            if (temp.grade < ml.grade)
            {
                ml = temp;
            }
        }
    }
    if (fh.grade == -1)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n",fh.name,fh.ID);
    }
    if (ml.grade == 101)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n",ml.name,ml.ID);
    }
    if ((ml.grade == 101) || (fh.gender == -1))
    {
        printf("NA");
    }
    else
    {
        printf("%d",fh.grade - ml.grade);
    }
    return 0;
}