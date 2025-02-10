class Solution {
public:
    bool isValid(string s) 
    {
        int n=s.length();
        if(s[0]=='b' || s[0]=='c' || s[n-1]!='c')
            return false;
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                st.push(s[i]);
            }
            else if(s[i]=='b' && st.empty())
                return false;
            else if(s[i]=='b' && !st.empty())
            {
                if(st.top()=='a')
                {
                    st.pop();
                    st.push(s[i]);
                }
                else
                    return false;
            }
            else if(s[i]=='c' && st.empty() )
                return false;
            else if(s[i]=='c' && !st.empty())
            {
                if(st.top()=='a')
                    return false;
                else if(st.top()=='b')
                {
                    st.pop();
                }
                else
                    return false;
            }

        }
            if(st.empty())
                return true;
            else
                return false;
    }
};