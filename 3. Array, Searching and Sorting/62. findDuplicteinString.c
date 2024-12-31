#include<stdio.h>

// using hash  O(n)
void findDuplicates(char s[]){
    int count[26] = {0};
    int i;
    // Counting the element of string
    for(i=0; s[i]!='\0';i++){
        int index = s[i] - 'a';
        count[index]++;
    }

    for(i=0;i<26;i++){
        if(count[i]>1){
            // char ch = i + 'a';
            printf("Duplicate element is : %c \n", i+'a');
            printf("Count is : %d \n", count[i]);
        }
    }
}

// for checking continous duplicate not used in string
void findDuplicates2(char s[]){
    int i,j;
    for(i=0; s[i]!=0; i++){
        if(s[i]==s[i+1]){
            j=i+1;
            while(s[j]==s[i]){
                j++;
            }
            printf("Duplicate element and its count are %c and %d respectively \n", s[i],j-i);
            i=j-1;  
        }  
    }
}

// using bits
void checkDuplicate(char s[]){
    int x = 0,H=0;  // As int is of 4 bytes it will be enough to store 26 alphabets
    int i;
    for(i=0;s[i]!='\0';i++){
        x=1;
        x = x << (s[i] - 'a');
        if((x & H)> 0 ){
            printf("Duplicate element is : %c \n", s[i]);
        }else{
            H = x|H;
        }
    }
}

int main(){
    char s[6] = "shoot";
    // findDuplicates(s);
    // findDuplicates2(s);
    checkDuplicate(s);
    // printf("%s",s);
}