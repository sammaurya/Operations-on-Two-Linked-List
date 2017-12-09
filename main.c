#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first1=NULL,*first2=NULL,*first=NULL;

int count1=0,count2=0;

void main_menu();
void LinkList_A();
void LinkList_B();
void menu(struct node **,int *);
void create(struct node ***,int **);
void insertbeg(struct node ***);
void insertmid(struct node ***);
void insertend(struct node ***);
void deletebeg(struct node ***);
void deletemid(struct node ***);
void deleteend(struct node ***);
void sorting(struct node ***);
void reverse(struct node ***);
void print(struct node ***);
void Operations();
void Concatenate(struct node **,struct node **);
void Merge(struct node **,struct node **,struct node **);

int main()
{
    main_menu();
    return 0;
}

void main_menu()
{
    int choice;
    system("cls");
    printf("\n\t\t  Single Link List");
    printf("\n\t\t--------------------");
    printf("\nOperations on : ");
    printf("\n\t1. Link List A\n\t2. Link List B\n\t3.Operations on Two LL\n\t4. Exit");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            LinkList_A();
            break;
        case 2:
            LinkList_B();
            break;
        case 3:
            Operations();
            break;
        case 4:
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("Wrong Choice!!!");
        }
    }while(choice!=4);

}
void LinkList_A()
{
    menu(&first1,&count1);

}
void LinkList_B()
{
    menu(&first2,&count2);
}
void menu(struct node **newfirst,int *count)
{
    int choice;
    option:
    printf("------------------");
    printf("\n1.Create\n2.Insert\n3.Delete\n4.Sorting\n5.Reversing\n6.Print\n7.Clear Screen\n8.Main Menu");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create(&newfirst,&count);
                    break;
            case 2: printf("\n1.Insert at Begining\n2.Insert at Middle\n3.Insert at End\n4.Back");
                    printf("\nEnter Choice : ");
                    do
                    {
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: insertbeg(&newfirst);
                                    break;
                            case 2: insertmid(&newfirst);
                                    break;
                            case 3: insertend(&newfirst);
                                    break;
                            case 4: system("cls");
                                    goto option;
                                    break;
                            default: printf("Wrong Choice!!!");
                        }
                        if(choice!=4)
                        {
                            printf("\nEnter Again : ");
                        }
                     }while(choice!=4);
                    break;

            case 3: printf("\n1.Delete at Begining\n2.Delete at Middle\n3.Delete at End\n4.Back");
                    printf("\nEnter Choice : ");
                    do
                    {
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: deletebeg(&newfirst);
                                    break;
                            case 2: deletemid(&newfirst);
                                    break;
                            case 3: deleteend(&newfirst);
                                    break;
                            case 4: system("cls");
                                    goto option;
                                    break;
                            default: printf("Wrong Choice!!!");
                        }
                        if(choice!=4)
                        {
                            printf("\nEnter Again : ");
                        }
                     }while(choice!=4);
                    break;

            case 4: sorting(&newfirst);
                    printf("\nLink List is Sorted\n");
                    break;
            case 5: reverse(&newfirst);
                    printf("\nLink List is Reversed");
                    break;
            case 6: print(&newfirst);
                    break;
            case 7: system("cls");
                    goto option;
                    break;
            case 8: main_menu();
                    break;
            default:printf("Wrong Choice!!!");
        }
    }while(choice!=8);
}
void Operations()
{
    int choice;
    OPTION:
    printf("\n\n1.Concatenate Two LL\n2.Merge Sorted LL\n3.Clear Screen\n4.Main Menu\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Concatenate(&first1,&first2);
            break;
        case 2:
            Merge(&first1,&first2,&first);
            break;
        case 3:
            system("cls");
            goto OPTION;
            break;
        case 4:
            main_menu();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=4);

}
void Concatenate(struct node **newfirst1,struct node **newfirst2)
{
    if(*newfirst1==NULL&&*newfirst2==NULL)
    {
        printf("\nLink List A and B is Empty");
    }
    else if(*newfirst1==NULL)
    {
        printf("\nLink List A is Empty");
    }
    else if(*newfirst2==NULL)
    {
        printf("\nlink List B is Empty");
    }
    else
    {
        struct node *ptr;
        ptr=*newfirst1;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=*newfirst2;
        print(&newfirst1);
        printf("\nElements of Link List B is Added to Link List A");
        printf("\nLink List B is Empty Now");
        *newfirst2=NULL;
    }
}
void Merge(struct node **newfirst1,struct node **newfirst2,struct node **newfirst3)
{
    if(*newfirst1==NULL&&*newfirst2==NULL)
    {
        printf("\nLink List A and B is Empty");
    }
    else if(*newfirst1==NULL)
    {
        printf("\nLink List A is Empty");
    }
    else if(*newfirst2==NULL)
    {
        printf("\nlink List B is Empty");
    }
    else
    {
        sorting(&newfirst1);
        sorting(&newfirst2);
        printf("\nLink List A and B are Sorted\n");
        struct node *ptr1,*ptr2,*ptr,*cpt;
        ptr1=*newfirst1;
        ptr2=*newfirst2;
        ptr=(struct node *)malloc(sizeof(struct node));
        *newfirst3=ptr;
        if(ptr1->data<ptr2->data)
        {
            ptr->data=ptr1->data;
            ptr1=ptr1->next;
        }
        else
        {
            ptr->data=ptr2->data;
            ptr2=ptr2->next;
        }
        while(ptr1!=NULL&&ptr2!=NULL)
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            if(ptr1->data<ptr2->data)
            {
                cpt->data=ptr1->data;
                ptr1=ptr1->next;
            }
            else
            {
                cpt->data=ptr2->data;
                ptr2=ptr2->next;
            }
            ptr->next=cpt;
            ptr=cpt;
        }
        while(ptr1!=NULL)
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            cpt->data=ptr1->data;
            ptr1=ptr1->next;
            ptr->next=cpt;
            ptr=cpt;
        }
         while(ptr2!=NULL)
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            cpt->data=ptr2->data;
            ptr2=ptr2->next;
            ptr->next=cpt;
            ptr=cpt;
        }
        ptr->next=NULL;
        print(&newfirst3);
    }

}

void create(struct node ***newfirst,int **count)
{
    char c;
    RECREATE:
    if(**count==0)
    {
        int test=1;
        struct node *ptr,*cpt;
        while(test==1)
        {
            if((**newfirst)==NULL)
            {
                ptr=(struct node *)malloc(sizeof(struct node));
                printf("Enter Data : ");
                scanf("%d",&ptr->data);
                ptr->next=NULL;
                **newfirst=ptr;
                (**count)++;
            }
            else
            {
                cpt=(struct node *)malloc(sizeof(struct node));
                printf("Enter Data : ");
                scanf("%d",&cpt->data);
                cpt->next=NULL;
                ptr->next=cpt;
                ptr=cpt;
                (**count)++;
            }
            printf("Press To Enter More (Y/N) : ");
            scanf(" %c",&c);
            if(c=='Y'||c=='y')
            {
                test=1;
            }
            else
            {
                test=0;
            }
        }
    }
    else
    {
        printf("\nList Already Created : %d Elements are present",**count);
        printf("\nPress to Create Again (Y/N) : ");
        scanf(" %c",&c);
        if(c=='Y'||c=='y')
        {
            **newfirst=NULL;
            (**count)=0;
            goto RECREATE;
        }
    }
}
void insertbeg(struct node ***newfirst)
{
    struct node *ptr;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        ptr->next=**newfirst;
        **newfirst=ptr;
        printf("Data %d is Insert",ptr->data);
    }
}
void insertmid(struct node ***newfirst)
{
    int num;
    struct node *ptr,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        printf("\nEnter Data After Which You Want to Insert : ");
        scanf("%d",&num);
        while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("Data %d is not Found",num);
        }
        else
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            printf("Enter Data : ");
            scanf("%d",&cpt->data);
            cpt->next=ptr->next;
            ptr->next=cpt;
            printf("Data %d is Inserted",cpt->data);
        }
    }
}
void insertend(struct node ***newfirst)
{
    struct node *ptr,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->next=NULL;
        ptr->next=cpt;
        printf("Data %d is Inserted",cpt->data);
    }
}
void deletebeg(struct node ***newfirst)
{
    struct node *ptr,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        cpt=ptr->next;
        **newfirst=cpt;
        ptr->next=NULL;
        printf("Data Deleted : %d",ptr->data);
        free(ptr);
    }
}
void deletemid(struct node ***newfirst)
{
    int num;
    struct node *ptr,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        printf("Enter Data you want to delete : ");
        scanf("%d",&num);
        while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                break;
            }
            cpt=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("Data %d is not Found",num);
        }
        else
        {
            cpt->next=ptr->next;
            ptr->next=NULL;
            printf("Data Deleted : %d",ptr->data);
            free(ptr);
        }
    }
}
void deleteend(struct node ***newfirst)
{
    struct node *ptr,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        while(ptr->next!=NULL)
        {
            cpt=ptr;
            ptr=ptr->next;
        }
        cpt->next=NULL;
        printf("Data Deleted : %d",ptr->data);
        free(ptr);
    }
}
void sorting(struct node ***newfirst)
{
    int temp;
    struct node *ptr,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            cpt=ptr->next;
            while(cpt!=NULL)
            {
                if(ptr->data>cpt->data)
                {
                    temp=ptr->data;
                    ptr->data=cpt->data;
                    cpt->data=temp;
                }
                    cpt=cpt->next;
            }
            ptr=ptr->next;
        }
    }
}
void reverse(struct node ***newfirst)
{
    struct node *ptr,*tpt,*cpt;
    ptr=**newfirst;
    if(ptr==NULL)
    {
        printf("\nLink List is Empty");
    }
    else
    {
        tpt=NULL;
        while(ptr!=NULL)
        {
            cpt=ptr->next;
            ptr->next=tpt;
            tpt=ptr;
            ptr=cpt;
        }
        **newfirst=tpt;
    }
}
void print(struct node ***newfirst)
{
    struct node *ptr;
    ptr=(**newfirst);
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        printf("\n");
        do
        {
            printf(" %d",ptr->data);
            ptr=ptr->next;
        }while(ptr!=NULL);
        printf("\n");
    }
}

