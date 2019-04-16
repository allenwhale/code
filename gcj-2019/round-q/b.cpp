#include <bits/stdc++.h>
using namespace std;
char s[500010];
void Solve()
{
    int N;
    scanf("%d", &N);
    scanf("%s", s);
    for (int i = 0; i < 2 * N - 2; i++)
    {
        if (s[i] == 'S')
            printf("E");
        else
            printf("S");
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
    return 0;
}