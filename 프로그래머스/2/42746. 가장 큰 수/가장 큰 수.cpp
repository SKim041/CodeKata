#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(),
        [](int a, int b)
         {
             string str_a = to_string(a);
             string str_b = to_string(b);
             return str_a+str_b > str_b+str_a;
         }
        );
    if(numbers[0]==0) return "0";
    for(int i : numbers)
    {
        answer+=to_string(i);
    }
    return answer;
}