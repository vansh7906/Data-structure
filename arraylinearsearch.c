#include<stdio.h>
void main(){
    int n;
    printf("enter size of arrr\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int key;
    printf("enter key");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("found\n");
            return;

        }
    }
    printf("not found\n");


}
