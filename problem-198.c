/* 动态规划 */

#define max(a, b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize) {
	int a = 0;
	int b = 0;
	int i;
	for (i = 0; i < numsSize; i++) {
		if ((i % 2) == 0) {
			a = max(a + nums[i], b);
		} else {
			b = max(a, b + nums[i]);
		}
	}
	return max(a, b);
}
