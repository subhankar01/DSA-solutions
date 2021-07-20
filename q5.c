#include<stdio.h>
#include<stdlib.h>
struct Node  
{  
    int data;  
    struct Node* next;  
};  
    
struct Node * push(struct Node *top,int data)  
{   
    struct Node* temp;  
    temp = (struct Node *)malloc(sizeof(struct Node)); 
    if (top==NULL)
    {
    temp->data = data;
    temp->next =NULL;
    top = temp;
    }
    else
    {
    temp->data = data;    
    temp->next = top;   
    top = temp;
    }
    return top;
}   
   
struct Node * pop(struct Node *top)  
{  
    struct Node* temp;  
  
    if (top == NULL)  
    {  
        printf("\nStack Underflow\n");  
        exit(1);  
    }  
    else
    {    
        temp = top;    
        top = top->next;  
        temp->next = NULL;   
        free(temp);  
    }  
    return top;
}  
void display(struct Node * top)  
{  
    struct Node* temp;    
    if (top == NULL) 
    {  
        printf( "\nStack Underflow");  
        exit(1);  
    }  
    else 
    {  
        temp = top;  
        while (temp != NULL) 
        {  

            printf("%d ->",temp->data);   
            temp = temp->next;  
        }  
        printf("End\n");
    }  
}  

int main() {
    int *a,m,pos,c,data;
    struct Node * head =NULL;
    int n,i;    
 do
 {
    printf("Enter your choice \n 0 - END  \n  1 - PUSH \n 2 - POP \n 3 - DISPLAY \n ");
    scanf("%d",&c);
 switch(c)
 {case 0: {break;}
case 1:
{   printf("\n Enter the data you wanna push\n");
    scanf("%d",&data);
    head=push(head,data);
    break;
}
case  2:
{
    head=pop(head);
    break;
}
case 3:
{
    display(head);
    break;
}

 }
}while(c!=0);
    return 0;
}
