#include <QCoreApplication>
#include "sequence.h"
#include <iostream>
#include <vector>
using namespace std;
void print(const vector<int>& x);

int main(int argc, char *argv[])
{
    QCoreApplication astart(argc, argv);
    return astart.exec();

    vector<int> b3;
   b3.push_back(5);
    b3.push_back(12);
    print(b3);


    Sequence<int, string>::Iterator iseqtr;
    Sequence<int, string>::Iterator jseqtr = iseqtr;
    Sequence<int, string>::Iterator kseqtr;
    kseqtr = iseqtr;

    Sequence<int, string> a;
    Sequence<int, string> b;
    //Sequence<int, string>::Iterator i2seqtr(a);
    //iseqtr.associeteWith(b);

    //iseqtr uses elements of a
    *iseqtr = string("testing");
    string a = iseqtr.getKey();
    iseqtr.getKey() = string ("newKey");
    iseqtr = a.begin();
    iseqtr = b.begin();

    return 0;

}
void print(const vector<int>& x){
    for (vector<int>::const_iterator i = x.begin();i!=x.end() ;i++ ) {
        cout <<*i<<", ";
        cout<<endl;
    }
}
