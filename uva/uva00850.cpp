#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    char *plaintext = "the quick brown fox jumps over the lazy dog";
    char tabel[26];
    char s[101][100];
    int inputNum = 0;
    int inputCase;
    cin >> inputCase;
    fgets(s[0], sizeof(s[0]), stdin);
    //fgets(s[0], sizeof(s[0]), stdin);
    while(inputCase--){
        int tabelFound = 0;
        inputNum = 0;
        memset(tabel, '\0', 26);
        while(fgets(s[inputNum], sizeof(s[inputNum]), stdin)){
            if(!strcmp(s[inputNum], "\n"))
                break;
            if(!tabelFound && strlen(plaintext) == (strlen(s[inputNum]) - 1)){
                tabelFound = 1;
                int count = 0;
                memset(tabel, '\0', 26);
                for(int i = 0; i < strlen(plaintext); i++){
                    if(s[inputNum][i] == ' '){
                        if(plaintext[i] == ' ')
                            continue;
                        else{
                            tabelFound = 0;
                            break;
                        }
                    }
                    if(tabel[s[inputNum][i] - 'a'] == '\0'){
                        count++;
                        tabel[s[inputNum][i] - 'a'] = plaintext[i];
                    }
                    else if(tabel[s[inputNum][i] - 'a'] != plaintext[i]){
                        tabelFound = 0;
                        break;
                    }
                }
                if(count != 26)
                    tabelFound = 0;
            }
            inputNum++;
        }
        if(!tabelFound){
            cout << "No solution." << endl;
        }
        else{
            for(int i = 0; i < inputNum; i++){
                for(int j = 0; s[i][j] != '\n'; j++){
                    if(s[i][j] != ' ')
                        s[i][j] = tabel[s[i][j] - 'a'];
                }
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
