int addDigits(int num) {
	int temp = 0;
	if (num == 0) {
		return 0;
	}
	temp = num % 9;
	if (temp == 0) {
		return 9;
	}
	return temp;
}
