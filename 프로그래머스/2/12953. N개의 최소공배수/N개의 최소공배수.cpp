#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    // 중복제거
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int lcd = arr[0];
    // 두 수의 최소공배수 구하기
    for (int i = 1; i < arr.size(); i++)
    {
        // 최대공약수
        int gcd = 1;
        int min = lcd > arr[i] ? lcd : arr[i];
        int max = lcd > arr[i] ? arr[i] : lcd;
        for (int j = 2; j <= min; )
        {
            if (min % j == 0 && max % j == 0)
            {
                min /= j;
                max /= j;
                gcd *= j;
            }
            else j++;
        }
        // 최소공배수
        lcd = lcd * arr[i] / gcd;

    }

    return lcd;
}