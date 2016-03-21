/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* list1   = l1;
    struct ListNode* list2   = l2;
    struct ListNode* lresult = NULL;
    struct ListNode* newNode = NULL;
    int    val               = 0;
    bool   bNeedNewNode      = 0;
    
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    
    lresult = list1;

    while(list1 && list2)
    {
        val += list1->val + list2->val;
        if (val >= 10)
        {
            list1->val = val - 10;
            val      = 1;
        }
        else
        {
            list1->val = val;
            val = 0;
        }
        //two list next node not null
        if(list1->next && list2->next)//
        {
            list1 = list1->next;
            list2 = list2->next;
            continue;
        }
        
        //twolist next node all null, we need new node
        if(!list1->next && !list2->next)
        {
            bNeedNewNode = true;
            break;
        }
        // list1 is null, list2 is not null    
        if(list2->next)
        {
            list1->next = list2->next;
            break;
        }
    }
    
    
    
    if(val == 1)
    {
        while(list1)
        {
            if (!list1->next)
            {
                bNeedNewNode = true;
                break;
            }
            list1 = list1->next;
            val += list1->val;
            list1->val = val % 10;
            val = val / 10;
            if(val == 0)
                break;
        }
    }
    if (bNeedNewNode)
    {
        newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = 1;
    }
    
    return lresult;
}