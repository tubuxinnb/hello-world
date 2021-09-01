#include <cstdio>
#include <math.h>
#include <string.h>
int main(){
    char A[5][70];
    char date[5];
    int flag = 0;
    scanf("%s",A[0]);
    scanf("%s",A[1]);
    scanf("%s",A[2]);
    scanf("%s",A[3]);
    for (int i = 0; i < strlen(A[0]) && i < strlen(A[1]); i++)
    {
        if (A[0][i] == A[1][i] && flag == 0 && A[0][i] >= 'A' && A[1][i] <= 'G') 
        {
            date[flag++] = A[0][i];
        }
        else if (flag == 1 && A[0][i] == A[1][i])
        {
            if ((A[0][i] >= 'A' && A[1][i] <= 'N') || (A[0][i] >= '0' && A[1][i] <= '9'))
            {
                date[flag++] = A[0][i];
            }
            
        }
    }
    for (int i = 0; i < strlen(A[2]) && i < strlen(A[3]); i++)
    {
        if (A[2][i] == A[3][i] && flag == 2 )
        {
            if ((A[2][i] >= 'a' && A[2][i] <= 'z') || (A[2][i] >= 'A' && A[2][i] <= 'Z'))
            {
                date[flag++] = i;
            }
        }
    }
    char week[10][20] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    char hour[25] = "0123456789ABCDEFGHIJKLMN";
    printf("%s ",week[date[0] - 'A']);
    int h = date[1]-'A'+10;
    if (date[1] > '9')
    {
        printf("%02d:%02d",h,date[2]);
    }
}