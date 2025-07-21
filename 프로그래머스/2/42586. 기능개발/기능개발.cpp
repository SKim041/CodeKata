#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    double daysleftPrev = 0.0;
    for(int i=0; i<progresses.size(); i++)
    {
        if(i==0 || daysleftPrev < ceil((100.0-progresses[i])/speeds[i]))
        {
            daysleftPrev = ceil((100.0-progresses[i])/speeds[i]);
            answer.push_back(1);
        }
        else
        {
            *answer.rbegin() += 1;
        }
    }
    return answer;
}