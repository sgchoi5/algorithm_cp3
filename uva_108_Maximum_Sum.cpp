#include <cstdio>

const int MAX = 100;
int A[MAX + 1][MAX + 1];

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, subRect;
	scanf("%d", &n); // 입력될 정사각 행렬의 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
			if (i > 0)
				A[i][j] += A[i - 1][j]; // 가능한 경우라면, 위쪽 값을 더한다
			if (j > 0)
				A[i][j] += A[i][j - 1]; // 가능한 경우라면, 왼쪽 값을 더한다
			if (i > 0 && j > 0)
				A[i][j] -= A[i - 1][j - 1]; // 중복 계산은 피한다 (포함-배제의 원리)
		}
	}

	int maxSubRect = -127 * 100 * 100; // 이 문제에 대해 가장 작은 값
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) // 시작 좌표
			for (int k = i; k < n; k++)
				for (int l = j; l < n; l++) { // 끝 좌표
					subRect = A[k][l]; // (0,0)부터 (k,l)까지의 원소들의 합을 O(1)에 계산한다
					if (i > 0)
						subRect -= A[i - 1][l]; // O(1)
					if (j > 0)
						subRect -= A[k][j - 1]; // O(1)
					if (i > 0 && j > 0)
						subRect += A[i - 1][j - 1]; // O(1)
					maxSubRect = max(maxSubRect, subRect);
				}
	printf("%d\n", maxSubRect);
	return 0;
}
