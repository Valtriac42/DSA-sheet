#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
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
    return r;
}

int main() {
    int nums[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("Majority Element: %d\n", result);
    return 0;
}
