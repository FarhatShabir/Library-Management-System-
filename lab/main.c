#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
void returnbook();
int acceptbook();
void getbookname(int );
int findbookcode();
void assignbook();
void modifybook();
void modifymember();
void deletemember();
void editmenu1();
 void addbook();
 void deletebook();
 void addmember();
 void showmember();
 void showbooks();
 void search();
  void intro();
 void intro()
 {

	 printf(" \n \t\t\t\t Welcome to Project") ;
	printf("\n \t\t\t\t B O O K  L I B R A R Y ") ;

	printf("\n\n \t\t YOU SHOULD BE A MEMBER THEN YOU CAN GET BOOKS \n");
	printf("\n\n \t\t This  project has facility of maintaining  records") ;
	printf("\n \t\t of BOOKS and MEMBERS.") ;


	printf("\n\n \t\t This  project  can  hold more  than  10,000  books") ;

	printf("\n \t\t records." );

	printf("\n\n \t\t One member can issue Two books.");
	printf("\n\n \t Group Members  :-\n \t Farhat Shabir ");

	printf("\n\n \t\t\t\tPress any key to continue") ;

	getch() ;
	 }
 void menu();
   struct book
   {
   	int code,copies;
   	char bname[33],bauthor[33];
   	float price;
   };
   struct member
   {
   	int code;
   	char mname[40],phone[15];
   	int bcode[2];
   	int bookisued;
   };
   int main()
   {
      	intro();

   	system("cls");
   	menu();
   	return 0;
   }
      void menu()
    {
    	char ch;
         while(1)
		 {
		 	system("cls");
		 	printf("\n\t\t\t\t\t\t\t\t\t By : FarHat ShaBir ");

		 	printf("\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		 	printf("\n \t\t\t ~    L I B R A R Y  M A N A G E M E N T   ~");
		 	printf("\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		 	printf("\n");

 		printf("\n\t\t1. ADD NEW BOOK\n \t\t2. ADD NEW MEMBER\n \t\t3. ISSUE BOOK\n \t\t4. RETURN BOOK\n \t\t5. LIST OF BOOKS\n \t\t6. LIST OF MEMBERS\n \t\t7. EDIT\n \t\t8. SEARCH\n \t\t0. QUIT\n");
 		printf("\n\t\t Enter YOUR CHOICE :: ");

		 ch=getch();
		 switch (ch)
		      {
      			case '1':

      			addbook();
      			break;
      			case '2':

      			addmember();
      			break;
      			case '3':

      			assignbook();
      			break;
      			case '4':

      		   returnbook();
      			break;
      			case '5':

      			showbooks();
      			break;
      			case '6':

      			showmember();
      			break;
      			case '7':

      			      editmenu1();
				  break;
				  case '8':
				  search();
				  break;
      			case '0':
      			exit(1);
      			default:
      			system("cls");
      			printf("\n\n\n\n\n\n \t\t\t E N T E R  C O R R E C T  O P T I O N !!!!!!!!");
      			  printf("\n\t\t\t\t P r e s s  A n y  K e y ");
				  getch();
  	     	  }
 		}
    }
     //add books
      void addbook()
      {
      	char cho;
      struct book b;
      int code,flag;
      FILE *fp;
      w:
      system("cls");
 printf("\n\n \t\t\t\t   A D D  B O O K");
	  printf("\nEnter Code of Book ::");
	  scanf("%d",&code);
	  flag=0;
	  fp=fopen("book.dat","ab+");
	    while(fread(&b,sizeof(b),1,fp)==1)
		{
		if(code==b.code)
		{
			printf("\n \t\t\t\tC o d e  A l r e a d y  E x i s t s");
			getch();
			flag=1;
			goto w;
		}
		}
		if(code==0 || code <0)
		{
			printf("\n \t\t\t\t E n t e r  A  V a l i d  B o o k  C o d e  ! ! !");
			getch();
			goto w;
		}
		if(flag==0)
		{
		b.code=code;
		fflush(stdin);
		a:
		printf("\nEnter Name of Book  ::");
		gets(b.bname);
		   if(strlen(b.bname)<3)
		   {
   			printf("\n Name too Small \n \t should be greater than 2 words");
   			goto a;
   		}
   		b:
		printf("\nEnter Author Name  ::");
		gets(b.bauthor);
		if(strlen(b.bauthor)<3)
		   {
   			printf("\n \t\t\tN a m e  t o o  S m a l l  \n \t\t\t\t Should Be Greater Than 2 Words !!!!!!!!!");
   			getch();
			   goto b;
   		}
   		c:
		printf("\nEnter Price of the Book  ::");
		scanf("%f",&b.price);
		if(b.price==0 || b.price<0)
		   {
   			printf("\n You Have Enter Wrong Price !!!!!!!!!!");
   		  getch();
		   goto c;
   		}
   		d:
		printf("\nEnter Number of Copies  ::");
		scanf("%d",&b.copies);
		if(b.copies==0 || b.copies<0)
		{
			printf(" \nEnter valid number !!!!!!");
			getch();
			goto d;
		}
		 printf("DO YOU WANT TO SAVE THE BOOK\n\t 'y' -->YES \t 'n' --> NO  \t 'm' --> MENU\n");
		 cho=getch();
		  if(cho=='y' || cho=='Y')
		  {
  			fwrite(&b,sizeof(b),1,fp);
  			printf("\n \t\t\t\t B o o k  S a v e  S u c e s s f u l l y \n");
  			getch();
		   }
		else if(cho=='n')
		   {
		   	printf("\n\t Enter Again the Information !!!!");
		   	getch();
   			goto w;
   		   }
			  else
			  {
			  	fclose(fp);
  				menu();
  			}
		}
		fclose(fp);
      }
        //show books

           void showbooks()
           {
           	FILE *fp;
           	struct book b;
           	system("cls");
           	 printf("\n\n \t\t\t\t   S H O W  B O O K");
           	 fp=fopen("book.dat","rb+");

           	 printf("\n CODE     BOOK NAME                       AUTHOR                           PRICE     COPIES");
           	 printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				while(fread(&b,sizeof(b),1,fp)==1)
           	 {
 	           	printf("\n  %d      %s            %s                     %f      %d",b.code,strupr(b.bname),strupr(b.bauthor),b.price,b.copies);

			    }
 	           fclose(fp);
 	           printf("\n\n \t\t\t\t P r e s s  A n y  K e y ");
 	          getch();

           }

    //add member
	void addmember()
	{
		FILE *fp;
		char cho;
		struct member m;
		int mid,flag;
		fp=fopen("member.dat","ab+");
		X:
		system("cls");
		printf("\n\n \t\t\t\t   A D D  M E M B E R");
		printf("\nEnter Member ID  ::");
		scanf("%d",&mid);
		flag=0;
		  while(fread(&m,sizeof(m),1,fp)==1)
		  {
  			if(m.code==mid)
  			{
			  	printf("\n \t\t\t\t M E M B E R  I D  I N  U S E ! ! ! !");
			  	getch();
				  flag=1;

			  	goto X;
			  }
  		   }
  		   if(mid==0 || mid < 0)
  		   {
   		  	printf("\n \t\t\t\tEnter a Valid Member ID !!!!!!");
   		  	getch();
				 goto X;
   		   }
  		   if(flag==0)
  		   {
  		   	m.code=mid;
  		   	a:
   		   printf("\nEnter Name Of Member  ::");
   		   fflush(stdin);
			  gets(m.mname);
			  if(strlen(m.mname)<3)
			  {
  				printf("\nName too Small!!!!!");
  				getch();
				  goto a;
  			}
              x:
			  printf("\nEnter Phone Number Of Member  ::");
			  gets(m.phone);
			  if(strlen(m.phone)!=10)
			  {
  				printf("Enter Valid 10 Digit Mobile Number");

  				goto x;
  			}
			  m.bcode[0]=0;
			 m.bcode[1]=0;
			 m.bookisued=0;
		printf("DO YOU WANT TO SAVE THE MEMBER\n\t 'y' -->YES \t 'n' --> NO 'm' --> MENU\n");
		 cho=getch();
		  if(cho=='y')
		  {
  			fwrite(&m,sizeof(m),1,fp);
  			printf("\n \t\t\t\t M e m b e r  S a v e  S u c e s s f u l l y ");
            getch();
		   }
		else if(cho=='n')
		   {
		   	printf("\nEnter Again the Information");
   		    getch();
			   addmember();
   		   }
			  else
			  {
			  	fclose(fp);
  				menu();

  			  }
   		   }
		    fclose(fp);
	}
	    //show member
	    void showmember()
	    {
    	FILE *fp;
    	struct member m;
    	system("cls");
    	printf("\n\n \t\t\t\t   S H O W  M E M B E R");
    	fp=fopen("member.dat","rb+");
    	printf("\n MCODE     BOOK CODE                   NAME                       PHONE              NO OF BOOK");
    	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    	 while(fread(&m,sizeof(m),1,fp)==1)
    	 {
 	    	printf("\n %d          %d , %d                    %s                  %s             %d",m.code,m.bcode[0],m.bcode[1],strupr(m.mname),m.phone,m.bookisued);
 	     }
		fclose(fp);
		printf("\n");

		printf("\n\t\t\t\t P r e s s  A n y  K e y ");
 	           getch();
 	}
       //delete books
	   void deletebook()
	   {
   		FILE *fp,*fb;
   		int bcod,flag=0;
   		char bname[20],bauthor[20],cho;
   		struct book b;
   	   			 del:
   	   			 system("cls");
   		 fp=fopen("book.dat","rb+");
   		 fb=fopen("temp.dat","wb+");


            rewind(fp);
   		    printf("\nEnter Book ID You Want To Delete  ::");
   		    scanf("%d",&bcod);
   		    if(bcod==0 || bcod <0)
   		    {
    		   	printf("\n \t\t\t Enter Correct Book Code !!!!!!");
    		   	getch();
				   goto del;
    		   }
   		       while(fread(&b,sizeof(b),1,fp)==1)
   		       {
   		       if(bcod==b.code)
   		       {
       		   	flag=1;
       		   	strcpy(bname,b.bname);
       		   	strcpy(bauthor,b.bauthor);

       		   }
       		   	if(bcod!=b.code)
       		   	  {
       		   	  		fwrite(&b,sizeof(b),1,fb);
	   		       }
	   		   }
	   		   if(flag==0)
	   		   {
   		   		printf("\n\t\t\t N o  B o o k  R e c o r d  F o u n d !!!!!\n\t\t\t\n 'Y' Delete Another 'M' Menu");
   		   		cho=getch();
   		   		  fclose(fp);
       		      fclose(fb);
  		   		  if(cho=='y' || cho =='Y')
  		   		  {
  		   		  	fclose(fb);
  		   		  	fclose(fp);
 		   		  	deletebook();

  		   		  }
  		   		  else
  		   		  {
  		   		       fclose(fp);
					   fclose(fb);
					   remove("temp.dat");
					   return;
  		   		  }
   		   	   }
   		   	   if(flag==1)
   		   	   {
     	   		   printf("\n\t\t\tBook  Name is ::  %s",strupr(bname));
	     		   printf("\n\t\t\tBook Author is ::  %s",strupr(bauthor));
         		   printf("\n");
			    	  fclose(fp);
       		       fclose(fb);
       		   printf("\n\tDo You Want To Delete That Book\n \t 'y' Yes \t 'n' No  \t 'm' Menu ");
       		       cho=getch();
       		        if(cho=='y' || cho=='Y')
       		        {
       		              remove("book.dat");
       		              rename("temp.dat","book.dat");
       		              printf("\n\t\t\t\t Book Deleted Sucussful");
       		              getch();
       		              fb=fopen("book.dat","rb+");
       		              fclose(fb);
       		              return;
					   }
       		        else if(cho=='n' || cho=='N')
       		          {
        		      remove("temp.dat");
        		      return;
        		       }

       		           else
       		           menu();
   		       }
	   }
		// edit menu back in edit
		 void editmenu1()
		  {
		  	char ch;
 		while (1)
      			      {
      			      	system("cls");
                          printf("\n\n \t\t\t\t   E D I T  M E N U");
      			      printf("\n \t\t 1. BOOKS \n \t\t 2. MEMBERS \n \t\t 0. BACK ");
      			      	printf("\n \t\t Enter YOUR CHOICE :: ");
      			      ch=getch();
      			         switch (ch)
      			          {
          			      	case '1':

          			      	printf("\n \t\t\t      B O O K ' S");

									while(1){
                                   system("cls");
          			      	printf("\n\t\t\t 1. DELETE BOOKS \n \t\t\t 2. MODIFY EXISTING BOOK \n \t\t\t 0. BACK");
          			      	printf("\n\t\t Enter YOUR CHOICE :: ");
								ch=getch();
          			      	  switch(ch)
								  {
  									case '1':
  									deletebook();
  									break;
  									case '2':
  									modifybook();
  									break;
  									case '0':
  									editmenu1();
  									break;
  								}
          			      	}

          			      	case '2':

          			      	printf("\n\t\t\t    M E M B E R ' S");

								  	while(1){
                             system("cls");
          			      	printf("\n\t\t\t 1. DELETE MEMBER\n \t\t\t 2. MODIFY MEMBER \n\t\t\t 0. BACK");
          			      	printf("\n\t\t Enter YOUR CHOICE :: ");
								ch=getch();
          			      	  switch(ch)
								  {
  									case '1':
  									deletemember();
  									break;
  									case '2':
  									modifymember();
  									break;
  									case '0':
  									editmenu1();
  									break;
  								}
          			      	}
          			      	case '0':
          			      	menu();
          			      	default:

          			      	printf("\nEnter Correct Option");
          			      	getch();
          			      }
      			      }
 		  }


			  void deletemember()
			  {
  				FILE *fp,*fm;
  				struct member m;
  				int code,flag;
  				char name[33],ph[33],cho;
  				system("cls");
  				fp=fopen("member.dat","rb+");
  				fm=fopen("Temp.dat","wb+");
  				printf("\n Enter Code Of Member You Want To Delete  ::");
  				scanf("%d",&code);
  				flag=0;
 				 if(code==0 || code<0)
 				 {
 				 	printf("\n\t\t\t Enter Correct Code");
 				 	getch();
 				 	deletemember();
 				 }
  				  while(fread(&m,sizeof(m),1,fp)==1)
  				  {
  				  if(code==m.code && m.bookisued>0)
  				  {
  				  	printf("\n Can Not Delete The Member \n Because Member has Books Assigned");
  				  	fclose(fp);
  				  	getch();
  				  	fclose(fm);
  				  	remove("Temp.dat");
  				  	return;

  				  }
  				  	else if(code==m.code)
  				  	  {
	  				  strcpy(name,m.mname);
						strcpy(ph,m.phone);
						flag=1;
	  				  }
	  				  if(code!=m.code)
							{
  				  		fwrite(&m,sizeof(m),1,fm);
  				  	     }
  				    }
  				    if(flag==0)
  				    {
    				  printf("\n \t\t\t No Member Found !!!!!!");
    				  fclose(fp);
  				      getch();
						fclose(fm);
					  return;
					  }
  				    fclose(fp);
  				    fclose(fm);
  				    printf("\n\nMember Name is  ::%s",strupr(name));
  				    printf("\nMember Phone Number is ::%s",strupr(ph));
  				     printf("\n\n\tDo You Want To Delete That Member\n \t 'y' Yes \t 'n' No \t 'm' Menu ");
       		       cho=getch();
       		        if(cho=='y' || cho=='Y')
       		        {

       		        	printf("\n\n \t\t\t Member Deleted Sucusfully !!");
       		              getch();
							 remove("member.dat");
       		              rename("Temp.dat","member.dat");
       		              fp=fopen("member.dat","rb+");
       		              fclose(fp);
       		        }
       		        else if(cho=='n' || cho=='N')
       		          {
        		      remove("Temp.dat");
        		       }
        		       else if(cho=='b' || cho == 'B')
        		       {
       		        	editmenu1();
       		           }
       		           else
       		           menu();
  			}

  			 void modifymember()
  			 {
 			  	FILE *fp;
 			  	struct member m;
 			  	int code,flag,newcode;
 			  	char ch;
 			  	system("cls");
 			  	fp=fopen("member.dat","rb+");
 			      printf("\nEnter Member Code You Want To Modify  ::");
				   scanf("%d",&code);
				   flag=0;
				   rewind(fp);
				     while(fread(&m,sizeof(m),1,fp)==1)
					 {
					 	if(m.bookisued>0)
					 	{
	 						printf("\n \t\t Can't Modify Member !!!!!");
	 						getch();
							 return;
	 					}
 						if(code==m.code && m.bookisued==0)
 						{
 						   flag=1;
 						   c:
						 	printf("\nEnter New Member ID  ::");
						 	scanf("%d",&newcode);
						 	if(newcode==0 || newcode<0)
						 	{
	 							printf("\n Enter Valid code");
	 															 goto c;
	 						}
						 	rewind(fp);
						 	while(fread(&m,sizeof(m),1,fp)==1)
						 	{
	 							if(newcode==m.code)
	 							{
							 		printf("\n Member Exists !!!!");
							 		getch();
									 goto c;
							 	}
	 						}
						 	fflush(stdin);
						 	m.code=newcode;
						 	a:
						 	printf("\nEnter New Member Name  ::");
						 	gets(m.mname);
						 	 if(strlen(m.mname)<3)
						 	 {
 	 							printf("\nEnter Vallid Member Name at Least 3 charsters");
 	 							getch();
 	 										  goto a;
 	 						}
 	 						b:
						 	printf("\nEnter New Phone Number  ::");
						 	gets(m.phone);
						 	if(strlen(m.phone)<10)
						 	{
	 							printf("Enter Valid 10 Digit Mobile Number");
	 							getch();
								 goto b;
	 						}
						 	fseek(fp,-sizeof(m),SEEK_CUR);
						 	fwrite(&m,sizeof(m),1,fp);
						 	fclose(fp);
						 	printf("\n Member Modifiyed");
						 	getch();
							 return;
						 }
	 					}
						 if (flag==0)
						 {
 							printf("\n No match found !!!!!!");
 							printf("\nDo You want To Modify Another \n 'y' YES \t 'n' NO  \t 'm' MENU \n");
 							ch=getch();
 							if(ch=='y' || ch=='Y')
 							{
							 	modifymember();
							 }
							 if (ch=='n' || ch=='N')
							 {
 								editmenu1();
 							}
 							else
 							menu();

 						}
 						fclose(fp);
 			  }


 			    //assign book
 			    void assignbook()
 			    {
 			    	int mcode;
 			    	FILE *fp;
 			    	int countb,bookcode,flag;
 			    	char ch;
 			    	struct book b;
 			    	struct member m;
 			    	system("cls");
 			    	printf("\n\n \t\t\t\t   A S S I G N  B O O K ");
 			    	   printf("\nEnter Code Of Member  ::");
 			    	   scanf("%d",&mcode);
 			    	     fp=fopen("member.dat","rb+");
 			    	     flag=0;
 			    	     while(fread(&m,sizeof(m),1,fp)==1)
 			    	      {


     	    			    if(mcode==m.code)
							 {
								flag=1;
							 	  if(m.bookisued>=2)
							 	  {
  	 							 printf("\n \t Book Can Not be Issued Because Member Has Priveious Books");
									getch();
									fclose(fp);
									return;
  	 							}
 								bookcode=findbookcode();
 							   	if(bookcode!=0)
 							   	{

 								m.bookisued=m.bookisued+1;
 								printf("\n****************************************************");
 								getbookname(bookcode);
 								printf("\nMember Name  :: %s",strupr(m.mname));
 								printf("\n****************************************************");
 								printf("\nDo You Want To Continue\n 'y' YES \t 'n' NO \t 'm' MENU");
 								ch=getch();
 								if(ch=='y' || ch=='Y')
 								{
 								   if(m.bcode[0]==0)
 								     m.bcode[0]=bookcode;
 								    else if(m.bcode[1]==0)
 								     m.bcode[1]=bookcode;
 								    fseek(fp,-sizeof(m),SEEK_CUR);
 								    printf("\n \n\t\tBook Sucussfully Asign");
									getch();
									 fwrite(&m,sizeof(m),1,fp);
									 fclose(fp);
									 return ;
 								}
 								else if(ch=='n' || ch=='N')
 								{

								 	fclose(fp);
								 	fp=fopen("book.dat","rb+");
								 	   while(fread(&b,sizeof(b),1,fp)==1)
								 	   {
   	 									if(bookcode==b.code)
   	 								     	{
									 	   	b.copies=b.copies+1;
									 	   	fseek(fp,-sizeof(b),SEEK_CUR);
									 	   	fwrite(&b,sizeof(b),1,fp);
									 	   	fclose(fp);
									 	   }
   	 								    }
								 	return;
								 }
						     	 else
								 {
 									fclose(fp);
 									fp=fopen("book.dat","rb+");
								 	   while(fread(&b,sizeof(b),1,fp)==1)
								 	   {
   	 									if(bookcode==b.code)
   	 								     	{
									 	   	b.copies=b.copies+1;
									 	   	fseek(fp,-sizeof(b),SEEK_CUR);
									 	   	fwrite(&b,sizeof(b),1,fp);
									 	   	fclose(fp);
									 	   }
   	 								    }
 									menu();
 								}

 							   	}
			     	        }
     	    			  }
 			    	if(flag==0)
					 printf("\nNo Member Found !!!!!");
					 getch();
					 fclose(fp);

    			 }    //close assign fxn

    			 int findbookcode()
    			 {
 			    	FILE *fp;
 			    	struct book b;
 			    	int bcode;
 			    	int flag;
 			    	//system("cls");
 			    	fp=fopen("book.dat","rb+");
                     tt:
 			    	printf("\nEnter The Book Code  :: ");

 			    	scanf("%d",&bcode);
 			    	if(bcode<=0)
 			    	{
	    			 	printf("\nEnter Valid Book Code");
	    			 goto tt;
					 }
 			    	flag=0;
 			    	 while(fread(&b,sizeof(b),1,fp)==1)
 			    	 {
 	    			    if(bcode==b.code)
						 {
 							flag=1;
 							if(b.copies==0)
 							{
							 	printf("\n This Book is Not Available");
                                getch();
							 	fclose(fp);
							 	return 0;
							 }
 							b.copies=b.copies-1;
 							fseek(fp,-sizeof(b),SEEK_CUR);
 							fwrite(&b,sizeof(b),1,fp);
 							fclose(fp);
 							return bcode;
 						 }
 	    			 }
 	    			 if(flag==0)
    			 {
 	    			 printf("\n\n\t\t\t\t You Have Enter Wrong Book Code \t\t\t\t \nEnter A Valid Book Code !!!!");
 	    			 getch();
					  return 0;
    			 }
			    fclose(fp);
			    return 0;
				 }
				 // get book name

				 void getbookname(int u)
				 {
				 	FILE *fb;
				 	struct book b;

				 	fb=fopen("book.dat","rb+");
				 	  while(fread(&b,sizeof(b),1,fb)==1)
				      {
 					  if(b.code==u)
 					     {
     					 	printf("\nName of Book is :: %s ",strupr(b.bname));
     					 	printf("\nAuthor of Book is :: %s ",strupr(b.bauthor));
     					 }
 				      }
		           fclose(fb);
 				}
 				//modify book
				      void modifybook()
					{
 					FILE *fp;
 			  	struct book b;
 			  	int code,flag,newbid;
 			  	char ch;
 			  	system("cls");
 			  	fp=fopen("book.dat","rb+");
 			  	yz:
 			      printf("\nEnter Book Code You Want To Modify  ::");
				   scanf("%d",&code);
				   flag=0;
				   rewind(fp);
				     while(fread(&b,sizeof(b),1,fp)==1)
					 {
 						if(code==b.code)
 						{
 						   flag=1;
 						   yy:

						 	rewind(fp);
						 	b.code=code;
						 	a:
						 	fflush(stdin);
						 /*	printf("\nEnter New BOOK Name  ::");
						 	gets(b.bname);
						 	  if(strlen(b.bname)<3)
						 	  {
  	 							printf("Enter Valid Book Name \n Atleast 3 words");
  	 							goto a;
  	 						}
  	 						b:
						 	printf("\nEnter Author Name  ::");
						 	gets(b.bauthor);
						 	   if(strlen(b.bauthor)<3)
						 	  {
  	 							printf("Enter Valid Author Name \n Atleast 3 words");
  	 							goto b;
  	 						} */
  	 						c:
						 	printf("\nEnter New Price of Book  ::");
						 	scanf("%f",&b.price);
						 	  if(b.price<=0 )
						 	  {
  	 							printf("\n Enter Correct Price");
  	 							goto c;
  	 						}
						 	d:
						 	printf("\nEnter Number of Copies  ::");
						   scanf("%d",&b.copies);
						     if(b.copies <= 0)
						     {
     							printf("\nEnter Copies Correctly");
     							goto d;
     						}
						 	fseek(fp,-sizeof(b),SEEK_CUR);
						 	fwrite(&b,sizeof(b),1,fp);
						 	fclose(fp);
						 	printf("\n  \t\t BOOK MODIFIYED ");
						 	getch();
						 	return;
						 }
	 					}
						 if (flag==0)
						 {
 							printf("\n No match found !!!!!!");
 							printf("\n\t Do You want To Modify Another \n 'y' YES \t 'n' NO  \t 'm' MENU \n");
 							ch=getch();
 							if(ch=='y' || ch=='Y')
 							{
 							fclose(fp);
 								modifybook();
							 	goto yz;
							 }
							 if (ch=='n' || ch=='N')
							 {
 								editmenu1();
 							}
 							else
 							menu();

 						}
 						fclose(fp);

					 }
					 int acceptbook()
				    {
    					FILE *fb;
    					struct book b;
    					int bid,flag;
    					char ch;
    					a:
    					printf("\nEnter Book Id to Return  :: ");
    					scanf("%d",&bid);

    					fb=fopen("book.dat","rb+");
    					flag=0;
    					if(bid==0 || bid<0)
    					{
					    	printf("Enter A Valid Book Number !!!! \n Or Enter 'M' MENU");
					    	ch=getch();
					    	if(ch=='m' || ch=='M')
					    	menu();
					    	goto a;
					    }

    					  while(fread(&b,sizeof(b),1,fb)==1)
    					  {

  					     if(bid==b.code)
  					    	{
  					    		flag=1;
	    					 b.copies=b.copies+1;
							 fseek(fb,-sizeof(b),SEEK_CUR);
							 fwrite(&b,sizeof(b),1,fb);
							 fclose(fb);
							 return bid;

	    					  }
  					      }
  					      if(flag==0)
  					      {
      					  	printf("\nNo Book found!!!!!!!");
      					  	 fclose(fb);
					  }
					  return 0;
				      }

 			void returnbook()
 				{
 					int mid,first,sec,getb;
 					FILE *fp;
 					int flag;
 					struct member m;
 					char ch;
 				system("cls");
 					printf("\n\n \t\t\t\t   R E T U R N  B O O K");
 					fp=fopen("member.dat","rb+");
 					 printf("\nEnter Member ID  ::");
					  scanf("%d",&mid);
					  flag=0;
					    while(fread(&m,sizeof(m),1,fp)==1)
						{

							 if(mid==m.code)
							{

								flag=1;
								if(m.bookisued!=0)
							printf("\n Member Has %d Books Assign\n Book Code Are %d , %d ",m.bookisued,m.bcode[0],m.bcode[1]);
							else if(m.bookisued==0)
							{
								printf("\n Member has No Book Issued");
							getch();
							return;
							}
							getbookname(m.bcode[0]);
							getbookname(m.bcode[1]);
							printf("\n\n Do You Want to Continue \n \t 'y' Yes \t 'n' No \t 'm' Menu");
							ch=getch();
							if(ch=='y' || ch=='Y')
						      	{
							getb=acceptbook();
							if(getb==0)
						            	{
								printf("\nsomething Went wrong!!!!");
								getch();
								returnbook();
						             	}
							 if(m.bcode[0]==getb)
							       {
 							    m.bcode[0]=0;
 							    goto p;
 						         	}
 						          if(getb==m.bcode[1])
 						         	{
	         						 	m.bcode[1]=0;
	         						 }
	         						 p:
	         						 m.bookisued=m.bookisued-1;
	         						 fseek(fp,-sizeof(m),SEEK_CUR);
	         						 fwrite(&m,sizeof(m),1,fp);
	         						 printf("\n \t BOOK HAS BEEN RECEVED \n\n \t\t Thank You ....");
									  getch();
	         							fclose(fp);
									  menu();
							}//if close
							 if(ch=='n' || ch=='N')
							{
								fclose(fp);
								return;
							}
							else
							{
								fclose(fp);
								return;
							}
						}//another if
						}//close while
						if(flag==0)
				printf("\nMember Not found!!!!!");
 				getch();
				 }//close fxn
// fxn search
 		void search()
 		{
 			char ch,name[40];
 			int id,flag;
 			struct book b;
 			struct member m;
 			FILE *fp;
		 	while(1)
		 	{
		 		system("cls");
		 		printf("\n \t\t\t\t S E A R C H ");
	 		printf("\n \t\t 1. BOOKS \n \t\t 2. MEMBER \n \t\t 0. MENU");
	 		printf("\n \t\t\t Enter Your Choice ::");
			 ch=getch();
			 switch (ch)
			   {
			   	case '1':
			   	while(1)
			   	{
			   		system("cls");
			   		printf("\n \t\t\t\t S E A R C H  B O O K");
	   		     printf("\n \t\t 1. Search With Id \n \t\t 2. Search with Name \n \t\t other key to exit");
	   		     printf("\n \t\t\t Enter Your Choice ::");
					ch=getch();

	   		     if(ch=='1')
	   		         {
	   		         	fp=fopen("book.dat","rb+");
     		   		  printf("\n\n\n Enter Id of the Book :: ");
     		   		  scanf("%d",&id);
     		   		  flag=0;
     		   		    while(fread(&b,sizeof(b),1,fp)==1)
     		   		    {
    		   		     if(id==b.code)
							{
								flag=1;
								printf("\n \t\t*****************************");
								printf("\n \t\tCode of Book is :: %d",b.code);
								printf("\n \t\tName of Book is :: %s " ,strupr(b.bname));
								printf("\n \t\tAuthor of Book is :: %s ",strupr(b.bauthor));
								printf("\n \t\tPrice of Book is :: %f ",b.price);
								printf("\n \t\tCopies of Book is :: %d",b.copies);
								printf("\n \t\t*****************************");
								fclose(fp);
								getch();
								return;
							}
    		   		     }
    		   		     if(flag==0)
    		   		     {
     		   		    	printf("\n \t\t No Book found");
     		   		    	getch();
     		   		    	return;
     		   		    }
     		   	      }
     		   	      else if(ch=='2')
     		   	      {
      	   		     fp=fopen("book.dat","rb+");
     		   		  printf("\n\n\n Enter Name of the Book :: ");
     		   		  gets(name);
						 flag=0;
     		   		    while(fread(&b,sizeof(b),1,fp)==1)
     		   		    {
    		   		     if(strcmp(strupr(name),strupr(b.bname))==0)
							{
								flag=1;
								printf("\n \t\t*****************************");
								printf("\n \t\tCode of Book is :: %d",b.code);
								printf("\n \t\tName of Book is :: %s " ,strupr(b.bname));
								printf("\n \t\tAuthor of Book is :: %s ",strupr(b.bauthor));
								printf("\n \t\tPrice of Book is :: %f ",b.price);
								printf("\n \t\tCopies of Book is :: %d",b.copies);
								printf("\n \t\t*****************************");
								fclose(fp);
								getch();
								return;
							}
    		   		     }
    		   		     if(flag==0)
    		   		     {
     		   		    	printf("\n \t\t No Book found");
     		   		    	getch();
     		   		    	return;
     		   		    }
      	   		     }
      	   		     else
      	   		     return;
			   	}
			   case '2':
			  // searchmember();
			     while(1)
			     {
			     	system("cls");
			     	printf("\n \t\t\t\t S E A R C H   M E M B E R");
     				printf("\n \t\t 1. Search By ID \n \t\t 2. Search By Name \n \t\t Other Key to exit");
     				 printf("\n \t\t\t Enter Your Choice ::");
     				ch=getch();
     				  switch (ch)
     				  {
  				     	case '1':
  				     	printf("\n\n\n \t\t Enter ID of Member  ::");
  				     	scanf("%d",&id);
  				     	fp=fopen("member.dat","rb+");
  				     	flag=0;
  				     	  while(fread(&m,sizeof(m),1,fp)==1)
  				     	  {
  	     				  	if(id==m.code)
  	     				  	{
  	     				  		flag=1;
  	     				  		printf("\n \t\t*****************************");
	  				     	  	printf("\n \t\t Member Code id  :: %d",m.code);
	  				     	  	printf("\n \t\t Member Name is  :: %s",strupr(m.mname));
	  				     	  	printf("\n \t\t Member Phone Number is  :: +91(%s)",m.phone);
	  				     	  	printf("\n \t\t Book issued Codes Are  :: %d  ,  %d ",m.bcode[0],m.bcode[1]);
	  				     	  	printf("\n \t\t Number Of Book Issued are  :: %d ",m.bookisued);
	  				     	  	printf("\n \t\t*****************************");
	  				     	  	fclose(fp);
	  				     	  	getch();
	  				     	  	return;
	  				     	  }
  	     				  }
  				     	   if(flag==0)
							  {
  								printf("\n \t\t\t NO Member Found");
  								fclose(fp);
  								getch();
  								return;
  							}
  				     	break;
  				          	case '2':
  				          	//search by name
  				          	   printf("\n\n\n \t\t Enter Name of Member :: ");
  				          	   gets(name);
  				          	   fp=fopen("member.dat","rb+");
  				          	   flag=0;
  				          	     while(fread(&m,sizeof(m),1,fp)==1)
  				          	     {
     	          				  	if(strcmp(strupr(name),strupr(m.mname))==0)
     	          				  	{
	  				          	     flag=1;
  	     				  		printf("\n \t\t*****************************");
	  				     	  	printf("\n \t\t Member Code id  :: %d",m.code);
	  				     	  	printf("\n \t\t Member Name is  :: %s",strupr(m.mname));
	  				     	  	printf("\n \t\t Member Phone Number is  :: +91(%s)",m.phone);
	  				     	  	printf("\n \t\t Book issued Codes Are  :: %d  ,  %d ",m.bcode[0],m.bcode[1]);
	  				     	  	printf("\n \t\t Number Of Book Issued are  :: %d ",m.bookisued);
	  				     	  	printf("\n \t\t*****************************");
	  				     	  	fclose(fp);
	  				     	  	getch();
	  				     	  	return;
     	          				  	}
	  				          	     }
	          	         if(flag==0)
							  {
  								printf("\n \t\t\t NO Member Found");
  								fclose(fp);
  								getch();
  								return;
     	          				  }

  				          default:
  				          return;
  				     }

     			}
			   break;
			   case '0':

			   menu();
			   break;
			   default:
			   printf("\n \t\t Enter Correct Choice");

			   }

 			}
 		}
