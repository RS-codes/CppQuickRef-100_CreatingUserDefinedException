100 _ Creating Custom, User Defined Exception Class
#include <iostream>
#include <exception>  /*since exception class is defined in this and all other exception classes 									are defined in this*/
using namespace std;
class Overspeed:public exception{ //user-defined exception- derived from exception class 
    int speed;
public:
    const char* what(){ 	//overloading what() method of exception class
        return "\n\tALERT\npls follow the speed-limit!!!\n";
    }
    void setSpeed(int speed){
        this->speed=speed;
    }
    void getSpeed(){
        cout<<"Ur car speed is: "<<speed<<endl;
    }
};
class Car{
    int speed;
public:
    Car(){
        speed=0;
    }
    void accelerate(){    // THIS METHOD THROWS THE USER-DEFINED EXCEPTION
        for(;;){
            speed+=10;
            cout<<"speed: "<<speed<<endl;
            if(speed>=100){
                Overspeed s;	//calling the userdefined exception class obj  
                s.setSpeed(speed);  //passing value to the  userdefined exception class obj
                throw(s);     // THROWING USERDEFINED EXCEPTION
            }
        }
    }
};
int main(){
    Car ford;
    try{
        ford.accelerate();   //THROWS userdefined exception, so keep it inside TRY CATCH block 
    }catch(Overspeed s){ //handling the user defined exception
        cout<<s.what()<<endl;  //calling the OVERLOADED user-defined what() method 
        s.getSpeed();
    }
    return 0;
}
