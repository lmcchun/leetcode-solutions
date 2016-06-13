int fn(int n, int* p, int currentRow) {
	if (currentRow == n) {
		return 1;
	}

	int sum = 0;

	int nextRow = currentRow + 1;
	for (int i = currentRow; i < n; ++i) {
		for (int j = 0; j < currentRow; ++j) {
			int rowDiff = currentRow - j;
			int columnDiff = p[i] - p[j];
			if ((rowDiff == columnDiff) || (rowDiff == -columnDiff)) {
				goto LABEL;
			}
		}

		int tmp = p[i];
		p[i] = p[currentRow];
		p[currentRow] = tmp;

		sum += fn(n, p, nextRow);

		p[currentRow] = p[i];
		p[i] = tmp;

LABEL:
		;
	}

	return sum;
}

int totalNQueens(int n) {
	int* p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
	}
	int sum = fn(n, p, 0);
	free(p);
	return sum;
}
