int hammingWeight(uint32_t n) {
	int i;
	int weight = 0;
	uint32_t temp;
	for (i = 0; i < 32; i++) {
		temp = (uint32_t) 1 << i;
		if ((n & temp) != 0) {
			weight++;
		}
	}
	return weight;
}
