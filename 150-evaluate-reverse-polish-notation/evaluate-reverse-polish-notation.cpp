class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;

        for(string token : tokens){
            if(token != "+" && token != "-" &&
                token != "*" && token != "/"){
                s.push(stoi(token));
            }else{
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                if(token == "+"){
                    s.push(a+b);
                }else if(token == "-"){
                    s.push(a-b);
                }else if(token == "*"){
                    s.push(a*b);
                }else if(token == "/"){
                    s.push(a/b);
                }
            }
        }
        return s.top();
    }
};