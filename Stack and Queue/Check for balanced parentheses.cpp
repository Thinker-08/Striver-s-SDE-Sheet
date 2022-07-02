bool isValid(string s)
    {
        stack<char> st;
        if(s[0]==')' or s[0]=='}' or s[0]==']')
            return false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' or s[i]=='[' or s[i]=='{')
                st.push(s[i]);
            else
            {
                if(s[i]==')' and !st.empty() and st.top()=='(')
                    st.pop();
                else if(s[i]=='}' and !st.empty() and st.top()=='{')
                    st.pop();
                else if(s[i]==']' and  !st.empty() and st.top()=='[')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }