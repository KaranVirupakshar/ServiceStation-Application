#include "header.c"
/*Customer Structure*/
struct cQueue
{
    struct customer
    {
        int custid;
        char name[10];
        char mobno[12];
        char plateno[20];
        int vehicleid;
        char jobs[8][30];
        int jobcount;
        int cost[8];
        int time;
    }cardata[MAX],bikedata[MAX];

    int twovehiclecount;
    int fourvehiclecount;
    int front;
    int rear;
};

typedef struct cQueue cQueue;