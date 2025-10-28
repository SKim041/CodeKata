#include <vector>

using namespace std;

int dfs(vector<int>& cards, vector<bool>& visited, int input, int openedBox)
{
    int nextInput = cards[input]-1;
    if(visited[nextInput]) return openedBox;
    visited[nextInput] = true;
    return dfs(cards, visited, nextInput, openedBox+1);
}

int solution(vector<int> cards) {
    int answer = 0;
    int firstResult = 0;
    vector<bool> visited(cards.size(), false);
    
    for(int i=0; i<cards.size(); i++)
    {
        vector<bool> tempVisited(cards.size(), false);
        int temp = dfs(cards, tempVisited, i, 0);
        if(temp > firstResult) 
        {
            firstResult = temp;
            visited = tempVisited;
        }
    }
    
    if(firstResult==cards.size()) return 0;
    
    for(int i=0; i<cards.size(); i++)
    {
        vector<bool> tempVisited = visited;
        if(tempVisited[i]) continue;
        int temp = firstResult * dfs(cards, tempVisited, i, 0);
        if(temp > answer) answer = temp;
    }
    
    return answer;
}