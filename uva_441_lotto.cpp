#include <cstdio>

int S[13];

int main(void) {
	int k;
	bool first = true;

	while (scanf("%d", &k), k != 0) {
		for (int i = 0; i < k; i++) { // 입력: k개의 정렬된 정수
			scanf("%d", &S[i]);
		}

		if (first)
			first = false;
		else
			printf("\n");

		for (int a = 0; a < k - 5; a++) // 6 중 루프!
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
	}
	return 0;
}
