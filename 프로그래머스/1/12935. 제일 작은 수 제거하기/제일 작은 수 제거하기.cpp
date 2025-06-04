#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {

    int min = arr[0];
    vector<int>::iterator idx;
    
    for(vector<int>::iterator i=arr.begin(); i!=arr.end(); i++){
        if(*i <= min){
            min = *i;
            idx = i ;
        }
    }
    arr.erase(idx);
    
    return arr.empty()? vector<int> (1, -1) : arr;
}