#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(),
        [](const vector<int>& a, const vector<int>& b)
         {
             return a[1]<b[1];
         });

    double missile = targets[0][1] - 0.5;
    for(auto& v:targets)
    {
        int s = v[0];
        int e = v[1];
        
        if(missile <= s)
        {
            ++answer;
            missile = e - 0.5;
        }
    }
    return answer;
}