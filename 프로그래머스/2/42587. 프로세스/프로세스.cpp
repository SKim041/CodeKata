#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    unordered_map<int, int> um_priorities;
    um_priorities.reserve(priorities.size());
    queue<int> q;
    priority_queue<int> max;
    for(int i=0; i<priorities.size(); i++)
    {
        um_priorities[i] = priorities[i];
        q.push(i);
        max.push(priorities[i]);
    }
    while(!q.empty())
    {  
        int priority = um_priorities[q.front()];
        if(priority == max.top())
        {
            if(q.front() == location) return answer;
            max.pop();
            q.pop();
            answer++;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        
    }
    return answer;
}