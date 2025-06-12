using namespace std;

int solution(int a, int b, int n) {
    // a: 빈병    b: 주는 콜라    n: 내가 가져간 빈병
    int answer = 0;
    int reward = 0;
    int rest_empty = n;
    while(rest_empty >= a){
        reward = rest_empty / a * b;
        rest_empty = reward + rest_empty % a;
        answer += reward;
    }
    return answer;
}