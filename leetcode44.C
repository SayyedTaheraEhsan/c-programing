class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        for( auto e:s)
        {
            if((e=='{'||e=='['||e=='(')){
            stk.push(e);
            }
            else
             {
                if(stk.empty())
                return false;
                if((e=='}'&& stk.top()=='{')|| (e==']'&& stk.top()=='[')||(e==')'&& stk.top()=='('))
                stk.pop();
                else 
                return false;
             }}
             if(stk.size()==0)
              return true;
             return false;
             }
        };