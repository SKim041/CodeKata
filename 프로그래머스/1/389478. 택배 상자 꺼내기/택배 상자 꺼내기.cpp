#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int row = 0;
    int col = 0;
    int last_row = 0;
    int last_col = 0;

	//짝수층 왼쪽>오른쪽 
	//홀수층 오른쪽>왼쪽

	// num 좌표 구하기
	///num이 w의 배수일 때 아닐 때 구분
	if (num % w == 0) {							
		row = num / w - 1;
		col = (row % 2 == 1) ? 0 : w - 1;
	}
	else {
		row = num / w;
		col = (row % 2 == 1) ? w - num % w : num % w - 1;
	}
	// 마지막 박스의 좌표 구하기
	///n이 w의 배수일 때 아닐 때 구분
	if (n % w == 0) {
		last_row = n / w - 1;
		last_col = (last_row % 2 == 1) ? 0 : w - 1;
	}
	else {
		last_row = n / w;
		last_col = (last_row % 2 == 1) ? w - n % w : n % w - 1;
	}

	// answer
	answer = last_row - row + 1;
	// 층별 마지막 박스의 위치 고려
	if (last_row % 2 == 1 ) {
		if (last_col > col) {
			answer--;
		}
	}
	else {
		if (last_col < col) {
			answer--;
		}
	}

	return answer;
}