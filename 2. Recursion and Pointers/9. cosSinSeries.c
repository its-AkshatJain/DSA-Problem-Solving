#include<stdio.h>
#include<math.h>
#define PI 3.142

double sinSeries( float x){
    int i=2;
    double sum=0;
    float num, den, term;
    num=x;
    den=1;
    
    do{
        term=num/den;
        sum=sum+term;
        num = -num*x*x;
        den = den * i * (i+1);
        i=i+2;
    }while(fabs(term)>= 0.00001);
    return sum;
}

double cosSeries( float x){
    int i=2;
    double sum=0;
    float num, den, term;
    num=1;
    den=1;
    do{
        term = num/den;
        sum=sum+ term;
        num= -num*x*x;
        den=den*i*(i-1);
        i=i+2;
    }while(fabs(term)>=0.00001);
    return sum;
}

int main(){
    int degree;
    printf("Enter the degree :");
    scanf("%d",&degree);
    float rad = degree * (PI/180);

    printf("Sin series value is %lf \n", sinSeries(rad));
    printf("Sin series value is (using inbuilt fn) %lf \n", sin(rad));

    printf("Cos series value is %lf \n", cosSeries(rad));
    printf("Cos series value is (using inbuilt fn) %lf \n", cos(rad));

    return 0;
}