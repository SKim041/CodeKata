#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    // 광물별 피로도
    vector<string> picksType = {"diamond","iron","stone"};
    unordered_map<string, int> durability = {{"diamond", 25}, {"iron", 5}, {"stone", 1}};
    
    // 곡괭이 개수 * 5만큼 광물 남기기
    int picksCount = picks[0]+picks[1]+picks[2];
    if(minerals.size()>picksCount*5)
    {
        minerals.resize(picksCount*5);
    }
    
    // 광물 피로도 계산
    vector<pair<int,vector<string>>> tiredness;
    for(int i=0; i<minerals.size();i+=5)
    {
        int total=0;
        vector<string> group;
        for(int j=i;j<i+5 && j<minerals.size();j++)
        {
            total+=durability[minerals[j]];
            group.push_back(minerals[j]);
        }
        tiredness.push_back({total,group});
    }
    sort(tiredness.begin(), tiredness.end(), 
        [](pair<int,vector<string>> a, pair<int,vector<string>>b)
         {
             return a.first > b.first;
         });
    
    // 피로도별 곡괭이 할당
    for(int i=0; i<tiredness.size(); i++)
    {
        string pick = "";
        for(int j=0; j<picksType.size(); j++)
        {
            if(picks[j]==0) continue;
            pick = picksType[j];
            picks[j]--;
            break;
        }
        if(pick=="") break;
        for(string s:tiredness[i].second)
        {
            int temp = durability[s]/durability[pick];
            answer+=temp>0?temp:1;
        }
    }
    
    return answer;
}