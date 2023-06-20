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

Node* findIntersection(Node *first, Node *second)
{
    
 int lenA=0,lenB=0;
for(Node*t=first;t!=NULL;t=t->next)
lenA++;

for(Node*t=second;t!=NULL;t=t->next)
lenB++;

while(lenA>lenB){
    first=first->next;
    lenA--;
}
while(lenB>lenA){
    second=second->next;
    lenB--;
}
while(first){
    if(first==second)
    return first;

    first=first->next;
    second=second->next;
}
return NULL;
}
