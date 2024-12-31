#include<stdio.h>

// we assume that anagram are of same length
void checkAnagram(char s1[],char s2[]){
    int count[26] = {0};
    int i;
    for(i=0; s1[i]!= '\0';i++){
        count[s1[i]-'a']++;
    }
    for(i=0; s2[i]!='\0';i++){
        count[s2[i]-'a'] -=1;
        if(count[s2[i]-'a']<0){
            printf("Not a Anagram");
            break;
        }
    }
    if(s2[i]=='\0'){
        printf("It is Anagram");
    } 
}

int main(){
    char A[] = "decimal";
    char B[] = "medical";
    checkAnagram(A,B);
}