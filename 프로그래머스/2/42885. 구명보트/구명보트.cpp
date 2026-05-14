#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    
    sort(people.begin(), people.end());
    auto min = people.begin();
    auto max = people.end()-1;
    
    while(min<people.end() && max>people.begin() && min<max)
    {
        if(*min+*max>limit) max--;
        else
        {
            min++;
            max--;
            answer--;
        }
    }
    
    return answer;
}