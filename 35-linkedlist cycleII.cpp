/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
      if(!head)return NULL;
        
        int flag=0;
        Node*slow=head;
        Node*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=1;
                break;
            }
        }
     if(flag==1){
       fast=head;
        
        while(slow!=fast){
            slow=slow->next;            
            fast=fast->next;
        }
        return fast;
        
     }else
         return NULL;
}
