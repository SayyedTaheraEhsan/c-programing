class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string& token:tokens){
            // see what we need to do is, if it is operand, we will push in the stack
            // otherwise, if it is a operand, we need to pop two operands from the stack and then we need to perform
            // that operator operation on them and then push that result into the stack

            if(token=="+" || token=="*" || token=="/" || token=="-"){
                int operand2= stk.top();
                stk.pop();
                int operand1= stk.top();
                stk.pop();
                int result=0;

                if(token=="+"){
                    result = operand2+operand1;
                }else if(token=="-"){
                    result = operand1-operand2;
                }else if(token=="/"){
                    result = operand1/operand2;
                }else{
                    result = operand2*operand1;
                }
                stk.push(result);
            }else{
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};