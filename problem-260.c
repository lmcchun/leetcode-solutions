/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int diff = nums[0];
	for (int i = 1; i < numsSize; ++i) {
		diff ^= nums[i];
	}
	diff &= -diff;

	int *result = (int *)malloc(sizeof(int) * 2);
	result[0] = 0;
	result[1] = 0;
	for (int i = 0; i < numsSize; ++i) {
		if ((nums[i] & diff) == 0) {
			result[0] ^= nums[i];
		} else {
			result[1] ^= nums[i];
		}
	}
	*returnSize = 2;
	return result;
}
