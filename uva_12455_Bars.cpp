#include <cstdio>

int bars[20];

int main(void) {
	int t, n, p, sum;
	scanf("%d", &t);
	while (t--) {
		bool found = false;
		scanf("%d %d", &n, &p);
		for (int i = 0; i < p; i++) {
			scanf("%d", bars + i);
		}
		for (int i = 0; i < (1 << p); i++) { // 각각의 부분집합에 대해, O(2^n)
			sum = 0;
			for (int j = 0; j < p; j++) // 포함되었는지 여부를 확인한다. O(n)
				if (i & (1 << j))       // 부분집합 'i' 에 대해 비트 'j'가 켜져 있는가?
					sum += bars[j];     // 만일 그렇다면, 'j'를 처리한다
			if (sum == n) {             // 답을 찾았다. 비트마스크 'i'다
				found = true;
				break;
			}
		}
		if (found)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
