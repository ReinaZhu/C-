#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double latitude1;
    double longitude1;
    double latitude2;
    double longitude2;
    string city1;
    string city2;
    cout<<"The first city:";
    getline(cin,city1);
    while(cin.fail()){
        cout<<"Please input the correct name"<<endl;
        cout<<"The first city:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>city1;
    }
    cout<<"The latitude and longitude of first city,separates by a space:";
    cin>>latitude1>>longitude1;
    while(cin.fail()){
        cout<<"Please input the correct numbers"<<endl;
        cout<<"The latitude and longitude of first city,separates by a space:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>latitude1>>longitude1;
     }
    while(latitude1>90||latitude1<-90){
        cout<<"Latitude should be between -90 to 90"<<endl;
        cout<<"The latitude and longitude of first city,separates by a space:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>latitude1>>longitude1;
    }
    while(longitude1>180||longitude1<-180){
        cout<<"Longitude should be between -180 to 180"<<endl;
        cout<<"The latitude and longitude of first city,separates by a space:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>latitude1>>longitude1;
    }
    cin.get();
    cout<<"The second city:";
    getline(cin,city2);
    while(cin.fail()){
        cout<<"Please input the correct name"<<endl;
        cout<<"The second city:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>city2;
    }
    cout<<"The latitude and longitude of second city,separates by a space:";
    cin>>latitude2>>longitude2;
    while(cin.fail()){
        cout<<"Please input the correct numbers"<<endl;
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cout<<"The latitude and longitude of second city,separates by a space:";
        cin>>latitude2>>longitude2;
    }
    while(latitude2>90||latitude2<-90){
        cout<<"Latitude should be between -90 to 90"<<endl;
        cout<<"The latitude and longitude of first city,separates by a space:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>latitude1>>longitude1;
    }
    while(longitude2>180||longitude2<-180){
        cout<<"Longitude should be between -180 to 180"<<endl;
        cout<<"The latitude and longitude of first city,separates by a space:";
        cin.clear();
        cin.sync();
        while(cin.get() != '\n'){}
        cin>>latitude1>>longitude1;
    }
    double phi1 = (90 - latitude1)*M_PI/180;
    double theta1=longitude1*M_PI/180;
    double phi2 = (90 - latitude2)*M_PI/180;
    double theta2=longitude2*M_PI/180;
    double c=sin(phi1)*sin(phi2)*cos(theta1-theta2)+cos(phi1)*cos(phi2);
    double d =6371*acos(c);
    cout<<"The distance between " <<city1<< " and "<<city2<<" is "<<d<<" km."<<endl;

    return 0;
}

