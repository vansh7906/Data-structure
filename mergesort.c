// Online C compiler to run C program online
#include <stdio.h>
void merge(int arr[],int l,int mid,int r){
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1],right[n2];
    for(i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[mid+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=right[j];
        k++;
        j++;
    }
}
void mergesort(int arr[],int l, int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main() {
    int arr[]={1,2,9,6,8,25};
    int n=6;
    mergesort(arr,0,5);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
