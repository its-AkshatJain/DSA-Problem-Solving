#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are :");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}

//Single Missing value for sorted array
int singleMissingValue(struct Array arr){
    int i, sum = 0,nSum=0;
    for(i=0;i<arr.length;i++){
        sum = sum + arr.A[i];
    }
    // printf("%d\n",sum);
    nSum= (arr.length+1)*((arr.length+1)+1)/2;   //n*(n+1)/2
    // printf("%d\n",nSum);
    if(nSum>sum){
        return (nSum-sum);
    }
    else{
        return 0;
    }
}

int singleMissingValue2(struct Array arr,int n){
    int i, l= arr.A[0];
    int diff = l-0;
    for(i=0;i<n;i++){
        if(arr.A[i]-i != diff){
            return i+diff;
        }
    }
    return 0;
}

// Multiple missing value
int multipleMissingValue(struct Array arr,int n){
    int i, l= arr.A[0];
    int diff = l-0;
    for(i=0;i<n;i++){
        if(arr.A[i]-i != diff){
            while(diff<arr.A[i]-i){
                printf("%d ",i+diff);
                diff++;
            }
        }
    }
    printf("\n");
    return 0;
}

//Unsorted Array for first n natural no.
int missingValues(struct Array arr,int n){
    int i;
    int *hash;
    hash = (int *)malloc((n+1)*sizeof(int));

    // Initialize hash array to 0
    for (i = 0; i <= n; i++) {
        hash[i] = 0;
    }

    for(i=0;i<arr.length;i++){
        hash[arr.A[i]]++;
    }
    for(i=1;i<=n;i++){
        if(hash[i]==0){
            printf("%d ",i);
        }
    }
    printf("\n");
    free(hash);
    return 0;
}

int main(){
    struct Array arr1 = {{1,2,3,4,6},10,5};
    // struct Array arr2 = {{1,2,4,5,8},10,5};
    struct Array arr3 = {{3,1,4,6,8},10,5};
    Display(arr1);

    // printf("Missing Value : %d \n",singleMissingValue(arr1));
    // printf("Missing Value : %d \n",singleMissingValue2(arr1,6));
    // multipleMissingValue(arr2,8);
    missingValues(arr3,8);


    return 0;
}