#include <stdio.h>
#include <string.h>
bool prime(int s)
{
	int i;
	if(s==1||s==2)return true;
	for(i=2;i*i<s+1;i++)
	{
		if(s%i==0)return false;
	}
	return true;
}
int main()
{
	int n[300];
	n['a']=1;
	n['b']=2;
	n['c']=3;
	n['d']=4;
	n['e']=5;
	n['f']=6;
	n['g']=7;
	n['h']=8;
	n['i']=9;
	n['j']=10;
	n['k']=11;
	n['l']=12;
	n['m']=13;
	n['n']=14;
	n['o']=15;
	n['p']=16;
	n['q']=17;
	n['r']=18;
	n['s']=19;
	n['t']=20;
	n['u']=21;
	n['v']=22;
	n['w']=23;
	n['x']=24;
	n['y']=25;
	n['z']=26;
	n['A']=27;
	n['B']=28;
	n['C']=29;
	n['D']=30;
	n['E']=31;
	n['F']=32;
	n['G']=33;
	n['H']=34;
	n['I']=35;
	n['J']=36;
	n['K']=37;
	n['L']=38;
	n['M']=39;
	n['N']=40;
	n['O']=41;
	n['P']=42;
	n['Q']=43;
	n['R']=44;
	n['S']=45;
	n['T']=46;
	n['U']=47;
	n['V']=48;
	n['W']=49;
	n['X']=50;
	n['Y']=51;
	n['Z']=52;
	char s[30];
	while(gets(s)!=NULL)
	{
		int len=strlen(s);
		int i;
		int ans=0;
		for(i=0;i<len;i++)
		{
			ans+=n[s[i]];
		}
		if(prime(ans))printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}			
    return 0;
}
