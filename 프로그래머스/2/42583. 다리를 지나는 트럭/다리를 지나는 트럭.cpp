#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    for(int i=0; i<bridge_length; i++)
    {
        bridge.push(0);
    }
    int total_weight=0;
    int i=0;
    bool isFinished = false;
    while(!isFinished)
    {
        for(int j=0; j<bridge_length; j++)
        {
            answer++;
            total_weight-=bridge.front();
            bridge.pop();
            if(i==truck_weights.size() && total_weight == 0)
            {
                isFinished = true;
                break;
            }
            if(i<truck_weights.size() && total_weight + truck_weights[i]<=weight)
            {
                total_weight+=truck_weights[i];
                bridge.push(truck_weights[i]);
                i++;
            }
            else bridge.push(0);
        }
    }
    return answer;
}