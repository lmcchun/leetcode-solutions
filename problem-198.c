/* 动态规划 */

#define MAX(a, b) ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize) {
	int a = 0;
	int b = 0;
	int i;
	for (i = 0; i < numsSize; i++) {
		if ((i % 2) == 0) {
			a = MAX(a + nums[i], b);
		} else {
			b = MAX(a, b + nums[i]);
		}
	}
	return MAX(a, b);
}
