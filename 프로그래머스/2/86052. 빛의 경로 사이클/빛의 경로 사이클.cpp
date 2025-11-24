#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// n행 m열
// 상 [0,1], 하 [0,-1], 좌 [-1,0], 우[1,0]

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int findPath(const vector<string>& grid, const vector<int> startPoint,
             vector<vector<vector<bool>>>& visited,
             int n, int m , 
             int direction, int result)
{
    if(visited[n][m][direction] && 
       startPoint[0]==n && startPoint[1]==m && startPoint[2]==direction) 
        return result;

    if(visited[n][m][direction]) return -1;
    visited[n][m][direction]=true;
    if(grid[n][m]=='L')
    {
        //1,0 -> 0,1 -> -1,0 -> 0,-1 ->1,0
        direction = (direction+1)%4;
    }
    else if(grid[n][m] == 'R')
    {
        //1,0 -> 0,-1 -> -1,0 -> 0,1 ->1,0
        direction = (direction+3)%4;
    }
    n=n+dx[direction];
    m=m+dy[direction];
    if(n<0) n=grid.size()-1;
    else if(n>=grid.size()) n=0;
    if(m<0) m=grid[0].size()-1;
    else if(m>=grid[0].size()) m=0;

    return findPath(grid,startPoint,visited, n, m, direction, result+1);
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<vector<bool>>> visited(grid.size(), 
                                            vector<vector<bool>>(grid[0].size(),
                                                                 vector<bool>(4,false)));
    for(int n=0; n<grid.size(); ++n)
    {
        for(int m=0; m<grid[0].size(); ++m)
        {
            for(int i=0; i<4; ++i)
            {
                int temp = findPath(grid,{n,m,i}, visited,n, m, i, 0);
                if(temp>0) answer.push_back(temp);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}