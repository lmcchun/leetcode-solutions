uint32_t reverseBits(uint32_t n) {
	uint32_t one = 1;
	uint32_t result = 0;
	for (uint32_t i = 0; i < 16; ++i) {
		result += ((n & (one << i)) << (31 - (2 * i)));
	}
	for (uint32_t i = 16; i < 32; ++i) {
		result += ((n & (one << i)) >> (2 * i - 31));
	}
	return result;
}
