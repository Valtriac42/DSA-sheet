#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = numsSize - 1, k = numsSize - 1;
    *returnSize = numsSize;
    int* temp = (int*)malloc(numsSize * sizeof(int));

    for (; k >= 0; k--) {
        if (nums[i] * nums[i] >= nums[j] * nums[j]) {
            temp[k] = nums[i] * nums[i];
            i++;
        } else {
            temp[k] = nums[j] * nums[j];
            j--;
        }
    }
    return temp;
}

int main() {
    int nums[] = {-4, 10};
    int numsSize = 2;
    int returnSize;
    int* result = sortedSquares(nums, numsSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
