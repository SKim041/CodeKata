#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    for(int i = 0; i < score.size(); i += m){
        int price = *min_element(score.begin()+i, score.begin()+i+m);
        answer += price * m;
    }
    
    return answer;
}