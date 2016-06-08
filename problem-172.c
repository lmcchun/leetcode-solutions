int trailingZeroes(int n) {
	int counter = 0;
	while (n > 0) {
		n /= 5;
		counter += n;
	}
	return counter;
}
