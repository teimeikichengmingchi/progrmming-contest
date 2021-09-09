#include <iostream>
using namespace std;

int main(){
    int input[10000];
    int input_t;
    for(int count = 0; cin >> input_t; count++){
        int start = count;
        for(int i = 0; i < count; i++){
            if(input[i] > input_t){
                start = i;
                break;
            }
        }
        for(int i = count; i > start; i--){
            input[i] = input[i - 1];
        }
        input[start] = input_t;
        if((count + 1) % 2){
            cout << input[(count + 1) / 2] << endl;
        }
        else{
            cout << (input[(count + 1) / 2] + input[((count + 1) / 2) - 1]) / 2 << endl;
        }
    }
    return 0;
}
