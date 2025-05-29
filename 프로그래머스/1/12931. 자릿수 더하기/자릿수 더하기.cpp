#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    
    for(int i=to_string(n).length() - 1; i >= 0; i--){
        answer += n / pow(10,i);
        n -= (int)(n / pow(10,i)) * pow(10,i);
    }
    
    return answer;
}