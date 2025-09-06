/**
 * Intersection of Two Linked Lists - 双指针解法（最优）
 * 时间复杂度：O(m+n) 空间复杂度：O(1)
 * 
 * 算法思路：
 * 1. 使用两个指针分别遍历两个链表
 * 2. 当一个指针到达链表末尾时，将其指向另一个链表的头部
 * 3. 这样两个指针会在交点相遇，或者同时到达NULL
 * 
 * 原理：设链表A长度为a，链表B长度为b，交点后长度为c
 * 指针A走完A链表后走B链表：a + (b-c)
 * 指针B走完B链表后走A链表：b + (a-c)
 * 两者相等：a + b - c = b + a - c，所以会在交点相遇
 */

// 双指针解法（最优）
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;
    
    // 两个指针同时遍历
    while (ptrA != ptrB) {
        // 如果ptrA到达末尾，将其指向headB
        if (ptrA == NULL) {
            ptrA = headB;
        } else {
            ptrA = ptrA->next;
        }
        
        // 如果ptrB到达末尾，将其指向headA
        if (ptrB == NULL) {
            ptrB = headA;
        } else {
            ptrB = ptrB->next;
        }
    }
    
    // 返回交点（如果ptrA == ptrB == NULL，说明没有交点）
    return ptrA;
}
