#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct ranker
{
    int total_score;
    int s[5];
}rk[10010];
int p[5]= {0};
int main(){
    scanf("%d %d %d",&N,&K,&M);
    int uid,qid,score;
    for (int i = 0; i < K; i++)
    {
        scanf("%d",&p[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&uid,&qid,&score);
        rk[uid]
    }
    
}