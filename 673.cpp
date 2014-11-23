#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
int main()
{
    int N;
    scanf("%d%*c",&N);
    char s[200];
    
    while(N--)
    {
        gets(s);
        stack<char>st;
        int len=strlen(s);
        int a=0;
        int tf=true;
        for(int i=0;i<len&&tf;i++)
        {
            if(s[i]=='('||s[i]=='[')st.push(s[i]);
            else
            {
                if(st.size()==0)tf=false;
                else if(s[i]==']'&&st.top()!='[')tf=false;
                else if(s[i]==')'&st.top()!='(')tf=false;
                if(st.size()!=0)st.pop();
            }
        }
        if(st.size()==0&&tf)puts("Yes");
        else puts("No");
    }
    //while(1);
}
