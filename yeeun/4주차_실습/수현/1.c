#include <stdio.h>
int main()
{
	int num = 1234;
	printf("12345678901234567890\n");
	printf("===%-6d===\n", num);
	return 0;
}
/*
A.
12345678901234567890
===1234===
B.
===  1234===
C.
===001234===
D.
===1234  ===
E.
6 콘솔에서 자리 6칸확보
0 공백을 0으로 채움
- 좌측정렬
*/