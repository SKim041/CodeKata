#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char dc[] = {'d','l','r','u'};
bool bFound = false;
void dfs(int x, int y, string route, string& answer,
         int k, const int n, const int m, const int r, const int c)
{
    if(bFound) return;
    // 남은 이동 횟수, 남은 최소 거리
    int dist = abs(x-r) + abs(y-c);
    if(dist>k || (k-dist)%2!=0) return;
    
    if(k==0)
    {
        if(x==r && y==c)
        {
            answer = route;
            bFound = true;
        }
        return;
    }
    for(int i=0; i<4; i++)
    {
        int nx= x+dx[i];
        int ny= y+dy[i];
        if(nx<1 || nx>n || ny<1 || ny>m) continue;
        dfs(nx,ny,route+dc[i],answer,k-1,n,m,r,c);
    }

}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    dfs(x,y,"",answer,k,n,m,r,c);
    return answer.size()!=k?"impossible":answer;
}