#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";

    reverse(cards1.begin(), cards1.end());
    reverse(cards2.begin(), cards2.end());
    for(auto &item:goal){
        if(item == cards1.back()){
            cards1.pop_back();
        }
        else if(item == cards2.back()){
            cards2.pop_back();
        }
        else{
            answer = "No";
            break;
        }
    }
    return answer;
}