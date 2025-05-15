class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) {
            return atoi(tokens[0].c_str());
        }
            std::stack<int> stack;
    int i = 0;
    int total = 0;
    while (i < tokens.size()) {
        //std::cout << stack << "\n";
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
            stack.push(atoi(tokens[i].c_str()));
        } else {
            //get first and second operands, compute the value, save it and push the value back to stack
            int second_op = stack.top(); stack.pop();
            int first_op = stack.top(); stack.pop();
            int val = 0;
            if (tokens[i] == "+") {
                val = first_op + second_op;
            } else if (tokens[i] == "-") {
                val = first_op - second_op;
            } else if (tokens[i] == "*") {
                val = first_op * second_op;
            } else if (tokens[i] == "/") {
                val = first_op / second_op;
            }
            total = val;
            //push val back to stack
            stack.push(val);
        }
        i++;
    }
    return total;
    }
};