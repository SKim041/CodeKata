#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// 모든 달은 28일까지 
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> mapTerms;
    // today의 총 일수
    int t_totalDays = stoi(today.substr(0, 4))*12*28 
        + (stoi(today.substr(5, 2))-1)*28 + stoi(today.substr(8, 2)) - 1;
    // terms map에 넣기
    for (auto s : terms)
    {
        mapTerms[s.substr(0, 1)] = stoi(s.substr(2));
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        string term = privacies[i].substr(11);
        int YYYY = stoi(privacies[i].substr(0, 4));
        int MM = stoi(privacies[i].substr(5, 2));
        int DD = stoi(privacies[i].substr(8, 2));
        
        int term_totalDays = YYYY*12*28 + (MM+mapTerms[term]-1)*28 + DD - 1 - 1;
        
        if (t_totalDays > term_totalDays)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}