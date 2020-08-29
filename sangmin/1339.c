#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char ** ary;
	int N;
	int sum = 0;
	char table[26];
	int count[26];
	int value[26];
	int ten;
	int temp;
	int input = 9;
	scanf("%d ", &N);
	ary = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++)
		ary[i] = (char*)malloc(sizeof(char) * 10);

	for (int i = 0; i < 26; i++)
		value[i] = 0;

	for (int i = 0; i < N; i++)
		scanf("%s", ary[i]);

	for (int i = 0; i < N; i++) {
		ten = 1;
		for (int j = 0; j < strlen(ary[i])-1; j++)
			ten *= 10;
		for (int j = 0; j < strlen(ary[i]); j++)
		{
			value[ary[i][j] - 65] += ten;
			ten /= 10;
		}
	}

	for(int i = 0; i<26; i++)
		for (int j = 0; j < 25; j++)
		{
			if (value[j] < value[j + 1])
			{
				temp = value[j];
				value[j] = value[j + 1];
				value[j + 1] = temp;
			}
		}
	for (int i = 0; i < 26; i++) {
		if (value[i] == 0)
			break;
		value[i] *= input--;
		sum += value[i];
	}
	
	printf("%d", sum);
}