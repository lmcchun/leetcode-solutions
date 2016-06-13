// int 数据共有 32 位, 可以用 32 变量存储这 N 个元素中各个二进制位上 1 出现的次数, 最后在进行模三操作.
// 要求 int 类型为 32 位.
int singleNumber(int* nums, int numsSize) {
	int bitNums[32] = {0};
	int result = 0;
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < numsSize; ++j) {
			bitNums[i] += ((nums[j] >> i) & 1);
		}
		result |= ((bitNums[i] % 3) << i);
	}
	return result;
}

int singleNumber(int* nums, int numsSize) {
	int one = 0; // 每一位上的 1 表示之前恰好有 3 * n + 1 个数在该位上为 1
	int two = 0; // 每一位上的 1 表示之前恰好有 3 * n + 2 个数在该位上为 1
	for (int i = 0; i < numsSize; ++i) {
		two |= (one & nums[i]); // 包括 3 * n + 2 和部分 3 * n + 3
		one ^= nums[i]; // 包括 3 * n + 1 和部分 3 * n + 3
		int notThree = ~(one & two);
		one &= notThree; // 移除 3 * n + 3
		two &= notThree; // 移除 3 * n + 3
	}
	return one;
}
