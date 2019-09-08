//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
void secure(int , int );
class fir
{
 int fno;
 char type[50],date[10],time[10];
 long char descr[200],evid[100],ivict[100];
 public:
	void register_fir()
	{
	 cout<<"\nPlease Enter The F.I.R No. Of The F.I.R "<<endl;
	 cin>>fno;
	 cout<<"\n\nPlease Enter The Type of The Crime "<<endl;
	 gets(type);
	 cout<<"\nPlease Enter The Date of The Incident (dd/mm/yy)"<<endl;
	 gets(date);
	 cout<<"\nPlease Enter The Time of The Incident (AM/PM)"<<endl;
	 gets(time);
	 cout<<"\nPlease Enter The Description Of The Incident"<<endl;
	 gets(descr);
	 cout<<"\nPlease Enter The Evidence Proving The Incident"<<endl;
	 gets(evid);
	 cout<<"\nPlease Enter The Name of Eye Vitness of The Incident"<<endl;
	 gets(ivict);
	 }

	void show_fir()
	{
	 cout<<"\nThe F.I.R No. Of The F.I.R "<<endl;
	 cout<<fno;
	 cout<<"\nThe Type of The Crime "<<endl;
	 puts(type);
	 cout<<"\nThe Date of The Incident "<<endl;
	 puts(date);
	 cout<<"\nThe Time of The Incident "<<endl;
	 puts(time);
	 cout<<"\nThe Description Of The Incident"<<endl;
	 puts(descr);
	 cout<<"\nThe Evidence Proving The Incident"<<endl;
	 puts(evid);
	 cout<<"\nThe Name of Eye Vitness of The Incident"<<endl;
	 puts(ivict);
	 }

  int  retfno()
  {return fno;}

  char* rettype()
  {return type;}

  char* retdate()
  {return date;}

  char* rettime()
  {return time;}

  char* retdescr()
  {return descr;}

  char* retevid()
  {return evid;}

  char* retivict()
  {return ivict;}

};         //class ends here



//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

 fstream fp;
 fir pr;


//***************************************************************
//    	function to write in file
//****************************************************************

void write_fir()
   {
    clrscr();
    fp.open("FIR.dat",ios::out|ios::app);
    pr.register_fir();
    fp.write((char*)&pr,sizeof(fir));
    fp.close();
    cout<<"\n\nThe F.I.R Has Been LOGGED \1\1";
    getch();
   }


//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all()
{
    clrscr();
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD \n\n";
    fp.open("FIR.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(fir)))
	{
	 pr.show_fir();
	 cout<<"\n\n===============================================================================\n";
	 getch();
	 }
    fp.close();
    getch();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    clrscr();
    int flag=0;
    fp.open("FIR.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(fir)))
	{
	 if(pr.retfno()==n)
		{
		 clrscr();
		 pr.show_fir();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\nrecord not exist";
    getch();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_fir()
{
    int no,found=0;
    clrscr();
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The F.I.R No. of The F.I.R";
    cin>>no;
    fp.open("FIR.dat",ios::in|ios::out);
    while(fp.read((char*)&pr,sizeof(fir)) && found==0)
	   {
	    if(pr.retfno()==no)
		   {
		    pr.show_fir();
		    cout<<"\nPlease Enter The New Details of Report"<<endl;
		    pr.register_fir();
		    int pos=-1*sizeof(pr);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&pr,sizeof(fir));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}


//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_fir()
   {
    int no;
    clrscr();
    cout<<"\n\n\n\tDelete Record of F.I.R";
    cout<<"\n\nPlease Enter The F.I.R no. of The F.I.R You Want To Delete";
    cin>>no;
    fp.open("FIR.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(fir)))
	{
	 if(pr.retfno()!=no)
		{
		 fp2.write((char*)&pr,sizeof(fir));
		 }
	 }
    fp2.close();
    fp.close();
    remove("FIR.dat");
    rename("Temp.dat","FIR.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
    }


//***************************************************************
//    	ABOUT FUNCTION
//****************************************************************

void about()
  {
    clrscr();
    cout<<"\n\n\tThis is a school project submmited for educational purposes only. This  has been an knowledge able project making me use all my C++ proggraming skills.  This had not been possible without my computer teacher Mrs. SKIMPY PANDEY."<<endl;
    cout<<"\n\n\n\tTHIS PROJECT IS DEVELOPED BY S!R DOSHHAMMER OR ACHINT KHANNA FEEL FREE  TO CONTACT FOR SUGGESTIONS AND COMPLAINTS AT -> achint.khanna@yahoo.com \1\1\1\1";
    getch();
   }

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
 int i,p;
 clrscr();
 gotoxy(30,5);
 cout<<"Rudrapur Police Station";
 gotoxy(35,10);
 cout<<"E- F.I.R";
 gotoxy(33,20);
 cout<<"Satyamev Jayte";
 cout<<"\nEnter Your ID "<<endl;
 cin>>i;
 cout<<"\nEnter your Password"<<endl;
 cin>>p;
 secure(i,p);
 getch();

}
//***************************************************************
//    	THE MAIN MENU OF PROGRAM
//****************************************************************
void accsseing_menu()
 {
  char ch;
  cout<<"\n\n\n\tACCSSEING MENU";
  cout<<"\n\n\t1.REGISTER F.I.R";
  cout<<"\n\n\t2.DISPLAY ALL F.I.R";
  cout<<"\n\n\t3.CHECKING F.I.R ";
  cout<<"\n\n\t4.MODIFY F.I.R";
  cout<<"\n\n\t5.DELETE F.I.R";
  cout<<"\n\n\t6.LOGOUT";
  cout<<"\n\n\t7.EXIT";
  cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
  ch=getche();
  getch();
  clrscr();
 do
 {
  switch(ch)
  {
    case '1': clrscr();
	      write_fir();
	      getch();
	      clrscr();
	      accsseing_menu();
	      getch();
	      break;
    case '2': clrscr();
	      display_all();
	      getch();
	      clrscr();
	      accsseing_menu();
	      getch();
	      break;
    case '3':
	       int num;
	       clrscr();
	       cout<<"\n\n\tPlease Enter The F.I.R No. ";
	       cin>>num;
	       display_sp(num);
	       getch();
	       clrscr();
	       accsseing_menu();
	       getch();
	       break;
      case '4':
		clrscr();
		modify_fir();
		getch();
		clrscr();
		accsseing_menu();
		getch();
		break;
      case '5':
		 clrscr();
		 delete_fir();
		 getch();
		 clrscr();
		 accsseing_menu();
		 getch();
		 break;
      case '6':
		clrscr();
		cout<<"\n\n\tLogging out...";
		getch();
		 intro();
		getch();
		break;
      case '7': exit(0);
      default:
		  cout<<"\n\n\n\tEntered choice do not exist" ;
  }
 }
  while(ch==7);
}
void main_menu()
 {
  clrscr();
   char ch;
  do
   {
   cout<<"\n\n\t\t\t\tMAIN MENU "<<endl;
   cout<<"\n\n\n\t\tPlease Enter The Choise Of Function You Want To Perform  "<<endl;
   cout<<"\n\n\t\t1 Acssesing menu "<<endl;
   cout<<"\n\n\t\t2 About Developer "<<endl;
   cout<<"\n\n\t\t3 Exit "<<endl;
   cout<<"\n\n\t\t\t Please Enter One Of The choises "<<endl;
   cin>>ch;
    switch(ch)
     {
      case '1':   clrscr();
		    accsseing_menu();
		  getch();
      case '2':   clrscr();
		  about();
		  main_menu();
		  getch();
      case '3':
		   exit(0);
      default:
	       cout<<"Entered Choise Is Incorrect ";
      }
   }while(ch==3);
 }

//***************************************************************
//    	THE LOGIN VERIFICATION FUNCTION OF PROGRAM
//****************************************************************

void secure(int i,int p)
{
   int id=421,pcode=721;
    if(i==id&&p==pcode)
      {
	main_menu();
      }
     else
      {
	 cout<<"\n\t\tEntered ID or Password is incorrect"<<endl;
	 getch();
	 exit(0);
      }
}

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
  intro();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
