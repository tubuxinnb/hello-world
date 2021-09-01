#include <cstdio>
struct stu
{
    char name[15];
    char ID[15];
    int grade;
    char gender;
}temp,fh,ml;

int main(){
    int N = 0;
    fh.grade = -1;
    ml.grade = 101;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %s %d",temp.name,&temp.gender,temp.ID,&temp.grade);
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
    if ((ml.grade == 101) || (fh.grade == -1))
    {
        printf("NA");
    }
    else
    {
        printf("%d",fh.grade - ml.grade);
    }
    return 0;
}