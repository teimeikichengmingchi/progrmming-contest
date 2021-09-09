#include <iostream>
using namespace std;

int GCD(int i, int j){
    int t;
    while(i % j != 0){
        t = i;
        i = j;
        j = t % i;
    }
    return j;
}

int main(){
    int N;
    while(cin >> N){
        if(!N) break;
        int G = 0;
        for(int i = 1; i < N; i++)
            for(int j = i + 1; j <= N; j++){
                G += GCD(i, j);
            }
        printf("%d\n", G);
    }
}
