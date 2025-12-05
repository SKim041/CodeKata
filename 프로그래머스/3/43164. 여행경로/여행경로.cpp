#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<string>> tickets, vector<bool>& visited, string departure, vector<string>& travel)
{
    if(travel.size() == tickets.size()+1) return true;
    
    for(int i=0; i<tickets.size(); ++i)
    {
        if(tickets[i][0] != departure || visited[i]) continue;
        
        visited[i] = true;
        travel.push_back(tickets[i][1]);
        if(dfs(tickets, visited, tickets[i][1], travel))
        {
            return true;
        }
        travel.pop_back();
        visited[i] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer = {"ICN"};
    vector<bool> visited(tickets.size(),false);
    sort(tickets.begin(), tickets.end(), 
         [](const auto& a, const auto& b)
         {
             if(a[0]==b[0]) return a[1] < b[1];
             return a[0] < b[0];
         });
    dfs(tickets, visited, "ICN", answer);
    return answer;
}