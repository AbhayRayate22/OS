#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int choice,track,no_req,head,head1,distance;
int disc_req[100],finish[100];
void menu()
{
    printf("\n\n********MENU********");
    printf("\n1. Input data \n 2. SCAN \n 3. Exit");
    printf("\n\n Enter your choice");
    scanf("%d",&choice);
}
void input()
{
    int i;
    printf("Enter Total number of tracks");
    scanf("%d",&track);
    printf("Enter total number of disc requests");
    scanf("%d",&no_req);
    printf("\n Enter disc requests in FCFS order");
    for(i=0;i<no_req;i++)
    {
        scanf("%d",&disc_req[i]);
        
    }
    printf("\n Enter current head position");
    scanf("%d",&head1);

}
void scan()
{
    int index,dir;
    int i;
    distance=0;
    head=head1;
    printf("\n Enter the direction of head \n 1 - Towars higher disc(Right) \n 0 -towards lower disc(left)");
    scanf("%d",&dir);
    //sort();
    printf("\n Sorted Disc requests are: ");
    for(i=0;i<no_req;i++)
    {
        
        printf("  %d",disc_req[i]);
    }
    
    i=0;
    while(head>=disc_req[i])
    {
        index=i;
        i++;
    }
    printf("\n index=%d",index);
    printf("\n%d=>",head);
    if(dir==1)
    {
        for(i=index+1;i<no_req;i++)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        distance+=abs(head-(track-1));
        printf("%d=>",track-1);
        head=track-1;
        for(i=index;i>=0;i--)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
    }
    else
    {
        for(i=index;i>=0;i--)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        distance+=abs(head-0);
        head=0;
        printf("0=>");
        for(i=index+1;i<no_req;i++)
        {
            printf("%d=>",disc_req[i]);
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        
    }
    printf("End");
    printf("\n Total Distance Traversed=%d",distance);
    


}
int main()
{
    while(1)
    {
        menu();
        switch(choice)
        {
        case 1: input();
            break;
        
        case 2: scan();
            break;
     
        case 3: exit(0);       
            break;
        default:
            printf("\n Enter valid choice");
            break;
        }
    }

    return 0;
}
