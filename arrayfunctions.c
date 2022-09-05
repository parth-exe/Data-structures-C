#include <stdio.h>
#define cap (100)
int array[cap],length,pos,ins;
int arrCreate();
int arrDisplay();
int arrInsert();
int arrDel();
int arrSortAs();
int search(int arr[], int left, int right, int searched);
int main(){
    REENTER:
    printf("\nEnter the length of array: ");
    scanf("%d", &length);
    char op;
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
        printf("(e)Sort array in ascending order \n");
        printf("(f)Search element in array \n");
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
        if(op == 'd'){
            if(pos>= length+1){
                printf("Deletion not possible");
            }
            else{
                printf("Enter the element position for deletion: \n");
                scanf("%d", &pos);
                arrDel();
            }
        }
        if(op == 'e') {
            arrSortAs();
            printf("The array has been sorted in ascending order!\n");
        }
        if(op == 'f'){
            int arr1[100];
            int n = sizeof(arr1)/sizeof(arr1[0]);
            for(int i=0; i<n; i++){
                arr1[i] = array[i];
            }
        int x;
        printf("Enter the element you want to search in array: ");
        scanf("%d", &x);
        int result = search(arr1, 0, n - 1, x);
        if(result == -1){
            printf("Value is not present in the array!\n");
        }
        else{
            printf("Element %d is found in %d\n",x, result+1);
        }
        }

        if(op == 'z'){
            break;
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
int arrDel(){
    for(int i=pos-1;i<=length-1;i++){
        array[i] = array[i+1];
    }
    length--;
    return 0;
}
int arrSortAs(){
    for(int i=0; i<length; i++){
        for(int j=i+1;j<length; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}
int search(int arr[], int left, int right, int searched){
    while (right>=left){
        int mid = left - (right - left) / 2;
        if (arr[mid] == searched) {
            return mid;
        }
        if (arr[mid] > searched) {
            return search(arr, searched, left, mid - 1);
        }
        if (arr[mid] < searched) {
            return search(arr, searched, mid + 1, right);

        }
    }
    return -1;
}
