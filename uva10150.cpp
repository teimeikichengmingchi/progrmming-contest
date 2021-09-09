#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    char s[18];
    char int_to_str[25200][18];
    map<string, int> str_to_int;
    map<string, int>::iterator it;
    vector<int> g[25200];
    int dict_count = 0;
    while(fgets(s, 18, stdin)){
        if(s[0] == '\n')
            break;
        s[strlen(s) - 1] = '\0';
        it = str_to_int.find(s);
        if(it == str_to_int.end()){
            str_to_int[s] = dict_count;
            memset(int_to_str[dict_count], '\0', 18);
            strncpy(int_to_str[dict_count], s, strlen(s));
            for(int i = 0; i < dict_count; i++){
                if(strlen(int_to_str[dict_count]) == strlen(int_to_str[i])){
                    int count = 0;
                    for(int j = 0; j < strlen(int_to_str[dict_count]); j++){
                        if(int_to_str[dict_count][j] != int_to_str[i][j]){
                            count++;
                            if(count > 1){
                                break;
                            }
                        }
                    }
                    if(count == 1){
                        g[i].push_back(dict_count);
                        g[dict_count].push_back(i);
                    }
                }
            }
            dict_count++;
        }
    }
    char input1[18], input2[18];
    memset(input1, '\0', 18);
    memset(input2, '\0', 18);
    while(cin >> input1 >> input2){
        it = str_to_int.find(input1);
        int a = it -> second;
        it = str_to_int.find(input2);
        int b = it -> second;
        int visted[25200] = {};
        int last[25200];
        queue<int> q;
        q.push(b);
        int flag = 0;
        while(!q.empty()){
            for(vector<int>::iterator vit = g[q.front()].begin(); vit != g[q.front()].end(); vit++){
                if(!visted[*vit]){
                    q.push(*vit);
                    visted[*vit] = 1;
                    last[*vit] = q.front();
                    if(*vit == a){
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag)
                break;
            q.pop();
        }
        if(flag){
            int curr = a;
            while(1){
                cout << int_to_str[curr] << endl;
                if(curr == b)
                    break;
                curr = last[curr];
            }
        }
        else{
            cout << "No solution." << endl;
        }
        cout << endl;
    }
}
