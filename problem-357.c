int countNumbersWithUniqueDigits(int n) {
	if (n < 0) {
		return 0;
	} else if (n == 0) {
		return 1;
	} else if (n > 10) {
		n = 10;
	}
	int sum = 10;
	for (int i = 2; i <= n; ++i) {
		int product = 9;
		for (int j = (11 - i); j <= 9; ++j) {
			product *= j;
		}
		sum += product;
	}
	return sum;
}
