#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int T = stoi(argv[1]);
    printf("%d\n", T);
    for(int i=0;i<T;i++){
        random_shuffle(a, a+9);
        for(int i=0;i<3;i++,puts(""))
            for(int j=0;j<3;j++)
                printf("%d ", a[i*3+j]);
    }
    return 0;
}
