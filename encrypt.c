/*******************************************************************************************************************************/
/**************TOPIC:-PROGRAM FOR ENCRYPTION AND DECRYPTION*********************************************************************/
/**************MADE BY:-DURBAR DASGUPTA........................*********************************************************************/
/*******************************************************************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>

COORD coord={0,0};
void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void delay(unsigned int msec)
{
    clock_t goal =msec +clock();
    while(goal>clock());
}
struct matrix
{
    long int A[2][2];
};
void main()
{
    int choice,i,count=0;
    system("COLOR 72");
    printf("Application is Initializing");
    for(i=0;i<15;i++)
    {
        if(i==14)
        {
            count++;
            i=0;
            system("cls");
            printf("Application is Initializing");
        }
        if(count == 4)
        {
            printf("...............");
            break;
        }
        printf(".");
        delay(100);
    }
    FILE *p;

    label2:                     /*used for default case if person presses something different than 1 or 2*/
    gotoxy(25,10);
    printf("WELCOME TO THE PROJECT");
    gotoxy(25,11);
    printf("Press enter to continue..........");
    getch();
    system("cls");
    label:
    system("COLOR 71");
    gotoxy(10,1);
    printf("THIS PROGRAM IS USED FOR ENCRYPTION AND DECRYPTION OF DATA");
    gotoxy(2,4);
    printf("WHAT DO YOU WANT TO DO");
    gotoxy(2,6);
    printf("1.ENCRYPT THE DATA");
    gotoxy(2,8);
    printf("2.DECRYPT THE DATA");
    gotoxy(2,10);
    printf("ENTER HERE : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:{
            system("cls");
            system("COLOR 74");
            char con;
            fflush(stdin);

        long int i,m,j,k,p=0,pass[2][2],n,sum=0,test;

        char *str,*tes,c;
        int capacity=0,counts=0;
        str=(char *)calloc(capacity,sizeof(char));
        gotoxy(22,1);
        printf("WELCOME TO ENCRYPTION OF DATA");
        gotoxy(2,3);
        printf("ENTER DATA TO BE ENCRYPT : ");
        while((c=getchar())!='\n')
        {
            if(counts>=capacity)
            {
                capacity=capacity+2;
                tes=(char *)realloc(str,capacity*sizeof(char));
                str=tes;
            }
            str[counts++]=c;
        }
        str[counts]='\0';
        if((strlen(str))%4 == 0)
            m=(strlen(str))/4;
        else
            m=((strlen(str))/4)+1;
        struct matrix mat[m],multi[m];
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<2;k++)
                {
                    if(j==1 && k==0)
                        test=3;
                    else if(j==0 && k==1)
                        test=2;
                    else if(j==0 && k==0)
                        test=1;
                    else
                        test=4;
                    if(i==(m-1) && ((i*4)+test)>strlen(str))
                        mat[i].A[j][k]=32;
                    else
                    {
                        mat[i].A[j][k]=str[p];
                        p++;
                    }
                }
            }
        }
        fflush(stdin);
        gotoxy(2,5);
        printf("ENTER PASSWARD (2 X 2) MATRIX");

        int pasx=2,pasy=7;
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                gotoxy(pasx,pasy);
                scanf("%ld",&pass[j][k]);
                pasx=5;
            }
            pasx=2;pasy=9;
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<2;k++)
                {
                    for(n=0;n<2;n++)
                        sum=sum+(mat[i].A[j][n])*pass[n][k];
                        multi[i].A[j][k]=sum;
                        sum=0;
                }
            }

        }
        fflush(stdout);
        gotoxy(2,11);
        printf("ENTER THE NAME OF THE FILE IN WHICH YOU WANT TO LOAD THE CIPHER : ");
        char in[10];
        int integer;
        gotoxy(68,11);
        scanf("%s",in);
        p=fopen(in,"w");
        gotoxy(2,13);
        printf("YOUR CIPHER TEXT IS : ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<2;k++)
                {
                    printf("%ld   ",multi[i].A[j][k]);
                    integer=multi[i].A[j][k];
                    fprintf(p,"%d",integer);
                    fprintf(p," ");
                }
            }
        }
        fflush(stdin);
        fclose(p);
        gotoxy(20,17);
        printf("DO YOU WANT TO CONTINUE (Y or N) : ");
        scanf("%c",&con);

        if(con=='y' || con=='Y')
        {
            system("cls");
            goto label;
        }
        break;}
        case 2:{
            system("cls");
            system("COLOR 74");
            long int i,j,k,n,t=0,pass[2][2],m=0,sum=0,no_of_elements;
            double inpass[2][2],det;
            char str[200];
            gotoxy(23,1);
            printf("WELCOME TO DECRYPTION OF DATA");

            gotoxy(2,3);
            printf("ENTER THE NAME OF THE FILE FROM WHICH CIPHER HAVE TO BE LOADED : ");
            char in[10];
            int out;
            gotoxy(68,3);
            scanf("%s",in);
            p=fopen(in,"r");
            fflush(stdin);
            fseek(p,0,SEEK_END);
            m=ftell(p);
            rewind(p);


            m=m/16;
            struct matrix mate[m],multie[m];
            for(i=0;i<m;i++)
            {
                for(j=0;j<2;j++)
                {
                    for(k=0;k<2;k++)
                    {
                        fscanf(p,"%d",&out);

                            mate[i].A[j][k]=out;

                    }

                }
            }
        gotoxy(2,5);
        printf("ENTER PASSWORD (2 X 2) MATRIX");
        int pasx=2,pasy=7;
        fflush(stdin);
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                gotoxy(pasx,pasy);
                scanf("%ld",&pass[j][k]);
                pasx=6;
            }
            pasx=2;pasy=9;
        }
        det=((pass[0][0] * pass[1][1])-(pass[0][1] * pass[1][0]));
        inpass[0][0]=((float)pass[1][1]/det);
        inpass[0][1]=(float)(0-(pass[0][1]/det));
        inpass[1][0]=(float)(0-(pass[1][0]/det));
        inpass[1][1]=(float)(pass[0][0]/det);
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<2;k++)
                {
                    for(n=0;n<2;n++)
                        sum=sum+((mate[i].A[j][n])*inpass[n][k]);
                        multie[i].A[j][k]=sum;
                        sum=0;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
                for(k=0;k<2;k++)
                {
                    str[t]=multie[i].A[j][k];
                    t++;
                }

            }
        }
        str[t]='\0';
        gotoxy(2,11);
        printf("YOUR ORIGINAL DATA IS : ");
        puts(str);
        gotoxy(22,18);
        char con;
        printf("DO YOU WANT TO CONTINUE (Y OR N) : ");
        fflush(stdin);
        scanf("%c",&con);
        if(con=='y' || con=='Y')
        {
            system("cls");
            goto label;
        }
        break;
    }
        default:
            {
                system("cls");
                printf("You have pressed wrong option\nPlease try again............");
                goto label2;
            }
    }
    system("cls");
    system("COLOR FC");
    gotoxy(23,10);
    printf("THANKYOU FOR USING THIS PROGRAM");
    getch();
}
