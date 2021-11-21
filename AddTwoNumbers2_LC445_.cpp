// LeetCode-445 Solutions
// @author: Akif Aydogmus

// -------------------------------------------------------------
// Solution-1, using 2 stacks 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        // push values into stacks 
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0, first, second;
        ListNode* head = NULL;
        bool s1cond = !s1.empty();
        bool s2cond = !s2.empty();
        
        while ( s1cond || s2cond || carry) {
            if (s1cond) {
                first = s1.top();
                s1.pop();
            }
            else
                first = 0;
            
            if (s2cond) {
                second = s2.top();
                s2.pop();
            }
            else
                second = 0;
            
            int summ = first+second+carry; 
            
            ListNode* newNode = new ListNode(summ%10); // get value
           
            newNode->next = head;
            head = newNode; 
            
            s1cond = !s1.empty(); // stack-1 condition 
            s2cond = !s2.empty(); // stack-2 condition 
            carry = summ/10; //update the carry 
        }
        return head;
    }
}; 


// -------------------------------------------------------------
// Solution 2: reverse 2 list then apply addtwo and reverse 1 list 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur=head;
        ListNode *nxt;
 
        while(cur!=NULL){
            nxt=cur->next;
            cur->next = pre;
            
            // move the pre and curr one forward 
            pre = cur; 
            cur = nxt; 
        }
        
        return pre; 
    }
    
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        int c = 0;
        // dummy head to simplify, at the end we'll return its next
        ListNode newHead(0);  

        ListNode *current = &newHead; 

        while(c || l1 || l2) { // continue if one of them has value
            // summation with checking the nodes
            c += (l1? l1->val : 0) + (l2? l2->val : 0);

            current->next = new ListNode(c%10); 
            current = current->next; 

            c /= 10; // update the carry 

            // Advance both p and q if not null 
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
            return newHead.next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// firstly reverse the input lists 
        l1 =  reverseList(l1); 
        l2 =  reverseList(l2);
        
		// apply summation then reverse the list 
        return reverseList(addTwoNumbers1(l1,l2)); 
    }
}; 
