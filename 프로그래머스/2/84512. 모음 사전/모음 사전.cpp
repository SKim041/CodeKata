#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
    // 각 알파벳별 단어 총 개수 781
    // 5^0 + 5^1 + 5^2 + 5^3 + 5^4
    for(int i=0; i<word.size(); i++)
    {
        for(int j=0; j<alphabet.size(); j++)
        {
            if(word[i] == alphabet[j])
            {
                int weight=0;
                for(int n=0; n<5-i; n++)
                {
                    weight += pow(5,n);
                }
                answer += weight*j + 1;
                break;
            }
        }
    }
    return answer;
}