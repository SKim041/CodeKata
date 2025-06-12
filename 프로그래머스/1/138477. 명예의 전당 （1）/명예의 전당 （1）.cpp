#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    // 매일 발표된 명예의 전당의 최하위 점수 -> 매일 k번째 점수
    vector<int> answer;
    for(int i=0; i<score.size(); i++){
        int idx = i<k? i : k-1;
        
        vector<int> temp(score.begin(), score.begin() + i + 1);
        sort(temp.begin(), temp.end(), greater<int>());
        
        answer.push_back(temp[idx]);
    }
    return answer;
}