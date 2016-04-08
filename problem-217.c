struct num_struct {
	int num;
	UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
	struct num_struct* num_struct_array = NULL;
	struct num_struct* num_struct_pointer;
	struct num_struct* temp = NULL;
	int i;
	for (i = 0; i < numsSize; i++) {
		num_struct_pointer = NULL;
		HASH_FIND_INT(num_struct_array, &(nums[i]), num_struct_pointer);
		if (num_struct_pointer != NULL) {
			num_struct_pointer = NULL;
			HASH_ITER(hh, num_struct_array, num_struct_pointer, temp) {
				HASH_DEL(num_struct_array, num_struct_pointer);
				free(num_struct_pointer);
			}
			return true;
		}
		num_struct_pointer = (struct num_struct*)malloc(sizeof(struct num_struct));
		num_struct_pointer->num = nums[i];
		HASH_ADD_INT(num_struct_array, num, num_struct_pointer);
	}
	num_struct_pointer = NULL;
	HASH_ITER(hh, num_struct_array, num_struct_pointer, temp) {
		HASH_DEL(num_struct_array, num_struct_pointer);
		free(num_struct_pointer);
	}
	return false;
}
