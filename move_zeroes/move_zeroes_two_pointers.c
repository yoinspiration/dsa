/**
 * Move Zeroes - 优化解法（快慢指针法）
 * 时间复杂度：O(n) 空间复杂度：O(1)
 */

// 优化解法：快慢指针法
void moveZeroes(int* nums, int numsSize) {
    int slow = 0;  // slow指针指向下一个非零元素应该放置的位置
    
    // 第一次遍历：将所有非零元素移动到数组前面
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    
    // 第二次遍历：将剩余位置设为0
    for (int i = slow; i < numsSize; i++) {
        nums[i] = 0;
    }
}