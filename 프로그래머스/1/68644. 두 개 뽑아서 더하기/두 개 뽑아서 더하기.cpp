#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            int add = numbers[i] + numbers[j];
            if(find(answer.begin(), answer.end(), add) == answer.end()){
                answer.push_back(add);
            }
        } 
    }
    sort(answer.begin(), answer.end());
    return answer;
}