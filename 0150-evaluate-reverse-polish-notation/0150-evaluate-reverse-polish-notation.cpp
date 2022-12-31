class Solution {
public:
    /*
        Reverse Polish Notation was was designed specifically to make 
        computing easier with the more efficient use of a stack, so we 
        can use stack to store numbers until they're used and then each 
        operand will use the the top two values of the stack
        
        So, our approach could be
        - If the current token is a operand (number), push it into the stack
        - If the token is a operator, pop the top two operands from the stack. 
        - Find the result of the operation using the operator and two operands 
          and push the result back into stack
        - Finally, the stack will contain the result of evaluated reverse polish expression.
    */
    int evalRPN(vector<string>& tokens) {
        stack<int> reversePolishNotation;
        
        for(auto &element: tokens) {
            
            if(element == "+" || element == "-" || element == "/" || element == "*") {
                
                // since it's a stack so first element popping out will be second
                // element of token
                
                int secondElement = reversePolishNotation.top();
                reversePolishNotation.pop();
                int firstElement = reversePolishNotation.top();
                reversePolishNotation.pop();
            
                if(element == "+"){
                    reversePolishNotation.push(firstElement + secondElement);
                }
                if(element == "-"){
                    reversePolishNotation.push(firstElement - secondElement);
                }
                if(element == "*"){
                    reversePolishNotation.push(firstElement * secondElement);
                }
                if(element == "/"){
                    reversePolishNotation.push(firstElement / secondElement);
                }
            }
            else {
                reversePolishNotation.push(stoi(element));
            }
        }
        return reversePolishNotation.top();
    }
};