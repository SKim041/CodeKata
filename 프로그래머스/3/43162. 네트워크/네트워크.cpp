#include <vector>

using namespace std;

void count(const vector<vector<int>> computers, vector<bool>& visited, int i)
{
    for(int k=0; k<visited.size(); ++k)
    {
        if(visited[k]) continue;
        if(computers[i][k]==1)
        {
            visited[k] = true;
            if(i==k) continue;
            count(computers, visited, k);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; ++i)
    {
        if(visited[i]) continue;
        count(computers, visited, i);
        answer++;
    }
    return answer;
}