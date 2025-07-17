#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.reserve(right - left + 1);
    
    long long idx = left;
    while(idx<=right)
    {
        long long i = idx/n;
        long long c = idx%n <= i? i + 1 : idx%n + 1;
        answer.push_back(c);
        idx++;
    }
    
    return answer;
}