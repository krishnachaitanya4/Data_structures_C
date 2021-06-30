#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};

struct node *head;

void print(){
    struct node *temp = head;
    printf("The list is : ");
    while(temp != NULL){
        printf("%d ",temp-> value);
        temp=temp->next;
    }
    printf("\n");
}

void starting(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> value = x;
    temp -> next = head;
    head = temp;
}

void ending(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> value = x;
    temp -> next = NULL;
    if (head == NULL){
        head = temp;
        return;
    }
    struct node *t2=head;
    while (t2!=NULL){
        if(t2->next==0){
            t2->next=temp;
            break;
        }
        t2=t2->next;
    }
}

void insert(int data,int n){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> value=data;
    temp -> next = NULL;
    if (n==1){
        temp->next=head;
        head=temp;
        return;
    }
    struct node *temp2=head;
    for (int i=0;i<n-2;i++){
        temp2=temp2->next;
    }
    temp -> next = temp2->next;
    temp2->next = temp;  
}

void delete(int n){
    struct node *temp = head;
    if (n==1){
        head=temp->next;
        free(temp);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp=temp->next;
    }
    struct node *temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}
int main(){

    head = NULL;
    printf("How many numbers : ");
    int n,i,x;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter a number \n");
        scanf("%d",&x);
        ending(x);
        print();
    }
    insert(7,3);
    ending(1);
    print();
    delete(3);
    print();
    return 0;
}
