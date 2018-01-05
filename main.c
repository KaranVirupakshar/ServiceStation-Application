#include "header.c"
#include "CustFunc.c"
#include "EmpFunc.c"
int main()
{
  
    cQueue tempFour;
    cQueue tempTwo;

    cQueue *fourPtr;
    cQueue *twoPtr;

    fourPtr=&tempFour;
    twoPtr=&tempTwo;

    fourPtr->front=-1;
    fourPtr->rear=-1;
    fourPtr->fourvehiclecount=0;

    twoPtr->front=-1;
    twoPtr->rear=-1;
    twoPtr->twovehiclecount=0;

    struct customer d;
    node *top=NULL;
    //top=fillingLL(top);
    fillingLL(&top);
    int type,num,done=1,choice,cid,fourcheck=0,twocheck=0,ch,op;
 
l1: system("clear");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t ************** ServoSoft Main Menu  **************\n");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");

    printf("\t\t\t\t\t\t\t\t\t 1] Customer Management\n");
    printf("\n\t\t\t\t\t\t\t\t\t 2] Employee Management\n");
    printf("\n\t\t\t\t\t\t\t\t\t 3] Log Out\n");
    printf("\n\t\t\t\t\t\t\t\t\t Your Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {

       case 1:l4: system("clear");
               printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
               printf("\n\t\t\t\t\t\t\t\t\t ************** Customer Management  **************\n");
               printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
               printf("\t\t\t\t\t\t\t\t\t 1] Servicing Entry\n");
               printf("\n\t\t\t\t\t\t\t\t\t 2] Generate Job Card\n");
               printf("\n\t\t\t\t\t\t\t\t\t 3] Estimated Time\n");
               printf("\n\t\t\t\t\t\t\t\t\t 4] Generate Invoice\n");
               printf("\n\t\t\t\t\t\t\t\t\t 5] Service a Vehicle\n");
               printf("\n\t\t\t\t\t\t\t\t\t 0] Back to Main Menu\n");
               printf("\n\t\t\t\t\t\t\t\t\t Your Choice : ");
               scanf("%d",&ch);
               switch(ch)
                {
                    case 1:
                    l2:   system("clear");
                          printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t **************   Servicing Entry   **************\n");
                          printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                          printf("\t\t\t\t\t\t\t\t\t 1] Four-Wheeler Entry\n");
                          printf("\n\t\t\t\t\t\t\t\t\t 2] Two-Wheeler Entry\n");
                          printf("\n\t\t\t\t\t\t\t\t\t 0] Back to Previous Menu\n");
                          printf("\n\t\t\t\t\t\t\t\t\t Your Choice : ");

                          scanf("%d",&type);
                          printf("\n");
                          switch(type)
                            {
                                case 1:
                                fourjoblist(fourPtr);
                                break;

                                case 2:
                                twojoblist(twoPtr);
                                break;

                                case 0:
                                goto l4;
                            }
                        printf("\n\t\t\t\t\t\t\t\t\t Another Vehicle [1].Yes  [2].No\n");
                        printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                        scanf("%d",&done);
                        if(done==2)
                        goto l4;
                        if(done==1)
                        goto l2;
                        break;

                    case 2:

                    l3:   system("clear");
                          printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t ************** Generating Job Card **************\n");
                          printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t Enter Customer Id: ");

                          scanf("%d",&cid);
                          fourcheck=generatefourjobcard(fourPtr,cid);
                          twocheck=generatetwojobcard(twoPtr,cid);

                          if((fourcheck==0)&&(twocheck==0))
                          printf("\t\t\t\t\t\t\t\t\t Customer ID not found\n");
                          printf("\n\t\t\t\t\t\t\t\t\t Another Job Card[1].Yes  [2].No\n");
                          printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                          scanf("%d",&done);
                          if(done==2)
                          goto l4;
                          if(done==1)
                          goto l3;
                          break;

                    case 5:
                         l10: system("clear");
                          int z;
                          printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t **************** Servicing a Vehicle *****************\n");
                          printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t 1] Process Four Wheeler\n");
                          printf("\n\t\t\t\t\t\t\t\t\t 2] Process Two Wheeler\n");
                          printf("\n\t\t\t\t\t\t\t\t\t Your Choice : ");
                          scanf("%d",&z);
                          if(z==1)
                          {
                          fourwheelerprocess(fourPtr);
                          printf("\n\t\t\t\t\t\t\t\t\t Another Servicing[1].Yes  [2].No\n");
                          printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                          scanf("%d",&done);
                          if(done==2)
                          goto l4;
                          if(done==1)
                          goto l10;
                          }
                          else
                          {
                          twowheelerprocess(twoPtr);
                          printf("\n\t\t\t\t\t\t\t\t\t Another Servicing[1].Yes  [2].No\n");
                          printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                          scanf("%d",&done);
                          if(done==2)
                          goto l4;
                          if(done==1)
                           goto l10;
                          }
                          break;

                    case 3:
                     l21 :system("clear");
                          printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t *****************  Estimated Time  ******************\n");
                          printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t Enter Customer Id: ");
                          scanf("%d",&cid);
                          fourcheck=fourEstimatedTime(fourPtr,cid);
                          twocheck=twoEstimatedTime(twoPtr,cid);

                          if((fourcheck==0)&&(twocheck==0))
                          printf("\n\t\t\t\t\t\t\t\t\t Customer ID not found\n");

                          printf("\n\t\t\t\t\t\t\t\t\t Another Customer[1].Yes  [2].No\n");
                          printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                          scanf("%d",&done);
                          if(done==2)
                          goto l4;
                          if(done==1)
                          goto l21;
                          break;

                    case 4:
                    l31 : system("clear");
                          printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t *************** Generating Invoice ***************\n");
                          printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                          printf("\n\t\t\t\t\t\t\t\t\t Enter Customer Id: ");
                          scanf("%d",&cid);
                          fourcheck=generatefourinvoice(fourPtr,cid);
                          twocheck=generatetwoinvoice(twoPtr,cid);

                          if((fourcheck==0)&&(twocheck==0))
                          printf("\n\t\t\t\t\t\t\t\t\t Customer ID not found\n");

                          printf("\n\t\t\t\t\t\t\t\t\t Another Customer[1].Yes  [2].No\n");
                          printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                          scanf("%d",&done);
                          if(done==2)
                          goto l4;
                          if(done==1)
                          goto l31;
                          break;

                    case 0:
                          goto l1;
                          break;

                    default:
                          printf("\n\t\t\t\t\t\t\t\t\t Wrong Choice \n");
            }
        break;

                    case 2:l44: system("clear");
                printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                printf("\n\t\t\t\t\t\t\t\t\t ************** Employee Management  **************\n");
                printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                printf("\t\t\t\t\t\t\t\t\t 1] Hire an employee\n");
                printf("\n\t\t\t\t\t\t\t\t\t 2] Fire an employee\n");
                printf("\n\t\t\t\t\t\t\t\t\t 3] Search for an Employee\n");
                printf("\n\t\t\t\t\t\t\t\t\t 4] Pay Bonus\n");
                printf("\n\t\t\t\t\t\t\t\t\t 5] See employee list\n");
                printf("\n\t\t\t\t\t\t\t\t\t 0] Back to Main Menu\n");
                printf("\n\t\t\t\t\t\t\t\t\t Your choice : ");
                scanf("%d",&op);
                switch(op)
                {
                    case 0:
                         goto l1;
                         break;

                    case 1:
                     l45:
                         top=CreateEmp(top);
                         printf("\n\t\t\t\t\t\t\t\t\t Another Employee[1].Yes  [2].No\n");
                         printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                         scanf("%d",&done);
                         if(done==2)
                         goto l44;
                         if(done==1)
                         goto l45;
                         break;

                    case 2:
                      l46:
                         top=firing(top);
                         printf("\n\t\t\t\t\t\t\t\t\t Another Employee[1].Yes  [2].No\n");
                         printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                         scanf("%d",&done);
                         if(done==2)
                         goto l44;
                         if(done==1)
                         goto l46;
                         break;

                    case 3:
                       l47: system("clear");
                        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                        printf("\n\t\t\t\t\t\t\t\t\t *************** Searching Employee ***************\n");
                        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                        printf("\n\t\t\t\t\t\t\t\t\t Employee id : ");
                        scanf("%d",&num);
                        Display(top,num);
                      printf("\n\t\t\t\t\t\t\t\t\t Another Employee[1].Yes [2]. No\n");
			printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                        scanf("%d",&done);
			if(done==1)
                           goto l47;
			else
			   goto l44;
                        break;

                    case 4:
                       l48: system("clear");
                        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                        printf("\n\t\t\t\t\t\t\t\t\t *************** Bonus an Employee  ***************\n");
                        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
                        printf("\t\t\t\t\t\t\t\t\t Employee id : ");
                        scanf("%d",&num);
                        PayBonus(num,top);
                        printf("\n\t\t\t\t\t\t\t\t\t Another Employee[1].Yes [2]. No\n");
			printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                        scanf("%d",&done);
			if(done==1)
                           goto l48;
			else
			   goto l44;
                        break;

                    case 5:

                        displaylist(top);
                        printf("\n\t\t\t\t\t\t\t\t\t [1].Go Back [2]. Main Menu\n");
			 printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                         scanf("%d",&done);
			if(done==1)
                           goto l44;
			else
			   goto l1;
                        break;

                    default:
                        printf("\n\t\t\t\t\t\t\t\t\t Invalid choice\n");
                        printf("\n\t\t\t\t\t\t\t\t\t [1].Go Back [2]. Main Menu\n");
			printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
                        scanf("%d",&done);
			if(done==1)
                           goto l44;
			else
			   goto l1;
                        break;
                }
        case 3:
	    system("clear");
            exit(1);
            break;

        default:
            printf("\n\t\t\t\t\t\t\t\t\t Invalid choice\n");
            exit(1);
	

  }
}
