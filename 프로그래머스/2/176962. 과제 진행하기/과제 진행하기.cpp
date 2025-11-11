#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int TimeToInt(string time)
{
    return stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<vector<string>> wait;
    
    sort(plans.begin(), plans.end(), 
         [](const vector<string>& a, const vector<string>& b) 
         {
            return TimeToInt(a[1]) < TimeToInt(b[1]);
         });
    
    int currentTime = TimeToInt(plans[0][1]);
    int playTime = stoi(plans[0][2]);
    
    for(int i=1; i<plans.size(); i++)
    {
        int nextStartTime = TimeToInt(plans[i][1]);
        int remainingTime = nextStartTime - currentTime;
        
        if(playTime<=remainingTime)
        {
            answer.push_back(plans[i-1][0]);
            currentTime += playTime;
            remainingTime -= playTime;
            
            while(!wait.empty() && remainingTime>0)
            {
                playTime = stoi(wait.top()[2]);
                if(playTime<=remainingTime)
                {
                    answer.push_back(wait.top()[0]);
                    currentTime += playTime;
                    remainingTime -= playTime;
                    wait.pop();
                }
                else
                {
                    wait.top()[2] = to_string(playTime - remainingTime);
                    currentTime += remainingTime;
                    remainingTime = 0;
                }
            }
        }
        else
        {
            plans[i-1][2] = to_string(playTime - remainingTime);
            wait.push(plans[i-1]);
        }
        currentTime = nextStartTime;
        playTime = stoi(plans[i][2]);
    }
    
    answer.push_back(plans.back()[0]);
    
    while(!wait.empty())
    {
        answer.push_back(wait.top()[0]);
        wait.pop();
    }
    
    return answer;
}