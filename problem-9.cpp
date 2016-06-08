class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0) {
				return false;
			}
			int tmp = x;
			int k = 1;
			while ((tmp /= 10) != 0) {
				k *= 10;
			}
			tmp = x;
			while (k != 0) {
				if ((tmp / k) != (tmp % 10)) {
					return false;
				}
				tmp %= k;
				tmp /= 10;
				k /= 100;
			}
			return true;
		}
};
