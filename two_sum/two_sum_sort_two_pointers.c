/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 定义值和索引的结构体
typedef struct {
    int value;
    int originalIndex;
} ValueIndex;

// 比较函数，用于 qsort
int compare(const void* a, const void* b) {
    ValueIndex* va = (ValueIndex*)a;
    ValueIndex* vb = (ValueIndex*)b;
    return va->value - vb->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 分配返回数组的内存
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // 创建值和索引的配对数组
    ValueIndex* pairs = (ValueIndex*)malloc(numsSize * sizeof(ValueIndex));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].value = nums[i];
        pairs[i].originalIndex = i;
    }
    
    // 按值排序
    qsort(pairs, numsSize, sizeof(ValueIndex), compare);
    
    // 使用双指针查找
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = pairs[left].value + pairs[right].value;
        if (sum == target) {
            // 找到答案，返回原始索引
            result[0] = pairs[left].originalIndex;
            result[1] = pairs[right].originalIndex;
            free(pairs);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // 清理内存
    free(pairs);
    
    // 理论上不会到达这里
    return result;
}