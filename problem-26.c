int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) {
		return 0;
	}
	int i1 = 0;
	for (int i = 1; i < numsSize; ++i) {
		if (nums[i] != nums[i1]) {
			++i1;
			if (i1 != i) {
				nums[i1] = nums[i];
			}
		}
	}
	return i1 + 1;
}
