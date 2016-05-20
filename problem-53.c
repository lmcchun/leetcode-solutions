int maxSubArray(int* nums, int numsSize) {
	int prev = nums[0];
	int max = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (prev < 0) {
			prev = nums[i];
		} else {
			prev += nums[i];
		}
		if (prev > max) {
			max = prev;
		}
	}
	return max;
}
