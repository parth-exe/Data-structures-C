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
void insertion(nodez *inserted, nodez* new){
    new->next = inserted->next;
    inserted->next = new;

}
nodez *search(nodez *head, int var){
    nodez *temp = head;
    while(temp != NULL){
        if(temp->var == var) return temp;
        temp = temp->next;
    }
    return NULL;
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
    insertion(temp->next, createNode(14));
    print_ll(head);
    printf("%d \n", head->next->next->var);
    printf("%d \n", head->var);
    temp = search(head, 13);
    printf("Found node %d \n", temp->var);
    return 0;
}
