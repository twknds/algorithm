#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct sensor {
	int distance;
	int x;
}sensor;


bool x_compare(sensor a, sensor b) {
	return a.x < b.x;
}
bool dist_compare(sensor a, sensor b) {
	return a.distance < b.distance;
}

//센서
int main(void) {
	int N;//센서 개수
	int K;//집중국 개수
	
	cin >> N;
	cin >> K;

	if (N <= K) {
		cout << 0;
		return 0;
	}

	vector<int> location(N);
	vector<sensor> distance(N - 1);

	int i,j;
	for (i = 0; i < N; i++) {
		cin >> location[i];
	}

	sort(location.begin(), location.end());
	
	for (i = 0; i < N-1; i++) {
		distance[i].distance = location[i + 1] - location[i];
		distance[i].x = i;
	}
	
	sort(distance.begin(), distance.end(),dist_compare);
	
	for (i = 0; i < K - 1; i++) {
		distance.pop_back();
	}
	sort(distance.begin(), distance.end(), x_compare);
	
	int total_min = 0;
	for (i = 0; i < distance.size(); i++) {
		total_min += distance[i].distance;
	}

	cout << total_min;


	
	return 0;
}