#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
vector<char>vc[300];
char k[300000];
void add(int a,char s)
{
	vc[a].push_back(s);
}
int main()
{
	add((int)'\'',';');
	add((int)'\\',']');
	add((int)'1','`');
	add((int)'2','1');
	add((int)'W','Q');
	add((int)'S','A');
	add((int)'X','Z');
	add((int)'3','2');
	add((int)'E','W');
	add((int)'D','S');
	add((int)'C','X');
	add((int)'4','3');
	add((int)'R','E');
	add((int)'F','D');
	add((int)'V','C');
	add((int)'5','4');
	add((int)'T','R');
	add((int)'G','F');
	add((int)'B','V');
	add((int)'6','5');
	add((int)'Y','T');
	add((int)'H','G');
	add((int)'N','B');
	add((int)'7','6');
	add((int)'U','Y');
	add((int)'J','H');
	add((int)'M','N');
	add((int)'8','7');
	add((int)'I','U');
	add((int)'K','J');
	add((int)',','M');
	add((int)'9','8');
	add((int)'O','I');
	add((int)'L','K');
	add((int)'.',',');
	add((int)'0','9');
	add((int)'P','O');
	add((int)';','L');
	add((int)'/','.');
	add((int)'-','0');
	add((int)'=','-');
	add((int)'[','P');
	add((int)']','[');
	add((int)' ',' ');
	while(gets(k)!=NULL)
	{
		int len=strlen(k);
		for(int i=0;i<len;i++)
		{
			printf("%c",vc[(int)k[i]][0]);
		}
		printf("\n");
	}
    return 0;
}
