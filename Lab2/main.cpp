#include <QCoreApplication>
#include "ring.cpp"
#include <iostream>
#include <vector>
using namespace std;
void testAll();
void testMerge();
void testInserBeforeAndAfter();
void testDelete();
void testConstructors();
template <typename Key, typename Info>
Ring <Key, Info> merge_pos (const Ring <Key, Info>& ring1, int start_pos1, bool direct1, int len1,const Ring <Key, Info>& ring2, int start_pos2, bool direct2, int len2,int count);
template <typename Key, typename Info>
Ring <Key, Info> merge_key (const Ring <Key, Info>& ring1, const Key& start_key1, int occ1, bool direct1, int len1,const Ring <Key, Info>& ring2, const Key& start_key2, int occ2, bool direct2, int len2,int count);
template <typename Key, typename Info>
bool AssertEquals(const Ring<Key,Info> &test,string wantedOutput);

int main(int argc, char *argv[])
{

    testAll();
    return 0;

}
template <typename Key, typename Info>
Ring <Key, Info> merge_pos (const Ring <Key, Info>& ring1, int start_pos1, bool direct1, int len1,const Ring <Key, Info>& ring2, int start_pos2, bool direct2, int len2,int count){

    Ring<Key, Info> temp;

    typename Ring<Key, Info>::const_Iterator it1;
    typename Ring<Key, Info>::const_Iterator it2;

    if (direct1) {
        it1=ring1.beginConst(true);
    }else{
        it1=ring1.endConst(true);
    }

    if (direct2) {
        it2=ring2.beginConst(true);
    }else{
        it2=ring2.endConst(true);
    }

    int originalStartpos1 = start_pos1;
    int originalStartpos2 = start_pos2;

    int size1 = ring1.size();
    int size2 = ring2.size();

    if (start_pos1>=size1 && start_pos1 >0 && size1>0) {

        start_pos1= start_pos1%size1;
    }
    if (start_pos2>=size2&& start_pos2 >0 && size2>0) {

        start_pos2= start_pos2%size2;
    }



    if (count > 0 )
    {

        while (start_pos1 != 0 && !(it1.isEmpty()) && originalStartpos1>=0 && len1 >0)
        {
            start_pos1--;
            direct1 ? it1++ : it1--; //if direct is false, then the iterator go in the negative direction, from tail to head

        }
        while (start_pos2 != 0 && !(it2.isEmpty())&& originalStartpos2>=0 && len2 >0)
        {

            direct2 ? it2++ : it2--; //if direct is false, then the iterator go in the negative direction, from tail to head
            start_pos2--;
        }

        while (count != 0)
        {
            int lenght1 = len1;
            int length2 = len2;
            while (lenght1 != 0 && !(it1.isEmpty())&& originalStartpos1>=0 && len1 >0)
            {
                temp.insertAtEnd(it1.getKey(), it1.getInfo(),true);

                direct1 ? it1++ : it1--;  //if direct is false, then the iterator go in the negative direction, from tail to head
                lenght1--;
            }

            while (length2 != 0 && !(it2.isEmpty())&& originalStartpos2>=0 && len2 >0)
            {
                temp.insertAtEnd(it2.getKey(), it2.getInfo(),true);
                direct2 ? it2++ : it2--; //if direct is false, then the iterator go in the negative direction, from tail to head
                length2--;
            }

            count--;
        }
    }



    return temp;
}


template <typename Key, typename Info>
Ring <Key, Info> merge_key (const Ring <Key, Info>& ring1, const Key& start_key1, int occ1, bool direct1, int len1,const Ring <Key, Info>& ring2, const Key& start_key2, int occ2, bool direct2, int len2,int count){

    Ring<Key, Info> temp;
    typename Ring<Key, Info>::const_Iterator it1;
    typename Ring<Key, Info>::const_Iterator it2;

    if (direct1) {
        it1=ring1.beginConst(true);
    }else{
        it1=ring1.endConst(true);
    }

    if (direct2) {
        it2=ring2.beginConst(true);
    }else{
        it2=ring2.endConst(true);
    }

    int originalOcc1 = occ1;
    int originalOcc2 = occ2;

    int ocuranceInRing1= ring1.search(start_key1);
    int ocuranceInRing2= ring2.search(start_key2);

    if (occ1>ocuranceInRing1 && occ1 >0 && ocuranceInRing1>0) {
        occ1= occ1%ocuranceInRing1;
        if (occ1==0) {
            occ1=ocuranceInRing1;
        }
    }
    if (occ2>ocuranceInRing2 && occ2 >0 && ocuranceInRing2>0) {
        occ2= occ2%ocuranceInRing2;
        if (occ2==0) {
            occ2=ocuranceInRing2;
        }
    }

    if (count > 0  )
    {
        while (occ1 != 0  && !(it1.isEmpty()) && originalOcc1>0 && len1 >0 && ocuranceInRing1>0)
        {

            if (it1.getKey() == start_key1)
            {
                occ1--;
            }
            if (occ1 != 0)
            {
                direct1 ? it1++ : it1--;
            }

        }
        while (occ2 != 0 && !(it2.isEmpty()) && originalOcc2>0 && len2 >0 && ocuranceInRing2>0)
        {
            if (it2.getKey() == start_key2)
            {
                occ2--;
            }
            if (occ2 != 0)
            {
                direct2 ? it2++ : it2--;
            }
        }


        while (count != 0)
        {

            int lenght1 = len1;
            int length2 = len2;
            while (lenght1 != 0 && !(it1.isEmpty()) && originalOcc1>0 && len1 >0 && ocuranceInRing1>0)
            {

                temp.insertAtEnd(it1.getKey(), it1.getInfo(),true);
                direct1 ? it1++ : it1--;
                lenght1--;
            }

            while (length2 != 0 && !(it2.isEmpty()) && originalOcc2>0 && len2 >0 && ocuranceInRing2>0)
            {

                temp.insertAtEnd(it2.getKey(), it2.getInfo(),true);
                direct2 ? it2++ : it2--;
                length2--;
            }

            count--;
        }
    }

    return temp;

}


void testInserBeforeAndAfter(){
    Ring<int, int> test1;
    test1.insertAtBeg(1,1,true);
    test1.insertAtBeg(2,2,true);
    test1.insertAtBeg(3,3,true);
    cout << "Test 1.1: " << (AssertEquals(test1,"[3,3][2,2][1,1]") == 1 ? "true" : "false") << endl;
    test1.print2(true);



    Ring<int, int> test2;
    test2.insertAtEnd(1,1,true);
    test2.insertAtEnd(2,2,true);
    test2.insertAtEnd(3,3,true);
    cout << "Test 1.2: " << (AssertEquals(test2,"[1,1][2,2][3,3]") == 1 ? "true" : "false") << endl;
    test2.print2(true);



    Ring<int, int> test3;
    test3.insertAtBeg(1,1,false);
    test3.insertAtBeg(2,2,false);
    test3.insertAtBeg(3,3,false);
    cout << "Test 1.3: " << (AssertEquals(test3,"[1,1][2,2][3,3]") == 1 ? "true" : "false") << endl;
    test3.print2(true);


    Ring<int, int> test4;
    test4.insertAtBeg(1,1,true);
    test4.insertAtBeg(2,2,true);
    test4.insertAtBeg(3,3,false);
    cout << "Test 1.4: " << (AssertEquals(test4,"[2,2][1,1][3,3]") == 1 ? "true" : "false") << endl;
    test4.print2(true);


    Ring<int, int> test5;
    test5.insertAtBeg(1,1,true);
    test5.insertAtBeg(2,2,true);
    test5.insertAtEnd(3,3,true);
    cout << "Test 1.5: " << (AssertEquals(test5,"[2,2][1,1][3,3]") == 1 ? "true" : "false") << endl;
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
    cout << "Test 1.6: " << (AssertEquals(test6,"[1,1][2,2][2,3][1,1][2,4][2,6][1,3][2,7][1,1][2,8][3,3]") == 1 ? "true" : "false") << endl;

    test6.insertAfter(2,14,2,3,true);

    test6.insertAfter(2,15,2,2,false);
    cout << "Test 1.7: " << (AssertEquals(test6,"[1,1][2,2][2,3][1,1][2,4][2,14][2,6][1,3][2,7][2,15][1,1][2,8][3,3]") == 1 ? "true" : "false") << endl;
    test6.print2(true);


    test6.insertAfter(2,17,2,2,true);
    test6.insertAfter(1,15,1,1,true);


    test6.insertAfter(3,15,3,1,false);


    cout << "Test 1.8: " << (AssertEquals(test6,"[1,1][1,15][2,2][2,3][2,17][1,1][2,4][2,14][2,6][1,3][2,7][2,15][1,1][2,8][3,3][3,15]") == 1 ? "true" : "false") << endl;
    test6.print2(true);

    test6.insertBefore(6,77,1,1,true);
    test6.insertBefore(2,26,2,4,false);
    test6.insertBefore(1,25,1,5,false);

    cout << "Test 1.9: " << (AssertEquals(test6,"[6,77][1,25][1,1][1,15][2,2][2,3][2,17][1,1][2,4][2,14][2,26][2,6][1,3][2,7][2,15][1,1][2,8][3,3][3,15]") == 1 ? "true" : "false") << endl;
    test6.print2(true);

    test6.insertAfter(7,77,1,21,false);

    cout << "Test 1.10: " << (AssertEquals(test6,"[6,77][1,25][1,1][1,15][2,2][2,3][2,17][1,1][7,77][2,4][2,14][2,26][2,6][1,3][2,7][2,15][1,1][2,8][3,3][3,15]") == 1 ? "true" : "false") << endl;
    test6.print2(true);


    cout<< "--------INSERT AFTER---------" << endl;

    Ring<int, int> test1InsertAfter;

    cout << "Test 4.1: " << (test1InsertAfter.insertAfter(8, 9, 2, 1,true) == false ? "true" : "false") << endl;
    test1InsertAfter.insertAtBeg(2, 5,true);
    test1InsertAfter.insertAtBeg(6, 7,true);
    test1InsertAfter.insertAfter(8, 9, 2, 1,true);
    test1InsertAfter.insertAfter(8, 10, 6, 1,true);
    test1InsertAfter.insertAfter(1, 1, 8, 2,true);

    cout << "Test 4.2: " << (AssertEquals(test1InsertAfter,"[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
    test1InsertAfter.print2(true);

    test1InsertAfter.insertAfter(1, 1, 8, 5,true);
    cout << "Test 4.3: " << (AssertEquals(test1InsertAfter,"[6,7][8,10][1,1][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
    test1InsertAfter.print2(true);

    test1InsertAfter.insertAfter(1, 1, 11, 5,true);
    cout << "Test 4.4: " << (AssertEquals(test1InsertAfter,"[6,7][8,10][1,1][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
    test1InsertAfter.print2(true);

    cout << endl
         << "--------INSERT BEFORE---------" << endl;

    Ring<int, int> test1InsertBefore;

    cout << "Test 5.1: " << (test1InsertBefore.insertBefore(8, 9, 2, 1,true) == false ? "true" : "false") << endl;
    test1InsertBefore.insertAtBeg(2, 5,true);
    test1InsertBefore.insertAtBeg(6, 7,true);
    test1InsertBefore.insertBefore(8, 9, 2, 1,true);
    test1InsertBefore.insertBefore(8, 10, 6, 1,true);
    test1InsertBefore.insertBefore(1, 1, 8, 2,true);

    cout << "Test 5.2: " << (AssertEquals(test1InsertBefore,"[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBefore.print2(true);

    test1InsertBefore.insertBefore(1, 1, 8, 5,true);
    cout << "Test 5.3: " << (AssertEquals(test1InsertBefore,"[1,1][8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBefore.print2(true);

    test1InsertBefore.insertBefore(1, 1, 11, 5,true);
    cout << "Test 5.4: " << (AssertEquals(test1InsertBefore,"[1,1][8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBefore.print2(true);

    cout << endl;
}
void testMerge(){
    Ring<int, int> test1MergePos;
    Ring<int, int> test1MergePos2;


    test1MergePos.insertAtEnd(0, 0,true);
    test1MergePos.insertAtEnd(1, 1,true);
    test1MergePos.insertAtEnd(2, 2,true);
    test1MergePos.insertAtEnd(3, 3,true);
    test1MergePos.insertAtEnd(4, 4,true);
    test1MergePos.insertAtEnd(5, 5,true);
    test1MergePos.insertAtEnd(6, 6,true);
    test1MergePos.insertAtEnd(7, 7,true);
    test1MergePos.insertAtEnd(8, 8,true);
    test1MergePos.insertAtEnd(9, 9,true);

    test1MergePos2.insertAtEnd(0, 0,true);
    test1MergePos2.insertAtEnd(1, 10,true);
    test1MergePos2.insertAtEnd(2, 20,true);
    test1MergePos2.insertAtEnd(3, 30,true);
    test1MergePos2.insertAtEnd(4, 40,true);
    test1MergePos2.insertAtEnd(5, 50,true);
    test1MergePos2.insertAtEnd(6, 60,true);
    test1MergePos2.insertAtEnd(7, 70,true);
    test1MergePos2.insertAtEnd(8, 80,true);
    test1MergePos2.insertAtEnd(9, 90,true);


    Ring<int, int> test1MergePosOut = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,true, 2, 4);
    cout << "Test 6.2: " << (AssertEquals(test1MergePosOut,"[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergePosOut.print2(true);

    Ring<int, int> test1MergePosOut2 = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,true, 2, 0);
    cout << "Test 6.3(0count): " << (AssertEquals(test1MergePosOut2,"[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut2.print2(true);

    Ring<int, int> test1MergePosOut3 = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,true, 2, 5);
    cout << "Test 6.4(bigcount): " << (AssertEquals(test1MergePosOut3,"[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90][7,7][0,0][1,10]") == 1 ? "true" : "false") << endl;
    test1MergePosOut3.print2(true);

    Ring<int, int> test1MergePosOut4 = merge_pos(test1MergePos, 3,true, 0, test1MergePos2, 2,true, 0, 8);
    cout << "Test 6.5(0length): " << (AssertEquals(test1MergePosOut4,"[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut4.print2(true);

    Ring<int, int> test1MergePosOut5 = merge_pos(test1MergePos, 20,true, 1, test1MergePos2, 20,true, 2, 5);
    cout << "Test 6.6(bigstartpos): " << (AssertEquals(test1MergePosOut5,"[0,0][0,0][1,10][1,1][2,20][3,30][2,2][4,40][5,50][3,3][6,60][7,70][4,4][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergePosOut5.print2(true);

    Ring<int, int> test1MergePosOut6 = merge_pos(test1MergePos, 0,true, 1, test1MergePos2, 0,true, 2, 10);
    cout << "Test 6.7:(0startpos) " << (AssertEquals(test1MergePosOut6,"[0,0][0,0][1,10][1,1][2,20][3,30][2,2][4,40][5,50][3,3][6,60][7,70][4,4][8,80][9,90][5,5][0,0][1,10][6,6][2,20][3,30][7,7][4,40][5,50][8,8][6,60][7,70][9,9][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergePosOut6.print2(true);


    Ring<int, int> test1Mergetest;
    Ring<int, int> test1Mergetest2;


    Ring<int, int> test1MergePosOut7 = merge_pos(test1Mergetest, 0,true, 1, test1Mergetest2, 0,true, 2, 10);
    cout << "Test 6.8:(nullRings) " << (AssertEquals(test1MergePosOut7,"[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut7.print2(true);

    Ring<int, int> test1MergePosOut8 = merge_pos(test1Mergetest, -5,true, -4, test1Mergetest2, -5,true, -2, -10);
    cout << "Test 6.9:(negatives) " << (AssertEquals(test1MergePosOut8,"[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut8.print2(true);

    Ring<int, int> test1MergePosOut9 = merge_pos(test1MergePos, 4,true, 1, test1MergePos2, -1,true, -2, 3);
    cout << "Test 6.10(onenegative):  " << (AssertEquals(test1MergePosOut9,"[4,4][5,5][6,6]") == 1 ? "true" : "false") << endl;
    test1MergePosOut9.print2(true);

    Ring<int, int> test1MergePosOut11 = merge_pos(test1MergePos, 23,true, 1, test1MergePos2, 22,true, 2, 4);
    cout << "Test 6.11(bigstartpos): " << (AssertEquals(test1MergePosOut11,"[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergePosOut11.print2(true);

    Ring<int, int> test1;
    Ring<int, int> test2;
    test1.insertAtEnd(1,1,true);
    test1.insertAtEnd(2,2,true);
    test1.insertAtEnd(3,3,true);
    test1.insertAtEnd(4,4,true);
    test1.insertAtEnd(5,5,true);

    test2.insertAtEnd(10,10,true);
    test2.insertAtEnd(20,20,true);
    test2.insertAtEnd(30,30,true);
    test2.insertAtEnd(40,40,true);

    Ring<int, int> test1MergePosOut12 = merge_pos(test1, 1,true, 2, test2, 2,true, 1, 4);
    cout << "Test 6.12(examplegiven): " << (AssertEquals(test1MergePosOut12,"[2,2][3,3][30,30][4,4][5,5][40,40][1,1][2,2][10,10][3,3][4,4][20,20]") == 1 ? "true" : "false") << endl;
    test1MergePosOut12.print2(true);


    //FALSE DIRECTION

    Ring<int, int> test1MergePosOut13 = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,false, 2, 4);
    cout << "Test 6.13(one false direction): " << (AssertEquals(test1MergePosOut13,"[3,3][7,70][6,60][4,4][5,50][4,40][5,5][3,30][2,20][6,6][1,10][0,0]") == 1 ? "true" : "false") << endl;
    test1MergePosOut13.print2(true);

    Ring<int, int> test1MergePosOut14 = merge_pos(test1MergePos, 3,false, 1, test1MergePos2, 2,true, 2, 4);
    cout << "Test 6.14(one false direction2): " << (AssertEquals(test1MergePosOut14,"[6,6][2,20][3,30][5,5][4,40][5,50][4,4][6,60][7,70][3,3][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergePosOut14.print2(true);

    Ring<int, int> test1MergePosOut15 = merge_pos(test1MergePos, 3,false, 1, test1MergePos2, 2,false, 2, 6);
    cout << "Test 6.15(two false direction): " << (AssertEquals(test1MergePosOut15,"[6,6][7,70][6,60][5,5][5,50][4,40][4,4][3,30][2,20][3,3][1,10][0,0][2,2][9,90][8,80][1,1][7,70][6,60]") == 1 ? "true" : "false") << endl;
    test1MergePosOut15.print2(true);


    test1MergePos.insertAtEnd(3, 50,true);


    Ring<int, int> test1MergeKeyOut2 = merge_key(test1MergePos, 3, 2,true, 1, test1MergePos2, 4, 1,true, 2, 2);
    cout << "Test 7.1: " << (AssertEquals(test1MergeKeyOut2,"[3,50][4,40][5,50][0,0][6,60][7,70]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut2.print2(true);

    Ring<int, int> test1MergeKeyOut3 = merge_key(test1MergePos, 3, 2,true, 10, test1MergePos2, 4, 1,true, 10, 2);
    cout << "Test 7.2(biggerLength):  " << (AssertEquals(test1MergeKeyOut3,"[3,50][0,0][1,1][2,2][3,3][4,4][5,5][6,6][7,7][8,8][4,40][5,50][6,60][7,70][8,80][9,90][0,0][1,10][2,20][3,30][9,9][3,50][0,0][1,1][2,2][3,3][4,4][5,5][6,6][7,7][4,40][5,50][6,60][7,70][8,80][9,90][0,0][1,10][2,20][3,30]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut3.print2(true);

    Ring<int, int> test1MergeKeyOut4 = merge_key(test1MergePos, 3, 2,true, 0, test1MergePos2, 4, 1,true, 0, 2);
    cout << "Test 7.3(0length):  " << (AssertEquals(test1MergeKeyOut4,"[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut4.print2(true);

    Ring<int, int> test1MergeKeyOut5 = merge_key(test1MergePos, 3, 2,true, 1, test1MergePos2, 4, 1,true, 2, 0);
    cout << "Test 7.4(0count):  " << (AssertEquals(test1MergeKeyOut5,"[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut5.print2(true);

    Ring<int, int> test1MergeKeyOut6 = merge_key(test1MergePos, 3, 2,true, 1, test1MergePos2, 4, 1,true, 2, 1);
    cout << "Test 7.5(1count):  " << (AssertEquals(test1MergeKeyOut6,"[3,50][4,40][5,50]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut6.print2(true);

    Ring<int, int> test1MergeKeyOut7 = merge_key(test1MergePos, 3, 0,true, 1, test1MergePos2, 4, 0,true, 2, 1);
    cout << "Test 7.6(0ocurrancekey):  " << (AssertEquals(test1MergeKeyOut7,"[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut7.print2(true);

    Ring<int, int> test1MergeKeyOut8 = merge_key(test1MergePos, 3, 24,true, 1, test1MergePos2, 4, 21,true, 2, 2);
    cout << "Test 7.7(bigocurrancekey):  " << (AssertEquals(test1MergeKeyOut8,"[3,50][4,40][5,50][0,0][6,60][7,70]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut8.print2(true);

    Ring<int, int> test1MergeKeyOut9 = merge_key(test1MergePos, 55, 2,true, 1, test1MergePos2, 55, 1,true, 2, 1);
    cout << "Test 7.8(noexistkey):  " << (AssertEquals(test1MergeKeyOut9,"[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut9.print2(true);

    Ring<int, int> test1MergeKeytest;
    Ring<int, int> test1MergeKeytest2;

    Ring<int, int> test1MergeKeyOut10 = merge_key(test1Mergetest, 3, 2,true, 1, test1Mergetest2, 4, 2,true, 2, 1);
    cout << "Test 7.9:(nullRings) " << (AssertEquals(test1MergeKeyOut10,"[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut10.print2(true);

    Ring<int, int> test1MergeKeyOut11 = merge_key(test1MergePos, 2, -2,true, -1, test1MergePos2, 2, -1,true, -2, -1);
    cout << "Test 7.10(negativevalues):  " << (AssertEquals(test1MergeKeyOut11,"[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut11.print2(true);

    Ring<int, int> test1MergeKeyOut12 = merge_key(test1MergePos, 4, 1,true, 1, test1MergePos2, 2, -1,true, -2, 3);
    cout << "Test 7.11(onenegative):  " << (AssertEquals(test1MergeKeyOut12,"[4,4][5,5][6,6]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut12.print2(true);

}
void testDelete(){

    Ring<int, int> test1Delete;

    cout << "Test 3.1: " << (test1Delete.remove(2, 5,true) == false ? "true" : "false") << endl;
    test1Delete.insertAtBeg(2, 5,true);

    test1Delete.remove(2, 1,true);

    cout << "Test 3.2: " << (AssertEquals(test1Delete,"[]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);

    test1Delete.insertAtBeg(2, 5,true);
    test1Delete.insertAtBeg(6, 7,true);
    test1Delete.insertAtBeg(7, 9,true);
    test1Delete.insertAtBeg(7, 45,true);
    test1Delete.insertAtBeg(7, 10,true);
    test1Delete.insertAtBeg(1, 2,true);
    test1Delete.print2(true);

    test1Delete.remove(1, 1,true);

    cout << "Test 3.3: " << (AssertEquals(test1Delete,"[7,10][7,45][7,9][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);



    test1Delete.remove(2, 1,true);

    cout << "Test 3.4: " << (AssertEquals(test1Delete,"[7,10][7,45][7,9][6,7]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);

    test1Delete.remove(7, 5,true);

    cout << "Test 3.5: " << (AssertEquals(test1Delete,"[7,10][7,9][6,7]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);

    test1Delete.remove(3, 2,true);
    cout << "Test 3.7: " << (AssertEquals(test1Delete,"[7,10][7,9][6,7]") == 1 ? "true" : "false") << endl;


    test1Delete.remove(7, 0,true);
    cout << "Test 3.9: " << (AssertEquals(test1Delete,"[7,10][7,9][6,7]") == 1 ? "true" : "false") << endl;

    test1Delete.remove(7, 1,true);
    cout << "Test 3.10: " << (AssertEquals(test1Delete,"[7,9][6,7]") == 1 ? "true" : "false") << endl;

    test1Delete.remove(7, 1,true);
    cout << "Test 3.11: " << (AssertEquals(test1Delete,"[6,7]") == 1 ? "true" : "false") << endl;

    test1Delete.remove(6, 1,true);

    cout << "Test 3.12: " << (AssertEquals(test1Delete,"[]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);




    test1Delete.insertAtBeg(2, 5,true);
    test1Delete.insertAtBeg(6, 7,true);
    test1Delete.insertAtBeg(7, 9,true);
    test1Delete.insertAtBeg(7, 45,true);
    test1Delete.insertAtBeg(7, 10,true);
    test1Delete.insertAtBeg(1, 2,true);
    test1Delete.print2(true);

    test1Delete.remove(2, 1,false);

    cout << "Test 3.13: " << (AssertEquals(test1Delete,"[1,2][7,10][7,45][7,9][6,7]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);

    test1Delete.remove(1, 1,false);

    cout << "Test 3.14: " << (AssertEquals(test1Delete,"[7,10][7,45][7,9][6,7]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);

    test1Delete.remove(7, 4,false);

    cout << "Test 3.15: " << (AssertEquals(test1Delete,"[7,10][7,45][6,7]") == 1 ? "true" : "false") << endl;
    test1Delete.print2(true);

    test1Delete.remove(3, 2,false);
    cout << "Test 3.16: " << (AssertEquals(test1Delete,"[7,10][7,45][6,7]") == 1 ? "true" : "false") << endl;


    test1Delete.remove(7, 0,false);
    cout << "Test 3.17: " << (AssertEquals(test1Delete,"[7,10][7,45][6,7]") == 1 ? "true" : "false") << endl;

    test1Delete.remove(7, 1,false);
    cout << "Test 3.18: " << (AssertEquals(test1Delete,"[7,10][6,7]") == 1 ? "true" : "false") << endl;

    test1Delete.remove(7, 1,false);
    cout << "Test 3.19: " << (AssertEquals(test1Delete,"[6,7]") == 1 ? "true" : "false") << endl;



    cout << endl;
}
void testConstructors(){
    cout << endl
         << "--------Constructors---------" << endl;
    Ring<int, int> test1Constructors;
    test1Constructors.insertAtBeg(2, 5,true);
    test1Constructors.insertAtBeg(6, 7,true);

    Ring<int, int> test2Constructors = test1Constructors;

    test1Constructors.insertAtBeg(1, 1,true);
    test2Constructors.insertAtBeg(3, 3,true);
    cout << "Test 0.1: " << (AssertEquals(test2Constructors,"[3,3][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test2Constructors.print2(true);



    Ring<int, int> test4Constructors;
    Ring<int, int> test5Constructors = test4Constructors;//call to copy constructor
    cout << "Test 0.2(empty copyconstructor): " << (AssertEquals(test5Constructors,"[]") == 1 ? "true" : "false") << endl;

    Ring<int, int> test6Constructors;
    test6Constructors.insertAtBeg(2, 5,true);
    test6Constructors.insertAtBeg(6, 7,true);
    Ring<int, int> test3Constructors;
    test3Constructors.insertAtEnd(3,6,true);
    test3Constructors= test6Constructors;// calls to assignment constructor
    cout << "Test 0.3: " << (AssertEquals(test3Constructors,"[6,7][2,5]") == 1 ? "true" : "false") << endl;
    test3Constructors.print2(true);


    Ring<int, int> test7Constructors;
    test7Constructors+= test3Constructors;
    cout << "Test 0.4(+=operator, empty first List): " << (AssertEquals(test7Constructors,"[6,7][2,5]") == 1 ? "true" : "false") << endl;
    test7Constructors.print2(true);


    test7Constructors+=test3Constructors;
    cout << "Test 0.5(+=operator): " << (AssertEquals(test7Constructors,"[6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test7Constructors.print2(true);

    Ring<int, int> test8Constructors;
    test7Constructors+= test8Constructors;
    cout << "Test 0.6(+=operator, empty second List): " << (AssertEquals(test7Constructors,"[6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test7Constructors.print2(true);

    Ring<int, int> test9Constructors;
    test9Constructors=test7Constructors + test8Constructors;
    cout << "Test 0.7(+operator, empty second List): " << (AssertEquals(test9Constructors,"[6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test9Constructors.print2(true);
    Ring<int, int> test10Constructors;
    test10Constructors = test7Constructors + test9Constructors;
    cout << "Test 0.8(+operator): " << (AssertEquals(test10Constructors,"[6,7][2,5][6,7][2,5][6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test10Constructors.print2(true);



    Ring<int, int> test11Constructors;
    Ring<int, int> test12Constructors;

    test11Constructors-= test12Constructors;
    cout << "Test 0.9(-=operator, empty first List): " << (AssertEquals(test12Constructors,"[]") == 1 ? "true" : "false") << endl;
    test12Constructors.print2(true);


    test11Constructors.insertAtBeg(1,1,true);
    test11Constructors.insertAtBeg(2,2,true);
    test11Constructors-= test12Constructors;
    cout << "Test 0.10(-=operator, empty second List): " << (AssertEquals(test11Constructors,"[2,2][1,1]") == 1 ? "true" : "false") << endl;
    test11Constructors.print2(true);


    test12Constructors.insertAtBeg(1,1,true);
    test11Constructors-= test12Constructors;
    cout << "Test 0.11(-=operator): " << (AssertEquals(test11Constructors,"[2,2]") == 1 ? "true" : "false") << endl;
    test11Constructors.print2(true);


    Ring<int, int> test13Constructors;
    Ring<int, int> test14Constructors;
    Ring<int, int> test15Constructors;
    test15Constructors.insertAtEnd(5,5,true);
    test13Constructors=test14Constructors - test15Constructors;
    cout << "Test 0.12(-operator, empty first List): " << (AssertEquals(test13Constructors,"[]") == 1 ? "true" : "false") << endl;
    test13Constructors.print2(true);


    test13Constructors=test15Constructors - test14Constructors;
    cout << "Test 0.13(-operator, empty second List): " << (AssertEquals(test13Constructors,"[5,5]") == 1 ? "true" : "false") << endl;
    test13Constructors.print2(true);


    test14Constructors.insertAtEnd(0,0,true);
    test14Constructors.insertAtEnd(1,1,true);
    test14Constructors.insertAtEnd(2,5,true);
    test14Constructors.insertAtEnd(3,5,true);
    test14Constructors.insertAtEnd(3,3,true);
    test14Constructors.insertAtEnd(4,5,true);

    test15Constructors.insertAtEnd(3,0,true);
    test15Constructors.insertAtEnd(0,5,true);
    test15Constructors.insertAtEnd(6,5,true);
    test15Constructors.insertAtEnd(0,5,true);
    test13Constructors=test14Constructors - test15Constructors;
    cout << "Test 0.14(-operator): " << (AssertEquals(test13Constructors,"[1,1][2,5][3,3][4,5]") == 1 ? "true" : "false") << endl;
    test13Constructors.print2(true);

}
void testAll(){

    testMerge();
    testInserBeforeAndAfter();
    testDelete();
    testConstructors();


}


template <typename Key, typename Info>
bool AssertEquals(const Ring<Key,Info>& test,string wantedOutput)
{
    string thisOuput;
    typename Ring<Key, Info>::const_Iterator it;

    it=test.beginConst(true);

    if (it == nullptr)
    {
        thisOuput = "[]";
    }
    else
    {
        stringstream thisOuputSS;
        int size= test.size();
        for (int i =0;i<size ; i++ ) {
            thisOuputSS << "[" << it.getKey() << "," << it.getInfo() << "]";

            it++;
        }



        thisOuputSS >> thisOuput;
    }

    return thisOuput == wantedOutput;
}

