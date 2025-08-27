#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void dfs(vector<string>& maps, vector<vector<bool>>& check, int row, int col, int& sum)
{
    if(row<0 || row>=maps.size()) return;
    if(col<0 || col>=maps[0].size()) return;
    
    if(maps[row][col]=='X') check[row][col]=true;
    if(check[row][col]) return;
    sum += maps[row][col] - '0';
    check[row][col] = true;

    dfs(maps, check, row-1, col, sum);
    dfs(maps, check, row+1, col, sum);
    dfs(maps, check, row, col-1, sum);
    dfs(maps, check, row, col+1, sum);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> check(maps.size(), vector<bool>(maps[0].size(),false));

    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[0].size(); j++)
        {
            if(maps[i][j]=='X') check[i][j]=true;
            if(check[i][j]) continue;
            int sum = 0;
            dfs(maps, check, i, j, sum);
            answer.push_back(sum);
        }
    }
    
    if(answer.size()==0) answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}