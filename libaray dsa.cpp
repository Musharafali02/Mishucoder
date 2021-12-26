#include<iostream>
#include<conio.h>
using namespace std;

class library
{
      private:
	    
	      struct node{
	      	int id;
	      	string name,author,publisher;
	      	node *next_add;
		  };
	  public:
	      node *head=NULL;
		  void menu();
		  void insert();
		  void search();
		  void update();
		  void del();
		  void sort();
		  void show();	  
				
};
    void library::menu(){
    	p:
    		system("cls");
    		int choice;
    		cout<<"\n\n\t\t\t**************************************"<<endl;
    		cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    		cout<<"\n\n\t\t\t**************************************"<<endl;
    		cout<<"\n\n\ 1:INSERT NEW RECORD";
    		cout<<"\n\n 2:SEARCH RECORD";
    		cout<<"\n\n 3:UPDATE RECORD";
    		cout<<"\n\n 4:DELETE RECORD";
    		cout<<"\n\n 5:SHOW ALL RECORD";
    		cout<<"\n\n 6:EXIT";
    		cout<<"\n\n ENTER CHOICE:";
    		cin>>choice;
    		switch(choice)
    		{
    			case 1:
    				insert();
    				break;
    			case 2:
				    search();
					break;
				case 3:
				    update();
					break;
				case 4:
				    del();
			      	break;
				case 5:
				    sort();
				    show();
					break;
				case 6:
				   exit(0);
				 default:
				    cout<<"\n\n  INVALID CHOICE:.........TRY AGAIN............";  			
			}
    		getch();
    		goto p;
    	
	}
	void library::insert()
	{
		system("cls");
    		cout<<"\n\n\t\t\t**************************************"<<endl;
    		cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    		cout<<"\n\n\t\t\t**************************************"<<endl;
    		node *new_node=new node;
    		cout<<"\n\n BOOK ID : ";
    		cin>> new_node->id;
    		cout<<"\n\n NAME : ";
    		cin>> new_node->name;
    		cout<<"\n\n AUTHOR NAME : ";
    		cin>> new_node->author;
    		cout<<"\n\n PUBLISHER NAME : ";
    		cin>> new_node->publisher;
    		new_node->next_add=NULL;
    		if(head==NULL)
    		{
    			head=new_node;
			}
			else{
			
				node *ptr=head;
				while(ptr -> next_add != NULL)
			{
				ptr= ptr->next_add;
			}
			ptr->next_add=new_node;
		}
			
			cout<<"\n\n\t\t BOOK INSERTED SUCCESSFULLY..........";
			
	
		
	}
	void library::search()
	{
		system("cls");
		int h_id,found=0;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
		if(head==NULL)
		{
		  cout<<"\n\n ****LIST IS EMPTY****"	;
		}
		else
		{
			cout<<"\n\n BOOK ID : ";
			cin>>h_id;
			node *ptr=head;
			while(ptr !=NULL)
			{
				if(h_id==ptr->id)
				{
				   system("cls");
    	        	cout<<"\n\n\t\t\t**************************************"<<endl;
    		        cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    		        cout<<"\n\n\t\t\t**************************************"<<endl;
    		        cout<<"\n\n BOOK ID : "<<ptr->id;  
    		        cout<<"\n\n BOOK NAME : "<<ptr->name;  
    		        cout<<"\n\n BOOK AUTHOR NAME : "<<ptr->author;  
    		        cout<<"\n\n BOOK PUBLISHER NAME : "<<ptr->publisher;
					found++; 
					cout<<"\n\n\t\t BOOK FOUND SUCCESSFULLY...........";
				}
				ptr=ptr->next_add;
			
				
				
			}
			if(found==0)
			{
				cout<<"\n\n BOOK NOT FOUND IN RECORD...........";
			}
		}
		
	}
	void library::update()
	{
			system("cls");
		int h_id,found=0;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
		if(head==NULL)
		{
		  cout<<"\n\n ****LIST IS EMPTY****"	;
		}
		else{
			cout<<"\n\n BOOK ID : ";
			cin>>h_id;
			node *ptr=head;
			while(ptr !=NULL)
			{
				if(h_id==ptr->id)
				{
				   system("cls");
    	        	cout<<"\n\n\t\t\t**************************************"<<endl;
    		        cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    		        cout<<"\n\n\t\t\t**************************************"<<endl;
    		        cout<<"\n\n BOOK ID : ";
					cin>>ptr->id;  
    		        cout<<"\n\n BOOK NAME : ";
					cin>>ptr->name;  
    		        cout<<"\n\n BOOK AUTHOR NAME : ";
					cin>>ptr->author;  
    		        cout<<"\n\n BOOK PUBLISHER NAME : ";
					cin>>ptr->publisher;
					found++; 
					cout<<"\n\n\t\t BOOK UPDATED SUCCESSFULLY...........";
				}
				ptr=ptr->next_add;
			
				
				
			}
			if(found==0)
			{
				cout<<"\n\n BOOK NOT FOUND IN RECORD...........";
			}
		}
		
	}
	 void library::del()
	 {
	 
		system("cls");
		int h_id,found=0;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
		if(head==NULL)
		{
		  cout<<"\n\n ****LIST IS EMPTY****"	;
		}
		else{
			cout<<"\n\n BOOK ID : ";
			cin>>h_id;
			if(h_id==head->id)
			{
				node *ptr=head;
				head=head->next_add;
				delete ptr;
				cout<<"BOOK DELETED SUCCESSFULLY.........";
				found++;
			}
			else
			{
				node *pre=head;
				node *ptr=head;
				while(ptr!=NULL)
				{
					if(h_id==ptr->id)
					{
						pre->next_add=ptr->next_add;
						delete ptr;
						cout<<"\n\n BOOK DELETED SUCCESSFULLY........";
   		                found++;			
					}
					pre=ptr;
					ptr=ptr->next_add;
				}
			}
		   if(found==0)
		   {
		   	cout<<"\n\n BOOK ID IS INVALID........";
		   }
		
		}
    }
    void library::sort()
	{
		system("cls");
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	if(head==NULL)
		{
    		cout<<"\n\n LIST IS EMPTY.......";
    		getch();
    		menu();
		}
		int count=0,h_id;
		string h_name,h_author,h_publisher;
		node *ptr=head;
		while(ptr!=NULL)
		{
			count++;
			ptr=ptr->next_add;
		}
		for(int i=0;i<=count;i++)
		{
			node *ptr=head;
			for(int j=1;j<count;j++)
			{
				if(ptr->id>ptr->next_add->id)
				{
					h_id=ptr ->id;
					h_name=ptr ->name;
					h_author=ptr ->author;
					h_publisher=ptr ->publisher;
					ptr->id=ptr->next_add->id;
					ptr->name=ptr->next_add->name;
					ptr->author=ptr->next_add->author;
					ptr->publisher=ptr->next_add->publisher;
					
				    ptr->next_add->id=h_id;
				    ptr->next_add->name=h_name;
					ptr->next_add->author=h_author;
					ptr->next_add->publisher=h_publisher;	
				}
				ptr=ptr->next_add;
			}
		}
		
	}
	void library::show()
	{
			system("cls");
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	cout<<"\n\n\t\t\t         LIBRARY MANAGMENT           "<<endl;
    	cout<<"\n\n\t\t\t**************************************"<<endl;
    	node *ptr=head;
		while(ptr !=NULL)
		{
			
           cout<<"\n\n BOOK ID : "<<ptr->id;  
           cout<<"\n\n BOOK NAME : "<<ptr->name;  
           cout<<"\n\n BOOK AUTHOR NAME : "<<ptr->author;  
           cout<<"\n\n BOOK PUBLISHER NAME : "<<ptr->publisher;	
				ptr=ptr->next_add;
		}
			
		}
	

int main()
{
	library obj;
	obj.menu();
	}	
	
   