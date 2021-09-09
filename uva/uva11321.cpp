#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int m;

bool mycompmod(int a ,int b){
    return (a % m) < (b % m);
}

bool mycomp2(int a, int b){
    return (a % 2) > (b % 2);
}

int main(){
    int n;
    int arr[10000];
    int temp[10000];
    while(cin >> n >> m){
        cout << n << " " << m << endl;
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            temp[i] = arr[i];
        }
        sort(arr, arr + n, mycompmod);
        int curr_m = arr[0] % m;
        for(int i = 0, start = 0; start + i <= n; i++){
            if(start + i == n){
                sort(arr + start, arr + start + i, mycomp2);
                break;
            }
            if(arr[i + start] % m != curr_m){
                sort(arr + start, arr + start + i, mycomp2);
                start += i;
                curr_m = arr[start] % m;
                i = 0;
            }
        }

        int is_odd = arr[0] % 2;
        curr_m = arr[0] % m;
        for(int i = 0, start = 0; i <= n; i++){
            if(i == n){
                if(is_odd){
                    sort(arr + start, arr + i, greater<int>());
                }
                else{
                    sort(arr + start, arr + i);
                }
            }
            if(arr[i] % 2 != is_odd || arr[i] % m != curr_m){
                if(is_odd){
                    sort(arr + start, arr + i, greater<int>());
                }
                else{
                    sort(arr + start, arr + i);
                }
                curr_m = arr[i] % m;
                is_odd = arr[i] % 2;
                start = i;
            }
        }

        for(int i = 0; i < n; i++){
            cout << arr[i] << endl;
        }
    }
}
