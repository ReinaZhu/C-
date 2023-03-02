//
// Created by Lenovo on 2019/9/12.
//
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main(){
    double latitude1;
    double longitude1;
    double latitude2;
    double longitude2;
    string city1;
    string city2;
    cout<<"Please write the name of the first city and its latitude and longitude"<<endl;
    cin>>city1>>latitude1>>longitude1;
    cout<<"Please write the name of the second city and its latitude and longitude"<<endl;
    cin>> city2>>latitude2>>longitude2;
    double phi1 = (90 - latitude1)*M_PI/180;
    double theta1=longitude1*M_PI/180;
    double phi2 = (90 - latitude2)*M_PI/180;
    double theta2=longitude2*M_PI/180;
    double c=sin(phi1)*sin(phi2)*cos(theta1-theta2)+cos(phi1)*cos(phi2);
    double d =6371*acos(c);
    cout <<"The first city:" << city1<<endl;
    cout <<"The second city:" << city2<<endl;
    cout <<"The distance between " << city1<<" and "<<city2<<" is "<<d<<"km."<<endl;

    return 0;
}

