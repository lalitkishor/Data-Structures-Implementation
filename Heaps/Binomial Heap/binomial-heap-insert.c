//file name binomial-heap-insert.c
// insertion in binomial heap

#include<stdio.h>

struct node{
    int n;
    int degree;
    struct node *head;
    struct node *child;
    struct node *sibling;
};
struct node* H = NULL;

struct node* MAKE_BINOMIAL_HEAP(){
    struct node *temp;
    temp=NULL;
    return temp;
};
//create a new node using malloc function

struct node* CREATE_NODE(int num){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->n=num;
    return temp;
};

void BINOMIAL_LINK(struct node *y,struct node *z){
    y->head=z;
    y->sibling=z->child;
    z->child=y;
    z->degree = z->degree+1;
}


struct node* BINOMIAL_HEAP_MERGE(struct node* H1,struct node* H2){
    struct node* H=MAKE_BINOMIAL_HEAP();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;
    y=H1;
    z=H2;
    if(y!= NULL){
        if( z!=NULL && y->degree <= z->degree){
            H=y;
            }
        else if(z!=NULL && y->degree > z->degree){
            H=z;
        }
        else{
            H=y;
        }
    }
    else
        H=z;
        while (z!=NULL && y!=NULL){
             if (y->degree < z->degree)
             {
                    y = y->sibling;
             }
        else if (y->degree == z->degree) {
                a = y->sibling;
                y->sibling = z;
                y = a;
            }
        else {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
        }
    return H;
};

struct node* BINOMIAL_HEAP_UNION(struct node* H1,struct node* H2){
    struct node* prev_x=NULL;
    struct node* next_x;
    struct node* x;
    int temp;
    struct node *H = MAKE_BINOMIAL_HEAP();
    H= BINOMIAL_HEAP_MERGE(H1,H2);
    if(H == NULL){
        return H;
    }
    x = H;
    next_x = x->sibling;
    while (next_x!=NULL){
        if((x->degree!=next_x->degree) ||(next_x->sibling!=NULL &&(next_x->sibling)->degree==x->degree)){
            prev_x=x;
            x=next_x;
        }
        else {
                if(x->n<=next_x->n){
                    x->sibling=next_x->sibling;

                    BINOMIAL_LINK(next_x,x);

                }
                else {
                        if(prev_x==NULL){
                                H=next_x;
                        }
                        else
                             prev_x->sibling=next_x;
                        BINOMIAL_LINK(x,next_x);
                        x=next_x;

                }

        }
        next_x=x->sibling;
    }
    return H;
};

struct node* BINOMIAL_HEAP_INSERT(struct node* H, struct node* x) {
    struct node* H1 = MAKE_BINOMIAL_HEAP();
    x->head = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = BINOMIAL_HEAP_UNION(H, H1);
    return H;
}

// display the binomial heap

int DISPLAY(struct node* H){
    struct node* p;
    if(H==NULL){
        printf("\n Heap is Empty !!!!!");
        return 0;
    }
    printf("\nTHE ROOT NODES ARE:-\n");
    p = H;
    while (p != NULL) {
        printf("%d", p->n);
        if (p->sibling != NULL)
            printf("-->");
        p = p->sibling;
    }
    printf("\n");
}

int main(){
    int array[]={3,5,1,2,13,15,11,12};
    int i;
    struct node* np;

    int size = sizeof(array)/sizeof(int);
    for (i = 0; i <size; i++) {
        np = CREATE_NODE(array[i]);
        H = BINOMIAL_HEAP_INSERT(H,np);
    }
    DISPLAY(H);
    return 0;
}
