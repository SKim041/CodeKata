#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    if(n==1) return answer;
    int startIdx = section[0];
    for(int i=0; i<section.size()-1; i++){
        if(startIdx + m-1 < section[i+1]){
            startIdx = section[i+1];
            answer++;
        }
    }
    return answer;
}