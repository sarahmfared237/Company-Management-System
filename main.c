#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    int id;
    char Lname[30];
    char Fname[30];
    float salary;
    date DOB;
    char adrs[50];
    char phNo[20];
    char mail[30];
} employee;
employee employees[100];
int n=0;
void search()
{
    char sename[30];
    printf("\nPlease enter the last name: ");
    scanf("%s",sename);
    int i;
    int flag=0;
    for(i=0; i<n; i++)
    {
        if(strcasecmp(employees[i].Lname,sename)==0)
        {
            printf("\nThe data of the employee who has this last name is:\n");
            printf("---------------------------------------------------\n");
            printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
            flag=1;
        }
    }
    if(flag==0)
        printf("This name is not found\n");
}

void delet()
{
    int i,k,flag=0;
    char fname[30],lname[30];
    printf("\nEnter the first and the last name of the employee that you want to delete its data:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("The first name is: ");
    scanf("%s",fname);
    printf("The last name is: ");
    scanf("%s",lname);
    for(i=0; i<n; i++)
    {
        if(strcasecmp(employees[i].Lname,lname)==0&&strcasecmp(employees[i].Fname,fname)==0)
        {
            for(k=i; k<n; k++)
            {
                employees[k].id=employees[k+1].id;
                strcpy(employees[k].Lname,employees[k+1].Lname);
                strcpy(employees[k].Fname,employees[k+1].Fname);
                employees[k].salary=employees[k+1].salary;
                employees[k].DOB.day=employees[k+1].DOB.day;
                employees[k].DOB.month=employees[k+1].DOB.month;
                employees[k].DOB.year=employees[k+1].DOB.year;
                strcpy(employees[k].adrs,employees[k+1].adrs);
                strcpy(employees[k].phNo,employees[k+1].phNo);
                strcpy(employees[k].mail,employees[k+1].mail);
                flag=1;


            }
            n=n-1;
            i--;
        }

    }

    if(flag==1)
    {
        printf("\nThe list after modification is:\n");
        printf("-------------------------------\n");
        for(i=0; i<n; i++)
        {
            printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
        }
    }
    else if(flag==0)printf("This name is not found\n\n");

}
void print()
{
    int ch;
    printf("\nPlease choose the way of sorting you would like:\n------------------------------------------------\nChoose 1 for sorting alphabetically by the last name\nChoose 2 for sorting according to date of birth from the younger to the elder\nChoose 3 for sorting according to the salary from the highst to the lowest\n");
    scanf("%d",&ch);
    if(ch==1)
        SLname();
    if(ch==2)
        SDOB();
    if(ch==3)
        Ssalary();
    else if(ch>3||ch<1)
    {
        printf("\nPlease enter correct number\n");
        print();
    }
}
void SLname()
{
    char temp [100];
    int temp1;
    char temp2[100];
    float temp3;
    int temp4;
    int temp5;
    int temp6;
    char temp7[100];
    char temp8[100];
    char temp9[100];
    int i,j;
    for (i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcasecmp(employees[i].Lname, employees[j].Lname)>0)
            {
                strcpy(temp,employees[i].Lname);
                strcpy(employees[i].Lname,employees[j].Lname);
                strcpy(employees[j].Lname,temp);
                temp1=employees[i].id;
                employees[i].id=employees[j].id;
                employees[j].id=temp1;
                strcpy(temp2,employees[i].Fname);
                strcpy(employees[i].Fname,employees[j].Fname);
                strcpy(employees[j].Fname,temp2);
                temp3=employees[i].salary;
                employees[i].salary=employees[j].salary;
                employees[j].salary=temp3;
                temp4=employees[i].DOB.day;
                employees[i].DOB.day=employees[j].DOB.day;
                employees[j].DOB.day=temp4;
                temp5=employees[i].DOB.month;
                employees[i].DOB.month=employees[j].DOB.month;
                employees[j].DOB.month=temp5;
                temp6=employees[i].DOB.year;
                employees[i].DOB.year=employees[j].DOB.year;
                employees[j].DOB.year=temp6;
                strcpy(temp7,employees[i].adrs);
                strcpy(employees[i].adrs,employees[j].adrs);
                strcpy(employees[j].adrs,temp7);
                strcpy(temp8,employees[i].phNo);
                strcpy(employees[i].phNo,employees[j].phNo);
                strcpy(employees[j].phNo,temp8);
                strcpy(temp9,employees[i].mail);
                strcpy(employees[i].mail,employees[j].mail);
                strcpy(employees[j].mail,temp9);

            }
        }

    }
    for(i=0; i<n; i++)
    {
        printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
    }
}
void SDOB()
{
    int i,j;
    char temp [100];
    int temp1;
    char temp2[100];
    float temp3;
    int temp4;
    int temp5;
    int temp6;
    char temp7[100];
    char temp8[100];
    char temp9[100];

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(employees[i].DOB.year<employees[j].DOB.year)
            {

                strcpy(temp,employees[i].Lname);
                strcpy(employees[i].Lname,employees[j].Lname);
                strcpy(employees[j].Lname,temp);
                temp1=employees[i].id;
                employees[i].id=employees[j].id;
                employees[j].id=temp1;
                strcpy(temp2,employees[i].Fname);
                strcpy(employees[i].Fname,employees[j].Fname);
                strcpy(employees[j].Fname,temp2);
                temp3=employees[i].salary;
                employees[i].salary=employees[j].salary;
                employees[j].salary=temp3;
                temp4=employees[i].DOB.day;
                employees[i].DOB.day=employees[j].DOB.day;
                employees[j].DOB.day=temp4;
                temp5=employees[i].DOB.month;
                employees[i].DOB.month=employees[j].DOB.month;
                employees[j].DOB.month=temp5;
                temp6=employees[i].DOB.year;
                employees[i].DOB.year=employees[j].DOB.year;
                employees[j].DOB.year=temp6;
                strcpy(temp7,employees[i].adrs);
                strcpy(employees[i].adrs,employees[j].adrs);
                strcpy(employees[j].adrs,temp7);
                strcpy(temp8,employees[i].phNo);
                strcpy(employees[i].phNo,employees[j].phNo);
                strcpy(employees[j].phNo,temp8);
                strcpy(temp9,employees[i].mail);
                strcpy(employees[i].mail,employees[j].mail);
                strcpy(employees[j].mail,temp9);
            }
            else if(employees[i].DOB.year==employees[j].DOB.year)
            {
                if(employees[i].DOB.month<employees[j].DOB.month)
                {
                    strcpy(temp,employees[i].Lname);
                    strcpy(employees[i].Lname,employees[j].Lname);
                    strcpy(employees[j].Lname,temp);
                    temp1=employees[i].id;
                    employees[i].id=employees[j].id;
                    employees[j].id=temp1;
                    strcpy(temp2,employees[i].Fname);
                    strcpy(employees[i].Fname,employees[j].Fname);
                    strcpy(employees[j].Fname,temp2);
                    temp3=employees[i].salary;
                    employees[i].salary=employees[j].salary;
                    employees[j].salary=temp3;
                    temp4=employees[i].DOB.day;
                    employees[i].DOB.day=employees[j].DOB.day;
                    employees[j].DOB.day=temp4;
                    temp5=employees[i].DOB.month;
                    employees[i].DOB.month=employees[j].DOB.month;
                    employees[j].DOB.month=temp5;
                    temp6=employees[i].DOB.year;
                    employees[i].DOB.year=employees[j].DOB.year;
                    employees[j].DOB.year=temp6;
                    strcpy(temp7,employees[i].adrs);
                    strcpy(employees[i].adrs,employees[j].adrs);
                    strcpy(employees[j].adrs,temp7);
                    strcpy(temp8,employees[i].phNo);
                    strcpy(employees[i].phNo,employees[j].phNo);
                    strcpy(employees[j].phNo,temp8);
                    strcpy(temp9,employees[i].mail);
                    strcpy(employees[i].mail,employees[j].mail);
                    strcpy(employees[j].mail,temp9);
                }
                else if(employees[i].DOB.month==employees[j].DOB.month)
                {
                    if(employees[i].DOB.day<employees[j].DOB.day)
                    {
                        strcpy(temp,employees[i].Lname);
                        strcpy(employees[i].Lname,employees[j].Lname);
                        strcpy(employees[j].Lname,temp);
                        temp1=employees[i].id;
                        employees[i].id=employees[j].id;
                        employees[j].id=temp1;
                        strcpy(temp2,employees[i].Fname);
                        strcpy(employees[i].Fname,employees[j].Fname);
                        strcpy(employees[j].Fname,temp2);
                        temp3=employees[i].salary;
                        employees[i].salary=employees[j].salary;
                        employees[j].salary=temp3;
                        temp4=employees[i].DOB.day;
                        employees[i].DOB.day=employees[j].DOB.day;
                        employees[j].DOB.day=temp4;
                        temp5=employees[i].DOB.month;
                        employees[i].DOB.month=employees[j].DOB.month;
                        employees[j].DOB.month=temp5;
                        temp6=employees[i].DOB.year;
                        employees[i].DOB.year=employees[j].DOB.year;
                        employees[j].DOB.year=temp6;
                        strcpy(temp7,employees[i].adrs);
                        strcpy(employees[i].adrs,employees[j].adrs);
                        strcpy(employees[j].adrs,temp7);
                        strcpy(temp8,employees[i].phNo);
                        strcpy(employees[i].phNo,employees[j].phNo);
                        strcpy(employees[j].phNo,temp8);
                        strcpy(temp9,employees[i].mail);
                        strcpy(employees[i].mail,employees[j].mail);
                        strcpy(employees[j].mail,temp9);
                    }
                }
            }
        }

    }
    for(i=0; i<n; i++)
    {
        printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
    }
}
void Ssalary()
{
    int i,j;
    char temp [100];
    int temp1;
    char temp2[100];
    float temp3;
    int temp4;
    int temp5;
    int temp6;
    char temp7[100];
    char temp8[100];
    char temp9[100];
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(employees[i].salary<employees[j].salary)
            {

                strcpy(temp,employees[i].Lname);
                strcpy(employees[i].Lname,employees[j].Lname);
                strcpy(employees[j].Lname,temp);
                temp1=employees[i].id;
                employees[i].id=employees[j].id;
                employees[j].id=temp1;
                strcpy(temp2,employees[i].Fname);
                strcpy(employees[i].Fname,employees[j].Fname);
                strcpy(employees[j].Fname,temp2);
                temp3=employees[i].salary;
                employees[i].salary=employees[j].salary;
                employees[j].salary=temp3;
                temp4=employees[i].DOB.day;
                employees[i].DOB.day=employees[j].DOB.day;
                employees[j].DOB.day=temp4;
                temp5=employees[i].DOB.month;
                employees[i].DOB.month=employees[j].DOB.month;
                employees[j].DOB.month=temp5;
                temp6=employees[i].DOB.year;
                employees[i].DOB.year=employees[j].DOB.year;
                employees[j].DOB.year=temp6;
                strcpy(temp7,employees[i].adrs);
                strcpy(employees[i].adrs,employees[j].adrs);
                strcpy(employees[j].adrs,temp7);
                strcpy(temp8,employees[i].phNo);
                strcpy(employees[i].phNo,employees[j].phNo);
                strcpy(employees[j].phNo,temp8);
                strcpy(temp9,employees[i].mail);
                strcpy(employees[i].mail,employees[j].mail);
                strcpy(employees[j].mail,temp9);

            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
    }

}
void save()
{
    FILE *f;
    f=fopen("Company.txt","w");
    int i;
    for(i=0; i<n; i++)
    {
        fprintf(f,"%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
    }
    fclose(f);
}
void ADD()
{

    int i=n++;
    char day[30],month[30],year[30],ID[20];
    printf("\nEnter the employee's ID:");
    do
    {
        scanf("%s",ID);
    }
    while(!isValid_ID(ID,i));
    printf("Enter the last name of the added employee:");
    getchar();
    gets(employees[i].Lname);
    printf("Enter the first name of the employee:");
    gets(employees[i].Fname);
    printf("Enter the salary of the employee:");
    scanf("%f",&employees[i].salary);
    do
    {
        printf("Enter the date of birth of the employee:");
        scanf("%s %s %s",day,month,year);
    }
    while(!(isValid_day(day,i)&&isValid_month(month,i)&&isValid_year(year,i)));
    printf("Enter the address of the added employee:");
    getchar();
    gets(employees[i].adrs);
    do
    {
        printf("Enter a valid phone number of the added employee:");
        scanf("%s",employees[i].phNo);
    }
    while(!isValid_phNo(employees[i].phNo));

    do
    {
        printf("Enter the mail of the employee:");
        scanf("%s",employees[i].mail);
    }
    while(!isvalid_mail(employees[i].mail));
    printf("\nThe data of employees after addition is:\n");
    printf("----------------------------------------\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
    }


}
void modify (int id,int index)
{
    int x;
    do
    {
        printf("\nEnter the field that you want to modify :\n");
        printf("-----------------------------------------\n");
        printf("Enter 1 for The last name \nEnter 2 for The first name\nEnter 3 for The salary\nEnter 4 for The birthday date\nEnter 5 for The address\nEnter 6 for The phone number\nEnter 7 for The e-mail\n:");
        scanf("%d",&x);
    }
    while(x<1||x>7);

    char N_lname[30],N_fname[30],N_day[10],N_month[10],N_year[10],N_adrs[50],N_phNo[20],N_mail[30];
    float N_salary =0.0;
    if(x==1)
    {
        printf("Enter the new last name : ");
        scanf("%s",N_lname);
        strcpy(employees[index].Lname,N_lname);
    }
    if(x==2)
    {
        printf("Enter the new first name : ");
        scanf("%s",N_fname);
        strcpy(employees[index].Fname,N_fname);
    }

    if(x==3)
    {
        printf("Enter the new salary : ");
        scanf("%f",&N_salary);
        employees[index].salary=N_salary ;
    }
    if(x==4)
    {
        do
        {
        printf("Enter the new DOB : ");
        scanf("%s%s%s",N_day,N_month,N_year);

        }
        while(!(isValid_day(N_day,index)&&isValid_month(N_month,index)&&isValid_year(N_year,index)));

    }
    if(x==5)
    {
        printf("Enter the new address : ");
        getchar();
        gets(N_adrs);
        strcpy(employees[index].adrs,N_adrs);
    }
    if(x==6)
    {
        do
        {
            printf("Enter the new phone number : ");
            scanf("%s",N_phNo);
        }
        while(!isValid_phNo(N_phNo));
        strcpy(employees[index].phNo,N_phNo);

    }
    if(x==7)
    {
        do
        {
            printf("Enter the new mail : ");
            scanf("%s",N_mail);
        }
        while(!isvalid_mail(N_mail));
        strcpy(employees[index].mail,N_mail);
    }
    printf("\nDO you want to modify other field ?\nIf yes enter: 1\nIf No enter: 2\n ");
    int other_mod =0;
    scanf("%d",&other_mod);
    if(other_mod==1)
    {
        modify(id,index);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
        }
    }



}

int isValid_phNo(char phNo[])
{
    int i=0;
    int m=strlen(phNo);
    for(i=0; i<m; i++)
    {
        if((phNo[i]>='a' && phNo[i]<='z') || (phNo[i]>='A' && phNo[i]<='Z'))
        {
            return 0;
        }
    }
    return 1;
}
int isvalid_mail(char mail[ ])
{
    int i,index1=-1,index2=-1,count=0;
    int m=strlen(mail);
    for(i=0; i<m; i++)
    {
        if(mail[i]=='@')
        {
            count++;
        }
    }
    if(count!=1)
    {
        return 0;
    }

    for(i=0; i<m; i++)
    {
        if(mail[i]=='@') //عشان دايما ال@تبقي قبل ال"." دايما شان لو قبلها  تبقي غلط فبيحط index1>=0 عشان تخليها غلط دايما لحد ما يلاقي ال @
            index1=i;
        if(mail[i]=='.'&&index1>=0)
            index2=i;

        if(index2-index1==1)
            return 0;
    }
    if(index1>=0&&index2>index1)
        return 1;

    return 0;
}
int isValid_day(char day[],int i)
{
    int j,m,dayint=0;
    m=strlen(day);
    for(j=0; j<m; j++)
    {
        if(!((day[j]>='0')&&(day[j]<='9')))
        {
            return 0;
        }
    }
    if(m>2||m<1)
    {
        return 0;
    }


    for(j=0; j<m; j++)
    {
        dayint=dayint*10+(day[j]-'0');
    }
    if(dayint<1||dayint>31)
        return 0;
    employees[i].DOB.day=dayint;

    return 1;
}
int isValid_month(char month[],int i)
{
    int j,m,monthint=0;
    m=strlen(month);
    for(j=0; j<m; j++)
    {
        if(!((month[j]>='0')&&(month[j]<='9')))
        {
            return 0;
        }
    }
    if(m>2||m<1)
    {
        return 0;
    }


    for(j=0; j<m; j++)
    {
        monthint=monthint*10+(month[j]-'0');
    }
    if(monthint<1||monthint>12)
    {
        return 0;
    }
    employees[i].DOB.month=monthint;

    return 1;
}
int isValid_year(char year[],int i)
{
    int j,m,yearint=0;
    m=strlen(year);
    for(j=0; j<m; j++)
    {
        if(!((year[j]>='0')&&(year[j]<='9')))
        {
            return 0;
        }
    }
    if(m>4||m<1)
    {
        return 0;
    }


    for(j=0; j<m; j++)
    {
        yearint=yearint*10+(year[j]-'0');
    }
    employees[i].DOB.year=yearint;

    return 1;
}
void quit()
{
    exit(0);
}
int isValid_ID(char ID[],int i)
{
    int j,k=0;
    int m=strlen(ID);
    for(j=0; j<m; j++)
    {
        if(!(ID[j]>='0' && ID[j]<='9'))
        {
            printf("Enter a valid ID number:");
            return 0;
        }
    }
    for (j=0; j<m; j++)
    {
        k=10*k+(ID[j]-'0');
    }
    employees[i].id=k;
    return 1;
}
void load()
{
    FILE *f;
    int i;
    f=fopen("Company.txt","r");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%d,",&employees[n].id);
            fscanf(f,"%[^,\n],",employees[n].Lname);
            fscanf(f,"%[^,\n],",employees[n].Fname);
            fscanf(f,"%f,",&employees[n].salary);
            fscanf(f,"%d-%d-%d,",&employees[n].DOB.day,&employees[n].DOB.month,&employees[n].DOB.year);
            fscanf(f,"%[^,\n],",employees[n].adrs);
            fscanf(f,"%[^,\n],",employees[n].phNo);
            fscanf(f,"%[^,\n],",employees[n].mail);
            n++;
        }
        fclose(f);
        for(i=0; i<n; i++)
        {
            printf("%d) The Id:%d, The last name:%s, The first name:%s, The salary:%.3f, The birthday date:%d-%d-%d,\nThe address:%s, The phone number:%s, The e-mail:%s\n\n",i+1,employees[i].id,employees[i].Lname,employees[i].Fname,employees[i].salary,employees[i].DOB.day,employees[i].DOB.month,employees[i].DOB.year,employees[i].adrs,employees[i].phNo,employees[i].mail);
        }
    }
    else
    {
        printf("File not found");
        quit();
    }

}
int main()
{
    load();
    int i;
    for(i=0;; i++)
        {
            int number;
            printf("\nchoose from the list:\n=====================\n");
            printf("Enter 1 for search\nEnter 2 for sort\nEnter 3 for delete\nEnter 4 for modify\nEnter 5 for add\nEnter 6 for save\nEnter 7 for exit\n");
            printf("the selection number is: ");
            scanf("%d",&number);
            if(number==1)
                search();
            if(number==2)
                print();
            if(number==3)
                delet();
            if(number==4)
            {
                int id=0, index=0,flag=0 ;
                printf("\nEnter the ID of employee:");
                scanf("%d",&id);
                for(int i=0;i<n; i++)
                {
                    if(employees[i].id==id)
                    {
                        index=i;
                        modify(id,index);
                        flag=1;
                    }
                }
               if(flag==0)
               printf("\nThe ID is not found\n");
            }
            if(number==5)
                ADD();
            if(number==6)
                save();
            if(number==7)
                quit();
      }

    return 0;
}

