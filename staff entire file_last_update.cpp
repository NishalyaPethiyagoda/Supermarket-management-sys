#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//stock classes and member fun
class fresh{
	protected:
		char prod_o_fac;        // 'p' or 'f' - produced or factory made
		string category;        // 10 types of goods
		string name;            // name of each item
		int quantity;           
		char quan_type;         //number or grams
		float price;
		float discount;
		float final_price;
	public:
		fresh( ):prod_o_fac('0'),category(" "),name(" "),quantity(0),quan_type(0),price('0'),discount('0'),
		               final_price('0') {	};
		void set_data( string cat, string n, int q, char q_t, float p, float d);
		string get_stock_ob_name();
		string get_stock_ob_category();
		int get_ob_quantity();
		char get_stock_ob_p_o_f();
		char get_ob_quantity_type();
		float get_ob_price();
		float get_ob_discount();
		int set_quantity(int tem);
		void show_data();

};
void fresh::set_data( string cat, string n, int q, char q_t, float p, float d )
{
	category=cat;
	name = n;
	quantity = q;
	quan_type = q_t;
	price = p;
	discount = d; 
	final_price = price*(1-(discount/100));
}
char fresh::get_stock_ob_p_o_f()
{
	return prod_o_fac;
}
string fresh::get_stock_ob_category()
{
	return category;
}
string fresh::get_stock_ob_name()
{
	return name;
}
int fresh::get_ob_quantity()
{
	return quantity;
}
char fresh::get_ob_quantity_type()
{
	return quan_type;
}
float fresh::get_ob_price()
{
	return price;
}
float fresh::get_ob_discount()
{
	return discount;
}
int fresh::set_quantity(int tem)
{
	quantity = tem;
	return quantity;
}
void fresh::show_data()
{
	cout << prod_o_fac  <<endl ;
	cout << category  <<endl ;
	cout << name      <<endl ;
	cout <<quantity   <<endl ;
	cout << quan_type <<endl ;
	cout << price     <<endl;
	cout << discount  <<endl ;
	cout << final_price<< endl;
}

class factory: public fresh{
	private:
		string brand;
		string brought_from;       //imported or local
	public:
		factory(): brand("-"), brought_from("-"){	};
		void set_data(string b, string b_f)	;
		string get_stock_ob_brand();
		string get_stock_ob_broughtfrom();
		void show_data();
};
void factory::set_data(string b, string b_f) 
{
	brand = b;
	brought_from = b_f;
}
string factory::get_stock_ob_brand()
{
	return brand;
}
string factory::get_stock_ob_broughtfrom()
{
	return brought_from;
}

void factory::show_data()
{
	cout << category  <<endl ;
	cout << name      <<endl ;
	cout <<quantity   <<endl ;
	cout << quan_type <<endl ;
	cout << price     <<endl;
	cout << discount  <<endl ;
	cout << final_price<< endl;
	cout << brand <<endl; 
	cout << brought_from <<endl;
}



//supply classes and member fun
class Supply{
	protected :
		string name;
		string brand;
		int quantity;
		string dateOfArrival;
		string vehicleRegstrationNo;				
	public :
        Supply():name(" "), brand(" "), quantity(0.f), dateOfArrival(" "), vehicleRegstrationNo(" ") {}
        Supply(string n, string b,int q,string da,string vr):name(n),brand(b),quantity(q),dateOfArrival(da),vehicleRegstrationNo(vr){}
        void getData(){
            cout<<"Enter the name of the item (use '_' to space seperate) : ";
	        cin>>name;
			cout << "Enter the brand name (use '-' if no brand name): ";
			cin >> brand;
	        cout<<"Enter the quantity : ";
	        cin>>quantity;
	        cout<<"Enter the date of arrival : ";
	        cin>>dateOfArrival;
	        cout<<"Enter the vehicle registration number :";
	        cin>>vehicleRegstrationNo;
		} 
		string get_ob_name()
		{
			return name;
		}	
		string get_ob_brand()
		{
			return brand;
		}
		int get_ob_quantity()
		{
			return quantity;
		}
};

class Local:public Supply{
	private:
		string nameOfOrigion;
		string dateOfDepature;
	public: 
		Local():nameOfOrigion(" "),dateOfDepature(" "){}
        Local(string no,string dd):nameOfOrigion(no),dateOfDepature(dd){}
		void getData(){
		    cout<<"Enter the date of departue : ";
	        cin>>dateOfDepature;
	        cout<<"Enetr the name of the region (use '_' to space seperate): ";
	        cin>>nameOfOrigion;
		}
		void showData(){
			cout<<"\nDate of departure           : "<<dateOfDepature;
			cout<<"\nName of the origion         : "<<nameOfOrigion;	
		}	
};

class International:public Supply{
	private:
		string countryOfOrigion;
		string dateArrival_harbour;
		string shipNumber;
	public : 
        International(string co=" ",string dh=" ",string sn=" "):countryOfOrigion(co),dateArrival_harbour(dh),
		                                                         shipNumber(sn){}
		void getData(){
			cout<<"Enter the ship number : ";
	        cin>>shipNumber;
		    cout<<"Enter the date arrival to the harbour : ";
	        cin>>dateArrival_harbour;
	        cout<<"Enter the country of the country (use '_' to space seperate) : ";
	        cin>>countryOfOrigion;
		}
		void showData(){
			cout<<"\nShip number                 : "<<countryOfOrigion;	
			cout<<"\nDate arrival to the harbour : "<<dateArrival_harbour;
			cout<<"\nCountry of the origion      : "<<countryOfOrigion;
		}	
};



//staff class and member functions
class Staff{
	protected:		
		string username;
		string password;
		string name;
		string position;
		string date;		
	public:
		Staff(string u ="-" , string pa="-",string n="-",string p="-",string d="-"): username(u), password(pa),
		                                                                           name(n),position(p),date(d){   };
		void set_data( string u, string pa, string n, string p, string d) ;
		void get_data();
		string operator == (Staff ob);  
//		bool check_data(Staff temp_ob, Staff people[]); 
//		void add_new_member(string u, string pa, string n, string p, string d);
		string get_ob_name();
		string get_ob_username();
		string get_ob_password();
		string get_ob_date();
		string get_ob_position();
		void Show_data();                                                                          
	
};
void Staff::set_data(string u, string pa, string n, string p, string d )   
{
	username = u;
	password = pa;
	name = n ;
	position = p;
	date = d;
}
void Staff::Show_data()
{
//		cout<< username<< endl;
//		cout<< password<< endl;
//		cout<< name<< endl;
		cout<<position<< endl;
//		cout<< date<< endl;
}
void Staff::get_data()
{
	cout << "enter username : ";
	cin>> username;
	cout<< "enter password : ";
	cin >> password;
}
string Staff::operator == (Staff ob)
{
	if(username == ob.username)
	{
		if(password == ob.password )
		{
		  	return position;		
		}
		else                        
		{  
			return "denied";   
		}
	}
	else                            
	{  return "denied";   }
}
//void Staff::add_new_member( string n, string po, string d_j, string u, string pa)
//{
//
//}
string Staff::get_ob_name()
{
	return name;
}
string Staff::get_ob_username()
{
	return username;
}
string Staff::get_ob_password()
{
	return password;
}
string Staff::get_ob_date()
{
	return date;
}
string Staff::get_ob_position()
{
	return position;
}

//program funtions

void stockup_fun(vector <factory> &stock_objects, int count_good, Local local_supply_ob, International international_supply_ob)
{
	int supplyType;
	string status;
	
	cout << "\n  if you want to add stock for local supply         enter - 1\n";
	cout <<	"                 add stock for international supply enter - 2  : ";
	cin >> supplyType;

	if (supplyType == 1)
	{
		local_supply_ob.Supply::getData();
		local_supply_ob.getData();
	}
	else if(supplyType == 2)
	{
		international_supply_ob.Supply::getData();
		international_supply_ob.getData();
	}
	else{
		cout<<"\n\nwrong input";
	}

	cout<< "\nenter shipment status as 'yes' for approved or 'no' for not approved : ";
	cin>>status;
	
	if(status == "yes")
	{
		int quantity_temp;
		if(supplyType == 1 )
		{
			for (int i = 0; i < count_good ; i++)
			{
				if(stock_objects[i].get_stock_ob_name() == local_supply_ob.get_ob_name() )
				{
					if ( local_supply_ob.get_ob_brand() != "-" )
					{
						if(stock_objects[i].get_stock_ob_brand() == local_supply_ob.get_ob_brand())
						{
							quantity_temp = stock_objects[i].get_ob_quantity() + local_supply_ob.get_ob_quantity();
							
							stock_objects[i].set_quantity(quantity_temp);
							
							ofstream file_2;
							file_2.open("stocks.txt");
							file_2 << count_good<<endl;
							for (int j = 0; j < count_good; j++)
							{
								file_2 << stock_objects[j].get_stock_ob_p_o_f()<< "   ";
								file_2 << stock_objects[j].get_stock_ob_category() << "   ";
								file_2 << stock_objects[j].get_stock_ob_name() << "   ";
								file_2 << stock_objects[j].get_ob_quantity() << "   ";
								file_2 << stock_objects[j].get_ob_quantity_type() << "   ";
								file_2 << stock_objects[j].get_ob_price() << "   ";
								file_2 << stock_objects[j].get_ob_discount() << "   ";
								file_2 << stock_objects[j].get_stock_ob_brand() << "   ";
								file_2 << stock_objects[j].get_stock_ob_broughtfrom()<< endl;
							}
							cout<<"\n\n    stocks were incremented successfully\n\n";
							break;
						}
						else
						{
							cout << "\nno such BRAND exists in stock";
							
						}
							
					}
					else
					{
						quantity_temp = stock_objects[i].get_ob_quantity() + local_supply_ob.get_ob_quantity();
						
						stock_objects[i].set_quantity(quantity_temp);
						
						ofstream file_2;
						file_2.open("stocks.txt");
						file_2 << count_good<<endl;
						for (int j = 0; j < count_good; j++)
						{
							file_2 << stock_objects[j].get_stock_ob_p_o_f()<< "   ";
							file_2 << stock_objects[j].get_stock_ob_category() << "   ";
							file_2 << stock_objects[j].get_stock_ob_name() << "   ";
							file_2 << stock_objects[j].get_ob_quantity() << "   ";
							file_2 << stock_objects[j].get_ob_quantity_type() << "   ";
							file_2 << stock_objects[j].get_ob_price() << "   ";
							file_2 << stock_objects[j].get_ob_discount() << "   ";
							file_2 << stock_objects[j].get_stock_ob_brand() << "   ";
							file_2 << stock_objects[j].get_stock_ob_broughtfrom()<< endl;
						}
						cout<<"\n\n    stocks were incremented successfully\n\n";
						break;		
					}
					
				}
				else
				{
				//	cout << "\nno such product name exsists in stock";
				}
				
			}

		}
		else if (supplyType == 2)
		{
			for (int i = 0; i < count_good ; i++)
			{
				if(stock_objects[i].get_stock_ob_name() == international_supply_ob.get_ob_name() )
				{
					if ( international_supply_ob.get_ob_brand() != "-" )
					{
						if(stock_objects[i].get_stock_ob_brand() == international_supply_ob.get_ob_brand())
						{
							quantity_temp = stock_objects[i].get_ob_quantity() + international_supply_ob.get_ob_quantity();
							
							stock_objects[i].set_quantity(quantity_temp);
							
							ofstream file_2;
							file_2.open("stocks.txt");
							file_2 << count_good<<endl;
							for (int j = 0; j < count_good; j++)
							{
								file_2 << stock_objects[j].get_stock_ob_p_o_f()<< "   ";
								file_2 << stock_objects[j].get_stock_ob_category() << "   ";
								file_2 << stock_objects[j].get_stock_ob_name() << "   ";
								file_2 << stock_objects[j].get_ob_quantity() << "   ";
								file_2 << stock_objects[j].get_ob_quantity_type() << "   ";
								file_2 << stock_objects[j].get_ob_price() << "   ";
								file_2 << stock_objects[j].get_ob_discount() << "   ";
								file_2 << stock_objects[j].get_stock_ob_brand() << "   ";
								file_2 << stock_objects[j].get_stock_ob_broughtfrom()<< endl;
							}
							cout<<"\n\n    stocks were incremented successfully\n\n";
							break;
						}
						else
						{
							cout << "\nno such BRAND exists in stock";
							
						}	
					}
					else
					{
						quantity_temp = stock_objects[i].get_ob_quantity() + international_supply_ob.get_ob_quantity();
						
						stock_objects[i].set_quantity(quantity_temp);
						
						ofstream file_2;
						file_2.open("stocks.txt");
						file_2 << count_good<<endl;
						for (int j = 0; j < count_good; j++)
						{
							file_2 << stock_objects[j].get_stock_ob_p_o_f()<< "   ";
							file_2 << stock_objects[j].get_stock_ob_category() << "   ";
							file_2 << stock_objects[j].get_stock_ob_name() << "   ";
							file_2 << stock_objects[j].get_ob_quantity() << "   ";
							file_2 << stock_objects[j].get_ob_quantity_type() << "   ";
							file_2 << stock_objects[j].get_ob_price() << "   ";
							file_2 << stock_objects[j].get_ob_discount() << "   ";
							file_2 << stock_objects[j].get_stock_ob_brand() << "   ";
							file_2 << stock_objects[j].get_stock_ob_broughtfrom()<< endl;
						}
						cout<<"\n\n    stocks were incremented successfully\n\n";
						break;		
					}
					
				}
				else
				{
				//	cout << "\nno such product name exsists in stock";
				}
				
				
			}
		}
	}
	else
	{
		cout<< "\n\nstock up unsuccessful";
	}
}
// stock down function
void stockdown_fun(vector <factory> &stock_objects, int count_good)
{
	string itemName;
	double itemQuantity;
	string itemBrand;
	double quantity_temp;
	
	cout << "item Brand (if none enter - 0) :"; cin >> itemBrand;
	cout << "item name                      :"; cin >> itemName;
	cout << "item quantity                  :"; cin >> itemQuantity;
	

	for (int i = 0; i < count_good ; i++)
	{
		if (stock_objects[i].get_stock_ob_name() == itemName  )
		{
			if(itemBrand != "0")
			{
				if(stock_objects[i].get_stock_ob_brand() == itemBrand)
				{
					
					if(stock_objects[i].get_ob_quantity()  < itemQuantity)
					{
						cout<<"amount requested is not available in stock";
						cout<<"stocks remaining = "<<stock_objects[i].get_ob_quantity();
					}
					else
					{
						quantity_temp = stock_objects[i].get_ob_quantity() - itemQuantity;
						
						stock_objects[i].set_quantity(quantity_temp);
						
						ofstream file_2;
						file_2.open("stocks.txt");
						file_2 << count_good<<endl;
						for (int j = 0; j < count_good; j++)
						{
							file_2 << stock_objects[j].get_stock_ob_p_o_f()<< "   ";
							file_2 << stock_objects[j].get_stock_ob_category() << "   ";
							file_2 << stock_objects[j].get_stock_ob_name() << "   ";
							file_2 << stock_objects[j].get_ob_quantity() << "   ";
							file_2 << stock_objects[j].get_ob_quantity_type() << "   ";
							file_2 << stock_objects[j].get_ob_price() << "   ";
							file_2 << stock_objects[j].get_ob_discount() << "   ";
							file_2 << stock_objects[j].get_stock_ob_brand() << "   ";
							file_2 << stock_objects[j].get_stock_ob_broughtfrom()<< endl;
						}
					}
						
				}
				else
				{
					cout<< "RESPECTIVE BRAND IS NOT PRESENT";
				}
			
			}
			else
			{
				if(stock_objects[i].get_ob_quantity()  < itemQuantity)
				{
					cout<<"amount requested is not available in stock";
					cout<<"stocks remaining = "<<stock_objects[i].get_ob_quantity();
				}
				else
				{
					quantity_temp = stock_objects[i].get_ob_quantity() - itemQuantity;
					
					stock_objects[i].set_quantity(quantity_temp);
					
					ofstream file_2;
					file_2.open("stocks.txt");
					file_2 << count_good<<endl;
					for (int j = 0; j < count_good; j++)
					{
						file_2 << stock_objects[j].get_stock_ob_p_o_f()<< "   ";
						file_2 << stock_objects[j].get_stock_ob_category() << "   ";
						file_2 << stock_objects[j].get_stock_ob_name() << "   ";
						file_2 << stock_objects[j].get_ob_quantity() << "   ";
						file_2 << stock_objects[j].get_ob_quantity_type() << "   ";
						file_2 << stock_objects[j].get_ob_price() << "   ";
						file_2 << stock_objects[j].get_ob_discount() << "   ";
						file_2 << stock_objects[j].get_stock_ob_brand() << "   ";
						file_2 << stock_objects[j].get_stock_ob_broughtfrom()<< endl;
					}
				}
			}
		}
		else
		{
		//	cout << "\nno such products exsists in stock";
		}
	}
}

//driver function
int main()
{
	//using a text file to input dummy data for staff
	int  count ;
	vector <Staff> people;	
	Staff temp_ob2;
	string u, pa,  n,  po,  d_j;
	
    ifstream file;
	file.open("staff.txt") ;
	file >> count;
	//cout<<count;
    for (int i = 0 ; i < count ; i ++)
    {
    	file>> u;
		file>> pa;
		file>> n ;
		file>> po;
		file>> d_j ;
		//cout<< u<<" " << pa<<" "<<n<<" "<<po<<" "<<d_j;
		temp_ob2.set_data( u,  pa,  n,  po, d_j);
		people.push_back(temp_ob2);
		
	}
	file.close();
	

//stock data initiLIZATION
	int  count_good ;  ////////////////////remember to change factory and fresh counts
	vector <factory> stock_objects;
	factory temp_ob1;
	//using a text file to input dummy data for stocks
	char p_o_f , q_t;
	string cat , na ,b, b_f;		
	int q;		
	float p , d;

	ifstream file_2;
	file_2.open("stocks.txt");
	file_2 >> count_good;
	
	for (int i = 0 ; i < count_good; i++)
	{
		file_2>>p_o_f;
		file_2>>cat;
		file_2>>na;
		file_2>>q;
		file_2>>q_t;
		file_2>>p;
		file_2>>d;
		file_2>> b ;
		file_2>> b_f ;
		
		temp_ob1.fresh::set_data(cat, na, q, q_t, p, d) ;
		temp_ob1.factory::set_data(b, b_f) ;	
		stock_objects.push_back(temp_ob1) ;
		//stock_objects[i].show_data() ;
	}
	file_2.close();
	
	//cout<<stock_objects.size() ;
//staff functionS ***********************************	
	Staff temp_ob , temp_ob3;
	string shallCloseProgram = " ";
	do{
	    temp_ob.get_data();
	    temp_ob.Show_data();
		//checking the position of the person
		char temp = '-';
		for(int i = 0 ; i < count ; i ++)
		{		
			if ( (people[i]  == temp_ob) == "cashier" )
			{
				temp = 'c' ;		break;
			}
			else if( (people[i]  == temp_ob) == "floor_worker")
			{
				temp = 'f' ;		break;
			}
			else if ( (people[i]  == temp_ob) == "manager")
			{
				temp = 'm' ;		break;
			}
			else if ( (people[i]  == temp_ob) == "owner")
			{
				temp = 'o' ;		break;
			}
			else{
				temp = 'e' ;
			}		
		}
		
		
	//supply data containing objects
		Local local_supply_ob; 
		International international_supply_ob;
	
	//providing the appropriate functions for the respective person
	    int function_to_do;
		switch(temp)
		{
			case 'f': {
				        cout << "\npress 1 to stock up\npress 6 to exist : ";
				        cin>> function_to_do;
						
						if(function_to_do == 1)
						{
							string nextItem = "";
							
							do{
								stockup_fun(stock_objects, count_good, local_supply_ob, international_supply_ob);
								cout << "\n\nTo add new item             -  1 \n ";
								cout<<  "To finish purchasing, enter - 'finish'\n->";
								cin >> nextItem;
								
							}while(nextItem != "finish");
						}
						else if(function_to_do == 6)
						{
						  //	exist(0);
						}
						else{
							cout<< "\nerror in the input. read instruction and try again";
						}
						
										break;					}
			case 'c': {
				        cout << "\npress 2 to stock down\npress 6 to exist\n : ";
				        cin>> function_to_do;
				
						
						if(function_to_do == 2)
						{	
							string nextItem = "";
							
							do{
								stockdown_fun(stock_objects,count_good);
								cout << "\n\nTo add new item             -  1 \n ";
								cout<<  "To finish purchasing, enter - 'finish'\n->";
								cin >> nextItem;
								
							}while(nextItem != "finish");
						}
						else if(function_to_do == 6)
						{
						  //	exist(0);
						}
						else{
							cout<< "\nerror in the input. Read instruction and try again";
						}
				
						        break;					}
			case 'm': {
						cout << "\npress 1 to stock up\npress 2 to stock down";
						cout << "\npress 6 to exist\n : ";
				        cin>> function_to_do;
						
						if(function_to_do == 1)
						{
							string nextItem = "";
							
							do{
								stockup_fun(stock_objects, count_good, local_supply_ob, international_supply_ob);
								cout << "\n\nTo add new item             -  1 \n ";
								cout<<  "To finish purchasing, enter - 'finish'\n->";
								cin >> nextItem;
								
							}while(nextItem != "finish");
						}
						else if(function_to_do == 2)
						{	
							string nextItem = "";
							
							do{
								stockdown_fun(stock_objects,count_good);
								cout << "\n\nTo add new item                -  1 \n ";
								cout<<  "To complete transaction, enter - 'finish'\n->";
								cin >> nextItem;
								
							}while(nextItem != "finish");
						}
						else if(function_to_do == 6)
						{
						  //	exist(0);
						}
						else{
							cout<< "\nerror in the input. read instruction and try again";
						}
				
				
						
										break;					}
			case 'o': {
						cout << "\npress 1 to stock up\npress 2 to stock down";
						cout << "\npress 4 to add an employee\npress 6 to exist\n : ";
						cin>> function_to_do;
	
						if(function_to_do == 1)
						{
							string nextItem = "";
							
							do{
								stockup_fun(stock_objects, count_good, local_supply_ob, international_supply_ob);
								cout << "\n\nTo add new item             -  1 \n ";
								cout<<  "To finish purchasing, enter - 'finish'\n->";
								cin >> nextItem;
								
							}while(nextItem != "finish");
						}
						else if(function_to_do == 2)
						{	
							string nextItem = "";
							
							do{
								stockdown_fun(stock_objects,count_good);
								cout << "\n\nTo add new item                -  1 \n ";
								cout<<  "To complete transaction, enter - 'finish'\n->";
								cin >> nextItem;
								
							}while(nextItem != "finish");
						}
						else if (function_to_do == 4)
						{
							count++;
							cout << "\nenter the name of member " << endl;
							cin >> n;
							cout << "enter the position of member " << endl;
							cin >> po;
							cout << "enter the date of member " << endl;
							cin >> d_j;
							cout << "enter the username of member " << endl;
							cin >> u;
							cout << "enter the password of member " << endl;
							cin >> pa;
	
							temp_ob3.set_data(u, pa, n, po, d_j);
							people.push_back(temp_ob3);
	
							ofstream file;
							file.open("staff.txt");
							file << count << endl;
							for (int i = 0; i < count; i++)
							{
								file << people[i].get_ob_username() << " ";
								file << people[i].get_ob_password() << " ";
								file << people[i].get_ob_name() << " ";
								file << people[i].get_ob_position() << " ";
								file << people[i].get_ob_date() << endl;
							}
	
						}
						else if (function_to_do == 5)
						{
							//vector <Staff>::iterator it;
							//cout << "enter the name of the member to erase";
							//cin >> n;
						
							//for (int i = 0; i < count; i++)
							//{
							//	if ( people[i].get_ob_name() == n )
							//	{
							//		it = people.begin();
							//		people.erase(it);
							//		for (auto it = people.begin(); it != people.end(); ++it)
							//		{
							//			cout << ' ' << *it ;  // vector position erase unresolved!!!!!!!!!!!!!!!!!!!!!!!!! 
							//		}
							//	}
							//}
							//--count;
	
							//ofstream file;
							//file.open("staff.txt");
							//file << count << endl;
							//for (int i = 0; i < count; i++)
							//{
							//	file << people[i].get_ob_username() << " ";
							//	file << people[i].get_ob_password() << " ";
							//	file << people[i].get_ob_name() << " ";
							//	file << people[i].get_ob_position() << " ";
							//	file << people[i].get_ob_date() << endl;
							//}
							cout << "\nsmall unclear part in  vector eraseing position";
						}
						else if (function_to_do == 6)
						{
							////	exist(0);
						}
						
						
						
										break;					}
			default : {  cout << "\naccess denied. username or password is incorrect ";		break;	}
		}
		cout<<"\n\nTo continue           press - 1\n";
		cout<<"To close the program, type  - 'exit'\n->";
		cin>> shallCloseProgram;
		
	}while(shallCloseProgram != "exit");
	
	return 0;
}
