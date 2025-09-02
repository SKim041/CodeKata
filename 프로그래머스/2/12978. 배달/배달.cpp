#include <vector>
using namespace std;

void calculateTime(vector<vector<int>>& road, const int K,int town,
                   int time, vector<int>& delivery)
{
    for(int i=0; i<road.size(); i++)
    {
        int nextTown=0;
        if(road[i][0]==town) nextTown = road[i][1];
        else if(road[i][1]==town) nextTown = road[i][0];
        else continue;
        
        int newTime = time + road[i][2];
        if(newTime>K) continue;
        if(newTime<delivery[nextTown])
        {
            delivery[nextTown] = newTime;
            calculateTime(road,K,nextTown,newTime,delivery);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> delivery(N+1,1e9);
    delivery[1]=0;
    calculateTime(road,K,1,0,delivery);
    
    for(int i=1; i<delivery.size();i++)
    {
        if(delivery[i]<=K) answer++;
    }
    
    return answer;
}