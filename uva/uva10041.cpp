#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){

    int selb_num;
    int location[500];
    int case_count;
    cin >> case_count;
    while(case_count--){
        cin >> selb_num;
        for(int i = 0; i < selb_num; i++){
            cin >> location[i];
        }
        sort(location, location + selb_num);
        int myLoc;
        if(selb_num % 2){
            myLoc = location[selb_num / 2];
        }
        else{
            myLoc = ((location[selb_num / 2] + location[selb_num / 2 - 1]) / 2);
        }
        int sum =  0;
        for(int i = 0; i < selb_num; i++){
            sum += (int)(abs(myLoc - location[i]) + 0.5);
        }
        cout << sum << endl;
    }
    return 0;
}
