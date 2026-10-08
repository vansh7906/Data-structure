#include <stdio.h>
int main() {
    int arr[100] ,n;
    printf("enter the sizeof array\n");
    scanf("%d",&n);
    printf("now enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("elements of array are: \n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
