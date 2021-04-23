#include <QCoreApplication>
#include "ring.cpp"
#include <iostream>
#include <vector>
using namespace std;
void print(const vector<int>& x);
void testAll();

int main(int argc, char *argv[])
{

    /*
    vector<int> d;
   d.push_back(5);
    d.push_back(12);
    print(d);


    Ring<string, string>::Iterator iseqtr;
    Ring<string, string>::Iterator jseqtr = iseqtr;
    Ring<string, string>::Iterator kseqtr;
    kseqtr = iseqtr;

    Ring<string, string> a;
    Ring<string, string> b;
    Sequence<int, string>::Iterator i2seqtr(a);
    //iseqtr.associeteWith(d);

    //iseqtr uses elements of a
    *iseqtr = string("testing");
    string c = iseqtr.getKey();
    iseqtr.getKey() = string ("newKey");
     iseqtr = c.begin();
    iseqtr = b.begin();

    */
    Ring<int, int> a;
    a.insertAtBeg(1,1,true);
    a.insertAtEnd(2,2,true);

    Ring<int, int>::Iterator it1;
    it1=a.begin();
    cout <<it1.getKey()<<endl;
    it1++;
    cout <<it1.getKey()<<endl;

  //  testAll();
    return 0;

}
void print(const vector<int>& x){
    for (vector<int>::const_iterator i = x.begin();i!=x.end() ;i++ ) {
        cout <<*i<<", ";
        cout<<endl;
    }
}
void testAll(){


    Ring<int, int> test1;
    test1.insertAtBeg(1,1,true);
    test1.insertAtBeg(2,2,true);
    test1.insertAtBeg(3,3,true);
    test1.print2(true);


    Ring<int, int> test2;
    test2.insertAtEnd(1,1,true);
    test2.insertAtEnd(2,2,true);
    test2.insertAtEnd(3,3,true);
    test2.print2(true);



    Ring<int, int> test3;
    test3.insertAtBeg(1,1,false);
    test3.insertAtBeg(2,2,false);
    test3.insertAtBeg(3,3,false);
    test3.print2(true);


    Ring<int, int> test4;
    test4.insertAtBeg(1,1,true);
    test4.insertAtBeg(2,2,true);
    test4.insertAtBeg(3,3,false);
    test4.print2(true);

    Ring<int, int> test5;
    test5.insertAtBeg(1,1,true);
    test5.insertAtBeg(2,2,true);
    test5.insertAtEnd(3,3,true);
    test5.print2(true);

    Ring<int, int> test6;
    test6.insertAtEnd(1,1,true);
    test6.insertAtEnd(2,2,true);
    test6.insertAtEnd(2,3,true);
    test6.insertAtEnd(1,1,true);
    test6.insertAtEnd(2,4,true);

    test6.insertAtEnd(2,6,true);
    test6.insertAtEnd(1,3,true);
    test6.insertAtEnd(2,7,true);
    test6.insertAtEnd(1,1,true);
    test6.insertAtEnd(2,8,true);
    test6.insertAtEnd(3,3,true);
    test6.insertAfter(2,14,2,3,true);
     test6.print2(true);
    test6.insertAfter(2,15,2,2,false);
    test6.print2(true);

    test6.insertAfter(2,17,2,2,true);
    test6.print2(true);
    test6.insertAfter(1,15,1,1,true);
    test6.print2(true);

    test6.insertAfter(3,15,3,1,false);
    test6.print2(true);

    test6.insertBefore(2,25,2,4,true);
    test6.print2(true);

    test6.insertBefore(2,26,2,2,false);
    test6.print2(false);

    test6.insertBefore(1,25,1,5,false);
    test6.print2(true);






}
