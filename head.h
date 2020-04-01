#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
using namespace std ;
class Parking {
public :
   Parking();
   ~Parking();
    string carkanum ;
   int nom;
   string fare ;
   string pass ;
    int tm_duration ;
   void setdata(std::string name , std::string number);
   string ui();
   string getdata();
   int getdata2();
    int getdata3();

} ;


#endif // HEAD_H_INCLUDED
