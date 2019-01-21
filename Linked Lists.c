// Author: Shreayan Chaudhary

#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node* insertAtBeginning(Node *head, int data)
{
    Node *newptr = (Node*)malloc(sizeof(Node));
    newptr->data = data;
    if(head==NULL)
    {
        newptr->next = NULL;
        head = newptr;
        return head;
    }
    else
    {
        newptr->next = head;
        head = newptr;
        return head;
    }
}

Node* insertAtEnd(Node *head, int data)
{
    Node *newptr = (Node*)malloc(sizeof(Node));
    newptr->data = data;
    if(head==NULL)
    {
        newptr->next = NULL;
        head = newptr;
        return head;
    }
    else
    {
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newptr;
        newptr->next = NULL;
        return head;
    }
}

Node* insertAtPos(Node *head, int data, int pos)
{
    Node *newptr = (Node*)malloc(sizeof(Node));
    newptr->data = data;
    if(head==NULL)
    {
        newptr->next = NULL;
        head = newptr;
        return head;
    }
    else
    {
        Node *temp = head;
        int i;
        for(i=0;i<pos-1;i++)
        {
            temp = temp->next;
        }
        newptr->next = temp->next;
        temp->next = newptr;
        return head;
    }
}

Node* deleteFromBeginning(Node *head)
{
    if(head==NULL)
        return head;
    else
    {
        Node *temp = head;
        temp = temp->next;
        free(head);
        head = temp;
        return head;
    }
}

Node* deleteFromEnd(Node *head)
{
    if(head==NULL)
        return head;
    else
    {
        Node *p = head;
        Node *temp;
        while(p->next!=NULL)
        {
            temp=p;
            p=p->next;
        }
        temp->next=NULL;
        free(p);
        return head;
    }
}

Node* deleteFromPos(Node *head, int pos)
{
    if(pos<=0)
        return head;
    else if(pos==1)
    {
        if(head==NULL)
            return head;
        return deleteFromBeginning(head);
    }
    Node *temp;
    Node *p = head;
    for(int i=0;i<pos-1;i++)
    {
        temp = p;
        p = p->next;
        if(p==NULL)
            return head;
    }
    temp->next=p->next;
    free(p);
    return head;
}

int countElements(Node *head)
{
	int ct=0;
	if(head==NULL)
		return 0;
	while(head!=NULL)
	{
		head = head->next;
		ct++;
	}
	return ct;
}

Node* reverse(Node *head)
{
	Node *prev, *current, *forward;
	current = head;
	prev = NULL;
	while(current!=NULL)
	{
		forward = current->next;
		current->next = prev;
		prev = current;
		current = forward;
	}
	head = prev;
	return head;
}

void display(Node *head)
{
    if(head==NULL)
        return;
    else
    {
        while(head!=NULL)
        {
            printf("%d->",head->data);
            head = head->next;
        }
        printf("\n");
    }
}


int main()
{

    int choice,subch;
    Node *head = NULL;    
    int i,ele,pos,n;
    printf("\nProgram Menu:\n");
    printf("1. Insert\n2. Delete\n3. Count number of elements in list\n4. Reverse List\n5. Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    
    do
    {
        switch(choice)
        {
            case 1: printf("\nInsert Menu:\n");
                    printf("1. Insert in the beginning \n2. Insert at the end \n3. Insert at given position \n4. Main Menu\n");
                    scanf("%d",&subch);
                    switch(subch)
                    {
                    case 1: printf("\nEnter number of elements to be inserted:");
                            scanf("%d",&n);
                            printf("\nEnter the elements to be inserted:");
                            for(i=0;i<n;i++)
                            {
                                scanf("%d",&ele);
                                head = insertAtBeginning(head, ele);
                            }
                            display(head);
                            break;
                    case 2: printf("\nEnter number of elements to be inserted:");
                            scanf("%d",&n);
                            printf("\nEnter the elements to be inserted:");
                            for(i=0;i<n;i++)
                            {
                                scanf("%d",&ele);
                                head = insertAtEnd(head, ele);
                            }
                            display(head);
                            break;
                    case 3: printf("\nEnter number of elements to be inserted:");
                            scanf("%d",&n);
                            printf("\nEnter the elements to be inserted along with their positions:");
                            for(i=0;i<n;i++)
                            {
                                scanf("%d",&ele);
                                scanf("%d",&pos);
                                head = insertAtPos(head, ele, pos);
                            }
                            display(head);
                            break;
                    case 4: break;
                    default: printf("Incorrect value entered!\n");
                    		break;
                    }
                    break;
            case 2: printf("\nDelete Menu:\n");
                    printf("1. Delete from the beginning \n2. Delete from the end \n3. Delete from given position \n4. Main Menu\n");
                    scanf("%d",&subch);
                    switch(subch)
                    {
                    case 1: printf("\nEnter number of elements to be deleted from beginning:");
                            scanf("%d",&n);
                            for(i=0;i<n;i++)
                                head = deleteFromBeginning(head);
                            display(head);
                            break;
                    case 2: printf("\nEnter number of elements to be deleted from end:");
                            scanf("%d",&n);
                            for(i=0;i<n;i++)
                                head = deleteFromEnd(head);
                            display(head);
                            break;
                    case 3: printf("\nEnter position of element to be deleted:");
                            scanf("%d",&pos);
                            head = deleteFromPos(head, pos);
                            display(head);
                            break;
                    case 4: break;        
                    default: printf("Incorrect value entered!\n");
                    		break;
                    }
                    break;
            case 3: printf("\nNumber of elements in list is: %d",countElements(head));
            		break;
            case 4: head = reverse(head);
            		break;
            default: printf("Incorrect value entered!\n");
                    break;
        }
    }while(choice!=5);
    
    return 0;
}
