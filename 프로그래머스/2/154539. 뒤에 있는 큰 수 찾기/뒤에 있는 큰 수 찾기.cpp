#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> idx;
    // 자기 인덱스 뒤부터 자신보다 크고 가장 가까이 있는 수
    for(int i=0; i<numbers.size(); i++)
    {
        while(!idx.empty() && numbers[i]>numbers[idx.top()])
        {
            answer[idx.top()] = numbers[i];
            idx.pop();
        }
        idx.push(i); 
    }
    return answer;
}