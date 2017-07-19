// http://gooddaytocode.blogspot.kr
// 회고
// 1) BOJ: https://www.acmicpc.net/problem/7563
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1025;
const int INF = 987654321;
int killed[MAX + 1][MAX + 1];

typedef struct _RatInfo {
	int y;
	int x;
	int num;
} RatInfo;
vector<RatInfo> ratInfo;

int abs(int a) {
	return a >= 0 ? a : -a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

bool isSafe(int y, int x) {
	if (y < 0 || y >= MAX || x < 0 || x >= MAX)
		return false;
	return true;
}

int main(void) {
	int T, d, n, x, y, size;
	scanf("%d", &T);
	while (T--) {
		int ans = 0, indexI = INF, indexJ = INF;
		scanf("%d %d", &d, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &size);
			ratInfo.push_back(RatInfo{ y, x, size });
		}

		for (int k = 0; k < ratInfo.size(); k++) {
			for (int i = -d; i <= d; i++) {
				for (int j = -d; j <= d; j++) {
					if (isSafe(ratInfo[k].y + i, ratInfo[k].x + j) &&
						max(abs(i), abs(j)) <= d) {
						killed[ratInfo[k].y + i][ratInfo[k].x + j] += ratInfo[k].num;
					}
				}
			}
		}

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (killed[i][j] > ans) {
					ans = killed[i][j];
					indexI = i;
					indexJ = j;
				}
				else if (killed[i][j] == ans) {
					if (indexJ > j) {
						indexJ = j;
						indexI = i;
					}
					else if (indexJ == j) {
						if (indexI > i) {
							indexI = i;
						}
					}
				}
				killed[i][j] = 0;
			}
		}
		printf("%d %d %d\n", indexJ, indexI, ans);
		ratInfo.clear();
	}

	return 0;
}
