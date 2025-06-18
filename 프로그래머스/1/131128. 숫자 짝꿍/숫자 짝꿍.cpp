#include <string>
#include <vector>

using namespace std;

int findAll(const string& str, const string& i){
    size_t idx = 0;
    int count = 0;
    while((idx=str.find(i,idx)) != string::npos){
        count++;
        idx+=i.length();
    }
    return count;
    
}

string solution(string X, string Y) {
    string answer = "";
    
    // 각 문자열에 9~0까지 몇개씩 들어있는지 체크
    // 더 적은 수만큼 answer에 추가
    // 0으로 시작하는 경우 Break;
    // answer=="" 면 answer="-1"
    
    for(int i=9; i>=0; i--){
        int countX = findAll(X, to_string(i));
        int countY = findAll(Y, to_string(i));
        int minCount = countX >= countY? countY : countX;

        while(minCount>0){
            if(answer == "0") break;
            minCount--;
            answer+=to_string(i);
        }
        
    }
    if(answer == "") answer = "-1";
    
    return answer;
}