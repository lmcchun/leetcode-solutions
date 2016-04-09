/* 实际上是一个斐波那契数列 */
int climbStairs(int n) {
	int a = 1;
	int b = 1;
	int temp;
	int i;
	for (i = 1; i < n; i++) {
		temp = b;
		b += a;
		a = temp;
	}
	return b;
}
