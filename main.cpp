#include <iostream>
#include <sstream>
#include <windows.h>
#include <mysql.h>
#include <ctime>
#include <time.h>
#include "head.h"
using namespace std;

const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[100];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


int main()
{

    MYSQL* pms = NULL ;
    pms = mysql_init(0) ;
    pms = mysql_real_connect(pms , "192.168.228.1" ,"varun" ,"varun" ,"pms" , 0 ,NULL , 0) ;
    if(pms){
        cout << "connected" << endl ;
    }
    else {
        cout << "error" << endl ;
    }

    Parking carnum ;
    carnum.ui();


int store = 0 ;
stringstream ss ;
string carno = carnum.getdata() ;
string timep = currentDateTime() ;
int number = carnum.nom ;
int farep = carnum.getdata3();
if(farep <= 12){
    farep =farep * 10 ;
}
else{
    farep = 200 ;
}
if(number == 1) {
ss << "INSERT INTO pms (vehicle_no , time , fare) VALUES('" << carno << "' , '" << timep << "' , '" << farep << "')";
	string query = ss.str();
	const char* q = query.c_str();
    store = mysql_query(pms , q);

	if(store == 0){
        cout << "" << endl ;
        cout << "" << endl ;
        cout << "" << endl ;
        cout << "        TOTAL FARE : " << farep << endl;
        cout << "" << endl ;
        cout << "" << endl ;
        cout << "       ========= RECORD INSERTED ==========" << endl ;
	}
	else{
        cout << "error" << endl ;
	}
}

else if(number == 2) {

MYSQL_RES *result ;
MYSQL_ROW row ;
int num_fields ;
int i ;

mysql_query(pms, "SELECT * FROM pms");
result = mysql_store_result(pms);
num_fields = mysql_num_fields(result);
while ((row = mysql_fetch_row(result))) {
    for(i = 0; i < num_fields; i++) {
        cout<<"     "<< row[i]<<"\t";
}
cout<<endl;
}

}
else if(number == 3) {

MYSQL_RES *result ;
int num_fields ;
int i = 0 ;

mysql_query(pms, "SELECT * FROM pms");
result = mysql_store_result(pms);
num_fields = mysql_num_rows(result);

   while(i <= num_fields) {
    i++;
   }
cout <<""<<endl;
cout <<""<<endl;
cout<<"       Total number of vehicle :   " << i-1 << endl;
cout <<""<<endl;
cout <<""<<endl;
}

else if(number == 4) {
    string pass = carnum.pass;
    if(pass == "varun") {
        char *pss ;
        pss = "DELETE FROM pms;";
        mysql_query(pms, pss) ;
        cout << endl;
        cout << endl ;
        cout << "       -------CLEARED-----" ;
    }
    else{
        cout << endl;
        cout << endl ;
        cout << "        WRONG PASSWORD " ;
    };
}
else if(number == 5) {
    mysql_close(pms);
}
else{ cout << "please select from above please" ;} ;
    return 0;
}
