#include <bits/stdc++.h>
using namespace std;

vector<int> z_value(const string& s){
	int len = s.size();
	vector<int> z(len, 0);
	int l = 0, r = 0;
	z[0] = len;
	for(int i=1,j;i<len;z[i]=j,i++){
		j = max(min(z[i - l], r - i), 0);
		while(i + j < len && s[i + j] == s[j])j++;
		if(i + z[i] > r)r = (l = i) + z[i];
	}
	return z;
}
char A[2010];
void Solve(){
    scanf("%s", A);
    auto z = z_value(A);
    int ans = -1;
    for(int i = 0 ; i < (int)z.size() ; i++){
        if(z[i] != 0 && z[i] + i != (int)z.size()){
            ans = i;
        }
    }
    if(ans == -1)printf("Impossible");
    else{
        for(int i = 0 ; i < ans ; i++)
            printf("%c", A[i]);
        printf("%s", A);
    }
    puts("");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
