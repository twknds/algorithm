#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int N, M; //Çà,¿­
	int i,j;
	int K;
	int zero_cnt = 0;
	int cnt = 0;
	string lamp[52];
	
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> lamp[i];
	}
	cin >> K;

	int max = 0;

	if (K % 2 == 0) {	//K°¡ Â¦¼ö
		for (i = 0; i < N; i++) {
			zero_cnt = 0;
			cnt = 0;
			for (j = 0; j < M; j++){
				if (lamp[i][j] == '0') {
					zero_cnt++;
				}
			}
			if (zero_cnt <= K && (zero_cnt % 2 == 0)) {
				for (j = 0; j < N; j++) {
					if (lamp[i].compare(lamp[j]) == 0) {
						cnt++;
					}
				}
			}
			if (max < cnt) {
				max = cnt;
			}
		}
	}
	else {	//K°¡ È¦¼ö
		for (i = 0; i < N; i++) {
			zero_cnt = 0;
			cnt = 0;
			for (j = 0; j < M; j++) {
				if (lamp[i][j] == '0') {
					zero_cnt++;
				}
				if (zero_cnt > K) {
					break;
				}
			}
			if (zero_cnt <= K && (zero_cnt % 2 == 1)) {
				for (j = 0; j < N; j++) {
					if (lamp[i].compare(lamp[j]) == 0) {
						cnt++;
					}
				}
			}
			if (max < cnt) {
				max = cnt;
			}


		}
	}

	cout << max;

	return 0;
}