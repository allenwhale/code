#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;
list<string>vc;
char s[100010];
int mth=0;
void push(char _s[])
{
    if(strlen(_s)==0)return;
    if(mth==0)vc.push_back(_s);
    else vc.push_front(_s);
}
int main()
{
    while(gets(s)!=NULL)
    {
        int len=strlen(s);
        vc.clear();
        char tmp[10100]={0};
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            //printf("%c\n",s[i]);
            if(s[i]=='[')
            {
                push(tmp);
                //memset(tmp,0,sizeof(tmp));
                tmp[0]=0;
                cnt=0;
                mth=1;
            }
            else if(s[i]==']')
            {
                push(tmp);
                //memset(tmp,0,sizeof(tmp));
                tmp[0]=0;
                cnt=0;
                mth=0;
            }
            else
            {
                tmp[cnt++]=s[i];
                tmp[cnt]=0;
            }
        }
        push(tmp);
        for(list<string>::iterator it=vc.begin();it!=vc.end();it++)
        {
            cout<<*it;
        }
        puts("");
    }
   
}

