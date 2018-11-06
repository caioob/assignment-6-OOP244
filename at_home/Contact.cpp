#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sict{
    bool Contact::phone_validation(long long phone){
        int countryCode_, areaCode_, fullNumber_;
        countryCode_ = phone/10000000000;
        areaCode_ = (phone%10000000000)/10000000;
        fullNumber_ = phone%10000000;
        if(phone > 10000000000  && phone < 999999999999){
            if (countryCode_ > 0 && countryCode_ <= 19 && areaCode_ > 99 && areaCode_ < 1000 && fullNumber_ > 999999 && fullNumber_ < 10000000){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }

    void Contact::clearSeparator(){
        countryCode = 0;
        areaCode = 0;
        fullNumber = 0;
        firstPart = 0;
        secondPart = 0;
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
    Contact::Contact(const char* Name_, long long* phones_, int numberOfPhones_){
        long long validPhones [50];
        clearSeparator();
        Name[0] = '\0';
        phones = nullptr;
        numberOfPhones = 0;
        for(int i = 1; i < numberOfPhones_; i++){
            if(phones_[i] > 10000000000  && phones_[i] < 999999999999){
                separator(phones_[i]);
            }
            if (countryCode > 0 && countryCode <= 19 && areaCode > 99 && areaCode < 1000 && fullNumber > 999999 && fullNumber < 10000000){
                numberOfPhones = numberOfPhones + 1;
                validPhones[numberOfPhones] = phones_[i];
                clearSeparator();
            }
        }
        if(Name_ != '\0' || Name_ != nullptr){
            strncpy(Name, Name_, 20);
        }
        if (numberOfPhones > 0 ){
            int index = numberOfPhones;
            phones = new long long [index];
            for(int i = 0; i <= numberOfPhones; i++){
                phones[i] = validPhones[i];
            }
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
            for (int i = 0; i < numberOfPhones; i++){
                separator(phones[i]);
                cout << "(+" << countryCode << ") " << areaCode << " " << firstPart << "-";
                cout.width(4);
                cout.fill('0');
                cout<< secondPart << endl;

            }
        }
    }

    Contact& Contact::operator=(const Contact& Contact_){

        if (this != &Contact_){
            strncpy(Name, Contact_.Name, 20);
            numberOfPhones = Contact_.numberOfPhones;
            if (Contact_.phones != nullptr){
                phones = new long long [numberOfPhones];
                for (int i = 0; i < numberOfPhones; i++){
                    phones[i] = Contact_.phones[i];
                }
            }
            else{
                phones = nullptr;
            }
        }
       return *this;
    }


    Contact& Contact::operator+=(long long phones_){
       if (phones_ > 10000000000 && phones_ < 999999999999) {
			int countryCode_ = (phones_ / 10000000000);
			int areaCode_ = ((phones_ % 10000000000) / 10000000);
			int fullNumber_ = phones_ % 10000000;

			if (countryCode_ > 0 && countryCode_ <= 19 && areaCode_ > 99 && areaCode_ < 1000 && fullNumber_ > 999999 && fullNumber_ < 10000000) {
				numberOfPhones += 1;
				long long* newPhones = new long long[numberOfPhones];
				for (int i = 0; i < numberOfPhones - 1; i++) {
					newPhones[i] = phones[i];
				}

				newPhones[numberOfPhones - 1] = phones_;
				delete[] phones;
				phones = nullptr;

				phones = new long long[numberOfPhones];

				for (int i = 0; i < numberOfPhones; i += 1) {
					phones[i] = newPhones[i];
				}
				delete[] newPhones;
				newPhones = nullptr;
			}
		}

			return *this;
   }

    Contact::Contact(const Contact& Contact_){
        *this = Contact_;
    }
}


