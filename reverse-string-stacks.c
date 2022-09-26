#include <stdio.h>
#include <stdbool.h>
#define EMPTY (-1)
#define STACK_LENGTH 5
#define STACK_EMPTY -214645

char stack[STACK_LENGTH];
int top = EMPTY;

int push(char str){
    if(top >= STACK_LENGTH-1) return false;
    top++;
    stack[top] = str;
}
char pop(){
    char result = stack[top];
    top--;
    return result;
}
void reverseStr(char str[]){
    for (int i = 0; i < STACK_LENGTH; i++)
        push(str[i]);
    for (int i = 0; i < STACK_LENGTH; i++)
        str[i] = pop();
}
int main () {
    char str[] = "Hello";
    reverseStr(str);
    printf("Reversed string: %s", str);
    return 0;
}
