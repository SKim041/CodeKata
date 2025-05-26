#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = angle > 90 ? 1 : 0;
    
    while(angle >= 0){
        answer++;
        angle-=90;
    }
    
    return answer;
}