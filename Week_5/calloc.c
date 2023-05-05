#include<stdio.h>
#include<stdlib.h>

 int main(){
    int i ,n,*ptr,sum=0;
    printf("enter size of array=");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL){
        printf("error");
    }
    else{
        printf("enter the elements in array");
    for(i=0;i<n;i++){
        scanf("%d",(ptr+i));
        sum=sum+*(ptr+i);
    }
    printf("array elements are\n");
    }
    for(i=0;i<n;i++){
        printf("%d\n",*(ptr+i));
    }
    printf("addition is%d",sum);
 }