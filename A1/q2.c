#include <stdio.h>
#include<math.h>
int main()
{
    int n,count,product=1;
    printf("Enter the number: ");
    scanf("%d",&n);
    if(n==0 | n<0){
    printf("Enter valid number ");
    return 0;
    }
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            count=0;
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0)
                count++;
            }
        if(count==0)
         product*=i;   
        }
    }
    printf("%d",product);
    return 0;
}



