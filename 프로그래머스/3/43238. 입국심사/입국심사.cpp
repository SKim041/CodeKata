#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long minTime = 1;
    long long maxTime = (long long)times.back() * n;
    while(minTime <= maxTime)
    {
        long long avg = (minTime+maxTime)/2;
        long long sum = 0;
        for(int& t:times)
        {
            sum += avg / t;
            if(sum >= n) break;
        }
        if(sum >= n)
        {
            answer = avg;
            maxTime = avg - 1; 
        }
        else
        {
            minTime = avg + 1;
        }
    }
    return answer;
}