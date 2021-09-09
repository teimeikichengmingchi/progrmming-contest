#include <iostream>
using namespace std;

int main(){
    char s[300];
    char *ans = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
    char myAns[300];
    while(fgets(s, sizeof(s), stdin)){
        int i;
        for(i = 0; s[i] != '\n'; i++){
            if(s[i] == ' '){
                myAns[i] = ' ';
                continue;
            }
            int j;
            for(j = 0; ans[j] != '\0'; j++){
                if(ans[j] == s[i]){
                    j--;
                    break;
                }
            }
            if(ans[j] == '\0'){
                cout << s[i] << "error";
                return -1;
            }
            myAns[i] = ans[j];
        }
        myAns[i] = '\0';
        cout << myAns << endl;
    }
    return 0;
}
