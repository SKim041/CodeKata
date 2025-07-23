#include <vector>
#include <algorithm>

using namespace std;

int findCount(int currentK, vector<vector<int>>& dungeon, vector<bool> isVisited, int result)
{
    int temp_result=result;
    for(int i=0; i<dungeon.size(); i++)
    {
        if(isVisited[i] || dungeon[i][0]>currentK) continue;
        isVisited[i] = true;
        temp_result=max(findCount(currentK-dungeon[i][1], dungeon, isVisited, result+1), temp_result);
        isVisited[i] = false;
    }
    return temp_result;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> isVisited(dungeons.size(), false);
    answer = findCount(k, dungeons, isVisited, answer);
    return answer;
}