int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
	int i = 0;
	int j;
	int k = 0;
	for (j = 0; j < gasSize; j++) {
		gas[j] -= cost[j];
	}
	while (i < gasSize) {
		for (j = i + 1; j < gasSize; j++) {
			if ((gas[k] >= 0) || (gas[j] <= 0)) {
				gas[k] += gas[j];
			} else {
				k++;
				gas[k] = gas[j];
				i = j;
				break;
			}
		}
		if (j == gasSize) {
			break;
		}
	}
	if (gas[0] >= 0) {
		return 0;
	}
	if ((k > 0) && (gas[k] <= 0)) {
		return -1;
	}
	for (j = 1; j <= k; j++) {
		gas[0] += gas[j];
	}
	if (gas[0] < 0) {
		return -1;
	} else {
		return i;
	}
}
