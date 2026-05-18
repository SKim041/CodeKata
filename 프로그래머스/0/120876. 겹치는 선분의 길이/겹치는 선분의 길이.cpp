#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;

    map<int, int> lineMap;
    for(auto l:lines)
    {
        for(int i=l[0]; i<l[1]; i++)
        {
            lineMap[i]++;
        }
    }
    for(auto p:lineMap)
    {
        if(p.second>1) answer++;
    }
    return answer;
}