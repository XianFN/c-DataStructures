#include "Sequence.cpp"

int main(int argc, char *argv[])
{
    cout << "--------INSERT AT BEG---------" << endl;
    Sequence<int, int> test1InsertBeg;
    test1InsertBeg.insertAtBeg(2, 5);
    test1InsertBeg.insertAtBeg(6, 7);
    test1InsertBeg.insertAtBeg(7, 9);
    test1InsertBeg.insertAtBeg(1, 2);

    cout << "Test 1: " << (test1InsertBeg.AssertEquals("[1,2][7,9][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBeg.prinf();









    cout << "--------INSERT AT END---------" << endl;
    Sequence<int, int> test1InsertAtEnd;
    test1InsertAtEnd.insertAtEnd(2, 5);
    test1InsertAtEnd.insertAtEnd(6, 7);
    test1InsertAtEnd.insertAtEnd(7, 9);
    test1InsertAtEnd.insertAtEnd(1, 2);

    cout << "Test 2: " << (test1InsertAtEnd.AssertEquals("[2,5][6,7][7,9][1,2]") == 1 ? "true" : "false") << endl;
    test1InsertAtEnd.prinf();









    cout << "--------DELETE AND SEARCH---------" << endl;

    Sequence<int, int> test1Delete;

    cout << "Test 3.1: " << (test1Delete.deleteElement(2, 5) == false ? "true" : "false") << endl;

    test1Delete.insertAtBeg(2, 5);
    test1Delete.insertAtBeg(6, 7);
    test1Delete.insertAtBeg(7, 9);
    test1Delete.insertAtBeg(7, 45);
    test1Delete.insertAtBeg(7, 10);
    test1Delete.insertAtBeg(1, 2);
    test1Delete.deleteElement(7, 1);

    cout << "Test 3.2: " << (test1Delete.AssertEquals("[1,2][7,45][7,9][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test1Delete.prinf();

    test1Delete.deleteElement(7, 2);
    cout << "Test 3.3: " << (test1Delete.AssertEquals("[1,2][7,45][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test1Delete.prinf();

    test1Delete.deleteElement(3, 2);
    cout << "Test 3.4: " << (test1Delete.AssertEquals("[1,2][7,45][6,7][2,5]") == 1 ? "true" : "false") << endl;


    test1Delete.deleteElement(7, 2);
    cout << "Test 3.5: " << (test1Delete.AssertEquals("[1,2][7,45][6,7][2,5]") == 1 ? "true" : "false") << endl;
    
    test1Delete.deleteElement(7, 0);
    cout << "Test 3.6: " << (test1Delete.AssertEquals("[1,2][7,45][6,7][2,5]") == 1 ? "true" : "false") << endl;




    cout << "--------INSERT AFTER---------" << endl;
    
    Sequence<int, int> test1InsertAfter;
    
     cout << "Test 4.1: " << (test1InsertAfter.insertAfter(8, 9,2,1) == false ? "true" : "false") << endl;
    test1InsertAfter.insertAtBeg(2, 5);
    test1InsertAfter.insertAtBeg(6, 7);
    test1InsertAfter.insertAfter(8, 9,2,1);
    test1InsertAfter.insertAfter(8, 10,6,1);
    test1InsertAfter.insertAfter(1, 1,8,2);


    cout << "Test 4.2: " << (test1InsertAfter.AssertEquals("[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
    test1InsertAfter.prinf();

    test1InsertAfter.insertAfter(1, 1,8,5);
    cout << "Test 4.2: " << (test1InsertAfter.AssertEquals("[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
   

    test1InsertAfter.insertAfter(1, 1,11,5);
    cout << "Test 4.2: " << (test1InsertAfter.AssertEquals("[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
    




    cout << "--------INSERT BEFORE---------" << endl;
    
    Sequence<int, int> test1InsertBefore;
    
     cout << "Test 5.1: " << (test1InsertBefore.insertBefore(8, 9,2,1) == false ? "true" : "false") << endl;
    test1InsertBefore.insertAtBeg(2, 5);
    test1InsertBefore.insertAtBeg(6, 7);
    test1InsertBefore.insertBefore(8, 9,2,1);
    test1InsertBefore.insertBefore(8, 10,6,1);
    test1InsertBefore.insertBefore(1, 1,8,2);


    cout << "Test 5.2: " << (test1InsertBefore.AssertEquals("[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBefore.prinf();

    test1InsertBefore.insertBefore(1, 1,8,5);
    cout << "Test 5.2: " << (test1InsertBefore.AssertEquals("[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
   

    test1InsertBefore.insertBefore(1, 1,11,5);
    cout << "Test 5.2: " << (test1InsertBefore.AssertEquals("[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
    



 
}