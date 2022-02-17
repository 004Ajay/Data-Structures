//C Program to add two polynomial using LinkedList
//completed up to line 85

#include<stdio.h>
#include<stdlib.h>

struct Node
  {
   int coeff;
   int pow;
   struct Node* next;
  };

void readPoly(struct Node** poly)
  {
   int coeff,exp,cont;
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
   *poly=temp;

   do
    {
     printf("\nEnter Coeffecient: ");
     scanf("%d",&coeff);
     printf("\nEnter Exponent: ");
     scanf("%d",&exp);
     temp->coeff=coeff;
     temp->pow=exp;
     temp->next=NULL;
     printf("\n1-Continue\n0-Next Step\n");
     scanf("%d",&cont);
     if(cont)
      {
       temp->next =(struct Node*)malloc(sizeof(struct Node));
       temp=temp->next;
       temp->next=NULL;
      }
    }while(cont);
  }

void displayPoly(struct Node* poly)
 {
   printf("\nPolynomial expression is: ");
   while(poly!=NULL)
   {
    printf("%dX^%d",poly->coeff,poly->pow);
    poly=poly->next;
    if(poly!=NULL)
    printf("+");
   }
 }

void addPoly(struct Node** result,struct Node* first,struct Node* second)
  {
   struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
   temp->next=NULL;
   *result=temp;

   while(first && second)
     {
      if(first->pow>second->pow)
 	{
 	 temp->coeff=first->coeff;
 	 temp->pow=first->pow;
 	 first=first->next;
 	}
      else if(first->pow<second->pow)
 	{
 	 temp->coeff=second->coeff;
 	 temp->pow=second->pow;
 	 second=second->next;
 	}
      else
 	{
 	 temp->coeff=first->coeff+second->coeff;
 	 temp->pow=first->pow;
 	 first=first->next;
 	 second=second->next;
 	}
      if(first && second)
 	{
 	 temp->next=(struct Node*)malloc(sizeof(struct Node));
 	 temp=temp->next;
 	 temp->next=NULL;
 	}
     }
   while(first||second)
     {
      temp->next=(struct Node*)malloc(sizeof(struct Node));
      temp=temp->next;
      temp->next=NULL;

      if(first)
 	{
 	 temp->coeff=first->coeff;
 	 temp->pow=first->pow;
 	 first=first->next;
 	}
      else if(second)
 	{
 	 temp->coeff=second->coeff;
 	 temp->pow=second->pow;
 	 second=second->next;
 	}
     }
  }

int main()
  {
   struct Node*first=NULL;
   struct Node*second=NULL;
   struct Node*result=NULL;
   
   printf("\n\tPolynomial 1\n\t----------");
   readPoly(&first);
   
   printf("\n\tPolynomial 2\n\t----------");
   readPoly(&second);
   
   addPoly(&result, first, second);
   
   displayPoly(first);
   displayPoly(second);
   displayPoly(result);
   
   return 0;
  }