#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int toll [25];// 资费
struct Record {
    char name[25];// 姓名
    int month, dd, hh, mm; //月份、日、时、分
    bool status;//status=true表示on-line, otherwise it is off-1ine
}rec[maxn], temp;
bool cmp(Record a,Record b){
    int s=strcmp(a.name,b.name);
    if(s!=0) return s<0;
    else if(a.month!=b.month) return a.month<b.month;
    else if(a.dd!=b.dd) return a.dd<b.dd;
    else if(a.hh!=b.hh) return a.hh<b.hh;
    else return a.mm<b.mm;
}
void get_ans(int on,int off,int &time,int &money){
    temp=rec[on];
    while(temp.dd<rec[off].dd || temp.hh<rec[off].hh || temp.mm<rec[off].mm){
        time++;//该次记录总时间加1min
        money+=toll[temp.hh];
        temp.mm++;
        if(temp.mm>=60){
            temp.mm=0;
            temp.hh++;
        }
        if(temp.hh>=24){
            temp.hh=0;
            temp.dd++;
        }
    }
}
int main(){
    for(int i=0;i<24;i++){
        scanf("%d",&toll[i]);
    }
    int n;
    scanf("%d",&n);
    char line[10];//临时存放on-line或off-line的输入
    for(int i=0;i<n;i++){
        scanf("%s",rec[i].name);
        scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
        scanf("%s", line);
        if(!strcmp(line,"on-line")){
            rec[i].status=true;
        }
        else
            rec[i].status=false;
    }
    sort(rec,rec+n,cmp);
    int on=0,off,next;//on和off为配对的两条记录，next为下一个用户
    while(on<n){
        int needPrint=0;
        next=on;
        while(next<n && strcmp(rec[next].name,rec[on].name)==0){
            if(needPrint==0 && rec[next].status==true)
                needPrint=1;//找到on，置needPrint为1
            else if(needPrint==1 && rec[next].status==false)
                needPrint=2;//在on之后找到off，置needPrint为2
            next++;//next自增，直到找到不同名字，即下一个用户
        }
        if(needPrint<2){
            on=next;
            continue;
        }
        int Allmoney=0;
        printf("%s %02d\n",rec[on].name,rec[on].month);
        while(on<next){
            while(on<next-1 && !(rec[on].status==true && rec[on+1].status==false))
                on++;//直到找到连续的on-line和off-line
            off = on+1;
            if(off==next){//已经输出完毕所有配对的
                on=next;
                break;
            }
            printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
            printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
            int time=0,money=0;
            get_ans(on,off,time,money);
            Allmoney+=money;
            printf("%d $%.2f\n",time,money/100.0);
            on=off+1;
        }
        printf("Total amount: $%.2f\n",Allmoney/100.0);
    }
    return 0;
}