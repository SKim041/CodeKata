#include <queue>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> conveyor;
    stack<int> subconveyor;
    for(int i=1; i<=order.size(); i++)
    {
        conveyor.push(i);
    }
    int idx=0;
    while(idx<order.size())
    {
        if(conveyor.empty())
        {
            if(!subconveyor.empty() && subconveyor.top() == order[idx])
            {
                subconveyor.pop();
                answer++;
                idx++;
            }
            else break;
        }
        else
        {
            if(conveyor.front() == order[idx])
            {
                conveyor.pop();
                answer++;
                idx++;
            }
            else if(!subconveyor.empty() && subconveyor.top() == order[idx])
            {
                subconveyor.pop();
                answer++;
                idx++;
            }
            else
            {
                subconveyor.push(conveyor.front());
                conveyor.pop();
            }
        }
    }
    return answer;
}