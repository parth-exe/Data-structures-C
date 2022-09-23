#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int var;
    struct node* next;
    struct node* prev;
}nodez;

nodez *createNode(int var){
    nodez *result = malloc(sizeof(nodez));
    result->var = var;
    result->next = NULL;
    result->prev = NULL;
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
    if(new->next != NULL){
        new->next->prev = inserted;
    }
    new->prev = inserted;
    inserted->next = new;
}
void delete(nodez **temphead, int x){
    nodez *temp = *temphead, *prev;
    if(temp != NULL && temp->var == x){
        *temphead = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->var != x){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}
nodez *search(nodez *head, int var){
    nodez *temp = head;
    while(temp != NULL){
        if(temp->var == var){
            printf("The node is present in the LL! \n");
            return temp;
        }
        temp = temp->next;
    }
    printf("Node not present in LL!\n");
    return NULL;
}

int main(){
    int x, length, tail, choice, tmp;
    nodez *head, *temp;
    do{
        printf("Enter the operations on linked list: \n");
        printf("1. Create \n");
        printf("2. Display \n");
        printf("3. Insert \n");
        printf("4. Delete \n");
        printf("5. Search \n");
        printf("0. To exit code \n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the length of linked list: \n");
                scanf("%d", &length);
                printf("Enter the tail element: \n");
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
                break;
            case 2:
                print_ll(head);
                break;
            case 3:
                printf("Enter the element for insertion: \n");
                scanf("%d", &tmp);
                insertion(temp->next, createNode(tmp));
                print_ll(head);
                break;
            case 4:
                printf("Enter element for deletion: \n");
                scanf("%d", &tmp);
                delete(&head, tmp);
                print_ll(head);
                break;
            case 5:
                printf("Enter the node to be searched: \n");
                scanf("%d", &tmp);
                temp = search(head, tmp);
                print_ll(head);
            default:
                printf("Enter choice again! \n");
                break;

        }
        if(choice == 0){
            break;
        }
    }while(1);

    return 0;
}
