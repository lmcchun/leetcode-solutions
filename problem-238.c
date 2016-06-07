/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int *result = (int *)malloc(sizeof(int) * numsSize);
	result[0] = 1;

	int *tmp = (int *)malloc(sizeof(int) * numsSize);
	tmp[numsSize - 1] = 1;

	for (int i = 1; i < numsSize; ++i) {
		int iMinorOne = i - 1;
		result[i] = result[iMinorOne] * nums[iMinorOne];

		int j = numsSize - i;
		tmp[j - 1] = tmp[j] * nums[j];
	}

	for (int i = 0; i < numsSize; ++i) {
		result[i] *= tmp[i];
	}

	free(tmp);
	*returnSize = numsSize;
	return result;
}
