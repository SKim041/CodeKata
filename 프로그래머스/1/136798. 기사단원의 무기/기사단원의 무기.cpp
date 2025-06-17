#include <cmath>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++){
        int str = 0;
        for(int j = 1; j <= (int)sqrt(i); j++){
            if(i % j == 0){
                str += j*j == i? 1 : 2;
            }
            if(str>limit){
                break;
            }
        }
        answer += str > limit? power : str;
    }
    return answer;
}