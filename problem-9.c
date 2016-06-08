bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	} else if (x < 10) {
		return true;
	} else {
		int y = (x / 10);
		int z = 0;
		int k = 1;
		while (y != 0) {
			z = (z * 10) + (y % 10);
			y /= 10;
			k *= 10;
		}
		int a = z % 10;
		return (a == (x % 10)) && ((a * k + z) == x);
	}
}
