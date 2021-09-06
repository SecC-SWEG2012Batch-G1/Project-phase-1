/****************************************************************************************************************************************
****************************************  SHOPPING MANGMENT SYSTEM*************************************************************************
*******************************************************************************************************************************************
*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int choice;
int option;
int num,i=0,quant;//quant used to denote the quantity entered  by customer
int j=0;//i and j for an array
char press;
struct address{
	string city;
	int housenum;
	};
  struct Administrator
{
    string fullName;
	int phoneNo;
	string email,password1,password2;
    char gender;
    address add;
     int admin_id;
}admin_1;
struct cust{
	string name;
	int phone_number;
	address add;
}cust;
 struct product{
		int product_num;
	string product_name;
	string product_type;
	int quantity;
	float price;
	float discount;// discout is by percent
	float discount_price;
	float total_price;
	}add_pro[1000],cloth_list[100],shoe_list[100],bag_list[100];
char getchoice();
 void customer_info();
 void cust_menu(int *opp);
void Registration();
void add_product(product added_pro[]);
void show_add_product(product add_pro[],int num);
void login();
void Admin_menu();
void clothlist();
void shoelist();
void baglist();
void order_cloth( product cloth_list[]);
void order_shoes(product shoe_list[]);
void order_bag(product bag_list[]);
 
int main(){
	char ch;
 ch=getchoice();
 
  switch(ch)
  {
  case 'A' :
  case 'a':
	 customer_info();
    
	break; 
  case 'B':
  case 'b':
       Registration(); 
	   break;
  default:
    cout<<"YOU are out of the sysytem"<<endl;
 }
  
 return 0;
}
 char getchoice()
 {
  char co;
  system("cls");
  cout<<"###########***************  WELCOME TO SHOPPING MANGMENT SYSTEM ########"<<endl;
  cout<<"**************** CHOOSE A TO BE A CUSTOMER AND B TO REGISTER IN TO SHOPPING MANGMENT SYSTEM AS AN ADMINISTER *********\n ";
  cout<<"A)Customer"<<endl;
  cout<<"B)Administer"<<endl;
  cout<<"###########Press any key to exit.##############"<<endl; 
  cout<<"Enter your choice: "<<endl;
  cin>>co;
   return co;
	}
 void customer_info(){
 	cout<<"##############################################################################################\n";
	cout<<"######################## WELCOME TO SHOPPING MANAGMENT SYSTEM ###############################################\n";
	cout<<"Enter your Name: ";
	cin.ignore();
	getline(cin,cust.name);
	cout<<"Enter your Phone Number: ";
	cin>>cust.phone_number;
	cout<<"Enter your city that you live in : ";
	cin>>cust.add.city;
	cout<<"Enter your House Number: ";
	cin>>cust.add.housenum;
	cout<<"You can buy  ";
	cust_menu(&option);
}

void Registration()
{
    cout<<"Please enter carefully admin's ID number which is \"270515073\": "<<endl;
    int admin_ID=270515073;
    cin>>admin_1.admin_id;
    while (admin_ID != admin_1.admin_id)
    {
        int count=0;
        cout<<"Yu are not approved to use this service!!! \nplease try again"<<endl;
        cin>> admin_1.admin_id;
        if( count==2)
        cout<<"failed";
        exit;
        count++;
    }
        
     cout<<"Enter your full Name:"<<endl;
    cin>>admin_1.fullName;
     cout<<"Enter your city You live in :"<<endl;
    cin>>admin_1.add.city;
     cout<<"Enter your email:"<<endl;
    cin>>admin_1.email;
     cout<<"Enter your phone number:"<<endl;
    cin>>admin_1.phoneNo;
    cout<<"Enter your password:"<<endl;
    cin>>admin_1.password1;
    cout<<"Re-enter your password:"<<endl;
  cin>>admin_1.password2;
    if(admin_1.password1 != admin_1.password2)
    {
        cout<<"wrong password!!\nplease write your password again"<<endl;
        cin>>admin_1.password2;
    }
    cout<<"you have successfully Registered...."<<endl;
    cout<<"what do you want to do\n1.Login\n2.exit"<<endl;
    b:cin>>choice;
    switch(choice)
    {
        case 1:
        login();break;
        case 2:
        exit;
         default:
        {cout<<"enter correct value"<<endl;
        goto b;}
    }
 }

void login()
{
    string password,fullname1;
    cout<<"enter your username:"<<endl;//user name refer to fullname
    cin>>fullname1;
    cout<<"password: "<<endl;
    cin>>password;
    while(fullname1 != admin_1.fullName)
    {
        int count=0;
        cout<<"wrong comcination!!\nplease enter your full Name"<<endl;
        cin>>fullname1;
        
        if( count==2)
        {cout<<"failed";
        exit;}
         count++;    
    }
    while(password != admin_1.password2)
    {
        int count=0;
        cout<<"wrong password!!\nplease try again"<<endl;
        cin>>password;
        
         if( count==2)
        {cout<<"1.forgot password\n2.retry";
        int n;
        cin>>n;}
        
        if( count==3)
        {cout<<"failed";
        exit;}
        count++;
        
    }
    cout<<"you have successfully signed up...."<<endl;
    Admin_menu();
}

void Admin_menu()
{
	system("pause");
   system("cls");
    cout<<"\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	cout<<"\n############################\tPress 1 to ADD PRODUCT#########################";
	cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	 cout<<"\n\nOption: ";
	cin>>option;
	if(option==1){
		add_product(add_pro);
	}
		system("cls");
	cout<<"\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    cout<<"\n#########################\tPress 2 to DISPLAY ALL PRODUCTS###################";
	cout<<"\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	 cout<<"\n\n\tOption: ";
	 cin>>option;
	if(option==2){
		show_add_product(add_pro,num);
	}
 
}
void add_product(product add_pro[]){
   
       cout<<"**********************  The programm already have clothes,shoes and bags.  ****************************\n";
	   cout<<"*********************  Do you want to add another type of product?"<<endl;
	   cout<<"Press Y to continue or N to go back to Registration again \n";
	   cin>>press;
	   if(press=='Y' || press=='y'){
	   	cout<<"What is  your Product type: "<<endl;
	   	cin>>add_pro[i].product_type;
	   	 
	   		cout<<" Product information "<<endl;
	   		cout<<"Enter the ID of the Product : ";
	   		cin>>add_pro[i].product_num;
	   		cout<<"The Name of the Product : ";
	   		cin>>add_pro[i].product_name;
	   		cout<<"The price of the product : ";
	   		cin>>add_pro[i].price;
	   		cout<<"THe quantity of your product :";
	   		cin>>add_pro[i].quantity;
	   		cout<<"The dicount of the Product : ";
	   		cin>>add_pro[i].discount;
	   		
	   		cout<<endl;
	   		i++;
	   		
	   	}
	   	else{
		    
		   if(press=='N' || press=='n'){
	   	Registration();}
	}
	   	
}
	   
void show_add_product(	product add[], int num)
{
	 
	cout<<"Pruduct ID "<<setw(23)<<"Product Name"<<setw(23)<<"Quantity"<<setw(23)<<"Price"<<setw(23)<<"Discount\n";

		
		cout<<add[j].product_num<<setw(28)<<add[j].product_name<<setw(26)<<add[j].price<<setw(23)<<add[j].quantity<<setw(23)<<add[j].discount<<endl;
	   		j++;	
	}
	void cust_menu(int *opp){
		system("cls");
	cout<<"1)Cloth"<<endl;
	cout<<"2)Shoes"<<endl;
	cout<<"3)Bag"<<endl;
	cout<<"4)To Return to   menu"<<endl;
	cout<<"\n\n Enter your option   to buy things you want."<<endl;
	cin>>option;
	switch(option){
		case 1:
			clothlist();
			break;
		case 2:
			shoelist();
				break;
		case 3:
		     baglist();
		     	break;
		case 4:
		      getchoice();  
		
		defult:
			cout<<"SORRY YOU ARE OUT OF THE PROGRAMM. \n";}
	}
void clothlist(){
	int clothnum;
	system("cls");
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||| CLOTH LIST ||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cloth_list[0].product_num=1;   cloth_list[0].product_name="Sweater"; 	cloth_list[0].quantity=3; 	cloth_list[0].price=1200.00; cloth_list[0].discount=0;
	cloth_list[1].product_num=2;  cloth_list[1].product_name="Jeans";   cloth_list[1].quantity=4;     cloth_list[1].price=1000.00;  cloth_list[1].discount=0;
	cloth_list[2].product_num=3;   cloth_list[2].product_name="Sweat pants";    cloth_list[2].quantity=7;     cloth_list[2].price=2500.00;  cloth_list[2].discount=0.01;
	cloth_list[3].product_num=4;   cloth_list[3].product_name="Jackets";   	cloth_list[3].quantity=10;     cloth_list[3].price=2000.00;  cloth_list[3].discount=0.01;
	cloth_list[4].product_num=5;   cloth_list[4].product_name="Dresses";   	cloth_list[4].quantity=2;     cloth_list[4].price=3000.00;  cloth_list[4].discount=0.03;
	cloth_list[5].product_num=6;   cloth_list[5].product_name="Coats";   	cloth_list[5].quantity=5;     cloth_list[5].price=3500.00;  cloth_list[5].discount=0.03;
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"Pruduct Num "<<setw(23)<<"Product Name"<<setw(23)<<"Quantity"<<setw(23)<<"Price"<<setw(23)<<"Discount\n";
 	cout<<cloth_list[0].product_num<<setw(28)<<cloth_list[0].product_name<<setw(26)<<cloth_list[0].quantity<<setw(23)<<cloth_list[0].price<<setw(23)<<cloth_list[0].discount<<endl;
 	cout<<cloth_list[1].product_num<<setw(28)<<cloth_list[1].product_name<<setw(26)<<cloth_list[1].quantity<<setw(23)<<cloth_list[1].price<<setw(23)<<cloth_list[1].discount<<endl;
 	cout<<cloth_list[2].product_num<<setw(28)<<cloth_list[2].product_name<<setw(26)<<cloth_list[2].quantity<<setw(23)<<cloth_list[2].price<<setw(23)<<cloth_list[2].discount<<endl;
 	cout<<cloth_list[3].product_num<<setw(28)<<cloth_list[3].product_name<<setw(26)<<cloth_list[3].quantity<<setw(23)<<cloth_list[3].price<<setw(23)<<cloth_list[3].discount<<endl;
 	cout<<cloth_list[4].product_num<<setw(28)<<cloth_list[4].product_name<<setw(26)<<cloth_list[4].quantity<<setw(23)<<cloth_list[4].price<<setw(23)<<cloth_list[4].discount<<endl;
 	cout<<cloth_list[5].product_num<<setw(28)<<cloth_list[5].product_name<<setw(26)<<cloth_list[5].quantity<<setw(23)<<cloth_list[5].price<<setw(23)<<cloth_list[5].discount<<endl;
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
order_cloth(cloth_list);
	 
}
void shoelist(){
	int shoenum;
	system("cls");
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||| SHOE LIST ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
shoe_list[0].product_num=7; 	shoe_list[0].product_name="Sandals"; 	shoe_list[0].quantity=3; 	shoe_list[0].price=450.00; 	shoe_list[0].discount=0.0;
	shoe_list[1].product_num=8;   shoe_list[1].product_name="Heels";    shoe_list[1].quantity=1;     shoe_list[1].price=2500.00;  shoe_list[1].discount=0.01;
	shoe_list[2].product_num=9;   shoe_list[2].product_name="Sneakers";    shoe_list[2].quantity=5;     shoe_list[2].price=3450.00;  shoe_list[2].discount=0.03;
	shoe_list[3].product_num=10;   shoe_list[3].product_name="Hiking boots";   	shoe_list[3].quantity=6;     shoe_list[3].price=3000.00;  shoe_list[3].discount=0.03;
	shoe_list[4].product_num=11;   shoe_list[4].product_name="sports shoes";   	shoe_list[4].quantity=7;    shoe_list[4].price=3450.00;  shoe_list[4].discount=0.03;
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	cout<<"Pruduct Num"<<setw(23)<<"Product Name"<<setw(23)<<"Quantity"<<setw(23)<<"Price"<<setw(23)<<"Discount\n";
 	cout<<shoe_list[0].product_num<<setw(28)<<shoe_list[0].product_name<<setw(26)<<shoe_list[0].quantity<<setw(23)<<shoe_list[0].price<<setw(23)<<shoe_list[0].discount<<endl;
 		cout<<shoe_list[1].product_num<<setw(28)<<shoe_list[1].product_name<<setw(26)<<shoe_list[1].quantity<<setw(23)<<shoe_list[1].price<<setw(23)<<shoe_list[1].discount<<endl;
 		cout<<shoe_list[2].product_num<<setw(28)<<shoe_list[2].product_name<<setw(26)<<shoe_list[2].quantity<<setw(23)<<shoe_list[2].price<<setw(23)<<shoe_list[2].discount<<endl;
 		cout<<shoe_list[3].product_num<<setw(28)<<shoe_list[3].product_name<<setw(26)<<shoe_list[3].quantity<<setw(23)<<shoe_list[3].price<<setw(23)<<shoe_list[3].discount<<endl;
 		cout<<shoe_list[4].product_num<<setw(28)<<shoe_list[4].product_name<<setw(26)<<shoe_list[4].quantity<<setw(23)<<shoe_list[4].price<<setw(23)<<shoe_list[4].discount<<endl;
 		 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	 order_shoes( shoe_list);
	 	 
  }
void baglist( ){
	int bagnum;
	system("cls");
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||| BAG LIST ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	bag_list[0].product_num=12; 	bag_list[0].product_name="Backpack"; 	bag_list[0].quantity=6; 	bag_list[0].price=1500.00; 	bag_list[0].discount=0.01;
	bag_list[1].product_num=13;   bag_list[1].product_name="Suitcase";    bag_list[1].quantity=2;     bag_list[1].price=2400.00;  bag_list[1].discount=0.02;
	bag_list[2].product_num=14;   bag_list[2].product_name="Shopping bag";    bag_list[2].quantity=4;     bag_list[2].price=1000.00;  bag_list[2].discount=0.0;
	bag_list[3].product_num=15;   bag_list[3].product_name="Briefcase";   	bag_list[3].quantity=11;     bag_list[3].price=800.00;  bag_list[3].discount=0.0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	 
 	cout<<"Pruduct Num "<<setw(23)<<"Product Name"<<setw(23)<<"Quantity"<<setw(23)<<"Price"<<setw(23)<<"Discount\n";
 	cout<<bag_list[0].product_num<<setw(28)<<bag_list[0].product_name<<setw(26)<<bag_list[0].quantity<<setw(23)<<bag_list[0].price<<setw(23)<<bag_list[0].discount<<endl;
 		cout<<bag_list[1].product_num<<setw(28)<<bag_list[1].product_name<<setw(26)<<bag_list[1].quantity<<setw(23)<<bag_list[1].price<<setw(23)<<bag_list[1].discount<<endl;
 		cout<<bag_list[2].product_num<<setw(28)<<bag_list[2].product_name<<setw(26)<<bag_list[2].quantity<<setw(23)<<bag_list[2].price<<setw(23)<<bag_list[2].discount<<endl;
 		cout<<bag_list[3].product_num<<setw(28)<<bag_list[3].product_name<<setw(26)<<bag_list[3].quantity<<setw(23)<<bag_list[3].price<<setw(23)<<bag_list[3].discount<<endl;
 	 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	order_bag(bag_list);  
}
 void order_cloth(product cloth_list[]){
 	int clothnum; 
 	cout<<"Enter the number of the cloth you want to buy"<<endl;
        cin.ignore();
        cin>>clothnum;
        if (clothnum >= 1 && clothnum <= 6){
 		cout<<"How many quantities do you want?";
 		add:
       cin>>quant;
       if(quant <= cloth_list[clothnum-1].quantity){
    cloth_list[clothnum-1].price = quant * cloth_list[clothnum-1].price;
    	cout<<"The price is  "<<cloth_list[clothnum-1].price;
    	cout<<"\nYour Discount price is :";
    	cloth_list[clothnum-1].discount_price= cloth_list[clothnum-1].price * cloth_list[clothnum-1].discount;
    	cout<<cloth_list[clothnum-1].discount_price<<endl;
    		cout<<"Your total price is :";
    		cloth_list[clothnum-1].total_price=cloth_list[clothnum-1].price - cloth_list[clothnum-1].discount_price ;
    		 cout<<	cloth_list[clothnum-1].total_price;
    		 cloth_list[clothnum-1].quantity = cloth_list[clothnum-1].quantity - quant;
			 cout<<"\nDo you want add the product. If you want to add press 'A ' else press any key to exit.\n";
    	  cin>>press;
		if(press == 'a' || press == 'A'){
			cout<<"Enter the amout you want to add.\n";
			goto add;
		}
		else{
			cout<<"\n Thank you for visiting our Progarmm.\n";
		}
		
	
	}

	else{
		cout<<" SORRY, We donot have this much quantity in this product.\n";
		cout<<"You can Press 'C' to continue \n";
		cin>>press;
		if(press == 'c' || press == 'C'){
			clothlist();
		}
	
	  }

}else{

       cout<<"The clolth list only have  product numbers between 1-6.\n ";
  		cout<<"You can Press 'M' to goback to custmor menu. \n";
  	cin>>press;
		if(press == 'm' || press == 'M'){
			cust_menu(&option);
	}
	cout<<"SORRY YOU ARE OUT OF THE PROGRAMM.\n";
}
}
void order_shoes(product shoe_list[]){
 	int shoenum,order2=15;
 	cout<<"Enter the number of the cloth you want to buy"<<endl;
        cin.ignore();
        cin>>shoenum;
        if(shoenum>=7 && shoenum <= 11){		
 		cout<<"How many quantities do you want?";
 		cin>>quant;
 		add:
       if(quant <= shoe_list[shoenum-7].quantity){
    shoe_list[shoenum-1].price = quant * shoe_list[shoenum-7].price;
    	cout<<"The price is  "<<	shoe_list[shoenum-7].price;
    	cout<<"\nYour Discount  price is :";
    	shoe_list[shoenum-7].discount_price= shoe_list[shoenum-7].price * shoe_list[shoenum-7].discount;
    	cout<<shoe_list[shoenum-7].discount_price<<endl;
    		cout<<"Your total price is :";
    		shoe_list[shoenum-7].total_price = shoe_list[shoenum-7].price - shoe_list[shoenum-7].discount_price ;
    		 cout<<	shoe_list[shoenum-7].total_price;
    		 shoe_list[shoenum-7].quantity = shoe_list[shoenum-7].quantity - quant;
    		 cout<<"\nDo you want add the product. If you want to add press 'A ' else press any key to exit.\n";
    	  cin>>press;
		if(press == 'a' || press == 'A'){
			cout<<"Enter the amout you want to add.\n";
			goto add;
		}
		else{
			cout<<"\n Thank you for visiting our Progarmm.\n";
		}
			
		
    		  
	}
	else{
		cout<<" SORRY, We donot have this much quantity in this product.\n";
		cout<<"You can Press 'C' to continue \n";
		cin>>press;
		if(press == 'c' || press == 'C'){
			shoelist();
		}
	
	  }

} 
else{
       cout<<"The shoes list only have  product numbers between 7-11.\n ";
  		cout<<"You can Press 'M' to goback to custmor menu. \n";
  	cin>>press;
		if(press == 'm' || press == 'M'){
			cust_menu(&option);
	}
	cout<<"SORRY YOU ARE OUT OF THE PROGRAMM.\n";
}
}

/////////////////////////////////////////////////
 	void order_bag(product bag_list[]){
 	int bagnum,order3=1;
 	cout<<"Enter the number of the shoes you want to buy"<<endl;
        cin.ignore();
        cin>>bagnum;
        if(bagnum >= 12 || bagnum <= 15){
 		cout<<"How many quantities do you want?";
       cin>>quant;
       add:
       if(quant <= bag_list[bagnum-12].quantity){
    bag_list[bagnum-12].price = quant * bag_list[bagnum-12].price;
    	cout<<"The price is  "<<bag_list[bagnum-12].price;
    	cout<<"\nYour Discount  price is :";
    	bag_list[bagnum-12].discount_price= bag_list[bagnum-12].price * bag_list[bagnum-12].discount;
    	cout<<bag_list[bagnum-12].discount_price<<endl;
    cout<<"Your total price is :";
    		bag_list[bagnum-12].total_price = bag_list[bagnum-12].price - bag_list[bagnum-12].discount_price ;
    		 cout<<	bag_list[bagnum-12].total_price;
    		 shoe_list[bagnum-12].quantity = shoe_list[bagnum-12].quantity - quant;
    		 cout<<"\nDo you want add the product. If you want to add press 'A ' else press any key to exit.\n";
    	  cin>>press;
		if(press == 'a' || press == 'A'){
			cout<<"Enter the amout you want to add.\n";
			goto add;
	      }
	      else{
			cout<<"\n Thank you for visiting our Progarmm.\n";
		}
		
}	else{
		cout<<" SORRY, We donot have this much quantity in this product.\n";
		cout<<"You can Press 'C' to continue \n";
		cin>>press;
		if(press == 'c' || press == 'C'){
			clothlist();
		}
	
	  }

}else{
       cout<<"The bag list only have  product numbers between 12-14.\n ";
  		cout<<"You can Press 'M' to goback to custmor menu. \n";
  	cin>>press;
		if(press == 'm' || press == 'M'){
			cust_menu(&option);
	}
	cout<<"SORRY YOU ARE OUT OF THE PROGRAMM.\n";
}
}
 
 	
 	
 	
 	
 	
 	
 

	
	
