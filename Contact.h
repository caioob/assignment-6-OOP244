#ifndef CONTACT_H
#define CONTACT_H

using namespace std;

namespace sict{
    const int MAX_CHAR = 20;
    class Contact{
        char Name[MAX_CHAR + 1];
        long long *phones;
        int numberOfPhones;
        int countryCode, areaCode, firstPart, secondPart, fullNumber;
    public:
        Contact();
        Contact(char*,long long*,int);
        ~Contact();
        bool isEmpty() const;
        void display();// needed to make this function with write permissions to void separator(double)
        void separator (long long);
        void clearSeparator();
    };
}
#endif
