int maxProduct(char** words, int wordsSize) {
	int* masks = (int*)malloc(sizeof(int) * wordsSize);
	int* lengths = (int*)malloc(sizeof(int) * wordsSize);
	int result = 0;
	for (int i = 0; i < wordsSize; ++i) {
		int j = 0;
		masks[i] = 0;
		while (words[i][j] != '\0') {
			masks[i] |= 1 << (words[i][j] - 'a');
			++j;
		}
		lengths[i] = j;
		for (int k = 0; k < i; ++k) {
			if ((masks[k] & masks[i]) == 0) {
				int product = lengths[k] * lengths[i];
				if (product > result) {
					result = product;
				}
			}
		}
	}
	free(masks);
	free(lengths);
	return result;
}
