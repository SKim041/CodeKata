#include <vector>

using namespace std;
// 가로>=세로
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // yellow의 너비, 높이
    int w = 0;
    int h = 0;
    // yellow 의 약수
    for (int i = 1; i * i <= yellow; i++)
    {
        if(yellow % i == 0)
        {
            w = i >= yellow/i? i : yellow/i; 
            h = yellow/w;
            if(2*(w + 2) + 2*h == brown) break;
        }
    }
    answer = {w+2, h+2};
    return answer;
}