#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::tree<int, null_type, 
		less<int>, rb_tree_tag, 
		tree_order_statistics_node_update> set_t;
void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> vec(n);
	set_t s;
    for(int i = 0 ; i < n ; i++){
        vec[i] = i;
        s.insert(i);
    }
    int counter = -1;
    while(m--){
        int t;
        scanf("%d", &t);
        t--;
        printf("%d ", (int)s.order_of_key(vec[t]));
        s.erase(vec[t]);
        s.insert(counter);
        vec[t] = counter;
        counter--;
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}

