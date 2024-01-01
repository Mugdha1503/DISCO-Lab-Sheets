#include <stdio.h>

int main()
{
    int num,j;
    scanf("%d",&num);
    int perfect[num];
    for(int j=2;j<=num;j++)
    {
      int sum=0;
        for(int i=1;i<j;i++){
        if(num%i==0)
        sum+=i;
         }
    if(sum==j)
    perfect[j]=1;
    }
    for(int i=0;i<num;i++){
        if (perfect[i]==1)
        printf("%d ",i);
    }
    return 0;
}




