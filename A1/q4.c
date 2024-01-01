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
//Function to make difference set
int ifexists(int z[], int u, int v){
    int i;
    if (u==0) return 0;
    for(i=0;i<u;i++){
        if(z[i]==v)
        return (1);
        return (0);
    }
}
// Function to print an array 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
void main(){
   int a, b, A[100],B[100];
   int U[100],I[100],D[100];
   scanf("%d",&a);
   for(int i=0;i<a;i++){
       scanf("%d",&A[i]);
   }
    scanf("%d",&b);
   for(int i=0;i<b;i++){
       scanf("%d",&B[i]);
   }
  for(int i=0;i<a;i++){
       U[i]=A[i];
   }
      int s=a;
      int i=0,j=0;
     // while(i<=a || j<=b)
     while(i<b)  //j<a &&
     {
          if (B[i]>U[j])
          j++;
          else if(B[i]==U[j])
          i++;
          else
          U[s++]=B[i++];
      }
  sort(U,s);
  printf("%d\n",s);
  printArray(U,s);
  int k=0;
  for(int i=0;i<a;i++){
       for(int j=0;j<b;j++){
           if(A[i]==B[j])
           I[k++]=B[j];
       }
   }
   if(k==0)
   printf("no intersection\n");
   sort(I,k);
   printArray(I,k);
   //difference of two arrays
   int x,y, l=0;
   for(x=0;x<a;x++){
       for(y=0;y<k;y++){
           if(A[x]==I[k])
           break;
       }
       if(y==k){
           if(!ifexists(D,l,A[x])){
               D[l]=A[x];
               l++;
           }
       }
       }
       sort(D,l);
    printArray(D,l);
   }

  







