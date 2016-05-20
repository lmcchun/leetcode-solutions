/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	if ((nums1 == NULL) || (nums1Size == 0) || (nums2 == NULL) || (nums2Size == 0)) {
		return NULL;
	}

	int* pIntTemp = NULL;
	int intTemp = -1;
	if (nums1Size > nums2Size) {
		pIntTemp = nums1;
		intTemp = nums1Size;
		nums1 = nums2;
		nums1Size = nums2Size;
		nums2 = pIntTemp;
		nums2Size = intTemp;
	}

	int* flagArray = malloc(sizeof(int) * nums1Size);
	for (int i = 0; i < nums1Size; i++) {
		flagArray[i] = 0;
	}

	int intersectionCount = 0;
	for (int i = 0; i < nums2Size; i++) {
		for (int j = 0; j < nums1Size; j++) {
			if ((nums1[j] == nums2[i]) && (flagArray[j] == 0)) {
				flagArray[j] = 1;
				intersectionCount++;
				break;
			}
		}
	}

	if (intersectionCount == 0) {
		free(flagArray);
		return NULL;
	}

	int* result = malloc(sizeof(int) * intersectionCount);
	int currentIndex = 0;
	for (int i = 0; i < nums1Size; i++) {
		if (flagArray[i] == 1) {
			result[currentIndex] = nums1[i];
			currentIndex++;
		}
	}

	free(flagArray);

	return result;
}
