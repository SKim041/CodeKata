#include <queue>
#include <vector>

using namespace std;
int dx[]={0,1};
int dy[]={1,0};
int divisor = 1000000007;
int dist[101][101];
int puddle[101][101];
int way[101][101];
void bfs(int sx, int sy, const int n, const int m)
{
    queue<pair<int, int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 1;
    way[sx][sy] = 1;
    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        for(int i=0; i<2; i++)
        {
            int nx= x+dx[i];
            int ny= y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m || puddle[nx][ny]) continue;
            if(dist[nx][ny]==0)
            {
                dist[nx][ny] = dist[x][y]+1;
                way[nx][ny] = way[x][y];
                q.push({nx,ny});
            }
            else if(dist[nx][ny]==dist[x][y]+1)
            {
                way[nx][ny] = (way[nx][ny] + way[x][y]) % divisor;
            }
        }
    }
}
int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto v:puddles)
    {
        puddle[v[1]][v[0]] = 1;
    }
    bfs(1,1,n,m);
    return way[n][m];
}