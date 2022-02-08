// C program to implement operations on LinkedList

#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

struct node *head = NULL;
//struct node *current = NULL;

//Function to check list is empty
int NoList(){
        struct node* temp = (struct node*)malloc(sizeof(struct node*));
        if(temp == NULL){ print("Memory Underflow"); return -1; } //no list
        else return 0; //list exists
}

//Function to Insert node at beginning
void Insert_Begin(){
        int item;
        struct node* ptr = (struct node*)malloc(sizeof(struct node*));
        struct node* temp = (struct node*)malloc(sizeof(struct node*));

        if(NoList()) exit (0);

        else{
                printf("Enter data to add: ");
                scanf("%d", &item);
                temp -> data = item; //assigning item to data
                temp -> link = head; 
                head = temp;
        }
}

//Function to Insert node at end
void Insert_End(){
        int item;
        struct node* ptr = (struct node*)malloc(sizeof(struct node*));
        struct node* temp = (struct node*)malloc(sizeof(struct node*));

        if(NoList()) exit (0);

        else{
                printf("Enter data to add: ");
                scanf("%d", &item);
            }    

}

//Function to Insert node at any position
void Insert_AnyPos(){

}

//Function to Delete node at beginning
void Delete_Begin(){

}

//Function to Delete node at end
void Delete_End(){

}

//Function to Delete node at any position
void Delete_AnyPos(){

}

//Function to Display(Travese) the list
void Traverse(){
        struct node* ptr = (struct node*)malloc(sizeof(struct node*));
        ptr = head;
        while(ptr != NULL)
             printf("%d", ptr -> data);
        ptr = ptr -> link;    
}


//Main Function
int main(){
int choice;

printf("LinkedList Operations\n1. Insertion at beginning\n2. Insertion at end\n3. Insertion at any position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at any position\n7. Display(Travesing)\n8. Exit\nChoice: ");
scanf("%d", &choice);

switch(choice){
    case 1: printf("Insertion at beginning selected");
            Insert_Begin();
            break;

    case 2: printf("Insertion at end selected");
            Insert_End();
            break;

    case 3: printf("Insertion at any position selected");
            Insert_AnyPos;
            break;

    case 4: printf("Deletion at beginning selected");
            Delete_Begin();
            break;

    case 5: printf("Deletion at end selected");
            Delete_End();
            break;

    case 6: printf("Deletion at any position selected");
            Delete_AnyPos();
            break;

    case 7: printf("Showing the List");
            Traverse();
            break; 

    case 8: printf("Exited!");
            exit(0); 

    default: printf("Wrong Choice!");
             break;
            }

    return 0;
}
