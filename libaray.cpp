#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int counter = 0;
int counter_student = 0;

int increment(int c)
{
	c++;
	counter = c;
	return counter;
}

int decrement(int c)
{
	c--;
	counter = c;
	return counter;
}

int increment_student(int c)
{
	c++;
	counter_student = c;
	return counter_student;
}

int decrement_student(int c)
{
	c--;
	counter_student = c;
	return counter_student;
}

class entery
{
public:
	string isbn, title, author, edition, publication;
	int _delete;
	string name, section, semester, password, enrollment;

	entery() //D constructor
	{
		isbn = "0";
		title = "0";
		author = "0";
		edition = "0";
		publication = "0";

		name = "0";
		section = "0";
		semester = "0";
		password = "0";
		enrollment = "0";
	}

	void setdata(string isb,string ti,string auth,string ed,string pu)
	{
		isbn = isb;
	
		title = ti;
		author = auth;
		publication = pu;
		edition = ed;
	}

	void setDelete(int del){
		_delete = del;
	}
	int getDelete()
	{
		return _delete;
	}
	
	
	void setdatastudent(string na,string sec,string sem,string pass,string enroll)
	{
		name = na;
		section = sec;
		semester = sem;
		password = pass;
		enrollment = enroll;
	}

	
	~entery()
	{
		cout << "distructor run:" << endl;
	}
};

class addbooks : virtual public entery //inheretance used here ....
{
public:
	void addbook(int counter)
	{
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t  || LIBRARIAN - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\n\n\t\t\t\t\t\t   ADD BOOKS " << endl << endl;
		
		if (counter == 10)
		{
			cout << "\t\t\t\t\tYOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE BOOKS " << endl;
			cout << "\n\t\t\t\t\tPress any key to continue..." << endl;
			_getch();
		}

		else
		{
			cin.ignore();
			cout << "\t\t\t\t\tENTER ISBN : ";
			getline(cin, isbn);

			cout << "\t\t\t\t\tENTER TITLE : ";
			getline(cin, title);

			cout << "\t\t\t\t\tENTER AUTHOR : ";
			getline(cin, author);

			cout << "\t\t\t\t\tENTER EDITION : ";
			getline(cin, edition);

			cout << "\t\t\t\t\tENTER PUBLICATION : ";
			getline(cin, publication);
			cout << endl << endl;
			setdata(isbn,title,author,edition,publication);
			
			setDelete(0);
	
			increment(counter);

			cout << "\t\t\t\t\tBOOK ADDED SUCCESFULLY! \n\n\t\t\t\t\tPress any key to continue..." << endl;
			_getch();
		}
	}
};

class addstudent : public virtual entery
{
public:
	void adddata(int counter_student)
	{
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t   || STUDENT - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl << endl;
		if (counter_student == 10)
		{
			cout << "\t\t\t\t\tYOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE Students " << endl;
			cout << "\n\t\t\t\t\tPress any key to continue..." << endl;
			_getch();
		}
		else
		{
			cin.ignore();
			cout << "\t\t\t\t\tEnter student Name     :";
			getline(cin, name);

			cout << "\t\t\t\t\tEnter student Roll#    :";
			getline(cin, enrollment);

			cout << "\t\t\t\t\tEnter student Section  :";
			getline(cin, section);

			cout << "\t\t\t\t\tEnter student Semester :";
			getline(cin, semester);

			cout << "\t\t\t\t\tEnter student Password :";
			getline(cin, password);
			cout << endl << endl;
			setdatastudent(name,section,semester,password,enrollment);
			increment_student(counter_student);
			cout << "\t\t\t\t\tStudent ADDED SUCCESFULLY! \n\n\t\t\t\t\tPress any key to continue..." << endl << endl;
			_getch();
		}
	}
};

class loginstudent :  virtual public addstudent
{
public:
	string name, pass;
	void login(int counter_student, loginstudent books[10])
	{
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t   || STUDENT - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl << endl;


		if (counter_student == 10)
		{
			cout << "\t\t\t\t\tYOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE Students " << endl;
			cout << "\n\t\t\t\t\tPress any key to continue..." << endl;
			_getch();
		}

		else
		{
			cout << "\t\t\t\t\tPlease Enter Your name :";
			cin >> name;
			cout << "\t\t\t\t\tPlaese enter your password :";
			cin >> pass;
			cout << endl << endl;
			for (int i = 0; i < counter_student; i++)
			{
				if (books[i].password == pass)
				{
					cout << "\t\t\t\t\tYou are successfully login your profile !\n";
					cout << "\n\t\t\t\t\tPress any key to continue . . .";
					_getch();
				}
			}


		}
	}
	void borrowbooks(int counter_student, loginstudent books[10])
	{
		int select, borrow, returnbook;

		system("cls");
	b:
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t   || STUDENT - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl << endl << endl;
		
		cout << "\t\t\t\t\tWHAT DO YOU WANT NEXT :\n\n";

		cout << "\t\t\t\t\t[1] - For Borrow_Books: \n";
		cout << "\t\t\t\t\t[2] - For Return_Books: \n";
		cout << "\t\t\t\t\t[3] - For Checking all Books in Library :\n";
		cout << "\t\t\t\t\t[4] - For Checking Borrow Books: \n\n";

		cout << "\t\t\t\t\tPlaese enter your choice :";
		cin >> select;

		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t   || STUDENT - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl << endl << endl;
		string Isbn;
		if (select == 1)
		{

			cout << "\t\t\t\t\tPlaese enter Book ISBN: ";
			cin >> Isbn;
			for (int i = 0; i < counter; i++)
			{
				if (books[i].isbn == Isbn)
				{
					cout << "\t\t\t\t\tBook Founded! \n\n";
					cout << "\t\t\t\t\tWhat do you want borrow [1] or exit [2] :";
					cin >> borrow;
					if (borrow == 1)
					{
						books[i].setDelete(1);
					}
				}
			}
			cout << "\n\t\t\t\t\tPROCESSING . . .\n" << endl;
			Sleep(2000);
			cout << "\t\t\t\t\tBOOK BORROW SUCCESSFULLY\n ";
			cout << "\n\t\t\t\t\tPress any key to continue . . .";
			_getch();
			goto b;

		}

		else if (select == 2)
		{
			cout << "\t\t\t\t\tDo yo want to return books: yes [1] or No [2] :";
			cin >> returnbook;
			if (returnbook == 1)
			{

				setDelete(0);
				cout << "\n\t\t\t\t\tPROCESSING . . .\n";
				cout << "\n\t\t\t\t\tBOOK RETURN SUCCESSFULLY ! \n";

			}
			cout << "\n\t\t\t\t\tPress any key to continue . . .";
			_getch();
			goto b;
		}
		else if (select == 3)
		{
			system("cls");

			cout << setw(75) << setfill('~') << "~" << endl;
			cout << "\t\t\t    BOOK DETAILS " << endl;
			cout << setw(75) << setfill('~') << "~" << endl;

			cout << "ISBN          TiTLE           AUTHOR          EDITION        PUBLICATION " << endl;

			for (int i = 0; i < counter; i++)
			{
				if (!books[i].getDelete())
					cout << books[i].isbn << "\t\t"
					<< books[i].title << "\t\t"
					<< books[i].author<< "\t\t"
					<< books[i].edition << "\t\t"
					<< books[i].publication<< endl
					<< endl;
			}
			cout << "\n\t\t\t\t\tPress any key to continue . . .";
			_getch();
			goto b;
		}
		else if (select == 4)
		{
			system("cls");

			cout << setw(75) << setfill('~') << "~" << endl;
			cout << "\t\t\t\t\t    BOOK DETAILS " << endl;
			cout << setw(75) << setfill('~') << "~" << endl;
			cout << "ISBN           TiTLE              AUTHOR               EDITION             PUBLICATION" << endl << endl;

			for (int i = 0; i < counter; i++)
			{
				if (books[i].getDelete()){
					cout << books[i].isbn << "\t\t"
						<< books[i].title << "\t\t"
						<< books[i].author << "\t\t"
						<< books[i].edition << "\t\t"
						<< books[i].publication << endl
						<< endl;
				}
			}
			cout << "\n\t\t\t\t\tPress any key to continue . . .";
			_getch();
			goto b;
		}
	}
};


class deletebook : virtual public entery, virtual public addbooks, virtual public addstudent, virtual public loginstudent
{
public:
	void deleteBooks(int counter, deletebook books[10])
	{
		string Isbn;
		int choice;
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t  || LIBRARIAN - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\n\n\t\t\t\t\t\t   DELETE BOOKS " << endl << endl;

		if (counter == 0)
		{
			cout << "\t\t\t\t\tTHERE IS NOT BOOKS TO BE DELETED " << endl;
			cout << "\n\t\t\t\t\tPress any key to continue..." << endl;
			_getch();
		}

		cin.ignore();

		cout << "\t\t\t\t\tENTER ISBN : ";
		getline(cin, Isbn);

		for (int i = 0; i < counter; i++)
		{
			if (books[i].isbn == Isbn)
			{
				cout << "\n\n\t\t\t\t\tBOOK FOUND!\n" << endl;
				cout << "\t\t\t\t\tDo You Want to delete this books yes[1], no[2] :";
				cin >> choice;
				if (choice == 1)
				{
					books[i].setdata("","","","","");
				
					decrement(counter);

					cout << "\t\t\t\t\tBOOK DELETED SUCCESFULLY!\n Press any key to continue.." << endl;
					_getch();

					for (int a = i; a < counter; a++)
					{
						books[a] = books[a + 1];
					}

					books[9].setdata("", "", "", "", "");
			
				}

				else
				{
				}
			}
		}

	}
};
class editbook : virtual public entery, virtual public addbooks, virtual public deletebook, virtual public addstudent, virtual public loginstudent
{
public:
	void editBooks(int counter, editbook books[10])
	{
		string editisbn;
		string Isbn;
		string choice;
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t  || LIBRARIAN - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\n\n\t\t\t\t\t\t   EDIT BOOKS " << endl << endl;

		if (counter == 0)
		{
			cout << "\t\t\t\t\tTHERE IS NO BOOKS TO BE EDITED FIRST ADD THE BOOKS!,Press any key to continue... " << endl;
			_getch();
		}
		cin.ignore();
		cout << "\t\t\t\t\tENTER ISBN : ";
		getline(cin, Isbn);

		for (int i = 0; i < counter; i++)
		{
			if (books[i].isbn== Isbn)
			{
				cout << "\n\n\t\t\t\t\tBOOK FOUND!" << endl << endl;
				cout << "\t\t\t\t\tDO YOU WANT TO EDIT THE BOOK edit [1] OR exit [2]? ";
				getline(cin, choice);

				if (choice == "1")
				{
					cout << "\t\t\t\t\tENTER ISBN : ";
					getline(cin, isbn);

					cout << "\t\t\t\t\tENTER TITLE : ";
					getline(cin, title);

					cout << "\t\t\t\t\tENTER AUTHOR : ";
					getline(cin, author);

					cout << "\t\t\t\t\tENTER EDITION : ";
					getline(cin, edition);

					cout << "\t\t\t\t\tENTER PUBLICATION : ";
					getline(cin, publication);
					books[i].setdata(isbn, title, author, edition, publication);
					cout << "\t\t\t\t\tPress any key to proceed.." << endl;
					_getch();
				}
				else if (choice != "1")
				{
					cout << "\t\t\t\t\tPRESS ANY KEY TO CONTINUE.." << endl;
					_getch();
				}
			}

			else
			{
			}
		}
	}
};

class searchbook : virtual public entery, virtual public addbooks, virtual public deletebook, virtual public editbook, virtual public addstudent, virtual public loginstudent
{
public:
	void searchBooks(int counter, searchbook books[10])
	{
		string Isbn;

		bool print = false;
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t  || LIBRARIAN - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\n\n\t\t\t\t\t\t   SEARCH BOOKS " << endl << endl;

		if (counter == 0)
		{
			cout << "\t\t\t\t\tTHERE IS NO BOOK TO SEARCH PLEASE ADD A BOOK FIRST " << endl;
			cout << "\t\t\t\t\tPress any key to continue..." << endl;
			_getch();
		}
		cin.ignore();

		cout << "\t\t\t\t\tENTER ISBN : ";
		getline(cin, Isbn);

		for (int i = 0; i < counter; i++)
		{
			if (books[i].isbn == Isbn)
			{
				cout << "\n\n\t\t\t\t\tBOOK FOUND " << endl << endl;
				cout << "\t\t\t\t\tISBN : " << books[i].isbn << endl;
				cout << "\t\t\t\t\tTITLE : " << books[i].title<< endl;
				cout << "\t\t\t\t\tAUTHOR : " << books[i].author << endl;
				cout << "\t\t\t\t\tEDITION : " << books[i].edition << endl;
				cout << "\t\t\t\t\tPUBLICATION : " << books[i].publication << endl;
				print = true;
			}
			if (print)
			{
				cout << "\t\t\t\t\tPRESS ANY KEY TO CONTINUE..." << endl;
				_getch();
			}

		}
	}
};

class viewbooks : virtual public entery, virtual public addbooks, virtual public deletebook, virtual public editbook, virtual public searchbook, virtual public addstudent, virtual public loginstudent
{
public:
	void viewAllBooks(int counter, viewbooks books[10])
	{
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t  || LIBRARIAN - INTERFACE ||" << endl;
		cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
		cout << "\n\n\t\t\t\t\t\t   VIEW ALL THE BOOKS " << endl << endl;

		if (counter == 0)
		{
			cout << "\t\t\t\t\tTHERE IS NO BOOK TO VIEW FIRST ADD THE BOOK! \n\n\t\t\t\t\tpresss any key to continue..." << endl;
			_getch();
		}
		else
		{
			system("cls");

			cout << setw(90) << setfill('~') << "~" << endl;
			cout << "\t\t\t    BOOK DETAILS " << endl;
			cout << setw(90) << setfill('~') << "~" << endl;

			cout << "ISBN          TiTLE           AUTHOR          EDITION        PUBLICATION " << endl;

			for (int i = 0; i < counter; i++)
			{
				if (!books[i].getDelete())
					cout << books[i].isbn << "\t\t"
					<< books[i].title << "\t\t"
					<< books[i].author<< "\t\t"
					<< books[i].edition<< "\t\t"
					<< books[i].publication << endl
					<< endl;
			}

			cout << "\t\t\t\t\tPress any key to continue . . .";
			_getch();
		}
	}

	void viewstudentprofile(int counter_student, viewbooks books[10])
	{
		system("cls");

		cout << setw(90) << setfill('~') << "~" << endl;
		cout << "\t\t\t    Students  DETAILS " << endl;
		cout << setw(90) << setfill('~') << "~" << endl;

		cout << "Name          Enrollment           Section          Semester        Password " << endl;
		for (int i = 0; i < counter_student; i++)
		{
			cout << books[i].name << "\t\t"
				<< books[i].enrollment << "\t\t"
				<< books[i].section<< "\t\t"
				<< books[i].semester << "\t\t"
				<< books[i].password << endl
				<< endl;
		}
		cout << "\t\t\t\t\tPress any key to continue . . .";
		_getch();
	}
};

int quit(void)
{
	system("cls");

	cout << "\n\n\n\n\t\t\t\t\t WAIT FOR A MOMENT , PROGRAM IS GOING TO CLOSE ! ";
	Sleep(3000);
	cout << "\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@     @@         @@     @@@@@@@@@@@@            \n";
	cout << "\t\t\t\t\t@@        @@      @@       @@      @@                         \n";
	cout << "\t\t\t\t\t@@        @@       @@     @@       @@                         \n";
	cout << "\t\t\t\t\t@@@@@@@@@@@@        @@   @@        @@                         \n";
	cout << "\t\t\t\t\t@@          @@       @@ @@         @@@@@@@@@               \n";
	cout << "\t\t\t\t\t@@          @@        @@@          @@                         \n";
	cout << "\t\t\t\t\t@@          @@        @@@          @@                         \n";
	cout << "\t\t\t\t\t@@@@@@@@@@@@          @@@          @@@@@@@@@@@@            \n";

	cout << endl;

	cout << "\n\n\t\t\t\t\t" << setw(47) << setfill('~') << "~" << endl;
	cout << "\t\t\t\t\t||           COPY RIGHT - GROUP 13           ||\n";
	cout << "\t\t\t\t\t" << setw(47) << setfill('~') << "~" << endl;
	cout << "\n\n\t\t\t\t\tPress any key to continue . . .";
	_getch();
	exit(1);
}

void setup()
{
	cout << "\n\n\n\n\t\t\t\t\tW";
	Sleep(200);
	cout << "E";
	Sleep(200);
	cout << "L";
	Sleep(200);
	cout << "C";
	Sleep(200);
	cout << "O";
	Sleep(200);
	cout << "M";
	Sleep(200);
	cout << "E";
	Sleep(200);
	cout << " ";
	Sleep(200);
	cout << "T";
	Sleep(200);
	cout << "O";
	Sleep(200);
	cout << " ";
	Sleep(200);

	cout << "U";
	Sleep(200);
	cout << "N";
	Sleep(200);
	cout << "I";
	Sleep(200);
	cout << "V";
	Sleep(200);
	cout << "E";
	Sleep(200);
	cout << "R";
	Sleep(200);
	cout << "S";
	Sleep(200);
	cout << "T";
	Sleep(200);
	cout << "Y";
	Sleep(200);

    cout << " ";
	Sleep(200);
	cout << "O";
	Sleep(200);
	cout << "F";
	Sleep(200);
	cout << " ";
	Sleep(200);
	
	cout << "O";
	Sleep(200);
	cout << "K";
	Sleep(200);
	cout << "A";
	Sleep(200);
	cout << "R";
	Sleep(200);
	cout << "A"<<endl;
	Sleep(200);



	cout << " \t\t\t\t\tLIBARARY MANAGEMENT";
	Sleep(200);
	cout << " SYSTEM" << endl;
	cout << "\t\t\t\t\tTeam Project " << endl;
	Sleep(200);
	//	cout << "\t\t\t\t\tPress Any Key To Continue...." << endl;
	//_getch();
}

int main()
{
	system("color 02");

	string c, choice;
	int q;

	viewbooks books[10];

	system("CLS");
	do
	{
		system("cls");
		setup();
		cout << endl << endl;
		cout << "\t\t\t\t\t" << setw(32) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t|| LIBRARY MANAGMENT SOFTWARE ||" << endl;
		cout << "\t\t\t\t\t" << setw(32) << setfill('~') << "~" << endl;
		cout << "\t\t\t\t\t       Discover Knowledge " << endl;

		cout << "\n\n\t\t\t\t\t[1] - For Librarian Interface \n";
		cout << "\t\t\t\t\t[2] - For Student Interface \n";
		cout << "\t\t\t\t\t[3] - About  \n";
		cout << "\t\t\t\t\t[4] - Quit \n\n";
		cout << "\n\t\t\t\t\tEnter your choice here : ";
		cin >> q;

		if (q == 1)
		{
		a:
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
			cout << "\t\t\t\t\t  || LIBRARIAN - INTERFACE ||" << endl;
			cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;


			cout << "\n\n\n\t\t\t\t\t[1] - ADD A BOOK " << endl;
			cout << "\t\t\t\t\t[2] - DELETE A BOOK " << endl;
			cout << "\t\t\t\t\t[3] - EDIT A BOOK " << endl;
			cout << "\t\t\t\t\t[4] - SEARCH A BOOK " << endl;
			cout << "\t\t\t\t\t[5] - VIEW ALL THE BOOKS " << endl;
			cout << "\t\t\t\t\t[6] - VIEW ALL STUDENT PROFILE " << endl;
			cout << "\t\t\t\t\t[7] - QUIT " << endl;
			cout << "\t\t\t\t\t[8] - MAIN " << endl;

			cout << "\n\t\t\t\t\tEnter your choice here : ";
			cin >> c;

			if (c == "1")
			{
				books[counter].addbook(counter);
				goto a;
			}
			else if (c == "2")
			{
				books[counter].deleteBooks(counter, books);
			}

			else if (c == "3")
			{
				books[counter].editBooks(counter, books);
			}

			else if (c == "4")
			{
				books[counter].searchBooks(counter, books);
			}

			else if (c == "5")
			{

				books[counter].viewAllBooks(counter, books);
			}

			else if (c == "6")
			{
				books[counter_student].viewstudentprofile(counter_student, books);
			}
			else if (c == "7")
			{
				quit();
			}
			else
			{
				main();
			}
		}

		else if (q == 2)
		{
		b:
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;
			cout << "\t\t\t\t\t   || STUDENT - INTERFACE ||" << endl;
			cout << "\t\t\t\t\t" << setw(31) << setfill('~') << "~" << endl;


			cout << "\n\t\t\t\t\t[1] - FOR ADD STUDENT " << endl;
			cout << "\t\t\t\t\t[2] - FOR login STUDENT " << endl;
			cout << "\t\t\t\t\t[3] - FOR Quit " << endl;
			cout << "\t\t\t\t\t[4] - FOR MAIN " << endl;

			cout << "\n\t\t\t\t\tEnter your choice here : ";
			cin >> choice;

			if (choice == "1")
			{
				books[counter_student].adddata(counter_student);
				goto b;
			}

			else if (choice == "2")
			{
				books[counter_student].login(counter_student, books);

				books[counter_student].borrowbooks(counter_student, books);
			}
			else if (choice == "3")
			{
				quit();
			}
			else
			{
				main();
			}
		}

		else if (q == 3)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\t" << setw(21) << setfill('~') << "~" << endl;
			cout << "\t\t\t\t\t\t\t|| ABOUT - PROGRAM ||\n";
			cout << "\t\t\t\t\t\t\t" << setw(21) << setfill('~') << "~" << endl;
			cout << endl << endl << endl;
			cout << "\t\t\t\t\t[1] - IF YOU PRESS 1 A LIBRARIAN POP-UP MAIN MENU APPEAR \n\t\t\t\t\tIN WHICH YOU CAN ADD A BOOK \n\t\t\t\t\tDELETE A BOOK EDIT A BOOK SEARCH A BOOK AND YOU CAN \n\t\t\t\t\tVIEW ALL BOOKS IN LIBRARY  \n\t\t\t\t\tAND ALSO VIEW ALL STUDENTS PROFILE\n\n";

			cout << "\t\t\t\t\t[2] - IF YOU PRESS 2 A STUDENT POP - UP MAIN MENU APPEAR \n\t\t\t\t\tIN WHICH YOU CAN CREATE YOUR STUDENT PROFILE\n\t\t\t\t\tOR USE THIS PROFILE TO LOGIN YOUR ACCOUNT \n\t\t\t\t\tTHEN YOU CAN BORROW A BOOK RETURN A BOOK\n\n";

			cout << "\t\t\t\t\t[3] - IF YOU PRESS 3 THE ABOUT MENU IS SHOWN\n\n";

			cout << "\t\t\t\t\t[4] - IF YOU PRESS 4 THE PROGRAM IS CLOSED\n\n";
			cout << "\n\n\t\t\t\t\tPress any key to continue . . .";
			_getch();
		}

		else if (q == 4)
		{

			quit();
		}

	} while (q != 8);
	_getch();
}