#include <iostream>
#include <sstream>
#include <windows.h>
#include <mysql.h>
#include "head.h"
using namespace std ;

Parking :: Parking() {
cout << "                   =========== PROGRAMME RUNNING ==========" << endl ;
cout << "       1. insert record" << endl ;
cout << "       2. view record" << endl ;
cout << "       3. Total vehicles" << endl ;
cout << "       4. clear record" << endl ;
cout << "       5. Close programm" << endl ;
}

Parking :: ~Parking() {
/*cout<<""<<endl ;
cout<<""<<endl ;
cout<<""<<endl ;
cout << "=========== terminated ============" << endl ;*/
}

string Parking::ui() {
    cout << "enter value : " ;
    cin >> nom ;



                                if(nom == 1){

                                    cout << "           ========= PLEASE SELECT VEHICLE =========" << endl ;
                                    cout <<         "       1. car " << endl ;
                                    cout <<         "       2. bike " << endl ;
                                    cout << "select vehicle : " ;
                                    int vehicle ;
                                    cin >> vehicle ;

                                        if(vehicle == 1) {
                                            cout << "       enter car number :" ;
                                            cin >> carkanum;
                                            cout << endl ;
                                            cout << "       enter time duration in hours(min. 1hr) :" ;
                                            cin >> tm_duration;
                                        }
                                        else if(vehicle == 2) {
                                            cout << "       enter bike number :" ;
                                            cin >> carkanum ;
                                            cout << endl ;
                                            cout << "       enter time duration in hours(min. 1hr) :" ;
                                            cin >> tm_duration;
                                        }
                                        else{};
                                }

                                else if(nom == 2) {
                                    cout << "           ======= VIEWING RECORD =======" << endl ;
                                    cout << "" << endl ;
                                    cout << "" << endl ;
                                }

                                else if(nom == 3){
                                    cout << "           ======= TOTAL VEHICLES =======" << endl ;
                                }

                                else if(nom == 4) {
                                    cout << "           ======== CLEARING RECORD =======" << endl ;
                                    cout << "" << endl ;
                                    cout << "Enter password : " ;
                                    cin >> pass;
                                }

                                else if(nom == 5) {
                                    cout << endl ;
                                    cout << endl;
                                    cout << "           ========= disconnected =========" << endl ;
                                }

                                return carkanum ;

}

void Parking:: setdata(std::string name , std::string number) {
name = carkanum;
number = nom ;
}

string Parking :: getdata() {
return carkanum ;
}

int Parking :: getdata2() {
return nom ;
}

int Parking :: getdata3() {
return tm_duration ;
}


