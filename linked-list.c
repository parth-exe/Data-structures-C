#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int var;
    struct node* next;
}nodez;

nodez *createNode(int var){
    nodez *result = malloc(sizeof(nodez));
    result->var = var;
    result->next = NULL;
    return result;
}
void print_ll(nodez *head){
    nodez *temperory = head;
    while(temperory != NULL){
        printf("%d--", temperory->var);
      temperory =  temperory->next;
    }
    printf("\n");
}

int main(){
    int x;
    int tail;
    int length;
    printf("Enter length of LL: ");
    scanf("%d", &length);
    nodez *head;
    nodez *temp;
    printf("Enter the tail of the linked list: ");
    scanf("%d", &tail);
    temp = createNode(tail);
    head = temp;
    for(int i=0; i<length-1;i++){
        printf("Enter other elements [%d]: \n", i+1);
        scanf("%d", &x);
        temp = createNode(x);
        temp->next = head;
        head = temp;
    }
    print_ll(head);
    return 0;
}
