#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int high = 0, temp = 0, i, temp2 = nums[0];
    for (i = 0; i < numsSize; i++) {
        temp = temp + nums[i];
        if (nums[i] >= temp2)
            temp2 = nums[i];
        if (temp <= 0) {
            temp = 0;
        }
        if (high < temp) {
            high = temp;
        }
    }
    if (high == 0 && numsSize != 0)
        return temp2;

    return high;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubArray(nums, numsSize);
    printf("Maximum subarray sum is: %d\n", result);
    return 0;
}
