#include <string>
#include <vector>
int totalUser=0;
int totalSales=0;
using namespace std;
void dfs(vector<int>& discount, const vector<vector<int>>& users,const vector<int>& emoticons,int idx)
{
    if(idx==emoticons.size())
    {
        int tempUser = 0;
        int tempSales = 0;
        for(const auto& info:users)
        {
            int totalPrice=0;
            for(int i=0;i<emoticons.size(); i++)
            {
                if(discount[i]>=info[0])
                {
                    totalPrice += emoticons[i] * (100 - discount[i])/100;
                }
            }
            if(totalPrice>=info[1])
            {
                ++tempUser;
            }
            else
            {
                tempSales += totalPrice;
            }
        }
        if(tempUser>totalUser)
        {
            totalUser = tempUser;
            totalSales = tempSales;
        }
        else if(tempUser==totalUser && tempSales>totalSales)
        {
            totalSales = tempSales;
        }
        return;
    }
    for(int dr = 10; dr<=40; dr+=10)
    {
        discount[idx] = dr;
        dfs(discount, users, emoticons, idx+1);
    } 
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> discount(emoticons.size());
    dfs(discount, users, emoticons, 0);
    answer = {totalUser, totalSales};
    return answer;
}