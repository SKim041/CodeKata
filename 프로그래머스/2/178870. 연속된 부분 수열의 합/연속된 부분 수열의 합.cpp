#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int size = sequence.size();
    vector<int> answer={0, size-1};
    int startIdx = 0;
    int endIdx = 0;
    long long sum=sequence[0]; 
    while(startIdx<size && endIdx<size)
    {
        if(sum == k)
        {
            if(answer[1]-answer[0]>endIdx-startIdx)
            {
                answer[0]=startIdx;
                answer[1]=endIdx;
            }
            sum-=sequence[startIdx++]; 
        }
        else if (sum<k)
        {
            endIdx++;
            if(endIdx<size) 
                sum+=sequence[endIdx];
        }
        else
        {
            sum-=sequence[startIdx++];            
        }
    }    
    return answer;
}