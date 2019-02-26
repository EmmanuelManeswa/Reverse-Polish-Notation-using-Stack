#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define STACK_SIZE 100
#define EXPR_SIZE 200

typedef struct{
    char data[STACK_SIZE];
    int top;
}stack;

void initialize(stack *s){
    s->top = -1;
}

bool is_empty(stack *s){
    return s->top == -1 ? true : false;
}

bool is_full(stack *s){
    return s->top == STACK_SIZE-1 ? true : false;
}

void push(stack *s, char elem){
    if(is_full(s)){
        printf("Overflow: Stack is full!\n\n");
        return;
    }
    s->data[++(s->top)] = elem;
}

char pop(stack *s){
    if(is_empty(s)){
        printf("Underflow: Stack is empty!\n\n");
        return '\0';
    }
    return s->data[s->top--];
}

char top_of_stack(stack *s){
    if(is_empty(s))
        return '\0';
    return s->data[s->top];
}

bool is_operator(char op){
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '$') ? true : false;
}

int priority(char op){
    if(op == '$')  return 3;
    if(op == '*' || op == '/')  return 2;
    if(op == '+' || op == '-')  return 1;
    return 0;
}

void infix_to_postfix(stack *s, char *expr){
    char store[EXPR_SIZE];
    bool loop = true;
    int it = 0;
    while(*expr != '\0'){
        if(isdigit(*expr))
            store[it++] = *expr;
        else if(*expr == '(')
            push(s, *expr);
        else if(is_operator(*expr)){
            while(loop){
                if(is_empty(s)){
                    push(s, *expr);
                    break;
                }
                else if(top_of_stack(s) == '('){
                    push(s, *expr);
                    break;
                }
                else if(priority(*expr) > priority(top_of_stack(s)) && (priority(top_of_stack(s)) != 0)){
                    push(s, *expr);
                    break;
                }
                else
                    store[it++] = pop(s);
            }
        }
        else if(*expr == ')'){
            while(top_of_stack(s) != '(' && !(is_empty(s)))
                store[it++] = pop(s);
            if(top_of_stack(s) == '(')
                pop(s);
            else{
                printf("\nError: Missing '('.\n\n");
                return;
            }
                
        }
        expr++;
    }
    while(!is_empty(s)){
        if(top_of_stack(s) == '('){
            printf("\nError!: Missing ')'.\n\n");
            return;
        }
        store[it++] = pop(s);
    }
    printf("\nPostfix expression: ");    
    store[it] = '\0';
    for(int i = 0; store[i] != '\0';)
        printf("%c", store[i++]);
    printf("\n\n");
}

int main(void){

    stack s;
    initialize(&s);

    int choice;
    bool loop = true;
    char *expr = (char*)malloc(EXPR_SIZE * sizeof(char));

    printf("\n\tSUPPORTED OPERATORS { (), +, -, *, /, $(power) }\n");
    printf("\tSUPPORTED DIGITS [0-9]\n\n");

    while(loop){
        printf("\t1. Enter Infix to convert.\n");
        printf("\t2. Exit\n");
        printf("Choice[1,2]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nInfix expression: ");
                scanf("%s", expr);
                infix_to_postfix(&s, expr);
                break;
            case 2:
                loop = false;
                break;
            default:
                printf("\nInvalid choice.\n\n");
        }
    }
    free(expr);

    return 0;
}