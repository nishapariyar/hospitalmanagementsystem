#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct patient
{
    char name[50],address[90],gud[100];
    int age,phone;
    char disease[90];
    char gender[50];
    char bloodgroup[50];
}p;
struct doctor
{
	char fullname[90],gender[40];
	char bloodgroup[20],specialty[100];
	char addresss[100];
	int tel;
}d;

void menu();
void patient();
void doctor();
void about();
void record();
void icu();
void view();
void reading();
void docreading();
void emereading();

main()
{
	char a[20]; 
	char p[20]="hospital";
	int i;
	do
	{
	for (i=1;i<=5;i++)
	{
	printf("\n\t\t\t\t****login page****\n");
	printf("\t\t\t\t\nEnter your password:");
	scanf("%s",&a);
	if(strcmp(a,p)==0)
	{
		menu();
	}
	else
	{
		printf("Invalid password\n\n");	
	}
	printf("\t\t\tYou have entered wrong password for %d times.",i);
	getch();
	system("cls");
    }
    
}while(i!=6);

}
void menu()
{
    int n;
    do
    {
    	system("cls");
    printf("\t\t******************************************");
    printf("\n\t\t***WELCOME TO HOSPITAL MANAGEMENT SYSTEM***");
    printf("\n\t\t*****************************************");
    printf("\n\n\n\n\n");
    printf("\t\t1.PATIENT");
    printf("\n\t\t2.DOCTOR");
    printf("\n\t\t3.ABOUT PROGRAM");
    printf("\n\t\t4.View All Record");
    printf("\n\t\t0.Exit");
    printf("\n\n\tEnter your choice :");
    scanf("%d",&n);
    system("cls");
    switch(n)
    {
    	case 1:
    		patient();
    		break;
    	case 2:
    		doctor();
    		break;
    	case 3:
    		about();
    		break;
    	case 4:
    		view();
    	break;
    	case 0:
    		exit(1);
    		
	}
}while(n!=0);


}
void patient()
{
	int n;
	printf("\n\t\t1.Add patient record");
	printf("\n\t\t2.Add Emergency patient record");
	printf("\n\t\t0.Exit ");
	printf("\n\t\t Enter your choice");
	scanf("%d",&n);
	system("cls");
	switch(n)
	{
		case 1:
			record();
			break;
		case 2:
			icu();
			break;
		case 0:
			exit(1);
	}
}
void record()
{
	FILE *fp;
	printf("\n\t\t\t****PATIENT RECORD****");
    printf("\nEnter the name of patient :");
    scanf("%s",&p.name);
    printf("\nEnter the name of the Guardian:");
    scanf("%s",&p.gud);
    printf("\n Enter the address of patient :");
    scanf("%s",&p.address);
    printf("\n Enter the age of patient :");
    scanf("%d",&p.age);
    printf("\n Enter the phone number :");
    scanf("%d",&p.phone);
    printf("\n Enter the gender of patient :");
    scanf("%s",&p.gender);
    printf("\n Enter the blood group :");
    scanf("%s",&p.bloodgroup);
    printf("\n Enter the disease : ");
    scanf("%s",&p.disease);
    fp=fopen("patientinfo.bat","a");
    if(fp==NULL)
    {
    printf("empty file");
	}
	else
	{
	fprintf(fp,"%s\n%s\n%s\n%d\n%d\n%s\n%s\n%s",p.name,p.gud,p.address,p.age,p.phone,p.gender,p.bloodgroup,p.disease);
	printf("Record successfully");
	fclose(fp);
	getch();
	system("cls");
	}
}
void icu()
{
	FILE *fp;
	printf("\n\t\t\t***EMERGENCY PATIENT RECORD***");
	printf("\n\t Enter  Emergency patient name:");
	scanf("%s",&p.name);
	printf("\n\t Enter the name of emergency patient Guardian :");
	scanf("%s",&p.gud);
	printf("\n\t Enter the phone number");
	scanf("%d",&p.phone);
	printf("\n\t Enter the address:");
	scanf("%s",&p.address);
	printf("\n\t Enter the age:");
	scanf("%d",&p.age);
	printf("\n\t Enter the Gender:");
	scanf("%s",&p.gender);
	printf("\n\t Enter the disease:");
	scanf("%s",&p.disease);
	fp=fopen("emergencyinfo.bat","a");
	if(fp==NULL)
	{
	printf("Empty file");
	}
	else
	{
	fprintf(fp,"%s\n%s\n%d\n%s\n%d\n%s\n%s",p.name,p.gud,p.phone,p.address,p.age,p.gender,p.disease);
	printf("Data record successfully");
	fclose(fp);
	getch();
	system("cls");
	}
}
void doctor ()
{
	FILE *fp;
	printf("\t***Adding Doctor information***");
	printf("\n\n\nEnter the Name of Doctor :");
	scanf("%s",&d.fullname);
	printf("\n Enter the Address :");
	scanf("%s",&d.addresss);
	printf("\n Enter the blood group:");
	scanf("%s",&d.bloodgroup);
	printf("\n Enter the phone number or telephone number:");
	scanf("%d",&d.tel);
	printf("\n Enter the specialty:");
	scanf("%s",&d.specialty);
	fp=fopen("doctorinfo.bat","a");
	if(fp==NULL)
	{
		printf("Empty file");
	}
	else
	{
		fprintf(fp,"%s\n%s\n%s\n%d\n%s\n",d.fullname,d.addresss,d.bloodgroup,d.tel,d.specialty);
		printf("Data is recorded successfully");
		fclose(fp);
		getch();
		system("cls");
	}
}
void view()
{
	int n;
	printf("\n\t\t1.view the record of patients");
	printf("\n\t\t2.view the record of emergency patients");
	printf("\n\t\t3.view the record of doctors");
	printf("\n\t\t0.Exit");
	printf("\n Enter your choice:");
	scanf("%d",&n);
	system("cls");
	switch(n)
	{
		case 1:
			reading();
			break;
		case 2:
			emereading();
			break;
		case 3:
			docreading();
			break;
		case 0:
			exit(0);
	}
}
void reading()
{
	FILE *fp;
	fp=fopen("patientinfo.bat","r");
	if(fp==NULL)
	{
		printf("Empty file");
	}
	else
	{
		while(fscanf(fp,"%s\n%s\n%s\n%d\n%d\n%s\n%s\n%s",&p.name,&p.gud,&p.address,
		&p.age,&p.phone,&p.gender,&p.bloodgroup,&p.disease)!=EOF)
		{
			
			printf("\n\nName:%s\n",p.name);
			printf("Guradian:%s\n",p.gud);
			printf("Address:%s\n",p.address);
			printf("Age:%d\n",p.age);
			printf("Phone Number:%d\n",p.phone);
			printf("Gender:%s\n",p.gender);
			printf("Bloodgroup:%s\n",p.bloodgroup);
			printf("Disease:%s\n\n\n",p.disease);
		}	
	}
	fclose(fp);
	getch();
	system("cls");
}
void emereading()
{
	FILE *fp;
	fp=fopen("emergencyinfo.bat","r");
	if(fp==NULL)
	{
		printf("empty file");
	}
	else
	{
		while(fscanf(fp,"%s\n%s\n%d\n%s\n%d\n%s\n%s",&p.name,&p.gud,&p.phone,
		&p.address,&p.age,&p.gender,&p.disease)!=EOF)
		{
			printf("\n\t\t**EMERGENCY PATIENT RECORD**");
			
			printf("\n\nName:%s\n",p.name);
			printf("Guardian:%s\n",p.gud);
			printf("Phone number:%d\n",p.phone);
			printf("Address:%s\n",p.address);
			printf("Age:%d\n",p.age);
			printf("Gender:%s\n",p.gender);
			printf("Disease:%s\n",p.disease);
		
		}
	}
	fclose(fp);
	getch();
	system("cls");
}
void docreading()
{
	FILE *fp;
	fp=fopen("doctorinfo.bat","r");
	if(fp==NULL)
	{
		printf("empty file");
	}
	else
	{
		while(fscanf(fp,"%s\n%s\n%s\n%d\n%s\n",&d.fullname,&d.addresss,
		&d.bloodgroup,&d.tel,&d.specialty)!=EOF);
		{
			printf("\n\nName:%s\n",d.fullname);
			printf("Address:%s\n",d.addresss);
			printf("Bloodgroup:%s\n",d.bloodgroup);
			printf("Phone number:%d\n",d.tel);
			printf("Specialty:%s\n\n",d.specialty);
		}
	}
	fclose(fp);
	getch();
	system("cls");
}
void about()
{
	char n;              
printf("***This program is developed to maintain records.\n,");
printf("It record the information of patient and doctors.");
printf("Developed  By:"); 
printf("my friend");
printf("Press any key: ");
n=getche();
menu();
}
	
 
