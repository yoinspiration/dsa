/**
 * Move Zeroes - 最优解法（覆盖法）
 * 时间复杂度：O(n) 空间复杂度：O(1)
 * 操作次数最少，符合LeetCode的follow-up要求
 */

// 最优解法：覆盖法（一次遍历）
void moveZeroes(int* nums, int numsSize) {
    int write = 0;  // write指针指向下一个非零元素应该写入的位置
    
    // 一次遍历：将所有非零元素移动到数组前面
    for (int read = 0; read < numsSize; read++) {
        if (nums[read] != 0) {
            // 只有当read != write时才需要复制，避免不必要的操作
            if (read != write) {
                nums[write] = nums[read];
            }
            write++;
        }
    }
    
    // 将剩余位置设为0
    for (int i = write; i < numsSize; i++) {
        nums[i] = 0;
    }
}