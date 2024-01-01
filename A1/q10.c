#include <stdio.h>
int gcd(int a, int b){
    if(a==0)
    return b;
    gcd(b%a,a);
}
long long findlcm(int arr[],int n){
    long long ans = arr[0];
    for(int i=1;i<n;i++){
      ans = (ans*arr[i])/(gcd(ans,arr[i]));  
    }
    return ans;
}
int main()
{
    int n,f[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&f[i]);
    }
    printf("%lld",findlcm(f,n));
    return 0;
}



