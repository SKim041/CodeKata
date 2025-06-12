#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for(int i=0; i<s.length(); i++){
        int idx = s.find(s[i]);
        if(idx == i){
            answer.push_back(-1);
        }
        else{
            answer.push_back(i - idx);
            s[idx]='0';
        }
    }
    return answer;
}