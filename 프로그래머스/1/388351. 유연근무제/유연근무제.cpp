#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
	int answer = 0;

	for (int i = 0; i < schedules.size(); i++) {

		int successCount = 0;
		int startTimeLimit = schedules[i] % 100 + 10 > 59 ? 
            (schedules[i] / 100 + 1) * 100 + (schedules[i] % 100 + 10) % 60 : schedules[i] + 10;

		for (int j = startday - 1; j < startday + 6; j++) {		// 7로 나눈 나머지를 월~일 0~6 으로 맞춤

			int timeStamp = timelogs[i][j - startday + 1];

			//  평일 출근시각 비교
			if (j % 7 < 5 and timeStamp <= startTimeLimit) {
				successCount++;
			}		
			// 성공 카운트 5회이상이면 answer++
			if (successCount >= 5) {
				answer++;
				break;
			}
		}

	}

	return answer;

}