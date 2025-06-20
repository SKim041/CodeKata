#include <string>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(char& c:s){
        int count = 0;
        char cFind;
        for(int i = 0; i<index; ){
            count++;
            cFind = (c + count % 26) > 'z' ? 
                'a' - 1 + (c + count % 26) % 'z' : c + count % 26;
            if(skip.find(cFind) == string::npos){
                i++;
            }
        }
        answer += cFind;
    }
    return answer;
}