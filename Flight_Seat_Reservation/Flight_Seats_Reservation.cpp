// flight reservation system of virgin airlines

 
#include<iostream>
#include<fstream>
#include<string>

int flightCount();

using namespace std;

struct seat_reservation{
	char seat_class='0';
	char seat_name[6]={'#','#','#','#','#','#'};
};

class Flight{
	private:
		string flight_Number;
		string dept_date_dept_time;
		string dept_airport_code;
		string arrival_airport_code;
		struct seat_reservation rows[60];
		
		
	public:
			void setFNumber(string name);
			string getFNum();
			void setDate_Time(string dt);
			void setDAirportcode(string apt);
			void setAAirportcode(string apt2);
			void setRow(int r,char type, char seat );
			void viewSeats();
			void countSeats();
			void seatBook(int row,char cls, char seat);
			void writefile();
			int numSeats(char type);
			
			
			void printFlight();
			string FnumberOut();
		
};

ofstream  writef("flights.dat");// create a variable of type ofstream eke name,flights.dat is the name of that variable

void Flight::writefile()//to write data for the particular file
{ 

    writef << flight_Number << endl; // using writef can write flight number detail on that file
                                     
    writef << dept_date_dept_time << endl;
    writef << arrival_airport_code << endl;
    writef << dept_airport_code << endl;
    int i;
    for (i = 0; i < 60; i++)
    {
        if (rows[i].seat_class != '0')
        {
            writef << i << " " << rows[i].seat_class << " ";
            int j = 0;
            for (j = 0; j < 6; j++)
            { 
                if (rows[i].seat_name[j] != '#')//print the seat names
                {
                    switch (j)
                    {
                    case 0:
                        writef << "A";
                        break;
                    case 1:
                        writef << "B";
                        break;
                    case 2:
                        writef << "C";
                        break;
                    case 3:
                        writef << "D";
                        break;
                    case 4:
                        writef << "E";
                        break;
                    case 5:
                        writef << "F";
                    }
                }
            }
            writef<<endl;
        }
    }
}






void Flight::seatBook(int row,char cls, char seat){// do unavailable  the seat which is goint to book by user
	int pos=0;
	
	switch(seat){
		case 'A':pos=0; 
		break;
		case 'B':pos=1; 
		break;
		case 'C':pos=2; 
		break;
		case 'D':pos=3; 
		break;
		case 'E':pos=4; 
		break;
		case 'F':pos=5; 
		break;	
		default : pos=6;
	}
	if(pos==6){
		cout<<"Wrong Intput"<<endl;
	}
	else if(rows[row].seat_name[pos]!='#'){
		rows[row].seat_name[pos]='#';
		cout<<row<<"\t"<<cls<<"\t"<<seat<<" is booked\t"<<endl;
	}
	else
		cout<<"Seat Cannot book"<<endl;
	
	
}

void Flight::countSeats() // count and display the seats of relevant flight number
{	int econ=0,bis=0;
	int i,j;
	for(i=0;i<60;i++){
		for(j=0;j<6;j++){
			if(rows[i].seat_name[j]!='#'){
				if(rows[i].seat_class=='E')
					econ++;
				else if(rows[i].seat_class=='B')
					bis++;
			}
		}
	}
	cout<<"Economy class seats= "<<econ<<endl; 
	cout<<"Business class seats=  "<<bis<<endl; 
		
}
int Flight::numSeats(char type) //count and dispaly the seats of the flight which is requested by user
{	int econ=0,bis=0;           
	int i,j;
	for(i=0;i<60;i++){
		for(j=0;j<6;j++){
			if(rows[i].seat_name[j]!='#'){
				if(rows[i].seat_class=='E')
					econ++;
				else if(rows[i].seat_class=='B')
					bis++;
			}
		}
	}
	if(type=='E')
	return econ;
	else
	return bis;
		
}

void Flight::printFlight(){ //this function print a relavent flight details of a flight without seat details
	cout<<"Flight number= "<<flight_Number<<endl;
	cout<<"Departure Date and Time= "<<dept_date_dept_time<<endl;
	cout<<"Departure Airport Code= "<<dept_airport_code<<endl;
	cout<<"Arrival Aiport Code= "<<arrival_airport_code  <<endl;

}

string Flight::FnumberOut(){
	return flight_Number;
	}

void Flight::viewSeats() // seat views of each flight
{	int i=0;
	for(i=0;i<60;i++){ // flight has 60 seat rows
		if(rows[i].seat_class!='0'){ //when seat_class equal ='B' or 'E'
			cout<<"Row number "<<i<<"\t"<<"Seat class "<<rows[i].seat_class<<"\t";
			int j=0;
			for(j=0;j<6;j++){// print the seat names
				if(rows[i].seat_name[j]!='#'){
				
					switch(j){
						
						case 0:
							cout<<"A";
							break;
						case 1:
							cout<<"B";
							break;
						case 2:
							cout<<"C";
							break;
						case 3:	
						    cout<<"D";
						    break;
						case 4:
						    cout<<"E";
						    break;
						case 5:
						    cout<<"F";
  					}
  					
					
				
				}
			
			}					
										
			cout<<endl;
		}
	}
	
}

void Flight::setRow(int r,char type, char seat ){//set the seats to relevant variables
	
	rows[r].seat_class=type; // assign the class name to relevant variables
	int pos=0;
	            //check the array index position relavent to the each seat
	switch(seat){
		case 'A':pos=0; 
		break;
		case 'B':pos=1; 
		break;
		case 'C':pos=2; break;
		case 'D':pos=3; break;
		case 'E':pos=4; break;
		case 'F':pos=5; break;
		default : pos=6; 
		cout<<"wrong seat"<<endl;
		// if there is anything beyond A-F range, infornm to user that by using this condition
	}
	if(pos!=6) //if we havent have a wrong seat set the seatName to the array
	rows[r].seat_name[pos]='1';
	
}

void Flight::setFNumber(string name){
	flight_Number=name;
}
string Flight::getFNum(){
	return flight_Number;
}

void Flight::setDate_Time(string dt){
	dept_date_dept_time=dt;
}


void Flight::setDAirportcode(string apt){
	dept_airport_code=apt;
}

void Flight::setAAirportcode(string apt2){
	arrival_airport_code=apt2;
}



int main(){
	
	int fcount=flightCount(); //get the number of flights for fcount;
	Flight *fl=new Flight[fcount];
	
	ifstream file;	//create a reference called "file" to flights.txt	
	string line;
	
   file.open("flights.txt");//open the flights.txt,put a reference "file" forfile.txt,we access the specific text file by using file reference 
    if (!file.is_open()) // check whether the file is open or not
	{
		cout << "Error in File Opening";
	}						
	
//getine(file,line) this function has a return value similar to eof
    while (getline(file,line)) // go through until find the not empty line
    {
    	int i=0;
        for (i = 0; i < fcount; i++)// put the data to relavent objects (flights)
        {	
            fl[i].setFNumber(line); 
			
			getline(file,line);
			
			fl[i].setDate_Time(line);
				
			getline(file,line);
	
			fl[i].setDAirportcode(line);
			
			getline(file,line);
			fl[i].setAAirportcode(line); 
			
			getline(file,line); //get the first seat details row to the string called "line" 
			
            do
           {
           	
            int j,a;
			for(j=0;j<3;j++){
				if(line[j]==' ' && j==1){ // we look where can we get the first space of the line :ex 1 E AB
										// if the row number is one digit ,we find it from this process
					int r=int(line[0]-48); // because we should typecast strign to int
					for(a=4;a<line.length();a++){ // we should find the seats
												// seat name starts from 4th position
												
						fl[i].setRow(r,line[j+1],line[a]); // pass the value (row number,seat class,seat name)
					}
				}
				else if(line[j]==' ' && j==2){ // we look where can we get the first space of the line :ex 15 E CDE
					int r=(int(line[0])-48)*10+(int(line[1])-48);//if the row number is two digit ,we find it from this process
					for(a=5;a<line.length();a++){
						fl[i].setRow(r,line[j+1],line[a]);
					}								
				}							
		
			}
			getline(file, line);// read the second seat line ,3,4th and so on
            } while(line.length() > 0);// read line by line untill find the space for the relevant flight ,after the loop will terminate
            							
            getline(file, line); // now read data of the next plane object from top to bottom
		   }
    }
    
    file.close();
    
    
    int c=1;
    while(c!=5){
	
    cout<<endl<<endl<<"--------------------****Main Menu****-------------------------\n\n"<<endl<<endl;
    cout<<"1.DISPLAY AVAILABLE FLIGHTS"<<endl;
    cout<<"2.VIEW FLIGHT"<<endl;
    cout<<"3.SEAT AVAILABILITY"<<endl;
    cout<<"4.SEAT BOOKING"<<endl;
    cout<<"5.EXIT"<<endl;
	cout<<endl;
    cout<<"Enter your choice:";
    int i=0,k=0;
    cin>>c;
    cout<<endl;
    switch(c){
    	case 1:{
    			int flag2=0;
    		for(int i=0;i<fcount;i++){
				fl[i].printFlight();
				fl[i].countSeats();
				cout<<endl<<endl;    				
				}
			break;
		}
					
		case 2:	{
				cout<<"Enter the flight number:"<<endl<<endl;
		string str1;
		cin>>str1;
		
		int flag=0;
		for(int i=0;i<fcount;i++){
			
			if((fl[i].getFNum()==str1)){
				flag=1;
				fl[i].printFlight();
				fl[i].countSeats();
				//fl[i].viewSeats();
				
			}
			}if(flag==0){
				cout<<"Flight number is not present"<<endl;
			}
			break;
		}
	
		
			
		
		
	
		case 3:{
		cout<<"Enter a flight number"<<endl;
		string str1;
		int w,flag=0;
		char type;
		cin>>str1;
		cout<<"Enter the class (E- Ecconomy, B- Buissiness)"<<endl;
		cin>>type;
		cout<<"Enter the number of seats required by customer"<<endl;
		cin>>w;
		for(int i=0;i<fcount;i++){
			if((fl[i].getFNum()==str1)){
				flag=1;
				int seats;
				seats=fl[i].numSeats(type);
				if(seats>=w){
					cout<<w<< " seats Available in the flight"<<endl;
				}
				else
					cout<<w<< " seats Not Available in the flight"<<endl;
				
			}
			}if(flag==0){
				cout<<"Flight number is not present"<<endl;
			}
			
			
		
			break;
		}
		case 4:{
			cout<<"Enter the flight number:"<<endl;
		string str1;
		cin>>str1;
		cout<<endl;
		int flag=0;
		for(int i=0;i<fcount;i++){
			
			if((fl[i].getFNum()==str1)){
				flag=1;
				fl[i].printFlight();
				fl[i].countSeats();
				fl[i].viewSeats();
				cout<<endl;
				int row;
				char type,st;
				cout<<"Enter the class: ";
				cin>>type;
				cout<<"Enter the row :";
				cin>>row;
				cout<<"Enter the seat position A-F :";
				cin>>st;
				fl[i].seatBook(row,type,st);
				
				
			}
			}if(flag==0){
				cout<<"Flight number is not present"<<endl;
			}
			break;
		}
		case 5:{
			c=5;
			int i;
			for(i=0;i<fcount;i++){
				fl[i].writefile();
				writef<<endl;
				}
			cout<<"Exiting from the system";
			break;
		}
		
		
	}
}

		
		
		
	
	
	/*				 // close the file after reading the data
	int i;
	for(i=0;i<fcount;i++){ 
	fl[i].printFlight();// printf the details of the specific flight
    fl[i].viewSeats(); // printf the order of the seats
    fl[i].countSeats(); // print the number of seats
	} 
		
	
	fl[4].seatBook(20,'E','A');
	fl[4].printFlight();
    fl[4].viewSeats();
    fl[4].countSeats();
    	
	
	fl[4].writefile(); 	
	*/
		return 0;
	 
}


int flightCount(){
	ifstream file; //
	string line;
	int flightCount=0;
	file.open("Flights.txt");//opent the file
	while(getline(file,line)){
		if(line.length()==0){
			
			flightCount++;
		}
	}
	
	return (flightCount+1);
}

