int removeElement(int* nums, int numsSize, int val) {
	int start = 0;
	int end = numsSize;
	while (start < end) {
		if (nums[start] == val) {
			--end;
			for (int i = start; i < end; ++i) {
				nums[i] = nums[i + 1];
			}
		} else {
			++start;
		}
	}
	return end;
}
