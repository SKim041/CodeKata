#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    stringstream answer;
    // 기호 제거 후 int로 변환
    int intVideoLen = stoi(video_len.erase(2,1));
    int intPos = stoi(pos.erase(2,1));
    int intOp_start = stoi(op_start.erase(2,1));
    int intOp_end = stoi(op_end.erase(2,1));

    //
    for (int i = 0; i < commands.size(); i++) {
        int intTemp=0;

        // 1. pos가 오프닝 구간인지 확인
        if (intOp_start <= intPos && intPos <= intOp_end) {
            intPos = intOp_end;
        }

        //prev면 -10초, next면 +10초
        int moveTime = commands[i] == "prev" ? -10 : 10;
        
        // 2.prev일때 pos가 10초 미만인지 확인
        if (moveTime < 0) {
            intPos = (abs(intPos + moveTime)) % 100 > 59 ?
                (intPos / 100 - 1) * 100 + (intPos % 100 + moveTime + 60) % 60 : intPos + moveTime;
            intPos = intPos < 10 ? 0 : intPos;
        }
        // 3. 남은 시간이 10초 미만인지 확인
        else {
            intPos = (intPos + moveTime) % 100 > 59 ?
                intPos + moveTime + 100 - 60 : intPos + moveTime;
            intPos = intPos > intVideoLen - 10 ? intVideoLen : intPos;
        }
              
    }
    // 4. pos가 오프닝 구간인지 재확인
    if (intOp_start <= intPos && intPos <= intOp_end) {
        intPos = intOp_end;
    }

    answer << setfill('0') << setw(2) << intPos / 100 << ":" << setfill('0') << setw(2) << intPos % 100;

    return answer.str();
}