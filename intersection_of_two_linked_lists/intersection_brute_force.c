/**
 * Intersection of Two Linked Lists - 暴力解法（双重循环）
 * 时间复杂度：O(m*n) 空间复杂度：O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *currA = headA;
    
    // 遍历链表A中的每个节点
    while (currA != NULL) {
        struct ListNode *currB = headB;
        
        // 遍历链表B中的每个节点
        while (currB != NULL) {
            // 如果找到相同的节点（地址相同），说明是交点
            if (currA == currB) {
                return currA;
            }
            currB = currB->next;
        }
        currA = currA->next;
    }
    
    // 没有找到交点
    return NULL;
}
