#include <stdio.h>
#include <stdlib.h>
int main()
{

int choice, unique_key;
FILE *fp;
char ch;
struct Baya_Karve_Hostel {
int Student_Id;
char Student_Name[50];
char Course[50];
char Year[50];
int RoomNo;
};
struct Baya_Karve_Hostel Bay;
printf("\n\t\t Baya_Karve_Hostel Database\n");
while(1)
{
printf("\n\tMenu - \n");
printf("\t1. Create new Baya_Karve_Hostel record\n");
printf("\t2. Read existing Baya_Karve_Hostel record\n");
printf("\t3. Delete a record from Baya_Karve_Hostel\n");
printf("\t0. To end the program\n");
printf("\tEnter your choice : ");
scanf("%d", &choice);

printf("\n");
switch(choice)
{
case 1: 
printf("Enter Student_Id : ");
scanf("%d", &Bay.Student_Id);
printf("Enter Student_Name : ");
scanf("%s", Bay.Student_Name);
printf("Enter Course : ");
scanf("%s", Bay.Course);
printf("Enter Year : ");
scanf("%s", Bay.Year);
printf("Enter RoomNo : ");
scanf("%d", &Bay.RoomNo);
fp = fopen("Baya_Karve_Hostel.csv", "a+");
fseek(fp, 0, SEEK_END);
fprintf(fp,"%d , %s , %s , %s , %d\n",Bay.Student_Id, Bay.Student_Name, Bay.Course, Bay.Year, Bay.RoomNo);
fclose(fp);
break;

case 2: 
fp = fopen("Baya_Karve_Hostel.csv", "a+");
fseek(fp, 0, SEEK_SET);
while(1) 
{
fscanf(fp,"%d %c %s %c %s %c %s %c %d",&Bay.Student_Id, &ch, &Bay.Student_Name , &ch, &Bay.Course , &ch, &Bay.Year , &ch, &Bay.RoomNo );
if(feof(fp))
{
break;
}
printf("%d, %s, %s, %s, %d \n", Bay.Student_Id, Bay.Student_Name, Bay.Course, Bay.Year, Bay.RoomNo);
}
fclose(fp);
getchar();
getchar();
break;

case 3: 
printf("Enter the unique ID of the row you want to delete : ");
scanf("%d", &unique_key);
FILE *fp1;
fp1 = fopen("Baya_Karve_Hostel1.csv", "w");
fp = fopen("Baya_Karve_Hostel.csv", "a+");
fseek(fp, 0, SEEK_SET);
while(1) 
{
fscanf(fp,"%d %c %s %c %s %c %s %c %d",&Bay.Student_Id, &ch, &Bay.Student_Name , &ch, &Bay.Course , &ch, &Bay.Year , &ch, &Bay.RoomNo );
if(feof(fp))
{
break;
}
if(unique_key != Bay.Student_Id)
{
fprintf(fp1,"%d , %s , %s , %s , %d\n",Bay.Student_Id, Bay.Student_Name, Bay.Course, Bay.Year, Bay.RoomNo);
}
}
fclose(fp);
fclose(fp1);
remove("Baya_Karve_Hostel.csv");
rename("Baya_Karve_Hostel1.csv", "Baya_Karve_Hostel.csv");
break;

case 0:
exit(0);
}
}
}
