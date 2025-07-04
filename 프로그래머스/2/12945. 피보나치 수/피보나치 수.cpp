#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num(n);
    // 피보나치 수열 저장
    for(int i = 0; i < n; i++)
    {
        if(i < 2) 
        {
            num[i] = i;
        }
        else
        {            
            num[i] = (num[i-1] + num[i-2]) % 1234567;
        }
    }
    answer = (num[n-1] + num[n-2]) % 1234567;
    return answer;
}