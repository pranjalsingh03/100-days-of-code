#include<stdio.h>
#include<stdlib.h>

 int main(){
    int i ,n;
    int*p;
    printf("enter no of elements=");
    scanf("%d",&n);
    p=(int*)calloc(n,sizeof(int));
    if(p==NULL){
        printf("not enough memory");
        exit(0);
    }
    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    for(i=0;i<n;i++){
        printf("%d  %u\n",*(p+i),(p+i));
    }
    free(p);
 }