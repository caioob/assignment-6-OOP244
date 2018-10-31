#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sict{
    void Contact::clearSeparator(){
        countryCode = 0;
        areaCode = 0;
        fullNumber = 0;
        firstPart = 0;
        secondPart = 0;
        //cout << "(+" << countryCode << ") " << areaCode << " " << phoneNumber[1] << "-" << phoneNumber[2] << endl;
    }
    void Contact::separator (long long phones_){
        countryCode = phones_ /10000000000;
        areaCode = (phones_%10000000000)/10000000;
        fullNumber = phones_%10000000;
        firstPart = fullNumber/10000;
        secondPart = fullNumber%10000;
    }

    Contact::Contact(){
        Name[0] = '\0';
        numberOfPhones = 0;
        phones = nullptr;
    }
    Contact::Contact(char* Name_, long long* phones_, int numberOfPhones_){
        long long validPhones [50];
        clearSeparator();
        Name[0] = '\0';
        phones = nullptr;
        numberOfPhones = 0;
        for(int i = 1; i <= numberOfPhones_; i++){
            if(phones_[i] > 10000000000  && phones_[i] < 999999999999){
                separator(phones_[i]);
            }
            if (countryCode > 0 && countryCode < 100 && areaCode > 99 && areaCode < 1000 && fullNumber > 999999 && fullNumber < 10000000){
                numberOfPhones = numberOfPhones + 1;
                validPhones[numberOfPhones] = phones_[i];
                clearSeparator();
            }
        }
        if(Name_ != '\0' || Name_ != nullptr){
            strncpy(Name, Name_, 20);
        }
        //copying valid number to the current object
        if (numberOfPhones > 0 ){
            int index = numberOfPhones;
            phones = new long long [index];
            for(int i = 0; i <= numberOfPhones; i++){
                phones[i] = validPhones[i];
            }
            //numberOfPhones = validPhones;
        }

    }
    Contact::~Contact(){
        delete [] phones;
        phones = nullptr;
    }
    bool Contact::isEmpty() const{
        if (Name[0] == '\0' ){
            return true;
        }
        else{
            return false;
        }
    }

    void Contact::display(){
        if(isEmpty() == true){
            cout << "Empty contact!" << endl;
        }
        else if (isEmpty() != true){
            cout << Name << endl;
            for (int i = 1; i <= numberOfPhones; i++){
                separator(phones[i]);
                cout << "(+" << countryCode << ") " << areaCode << " " << firstPart << "-";
                cout.width(4);
                cout.fill('0');
                cout<< secondPart << endl;

            }
        }
    }
}


