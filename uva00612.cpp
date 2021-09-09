#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int case_count;
    int len, dna_count;
    cin >> case_count;

    char dna[100][50];
    int arr[100];
    int arr2[100];
    cin.getline(dna[0], sizeof(dna[0]));
    while(case_count--){
        cin.getline(dna[0], sizeof(dna[0]));
        cin >> len >> dna_count;
        cin.getline(dna[0], sizeof(dna[0]));
        for(int i = 0; i < dna_count; i++){
            cin >> dna[i];
            arr[i] = 0;
            for(int j = 0; j < len; j++){
                for(int k = j + 1; k < len; k++){
                    if(dna[i][k] < dna[i][j]){
                        arr[i]++;
                    }
                }
            }
            arr2[i] = arr[i];
        }
        stable_sort(arr, arr + dna_count);
        int t = -1;
        for(int i = 0; i < dna_count; i++){
            for(int j = 0; j < dna_count; j++){
                if(arr[i] == t)
                    break;
                if(arr[i] == arr2[j]){
                    cout << dna[j] << endl;
                }
            }
            t = arr[i];
        }
        cout << endl;
    }
}
