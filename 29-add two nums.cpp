/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
      int c=0;
      
             Node*ans=l1;
             Node*p=l1;
        while(l1 && l2){
           
            int data=c+l1->data+l2->data;
            c=data/10;
            l1->data=data%10;
            p=l1;
            l1=l1->next;
            l2=l2->next; 
        }
        
        while(l1){
            int data=c+l1->data;
            c=data/10;
            l1->data=data%10;
            p=l1;
            l1=l1->next;           
        } 
        if(l2){
            p->next=l2;
            l1=l2;
        }
         while(l2){
            int data=c+l2->data;
            c=data/10;
            l1->data=data%10;
            p=l1;
            l1=l1->next;
            l2=l2->next;
        } 
              if(c!=0){
            Node*carryNode=new Node(c);
            p->next=carryNode;
            p=carryNode;
        }
         return ans;
     
}
