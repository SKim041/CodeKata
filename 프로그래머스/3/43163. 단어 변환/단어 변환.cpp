#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct word
{
    string s;
    int tryCount;
};
int bfs(const vector<string>& words,string& begin, string& target)
{
    queue<word> q;
    vector<bool> visited(words.size(), false);
    
    q.push({begin, 0});
    
    while(!q.empty())
    {
        word temp = q.front();
        q.pop();
        
        if(temp.s == target)
        {
            return temp.tryCount;
        }
        
        for(int i=0; i<words.size(); ++i)
        {
            if(visited[i]) continue;
            
            for (int j = 0; j < words[0].size(); ++j)
            {
                if (temp.s.substr(0, j) == words[i].substr(0, j)
                    && temp.s.substr(j + 1) == words[i].substr(j + 1))
                {
                    visited[i] = true;
                    q.push({ words[i], temp.tryCount + 1 });
                }
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target)==words.end())
    {
        return 0;
    };
    
    return bfs(words, begin, target);
}