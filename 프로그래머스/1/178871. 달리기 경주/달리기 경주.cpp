#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    answer.reserve(players.size());
    map<int, string> order;
    unordered_map<string, int> reverse_order;
    // 현재 순위별 플레이어 저장
    for(int i=0; i<players.size(); i++)
    {
        order[i] = players[i];
        reverse_order[players[i]] = i;
        
    }
    // 이름 불린 플레이어 순위 바꾸기
    for(string s:callings)
    {
        int s_rank = reverse_order[s];
        string behind = order[s_rank-1];
        order[s_rank-1] = s;
        order[s_rank] = behind;
        // reverse_order 값도 변경
        reverse_order[s] = s_rank-1;
        reverse_order[behind] = s_rank;
    }
    // 변경 된 순위 저장
    for(auto& p:order)
    {
        answer.push_back(p.second);
    }
    
    return answer;
}