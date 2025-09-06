/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 哈希表条目结构体
typedef struct {
    int value;    // 存储数组元素的值
    int index;    // 存储原始索引
    int used;     // 标记该位置是否被使用
} HashEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 分配返回数组的内存
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // 使用简单的哈希表实现
    // 由于数组长度最大为10^4，我们可以使用一个较小的哈希表
    // 使用开放地址法处理冲突
    #define HASH_SIZE 10007  // 选择一个质数作为哈希表大小
    
    HashEntry* hashTable = (HashEntry*)calloc(HASH_SIZE, sizeof(HashEntry));
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // 计算补数的哈希值
        int hash = (complement % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        
        // 查找补数
        while (hashTable[hash].used) {
            if (hashTable[hash].value == complement) {
                result[0] = hashTable[hash].index;
                result[1] = i;
                free(hashTable);
                return result;
            }
            hash = (hash + 1) % HASH_SIZE; // 线性探测
        }
        
        // 将当前元素插入哈希表
        int currentHash = (nums[i] % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        while (hashTable[currentHash].used) {
            currentHash = (currentHash + 1) % HASH_SIZE; // 线性探测
        }
        hashTable[currentHash].value = nums[i];
        hashTable[currentHash].index = i;
        hashTable[currentHash].used = 1;
    }
    
    free(hashTable);
    // 理论上不会到达这里，因为题目保证有解
    return result;
}
