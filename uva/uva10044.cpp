#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int all_sen = 0, count_sen = 0;
    cin >> all_sen;
    char s[512];
    while(all_sen--){
        count_sen++;
        int lines, ques;
        cin >> lines >> ques;
        cin.getline(s, 512);//, '\n');
        map<string, int> name_number;
        map<string, int>::iterator map_iter;
        int name_start_pos = 0;
        name_number["Erdos, P."] = 0;
        int curr_size = 1;
        vector<int> graph[4096];
        while(lines--){
            vector<int> author_list;
            cin.getline(s, 512);// '\n');
            //cout << s << endl;
            name_start_pos = 0;
            for(int i = 0; ; i++){
                if(s[i] == ',' && s[i - 1] == '.'){
                    s[i] = '\0';
                    map_iter = name_number.find(s + name_start_pos);
                    if(map_iter == name_number.end()){
                        //cout << s + name_start_pos << " : " << curr_size << endl;
                        name_number[s + name_start_pos] = curr_size;
                        author_list.push_back(curr_size);
                        curr_size++;
                    }
                    else{
                        //cout << map_iter -> first << " : " << map_iter -> second << endl;
                        author_list.push_back(map_iter -> second);
                    }
                    name_start_pos = i + 2;
                }
                else if(s[i] == ':'){
                    s[i] = '\0';
                    map_iter = name_number.find(s + name_start_pos);
                    if(map_iter == name_number.end()){
                        //cout << s + name_start_pos << " : " << curr_size << endl;
                        name_number[s + name_start_pos] = curr_size;
                        author_list.push_back(curr_size);
                        curr_size++;
                    }
                    else{
                        //cout << map_iter -> first << " : " << map_iter -> second << endl;
                        author_list.push_back(map_iter -> second);
                    }
                    break;
                }
            }
            for(vector<int>::iterator v_iter = author_list.begin(); v_iter != author_list.end(); v_iter++){
                for(vector<int>::iterator v_iter2 = author_list.begin(); v_iter2 != author_list.end(); v_iter2++){
                    if(*v_iter2 != *v_iter){
                        graph[*v_iter].push_back(*v_iter2);
                    }
                }
            }
        }
        queue<int> traverse;
        int visted[4096] = {};
        int erdos[4096] = {};
        traverse.push(0);
        int curr_erdos_num = 0;
        erdos[0] = -1;
        while(!traverse.empty()){
            curr_erdos_num++;
            for(vector<int>::iterator v_iter = graph[traverse.front()].begin(); v_iter != graph[traverse.front()].end(); v_iter++){
                if(erdos[*v_iter] == 0){
                    traverse.push(*v_iter);
                    erdos[*v_iter] = curr_erdos_num;
                }
            }
            traverse.pop();
        }
        cout << "Scenario " << count_sen << endl;
        while(ques--){
            cin.getline(s, 512);//, '\n');
            cout << s << " ";
            int tempI = -1;
            if(name_number.find(s) != name_number.end())
                tempI = name_number[s];
            //cout << tempI << " : ";
            if(erdos[tempI] == -1){
                if(!strcmp(s, "Erdos, P."))
                    cout << "0" << endl;
                else
                    cout << "infinity" << endl;
            }
            else if(erdos[tempI] == 0){
                cout << "infinity" << endl;
            }
            else{
                cout << erdos[tempI] << endl;
            }
        }
    }
    return 0;
}
