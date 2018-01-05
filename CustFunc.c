#include "header.c"
#include "CustStruct.c"

int randomid()
{
  srand(time(NULL));
  int r = rand();
  return(r);
}

/*Four functions to check if workshops are full or empty*/
int twovehiclefull(cQueue *q)
{
    if(q->twovehiclecount==MAX)
        return 1;
    else
        return 0;
}

int fourvehiclefull(cQueue *q)
{
    if(q->fourvehiclecount==MAX)
        return 1;
    else
        return 0;
}

int fourvehicleempty(cQueue *q)
{
    if(q->fourvehiclecount==0)
        return 1;
    else
        return 0;
}
int twovehicleempty(cQueue *q)
{
    if(q->twovehiclecount==0)
        return 1;
    else
        return 0;
}

/*Function to input the customer details and choose the servicing options
required of a 4-wheeler. Customer structure is stored in circular queue.*/
void fourjoblist(cQueue *fourPtr)
{
    int ch,r;
    int done;

    if(fourvehiclefull(fourPtr))
    {
        printf("\n\t\t\t\t\t\t\t\t\t Workshop is full\n");
        return;
    }

    struct customer data;
    data.jobcount=0;
    data.time=0;
    system("clear");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t **************  Four Wheeler Entry  **************\n");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t Enter Name      : ");
    scanf("%s",data.name);
    printf("\t\t\t\t\t\t\t\t\t Enter Mobile no : ");
    scanf("%s",data.mobno);
    printf("\t\t\t\t\t\t\t\t\t Enter Plateno   : ");
    scanf("%s",data.plateno);
    printf("\t\t\t\t\t\t\t\t\t Enter Chasis no : ");
    scanf("%d",&data.vehicleid);
    r=randomid();
    data.custid=r;

    fp=fopen("four.txt","a");
    fprintf(fp,"%d %s %s %s %d\n",data.custid,data.name,data.mobno,data.plateno,data.vehicleid);
    fclose(fp);
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t Your Job ID is  : %d\n",data.custid);
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t Keep it for future reference!!\n");

    printf("\t\t\t\t\t\t\t\t\t Thank You for the details\n");
    printf("\n\t\t\t\t\t\t\t\t\t ><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t\t\t\t\t\t\t\t\t Let's get you to servicing\n");

    printf("\n\t\t\t\t\t\t\t\t\t 1.Washing\n");
    printf("\t\t\t\t\t\t\t\t\t 2.Change Engine Oil\n");
    printf("\t\t\t\t\t\t\t\t\t 3.Inspect Suspension\n");
    printf("\t\t\t\t\t\t\t\t\t 4.Replace Spark Plug\n");
    printf("\t\t\t\t\t\t\t\t\t 5.Check Wheel Alignment\n");
    printf("\t\t\t\t\t\t\t\t\t 6.Seat Lamination\n");
    printf("\t\t\t\t\t\t\t\t\t 7.Dent Fixing\n");
    printf("\t\t\t\t\t\t\t\t\t 8.Carborator Cleaning\n");
	do
    {
            printf("\n\t\t\t\t\t\t\t\t\t Services Required : ");
            printf("\n\t\t\t\t\t\t\t\t\t Your Choice : ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Washing/Detailing");
                    data.time=data.time+20;
                    data.cost[data.jobcount]=100;
                    break;

            case 2:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Change Engine Oil");
                    data.time=data.time+30;
                    data.cost[data.jobcount]=250;
                    break;

            case 3:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Inspect Suspension");
                    data.time=data.time+15;
                    data.cost[data.jobcount]=200;
                    break;

            case 4:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Replace Spark Plug");
                    data.time=data.time+40;
                    data.cost[data.jobcount]=300;
                    break;

            case 5:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Check Wheel Alignment");
                    data.time=data.time+20;
                    data.cost[data.jobcount]=350;
                    break;


            case 6:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Seat Cover");
                    data.time=data.time+120;
                     data.cost[data.jobcount]=1000;
                    break;


            case 7:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Dent Fixing");
                    data.time=data.time+70;
                    data.cost[data.jobcount]=800;
                    break;


            case 8:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Carborator Cleaning");
                    data.time=data.time+90;
                    data.cost[data.jobcount]=600;
                    break;
            }

            ++data.jobcount;
            printf("\t\t\t\t\t\t\t\t\t Add another Service [1].Yes  [2].No\n");
            printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
            scanf("%d",&done);

   }while(done==1 && data.jobcount<8);
   printf("\n\t\t\t\t\t\t\t\t\t Park your vehicle in the workshop\n");                                                            //extra

    fourPtr->rear=(fourPtr->rear+1)%MAX;
    fourPtr->cardata[fourPtr->rear]=data;
    fourPtr->fourvehiclecount++;
    if(fourPtr->fourvehiclecount==1)
    fourPtr->front=0;

}
/*Function to input the customer details and choose the servicing options required of a 2-wheeler. Customer structure is stored in circular queue.*/
void twojoblist(cQueue *twoPtr)
{
    int ch,r;
    int done;

    if(twovehiclefull(twoPtr))
    {
        printf("\n\t\t\t\t\t\t\t\t\t Workshop is full\n");
        return;
    }

    struct customer data;
    data.jobcount=0;
    data.time=0;
    system("clear");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t *************** Two Wheeler Entry  ***************\n");
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t Enter Name      : ");
    scanf("%s",data.name);
    printf("\t\t\t\t\t\t\t\t\t Enter Mobile no : ");
    scanf("%s",data.mobno);
    printf("\t\t\t\t\t\t\t\t\t Enter Plateno   : ");
    scanf("%s",data.plateno);
    printf("\t\t\t\t\t\t\t\t\t Enter Chasis no : ");
    scanf("%d",&data.vehicleid);
    r=randomid();
    data.custid=r;


    fp=fopen("two.txt","a");
    fprintf(fp,"%d %s %s %s %d\n",data.custid,data.name,data.mobno,data.plateno,data.vehicleid);
    fclose(fp);

    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t Your Job ID is  : %d\n",data.custid);
    printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t Keep it for future reference!!\n");

    printf("\t\t\t\t\t\t\t\t\t Thank You for the details\n");
    printf("\t\t\t\t\t\t\t\t\t ><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t\t\t\t\t\t\t\t\t Let's get you to servicing\n");


    printf("\n\t\t\t\t\t\t\t\t\t 1.Washing\n");
    printf("\t\t\t\t\t\t\t\t\t 2.Chain Lubrication\n");
    printf("\t\t\t\t\t\t\t\t\t 3.Engine Fluse\n");
    printf("\t\t\t\t\t\t\t\t\t 4.Inspect Carborator\n");
    printf("\t\t\t\t\t\t\t\t\t 5.Inspect Battery\n");
    printf("\t\t\t\t\t\t\t\t\t 6.Seat Lamination\n");
    printf("\t\t\t\t\t\t\t\t\t 7.Dent Fixing\n");
    printf("\t\t\t\t\t\t\t\t\t 8.Carborator Cleaning\n");
	do
    {
            printf("\n\t\t\t\t\t\t\t\t\t Services Required : ");
            printf("\n\t\t\t\t\t\t\t\t\t Your Choice : ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Washing/Detailing");
                    data.time=data.time+15;
                    data.cost[data.jobcount]=100;
                    break;

            case 2:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Chain Lubrication");
                    data.time=data.time+10;
                     data.cost[data.jobcount]=250;
                    break;

            case 3:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Engine Fluse");
                    data.time=data.time+30;
                     data.cost[data.jobcount]=200;
                    break;

            case 4:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Inspect Carborator");
                    data.time=data.time+20;
                     data.cost[data.jobcount]=300;
                    break;

            case 5:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Inspect Battery");
                    data.time=data.time+15;
                     data.cost[data.jobcount]=350;
                    break;

            case 6:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Seat Lamination");
                    data.time=data.time+25;
                     data.cost[data.jobcount]=1000;
                    break;


            case 7:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Dent Fixing");
                    data.time=data.time+30;
                     data.cost[data.jobcount]=800;
                    break;


            case 8:
                    printf("\t\t\t\t\t\t\t\t\t Added To the job Card\n");
                    strcpy(data.jobs[data.jobcount],"Carborator Cleaning");
                    data.time=data.time+40;
                     data.cost[data.jobcount]=600;
                    break;
            }

            ++data.jobcount;
            printf("\t\t\t\t\t\t\t\t\t Add another Service [1].Yes  [2].No\n");
            printf("\t\t\t\t\t\t\t\t\t Your Choice : ");
            scanf("%d",&done);

    }while(done==1 && data.jobcount<8);

    printf("\n\t\t\t\t\t\t\t\t\t Park your vehicle in the workshop\n");

    twoPtr->rear=(twoPtr->rear+1)%MAX;
    twoPtr->bikedata[twoPtr->rear]=data;
    twoPtr->twovehiclecount++;
    if(twoPtr->twovehiclecount==1)
    twoPtr->front=0;
}

/*Function to generate a Job Card of 2-wheeler using the customer id. Job Card displays only the services and not the cost.*/
int generatetwojobcard(cQueue *twoPtr,int id)
{
    int i,j;
    int flag=0;
    j=twoPtr->front;
    for(i=0;i<twoPtr->twovehiclecount;i++)
    {
        if(twoPtr->bikedata[j].custid==id)
        {
         system("clear");
         printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
         printf("\n\t\t\t\t\t\t\t\t\t ********************  JOB CARD  *********************\n");
         printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
         printf("\t\t\t\t\t\t\t\t\t Name      : %s\t\t  Plate No  : %s\n\n\t\t\t\t\t\t\t\t\t Mobile No : %s\t\t  Chasis No : %d\n ",twoPtr->bikedata[j].name,twoPtr->bikedata[j].plateno,twoPtr->bikedata[j].mobno,twoPtr->bikedata[j].vehicleid);
         printf("\n\t\t\t\t\t\t\t\t\t ------------------------------------------------------\n");
         printf("\t\t\t\t\t\t\t\t\t ><><><><><><><> Jobs Requested  <><><><><><><><><><><>");
         printf("\n\t\t\t\t\t\t\t\t\t ------------------------------------------------------");

        for(i=0;i<twoPtr->bikedata[j].jobcount;i++)
        {
        printf("\n\t\t\t\t\t\t\t\t\t %d] %s\n",(i+1),twoPtr->bikedata[j].jobs[i]);
        }
        flag=1;
        }
        j=(j+1)%MAX;
    }

    printf("\n");


    return flag;
}

/*Function to generate a Job Card for 4-wheeler using the customer id. Job Card displays only the services and not the cost.*/
int generatefourjobcard(cQueue *fourPtr,int id)
{
    int i,j;
    int flag=0;
    j=fourPtr->front;
    for(i=0;i<fourPtr->fourvehiclecount;i++)
    {
        if(fourPtr->cardata[j].custid==id)
        {
        system("clear");
        printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t ********************  JOB CARD  *********************\n");
        printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t Name      : %s\t\t  Plate No  : %s\n\n\t\t\t\t\t\t\t\t\t Mobile No : %s\t\t  Chasis No : %d\n ",fourPtr->cardata[j].name,fourPtr->cardata[j].plateno,fourPtr->cardata[j].mobno,fourPtr->cardata[j].vehicleid);
        printf("\n\t\t\t\t\t\t\t\t\t ------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t ><><><><><><><> Jobs Requested  <><><><><><><><><><><>");
        printf("\n\t\t\t\t\t\t\t\t\t ------------------------------------------------------");

        for(i=0;i<fourPtr->cardata[j].jobcount;i++)
        {
            printf("\n\t\t\t\t\t\t\t\t\t %d] %s\n",(i+1),fourPtr->cardata[j].jobs[i]);
        }
        flag=1;
        }
        j=(j+1)%MAX;
    }

    printf("\n");

    return flag;
}

/*Function to service a 4-wheeler  vehicle that is on top of the queue*/
void fourwheelerprocess(cQueue *q)
{
    struct customer n;
    if(fourvehicleempty(q))
    {
        printf("\n\t\t\t\t\t\t\t\t\t All the Vehicles have been serviced\n");
        return;
    }
    n=q->cardata[q->front];
    q->fourvehiclecount--;
    if((q->front)==(q->rear))
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        q->front=(q->front+1)%MAX;
    }
     system("clear");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t **************** Servicing a Vehicle *****************\n");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t Customer ID :%d\n",n.custid);
     printf("\t\t\t\t\t\t\t\t\t Customer Name :%s\n",n.name);
     printf("\t\t\t\t\t\t\t\t\t Your car is ready\n");
}

/*Function to service a 2-wheeler vehicle that is on top of the queue*/
void twowheelerprocess(cQueue *q)
{
    struct customer n;
    if(twovehicleempty(q))
    {
        printf("\n\t\t\t\t\t\t\t\t\t All the Vehicles have been serviced\n");
        return;
    }
    n=q->bikedata[q->front];
    q->twovehiclecount--;
    if((q->front)==(q->rear))
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        q->front=(q->front+1)%MAX;
    }
     system("clear");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t **************** Servicing a Vehicle *****************\n");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t Customer ID :%d\n",n.custid);
     printf("\t\t\t\t\t\t\t\t\t Customer Name :%s\n",n.name);
     printf("\t\t\t\t\t\t\t\t\t Your bike is ready\n");
}

/*Function to check estimated time remaining to service a 4-wheeler vehicle*/
int fourEstimatedTime(cQueue *fourPtr,int id)
{
    int i,j;
    int flag=0;
    int totaltime=0;
    int hours,minutes;
    j=fourPtr->front;
    for(i=0;i<fourPtr->fourvehiclecount;i++)
    {
        totaltime=totaltime+fourPtr->cardata[j].time;
        if(fourPtr->cardata[j].custid==id)
        {
            flag=1;
            break;
        }
        j=(j+1)%MAX;
    }
    hours=totaltime/60;
    minutes=totaltime%60;
    if(flag==1)
    {
     system("clear");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t *****************  Estimated Time  ******************\n");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t Estimated Time : %d hours %d minutes\n",hours,minutes);
    }
    return flag;
}

/*Function to check estimated time remaining to service a 2-wheeler vehicle*/
int twoEstimatedTime(cQueue *twoPtr,int id)
{
    int i,j;
    int flag=0;
    int totaltime=0;
    int hours,minutes;
    j=twoPtr->front;
    for(i=0;i<twoPtr->twovehiclecount;i++)
    {
        totaltime=totaltime+twoPtr->bikedata[j].time;
        if(twoPtr->bikedata[j].custid==id)
        {
            flag=1;
            break;
        }
        j=(j+1)%MAX;
    }
    hours=totaltime/60;
    minutes=totaltime%60;
    if(flag==1)
    {
     system("clear");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t *****************  Estimated Time  ******************\n");
     printf("\n\t\t\t\t\t\t\t\t\t -----------------------------------------------------\n");
     printf("\n\t\t\t\t\t\t\t\t\t Estimated Time : %d hours %d minutes\n",hours,minutes);
    }
     return flag;
}

/*Function to generate the invoice of 4-wheeler*/
int generatefourinvoice(cQueue *fourPtr, int id)
{
    int i,j;
    int flag=0;
    j=fourPtr->front;
    for(i=0;i<fourPtr->fourvehiclecount;i++)
    {
        if(fourPtr->cardata[j].custid==id)
        {
        system("clear");
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t *************** Generating Invoice ***************\n");
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t Name      : %s\t\t  Plate No  : %s\n\n\t\t\t\t\t\t\t\t\t Mobile No : %s\t\t  Chasis No : %d\n ",fourPtr->cardata[j].name,fourPtr->cardata[j].plateno,fourPtr->cardata[j].mobno,fourPtr->cardata[j].vehicleid);
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t ><><><><><><><>  Jobs Completed   <><><><><><><><><>");
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------");

        for(i=0;i<fourPtr->cardata[j].jobcount;i++)
        {
        printf("\n\t\t\t\t\t\t\t\t\t %d. %s\t\t\t Rs. %d\n",(i+1),fourPtr->cardata[j].jobs[i],fourPtr->cardata[j].cost[i]);
        }
        flag=1;
        }
        j=(j+1)%MAX;
    }

    printf("\n");

    return flag;
}

/*Function to generate the invoice of 2-wheeler*/
int generatetwoinvoice(cQueue *twoPtr, int id)
{
    int i,j;
    int flag=0;
    j=twoPtr->front;
    for(i=0;i<twoPtr->twovehiclecount;i++)
    {
        if(twoPtr->bikedata[j].custid==id)
        {
        system("clear");
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t *************** Generating Invoice ***************\n");
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t Name      : %s\t\t  Plate No  : %s\n\n\t\t\t\t\t\t\t\t\t Mobile No : %s\t\t  Chasis No : %d\n ",twoPtr->bikedata[j].name,twoPtr->bikedata[j].plateno,twoPtr->bikedata[j].mobno,twoPtr->bikedata[j].vehicleid);
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t ><><><><><><><>  Jobs Completed   <><><><><><><><><>");
        printf("\n\t\t\t\t\t\t\t\t\t --------------------------------------------------");

        for(i=0;i<twoPtr->bikedata[j].jobcount;i++)
        {
        printf("\n\t\t\t\t\t\t\t\t\t %d] %s\t\t\t Rs. %d\n",(i+1),twoPtr->bikedata[j].jobs[i],twoPtr->bikedata[j].cost[i]);
        }
        flag=1;
        }
        j=(j+1)%MAX;
    }

    printf("\n");

    return flag;
}