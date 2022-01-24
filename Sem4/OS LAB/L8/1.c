// Implementation of Deadlock Avoidance using Bankers Algorithm
// Important :
// Each process should beforehand declare the number of resources of each type that it may need. (Max matrix)

#include <stdlib.h>
#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the number of proceesses(m): ");
    scanf("%d", &m);
    printf("Enter the number of resources(n): ");
    scanf("%d", &n); 

    //Develop the Matrices and Vectors
    int allocation[m][n], max[m][n], need[m][n], available[m];
    printf("Enter the Max matrix :");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation matrix :");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Enter the available vector");
    for(int i=0;i<m;i++)
        scanf("%d", &available[i]);
    
    // Apply Safety Algorithm    
    int work[m], finish[m], safestate[m];
    memcpy(work, available, m);
    int i=0, ind = 0;
    while(1){
        int inside = 0;
        int success = 1;
        for(int j=0;j<n;j++){
            if(need[i][j]>available[j]){
                success = 0;
                break;
            }
        }

        if(success){
            inside = 1;
            safestate[ind++] = i;
            for(int k = 0;k<m; k++)
                available[k] += allocation[i][k];
            finish[i]=1;
        }
        i++;
    }
    return 0;
}