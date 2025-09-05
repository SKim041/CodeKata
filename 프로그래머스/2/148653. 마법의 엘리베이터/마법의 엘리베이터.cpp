#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    // 반올림 고려
    while(storey>0)
    {
        int remainder = storey%10;
        if(remainder>5 || (remainder==5 && storey/10%10+1>5))
            remainder = 10-remainder;
        else    remainder *= -1;
        
        answer+=abs(remainder);
        storey+=remainder;
        
        storey/=10;
    }
    return answer;
}