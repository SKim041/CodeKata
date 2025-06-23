#include <vector>

using namespace std;
// 빵:1 야채:2 고기:3
// 쌓여 있는 재료 순서를 바꿀 수 없음
int solution(vector<int> ingredient) 
{
    int answer = 0;
    vector<int> burger;
    for(int i:ingredient)
    {
        burger.push_back(i);
        int n = burger.size();
        if(n >= 4 && burger[n-4]==1 && burger[n-3]==2 && burger[n-2]==3 && burger[n-1]==1)
        {
            answer++;
            burger.erase(burger.end()-4,burger.end());
        }
        
    }
    return answer;
}