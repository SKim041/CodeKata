#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> nums = 
    {"zero", "one","two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=0; i<10; i++){
        string number = nums[i];
        if(s.find(number) != string::npos){
            while(s.find(number) != string::npos){
                s.replace(s.find(number), number.length(), to_string(i));
            }
        }
    }    
    return stoi(s);
}