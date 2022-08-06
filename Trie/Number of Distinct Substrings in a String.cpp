#include<bits/stdc++.h>
int countDistinctSubstrings(string &s)
{
    set<string>st;
    for(int i=0;i<s.length();i++)
    {
        string temp;
        for(int j=i;j<s.length();j++)
        {
            temp+=s[j];
            st.insert(temp);
        }
    }
    return st.size()+1;
}