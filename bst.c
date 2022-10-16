#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct binarytree
{
    int value;
    struct binarytree *left;
    struct binarytree *right;
}tree;
tree *createnode(int value){
    tree* result = malloc(sizeof(tree));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

//         printf("Empty \n");
//         return;
//     } 
//     printf("Root: %d", root->value);
//     printf("\n-Left\n");
//     print(root->left, space+1);
//     printf("-Right\n");
//     print(root->right, space+1);
// }
// void printtree(tree *root){
//     print(root, 0);
// }
void print_inorder(tree *root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    printf("%d--", root->value);
    print_inorder(root->right);
}
void print_preoder(tree *root){
    if(root == NULL){
        return;
    }
    printf("%d--", root->value);
    print_inorder(root->left);
    print_inorder(root->right);
}
tree insert_value(tree **rootptr, int val){
    tree *root = *rootptr;
    if(root == NULL){
        (*rootptr) = createnode(val);
        return;
    }
    if(val == root->value){
        return;
    }
    if(val < root->value){
        return insert_value(&(root->left), val); 
    }
    else{
        return insert_value(&(root->right), val);
    }

}
bool is_present(tree *root, int val){
    if(root == NULL){
        return false;
    }
    if(root->value == val){
        return true;
    }
    if(val < root->value){
        return is_present(root->left, val);
    }
    if(val > root->value){
        return is_present(root->right, val);
    }
}
int main(){
tree *root_node = NULL;
int total_elements, element, choice, temp;
do{
    printf("Enter the operations on binary search tree: \n");
        printf("1. Create \n");
        printf("2. Display InOrder \n");
        printf("3. Display PostOrder \n");
        printf("4. Search \n");
        printf("5. Insert element \n");
        printf("6. Exit \n");
        scanf("%d", &choice);
    switch(choice){
    case 1:
    printf("Enter the total elements in the binary search tree: ");
    scanf("%d", &total_elements);
    for(int i=0;i<total_elements; i++){
        printf("Element[%d]: ", i);
        scanf("%d", &element);
        insert_value(&root_node, element);
    }
    break;
    case 2:
    printf("Inorder form: ");
    print_inorder(root_node);
    printf("\n");
    break;
    case 3:
    printf("Preorder form: ");
    print_preoder(root_node);
    printf("\n");
    break;
    case 4:
    printf("Enter node to be searched in binary tree: ");
    scanf("%d", &temp);
    printf("\n %d (%d) \n", temp, is_present(root_node, temp));
    break;
    case 5:
    printf("Enter the node to be inserted: ");
    scanf("%d", &temp);
    insert_value(&root_node, temp);
    }
    if(choice >= 6){
        printf("Program ending");
        system("cls");
        break;
        }
}while(1);
    return 0;
}
