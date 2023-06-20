#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
    // Write your code here.
     Node<int>*third=NULL;
      Node<int>*ans=NULL;
        
        if(!list1)
            return list2;
        else if(!list2)
            return list1;
        
        if(list1->data<list2->data){
            ans=list1;
            list1=list1->next;
        }
        else{
            ans=list2;
            list2=list2->next;
        }
        third=ans;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->data<list2->data){
                third->next=list1;
                third=third->next;
                list1=list1->next;
            }
            else{
               third->next=list2;
                 third=third->next;
                list2=list2->next; 
            }
        }
        
        while(list1!=NULL){
            third->next=list1;
             third=third->next;
                list1=list1->next;
        }
          while(list2!=NULL){
            third->next=list2;
               third=third->next;
                list2=list2->next;
        }
        return ans;
}
