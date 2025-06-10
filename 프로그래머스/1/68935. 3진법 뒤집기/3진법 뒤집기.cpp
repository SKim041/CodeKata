#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> base3;
    while(n > 0){
            base3.insert(base3.begin(), n%3);
            n /= 3;
        }
    for(int i=0; i<base3.size(); i++){
        answer += base3[i] * pow(3, i);
    }
    return answer;
}