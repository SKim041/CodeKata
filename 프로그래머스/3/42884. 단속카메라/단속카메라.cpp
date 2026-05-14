#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(),
        [](vector<int> a,vector<int> b)
         {
             if(a[0]==b[0]) return a[1]<b[1];
             return a[0]<b[0]; 
         });
    vector<int> prev = routes[0];
    for(vector<int> r:routes)
    {
        if(r[0]<=prev[1]) prev[1] = min(r[1], prev[1]);
        else prev=r, answer++;
    }

    return answer;
}