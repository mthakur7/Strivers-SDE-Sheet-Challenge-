/*
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
*/

Node* removeKthNode(Node* head, int n)
{
    // Write your code here.
     
        Node*f=head;
     Node*s=head;
       Node*p=NULL;
    
        
        for(int i=0;i<n;i++)
            f=f->next;
        
        while(f!=NULL){
            p=s;
            f=f->next;         
            s=s->next;
        }
        if(p)
        p->next=s->next;
        else
            head=s->next;
        
        return head; 
        
      
}
