#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> number;
    size_t idx;
    
    while((idx=s.find(" "))!=string::npos)
    {
        number.push_back(stoi(s.substr(0, idx)));
        s = s.substr(idx + 1);
    }
    number.push_back(stoi(s));
    answer = to_string(*min_element(number.begin(), number.end()))
        +" "+to_string(*max_element(number.begin(), number.end()));
    return answer;
}