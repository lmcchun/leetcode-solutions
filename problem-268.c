int missingNumber(int* nums, int numsSize) {
	int n = numsSize * (numsSize + 1) / 2;
	for (int i = 0; i < numsSize; ++i) {
		n -= nums[i];
	}
	return n;
}
