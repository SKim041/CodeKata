#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(char c:number)
    {
        while(answer.size()>0 && c>answer.back() && k>0)
        {
            answer.pop_back();
            k-=1;
        }
        answer+=c;
    }
    
    while(k>0)
    {
        answer.pop_back();
        k-=1;
    }
    
    return answer;
}