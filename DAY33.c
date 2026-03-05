#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    if(op=='+' || op=='-')
        return 1;
    if(op=='*' || op=='/')
        return 2;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int i=0, k=0;

    scanf("%s", infix);

    while(infix[i] != '\0'){
        
        if(isalnum(infix[i])){          // operand
            postfix[k++] = infix[i];
        }

        else if(infix[i] == '('){
            push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(peek() != '(')
                postfix[k++] = pop();
            pop();
        }

        else{                           // operator
            while(top!=-1 && precedence(peek()) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }

        i++;
    }

    while(top!=-1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}
