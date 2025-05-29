#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int item : arr){
        answer+=item;
    }
    return answer/(double)arr.size();
}