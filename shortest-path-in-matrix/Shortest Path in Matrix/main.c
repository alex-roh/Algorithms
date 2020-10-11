#define _CRT_SECURE
#include <stdio.h>
#define SIZE 4
#define INF 99999

int M[SIZE + 1][SIZE + 1] = { {6, 7, 12, 5} ,{5, 3, 11, 18}, {7, 17, 3, 3}, {8, 10, 14, 9} };
int L[SIZE + 1][SIZE + 1];

int main(void)
{
	int i, j;

	// initialization
	for (i = 0; i <= SIZE; i++) {
		L[i][0] = INF;
		L[0][i] = INF;
	}

	// main algorithm
	for (i = 1; i <= SIZE; i++) { // 행 우선 순서이므로 행을 먼저 순회
		for (j = 1; j <= SIZE; j++) {
			if (i == 1 && j == 1) 
			{
				L[i][j] = M[i][j];
			}
			else 
			{
				if (L[i - 1][j] < L[i][j - 1])
				{
					L[i][j] = M[i][j] + L[i - 1][j];
				}
				else
				{
					L[i][j] = M[i][j] + L[i][j - 1];
				}
			}
		}
	}

	printf("result : %d\n", L[SIZE][SIZE]);

	return 0;
}