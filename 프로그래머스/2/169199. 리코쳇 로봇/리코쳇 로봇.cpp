#include <string>
#include <vector>
#include <queue>

using namespace std;
struct point
{
    int x, y, count;
};

int bfs(int x, int y, vector<string>& board)
{
    queue<point> q;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    
    q.push({x,y,0});
    visited[y][x] = true;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    while(!q.empty())
    {
        point temp = q.front();
        q.pop();
        if(board[temp.y][temp.x] == 'G')
        {
            return temp.count;
        }
        
        for(int i=0; i<4; i++)
        {
            int tempX = temp.x;
            int tempY = temp.y;
            
            while(1)
            {
                tempX += dx[i];
                tempY += dy[i];

                if((tempX<0 || tempX>=board[0].size())
                   ||(tempY<0 || tempY>=board.size())
                   || board[tempY][tempX] == 'D')
                {
                    tempX -=dx[i];
                    tempY -=dy[i];
                    break;
                }
            }
            if(!visited[tempY][tempX])
            {
                visited[tempY][tempX] = true;
                q.push({tempX, tempY, temp.count+1});
            }
        }        
    }
    return -1; 
}
int solution(vector<string> board) {
    int answer = 0;
    vector<int> start;
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j]=='R') start = {i, j};
        }
    }
    
    answer = bfs(start[1], start[0], board);
    return answer;
}