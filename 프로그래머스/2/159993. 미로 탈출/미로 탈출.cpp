#include <string>
#include <vector>
#include <queue>

using namespace std;
struct Point
{
    int y;
    int x;
    int dist;
};

int bfs(int y, int x, char c, vector<string>& maps)
{
    queue<Point> q;
    vector<vector<bool>> visited(maps.size(),vector<bool>(maps[0].size()));
    
    q.push({y,x,0});
    visited[y][x] = true;
    
    int dy[]={-1,1,0,0};
    int dx[]={0,0,-1,1};
    
    while(!q.empty())
    {
        Point temp = q.front();
        q.pop();
        
        if(maps[temp.y][temp.x] == c)
        {
            return temp.dist;
        }
        
        for(int i=0; i<4; i++)
        {
            int tempY = temp.y+dy[i];
            int tempX = temp.x+dx[i];
            
            if(tempY>=0 && tempY<maps.size() && tempX>=0 && tempX<maps[0].size() 
               && !visited[tempY][tempX]
               && maps[tempY][tempX] != 'X')
            {
                visited[tempY][tempX] = true;
                q.push({tempY, tempX, temp.dist+1});
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    vector<int> start(2,0);
    vector<int> lever(2,0);
    
    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[0].size(); j++)
        {
            if(maps[i][j]=='S') start={i,j};
            if(maps[i][j]=='L') lever={i,j};
        }
    }
    
    int temp = 0;
    temp = bfs(start[0],start[1],'L', maps);
    if(temp==-1) return -1;
    answer += temp;
    
    temp =  bfs(lever[0],lever[1],'E', maps);
    if(temp==-1) return -1;
    answer += temp;
    
    return answer;
}