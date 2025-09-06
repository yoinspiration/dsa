/**
 * Move Zeroes - 暴力解法（逐个移动法）
 * 时间复杂度：O(n²) 空间复杂度：O(1)
 * 保持非零元素的相对顺序
 */

// 暴力解法：逐个移动法
void moveZeroes(int* nums, int numsSize) {
    // 从后往前遍历，找到每个0
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == 0) {
            // 将0后面的所有元素向前移动一位
            for (int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
            // 将最后一个位置设为0
            nums[numsSize - 1] = 0;
        }
    }
}