#include <string>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0; i<=t.length()-p.length(); i++){
        long long num_t = stoll(t.substr(i,p.length()));
        long long num_p = stoll(p);
        if(num_p>=num_t){
            answer++;
        }
    }
    return answer;
}