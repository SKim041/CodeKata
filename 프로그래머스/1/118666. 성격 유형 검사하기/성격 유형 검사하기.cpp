#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> mbti = {{'R', 0}, {'T', 0},
                                     {'C', 0}, {'F', 0},
                                     {'J', 0}, {'M', 0},
                                     {'A', 0}, {'N', 0}};
    for(int i = 0; i < choices.size(); i++)
    {
        if (choices[i] < 4)
        {
            mbti[survey[i][0]] += 4 - choices[i];
        }
        else if (choices[i] > 4)
        {
            mbti[survey[i][1]] += choices[i] - 4;
        }       
    }
    if(mbti['R'] >= mbti['T']) answer += 'R';
    else answer += 'T';
    
    if(mbti['C'] >= mbti['F']) answer += 'C';
    else answer += 'F';
    
    if(mbti['J'] >= mbti['M']) answer += 'J';
    else answer += 'M';
    
    if(mbti['A'] >= mbti['N']) answer += 'A';
    else answer += 'N';
    return answer;
}