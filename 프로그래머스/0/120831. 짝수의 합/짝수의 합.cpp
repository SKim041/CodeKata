#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1; i <= n/2; i++){
        answer += 2*i;
    }
    return answer;
}