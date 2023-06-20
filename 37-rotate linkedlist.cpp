/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
      Node*p=head;
        Node*q=head;
       
        int len=0;
        for(Node*t=head;t!=NULL;t=t->next)
            len++;
        if(head!=NULL &&k>len)
            k=k%len;
        
       if(head==NULL || k==0||k==len)return head;
        
        for(Node*t=head;t->next!=NULL;t=t->next)
            q=q->next;
        
        
        

        
        for(int i=1;i<(len-k);i++)
            p=p->next;
        
        Node*ans=p->next;
        
        q->next=head;
        p->next=NULL;
        
        return ans;
        
}
