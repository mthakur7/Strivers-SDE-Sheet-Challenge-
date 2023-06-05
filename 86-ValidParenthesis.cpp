bool isValidParenthesis(string expression)
{
    // Write your code here.
       stack<char>st;
    for(int i=0;i<expression.size();i++){
        if(expression[i]=='[' ||expression[i]=='{'||expression[i]=='(')
        st.push(expression[i]);
        else if(!st.empty() && ((expression[i]==')'&& st.top() == '(') ||(expression[i] == '}' && st.top() == '{') || (expression[i] == ']' && st.top() == '[')))             
         st.pop();
         else
          return 0;         
        
    }
    if(st.empty())
    return 1;
    else
    return 0;
}
