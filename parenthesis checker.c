#include <stdio.h>
#define EMPTY (-1)
char a[20], stack[20];
int i;
int top = EMPTY;
void push(char);
void pop();

int main(){
    printf("Enter the expression: \n");
    scanf("%s", &a);
    for(i=0;a[i]!='\0';i++) {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[') {
            push(a[i]);
        } else if (a[i] == ')'  || a[i] ==  '}' || a[i] == ']') {
            pop();
            if(top == -2){
                break;
            }
        }
    }
        if(top == -1){
            printf("Valid expression\n");
        }
        else{
            printf("Invalid expression\n");
        }


}
void push(char a){
    top = top + 1;
    stack[top] = a;
}
void pop(){
    top = top - 1;
}
