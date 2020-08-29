#include <stdio.h>
#include <string.h>

char input[52][52];
char count[52];

int main()
{
	int raw, col, k, max = 0;
	int zero_count;
	scanf("%d %d", &raw, &col);
	for (int i = 0; i < raw; i++) {
		scanf("%s", input[i]);
		for (int j = 0; j <= i; j++)
			if (strcmp(input[i], input[j]) == 0) {
				count[j]++;
				break;
			}
	}
	scanf("%d", &k);

	for (int i = 0; i < raw; i++)
	{
		zero_count = 0;
		if (count[i] != 0) 
		{
			for (int j = 0; j < col; j++)
				if (input[i][j] == '0')
					zero_count++;
			if (k % 2 == zero_count % 2 && zero_count <= k)
				if (max < count[i])
					max = count[i];
		}
	}
	printf("%d", max);
}