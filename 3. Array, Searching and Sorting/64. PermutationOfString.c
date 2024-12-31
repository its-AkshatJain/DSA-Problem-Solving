#include<stdio.h>

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char s[], int k){
    // k is the stages of graph that we create in brute force 
    static int A[10] = {0}; // Keeps track of used elements
    static char res[10]; // Stores the current permutation

    if(s[k] == '\0'){ // Base case: end of the string
        res[k] = '\0';
        printf("%s \t", res);
        return;
    }
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(A[i] == 0){ // If s[i] has not been used
            res[k] = s[i];
            A[i] = 1;
            permutation(s, k + 1);
            A[i] = 0; // Backtrack
        }
    }
}

// it also creates duplicates you can use set to store it
void permutation2(char s[], int l,int h){
    if(l==h){
        printf("%s \t",s);
    }
    int i;
    for(i=0;s[i]!='\0';i++){
        swap(&s[i],&s[l]);
        permutation2(s,l+1,h);
        // Backtracking
        swap(&s[i],&s[l]);
    }
}

int main(){
    char s[] = "ABC";
    permutation(s,0);
    printf("\n");
    permutation2(s,0,2);
}