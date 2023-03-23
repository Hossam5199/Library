#include<fstream>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class library{
 public:
  char Book_Name[50];
  char Author_Name[50];
  char Date_Of_Publishing[50];
  char Edition_Number[50];

  void read()
  {
cout<<"enter Book_Name";
cin>>Book_Name;
cout<<"enter Author_Name";
cin>>Author_Name;
cout<<"enter Date_Of_Publishing";
cin>>Date_Of_Publishing;
cout<<"enter Edition_Number";
cin>>Edition_Number;
}

};
////////////////<<Insert>>///////////////////////////////////////////

void insert(){
	library l;
    char ch;
    fstream file;
    file.open("library.txt",ios::out|ios::app);    //Ios::out = writes on the file, app= leave the data on the file and continue working on it

    do{
   	l.read();
    file<<l.Book_Name<<"|";
    file<<l.Author_Name<<"|";
    file<<l.Date_Of_Publishing<<"|";
    file<<l.Edition_Number<<"|"<<"\n";
    cout<<"IF you want to add another recored press y else press n :- ";
    cin>>ch;
    }
   while (ch=='y');
}
/////////////////////<<search>>////////////////////////////////////

void search_Book_Name(){
library l;
fstream file;
char k[50];
cout<<"the Book_Name you want to search about it::";
cin>>k;
file.open("library.txt",ios::in );

int flag=0;
while(!file.eof()){
file.getline(l.Book_Name ,50,'|');
file.getline(l.Author_Name,50,'|');
file.getline(l.Date_Of_Publishing,50,'|');
file.getline(l.Edition_Number,50);

if(strcmp(k,l.Book_Name)==0){

cout<<"Book Name \t"<<"Author Name \t"<<"Date Of Publishing  \t"<<"Edition Number \t" <<"\n";
cout<<l.Book_Name <<"\t ";
cout<<l.Author_Name<<"\t ";
cout<<l.Date_Of_Publishing<<"\t ";
cout<<l.Edition_Number<<"\t ";

flag=1;
}
}
if(flag==0){
cout<<"the "<<k<<" not found"<<"\n";
}
}

////////////////////<<delete>>/////////////////////////////////////

void delete_Book_Name(){
	library l;
char field[50];

 cout<<"the Book_Name field you want to delete it::";
    cin>>field;
fstream file;
fstream newfile;
 int flag=0;
file.open("library.txt",ios::in);
newfile.open("library 1.txt",ios::out);

while(!file.eof())
{
file.getline(l.Book_Name ,50,'|');
file.getline(l.Author_Name,50,'|');
file.getline(l.Date_Of_Publishing,50,'|');
file.getline(l.Edition_Number,50);


if(strcmp(field,l.Book_Name)==0){
            flag=1;
        }
        else {

newfile<<l.Book_Name<<'|'<<l.Author_Name<<'|'<<l.Date_Of_Publishing<<'|'<<l.Edition_Number<<'|'<<"\n";
        cout<<l.Book_Name<<"\t";
        cout<<l.Author_Name<<"\t";
        cout<<l.Date_Of_Publishing<<"\t";
        cout<<l.Edition_Number<<"\t";
        }
        }

        file.close();
        newfile.close();
        remove("library.txt");
        // rename("library.txt","old.txt");
        rename("library 1.txt","library.txt");

    }

///////////////////<<update>>///////////////////////////////////////

void update_Edition_Number(){

        library l;
        char field[50];
        cout<<"Enter the Edition_Number you want to update \t";
        cin>>field;
        int flag=0;
        fstream myfile;
        fstream newfile;
        myfile.open("library.txt",ios::in);
        newfile.open("library 1.txt",ios::out);

        while(!myfile.eof()){
        myfile.getline(l.Book_Name,50,'|');
        myfile.getline(l.Author_Name,50,'|');
        myfile.getline(l.Date_Of_Publishing,50,'|');
        myfile.getline(l.Edition_Number,50);


        if(strcmp(field,l.Edition_Number)==0)
        {
        flag=1;


        cout<<" new Edition_Number \t";
        cin>>l.Edition_Number;
        newfile<<l.Book_Name<<'|';
        newfile<<l.Author_Name<<'|';
        newfile<<l.Date_Of_Publishing<<'|';
        newfile<<l.Edition_Number<<'|';


        }
        }
        myfile.close();
        newfile.close();

        remove("library.txt");
        // rename("library.txt","old.txt");
        rename("library 1.txt","library.txt");



        if(flag==false)
        {
        cout<<"YOU CAN'T UPDATE THIS RECORD BY Edition_Number\n\n";
        }
}

/////////////////<<display>>////////////////////////////////////////

void read_data(){
library l;
fstream myfile;
myfile.open("library.txt",ios::in);
while(!myfile.eof()){
myfile.getline(l.Book_Name,50,'|');
myfile.getline(l.Author_Name,50,'|');
myfile.getline(l.Date_Of_Publishing,50,'|');
myfile.getline(l.Edition_Number,50,'\n');

cout<<l.Book_Name<<"\t";
cout<<l.Author_Name<<"\t";
cout<<l.Date_Of_Publishing<<"\t";
cout<<l.Edition_Number<<"\n";


}
myfile.close();
}


////////////////////////////////////////////////////////

int main()
{
int d;
char ch;
do{
cout<<"1- insert:: press 1"<<"\n";
cout<<"2- search:: press 2"<<"\n";
cout<<"3- delete:: press 3"<<"\n";
cout<<"4- update:: press 4"<<"\n";
cout<<"5- display::press 5"<<"\n";
cout<<"Enter Your Operation\t";
cin>>d;

    if (d==1){insert ();}
    if (d==2){search_Book_Name();}
    if (d==3){delete_Book_Name();}
	if (d==4){update_Edition_Number();}
	if (d==5){read_data();}

else {
	cout<<"Check you operation\n";
}

cout<<"Do you want to Add another Operation press y else press anykey\t";
cin>>ch;
}while(ch=='y');
return 0;
}
