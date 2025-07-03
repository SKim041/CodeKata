#include <string>
#include <vector>
#include <regex>

using namespace std;
// 이진변환 횟수, 0 개수 
pair<int, int> ConvertToBinary(string& input)
{
    // regex 0 제거
    string result = "";
    regex pattern("0");
    result = regex_replace(input, pattern, ""); 
    // 제거한 0 개수 저장
    int deleteCount = input.length()-result.length();
    // 1이면 종료
    if(input == "1") return {0, deleteCount};
    // result 길이 이진법으로 표현
    int num = result.length();
    result = "";
    
    while(1)
    {
        result+=to_string(num % 2);
        num/=2;
        if(num==0) break;
    }
    
    pair<int, int> p = ConvertToBinary(result);
    return {p.first + 1, p.second + deleteCount};
}

vector<int> solution(string s) {
    vector<int> answer;
    pair<int, int> p = ConvertToBinary(s);
    answer = {p.first, p.second};
    return answer;
}