#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;

    for(int i=0; i<s.size(); i++)
    {
        // 길이가 홀수일 때
        int temp=1;
        int left = i-1;
        int right = i+1;
        
        while(left>=0 && right<s.size())
        {
            if(s[left]!=s[right]) break;
            temp+=2;
            left--;
            right++;
        }
        if(temp>answer) answer=temp;
        // 길이가 짝수일 때
        if(s[i]==s[i+1])
        {
            temp = 2;
            left = i-1;
            right = i+2;
            while(left>=0 && right<s.size())
            {
                if(s[left]!=s[right]) break;
                temp+=2;
                left--;
                right++;
            }
        }
        if(temp>answer) answer=temp;
    }    

    return answer;
}