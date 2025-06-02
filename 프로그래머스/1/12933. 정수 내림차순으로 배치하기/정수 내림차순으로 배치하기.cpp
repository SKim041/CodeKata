#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> vNum;
    string strAnswer;

    for (char c : to_string(n)) {
        vNum.push_back(c - '0');
    }

    while (vNum.size() > 0) {
        bool isFirst = true;
        int max = 0;
        for (vector<int>::iterator i = vNum.begin(); i != vNum.end(); i++) {
            if (isFirst) {
                max = *i;
                isFirst = false;
                continue;
            }
            if (*i > max) {
                max = *i;
            }
        }
        for (vector<int>::iterator i = vNum.begin(); i != vNum.end();) {
            if (*i == max) {
                strAnswer += to_string(*i);
                i = vNum.erase(i);                
            }
            else {
                i++;
            }
        }
    }
    answer = stoll(strAnswer);
    return answer;
}