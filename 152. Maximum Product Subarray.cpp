#include <stdio.h>

int maxProduct(int* nums, int numsSize) {
    int high = nums[0], temp = 1, i, temp2 = 1;
    int high2 = high;
    for (i = 0; i < numsSize; i++) {
        temp = temp * nums[i];
        temp2 = temp2 * nums[i];

        if (high2 <= temp2) {
            high2 = temp2;
        }
        if (temp2 == 0)
            temp2 = 1;

        if (temp >= high) {
            high = temp;
        }
        if (temp <= 0) {
            temp = 1;
        }
    }
    int t, t2;
    if (high > high2)
        t = high;
    else
        t = high2;

    high = nums[numsSize - 1];
    temp = 1;
    temp2 = 1;
    high2 = high;
    for (i = numsSize - 1; i >= 0; i--) {
        temp = temp * nums[i];
        temp2 = temp2 * nums[i];

        if (high2 <= temp2) {
            high2 = temp2;
        }
        if (temp2 == 0)
            temp2 = 1;

        if (temp >= high) {
            high = temp;
        }
        if (temp <= 0) {
            temp = 1;
        }
    }
    if (high > high2)
        t2 = high;
    else
        t2 = high2;

    if (t > t2)
        return t;
    return t2;
}

int main() {
    int nums[] = {2, 3, -2, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = maxProduct(nums, numsSize);
    printf("Maximum Product Subarray: %d\n", result);
    return 0;
}
