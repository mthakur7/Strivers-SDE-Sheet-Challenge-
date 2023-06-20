#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
   LinkedListNode<int>* reverse(LinkedListNode<int>*p){
    LinkedListNode<int>*q=NULL;
        LinkedListNode<int>*r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    
    }

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
      if(head==NULL||head->next==NULL) return true;        
       
        LinkedListNode<int>*slow=head;
        LinkedListNode<int>*fast=head;
        
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
       
         LinkedListNode<int>*temp=head;
        
        
         while(slow){
               if(temp->data!=slow->data)
                    return false;
             temp=temp->next;
             slow=slow->next;
              
         }
        return true;

}
