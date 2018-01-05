#include "header.c"
#include "EmpStruct.c"

void fillingLL(node **top)
{
    struct employee data;
    node *cur,*newnode;
    int i=1;
    fp=fopen("out.txt","r");
    while(fscanf(fp,"%d %s %s %d",&data.id,data.name,data.department,&data.salary))
    {
        cur=(node *)malloc(sizeof(node));
        cur->next=NULL;
        cur->empdata.id=data.id;
        strcpy(cur->empdata.name,data.name);
        strcpy(cur->empdata.department,data.department);
        cur->empdata.salary=data.salary;
        if(feof(fp))
            break;
        if(i==1)
        {
            *top=cur;
            newnode=*top;
            i++;
        }
        else
        {
            newnode->next=cur;
            newnode=newnode->next;
        }
    }
    fclose(fp);
}

node *CreateEmp(node *head)
{
    system("clear");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t **************** Hiring Employee  ****************\n");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    struct employee data;
    printf("\n\t\t\t\t\t\t\t\t\t Employee id              : ");
    scanf("%d",&data.id);
    printf("\t\t\t\t\t\t\t\t\t Employee name            : ");
    scanf("%s",data.name);
    printf("\t\t\t\t\t\t\t\t\t Employee Work Department : ");
    scanf("%s",data.department);
    printf("\t\t\t\t\t\t\t\t\t Enter the salary         : ");
    scanf("%d",&data.salary);
    fp=fopen("out.txt","a");
    fprintf(fp,"%d %s %s %d\n",data.id,data.name,data.department,data.salary);
    fclose(fp);
    node *newnode;
    node *temp;
    if(head==NULL)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->empdata=data;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        temp=(node*)malloc(sizeof(node));
        for(newnode=head;newnode->next!=NULL;newnode=newnode->next);
        newnode->next=temp;
        temp->empdata=data;
        temp->next=NULL;
    }
    return(head);
}

void Display(node *head,int num)
{
   struct employee empdata;
   fp=fopen("out.txt","r");
   node *cur=head;
   while(fscanf(fp,"%d %s %s %d",&empdata.id,empdata.name,empdata.department,&empdata.salary)==4)
    {
        if(empdata.id==num)
            printf("\n\t\t\t\t\t\t\t\t\t %d %s %s %d\n",empdata.id,empdata.name,empdata.department,empdata.salary);
    }
fclose(fp);
}

void PayBonus(int empid,node *head)                                                    //check
{
    node *cur;
    for(cur=head;cur!=NULL && cur->empdata.id !=empid;cur=cur->next);
    if(cur==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t ID not found...");
        return;
    }
    else
    {
        cur->empdata.salary+=1000;
    }
    fp=fopen("out.txt","w");
    struct employee data;
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        data=cur->empdata;
        fprintf(fp,"%d %s %s %d\n",data.id,data.name,data.department,data.salary);
    }
    fclose(fp);
    printf("\n\t\t\t\t\t\t\t\t\t Salary incremented...");
}

void displaylist(node *top)
{
    node *cur;
    system("clear");
    printf("\n\t\t\t\t\t\t\t\t\t ------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t ********************* Display all Employees **********************\n");
    printf("\n\t\t\t\t\t\t\t\t\t ------------------------------------------------------------------\n");
    for(cur=top;cur!=NULL;cur=cur->next)
    printf("\t\t\t\t\t\t\t\t\t\t %d %s %s %d\n",cur->empdata.id,cur->empdata.name,cur->empdata.department,cur->empdata.salary);
}

node *firing(node *head)
{
    system("clear");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t **************** Firing Employee  ****************\n");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    int i;
    node *cur,*prev;
    printf("\n\t\t\t\t\t\t\t\t\t\t Employee ID : ");
    scanf("%d",&i);
    for(prev=NULL,cur=head;cur!=NULL && cur->empdata.id!=i;prev=cur,cur=cur->next);
    if(cur==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t ID not found...\n");
        return head;
    }
    if(cur==head)
    {
        head=head->next;
        free(cur);
    }
    else
    {
        prev->next=cur->next;
        free(cur);
    }
    fp=fopen("out.txt","w");
    struct employee data;
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        data=cur->empdata;
        //fwrite(&data,sizeof(struct employee),1,fp);
        fprintf(fp,"%d %s %s %d\n",data.id,data.name,data.department,data.salary);
    }
    printf("\n\t\t\t\t\t\t\t\t\t Employee Fired!!...");
    fclose(fp);
    return head;
}
