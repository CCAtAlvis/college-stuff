/*Design a software for a retail store to keep track of inventory. 
The software should generate a report of items whose quantity is below threshold*/
// #include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct inventory
{
    char item[50];
    int itemCode;
    int threshold;
    int quantity;
    int price;
    struct inventory *next;
} *start,*newItem;

void storeData();
void restoreData();
void arrangeItem();
void addNewItem( struct inventory * );
void deleteItem();
void changeQuantity();
void changeThreshold();
void thresholdReport();
void allReport();
void itemBought();

void storeData()
{
    FILE *fpName;
    FILE *fpCode;
    FILE *fpThreshold;
    FILE *fpQuantity;
    FILE *fpPrice;
    int i;
    struct inventory *ptr;

    fpName = fopen("itemName.txt","w");
    fpCode = fopen("itemCode.txt","w");
    fpThreshold = fopen("ite.Threshold.txt","w");
    fpQuantity = fopen("itemQuantity.txt","w");
    fpPrice = fopen("itemPrice.txt","w");

    ptr = start;

    // new code
    {
    for(i=0;i!='\0';i++)
        putc(ptr->item[i],fpName);

    fprintf(fpCode, "%d",ptr->itemCode);
    fprintf(fpThreshold, "%d",ptr->threshold);
    fprintf(fpQuantity, "%d",ptr->quantity);
    fprintf(fpPrice, "%d",ptr->price);

    ptr = ptr->next;

    while( ptr!=NULL )
    {
        putc('\n',fpName);        
        for(i=0;i!='\0';i++)
            putc(ptr->item[i],fpName);

        fprintf(fpCode, "\n%d",ptr->itemCode);
        fprintf(fpThreshold, "\n%d",ptr->threshold);
        fprintf(fpQuantity, "\n%d",ptr->quantity);
        fprintf(fpPrice, "\n%d",ptr->price);

        ptr = ptr->next;
    }
    }

    // old code
    // while( ptr!=NULL )
    // {
    //     for(i=0;i!='\0';i++)
    //         putc(ptr->item[i],fpName);
    //     putc('\n',fpName);

    //     fprintf(fpCode, "%d\n",ptr->itemCode);
    //     fprintf(fpThreshold, "%d\n",ptr->threshold);
    //     fprintf(fpQuantity, "%d\n",ptr->quantity);
    //     fprintf(fpPrice, "%d\n",ptr->price);

    //     ptr = ptr->next;
    // }
}


void restoreData()
{
    FILE *fpName;
    FILE *fpCode;
    FILE *fpThreshold;
    FILE *fpQuantity;
    FILE *fpPrice;
    int i = 0;
    char c = '';
    struct inventory *ptr;
    fpName = fopen("itemName.txt","r");
    fpCode = fopen("itemCode.txt","r");
    fpThreshold = fopen("ite.Threshold.txt","r");
    fpQuantity = fopen("itemQuantity.txt","r");
    fpPrice = fopen("itemPrice.txt","r");

    while(!feof(fpCode))
    {
	    ptr = (struct inventory*)malloc(sizeof(struct inventory));
        // printf("%c",fgetc(fpName));
        while(c!='\0')
        {
            c = fgetc(fpName);
            printf("%c",c);
            ptr->item[i] = c;
            i++;
        }
        ptr->item[i] = '\0';

        // do
        // {
        //     c = getc(fpName);
        //     ptr->item[i] = c;
        //     i++;
        // }
        // while(c != '\0');
        // ptr->item[i] = '\0';

        fscanf(fpCode, "%d", &ptr->itemCode);
        fscanf(fpThreshold, "%d", &ptr->threshold);
        fscanf(fpQuantity, "%d", &ptr->quantity);
        fscanf(fpPrice, "%d", &ptr->price);
        addNewItem(ptr);
    }
}
void arrangeItem()
{
    // struct inventory *ptr = start;
    // struct inventory *ptrnext = start->next;
    // struct inventory *min;

    // while (ptr!=NULL)
    // {
    //     min = ptr;
    //     ptrnext = ptr->next;
    //     while (ptrnext!=NULL)
    //     {
    //         if((min->quantity-min->threshold)>(ptrnext->quantity-ptrnext->threshold))
    //         {
    //             min = ptrnext;
    //         }
    //         ptrnext = ptrnext->next;

    //     }
    //     ptr = ptr->next;
    // }

    struct inventory *ptr1 = start;
    struct inventory *ptr2;
    struct inventory *temp;
    int diff = 0;

    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if ((ptr1->quantity-ptr1->threshold) < (ptr2->quantity-ptr2->threshold))
            {
                strncpy(temp->item, ptr1->item, 50);
                temp->itemCode = ptr1->itemCode;
                temp->threshold = ptr1->threshold;
                temp->quantity = ptr1->quantity;
                temp->price = ptr1->price;

                strncpy(ptr1->item, ptr2->item, 50);
                ptr1->itemCode = ptr2->itemCode;
                ptr1->threshold = ptr2->threshold;
                ptr1->quantity = ptr2->quantity;
                ptr1->price = ptr2->price;

                strncpy(ptr2->item, temp->item, 50);
                ptr2->itemCode = temp->itemCode;
                ptr2->threshold = temp->threshold;
                ptr2->quantity = temp->quantity;
                ptr2->price = temp->price;
            }
        }
    }

}

void addNewItem(struct inventory *addedItem)
{
    newItem = addedItem;
    struct inventory *ptr = start;

    if(start==NULL)
    {
        newItem->next = NULL;
        start = newItem;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
            ptr=ptr->next;

        ptr->next = newItem;
        newItem->next=NULL;
    }
    // if(start==NULL)
    // {
    //     start = newItem;
    // }
    // else
    // {
    //     do
    //     {
    //         ptr = ptr->next;
    //     }
    //     while(ptr!=NULL);
    //     ptr = newItem;
    // }
    printf("\nItem saved\n");
}

void deleteItem()
{
        int itmcd;
        struct inventory *ptr = start;
        struct inventory *preptr;
        printf("enter item code");
        scanf("%d",&itmcd);
        if(start->itemCode==itmcd)
        {
            start = start->next;
        }
        else
        {
        preptr = start;
        ptr = ptr->next;
        do
        {
            if(ptr->itemCode==itmcd)
            {
                preptr->next = ptr->next;
                free(ptr);
                printf("\nItem deleted\n");
            }
            preptr = ptr;
            ptr = ptr->next;
        }while(ptr!=NULL);
        if(ptr == NULL)
        {
            printf("Item not found");
        }
    }
}

void changeQuantity()
{
    int itmcd;
    int qntadd;
    struct inventory *ptr = start;
    printf("Enter Item code");
    scanf("%d",&itmcd);
    do
    {
        if(ptr->itemCode==itmcd)
        {
            printf("Enter quantity added :");
            scanf("%d",&qntadd);
            ptr->quantity+= qntadd;
            arrangeItem(ptr);
            printf("\nQuantity changed\n");
            break;
        }
        ptr= ptr->next;
    }while(ptr!=NULL);
    if(ptr==NULL)
        printf("Item not found");
}

void changeThreshold()
{
    int itmcd;
    int newthres;
    struct inventory *ptr = start;
    printf("Enter Item code");
    scanf("%d",&itmcd);
    do
    {
        if(ptr->itemCode==itmcd)
        {
            printf("Enter the new threshold :");
            scanf("%d",&newthres);
            ptr->threshold= newthres;
            arrangeItem(ptr);
            printf("\nThreshold changed\n");
            break;
        }
        ptr= ptr->next;
    }while(ptr!=NULL);
    if(ptr==NULL)
        printf("Item not found");
}

void thresholdReport()
{
    struct inventory *ptr = start;
    int i = 0;
    do
    {
        if(ptr->quantity < ptr->threshold)
        {
            printf("\n%d. %s(item code : %d) :",++i,ptr->item,ptr->itemCode);
            printf("\nQuantity : %d, Threshold :%d",ptr->quantity,ptr->threshold);
            printf("\nPrice : %d\n",ptr->price);
        }
        ptr = ptr->next;
    }while(ptr!=NULL);
}

void allReport()
{
    struct inventory *ptr = start;
    int i = 0;

    do
    {
        printf("\n%d. %s(item code : %d) :",++i,ptr->item,ptr->itemCode);
        printf("\nQuantity : %d, Threshold :%d",ptr->quantity,ptr->threshold);
            printf("\nPrice : %d\n",ptr->price);
            ptr = ptr->next;
        
    }
    while(ptr!=NULL);
}

void itemBought()
{
    int itmcd;
    int qntchg;
    struct inventory *ptr = start;
    printf("Enter Item code");
    scanf("%d",&itmcd);
    do
    {
        if(ptr->itemCode==itmcd)
        {
            printf("Enter number of the item bought :");
            scanf("%d",&qntchg);
            ptr->quantity-= qntchg;
            arrangeItem(ptr);
            break;
        }
        ptr= ptr->next;
    }while(ptr!=NULL);
    if(ptr==NULL)
        printf("Item not found");
}

void main()
{
    int choice;
    struct inventory *Item = (struct inventory*)malloc(sizeof(struct inventory));    
    restoreData();
    do
    {
        printf("1.Item bought\n2.Add new item\n3.delete an item\n4.Change quantity of an item\n5.Change threshold of an item\n");
        printf("Print Report :\n6.items having quantity less than threshold\n7.all items\n8.Exit\n");
        printf("Enter Choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: itemBought();
                    break;
            case 2: 
                printf("\nEnter item name :");
                scanf("%s",Item->item);
                printf("\nEnter item code :");
                scanf("%d",&Item->itemCode);
                printf("\nEnter item threshold quantity :");
                scanf("%d",&Item->threshold);
                printf("\nEnter current quantity :");
                scanf("%d",&Item->quantity);
                printf("\nEnter item price :");
                scanf("%d",&Item->price);
                addNewItem(Item);
                break;
            
            case 3: deleteItem();
                    break;
            case 4: changeQuantity();
                    break;
            case 5: changeThreshold();
                    break;
            case 6: thresholdReport();
                    break;
            case 7: allReport();
                    break;
            case 8: break;
            default:("invalid choice");
        }
    }while(choice!=8);
    storeData();
    // getch();
}
