#include <string>
#include <vector>

using namespace std;

void replaceAll(string& str, const string& item1, const string& item2) {
    size_t idx = str.find(item1, 0);
    while (idx != string::npos) {
        str.replace(idx, item1.length(), item2);
        idx = str.find(item1, idx + item2.length());
    }

}

// 연속하지만 않으면 발음할 수 있음
bool isMatch(string& bbItem, const string& cItem, size_t pos, int count) {
    size_t idx = bbItem.find(cItem, pos);
    if (count == 0) {
        if (idx == string::npos) {
            return true;
        }
    }
    else {
        if (idx == pos) {
            return false;
        }

        else if (idx == string::npos) {
            return true;
        }
    }

    return isMatch(bbItem, cItem, idx + cItem.length(), count + 1);

}

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> correct = { "aya", "ye", "woo", "ma" };
    for (auto& item : babbling) {
        for (auto& c : correct) {
            if (item == "") {
                break;
            }
            if (isMatch(item, c, (size_t)0, 0)) {
                replaceAll(item, c, " ");
            }
            else {
                break;
            }
        }
        replaceAll(item, " ", "");
        if (item == "") answer++;
    }

    return answer;
}