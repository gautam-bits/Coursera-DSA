#include <iostream>
#include <stack>
#include <string>

class Bracket {
public:
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int ans = -1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket tem(next,position);
            opening_brackets_stack.push(tem);    
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty()){
                ans = position;
                break;
            }
            else if(opening_brackets_stack.top().Matchc(next)){
                opening_brackets_stack.pop();
            }
            else{
                ans = position;
                break;
            }
        }

    }

    // Printing answer, write your code here
    if(!opening_brackets_stack.size() && ans == -1) {
        std::cout<<"Success"<<std::endl;
    }
    else{
        if(ans == -1){
            while(!opening_brackets_stack.empty()){
                ans = opening_brackets_stack.top().position;
                opening_brackets_stack.pop();
            }
        }
        
        std::cout<<ans + 1<<std::endl;
    }

    return 0;
}
