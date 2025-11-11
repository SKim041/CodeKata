#include <string>
#include <vector>

using namespace std;
int solution(string name) {
    int answer = 0;
    int n = name.size();
    // 문자 조작
    for(char c : name)
    {
        answer += (c-'A')>('Z'-c+1)? 'Z'-c+1: c-'A'; 
    }
    
    // 위치 이동
    int move = n-1;
    for(int i=0; i<n; ++i)
    {
        int nextIdx = i+1;
        while(nextIdx<n && name[nextIdx] == 'A')
        {
            ++nextIdx;
        }
        int temp = 2*i+n-nextIdx>2*(n-nextIdx)+i? 2*(n-nextIdx)+i : 2*i+n-nextIdx;
        move = move>temp? temp:move;
    }
    answer += move;
    return answer;
}