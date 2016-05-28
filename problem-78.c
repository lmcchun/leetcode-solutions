/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const int *a, const int *b) {
	if (*a > *b) {
		return 1;
	} else if (*a < *b) {
		return -1;
	} else {
		return 0;
	}
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	qsort(nums, numsSize, sizeof(int), comp);

	int n = 1 << numsSize;
	int **result = (int **)malloc(sizeof(int *) * n);
	int *temp = (int *)malloc(sizeof(int) * numsSize);
	*columnSizes = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		int index = 0;
		for (int j = 0; j < numsSize; ++j) {
			if ((i & (1 << j)) > 0) {
				temp[index++] = nums[j];
			}
		}
		result[i] = (int *)malloc(sizeof(int) * index);
		for (int j = 0; j < index; ++j) {
			result[i][j] = temp[j];
		}
		(*columnSizes)[i] = index;
	}
	free(temp);
	*returnSize = n;
	return result;
}
