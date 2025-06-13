#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    
    const vector<int> pattern_1 = {1,2,3,4,5};
    const vector<int> pattern_2 = {2,1,2,3,2,4,2,5};
    const vector<int> pattern_3 = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == pattern_1[i%5]){
            score[0]++;
        }
        if(answers[i] == pattern_2[i%8]){
            score[1]++;
        }
        if(answers[i] == pattern_3[i%10]){
            score[2]++;
        }
    }
    
    int max_score = *max_element(score.begin(), score.end());
    for(int i=0; i<score.size(); i++){
        if(score[i]==max_score){
            answer.push_back(i+1);
        }
    }
    return answer;
}