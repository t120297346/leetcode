#define TRANSFORMATION_NUM 20000

int hash(int num) {
    int index = num % TRANSFORMATION_NUM;
    return index < 0 ? index + TRANSFORMATION_NUM : index;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* hashmap = (int*)malloc(TRANSFORMATION_NUM * sizeof(int));
    memset(hashmap, -1, TRANSFORMATION_NUM * sizeof(int));
    
    int* result = (int*)malloc(2 * sizeof(int));
    memset(result, 0, 2 * sizeof(int));

    int index;

    for (int i = 0; i < numsSize; i++) {
        index = hash(target - nums[i]);

        if (hashmap[index] != -1) {
            result[0] = hashmap[index];
            result[1] = i;
            *returnSize = 2;
            return result;
        }

        hashmap[hash(nums[i])] = i;
    }

    return result;
}
