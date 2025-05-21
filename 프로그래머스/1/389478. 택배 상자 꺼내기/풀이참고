#include <string>
#include <vector>

using namespace std;


int solutionA(int n, int w, int num) {
	int answer = 0;
	while (num <= n) { 
		answer++; 
		num += (w - 1 - (w + num - 1) % w) * 2 + 1; 
		cout << "answer: " << answer << endl;
		cout << "num: " << num << endl;
	}

	return answer;
}
// num-1은 0을 기준으로 현재 줄에서 박스의 인덱스를 나타냄
// w + ( num - 1 ) 을 사용하는 이유는 % w로 나머지를 구할 때 음수가 되는 것을 방지 (num이 1이하 일 때)
// 이 인덱스는 해당 줄의 시작 위치부터의 인덱스
// 이 인덱스로 해당 줄의 마지막까지 몇 칸 남았는지 계산 -> w - 1 - (w + num - 1) % w
// 예시) 0번째 줄에서 이 칸 수 만큼 오른쪽으로 갔다가 1번째 줄에서는 이만큼 왼쪽으로 돌아오고 
// 한 칸 더 가면 num 박스의 바로 위 박스 넘버
