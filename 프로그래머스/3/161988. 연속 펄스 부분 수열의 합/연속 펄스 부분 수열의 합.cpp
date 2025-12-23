#include <vector>
#include <algorithm>

using namespace std;
long long findSubSum(const vector<int>& pattern)
{   
    long long currentSum = 0;
    long long maxSum = -100000;
    for(int i=0; i<pattern.size(); i++)
    {
        currentSum = max((long long)pattern[i], currentSum+pattern[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<int> pattern1 = sequence;
    vector<int> pattern2 = sequence;
    int n = 1;
    for(int i=0; i<sequence.size(); i++)
    {
        pattern1[i] = sequence[i]*n;
        pattern2[i] = sequence[i]*n*(-1);
        n *= -1;
    }
    
    answer = max(findSubSum(pattern1), findSubSum(pattern2));

    return answer;
}