#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;//input
	int cnt = 0;//N과 같아질때까지
	long long inc = 1;//1부터 비교~~
	int isitfirst = 0;
	long long rem=0;
	int cmp = -1;
	int digit = 1;//자릿수
	int digit_check=1;
	int over_flag = 0;

	cin >> N;

	while (!(N == cnt)) {
		digit = 1;
		digit_check = 1;
		
		if (rem==9876543210) {
			rem = -1;
			break;
		}

		//자릿수 check
		rem = inc;
		while (inc/10) {
			digit_check++;
			inc /= 10;
		}
		inc = rem;
		
		

		//첫번째 숫자가 자릿 수부터 검사
		//첫번째 숫자 == 자릿 수 -1 ==> cnt++
		//첫번째 숫자 >= 자릿 수-1 이어야 함
		if (inc/pow(10,digit_check-1) < (digit_check-1)) {
			inc = pow(10, digit_check - 1) * ((digit_check - 1));
			continue;
		}
		else if (inc / pow(10, digit_check - 1) == (digit_check - 1)) { //첫번째 숫자 == 자릿수 -1 ==> 검사할 필요 없음
			cnt++;
			inc = inc + pow(10, digit_check - 1);
			if (digit_check == 10) {
				rem = 9876543210;
			}
			
			continue;
		}
		else if(inc / pow(10, digit_check - 1) >= digit_check){ //검사해야함
			while (inc != 0) {
				if (cmp < inc % 10) {
					cmp = inc % 10;	
					digit *= 10;
					inc /= 10;
				}
				else {
					rem = (rem / digit) * digit + digit - 1;
					break;
				}
				if (inc == 0) {
					cnt++;
				}
			}
		}
		

		inc = rem + 1;
		cmp = -1;
		digit = 1;
	}
		

	cout << rem;

	return 0;
}
