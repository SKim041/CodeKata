#include <string>

using namespace std;

string solution(string s) {

    bool bIsFirst = true;
    for(char& c:s)
    {
        // 공백 건너뛰기
        if(c==' ')
        {
            bIsFirst = true;
            continue;
        }
        // 첫 문자 확인
        if(bIsFirst && c >= 'a')
        {
            c = c - ('a'-'A');
        }
        // 첫 문자 아닌 대문자 확인
        else if(!bIsFirst && c < 'a')
        {
            c = c + ('a'-'A');
        }
        
        bIsFirst = false;
    }
    return s;
}