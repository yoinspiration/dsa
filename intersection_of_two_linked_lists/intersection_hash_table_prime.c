/**
 * Intersection of Two Linked Lists - 质数哈希表解法
 * 时间复杂度：O(m+n) 空间复杂度：O(m)
 * 优化：使用质数作为哈希表大小，减少冲突
 */

// 使用质数作为哈希表大小
#define HASH_SIZE 50021  // 50021 是质数，接近50000

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // 创建哈希表，存储链表A中所有节点的地址
    struct ListNode **hashTable = (struct ListNode**)calloc(HASH_SIZE, sizeof(struct ListNode*));
    
    // 遍历链表A，将所有节点地址存入哈希表
    struct ListNode *currA = headA;
    while (currA != NULL) {
        // 使用节点地址的哈希值作为索引
        unsigned long hash = ((unsigned long)currA) % HASH_SIZE;
        
        // 处理哈希冲突（使用开放地址法）
        while (hashTable[hash] != NULL && hashTable[hash] != currA) {
            hash = (hash + 1) % HASH_SIZE;
        }
        hashTable[hash] = currA;
        
        currA = currA->next;
    }
    
    // 遍历链表B，检查每个节点是否在哈希表中
    struct ListNode *currB = headB;
    while (currB != NULL) {
        unsigned long hash = ((unsigned long)currB) % HASH_SIZE;
        
        // 查找节点
        while (hashTable[hash] != NULL) {
            if (hashTable[hash] == currB) {
                // 找到交点，释放内存并返回
                free(hashTable);
                return currB;
            }
            hash = (hash + 1) % HASH_SIZE;
        }
        
        currB = currB->next;
    }
    
    // 没有找到交点，释放内存
    free(hashTable);
    return NULL;
}
