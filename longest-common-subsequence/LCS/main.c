#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 32

char x[6] = {'b', 'd', 'c', 'a', 'b', 'a',}; // 32 bit register
char y[7] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'}; // 32 bit register
int c[6 + 1][7 + 1];

void printArr(int m, int n) {
	int i, j;
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

int lcs(int m, int n)
{
	// 어느 한 쪽이 0인 경우를 모두 0으로 채움
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;

	// Bottom-up 방식으로 캐싱 (행 우선 순서)
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else {
				if (c[i - 1][j] > c[i][j - 1]) c[i][j] = c[i - 1][j];
				else c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[m][n];
}

int main(void) {
	int result = lcs(6, 7);
	printf("result : %d\n", result);
	printArr(6, 7);
}