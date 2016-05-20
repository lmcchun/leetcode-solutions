int reverse(int x) {
	int sign = (x >= 0) ? 1 : -1;
	x *= sign;

	int result = 0;
	while (x > 0) {
		int remainder = (x % 10);
		if (((INT_MAX / 10) < result) || ((INT_MAX - remainder) < (result * 10))) {
			return 0;
		}
		result = (result * 10) + remainder;
		x /= 10;
	}
	return result * sign;
}
