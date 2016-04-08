/* 将数组中分为 majority 和非 majority 两种情况, 非 majority 的情况下, count 一定会被减至 0 */
int majorityElement(int* nums, int numsSize) {
	int i;
	int majority;
	int count = 0;
	for (i = 0; i < numsSize; i++) {
		if (count == 0) {
			majority = nums[i];
			count = 1;
		} else if (nums[i] == majority) {
			count++;
		} else {
			count--;
		}
	}
	return majority;
}
