#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;//��� ��
	int result_min = 0;//�ʿ��� �ð��� ���� �ּڰ�
	int i;
	int sum = 0;
	cin >> N;
	vector<int> P(N);//�� ����� ���� �����ϴµ� �ɸ��� �ð�

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