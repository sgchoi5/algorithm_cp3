#include <cstdio>

int abs(int a) {
	return a < 0 ? -a : a;
}

int main(void) {
	int n, prev, cur;
	while (scanf("%d", &n) != EOF) {
		bool flag[3000] = { false };
		scanf("%d", &prev);
		for (int i = 1; i < n; i++) {
			scanf("%d", &cur);
			if (abs(cur - prev) > 0 && abs(cur - prev) < n)
				flag[abs(cur - prev)] = true;
			prev = cur;
		}
		bool jolly = true;
		for (int i = 1; i < n; i++) {
			if (flag[i] == false) {
				jolly = false;
				break;
			}
		}
		if (jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}
