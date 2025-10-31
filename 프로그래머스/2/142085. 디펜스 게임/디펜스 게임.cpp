#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int totalRound = enemy.size();
    if(k>=totalRound) return totalRound;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int sum=0;
    int sumK=0;
    for(int i : enemy)
    {
        if(minHeap.size()<k)
        {
            minHeap.push(i);
            sumK += i;
        }
        else if(i>minHeap.top())
        {
            sumK -= minHeap.top();
            minHeap.pop();
            minHeap.push(i);
            sumK += i;
        }
        sum += i;
        if(sum-sumK>n)
        {
            break;
        }
        else
        {
            ++answer;
        }
    }
    
    return answer;
}