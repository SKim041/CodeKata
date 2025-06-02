#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int n = 0;
    for(char c:to_string(x)){
        n += c - '0';
    }
    return x % n == 0;
}