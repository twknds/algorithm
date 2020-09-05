#include <stdio.h>

int main()
{
	int man;
	int temp;
	int sum1 = 0;
	int sum2 = 0;
	int arr[1000];

	scanf("%d", &man);
	for (int i = 0; i < man; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < man; i++) {
		for (int j = 0; j < man - (i + 1); j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				
			}
		}
	}



	for (int i = 0; i < man; i++) {
		sum1 += arr[i];
		sum2 += sum1;
	}
	printf("%d",sum2);


}
