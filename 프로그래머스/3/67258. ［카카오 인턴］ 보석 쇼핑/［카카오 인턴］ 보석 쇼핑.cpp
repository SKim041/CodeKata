#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,0);
    // 보석 종류 구하기
    unordered_set<string> gemType(gems.begin(), gems.end());
    int gemCount = gemType.size();
    // 구간 찾기
    int startIdx=0;
    int min = gems.size()+1;
    unordered_map<string, int> gemMap;
    for(int i=0; i<gems.size(); i++)
    {
        gemMap[gems[i]]++;
        if(gemMap.size()==gemCount)
        {
            while(gemMap[gems[startIdx]]>1)
            {
                gemMap[gems[startIdx]]--;
                startIdx++;
            }
            if(i-startIdx+1<min)
            {
                min = i-startIdx+1;
                answer[0] = startIdx+1;
                answer[1] = i+1;
            }
        }

    }
    
    return answer;
}