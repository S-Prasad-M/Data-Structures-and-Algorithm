#include<stdio.h>
int bin_search( int arr[], int l, int r, int x){
    if (r>=l){
        int mid = l+(r-l)/2;
        if (arr[mid]==x) return mid;
        if (arr[mid]>x) return bin_search(arr,l,mid-1,x);
        return bin_search(arr, mid+1, r, x);
    }
    return -1;
}
void main(){
    int arr[] = {2,3,14,25,34,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = bin_search(arr, 0, n, 34);
    printf("%d", result);
}