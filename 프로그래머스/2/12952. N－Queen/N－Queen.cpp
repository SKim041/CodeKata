#include <vector>

using namespace std;

void backtracking(int row, const int n, int& result, 
                  vector<bool>& vertical, vector<bool>& diagonal1,vector<bool>& diagonal2)
{
    if(row==n)
    {
        ++result;
        return;
    }
    for(int col=0; col<n; col++)
    {
        if(vertical[col] && diagonal1[row+col] && diagonal2[row-col+n])
        {
            vertical[col] = false;
            diagonal1[row+col] = false;
            diagonal2[row-col+n] = false;
            backtracking(row+1, n, result, vertical, diagonal1, diagonal2);
            vertical[col] = true;
            diagonal1[row+col] = true;
            diagonal2[row-col+n] = true;
        }
    }
}
int solution(int n) {
    int answer = 0;
    vector<bool> vertical(n,true);
    vector<bool> diagonal1(2*n,true);
    vector<bool> diagonal2(2*n,true);
    
    backtracking(0, n, answer, vertical, diagonal1, diagonal2);
    
    return answer;
}