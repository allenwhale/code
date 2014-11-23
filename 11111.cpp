#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
using namespace std;
int main()
{
    char s[100000];
    int num[100000];
    while(gets(s)!=NULL)
    {
        int cnt=0;
        char *ptr=strtok(s," ");
        while(ptr!=NULL)
        {
            sscanf(ptr,"%d",&num[cnt++]);
            ptr=strtok(NULL," ");
        }
        bool tf=true;
        stack<int>st;
        for(int i=0;i<cnt&&tf;i++)
        {
            if(num[i]<0)
            {
                st.push(num[i]);
            }
            else
            {
                if(st.size()==0)tf=false;
                else if(st.top()!=-num[i])tf=false;
                st.pop();             
            }
        }
        if(st.size()!=0)tf=false;
        //printf("%d\n",tf);
        stack<pair<int,int> >st2;
        for(int i=0;i<cnt&&tf;i++)
        {
            if(num[i]<0)
            {
                if(st2.size()>0)
                {
                    pair<int,int> tmp=st2.top();
                    st2.pop();
                    st2.push(make_pair(tmp.first,tmp.second-num[i]));
                }
                st2.push(make_pair(-num[i],0));
            }
            else
            {
                pair<int,int> tmp=st2.top();st2.pop();
                if(tmp.second>=tmp.first)tf=false;
            }
        }
        if(tf)puts(":-) Matrioshka!");
        else puts(":-( Try again.");
    }
}
