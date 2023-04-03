#include<stdio.h>

int main(){
    int a,i;
    printf("enter the number of array\n");
    scanf("%d",&a);
    int arr[a];
    printf("enter the elements of array\n");
    for(i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("the elements of array are\n");
    for(i=0;i<a;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}