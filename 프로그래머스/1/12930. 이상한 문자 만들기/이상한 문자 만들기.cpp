#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int i = -1;
    for(char c:s){
        i++;
        if(c == 32){
            i=-1;
            answer += 32;
            continue;
        }
        if(i % 2 == 1){
            answer += tolower(c);
        }
        else{
            answer += toupper(c);
        }
    }
    
    return answer;
}