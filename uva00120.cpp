#include <iostream>
#include <cstring>
using namespace std;

int atoi(char *c){
    int ans = 0;
    for(int i = 0; c[i] != ' '; i++){
        if(c[i] == '\0')
            break;
        ans *= 10;
        ans += (c[i] - '0');
    }
    return ans;
}

void rev(int *arr, int n){
    int temp;
    for(int i = 0; i * 2 < (n - 1); i++){
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    return;
}

int main(){
    int input[30];
    char t[150];
    memset(t, '\0', 150);
    while(cin.getline(t, 150)){
        if(strlen(t) == 0){
            break;
        }
        int count = 0;
        int start = 0, end = 0;
        for(int i = 0; t[i] != '\0'; i++){
            if(t[i] != ' '){
                input[count++] = atoi(t + i);
                while(t[i] != ' '){
                    if(t[i] == '\0')
                        break;
                    i++;
                }
            }
        }
        for(int i = 0; i < count; i++){
            cout << input[i];
            if(i == count - 1){
                cout << endl;
            }
            else{
                cout << " ";
            }
        }
        for(int i = count; i > 0; i--){
            int max = 0, index = -1;
            for(int j = 0; j < i; j++){
                if(input[j] >= max){
                    max = input[j];
                    index = j;
                }
            }
            if(index == i - 1){
                //
            }
            else if(index == 0){
                cout << count - i + 1 << " ";
                rev(input, i);
            }
            else{
                cout << count - index << " ";
                rev(input, index + 1);
                cout << count - i + 1 << " ";
                rev(input, i);
            }
        }
        cout << "0" << endl;
        memset(t, '\0', 150);
    }
}
