#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c:s){
        if(c == 32){
            answer+=" ";
        }
        else if((c < 91 && c + n > 90) || (c > 96 && c + n > 122)){
            answer += c + n - 26;
        }
        else{
            answer += c + n;
        }
    }
    return answer;
}