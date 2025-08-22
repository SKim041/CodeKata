#include <vector>

using namespace std;

int findIdx(int row, int col)
{
    return row*(row+1)/2 + col;
}
vector<int> solution(int n) {
    // 총 길이: n(n+1)/2
    vector<int> answer(n*(n+1)/2,0);
    int row = 0;
    int col = 0;
    int num = 1;
    int idx = 0;
    for(int length=n; length>0; length-=3)
    {
        // 왼쪽
        for(int i=0; i<length; i++)
        {
            answer[findIdx(row, col)] = num++;
            if(i!=length-1) row += 1;
        }
        // 아래
        if (length>1)
        {
            for(int i=0; i<length-1; i++)
            {
                col += 1;
                answer[findIdx(row, col)] = num++;
            }
        }
        // 오른쪽
        if (length>2)
        {
            for(int i=0; i<length-2; i++)
            {
                row -= 1;
                col -= 1;
                answer[findIdx(row, col)] = num++;
            }
        }
        row += 1;
    }
    return answer;
}