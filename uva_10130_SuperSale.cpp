#include <cstdio>

int dp[1001][31];

int P[1001];
int W[1001];
int MW[101];

int N;

int max(int a, int b) {
	return a > b ? a : b;
}

int shopping(int item, int remained) {
	if (item > N || remained == 0) {
		return 0;
	}

	int& ret = dp[item][remained];
	if (ret != -1)
		return ret;

	if (W[item] > remained) {
		return ret = shopping(item + 1, remained);
	}
	
	return ret = max(shopping(item + 1, remained), P[item] + shopping(item + 1, remained - W[item]));
}

void init(void) {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 30; j++) {
			dp[i][j] = -1;
		}
	}
}

int main(void) {
	int T, G, ans;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d", &N);
		init();
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &P[i], &W[i]);
		}
		scanf("%d", &G);
		for (int i = 1; i <= G; i++) {
			scanf("%d", &MW[i]);
		}

		for (int i = 1; i <= G; i++) {
			ans += shopping(1, MW[i]);
		}

		printf("%d\n", ans);
	}
	return 0;
}
