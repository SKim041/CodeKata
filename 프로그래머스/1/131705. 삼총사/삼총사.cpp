#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i=0; i<number.size(); i++){
        for(int j=0; j<number.size(); j++){
            if(i==j){
                continue;
            }
            for(int k=0; k<number.size(); k++){
                if(i==k || j==k){
                    continue;
                }
                if(number[i]+number[j]+number[k]==0){
                    answer++;
                }
            }
        }
    }
    return answer/6;
}