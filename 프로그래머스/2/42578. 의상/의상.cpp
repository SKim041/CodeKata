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
    vector<int> typeCount;
    typeCount.reserve(type.size());
    for(pair<string, int> p:type)
    {
        typeCount.push_back(p.second+1);
    }

    for(int i:typeCount)
    {
       answer*=i;
    }
    answer-=1;
    return answer;
}