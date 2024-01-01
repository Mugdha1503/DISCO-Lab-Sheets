#include<stdio.h>
void sum(int M[][100], int n, int m, int k)
{
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            for(int c=a; c<n; c++)
            {
                for(int d=b; d<m; d++)
                {
                    int S=0;
                    for (int p=a; p<=c; p++)
                    {
                        for (int q=b; q<=d; q++)
                        {
                            S = S + M[p][q];
                        }
                    }
                    if(S == k)
                    {
                        printf("\n%d %d\n", (c - a + 1), (d - b + 1));
                        for(int p=a; p<=c; p++)
                        {
                            for(int q=b; q<=d; q++)
                            {
                                printf("%d ",M[p][q]);
                            }
                            printf("\n");
                        }
                        return;    
                    }
                }
            }
        }
    }
    printf("\nNo such submatrix found");
}
void main()
{
    int M[100][100];
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    sum(M, n, m, k);
}


