#ifndef CONTACT_H
#define CONTACT_H
#define MAX_CHAR 20

using namespace std;

namespace sict{

    class Contact{
        char Name[MAX_CHAR + 1];
        double *phones;
        int numberOfPhones;

    public:
        Contact();
        Contact(char,double,int);
        ~Contact();
        bool isEmpty() const;
        void display() const;

    };
}
#endif
