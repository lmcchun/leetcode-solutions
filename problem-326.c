bool isPowerOfThree(int n) {
	/* 1162261467 is 3 ^ 19,  3 ^ 20 is bigger than int */
	/* return (n > 0) && ((1162261467 % n) == 0); */
	if (n <= 0) {
		return false;
	} else if (n == 1) {
		return true;
	} else if ((n % 3) != 0) {
		return false;
	} else {
		return isPowerOfThree(n / 3);
	}
}
