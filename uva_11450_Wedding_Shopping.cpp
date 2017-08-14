#include <cstdio>
#include <cstring>   // memset
#include <algorithm> // max
using namespace std;

#if 1
// UVa 11450 - Wedding Shopping 문제 - 바텀업
int main(void) {
	int g, money, k, TC, M, C;
	int price[25][25];       // price[g (<= 20)][model <= 20)]
	bool reachable[25][210]; // reachable 테이블 g (<= 20)][money (<= 200)]

	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &M, &C);
		for (g = 0; g < C; g++) {
			scanf("%d", &price[g][0]);    // K 값을 price[g][0]에 저장한다
			for (money = 1; money <= price[g][0]; money++)
				scanf("%d", &price[g][money]);
		}
		memset(reachable, false, sizeof reachable);  // 모든 것을 초기화한다
		for (g = 1; g <= price[0][0]; g++) // 초기 값 (기저 사례)
			if (M - price[0][g] >= 0)      // 배열 첨자 범위를 초과하지 않기 위한 부분이다
				reachable[0][M - price[0][g]] = true;   // g = 0번째 예복

		for (g = 1; g < C; g++) // 남아있는 각각의 예복에 대해
			for (money = 0; money < M; money++)
				if (reachable[g - 1][money])
					for (k = 1; k <= price[g][0]; k++)
						if (money - price[g][k] >= 0)
							reachable[g][money - price[g][k]] = true; // 이또한 도달 가능하다

		for (money = 0; money <= M & !reachable[C - 1][money]; money++);

		if (money == M + 1)
			printf("no solution\n"); // 마지막 행에 켜져 있는 비트가 없다면
		else
			printf("%d\n", M - money);
	}
	return 0;
}

#else
// UVa 11450 - Wedding Shopping 문제 - 탑다운

int M, C, price[25][25]; // price[g (<=20)][model (<=20)]
int memo[210][25];       // 탑다운: dp 테이블 memo[money (<= 200)][g (<= 20)]
int shop(int money, int g) {
	if (money < 0)
		return -1000000000;    // 둘 이상의 기저 사례를 처리할 때는 순서가 중요하다
	if (g == C)
		return M - money;      // 이 행에서 money 는 음수일 수 없다
	int &ans = memo[money][g]; // 메모리 주솔르 저장한다
	if (ans != -1)
		return ans;
	for (int model = 1; model <= price[g][0]; model++)
		ans = max(ans, shop(money - price[g][model], g + 1));
	return ans;

}

int main(void) {
	int i, j, TC, score;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &M, &C);
		for (int i = 0; i < C; i++) {
			scanf("%d", &price[i][0]);   // K 값을 price[i][0] 에 저장한다
			for (j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1, sizeof memo);   // 탑다운: DP 메모 테이블 초기화한다
		score = shop(M, 0);              // 탑다운 DP를 시작한다
		if (score < 0)
			printf("no solution\n");
		else
			printf("%d\n", score);
	}
    return 0;
}
#endif
