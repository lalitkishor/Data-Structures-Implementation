//file name Binary-search-tree.c
#include<stdio.h>

struct Node{
 int num;
 struct Node *Left;
 struct Node *Right;
};

struct Node* node;// create a globaly node
// for createing  a new node
struct Node* CreateNode(struct Node* temp,int num){
    temp=(struct Node*) malloc(sizeof(struct Node));
    temp->num=num;
    temp->Left=temp->Right=NULL;
    return temp;
};

struct Node* Insert(struct Node* node,int num){
    if (node==NULL)
        node=CreateNode(node,num);
    else if(num <=node->num)//if number is smaller than root node then insert a number in left sub tree
            node->Left = Insert(node->Left,num);
    else
       node->Right = Insert(node->Right,num);//if number is grater than root node then insert a number in right sub tree
    return node; //return always root node address
}
void Preoder(struct Node* root){
    if(root==NULL)return;
    printf("%d\n",root->num);
    Preoder(root->Left);
    Preoder(root->Right);
}
void main(){
    node=NULL;
    node = Insert(node,15);
	node = Insert(node,10);
	node = Insert(node,20);
	node = Insert(node,25);
	node = Insert(node,8);
	node = Insert(node,12);
	printf("Preoder traversing in binary search tree\n");
    Preoder(node);
}
