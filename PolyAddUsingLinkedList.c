//C Program to add two polynomial using LinkedList
//completed up to line 85

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int coeff;
  int pow;
  struct Node* next;
};

void readPolynomial(struct Node** poly){
int coeff, exp, cont,n;
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
*poly = temp;
printf("\nno.of b terms present:");
scanf("%d", &n);
for(int i=0; i < n; i++){
  printf("\nEnter the coefficient:");
  scanf("%d", &temp->coeff);
  printf("\nEnter the exponent:");
  scanf("%d", &temp->pow);
  temp -> next = NULL;
  if((temp -> pow) != 0){
    temp -> next = (struct Node*)malloc(sizeof(struct Node));
    temp = temp -> next;
    temp -> next = NULL;
  }
}
}

void displayPolynomial(struct Node* poly){
printf("\nPolynomial expression is: ");
while(poly != NULL){
  printf("%dX^%d", poly -> coeff, poly -> pow);
  poly = poly -> next;
  if(poly != NULL)
    printf("+");
}
printf("\n");
}

void addPolynomials(struct Node** result, struct Node* first, struct Node* second){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp -> next = NULL;
  *result = temp;
  while(first && second){
  if(first -> pow > second -> pow){
  temp -> coeff = first -> coeff;
  temp -> pow = first -> pow;
  first = first -> next;
  }
  else if(first -> pow < second -> pow){
  temp -> coeff = second -> coeff;
  temp -> pow = second -> pow;
  second = second -> next;
  }
  else{
  temp -> coeff = first -> coeff + second -> coeff;
  temp -> pow = first -> pow;
  first = first -> next;
  second = second -> next;
  }

  if(first && second){
  temp -> next = (struct Node*)malloc(sizeof(struct Node));
  temp = temp -> next;
  temp -> next = NULL;
  }
  }
  while(first || second){
  temp -> next = (struct Node*)malloc(sizeof(struct Node));
  temp = temp -> next;
  temp -> next = NULL;
 
  if(first){
  temp -> coeff = first -> coeff;
  temp -> pow = first -> pow;
  first = first -> next;
  }

  else if(second){
  temp -> coeff = second -> coeff;
  temp -> pow = second -> pow;
  second = second -> next;
  }
  }
}

int main()
{

 struct Node* first = NULL;
 struct Node* second = NULL;
 struct Node* result = NULL;
 printf("\nEnter the corresponding data:-\n");
 printf("\nFirst polynomial:\n");
 readPolynomial(&first);
 displayPolynomial(first);
 printf("\nSecond polynomial:\n");
 readPolynomial(&second);
 displayPolynomial(second);
 addPolynomials(&result, first, second);
 printf("\nResult:");
 displayPolynomial(result);
 return 0;
}