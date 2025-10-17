#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a % b);
}
int findGcdOfArray(vector<int>& arr)
{
    int result = arr[0];
    
    for(int i=1; i<arr.size(); i++)
    {
        result = gcd(result, arr[i]);
    }
    
    return result;
}
int getAnswer(vector<int>& arr, int gcd)
{    
    for(int& i:arr)
    {
        if(i%gcd == 0)
        {
            return 0;
        }
    }   
    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answerA = getAnswer(arrayA, findGcdOfArray(arrayB));
    int answerB = getAnswer(arrayB, findGcdOfArray(arrayA));
        
    return answerA>answerB? answerA:answerB;
}