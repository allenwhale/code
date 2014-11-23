#include <stdio.h>
int Judge(int *num, int N);
int main()
{
    int i, N, num[1000], first = 0;
    while(scanf("%d", &N) == 1 && N){
        while(scanf("%d", &num[0]) && num[0]){
            for(i = 1; i < N; i++)
                scanf("%d", &num[i]);
            puts(Judge(num, N)?"Yes":"No");
        }
        puts("");
    }
    return 0;
}
int Judge(int *num, int N){
    int *stack = new int [N], top = -1, i, j;
    for(i = 0, j = 1; i < N; i++){
        for(j; j <= N; j++){
            if(j == num[i])   {j++;  break;}
            if(top != -1 && stack[top] == num[i])   {top--;  break;}
            if(j != num[i])   stack[++top] = j;
        }
        if(j > N && stack[top] == num[i])
            top--;
    }
    return (top == -1)?1:0;
}
