#include <cstdio>
// 3
// CS301111 15:30:28 17:00:10
// SC3021234 08:00:00 11:25:25
// CS301133 21:45:00 21:58:40
struct time
{
    int HH;
    int MM;
    int SS;
    
};
struct stu
{
    char ID[16];
    time in;
    time out;
}temp,late,early;
void init(){
    late.in = {24,24,24};
    late.out = {0,0,0};
    early = late;
}
int TIM(time tbx)
{
    return(tbx.HH*3600+tbx.MM*60+tbx.SS);
}
int main(){
    init();
    int M = 0;
    scanf("%d",&M);
    for (int i = 0; i < M; i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d",&temp.ID,&temp.in.HH,&temp.in.MM,&temp.in.SS,&temp.out.HH,&temp.out.MM,&temp.out.SS);
        if (TIM(temp.in) < TIM(early.in))
        {
            early = temp;
        }
        if (TIM(temp.out) > TIM(late.out))
        {
            late = temp;
        }
    }
    printf("%s %s",early.ID,late.ID);
    return 0;
}