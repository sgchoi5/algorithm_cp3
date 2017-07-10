#include <cstdio>

int main(void) {
	int N;
	bool start = true;
	while (scanf("%d", &N), N > 0) {
		if (start) {
			start = false;
		}
		else {
			printf("\n");
		}

		bool found = false;
		for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
			int abcde = fghij * N; // 이렇게 하면 abcde와 fghj 가 모두 최대 다섯 자리가 된다
			int tmp, used = (fghij < 10000); // 만일 숫자 f가 0이면, 이를 체크해 두어야 한다
			tmp = abcde;
			while (tmp)
			{
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}
			tmp = fghij;
			while (tmp)
			{
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}
			if (used == (1 << 10) - 1) // 모든 숫자가 사용되었다면 결과를 출력한다
			{
				found = true;
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
			}
		}
		if (!found)
			printf("There are no solutions for %d.\n", N);		
	}
	
	return 0;
}
