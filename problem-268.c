int missingNumber(int* nums, int numsSize) {
	int n = numsSize * (numsSize + 1) / 2; // 可能超出 int 的表达范围
	for (int i = 0; i < numsSize; ++i) {
		n -= nums[i];
	}
	return n;
}

int missingNumber(int* nums, int numsSize) {
	int n = numsSize;
	for (int i = 0; i < numsSize; ++i) {
		n ^= (i ^ nums[i]);
	}
	return n;
}
