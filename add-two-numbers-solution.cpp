/**
*
* author: zachary lauzon
* date: 2022-07-26
*
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        ListNode* temp;
        ListNode* tempPrevious;
        
        //We need to assign and remember the head to our returned linked list so we process the
        //first sum outside the loop.
        int sum = l1->val + l2->val;
        //Only a single digit is stored in each node so we remember the additional digits and
        //add it to the next sum.
        int carryOver = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode* head = new ListNode(sum % 10);
        temp = head;
        tempPrevious = temp;
        
        //Check for carryOver because nodes may add up to a multi digit number that would create new nodes within
        //the return beyond the lengths of the passed linked lists.
        while(l1 || l2 || carryOver){
            int lhs = 0;
            int rhs = 0;
            
            if (l1) {
                lhs = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                rhs = l2->val;
                l2 = l2->next;
            }
                
            sum = (lhs + rhs) + carryOver;
            carryOver = sum / 10;
            temp = new ListNode(sum % 10);
            if (temp != tempPrevious)
                tempPrevious->next = temp; //Ensure the previous node is pointed to the current node
            tempPrevious = tempPrevious->next;
                
        }
        return head;
    }
};
