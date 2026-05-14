#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> splitString(const string& s, const char& delimiter)
{
    vector<string> result;
    string token;
    stringstream ss(s);
    while(getline(ss, token, delimiter))
    {
        if(!token.empty()) result.push_back(token);
    }
    return result;
}
void makeAllCombination(const vector<string>& info, int idx, string key, const int& score, 
                        unordered_map<string, vector<int>>& OutMap)
{
    if(idx==4)
    {
        OutMap[key].push_back(score);
        return;
    }
    makeAllCombination(info, idx+1, key+info[idx], score, OutMap);
    makeAllCombination(info, idx+1, key+'-', score, OutMap);
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
    unordered_map<string, vector<int>> infoMap;
    // 모든 지원자 스펙 경우의 수 추가
    for(string s:info)
    {
        vector<string> temp = splitString(s,' ');
        makeAllCombination(temp, 0, "", stoi(temp[4]), infoMap);
    }
    // 점수 벡터 오름차순 정렬
    for(auto& p:infoMap)
    {
        sort(p.second.begin(), p.second.end());
    }
    for(int i=0; i<query.size(); i++)
    {
        vector<string> temp = splitString(query[i],' ');
        string key = temp[0]+temp[2]+temp[4]+temp[6];
        if(infoMap.find(key)==infoMap.end()) continue;
        answer[i] = infoMap[key].end() - lower_bound(infoMap[key].begin(), infoMap[key].end(), stoi(temp[7]));
    }
    return answer;
}