#include<cstdio>
void func(int n)
{
    int a = n%10;
    if (n/10 != 0)
    {
        func(n/10);
    }
    printf("%d ",a);
}
int main()
{
    func(8712);
}