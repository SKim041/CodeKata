#include <vector>

using namespace std;

int backtracking(vector<int>& numbers, int idx, const int target, int sum, int count)
{
    int temp_count = count;
    if(idx<numbers.size())
        temp_count = backtracking(numbers, idx+1, target,sum + numbers[idx], count)+
                backtracking(numbers, idx+1, target,sum - numbers[idx], count);  
    else if(sum==target) return 1;
    return temp_count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = backtracking(numbers, 0, target, 0, 0);
    return answer;
}