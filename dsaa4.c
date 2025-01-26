int maxSubArray(int* nums, int numsSize) {

    int currentSum = 0; 
    int maxSum = INT_MIN; 

   
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];

       
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum; 
}