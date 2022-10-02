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
void tabs(int tabbing){
    for(int i=0;i<tabbing; i++){
        printf("\t");
    }
}
void print(tree *root, int space){
    if(root == NULL){
        tabs(space);
        printf("Empty \n");
        return;
    } 
    tabs(space);
    printf("Root: %d", root->value);
    printf("-Left\n");
    tabs(space);
    print(root->left, space+1);
    printf("-Right\n");
    tabs(space);
    print(root->right, space+1);
}
void printtree(tree *root){
    print(root, 0);
}

int main(){
    tree *n1 = createnode(52);
    tree *n2 = createnode(32);
    tree *n3 = createnode(55);
    tree *n4 = createnode(133);
    tree *n5 = createnode(1);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printtree(n1);

    return 0;
}
