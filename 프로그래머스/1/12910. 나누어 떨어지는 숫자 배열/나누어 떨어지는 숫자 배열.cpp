#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for(int item:arr){
        if(item % divisor == 0){
            answer.push_back(item);
        }
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    return answer;
}