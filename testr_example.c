#include <stdio.h>
#include "testr.h"

int arithmetic(char op, int n1, int n2) {
	switch (op) {
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 / n2;   // Purposeful mistake, can be fixed to show the contrast
			break;
		case '/':
			return n1 / n2;
			break;
		default:
			return -1;
	}
}

TESTR() {
	TEST(arithmetic('+', 1, 2) == 3);
	TEST(arithmetic('-', 1, 2) == -1);
	TEST(arithmetic('*', 2, 3) == 6);
	TEST(arithmetic('/', 4, 2) == 2);
}

int main() {
	int run_tests = 1;
	if (run_tests)
		RUN_TESTS();
	else
		puts("Tests not run");
	return 0;
}
