#include<stdio.h>
#include<stdlib.h>
#include<math.h>
	signed int n,times,st,x,y;
	char sss[110][110],a;
	int ss[110][110];
	int one[9999][2];
	int three[9999][2];
	int start,end,step,check,i,j,k,l,v,m;
int main()
{
	while(1){
		step=0;
		scanf("%d",&n);
		k=0;
		l=0;
		scanf("%c",&a);
		for(j=0;j<n;j++){
			for(i=0;i<=n;i++){
				scanf("%c",&sss[j][i]);
				
				//printf("%c",sss[j][i]);
				if(sss[j][i]=='1'){
					//printf("yes");
					one[k][0]=j;
					one[k][1]=i;
					printf("%d",one[l][1]);
					k++;
				}
				else if(sss[j][i]=='3'){
					three[l][0]=j;
					three[l][1]=i;
					printf("%d",three[l][1]);
					l++;
				}
			}//scanf("%c",&a);
		}
		step=0;
		for(i=0;i<k;i++){
			for(j=0;j<l;j++){
				x=1;//one[k][0]-three[l][0];
				
				st=abs(one[k][0]-three[l][0])+abs(one[k][1]-three[l][1]);
				printf("asdf");
				if(step<st){
					step=st;
				}
			}
		}
		printf("%d",step);
		//system("pause");
		//times=clock();
		//for(i=0;i<k;i++){
//			for(v=0;v<n;v++){
//				for(m=0;m<n;m++){
//					if(sss[v][m]=='2' or sss[v][m]=='1'){
//						ss[v][m]=99;
//					}
//					else{
//						ss[v][m]=-1;
//						}
//				}
//			}
//			//for(v=0;v<n;v++){
//			//	for(m=0;m<n;m++){
//				//	printf("\t%d",ss[v][m]);
//				//}printf("\n");
//			//}
//			//for(v=0;v<=step+1;v++){
//			//	for(m=0;m<3;m++){
//				//	t[v][m]=0;
//				//	printf("%d",t[v][m]);
//			//	}
//			//}
//			t[0][0]=r[i][0];
//			t[0][1]=r[i][1];
//			t[0][2]=0;
//			ss[t[0][0]][t[0][1]]=0;
//			start=0;
//			end=1;
//			check=0;
//			while(check==0){//system("pause");
//				if(ss[t[start][0]+1][t[start][1]]==-1){
//					check=1;
//					if(step<t[start][2]+1){
//						step=t[start][2]+1;
//						break;
//					}
//				}
//				if(ss[t[start][0]-1][t[start][1]]==-1){
//					check=1;
//					if(step<t[start][2]+1){
//						step=t[start][2]+1;	
//						break;
//					}
//				}
//				if(ss[t[start][0]][t[start][1]+1]==-1){
//					check=1;
//					if(step<t[start][2]+1){
//						step=t[start][2]+1;
//						break;
//					}
//				}
//				if(ss[t[start][0]][t[start][1]-1]==-1){
//					check=1;
//					if(step<t[start][2]+1){
//						step=t[start][2]+1;
//						//printf("%d",step);
//						break;
//					}
//				}
//				if(ss[t[start][0]+1][t[start][1]]==99){
//					
//					t[end][0]=t[start][0]+1;t[end][1]=t[start][1];t[end][2]=t[start][2]+1;ss[t[end][0]][t[end][1]]=t[end][2];end++;
//				}
//				if(ss[t[start][0]-1][t[start][1]]==99){
//					t[end][0]=t[start][0]-1;t[end][1]=t[start][1];t[end][2]=t[start][2]+1;ss[t[end][0]][t[end][1]]=t[end][2];end++;
//				}
//				if(ss[t[start][0]][t[start][1]+1]==99){
//					t[end][0]=t[start][0];t[end][1]=t[start][1]+1;t[end][2]=t[start][2]+1;ss[t[end][0]][t[end][1]]=t[end][2];end++;
//				}
//				if(ss[t[start][0]][t[start][1]-1]==99){
//					t[end][0]=t[start][0];t[end][1]=t[start][1]-1;t[end][2]=t[start][2]+1;ss[t[end][0]][t[end][1]]=t[end][2];end++;
//				}
//				start++;
//			}
//			
//		}printf("%d\n",step);
//		//printf("\n\t%d",clock()-times);
	}
return 0;
}
