#include <cstdio>

int main(void) {
	int N, A, B, C;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d %d", &A, &B, &C);
		bool sol = false;
		int x, y, z;
		for (x = -100; x <= 100; x++) {
			for (y = -100; y <= 100; y++) {
				for (z = -100; z <= 100; z++) {
					if (y != x && z != x && z != y && // 세 정수는 서로 달라야 한다
						x + y + z == A && x * y * z == B && x*x + y*y + z*z == C) {
						if (!sol)
							printf("%d %d %d\n", x, y, z);
						sol = true;
					}
				}
			}
		}
		if (!sol) {
			printf("No solution.\n");
		}
	}
	return 0;
}
