#include <stdio.h>

int main() {
	int number = 0;
	scanf("%d", &number);
	int count = 0;

	for (; count < number; ++count) {
		int fibonacci_Number = 0;
		scanf("%d", &fibonacci_Number);

		if (fibonacci_Number == 0)
			printf("%d %d\n", 1, 0);
		else if (fibonacci_Number == 1)
			printf("%d %d\n", 0, 1);
		else {
			int temp1[2] = { 1 , 0 }; // 전전 fibonaci
			int temp2[2] = { 0 , 1 }; // 직전 fibonaci
			int temp3[2] = { 0 }; // fibonaci(N)이 갖는 0과 1 출력개수를 저장하는 배열
			int a = 2; // 2이상의 수 고려시

			for (; a <= fibonacci_Number; ++a) {
				int index = 0;

				for (; index < 2; ++index) { // 피보나치 계산 후 저장, 다음 연산을 위한 값 넘김
					temp3[index] = temp1[index] + temp2[index];
					temp1[index] = temp2[index];
					temp2[index] = temp3[index];
				}
			}
			printf("%d %d\n", temp3[0], temp3[1]); // 연산이 끝난 후 출력문
		}
	}


	return 0;
}
