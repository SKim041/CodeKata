#include <string>
#include <vector>
#include <map>

using namespace std;

bool CheckWin(map<int, vector<int>> M)
{
    int diagonal1 = 0, diagonal2 = 0;
    map<int, int> vertical;
    for(auto& m : M)
    {
        if(m.second.size()==3) return true;
        if(M.size()==3)
        {
            for(int col:m.second)
            {
                if(m.first==col) ++diagonal1;
                if(m.first+col == 2) ++diagonal2;
                ++vertical[col];                    
            }
        }
    }
    
    if(diagonal1==3 || diagonal2 == 3) return true;
    for(auto& c:vertical)
    {
        if(c.second==3) return true;
    }
    return false;
}
int solution(vector<string> board) {
    int answer = 0;
    map<int, vector<int>> O;
    map<int, vector<int>> X;
    int OCount=0, XCount=0;
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j] == 'O')
            {
                O[i].push_back(j);
                ++OCount;
            }
            else if(board[i][j] == 'X')
            {
                X[i].push_back(j);
                ++XCount;
            }
        }
    }
    // 개수 확인
    if(OCount<XCount || OCount-XCount>1) return 0;
    if(OCount<3) return 1;
    // 게임 종료 확인
    if(OCount==XCount && CheckWin(O)) return 0;
    if(OCount>XCount && CheckWin(X)) return 0;

    return 1;
}