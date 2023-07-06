/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode res;
    res.val = 0;
    res.next = NULL;
    struct ListNode* tmp = &res;
    int add = 0, value = 0;

    while (l1 != NULL|| l2 != NULL || add != 0) {
        value = (l1 ? l1->val: 0) + (l2 ? l2->val : 0) + add;
        add = value / 10;

        tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        (tmp->next)->val = value % 10;
        (tmp->next)->next = NULL;
        tmp = tmp->next;

        l1 = (l1 ? l1->next : l1);
        l2 = (l2 ? l2->next : l2);
    }

    return res.next;
}
