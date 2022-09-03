#include <stdio.h>
#define cap (100)
int array[cap],length,pos,ins;
int arrCreate();
int arrDisplay();
int arrInsert();
int main(){
    REENTER:
        printf("\nEnter the length of array: ");
        scanf("%d", &length);
    char op;
    char options[] = {'a', 'b', 'c', 'z'};
    do{
        if(length > cap){
            printf("Error! Invalid size of array, Re-enter <= 100");
            goto REENTER;
        }
        printf("Enter function on array: \n");
        printf("(a)Create an array \n");
        printf("(b)Display created array \n");
        printf("(c)Insert element \n");
        printf("(d)Delete element \n");
        printf("(z)Exit Code \n");
        scanf("%s", &op);

        if (op == 'a'){
            arrCreate();
        }

        if (op == 'b'){
            if(array[0] != 0){
                arrDisplay();
            }
            else{
                printf("Array is empty!");
                break;
            }
        }
        if(op == 'c'){
            if(array[0] != 0) {
                printf("Enter the element for insertion: \n");
                scanf("%d", &ins);
                printf("Enter the position to enter the element: \n");
                scanf("%d", &pos);
                arrInsert();
            }
            else{
                printf("Array is empty!");
            }
        }
        if(op == 'z'){
            break;
        }
        if(op != options['a', 'b', 'c', 'z']){
            printf("Invalid options! Renter\n");
        }

    }while(1);
    return 0;
}
int arrCreate(){
    for(int i=0;i<length;i++){
        printf("Element[%d]: ", i+1);
        scanf("%d", &array[i]);
    }
    return 0;
}

int arrDisplay(){
    for(int i=0;i<length;i++){
        printf("Element[%d]: %d \n", i+1, array[i]);
    }
    return 0;
}
int arrInsert(){
    length++;
    for(int i= length-1; i>=pos; i--){
        array[i] = array[i-1];
    }
    array[pos - 1] = ins;
    return 0;
}
