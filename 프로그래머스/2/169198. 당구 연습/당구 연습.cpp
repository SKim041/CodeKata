#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(auto& b:balls)
    {
        int minDist = 1e9;
        int x = b[0], y = b[1], dist = 0;
        // 위
        if(!(x==startX && y>startY))
        {
            dist = (startX-x)*(startX-x) + (2*n-y-startY)*(2*n-y-startY);
            minDist = minDist>dist? dist: minDist;
        }
        
        // 아래
        if(!(x==startX && y<startY))
        {
            dist = (startX-x)*(startX-x) + (startY+y)*(startY+y);
            minDist = minDist>dist? dist: minDist;
        }
        // 오른쪽
        if(!(y==startY && x>startX))
        {
            dist = (2*m-x-startX)*(2*m-x-startX) + (startY-y)*(startY-y);
            minDist = minDist>dist? dist: minDist;
        }
        // 왼쪽
        if(!(y==startY && x<startX))
        {
            dist = (startX+x)*(startX+x) + (startY-y)*(startY-y);
            minDist = minDist>dist? dist: minDist;
        }
        
        answer.push_back(minDist);
    }
    return answer;
}