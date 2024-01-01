#include <stdio.h>
void sort(int arr[], int n){
    int a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
               a=arr[i];
               arr[i]=arr[j];
               arr[j]=a;
            }
        }
    }
}
int mode(int arr[],int n){
    int maxVal=0,maxCount=0,count;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i])
            ++count;
        }
        if(count>maxCount){
            maxCount=count;
            maxVal=arr[i];
        }
    }
    return maxVal;
}
int main()
{
    int n,arr[100],median;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    median = (n-1)/2;
    printf("%d %d",arr[median],mode(arr,n));
    /*for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }*/
    return 0;
}


