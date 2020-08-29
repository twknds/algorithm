#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;//사람 수
	int result_min = 0;//필요한 시간의 합의 최솟값
	int i;
	int sum = 0;
	cin >> N;
	vector<int> P(N);//각 사람이 돈을 인출하는데 걸리는 시간

	for (i = 0; i < N; i++) {
		cin >> P[i];
	}
	sort(P.begin(), P.end());

	for (i = 0; i < N; i++) {
		sum += P[i];
		result_min += sum;
	}

	cout << result_min;
	return 0;
}