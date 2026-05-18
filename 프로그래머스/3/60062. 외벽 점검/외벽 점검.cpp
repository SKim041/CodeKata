#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size()+1;
    // 일직선으로 만들기
    int weakCount = weak.size();
    for(int i=0; i<weakCount; i++)
    {
        weak.push_back(n+weak[i]);
    }
    sort(dist.begin(),dist.end());
    do
    {
       for(int i=0; i<weakCount; i++)
        {
            int temp = 0;
            int start = i;
            int current = i;
            for(int d:dist)
            {
                temp++;
                // 점검 범위
                int checkRange = weak[current]+d;
                
                while(current<weakCount+start && weak[current]<=checkRange)
                {
                    current++;
                }

                if(current>=weakCount+start) break;
            }
            if(current>=weakCount+start)
            {
                answer = min(temp, answer);
            }
        }
    }
    while(next_permutation(dist.begin(), dist.end()));
    
    return answer>dist.size()?-1:answer;
}