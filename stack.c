#include <stdio.h>
#include <stdbool.h>
#define EMPTY (-1)
#define STACK_LENGTH 5
#define STACK_EMPTY -214645

int stack[STACK_LENGTH];
int top = EMPTY;
int number;

bool push(int value){
    if(top >= STACK_LENGTH-1) return false;
    top++;
    stack[top] = value;
}
int pop(){
    if(top == EMPTY) return STACK_EMPTY;
    int result = stack[top];
    top--;
    return result;
}
int main () {
    for(int i=0;i <= STACK_LENGTH; i++ ){
        printf("Enter the number into stack: \n");
        scanf("%d", &number);
        push(number);
    }

    int t;
    while ((t = pop()) != STACK_EMPTY)
        printf("t = %d\n",t);

}
