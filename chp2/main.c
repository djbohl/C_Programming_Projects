#include <stdio.h>

//function prototypes
int addSum(int n1, int n2, int n3);
int getAverage(int sum, int n4);
int getProduct(int n1, int n2, int n3);
int getSmallest(int n1, int n2, int n3);
int getLargest(int n1, int n2, int n3);

int main()
{
    //declare variables
    int n1;
    int n2;
    int n3;
    int n4 = 3;
    //get user input
    printf("Enter three different integers:");
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    //call the functions
    int sum = addSum(n1,n2,n3);
    int average = getAverage(sum,n4);
    int product = getProduct(n1,n2,n3);
    int smallest = getSmallest(n1,n2,n3);
    int largest = getLargest(n1,n2,n3);
    //print the result
    printf("\nSum is %d", sum);
    printf("\nAverage is %d", average);
    printf("\nProduct is %d", product);
    printf("\nSmallest is %d", smallest);
    printf("\nLargest is %d", largest);
}

//function definitions

//function to get the sum
int addSum(int n1, int n2, int n3) {
    return n1+n2+n3;
}
//function to get the average
int getAverage(int sum, int n4){
    return sum/n4;
}
//function to get the product
int getProduct(int n1, int n2, int n3){
    return (n1*n2)*n3;
}
//function to get the smallest num
int getSmallest(int n1, int n2, int n3) {
    int smallest = 0;
    if(n1<n2) {
        return smallest = n1;
    }
    if(n2<n3) {
        return smallest = n2;
    }
    if(n3<n1) {
        return smallest = n3;
    }
    return smallest;
}
//function to get the smallest num
int getLargest(int n1, int n2, int n3) {
    int largest = 0;
    if(n1>n2) {
        return largest = n1;
    }
    if(n2>n3) {
        return largest = n2;
    }
    if(n3>n1) {
        return largest = n3;
    }
    return largest;
}