#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int>result(y+1, y);
    result[x] = 0;
    for(int i=x; i<=y; i++)
    {
        int temp = i+n;
        if(temp<=y)
        {
            result[temp] = result[i]+1>result[temp]?result[temp]:result[i]+1;
        }
        
        temp = i*2;
        if(temp<=y)
        {
            result[temp] = result[i]+1>result[temp]?result[temp]:result[i]+1;
        }
        
        temp = i*3;
        if(temp<=y)
        {
            result[temp] = result[i]+1>result[temp]?result[temp]:result[i]+1;
        }
    }
    answer = result[y]==y? -1: result[y];
    return answer;
}