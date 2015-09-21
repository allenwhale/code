#include<stdio.h>
#include<stdlib.h>
int l,r,c;
int i,j,k;
int start,end,check,step;
int s[33][33][33];
int t[29000][4];
char a;
int ck;
int main(){
	ck=0;
	while(ck!=1){
		scanf("%d %d %d",&l,&r,&c);
		if(l==0){ck=1;break;}
		for(i=1;i<=l;i++){
			scanf("%c",&a);
			for(j=1;j<=r;j++){
				for(k=1;k<=c;k++){
					scanf("%c",&a);
					if(a=='#'){
						s[i][j][k]=-1;
					}
					else if(a=='.'){
						s[i][j][k]=9999999;
					}
					else if(a=='S'){
						s[i][j][k]=0;
						t[0][0]=i;
						t[0][1]=j;
						t[0][2]=k;
						t[0][3]=0;
					}
					else if(a=='E'){
						s[i][j][k]=-2;
						}
				}
				scanf("%c",&a);
			}
		}
		start=0;
		end=1;
		check=0;
		step=0;
		while(check!=1){
			if(end==start){
				check=1;
				break;
			}
			if(s[t[start][0]+1][t[start][1]][t[start][2]]==9999999){
				t[end][0]=t[start][0]+1;
				t[end][1]=t[start][1];
				t[end][2]=t[start][2];
				t[end][3]=t[start][3]+1;
				s[t[end][0]][t[end][1]][t[end][2]]=t[end][3];
				end++;
			}
			if(s[t[start][0]-1][t[start][1]][t[start][2]]==9999999){
				t[end][0]=t[start][0]-1;
				t[end][1]=t[start][1];
				t[end][2]=t[start][2];
				t[end][3]=t[start][3]+1;
				s[t[end][0]][t[end][1]][t[end][2]]=t[end][3];
				end++;
			}
			if(s[t[start][0]][t[start][1]+1][t[start][2]]==9999999){
				t[end][0]=t[start][0];
				t[end][1]=t[start][1]+1;
				t[end][2]=t[start][2];
				t[end][3]=t[start][3]+1;
				s[t[end][0]][t[end][1]][t[end][2]]=t[end][3];
				end++;
			}
			if(s[t[start][0]][t[start][1]-1][t[start][2]]==9999999){
				t[end][0]=t[start][0];
				t[end][1]=t[start][1]-1;
				t[end][2]=t[start][2];
				t[end][3]=t[start][3]+1;
				s[t[end][0]][t[end][1]][t[end][2]]=t[end][3];
				end++;
			}
			if(s[t[start][0]][t[start][1]][t[start][2]+1]==9999999){
				t[end][0]=t[start][0];
				t[end][1]=t[start][1];
				t[end][2]=t[start][2]+1;
				t[end][3]=t[start][3]+1;
				s[t[end][0]][t[end][1]][t[end][2]]=t[end][3];
				end++;
			}
			if(s[t[start][0]][t[start][1]][t[start][2]-1]==9999999){
				t[end][0]=t[start][0];
				t[end][1]=t[start][1];
				t[end][2]=t[start][2]-1;
				t[end][3]=t[start][3]+1;
				s[t[end][0]][t[end][1]][t[end][2]]=t[end][3];
				end++;
			}
			if(s[t[start][0]+1][t[start][1]][t[start][2]]==-2){
				check=1;
				step=t[start][3]+1;
				break;
			}
			if(s[t[start][0]-1][t[start][1]][t[start][2]]==-2){
				check=1;
				step=t[start][3]+1;
				break;
			}
			if(s[t[start][0]][t[start][1]+1][t[start][2]]==-2){
				check=1;
				step=t[start][3]+1;
				break;
			}
			if(s[t[start][0]][t[start][1]-1][t[start][2]]==-2){
				check=1;
				step=t[start][3]+1;
				break;
			}
			if(s[t[start][0]][t[start][1]][t[start][2]+1]==-2){
				check=1;
				step=t[start][3]+1;
				break;
			}
			if(s[t[start][0]][t[start][1]][t[start][2]-1]==-2){
				check=1;
				step=t[start][3]+1;
				break;
			}
			start++;
		}
		if(step==0){
			printf("Trapped!\n");
		}
		else{
			printf("Escaped in %d minute(s).\n",step);
			}
//		printf("%d",step);	
	}
	return 0;	
}
