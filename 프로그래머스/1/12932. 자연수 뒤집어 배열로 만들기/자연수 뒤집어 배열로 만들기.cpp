#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    for(int i = to_string(n).length() - 1; i >= 0; i--){
        char c = to_string(n)[i];
        answer.push_back(c - '0');
    }
    return answer;
}