#include <bits/stdc++.h>
using namespace std;
bool Solve(){
	string str[7];
	int a, b, c;
	cin >> a >> b >> c;
	bool tf=false;
	for(int i = 0 ; i < 7 ; i++){
		cin >> str[i];
		for(int j = 0 ; j < 7 ; j++){
			if(str[i][j] == '+'){
				if(i && str[i-1][j]=='+'){
					tf = true;
				}
				if(j && str[i][j-1]=='+'){
					tf = true;
				}
			}
		}
	}
	return tf;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cout << (Solve()?"YES":"NO") << endl;
	}
}
