#include <stdio.h>
int maxfunc(int n, int tasks[n],int current){
    int start=0,end=0;
    int maxtasks = 0;
    while(end<n){
        current-=tasks[end];
        end++;
      if(current < 0){
        current += tasks[start];
        start++;
    }
      if(end-start > maxtasks)
        maxtasks = end-start;
    }  
     return maxtasks;
}
void main(){
    int n, tasks[100],current;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
    scanf("%d",tasks+i);
    }
    scanf("%d", &current);
    int maxtasks = maxfunc(n,tasks,current);
    printf("%d",maxtasks);
}


