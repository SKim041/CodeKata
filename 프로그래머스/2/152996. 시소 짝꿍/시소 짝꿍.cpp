#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, long long> weightCount;
    
    // 몸무게별 인원 수
    for(const int& i : weights)
    {
        weightCount[i] += 1;
    }
    // 같은 몸무게 조합 수
    for(const auto& [w,c] : weightCount)
    {
        if(c>1)
        {
            answer+=c*(c-1)/2;
        }
    }
    
    for(const auto& [w,c] : weightCount)
    {
        // 2:3
        if(w * 2 % 3 == 0)
        {
            int temp = w * 2 / 3;
            if(weightCount.find(temp) != weightCount.end())
            {
                answer += c * weightCount[temp];
            }
        }                
        // 2:4
        if(w * 2 % 4 == 0)
        {
            int temp = w * 2 / 4;
            if(weightCount.find(temp) != weightCount.end())
            {
                answer += c * weightCount[temp];
            }
        }
        // 3:4
        if(w * 3 % 4 == 0)
        {
            int temp = w * 3 / 4;
            if(weightCount.find(temp) != weightCount.end())
            {
                answer += c * weightCount[temp];
            }
        }
    }
    
    return answer;
}