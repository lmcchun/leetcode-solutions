/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	if (numsSize <= 0) {
		return NULL;
	}

	int center = numsSize / 2;
	int centerPlusOne = center + 1;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = nums[center];
	root->left = sortedArrayToBST(nums, center);
	root->right = sortedArrayToBST(&nums[centerPlusOne], numsSize - centerPlusOne);

	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	if (numsSize <= 0) {
		return NULL;
	}

	int index = 0;
	int** pp = (int**)malloc(sizeof(int*) * numsSize);
	int* lengthArray = (int*)malloc(sizeof(int) * numsSize);
	struct TreeNode** nodePointerArray = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * numsSize);
	pp[index] = nums;
	lengthArray[index] = numsSize;
	nodePointerArray[index] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	++index;

	int counter = 0;
	while (counter < numsSize) {
		int* p = pp[counter];
		int length = lengthArray[counter];
		struct TreeNode* pNode = nodePointerArray[counter];
		int center = length / 2;
		pNode->val = p[center];
		pNode->left = NULL;
		pNode->right = NULL;
		++counter;

		if (center > 0) {
			pp[index] = p;
			lengthArray[index] = center;
			pNode->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
			nodePointerArray[index] = pNode->left;
			++index;
		}

		int centerPlusOne = center + 1;
		if (length > centerPlusOne) {
			pp[index] = &(p[centerPlusOne]);
			lengthArray[index] = length - centerPlusOne;
			pNode->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
			nodePointerArray[index] = pNode->right;
			++index;
		}
	}

	struct TreeNode* result = nodePointerArray[0];

	free(pp);
	free(lengthArray);
	free(nodePointerArray);

	return result;
}
