#include <bits/stdc++.h>
using namespace std;
void Solve()
{
    char N[150], A[150] = {0}, B[150] = {0};
    scanf("%s", N);
    int len = strlen(N);
    for (int i = 0; i < len; i++)
    {
        if (N[i] == '4')
        {
            A[i] = '1';
            B[i] = '3';
        }
        else
        {
            A[i] = N[i];
            B[i] = '0';
        }
    }
    bool start = true;
    for (int i = 0; i < len; i++)
    {
        if (A[i] == '0' && start == true)
        {
        }
        else
        {
            start = false;
            printf("%c", A[i]);
        }
    }
    printf(" ");
    start = true;
    for (int i = 0; i < len; i++)
    {
        if (B[i] == '0' && start == true)
        {
        }
        else
        {
            start = false;
            printf("%c", B[i]);
        }
    }
    printf("\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);
        Solve();
    }
}