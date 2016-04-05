// file name max-heapify.c
#include<stdio.h>

// max_heapify

void max_heapify(int array[],int i,int s){
    int left=2*i+1;
    int right=2*i+2;
    int largest;
    if((left<s)&&(array[left]>array[i])){
        largest=left;
        }
    else{
        largest=i;
    }
    if((right<s)&&(array[right]>array[largest])){
        largest=right;
    }
    if (largest!=i){
        int temp=array[i];
        array[i]=array[largest];
        array[largest]=temp;
        max_heapify(array,largest,s);
    }
}

//Build a max heapify

void build_max_heapify(int array[] , int s){
    int i;
    for(i=s/2;i>=0;i--){
        max_heapify(array,i,s);
    }
}

void main(){
    int array[]={4,1,3,2,16,9,10,14,8,7};
    int i,size;
    size = sizeof(array)/sizeof(int);
    printf("Given tree element is \n");
    for (i=0;i<size;i++){
        printf("\t%d",array[i]);
    }
    build_max_heapify(array,size);
    // print max heapify
    printf("\n Max heapify element is \n");
    for (i=0;i<size;i++){
        printf("\t%d",array[i]);    //print element of max heap
    }
}
