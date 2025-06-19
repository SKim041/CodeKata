#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> keys;
    for(auto& item:keymap){
        for(int i=0; i<item.size(); i++){
            if(keys.find(item[i]) == keys.end() || keys[item[i]] > i+1){
                keys[item[i]] = i+1;
            }  
        }
    }
    for(auto& item:targets){
        int count = 0;
        for(auto& c:item){
            if(keys.find(c) != keys.end()){
                count += keys[c];
            }
            else{
                count = -1;
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}