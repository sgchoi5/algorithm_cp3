#include <cstdlib> // 우리는 'abs'의 정수 버전을 사용한다
#include <cstdio>
#include <cstring>
using namespace std;

int row[8], TC, a, b, lineCounter; // 전역 변수를 사용해도 좋다

bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++) // 이미 배치된 퀸에 대해 확인한다
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
			return false; // 같은 행이나 같은 대각선에 있다면 불가능하다
	return true;
}

void backtrack(int c) {
	if (c == 8 && row[b] == a) { // 후보 해, (a, b)에 퀸이 하나 있다
		printf("%2d      %d", ++lineCounter, row[0] + 1);
		for (int j = 1; j < 8; j++)
			printf(" %d", row[j] + 1);
		printf("\n");
	}
	for (int r = 0; r < 8; r++) // 가능한 모든 행에 대해 시도해본다
		if (place(r, c)) { // 이 행과 열에 퀸을 배치할 수 있다면
			row[c] = r;
			backtrack(c + 1); // 이번 퀸을 여기에 배치하고 재귀를 수행한다
		}
}

int main(void) {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		a--; b--; // 인덱스가 0 번부터 시작하도록 변환한다
		memset(row, 0, sizeof row);
		lineCounter = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if (TC)
			printf("\n");
	}
	return 0;
}
