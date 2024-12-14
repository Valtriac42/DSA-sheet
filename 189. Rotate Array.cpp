#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    int temp[1000000], i;

    // Adjust k if it's greater than numsSize
    if (k > numsSize)
        k = k % numsSize;

    // Store the last k elements in temp
    for (i = 0; i < k; i++) {
        temp[i] = nums[numsSize - k + i];
    }
    
    // Store the first (numsSize - k) elements in temp
    for (; i < numsSize; i++) {
        temp[i] = nums[i - k];
    }

    // Copy the rotated result back into nums
    for (i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;  // Number of positions to rotate

    // Print original array
    printf("Original array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Rotate the array
    rotate(nums, numsSize, k);

    // Print rotated array
    printf("Rotated array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
