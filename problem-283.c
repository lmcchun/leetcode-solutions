void moveZeroes(int* nums, int numsSize) {
	int i;
	int j = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != 0) {
			if (j != i) {
				nums[j] = nums[i];
				nums[i] = 0;
			}
			j++;
		}
	}
}
