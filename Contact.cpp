#include <iostream>
#include "Contact.h"
using namespace std;
namespace sict{
    Contact::Contact(){
        Name[0] = '\0';
        numberOfPhones = 0;
    }
    Contact::Contact(char Name_, double phones_, int numberOfPohnes_){
        if (phones_ > 11001000000 && Name_ != '\0' && numberOfPhones_ > 0){
            Name = Name_;
            numberOfPhones_ = numberOfPhones;
        }
        for(int i = 0; i <= numberOfPhones_; i++){
            int coutryCode, areaCode, phoneNumber;
            countryCode = phones_ /10000000000;
            areaCode = (phones_%10000000000)/10000000;
            phoneNumber = areaCode%10000000;
            if (coutryCode > 0 && countryCode < 100 && areaCode > 99 && areaCode < 1000 && phoneNumber > 999999 && phoneNumber < 10000000){
                phones = new double[numberOfPohnes_];
            }
        }
    }
    Contact::~Contact(){
        delete [] phones;
        //phones = nullptr;
    }
    bool Contact::isEmpty() const{
        if (Name[0] == '\0'){
            return false;
        }
        else{
            return true;
        }
    }
    int Contact::separator(double phone_){
        int inter, area, number;
        inter = phone_ /10000000000


    void Contact::display(){
        int number[2];//used for separating the area code an phone numbers
        if(Name[0] == '\0'){
            cout << "Empty contact!" << endl;
        }
        else{
            cout << Name << endl;
            for (int i = 0; i <= numberOfPhones; i++){
                cout << "(+" << phones[i]/10000000000 << ")";
                number[0] = (phones[i]/10000000000) * 10000000000;
                number[1] = phones[i] - number[0];
                cout <<  number[1] / 100000000 << " ";
                number[2] = (number[1]/100000000) * 100000000;
                number =
            }
        }
    }
}


