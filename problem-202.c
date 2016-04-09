/* Floyd Cycle detection algorithm */

int digitSquareSum(int n) {
	int sum = 0;
	int temp;
	while (n != 0) {
		temp = n % 10;
		sum += (temp * temp);
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) {
	int slow = n;
	int fast = n;
	do {
		slow = digitSquareSum(slow);
		fast = digitSquareSum(fast);
		fast = digitSquareSum(fast);
	} while(slow != fast);
	if (slow == 1) {
		return true;
	} else {
		return false;
	}
}
