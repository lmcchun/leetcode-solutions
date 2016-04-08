int romanToInt(char* s) {
	int* nums;
	int i = 0;
	int size = 0;
	int sum = 0;
	while (s[size] != '\0') {
		size++;
	}
	nums = (int*)malloc(size * sizeof(int));
	while (s[i] != '\0') {
		switch (s[i]) {
			case 'I':
				nums[i] = 1;
				break;
			case 'V':
				nums[i] = 5;
				break;
			case 'X':
				nums[i] = 10;
				break;
			case 'L':
				nums[i] = 50;
				break;
			case 'C':
				nums[i] = 100;
				break;
			case 'D':
				nums[i] = 500;
				break;
			case 'M':
				nums[i] = 1000;
				break;
		}
		i++;
	}
	i = 0;
	while (i < size) {
		if (((i + 1) < size) && (nums[i] < nums[i + 1])) {
			sum = sum - nums[i] + nums[i + 1];
			i += 2;
		} else {
			sum += nums[i];
			i++;
		}
	}
	free(nums);
	return sum;
}
