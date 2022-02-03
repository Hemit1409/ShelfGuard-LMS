#include<fstream>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<cstdlib>
#define MAX_YR  9999
#define MIN_YR  1900
#include<ctime>
#include<conio.h>
using namespace std;
char passw[10]={"library"};
class Library
{
  char name[20];
 int BookId;
  char Title[20];
  char Author[20];
  char Category[20];
  int Pages;
  float Price;
 public:
  //Accessor Functions
 int getID(){return BookId;}
 string getName(){return name;}
  char* getTitle(){return Title;}
  char* getAuthor(){return Author;}
  char* getCategory(){return Category;}
  float getPrice(){return Price;}
  string getDate() {return cdate;}
int m;
//string sdate;
string cdate;
  //Default constructor
 Library()
  {
   BookId=0;
   strcpy(Title,"");
   strcpy(Author,"");
   strcpy(Category,"");
  Pages=0;
   Price=0;

 }

 void getBook();
 void listView();
 void showBook();
 void header();
}l;


void Library::getBook()
{
 cout<<"\tBook issued by: ";
 cin>>name;
 cout<<"\tEnter Book Id : ";
 cin>>BookId;
 cout<<"\tEnter Book Title : ";
 cin.get();
 cin.getline(Title,20);
 cout<<"\tEnter Book Author: ";
 cin.getline(Author,20);
 cout<<"\tEnter Book Category: ";
 cin.getline(Category,20);
 cout<<"\tEnter No. of Pages : ";
 cin>>Pages;
 cout<<"\tEnter Price of Book: ";
 cin>>Price;
 cout<<"\nMenu:";
cout<<"\n1. very nice";
cout<<"\n2. nice";
cout<<"\n3. good";
cout<<"\n4. average";
cout<<"\n5. bad";
cout<<"\n\nenter rate of book as per its quality: ";
cin>>m;

if(m>=1 && m<=5)
{
	if(m==1)
	cout<<"very nice";
	if(m==2)
    cout<<"nice";
	if(m==3)
	cout<<"good";
	if(m==4)
	cout<<"average";
	if(m==5)
    cout<<"bad";
}
else
{
cout<<"enter valid number";
}
//time_t timetoday;
//time (&timetoday);
//cout << "Calendar date and time as per todays is : "<< asctime(localtime(&timetoday));
//sdate = asctime(localtime(&timetoday));
//cout << "\n\nCalendar date and time as per todays is : "<< sdate;//asctime(localtime(&timetoday))
cout<< "\n\n enter date as per system date(dd-mm-yy): ";
cin>> cdate;
cout<<endl;
}

//For displaying the book details in individual form
void Library::showBook()
{
 cout<<endl;
 cout<<"Book ID      : "<<BookId<<endl;
 cout<<"Book Title   : "<<Title<<endl;
 cout<<"Author Name  : "<<Author<<endl;
 cout<<"Category     : "<<Category<<endl;
 cout<<"No. of Pages : "<<Pages<<endl;
 cout<<"Price of Book: "<<Price<<endl;
 cout<<"Issued by:     "<<name<<endl;
}

//For displaying header for Display all function
void Library::header()
{
 cout.setf(ios::left);
 cout<<setw(5)<<"I.D."
  <<setw(20)<<"Book Title"
  <<setw(20)<<"Book Author"
  <<setw(15)<<"Category"
  <<setw(6)<<"Pages"
  <<setw(6)<<"Price";
  //cout.setf(ios::right);
  cout<<setw(15)<<"quality rate"
  <<setw(15)<<"Issued by:     "
  <<setw(15)<<"issue date"<<endl;
 for(int i=1;i<=120;i++)
  cout<<"=";
 cout<<endl;
}

//For displaying in the tabular form used in Display all function
void Library::listView()
{
 cout.setf(ios::left);
 cout<<setw(5)<<BookId
  <<setw(20)<<Title
  <<setw(20)<<Author
  <<setw(15)<<Category
  <<setw(6)<<Pages
  <<setw(6)<<Price
  <<setw(15)<<m
  <<setw(15)<<name
  //<<setw(15)<<sdate
  <<setw(15)<<cdate<<endl;
}

//Function prototyping for project
void drawLine(char);//Fx for drawing line on screen.
void heading();  //Fx for heading to be displayed on each page.
void menu();  //Fx for displaying program options.
void searchMenu(); //Fx for displaying searching options.
void addBook();  //Fx for writing data to file.
void displayBooks();//Fx for reading data from file.
void searchHistory();
//Function for searching data from file.
void searchByID();
void searchByTitle();
void searchByCategory();
void searchByPrice();
void searchByAuthor();
void searchByDate();
void searchByName();
void dispose();  //Fx to shift books from main file to other file.
void modify();  //Fx to modify the book details.
void displayHistory();//Fx to display the list of disposed off books
void quality();
void charge();
void searchByIDH();
void searchByTitleH();
void searchByCategoryH();
void searchByPriceH();
void searchByAuthorH();
void searchByDateH();
void searchByNameH();
/////////////////////////////////// Global Functions Definitions ///////////////////////////////////

//Fx for drawing line on screen.
void drawLine(char ch)
{
 for(int i=1;i<100;i++)
  cout<<ch;
 cout<<endl;
}

void heading()
{
 drawLine('+');
 cout<<"\t\tL I B R A R Y   M A N A G E M E N T   S Y S T E M\n";
 drawLine('+');
}

//Fx for adding new book in file.
void addBook()
{
 ofstream fout;
 fout.open("books.dat",ios::app);
 l.getBook();
 fout.write((char*)&l,sizeof(l));
 cout<<"Book data saved in file...\n";
 fout.close();
}

//Fx for reading data from file.
void displayBooks()
{
 ifstream fin("books.dat");
 int rec=0;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(rec<1)
   l.header();
  l.listView();
  rec++;
 }
 fin.close();
 cout<<"\nTotal "<<rec<<" Records in file...\n";
}

//Fx for searching data from file.
void searchByID()
{
 int n,flag=0;
 ifstream fin("books.dat");
 cout<<"Enter Book ID : ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getID())
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with ID:"<<n<<" not available...\n";
}

void searchByDate()
{
 int flag=0;
 string n;
 ifstream fin("books.dat");
 cout<<"Enter date (dd-mm-yy): ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getDate())
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with Date:"<<n<<" not available...\n";
}
void searchByName()
{
    int flag=0;
 string n;
 ifstream fin("books.dat");
 cout<<"Enter name: ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getName())
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with this name:"<<n<<" not available...\n";
}

//Fx for searching data from file.
void searchByTitle()
{
 int flag=0;
 char title[20];
 ifstream fin("books.dat");
 cout<<"Enter Book Title : ";
 cin.ignore();
 cin.getline(title,20);
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(strcmpi(title,l.getTitle())==0)
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book with Title: "<<title<<" not available...\n";
}

//Fx for searching data from file.
void searchByCategory()
{
 int flag=0,rec=0;
 char cat[20];
 ifstream fin("books.dat");
 cout<<"Enter Book Category : ";
 cin.ignore();
 cin.getline(cat,20);
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(strcmpi(cat,l.getCategory())==0)
  {
   if(rec<1)
    l.header();
   l.listView();
   flag++;
   rec++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book with Category: "<<cat<<" not available...\n";
}

//Fx for searching data from file.
void searchByAuthor()
{
 int flag=0,rec=0;
 char aut[20];
 ifstream fin("books.dat");
 cout<<"Enter Book Author : ";
 cin.ignore();
 cin.getline(aut,20);
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(strcmpi(aut,l.getAuthor())==0)
  {
   if(rec<1)
    l.header();
   l.listView();
   flag++;
   rec++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book with Author name: "<<aut<<" not available...\n";
}

//Fx for searching data from file.
void searchByPrice()
{
 int flag=0,rec=0;
 float minrate, maxrate;
 ifstream fin("books.dat");
 cout<<"Enter Minimum Price of Book : ";
 cin>>minrate;
 cout<<"Enter Maximum Price of Book : ";
 cin>>maxrate;

 while(fin.read((char*)&l,sizeof(l)))
 {
  if(l.getPrice()>=minrate && l.getPrice()<=maxrate)
  {
   if(rec<1)
    l.header();
   l.listView();
   flag++;
   rec++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Books between Price Range: "<<minrate
      <<" and "<<maxrate<<" not available...\n";
}
//*********************************************** SEARCH HISTORY ******************************
//Fx for searching data from file.
void searchByIDH()
{
 int n,flag=0;
 ifstream fin("history.dat");
 cout<<"Enter Book ID : ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getID())
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with ID:"<<n<<" not available...\n";
}

//Fx for searching data from file.
void searchByTitleH()
{
 int flag=0;
 char title[20];
 ifstream fin("history.dat");
 cout<<"Enter Book Title : ";
 cin.ignore();
 cin.getline(title,20);
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(strcmpi(title,l.getTitle())==0)
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book with Title: "<<title<<" not available...\n";
}

//Fx for searching data from file.
void searchByCategoryH()
{
 int flag=0,rec=0;
 char cat[20];
 ifstream fin("history.dat");
 cout<<"Enter Book Category : ";
 cin.ignore();
 cin.getline(cat,20);
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(strcmpi(cat,l.getCategory())==0)
  {
   if(rec<1)
    l.header();
   l.listView();
   flag++;
   rec++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book with Category: "<<cat<<" not available...\n";
}

//Fx for searching data from file.
void searchByAuthorH()
{
 int flag=0,rec=0;
 char aut[20];
 ifstream fin("history.dat");
 cout<<"Enter Book Author : ";
 cin.ignore();
 cin.getline(aut,20);
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(strcmpi(aut,l.getAuthor())==0)
  {
   if(rec<1)
    l.header();
   l.listView();
   flag++;
   rec++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book with Author name: "<<aut<<" not available...\n";
}

//Fx for searching data from file.
void searchByPriceH()
{
 int flag=0,rec=0;
 float minrate, maxrate;
 ifstream fin("history.dat");
 cout<<"Enter Minimum Price of Book : ";
 cin>>minrate;
 cout<<"Enter Maximum Price of Book : ";
 cin>>maxrate;

 while(fin.read((char*)&l,sizeof(l)))
 {
  if(l.getPrice()>=minrate && l.getPrice()<=maxrate)
  {
   if(rec<1)
    l.header();
   l.listView();
   flag++;
   rec++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Books between Price Range: "<<minrate
      <<" and "<<maxrate<<" not available...\n";
}

void searchByDateH()
{
 int flag=0;
 string n;
 ifstream fin("history.dat");
 cout<<"Enter date (dd-mm-yy): ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getDate())
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with ID:"<<n<<" not available...\n";
}

void searchByNameH()
{
 int flag=0;
 string n;
 ifstream fin("history.dat");
 cout<<"Enter name: ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getName())
  {
   l.showBook();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with this date:"<<n<<" not available...\n";
}

void searchHistory()
{
 int ch;
 do
 {
  system("cls");
  heading();
  cout<<"BOOK SEARCH OPTIONS\n";
  cout<<"0. Back\n";
  cout<<"1. By ID\n";
  cout<<"2. By Title\n";
  cout<<"3. By Category\n";
  cout<<"4. By Author\n";
  cout<<"5. By Price Range\n";
  cout<<"6. By Issue Date\n";
  cout<<"7. By Issue Name\n";
  cout<<"Enter Your Choice : ";
  cin>>ch;
  system("cls");
  heading();
  switch(ch)
  {
   case 1: system("COLOR 5E"); searchByIDH(); break;
   case 2: system("COLOR 6E"); searchByTitleH(); break;
   case 3: system("COLOR 5F"); searchByCategoryH(); break;
   case 4: system("COLOR 6F"); searchByAuthorH(); break;
   case 5: system("COLOR 4F"); searchByPriceH();break;
   case 6: system("COLOR 4F"); searchByDateH();break;
   case 7: system("COLOR 4F"); searchByNameH();break;
   default: cout<<"\a";
  }
  system("pause");
 }while(ch!=0);
}



void dispose()
{
    int n;
    cout<<"\n\n\n\tDELETE BOOK ...";
    label:
    cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin>>n;
    fstream fp;
    fp.open("books.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    fstream fp3;
    fp3.open("history.dat",ios::app);
    while(fp.read((char*)&l,sizeof(l)))
    {
        if(n==l.getID())
        {
            fp3.write((char*)&l,sizeof(l));
        }
        else{
                fp2.write((char*)&l,sizeof(l));
        }
    }
cout<<"\nLate submission?? (enter 'y' for yes or 'n' for no) : ";
  char ab;
  cin>>ab;
  if(ab=='y'||ab=='y')
  {
      charge();
  }


  int m1;
  cout<<"\n\nQuality Menu:";
  cout<<"\n1. very nice";
  cout<<"\n2. nice";
  cout<<"\n3. good";
  cout<<"\n4. average";
  cout<<"\n5. bad";
  cout<<"\n\nenter quality rate at present : ";
  cin>>m1;
  ofstream fout1;
  fout1.open("books.dat",ios::app);
  if(m1>l.m)
  {
  cout<<"\n you have to pay 50 Rs. due to bad condition of book.";
  }
  fout1.close();

  cout<<"\n\n next?? (1 for yes , 0 for no) : ";
  int z;
  cin>>z;
  if(z==1)
  {
  goto label;
  }

    fp2.close();
        fp.close();
        remove("books.dat");
        rename("Temp.dat","books.dat");
        cout<<"\n\n\tRecord Deleted ..";
        getch();
}


//Fx for modifying data in file.
void modify()
{
 int n,flag=0,pos;
 fstream fin("books.dat",ios::in|ios::out);
 cout<<"Enter Book ID : ";
 cin>>n;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(n==l.getID())
  {
   pos=fin.tellg();
   cout<<"Following data will be edited...\n";
   l.showBook();
   flag++;
   fin.seekg(pos-sizeof(l));
   l.getBook();
   fin.write((char*)&l,sizeof(l));
   cout<<"\nData Modified successfully...\n";
  }
 }
 fin.close();
 if(flag==0)
  cout<<"Book Number with ID:"<<n<<" not available...\n";
}

//Fx to display the list of disposed off books
void displayHistory()
{
 ifstream fin("history.dat");
 int rec=0;
 while(fin.read((char*)&l,sizeof(l)))
 {
  if(rec<1)
   l.header();
  l.listView();
  rec++;
 }
 fin.close();
 cout<<"\nTotal "<<rec<<" Records in disposed off file...\n";
}

//Fx for displaying program options.
void menu()
{
 int ch;
 do
 {
  system("cls");
  heading();
  cout<<"0. EXIT.\n";
  cout<<"1. Add New Book\n";
  cout<<"2. Display All Books\n";
  cout<<"3. Search Books\n";
  cout<<"4. Delete book record\n";
  cout<<"5. Modify Details\n";
  cout<<"6. History\n";
  cout<<"7. Search History\n";
  //cout<<"7. Book quality";
  cout<<"Enter Your Choice : ";
  cin>>ch;
  system("cls");
  heading();
  switch(ch)
  {
   case 1: system("COLOR 5E"); addBook(); break;
   case 2: system("COLOR 5F"); displayBooks(); break;
   case 3: system("COLOR 6E"); searchMenu(); break;
   case 4: system("COLOR 6F"); dispose(); break;
   case 5: system("COLOR 4E"); modify(); break;
   case 6: system("COLOR 4F"); displayHistory(); break;
   case 7: system("COLOR 4E"); searchHistory(); break;
   }
  system("pause");
 }while(ch!=0);
}

void searchMenu()
{
 int ch;
 do
 {
  system("cls");
  heading();
  cout<<"BOOK SEARCH OPTIONS\n";
  cout<<"0. Back\n";
  cout<<"1. By ID\n";
  cout<<"2. By Title\n";
  cout<<"3. By Category\n";
  cout<<"4. By Author\n";
  cout<<"5. By Price Range\n";
  cout<<"6. By Issue Date\n";
  cout<<"7. By Issue Name\n";
  cout<<"Enter Your Choice : ";
  cin>>ch;
  system("cls");
  heading();
  switch(ch)
  {
   case 1: system("COLOR 5E"); searchByID(); break;
   case 2: system("COLOR 6E"); searchByTitle(); break;
   case 3: system("COLOR 5F"); searchByCategory(); break;
   case 4: system("COLOR 6F"); searchByAuthor(); break;
   case 5: system("COLOR 4F"); searchByPrice();break;
   case 6: system("COLOR 4F"); searchByDate();break;
   case 7: system("COLOR 4F"); searchByName();break;
   default: cout<<"\a";
  }
  system("pause");
 }while(ch!=0);
}



void charge()
{
    int days;
    float fine;

    cout<<"Enter the number of days: ";
    cin>>days;

    if (days > 0 && days <= 5)
        fine = 0.50 * days;

    if (days >= 6 && days <= 10)
        fine = 1 * days;

    if (days > 10)
        fine = 5 * days;

        if (days > 30)
        {
            printf("Your membership would be canceled.\n");
        }


    printf("You have to pay Rs. %.2f fine.", fine);
}

void password()
{
    char ch,pass[10];
    int i=0;

    cout<<"\n\nEnter Password:";
    while(ch!=13)
    {
        ch=getch();
        putch('*');
        if(ch!=13)
        {
            pass[i]=ch;
            i++;
        }
    }
    pass[i]='\0';
    if(strcmp(pass,passw)==0)
    {

        cout<<"\n\npassword match";
        cout<<"\n\npress any key to continue";
        getch();

    }
    else{
        cout<<"\n\nwarning!!! wrong password.";
        getch();
        password();
    }
}

int main()
{
 system("COLOR 70");
 cout<<"*****PASSWORD PROTECTED****";
 password();
 menu();
 return 0;
}
