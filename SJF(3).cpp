#include<stdio.h>
 
struct Process
{             
    int id,WT,AT,BT,TAT;
    // WT - Waiting Time
    // AT - Arrival Time
    // BT - Burst Time
    // TAT - TurnAroundTime
};
 
int main()
{
    freopen("input.txt","r",stdin);
    int n,temp[10];
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
 
    printf("Enter the number of the process\n");
    scanf("%d",&n);
     
    struct Process a[10], a1[10];
 
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT WT\n");
 
    for(int i=0;i<n;i++)
    {
        a[i].id = i+1;
        scanf("%d%d",&a[i].AT,&a[i].BT);
         
        // copying the burst time in
        // a temp array for the further use
        // in calculation of WT
        temp[i]=a[i].BT;
    }
     
    printf("\n\n Input Data:");
    printf("\n\nID \t AT \t BT \n\n");
    for(int i =0;i<n;i++)
    {
        printf("%d \t %d \t %d\n",a[i].id,a[i].AT,a[i].BT);
    }
 
    // we initialize the burst time
    // of a process with the maximum
    a[9].BT=10000;
 
    // loop will be execute until all the process
    // complete so we use count!= number of 
    // the process
 
    // t = time 
    for(t=0;count!=n;t++)
    {
        // for finding min burst
        // it is useful 
        short_P=9;
 
        for(int i=0;i<n;i++)
        {
            // If Process is shortest 
            // and process arrived and It is remain to execute i.e Burst time greater than 0
            // So assign that as shortest process
 
            if( (a[i].AT <= t && a[i].BT>0) &&  a[i].BT <= a[short_P].BT)
            {
                short_P=i; 
            }   
        }
 
        // Reduce burst time by 1 and check again
        a[short_P].BT = a[short_P].BT-1;
         
        // if any process is completed
        if(a[short_P].BT==0)
        {
            // one process complete
            a[short_P].WT= t + 1 - a[short_P].AT - temp[short_P]; 
         
            a[short_P].TAT= t + 1 - a[short_P].AT; 
             
            a1[count] = a[short_P];
 
            count++;
             
            // total calculation
            total_WT=total_WT+a[short_P].WT;
            total_TAT=total_TAT+a[short_P].TAT;
        }
 
    }
 
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
     
 
    // printing of the answer
    printf("\n\n After Applying SJF Preemptive:");
    printf("\n\nId \t AT \t BT \t WT \t TAT\n");
    for(int i=0;i<n;i++)
    {  
        printf("%d\t%d\t%d\t%d\t%d\n",a1[i].id,a1[i].AT,temp[i],a1[i].WT,a1[i].TAT);
    }
 
    printf("Avg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process %f\n",Avg_TAT);
     
}





