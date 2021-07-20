#include<stdio.h>
#include<stdlib.h>
int top;
int * push(int *stack,int n)
{int x;
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
    return stack;
}
int * pop(int *stack)
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
    return stack;
}
void display(int * stack)
{int i;
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
          { printf("\n%d",stack[i]);}
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
int main()
{
    
    top=-1;
    int choice,n,i;
    printf("\n Enter the size of STACK");
    scanf("%d",&n);
    int* stack= (int *) malloc(n*sizeof(int));
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                stack=push(stack,n);
                break;
            }
            case 2:
            {
               stack = pop(stack);
                break;
            }
            case 3:
            {
                display(stack);
                break;
            }
            case 4:
            {
                printf("\n\t BYE ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
