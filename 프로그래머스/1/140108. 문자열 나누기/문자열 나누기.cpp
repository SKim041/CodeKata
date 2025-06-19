#include <string>

using namespace std;
int splitString(string str, int count){
    char x = str[0];
    int countX = 0;
    int countOther = 0;
    int i = 0;
    for( ; i<str.length(); i++){
        if(str[i]==x) countX++;
        else countOther++;
        if(countX == countOther) break;
    }
    if(i<str.length()-1) return splitString(str.substr(i+1), ++count);
    else return count;
}

int solution(string s) {
    return splitString(s,1);
}