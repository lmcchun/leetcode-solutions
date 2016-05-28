int maxProfit(int* prices, int pricesSize) {
	if (pricesSize < 2) {
		return 0;
	}

	int totalProfit = 0;
	int current = 0;
	bool hasBuy = false;
	for (int i = 0; i < pricesSize; ++i) {
		if (!hasBuy) {
			if (prices[i] < prices[i + 1]) {
				current = prices[i];
				hasBuy = true;
			}
		} else {
			if ((prices[i] > prices[i + 1]) || ((i + 1) == pricesSize)) {
				totalProfit += (prices[i] - current);
				current = 0;
				hasBuy = false;
			}
		}
	}
	return totalProfit;
}
