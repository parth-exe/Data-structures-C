#include <stdio.h>
#include <stdlib.h>
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
void print(tree *root, int space){
    if(root == NULL){
        printf("Empty \n");
        return;
    } 
    printf("Root: %d", root->value);
    printf("\n-Left\n");
    print(root->left, space+1);
    printf("-Right\n");
    print(root->right, space+1);
}
void printtree(tree *root){
    print(root, 0);
}
tree *insert(tree *inserted, int value){
    if(inserted == NULL){
        createnode(value);
        return;
    }
    if(value < inserted->value){
        inserted->left = insert(inserted->left, value);
    }
    if(value > inserted->value){
        inserted->right = insert(inserted->right, value);
    }
    return inserted;
}
int main(){
tree *root_node = NULL;
root_node = createnode(3);
tree *n1 = createnode(4);
tree *n2 = createnode(66);
tree *n3 = createnode(32);
tree *n4 = createnode(11);
root_node->left = n1;
root_node->right = n2;
n2->left = n3;
n2->right = n4;
printtree(root_node);
insert(n3, 99);
printtree(root_node);
    return 0;
}
