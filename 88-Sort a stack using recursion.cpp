#include <bits/stdc++.h>
void insert(stack<int> &stack, int x) {
  if (stack.empty() || stack.top() < x){
    stack.push(x);
    return;
}
int y=stack.top();
stack.pop();
insert(stack,x);
stack.push(y);
return;
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.size()==0 || stack.size()==1)return;
	int x=stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,x);
	return;
}
