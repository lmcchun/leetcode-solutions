class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			vector<int> result;
			int carry = 1;
			for (vector<int>::const_reverse_iterator iter = digits.crbegin(), end = digits.crend(); iter != end; ++iter) {
				carry += *iter;
				result.push_back(carry % 10);
				carry /= 10;
			}
			if (carry != 0) {
				result.push_back(carry);
			}
			return vector<int>(result.rbegin(), result.rend());
		}
};
