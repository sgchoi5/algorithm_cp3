#include <cstdio>

int history[10000];

int main(void) {
	int Z, I, M, L, tc = 0;
	while (true) {
		scanf("%d %d %d %d", &Z, &I, &M, &L);
		if (Z == 0 && I == 0 && M == 0 && L == 0)
			break;

		bool go = true;
		int cnt = 0;
		while (go) {
			history[cnt] = L;
			L = (Z * L + I) % M;
			cnt++;
			for (int i = 0; i < cnt; i++) {
				if (L == history[i]) {
					printf("Case %d: %d\n", ++tc, cnt - i);
					go = false;
					break;
				}
			}
		}
	}
	return 0;
}
