#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                // 파일 처음 찾았을 때
                if(answer.size()==0)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                    continue;
                }
                // rdx 비교
                if(i + 1 > answer[2]) answer[2] = i + 1;
                // luy, rdy 
                if(j < answer[1]) answer[1] = j;
                else if (j + 1 > answer[3]) answer[3] = j + 1;
                
            }
                
        }
        
    }
    return answer;
}