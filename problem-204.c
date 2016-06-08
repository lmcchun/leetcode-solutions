int countPrimes(int n) {
	if (n <= 2) {
		return 0;
	}

	char* sieve = (char*)malloc(sizeof(char) * n);
	memset(sieve, 0, sizeof(char) * n);

	int counter = 1;
	int upper = sqrt(n);
	for (int i = 3; i < n; i += 2) {
		if (sieve[i] == 0) {
			++counter;

			if (i <= upper) {
				for (int j = i * i; j < n; j += i) {
					sieve[j] = 1;
				}
			}
		}
	}

	free(sieve);

	return counter;
}
