#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i = 1; i < food.size() * 2; i++){
        if(i == food.size()){
            answer += '0';
            continue;
        }
        int j = i > food.size()? food.size() * 2 - i : i;
        for(int n=0; n<food[j]/2; n++){
            answer += j + '0';
        }
    }
    return answer;
}