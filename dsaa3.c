#include <stdio.h>
#include <stdlib.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}


void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
       
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        // Swap pivot with successor
        swap(&nums[i], &nums[j]);
    }

    
    reverse(nums, i + 1, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    nextPermutation(nums, numsSize);

    printf("Next permutation: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
