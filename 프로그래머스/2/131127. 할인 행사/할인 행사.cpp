#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0; i<=discount.size()-10; i++)
    {
        unordered_map<string, int> wishlist;
        for(int idx=0; idx<want.size(); idx++)
        {
            wishlist[want[idx]]=number[idx];
        }
        for(vector<string>::iterator it=discount.begin()+i; it<discount.begin()+i+10; it++)
        {
            if (wishlist.find(*it)!=wishlist.end())
            {
                wishlist[*it]--;
                if(wishlist[*it]==0) wishlist.erase(*it);
            }
            if(wishlist.size()==0) break;
        }
        if(wishlist.size()==0) answer++;
    }
    return answer;
}