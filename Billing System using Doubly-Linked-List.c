#include<stdio.h>
#include<stdlib.h>

void display();

struct node{
    struct node *prev;
    int data;
    char name[20];
    int quantity;
    int price; 
    struct node *next;
};

struct node *start=NULL;

struct node* create_node(){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    printf("ENTER PRODUCT ID: \n");
    scanf("%d",&n->data);
    printf("ENTER PRODUCT NAME: \n");
    scanf("%s",&n->name);
    printf("ENTER QUANTITY: \n");
    scanf("%d",&n->quantity);
    printf("ENTER PRICE OF EACH PRODUCT: \n");
    scanf("%d",&n->price);
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void add_end(){
    system("cls");
    struct node *temp;
    temp = create_node();
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *traverse;
        traverse = start;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse->next=temp;
        temp->prev=traverse;
    }
    display();
}

void delete_end(){
    system("cls");
    struct node *traverse;
    traverse = start;
    while(traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    traverse->prev->next = NULL;
    printf("%d has been deleted",traverse->data);
    free(traverse);
    display();
}
void delete_beg(){
    system("cls");
    struct node *temp;
    temp = start;
    start = start->next;
    printf("%d has been deleted\n",temp->data);
    free(temp);
    display();
}

void delete_after(int value){
    system("cls");
    struct node *traverse;
    traverse = start->next;
    while(traverse->data != value)
    {
        traverse = traverse->next;
    }
    if(traverse->next==NULL)
    {
        delete_end();
    }
    else
    {
        traverse->next->prev=traverse->prev;
        traverse->prev->next=traverse->next;
        printf("%d has been deleted\n",traverse->data);
        free(traverse);
        display();
    }
}

void display(){
    struct node *traverse;
    traverse  = start;
    system("cls");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t******ALL MART STORE******\n\n");
    printf("--------------------------------------------------------------------------------");
    printf("\nPRODUCT ID\tPRODUCT NAME\t\tQUANTITY\tPRICE\t\tTOTAL\n");
    printf("--------------------------------------------------------------------------------\n");
    while(traverse!=NULL)
    {   
        printf("%d\t\t",traverse->data);
        printf("%s\t\t\t",traverse->name);
        printf("%d\t\t",traverse->quantity);
        printf("%d\t\t",traverse->price);
        printf("%d\n",traverse->quantity*traverse->price);
        traverse = traverse->next;

    }
}

void edit_price(){
    system("cls");
    display();
    struct node *traverse;
    traverse  = start;
    int DATA,PRICE;
    printf("\nEnter the ID of the product for which you want to edit the bill: \n");
    scanf("%d",&DATA);
    printf("Enter the new price: \n");
    scanf("%d",&PRICE);
    while(traverse->data != DATA)
    {
        traverse = traverse->next;
    }
    traverse->price=PRICE;
    system("cls");
    display();
}
void edit_quantity(){
    system("cls");
    display();
    struct node *traverse;
    traverse  = start;
    int DATA,QUANTITY,PRICE;
    printf("\nEnter the ID of the product for which you want to edit the bill: \n");
    scanf("%d",&DATA);
    printf("Enter the new quantity: \n");
    scanf("%d",&QUANTITY);
    while(traverse->data != DATA)
    {
        traverse = traverse->next;
    }
    traverse->quantity=QUANTITY;
    system("cls");
    display();
}

void edit(){
    system("cls");
    display();
    struct node *traverse;
    traverse  = start;
    int DATA,QUANTITY,PRICE;
    printf("\nEnter the ID of the product for which you want to edit the bill: \n");
    scanf("%d",&DATA);
    printf("Enter the new quantity and price: \n");
    scanf("%d %d",&QUANTITY,&PRICE);
    while(traverse->data != DATA)
    {
        traverse = traverse->next;
    }
    traverse->quantity=QUANTITY;
    traverse->price=PRICE;
    system("cls");
    display();
}

void buy(){
    system("cls");
    float total;
   
    if(start==NULL) 
    {
	    printf("\n<<<<<There are no items to buy!!!!!>>>>>\n\n");
    }
	else
    {
        int c=0,pay=0;
        struct node *traverse;
        traverse=start;
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t******ALL MART STORE******\n\n");
        printf("--------------------------------------------------------------------------------");
        printf("\nPRODUCT ID\tPRODUCT NAME\t\tQUANTITY\tPRICE\t\ttotal\n");
        printf("--------------------------------------------------------------------------------\n");
        while(traverse!=NULL)
	    {
            printf("%d\t\t",traverse->data);
            printf("%s\t\t\t",traverse->name);
            printf("%d\t\t",traverse->quantity);
            printf("%d\t\t",traverse->price);
            printf("%d\n",traverse->quantity*traverse->price);
		    c=c+1;
            pay=pay + ((traverse->quantity)*(traverse->price));
            traverse=traverse->next;
	    }
        printf("\n--------------------------------------------------------------------------------");
        printf("\nTotal products in your Bill are: %d\n",c);
        total=pay*(0.95);
        printf("--------------------------------------------------------------------------------\n");
        printf("\n\nOriginal price: \t\t\t%d",pay);
        printf("\nWith 5%% discount: \t\t\t%f\n\n\n\t\tTHANKS FOR SHOPPING , VISIT AGAIN\n",total);
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

void search(){
    system("cls");
    int id;
    printf("\nEnter Product ID \n");
    scanf("%d",&id);
    int f=0;
 	struct node *p=start;
    system("cls");
    display();
 	while(p!=NULL)
 	{
 		if(id==p->data)
 		{
 		    f=1;
 			break;
 		}
        p=p->next;
	}
	if(f==1)
    {
        printf("\n\n\nProduct is available!:-)\n");
        printf("------------------------------------------------------------------------");
        printf("\nPRODUCT ID\tPRODUCT NAME\tQUANTITY\tPRICE\t\ttotal\n");
        printf("------------------------------------------------------------------------\n");
        printf("%d\t\t",p->data);
        printf("%s\t\t",p->name);
        printf("%d\t\t",p->quantity);
        printf("%d\t\t",p->price);
        printf("%d\n",p->quantity*p->price);
    }
    else
    {
        printf("Product is unavailable!:-(\n");
    }
}

int main(){
    system("color 70");
    int option,id,editno;
    system("cls");
    do
    {   
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("1) ADD PRODUCT TO THE BILL\n");
        printf("2) DELETE PRODUCT FROM THE BILL\n");
        printf("3) EDIT THE BILL \n");
        printf("4) BUY\n");
        printf("5) SEARCH THE PRODUCT IN THE BILL \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        scanf("%d",&option);
        switch(option){
        case 1: add_end();
                break;
        case 2: {
                    printf("Enter the ID of the product which you want to delete: \n");
                    scanf("%d",&id);
                    if(start->data==id)
                    {
                        delete_beg();
                    }
                    else
                    {
                        delete_after(id);
                    }
                    break;
                }
        case 3: {
                    system("cls");
                    display();
                    printf("\n1) Edit the Price\n");
                    printf("2) Edit the Quantity\n");
                    printf("3) Edit both Quantity and Price\n");
                    scanf("%d",&editno);
                    if(editno==1)
                    {
                        edit_price();
                    }
                    else if(editno==2)
                    {
                        edit_quantity();
                    }
                    else
                    {
                        edit();
                    }
                    break;
                }
        case 4: buy();
                break;
        case 5: search();
                break;
        
        }
        if(option==4)
        {
            break;
        }
    }while(option!= 0);
    return 0;
}