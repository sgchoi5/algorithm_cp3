#include <cstdio>
#include <vector>
#include <algorithm>  // next_permutation 이 C++ STL에 들어있다
using namespace std;

int n, m, i, p[8] = { 0, 1, 2, 3, 4, 5, 6, 7 }; // 첫 번째 순열
int a[21], b[21], c[21];

bool possible(void) {
	for (int i = 0; i < m; i++) {
		if (c[i] > 0 && abs(p[a[i]] - p[b[i]]) > c[i])
			return false;
		if (c[i] < 0 && abs(p[a[i]] - p[b[i]]) < -c[i])
			return false;
	}
	return true;
}

int main(void) {
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &a[i], &b[i], &c[i]);

		int cnt = 0;
		do {
			if (possible())
				cnt++;
		} while (next_permutation(p, p + n));
		printf("%d\n", cnt);
	}
	return 0;
}
