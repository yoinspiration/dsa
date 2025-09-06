/**
 * Intersection of Two Linked Lists - 双指针解法（最优）
 * 时间复杂度：O(m+n) 空间复杂度：O(1)
 * 
 * 这是LeetCode上最推荐的解法，简洁高效
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;
    
    // 两个指针同时遍历
    while (ptrA != ptrB) {
        // 如果ptrA到达末尾，将其指向headB
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        // 如果ptrB到达末尾，将其指向headA
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }
    
    // 返回交点（如果ptrA == ptrB == NULL，说明没有交点）
    return ptrA;
}
