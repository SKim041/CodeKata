#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {

    int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string dates[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    
    for(int i=1; i<a; i++){
        b+=days[i-1];
    }
    
    return dates[b%7];
}