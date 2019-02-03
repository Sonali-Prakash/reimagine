                                    LIBRARY MANAGEMENT  SYSTEM  IN C 

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>


struct  student
{
int rl;
char ph[11];
char fnm[20],lnm[20],sn[20];
char dept[10],id[20],pwd[20];
}stud;

struct book
{
int bk_id;
char bk_nm[20],bk_pub[20],bk_au[20];
int bk_pr;
}book;

struct issue
{
int bk_id,id;
char bk_nm[20],sn[20];
int rl;
char fnm[20],lnm[20];
char dept[10];
}is;


void search_bkid()
{
 FILE *f_bk;
 char ch;
 int r, s, avl;
 clrscr();
do{
clrscr();

 printf("\nEnter  Book Id   To Search  :");
 scanf("%d", &r);
 avl = iid(r);
 if (avl == 0){
  printf("\n\n\nBook Id %d Is Not Available In The File\n",r);
 printf("\n\nPress ENTER To Continue ");
 getche();     }
 else
 {
  f_bk = fopen("book_f.txt", "r");
  while (fread(&stud, sizeof(stud), 1, f_bk)!=NULL)
  {
   s = book.bk_id;
   if (s == r)
   {
    printf("\nBook id = %d", book.bk_id);
    printf("\nBook Name    = %s", book.bk_nm);
    printf("\nAuther   = %s", book.bk_au);
    printf("\nPublisher   = %s", book.bk_pub);
    printf("\nPrice   = %d\n", book.bk_pr);
    break;
   }
  }
  fclose(f_bk);
  textcolor(YELLOW);
cprintf("\n\n DO YOU WANT TO  SEARCH AGAIN(Y/N):  ");
ch=getche();
}
}
while(ch=='y');

}

void search_bknm()
{
 FILE *f_bk;
 char ch,r[20],s[20];
 int  avl;
do{
clrscr();

 printf("\nEnter  Book name   To Search  :");
 scanf("%s",r);
 avl = nm(r);
 if (avl == 0)
  printf("\nBook %s Is Not Available In The File\n",r);
 else
 {
  f_bk = fopen("book_f.txt", "r");
  while (fread(&stud, sizeof(stud), 1, f_bk)!=NULL)
  {
strcpy(s,book.bk_nm);
   if (strcmp(r,s)==0)
   {
    printf("\nBook id = %d", book.bk_id);
    printf("\nBook Name    = %s", book.bk_nm);
    printf("\nAuther   = %s", book.bk_au);
    printf("\nPublisher   = %s", book.bk_pub);
    printf("\nPrice   = %d\n", book.bk_pr);
    break;
   }
  }
  fclose(f_bk);
  textcolor(YELLOW);
cprintf("\n\n DO YOU WANT TO  SEARCH AGAIN(Y/N):  ");
ch=getche();
}
}
while(ch=='y');

}


int nm(char id[])
{
FILE *fp;
fp=fopen("book_f.txt","r");
while(!feof(fp))
{
fread(&book,sizeof(book),1,fp);
if(strcmp(id,book.bk_nm)==0)
{
fclose(fp);
return 1;
}
}
{
fclose(fp);
return 0;
}
}

void search_bk()
{
	int opt;
	printf("\n_____________________LIBRARY MANAGEMENT SYSTEM____________________________\n\n");
	clrscr();
	printf("             \n ..........SELECT OPTION............\n\n");
	printf("1. SEARCH BY BOOK ID\n");

	printf("2. SEARCH BY BOOK  NAME\n");

	printf("__________________________\n");
	printf("Enter your choice :   ");
	scanf("%d", &opt);
	switch (opt)
	{
	case 1:
		search_bkid();
		break;
	case 2:
		search_bknm();
		break;
	}
}



void view_bk()
{
FILE *f_bk;
clrscr();
f_bk=fopen("book_f.txt","r");
printf("           \n\n ................................BOOK DETAILS........................................\n");
printf("BOOK ID\tBOOK NAME\tAUTHER\t\tPUBLISER\t\tPRICE\n");
while(fread(&book,sizeof(book),1,f_bk)!=NULL)
{
printf("\n%d	  %s		%s		%s		   %d \n",book.bk_id,book.bk_nm,book.bk_au,book.bk_pub,book.bk_pr);
}
fclose(f_bk);
printf("\n\nPress ENTER To Continue ");
getche();
}



void create_acc()
{
FILE  *stud_f;
char id[20],pwd[20];
int i,tl,sl,ts;
char ch,c;
clrscr();
stud_f=fopen("stud_rc.txt","r");
printf("_____________________________________________________________________\n");
printf("                               REGISTER      \n");
printf("_____________________________________________________________________\n");
fseek(stud_f,0,SEEK_END);
tl=ftell(stud_f);
	  sl=sizeof(stud);
	  ts=tl/sl;
	  fseek(stud_f,(ts-1)*sl,SEEK_SET);
	  fread(&stud,sizeof(stud),1,stud_f);
	  printf("\nSTUDENT ID. :%d\n",++stud.rl);
	  fclose(stud_f);
	  stud_f=fopen("stud_rc.txt","a");
printf("\n Enter First Name :   ");
scanf("%s",&stud.fnm);
printf("\n Enter Title:   ");
scanf("%s",&stud.lnm);
printf("\n Enter Department :   ");
scanf("%s",&stud.dept);
printf("\n Enter Session :   ");
scanf("%s",&stud.sn);
printf("\n Enter Phone No. :   ");
scanf("%s",&stud.ph);
printf("\n Enter User Id. :   ");
scanf("%s",&stud.id);
printf("\n Enter 6 character  Password :   ");
for(i=0;i<6;i++)
{
pwd[i]=getch();
printf("*");
}
pwd[6]='\0';
strcpy(stud.pwd,pwd);
fwrite(&stud,sizeof(stud),1,stud_f);
if(fwrite != 0)
	printf("\n\n....................REGISTER SUCCESSFULLY....................\n");
    else
	printf("ERROR WHILE REGISTRATION!!!!\n");
fclose(stud_f);
printf("\n\nPress ENTER To Continue ");
getche();
 }


void user_log()
{
FILE  *fpi;
int opt,i;
char id[20],pas[20],ch[20];
clrscr();
fpi=fopen("stud_rc.txt","r");
textcolor(RED);
cprintf("\n\n----------------------------STUDENT  LOGIN---------------------------------------\n\n");
printf("Enter User Id:  ");
scanf("%s",id);
printf("\nEnter Password :  ");
for(i=0;i<6;i++)
{
pas[i]=getch();
printf("*");
}
pas[6]='\0';
while(!feof(fpi))
{
fread(&stud,sizeof(stud),1,fpi);
strcpy(ch,stud.pwd);
if(strcmp(id,stud.id)==0)
     {
			if(strcmp(ch,pas)==0){
					   printf("\n");
do{
clrscr();


				  printf("\n\n---------------------------SELECT MENU--------------------------------\n");
				   printf("1......VIEW BOOK\n");
				   printf("2......SEARCH\n");
				   printf("3......BACK\n");
				   printf("_____________________________________");
		printf("\n\nENTER YOUR OPTION :  ");
		scanf("%d",&opt);
						       switch(opt)
				{
					case 1:
						view_bk();
						break;
					case 2:
						search_bk();
						break;
					case 3:

						return;
			    }
}while(opt!=3);

}} } }



void reader()
{
int opt;
char ch;
clrscr();
do{
clrscr();
printf("\n-----------------------------SELECT OPTION---------------------------------------\n");
printf("1......CREATE ACCOUNT \n");
printf("2.......LOGIN\n");
printf("3.......BACK\n");
printf("____________________________________________________\n\n");
printf("Enter Your Option:    ");
scanf("%d",&opt);
 switch(opt)
	{
	case 1:
			create_acc();
			break;
		case 2:
		      user_log();
			      break;
	case 3:
				     return;
}
}
while(ch!=3);
getch();

}


void view_stud()
{
FILE  *stud_f;
clrscr();
stud_f=fopen("stud_rc.txt","r");
printf("\n\n-----------------------------STUDENT  DETAILS-----------------------------------------\n");
printf("STUDENT ID	  NAME	       DEPARTMENT	SESSION      PHONE NO \n  ");

while(fread(&stud,sizeof(stud),1,stud_f)!=NULL)
{
printf("%d	  %s %s		%s		%s	%s\n",stud.rl,stud.fnm,stud.lnm,stud.dept,stud.sn,stud.ph);
}
fclose(stud_f);
printf("\n\nPress ENTER To Continue ");
getche();
}

int check_is(int id)
{
	FILE *fp;
	fp = fopen("issue_fl.txt", "r");
	while (!feof(fp))
	{
		fread(&is, sizeof(is), 1, fp);
		if (id == is.id)
		{
			fclose(fp);
			return 1;
		}
	}
	{
		fclose(fp);
		return 0;
	}
}



void issue()
{
	FILE *fpi, *fpb, *fps;
	struct date d;
	int id, r, s;
	int tl, sl, ts;
	clrscr();
	fpi = fopen("issue_fl.txt", "r");
	getdate(&d);

	printf("\nEnter Student ID:  ");
	scanf("%d", &r);
	if (check_id(r) == 0){
		printf("Student Id %d Is Not Available In Database\n", r);
	printf("\n\nPress ENTER To Continue ");
	getche();
}
 else
{
printf("\nEnter Book Id:   ");
scanf("%d",&id);
   if(iid(id)==0)
   printf("Book  %d Is Not Available\n",id);
   else
   {
	   if (check(id) == 1)  {
		   printf("Book With ID %d is not available for issue", id);
		   printf("\n\nPress ENTER To Continue ");
		   getche();    }
	   else
	   {

		   fps = fopen("stud_rc.txt", "r");
		   fpb = fopen("book_f.txt", "r");
		   fseek(fpi, 0, SEEK_END);
		   tl = ftell(fpi);
		   sl = sizeof(is);
		   ts = tl / sl;
		   fseek(fpi, (ts - 1)*sl, SEEK_SET);
		   fread(&stud, sizeof(stud), 1,fpi);
		   printf("\nISSUE NO. :%d\n", ++is.id);
		   fclose(fpi);
		    fpi= fopen("issue_fl.txt", "a");
		   printf("ISSUE DATE: %d/%d/%d", d.da_day, d.da_mon, d.da_year);
		   while (fread(&book, sizeof(book), 1, fpb) != NULL)
		   {
			   s = book.bk_id;
			   if (s == id)
			   {
				   printf("\nBook id = %d", book.bk_id);
				   printf("\nBook Name    = %s", book.bk_nm);
				   is.bk_id = book.bk_id;
				   strcpy(is.bk_nm, book.bk_nm);
			   }
		   }
		   fclose(fpb);
		   while (fread(&stud, sizeof(stud), 1, fps) != NULL)
		   {
			   s = stud.rl;
			   if (s == r)
			   {
				   printf("\nStudent Id = %d", stud.rl);
				   printf("\nStudent Name    = %s %s ", stud.fnm, stud.lnm);
				   printf("\nDepartment   = %s", stud.dept);
				   printf("\nSession   = %s", stud.sn);
				   is.rl = stud.rl;
				   strcpy(is.fnm, stud.fnm);
				   strcpy(is.lnm, stud.lnm);
				   strcpy(is.dept, stud.dept);
				   strcpy(is.sn, stud.sn);
			   }
		   }

		   fclose(fpb);
		   fwrite(&is, sizeof(is), 1, fpi);
if(fwrite != 0)
	printf("\n\n....................ISSUE SUCCESSFULLY....................\n");
    else
	printf("ERROR WHILE ISSUING!!!!\n");
		   fclose(fpi);
	   }
   }

printf("\n\nPress ENTER To Continue ");
getche();
}
}

void view_iss()
{
FILE *f_iss;
clrscr();
f_iss=fopen("issue_fl.txt","r");
printf("           \n\n                   ISSUE DETAILS  \n");
printf(" I.ID   BOOK ID BOOK NAME STUDENT ID    STUDENT NAME   DEPARTMENT   SESSION\n\n");
while(fread(&is,sizeof(is),1,f_iss)!=NULL)
{
printf(" %d   %d          %s         %d        %s %s       %s        %s \n",is.id,is.bk_id,is.bk_nm,is.rl,is.fnm,is.lnm,is.dept,is.sn);
}
fclose(f_iss);
printf("\n\nPress ENTER To Continue ");
getche();

}

int check_id(int s_id)
{
 FILE *fp;
 fp = fopen("stud_rc.txt", "r");
 while (!feof(fp))
 {
  fread(&stud, sizeof(stud), 1, fp);

  if (s_id == stud.rl)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}


void delete_bk()
{
 FILE *f_bk;
 FILE *fpt;
char ch;
 int b_id, s,id;
do{
clrscr();
printf("\n\n___________LIBRARY MANAGEMENT SYSTEM___________");
 printf("\n\nEnter The book Id You Want To Delete :    ");
 scanf("%d", &b_id);
 if (iid(b_id) == 0) {
  printf(" Book With Id %d Is Not Available In The File\n", b_id);
  printf("\n\nPress ENTER To Continue ");
  ch=getche();        }
 else
 {
  f_bk = fopen("book_f.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&book, sizeof(book), 1, f_bk))
  {
   s = book.bk_id;
   if (s != b_id)
    fwrite(&book, sizeof(book), 1, fpt);
  }
  fclose(f_bk);
  fclose(fpt);
  f_bk = fopen("book_f.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&book, sizeof(book), 1, fpt))
   fwrite(&book, sizeof(book), 1, f_bk);
  printf("\n......................RECORD DELETED SUCCESSFULLY FROM FILE....................\n");
  fclose(f_bk);
  fclose(fpt);
printf("Do You Want To Delete More Book(y/n): ");
ch=getche();}
}
while(ch=='y');
 }





void add_bk()
{
FILE *f_bk;
char ch;
int tl,sl,ts;
do{
clrscr();
f_bk=fopen("book_f.txt","r");
printf("\n\n.............................................ENTER BOOK DETAILS...............................................\n");
fseek(f_bk,0,SEEK_END);
tl=ftell(f_bk);
	  sl=sizeof(book);
	  ts=tl/sl;
	  fseek(f_bk,(ts-1)*sl,SEEK_SET);
	  fread(&book,sizeof(book),1,f_bk);
	  printf("\nBook ID. :%d\n",++book.bk_id);
	  fclose(f_bk);
	  f_bk=fopen("book_f.txt","a");
printf("\nEnter book Name:  ");
scanf("%s",book.bk_nm);
printf("\nEnter Auther Name:  ");
scanf("%s",book.bk_au);
printf("\nEnter Publisher :   ");
scanf("%s",book.bk_pub);
printf("\nEnter Price Of Book:  ");
scanf("%d",&book.bk_pr);
fwrite(&book,sizeof(book),1,f_bk);
if(fwrite != 0)
	printf("\n\n....................NEW BOOK IS ADDED SUCCESSFULLY....................\n");
    else
	printf("\n\nERROR WHILE ADDING NEW BOOK!!!!\n");

fclose(f_bk);
printf("Do You Want To Delete More Book(y/n): ");
ch=getche();}
while(ch=='y');
}



int iid(int id)
{
FILE *fp;
fp=fopen("book_f.txt","r");
while(!feof(fp))
{
fread(&book,sizeof(book),1,fp);
if(id==book.bk_id)
{
fclose(fp);
return 1;
}
}
{
fclose(fp);
return 0;
}
}


int check(int id)
{
	FILE *fp;
	fp = fopen("issue_fl.txt", "r");
	while (!feof(fp))
	{
		fread(&is, sizeof(is), 1,fp);
		if (id == is.bk_id)
		{
			fclose(fp);
			return 1;
		}
	}
	{
		fclose(fp);
		return 0;
	}
}

void admin_se()
{
int opt;

printf("\n_____________________LIBRARY MANAGEMENT SYSTEM____________________________\n\n");
       do{
clrscr();
		printf("             \n ..........SELECT MENU............\n\n");
		printf("1. Add Book\n");

		printf("2. View Book List\n");
		printf("3. Search Book\n");
				printf("4. Delete Book\n");
		printf("5. View Student List\n");
		printf("6. Issue\n");
		printf("7. View issue list\n");
		printf("8. Exit\n");

		printf("__________________________\n");
		printf("Enter your choice :   ");
		scanf("%d",&opt);
			switch(opt)
						     {
				case 1:
						    add_bk();
						    break;
				case 2:
						     view_bk();
						     break;

				case 3:
						     search_bk();
							     break;

				case 4:
						delete_bk();
							 break;
				case 5:
						    view_stud();
									     break;

					case 6:
							     issue();
							     break;
								 
				  case 7:
							    view_iss();
							    break;
								case 8:
				
							     return;

			     }             }
			     while(opt!=8);
getch();
}

void admin()
{
char admin_pwd[20] = "password",admin_nm[20] ="user";
char ch;
char admin_pwd1[20], admin_nm1[20];
int i;
clrscr();
printf("-------------------------------------------------------------------\n");
printf("          WELCOME  TO LIBRARY MANAGEMENT    SYSTEM\n");
printf("-------------------------------------------------------------------\n\n\n");
printf("\t................................ADMIN  LOGIN..........................\n\n\n");
   printf("Enter User id: ");
scanf("%s",admin_nm1);
printf("Enter Password:  ");
gets(admin_pwd1);
 i=0;
   while(ch!=13){
    ch = getch();	if(ch!=13 && ch!=8){
     putch('*');
     admin_pwd1[i]=ch;
     i++;
     }
    }

 if(strcmp(admin_nm1,admin_nm)==0)
  {
     if(strcmp(admin_pwd1,admin_pwd)==0){
     printf("correct");
	   admin_se();   }
	   else
	   printf("\n\nINCORRECT PASSWORD");


       }
else
{
printf("\nINCORRECT PASSWORD");
 }
}






void main()
{
int opt;
FILE *bk_f,*stud_f;
do{
clrscr();
printf("\n\n--------------------------------------------------------------------------------\n");
printf("                        WELCOME  TO LIBRARY SYSYTEM");
printf("\n-------------------------------------------------------------------------------\n\n");
printf("1. LIBRARIAN LOGIN");
printf("\n2. READER LOGIN");
printf("\n3. EXIT \n");
printf("__________________________\n\n");
printf("\n Enter Your Choice   :    ");
scanf("%d",&opt);
switch(opt)
{
		case 1:
			admin();
			break;

		case 2:
			reader();
			break;
		case 3:
		exit();
			}
			}
while(opt!=3) ;
getch();
}




