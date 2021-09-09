#include <iostream>
using namespace std;

int main(){
    int h1, h2, m1, m2;
    while(cin >> h1 >> m1 >> h2 >> m2){
        if(h1 ==0 && h2 == 0 && m1 == 0 && m2 == 0) break;
        if(m1 > m2) {
            m2 += 60;
            h2--;
        }
        if(h1 > h2) h2 += 24;
        printf("%d\n", 60 * (h2 - h1) + (m2 - m1));
    }
    return 0;
}
