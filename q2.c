#include <stdio.h> 
#include <stdlib.h> 
  
struct node { 
    int key; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new BST node 
struct node* newNode(int item) 
{ 
    struct node* temp 
        = (struct node*)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(struct node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
  
/* A utility function to insert 
   a new node with given key in 
 * BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
struct node* search(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
}
int main()
{
    int ch,ele;
    struct node* root = NULL;
    printf("Press 1 for insertion\n");
    printf("Press 2 for searching element\n");
    do
    {
        printf("Enter your choice:\n");
        scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the element you want to insert:\n");
        scanf("%d",&ele);
        root = insert(root,ele); 
        break;
        case 2:
        printf("Enter the element you want to search:\n");
        scanf("%d",&ele);
        root=search(root,ele);
        if(root->key == ele)
        printf("Found !");
        else
        printf("Not found !");
        break;
        default:
        printf("Exiting.....");
        exit(0);
        break;
        
    }
    }while(ch<=2);
    return 0;
}
