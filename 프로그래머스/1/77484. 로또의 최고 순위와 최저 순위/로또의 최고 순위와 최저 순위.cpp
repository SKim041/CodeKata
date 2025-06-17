#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int unknown = 0;
    int correct = 0;

    for(int i=0; i<lottos.size(); i++){
        if(lottos[i]==0){
            unknown++;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++){
            if(win_nums[j]==lottos[i]){
                correct++;
                break;
            }
        }       
    }
    answer.push_back(7-(correct+unknown==0?1:correct+unknown));
    answer.push_back(7-(correct==0?1:correct));
    
    return answer;
}