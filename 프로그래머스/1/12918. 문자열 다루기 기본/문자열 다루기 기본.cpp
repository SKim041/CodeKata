#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len=s.length();
    
    if(len == 4 || len == 6){
        for(char c:s){
            if(c < '0' || c > '9'){
                answer = false;
            }
        }
    }
    else{
        answer = false;
    }
    return answer;
}