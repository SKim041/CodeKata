#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> type;
    for(vector<string>& item : clothes)
    {
        type[item[1]] += 1;
    }

    for(auto p:type)
    {
       answer*=p.second+1;
    }
    answer-=1;
    return answer;
}