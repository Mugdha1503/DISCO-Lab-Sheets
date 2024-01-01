#include <stdio.h>
void main()
{
    int n,x,y;
    printf("Enter the number of scheduled meetings: ");
    scanf("%d",&n);
    int start[100],stop[100];
    for(int i=0;i<n;i++){
        scanf("%d %d",&start[i],&stop[i]);
        if(start[i]>24 || stop[i]>24){
            printf("Please enter valid start and stop time");
            return;
        }
    }
    printf("Enter new meeting start and stop time: ");
    scanf("%d %d",&x,&y);
    if(x>24 || y>24){
        printf("Please enter valid start and stop time");
        return;
    }
    for(int i=0;i<n;i++){
        if((x<start[i]&&y>start[i])||(x>=start[i]&&x<stop[i])){
        printf("NO");
        return;}
    }
    printf("YES");
}





