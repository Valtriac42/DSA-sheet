#include <stdio.h>
#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int store[100000], repetation[100000] = {0}, i = 0, r = 0, m = 0, sti = 0, j = 0, flag = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < sti; j++) {
            if (nums[i] == store[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            repetation[j] = repetation[j] + 1;
            if (m < repetation[j]) {
                m = repetation[j];
                r = store[j];
            }
            flag = 0;
            continue;
        }
        store[sti] = nums[i];
        repetation[sti] = repetation[sti] + 1;
        if (m < repetation[sti]) {
            m = repetation[sti];
            r = store[sti];
        }
        sti++;
    }
    int* temp1 = (int*)malloc(10000 * sizeof(int));
    int count = 0;
    float h = numsSize;
    h = h / 3;
    for (i = 0; i < sti; i++) {
        if (repetation[i] > h) {
            temp1[count] = store[i];
            count++;
        }
    }
    *returnSize = count;
    return temp1;
}

int main() {
    int nums[] = {3, 2, 3, 1, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = majorityElement(nums, numsSize, &returnSize);
    printf("Majority elements: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
