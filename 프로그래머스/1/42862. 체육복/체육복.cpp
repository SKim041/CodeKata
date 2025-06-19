#include <algorithm>
#include <vector>

using namespace std;
//전체 학생 수 n
//도난 번호 리스트 lost
//여벌 체육복 리스트 reserve
//체육복있는 최대 학생 수 리턴
//여벌 체육복이 있어도 도난 당할 수 있고 그러면 빌려줄 수 없음

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 도난 당하지 않은 학생 수
    int answer = n - lost.size();   
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // reserve로 본인 도난 여부 확인
    for(int& i: reserve){
        // 본인이 도난당했으면 빌려줄 수 없음
        auto it = find(lost.begin(), lost.end(), i);
        if(it != lost.end()){
            answer++;
            i = 0;
            *it = 0;
        }

    }
    // 앞 뒤 확인
    for(int& i:reserve){
        
        vector<int> closeNum(2,0);
        if(i > 1) closeNum[0] = i-1;
        if(i > 0 && i < n) closeNum[1] = i+1;
        for(int& cNum: closeNum){
            if(cNum == 0) continue;
            auto it = find(lost.begin(), lost.end(), cNum);
            if(it != lost.end()){
                answer++;
                *it = 0;
                break;
            }
        }
    }
        
    
    return answer;
}