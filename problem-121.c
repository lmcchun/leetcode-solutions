#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

int maxProfit(int* prices, int pricesSize) {
	if (pricesSize < 2) {
		return 0;
	}

	int maxPro = prices[1] - prices[0];
	int minPrice = MIN(prices[0], prices[1]);

	for (int i = 2; i < pricesSize; i++) {
		maxPro = MAX(prices[i] - minPrice, maxPro);
		minPrice = MIN(prices[i], minPrice);
	}

	if (maxPro < 0) {
		return 0;
	}

	return maxPro;
}
