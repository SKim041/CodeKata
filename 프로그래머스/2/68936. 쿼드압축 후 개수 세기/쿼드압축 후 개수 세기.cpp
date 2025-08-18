#include <vector>

using namespace std;
bool checkQuad(vector<vector<int>>& arr,int x, int y, int size, int firstNum)
{
    for(int i=x; i<x+size; i++)
    {
        for(int j=y; j<y+size; j++)
        {
            if (arr[i][j] != firstNum) return false;
        }
    }
    return true;
}
void quad(vector<vector<int>>& arr, vector<int>& answer, int x, int y, int size)
{
    if(checkQuad(arr, x, y, size, arr[x][y]))
    {
        if(arr[x][y] == 0) answer[0]++;
        else answer[1]++;
        return;
    }
    quad(arr, answer, x, y, size/2);
    quad(arr, answer, x, y+size/2, size/2);
    quad(arr, answer, x+size/2, y, size/2);
    quad(arr, answer, x+size/2, y+size/2, size/2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    
    quad(arr, answer, 0,0,arr.size());
    
    return answer;
}