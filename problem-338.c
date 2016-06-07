/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
	int *result = malloc(sizeof(int) * (num + 1));
	result[0] = 0;
	int counter = 1;
	while (counter <= num) {
		int i;
		int j;
		for (i = 0, j = counter; (i < counter) && (j <= num); ++i, ++j) {
			result[j] = result[i] + 1;
		}
		counter = j;
	}
	*returnSize = counter;
	return result;
}
