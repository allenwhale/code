#include <stdio.h>
#include <string.h>
char str[1000001];
int main()
{
    while(gets(str)){
        if(!strcmp(str, "END"))   break;
        int len = strlen(str), Ans = 1;
        if(!strcmp(str, "1"))    {puts("1");   continue;}
        while(len > 1){
            int temp = len;
            len = 0;
            while(temp > 0)
                len++, temp /= 10;
            Ans++;
        }
        printf("%d\n", Ans+1);
    }
    return 0;
}
