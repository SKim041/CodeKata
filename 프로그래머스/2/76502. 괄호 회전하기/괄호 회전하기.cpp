#include <string>
#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;
    regex pattern("\\(\\)|\\[\\]|\\{\\}");
    
    for(int i=0; i<s.size(); i++)
    {
        string temp = "";
        if(i==0) temp = s.substr(i);
        else temp = s.substr(i) + s.substr(0, i);
        
        while(regex_search(temp, pattern))
        {
            temp = regex_replace(temp, pattern, "");
        }
        if(temp.size()==0) answer++;
        
    }
    return answer;
}