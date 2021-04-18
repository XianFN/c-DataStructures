#include <QCoreApplication>
#include "Sequence.cpp"

template <typename Key, typename Info>
Sequence<Key, Info> merge_pos(Sequence<Key, Info> &seq1, int start_pos1, int len1, Sequence<Key, Info> &seq2, int start_pos2, int len2, int count);
template <typename Key, typename Info>
Sequence<Key, Info> merge_key(Sequence<Key, Info> &seq1, const Key &start_key1, int start_occ1, int len1, Sequence<Key, Info> &seq2, const Key &start_key2, int start_occ2, int len2, int count);
void testAll();

int main(int argc, char *argv[])
{
    testAll();
    exit(0);

}

void testAll()
{
    cout << endl
         << "--------Constructors---------" << endl;
    Sequence<int, int> test1Constructors;
    test1Constructors.insertAtBeg(2, 5);
    test1Constructors.insertAtBeg(6, 7);

    Sequence<int, int> test2Constructors = test1Constructors;

    test1Constructors.insertAtBeg(1, 1);
    test2Constructors.insertAtBeg(3, 3);
    cout << "Test 0.1: " << (test2Constructors.AssertEquals("[3,3][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test2Constructors.prinf();



    Sequence<int, int> test4Constructors;
    Sequence<int, int> test5Constructors = test4Constructors;//call to copy constructor
    cout << "Test 0.2(empty copyconstructor): " << (test5Constructors.AssertEquals("[]") == 1 ? "true" : "false") << endl;

    Sequence<int, int> test6Constructors;
    test6Constructors.insertAtBeg(2, 5);
    test6Constructors.insertAtBeg(6, 7);
    Sequence<int, int> test3Constructors;
    test3Constructors.insertAtEnd(3,6);
    test3Constructors= test6Constructors;// calls to assignment constructor
    cout << "Test 0.3: " << (test3Constructors.AssertEquals("[6,7][2,5]") == 1 ? "true" : "false") << endl;
    test3Constructors.prinf();


    Sequence<int, int> test7Constructors;
    test7Constructors+= test3Constructors;
    cout << "Test 0.4(+=operator, empty first List): " << (test7Constructors.AssertEquals("[6,7][2,5]") == 1 ? "true" : "false") << endl;
    test7Constructors.prinf();


    test7Constructors+=test3Constructors;
    cout << "Test 0.5(+=operator): " << (test7Constructors.AssertEquals("[6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test7Constructors.prinf();

    Sequence<int, int> test8Constructors;
    test7Constructors+= test8Constructors;
    cout << "Test 0.6(+=operator, empty second List): " << (test7Constructors.AssertEquals("[6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test7Constructors.prinf();

    Sequence<int, int> test9Constructors;
    test9Constructors=test7Constructors + test8Constructors;
    cout << "Test 0.7(+operator, empty second List): " << (test9Constructors.AssertEquals("[6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test9Constructors.prinf();

    Sequence<int, int> test10Constructors;
    test10Constructors = test7Constructors + test9Constructors;
    cout << "Test 0.8(+operator): " << (test10Constructors.AssertEquals("[6,7][2,5][6,7][2,5][6,7][2,5][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test10Constructors.prinf();



    Sequence<int, int> test11Constructors;
    Sequence<int, int> test12Constructors;


    test11Constructors-= test12Constructors;
    cout << "Test 0.9(-=operator, empty first List): " << (test12Constructors.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test12Constructors.prinf();


    test11Constructors.insertAtBeg(1,1);
    test11Constructors.insertAtBeg(2,2);
    test11Constructors-= test12Constructors;
    cout << "Test 0.10(-=operator, empty second List): " << (test11Constructors.AssertEquals("[2,2][1,1]") == 1 ? "true" : "false") << endl;
    test11Constructors.prinf();


    test12Constructors.insertAtBeg(1,1);
    test11Constructors-= test12Constructors;
    cout << "Test 0.11(-=operator): " << (test11Constructors.AssertEquals("[2,2]") == 1 ? "true" : "false") << endl;
    test11Constructors.prinf();


    Sequence<int, int> test13Constructors;
    Sequence<int, int> test14Constructors;
    Sequence<int, int> test15Constructors;
    test15Constructors.insertAtEnd(5,5);
    test13Constructors=test14Constructors - test15Constructors;
    cout << "Test 0.12(-operator, empty first List): " << (test13Constructors.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test13Constructors.prinf();


    test13Constructors=test15Constructors - test14Constructors;
    cout << "Test 0.13(-operator, empty second List): " << (test13Constructors.AssertEquals("[5,5]") == 1 ? "true" : "false") << endl;
    test13Constructors.prinf();


    test14Constructors.insertAtEnd(0,0);
    test14Constructors.insertAtEnd(1,1);
    test14Constructors.insertAtEnd(2,5);
    test14Constructors.insertAtEnd(3,5);
    test14Constructors.insertAtEnd(3,3);
    test14Constructors.insertAtEnd(4,5);

    test15Constructors.insertAtEnd(3,0);
    test15Constructors.insertAtEnd(0,5);
    test15Constructors.insertAtEnd(6,5);
    test15Constructors.insertAtEnd(0,5);
    test13Constructors=test14Constructors - test15Constructors;
    cout << "Test 0.14(-operator): " << (test13Constructors.AssertEquals("[1,1][2,5][3,3][4,5]") == 1 ? "true" : "false") << endl;
    test13Constructors.prinf();











    cout << endl
         << "--------INSERT AT BEG---------" << endl;
    Sequence<int, int> test1InsertBeg;
    test1InsertBeg.insertAtBeg(2, 5);
    test1InsertBeg.insertAtBeg(6, 7);
    test1InsertBeg.insertAtBeg(7, 9);
    test1InsertBeg.insertAtBeg(1, 2);

    cout << "Test 1: " << (test1InsertBeg.AssertEquals("[1,2][7,9][6,7][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBeg.prinf();

    cout << endl
         << "--------INSERT AT END---------" << endl;
    Sequence<int, int> test1InsertAtEnd;
    test1InsertAtEnd.insertAtEnd(2, 5);
    test1InsertAtEnd.insertAtEnd(6, 7);
    test1InsertAtEnd.insertAtEnd(7, 9);
    test1InsertAtEnd.insertAtEnd(1, 2);

    cout << "Test 2: " << (test1InsertAtEnd.AssertEquals("[2,5][6,7][7,9][1,2]") == 1 ? "true" : "false") << endl;
    test1InsertAtEnd.prinf();

    cout << endl
         << "--------DELETE AND SEARCH---------" << endl;

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

    cout << endl
         << "--------INSERT AFTER---------" << endl;

    Sequence<int, int> test1InsertAfter;

    cout << "Test 4.1: " << (test1InsertAfter.insertAfter(8, 9, 2, 1) == false ? "true" : "false") << endl;
    test1InsertAfter.insertAtBeg(2, 5);
    test1InsertAfter.insertAtBeg(6, 7);
    test1InsertAfter.insertAfter(8, 9, 2, 1);
    test1InsertAfter.insertAfter(8, 10, 6, 1);
    test1InsertAfter.insertAfter(1, 1, 8, 2);

    cout << "Test 4.2: " << (test1InsertAfter.AssertEquals("[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;
    test1InsertAfter.prinf();

    test1InsertAfter.insertAfter(1, 1, 8, 5);
    cout << "Test 4.2: " << (test1InsertAfter.AssertEquals("[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;

    test1InsertAfter.insertAfter(1, 1, 11, 5);
    cout << "Test 4.2: " << (test1InsertAfter.AssertEquals("[6,7][8,10][2,5][8,9][1,1]") == 1 ? "true" : "false") << endl;

    cout << endl
         << "--------INSERT BEFORE---------" << endl;

    Sequence<int, int> test1InsertBefore;

    cout << "Test 5.1: " << (test1InsertBefore.insertBefore(8, 9, 2, 1) == false ? "true" : "false") << endl;
    test1InsertBefore.insertAtBeg(2, 5);
    test1InsertBefore.insertAtBeg(6, 7);
    test1InsertBefore.insertBefore(8, 9, 2, 1);
    test1InsertBefore.insertBefore(8, 10, 6, 1);
    test1InsertBefore.insertBefore(1, 1, 8, 2);

    cout << "Test 5.2: " << (test1InsertBefore.AssertEquals("[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;
    test1InsertBefore.prinf();

    test1InsertBefore.insertBefore(1, 1, 8, 5);
    cout << "Test 5.3: " << (test1InsertBefore.AssertEquals("[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;

    test1InsertBefore.insertBefore(1, 1, 11, 5);
    cout << "Test 5.4: " << (test1InsertBefore.AssertEquals("[8,10][6,7][1,1][8,9][2,5]") == 1 ? "true" : "false") << endl;

    cout << endl
         << "--------MERGE BY POSITION---------" << endl;

    Sequence<int, int> test1MergePos;
    Sequence<int, int> test1MergePos2;

    test1MergePos.insertAtEnd(0, 0);
    test1MergePos.insertAtEnd(1, 1);
    test1MergePos.insertAtEnd(2, 2);
    test1MergePos.insertAtEnd(3, 3);
    test1MergePos.insertAtEnd(4, 4);
    test1MergePos.insertAtEnd(5, 5);
    test1MergePos.insertAtEnd(6, 6);
    test1MergePos.insertAtEnd(7, 7);
    test1MergePos.insertAtEnd(8, 8);
    test1MergePos.insertAtEnd(9, 9);

    test1MergePos2.insertAtEnd(0, 0);
    test1MergePos2.insertAtEnd(1, 10);
    test1MergePos2.insertAtEnd(2, 20);
    test1MergePos2.insertAtEnd(3, 30);
    test1MergePos2.insertAtEnd(4, 40);
    test1MergePos2.insertAtEnd(5, 50);
    test1MergePos2.insertAtEnd(6, 60);
    test1MergePos2.insertAtEnd(7, 70);
    test1MergePos2.insertAtEnd(8, 80);
    test1MergePos2.insertAtEnd(9, 90);

    test1MergePos.prinf();
    test1MergePos2.prinf();
    cout<<endl;

    Sequence<int, int> test1MergePosOut = merge_pos(test1MergePos, 3, 1, test1MergePos2, 2, 2, 4);
    cout << "Test 6.2: " << (test1MergePosOut.AssertEquals("[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergePosOut.prinf();

    Sequence<int, int> test1MergePosOut2 = merge_pos(test1MergePos, 3, 1, test1MergePos2, 2, 2, 0);
    cout << "Test 6.3(0count): " << (test1MergePosOut2.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut2.prinf();

    Sequence<int, int> test1MergePosOut3 = merge_pos(test1MergePos, 3, 1, test1MergePos2, 2, 2, 20);
    cout << "Test 6.4(bigcount): " << (test1MergePosOut3.AssertEquals("[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90][7,7][8,8][9,9]") == 1 ? "true" : "false") << endl;
    test1MergePosOut3.prinf();

    Sequence<int, int> test1MergePosOut4 = merge_pos(test1MergePos, 3, 0, test1MergePos2, 2, 0, 8);
    cout << "Test 6.5(0length): " << (test1MergePosOut4.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut4.prinf();

    Sequence<int, int> test1MergePosOut5 = merge_pos(test1MergePos, 20, 1, test1MergePos2, 20, 2, 8);
    cout << "Test 6.6(bigstartpos): " << (test1MergePosOut5.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut5.prinf();

    Sequence<int, int> test1MergePosOut6 = merge_pos(test1MergePos, 0, 1, test1MergePos2, 0, 2, 10);
    cout << "Test 6.7:(0startpos) " << (test1MergePosOut6.AssertEquals("[0,0][0,0][1,10][1,1][2,20][3,30][2,2][4,40][5,50][3,3][6,60][7,70][4,4][8,80][9,90][5,5][6,6][7,7][8,8][9,9]") == 1 ? "true" : "false") << endl;
    test1MergePosOut6.prinf();

    Sequence<int, int> test1Mergetest;
    Sequence<int, int> test1Mergetest2;

    Sequence<int, int> test1MergePosOut7 = merge_pos(test1Mergetest, 0, 1, test1Mergetest2, 0, 2, 10);
    cout << "Test 6.8:(nullsequences) " << (test1MergePosOut7.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut7.prinf();

    Sequence<int, int> test1MergePosOut8 = merge_pos(test1Mergetest, -5, -4, test1Mergetest2, -5, -2, -10);
    cout << "Test 6.9:(negatives) " << (test1MergePosOut8.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergePosOut8.prinf();

    Sequence<int, int> test1MergePosOut9 = merge_pos(test1MergePos, 4, 1, test1MergePos2, -1, -2, 3);
    cout << "Test 6.10(onenegative):  " << (test1MergePosOut9.AssertEquals("[4,4][5,5][6,6]") == 1 ? "true" : "false") << endl;
    test1MergePosOut9.prinf();

    cout << endl
         << "--------MERGE BY KEY---------" << endl;

    test1MergePos.insertAtEnd(3, 50);

    Sequence<int, int> test1MergeKeyOut2 = merge_key(test1MergePos, 3, 2, 1, test1MergePos2, 4, 1, 2, 2);
    cout << "Test 7.1: " << (test1MergeKeyOut2.AssertEquals("[3,50][4,40][5,50][6,60][7,70]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut2.prinf();

    Sequence<int, int> test1MergeKeyOut3 = merge_key(test1MergePos, 3, 2, 20, test1MergePos2, 4, 1, 20, 2);
    cout << "Test 7.2(biggerLength):  " << (test1MergeKeyOut3.AssertEquals("[3,50][4,40][5,50][6,60][7,70][8,80][9,90]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut3.prinf();

    Sequence<int, int> test1MergeKeyOut4 = merge_key(test1MergePos, 3, 2, 0, test1MergePos2, 4, 1, 0, 2);
    cout << "Test 7.3(0length):  " << (test1MergeKeyOut4.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut4.prinf();

    Sequence<int, int> test1MergeKeyOut5 = merge_key(test1MergePos, 3, 2, 1, test1MergePos2, 4, 1, 2, 0);
    cout << "Test 7.4(0count):  " << (test1MergeKeyOut5.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut5.prinf();

    Sequence<int, int> test1MergeKeyOut6 = merge_key(test1MergePos, 3, 2, 1, test1MergePos2, 4, 1, 2, 1);
    cout << "Test 7.5(1count):  " << (test1MergeKeyOut6.AssertEquals("[3,50][4,40][5,50]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut6.prinf();

    Sequence<int, int> test1MergeKeyOut7 = merge_key(test1MergePos, 3, 0, 1, test1MergePos2, 4, 0, 2, 1);
    cout << "Test 7.6(0ocurrancekey):  " << (test1MergeKeyOut7.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut7.prinf();

    Sequence<int, int> test1MergeKeyOut8 = merge_key(test1MergePos, 3, 20, 1, test1MergePos2, 4, 20, 2, 1);
    cout << "Test 7.7(bigocurrancekey):  " << (test1MergeKeyOut8.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut8.prinf();

    Sequence<int, int> test1MergeKeyOut9 = merge_key(test1MergePos, 55, 2, 1, test1MergePos2, 55, 1, 2, 1);
    cout << "Test 7.8(noexistkey):  " << (test1MergeKeyOut9.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut9.prinf();

    Sequence<int, int> test1MergeKeytest;
    Sequence<int, int> test1MergeKeytest2;

    Sequence<int, int> test1MergeKeyOut10 = merge_key(test1Mergetest, 3, 2, 1, test1Mergetest2, 4, 2, 2, 1);
    cout << "Test 7.9:(nullsequences) " << (test1MergeKeyOut10.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut10.prinf();

    Sequence<int, int> test1MergeKeyOut11 = merge_key(test1MergePos, 2, -2, -1, test1MergePos2, 2, -1, -2, -1);
    cout << "Test 7.10(negativevalues):  " << (test1MergeKeyOut11.AssertEquals("[]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut11.prinf();

    Sequence<int, int> test1MergeKeyOut12 = merge_key(test1MergePos, 4, 1, 1, test1MergePos2, 2, -1, -2, 3);
    cout << "Test 7.11(onenegative):  " << (test1MergeKeyOut12.AssertEquals("[4,4][5,5][6,6]") == 1 ? "true" : "false") << endl;
    test1MergeKeyOut12.prinf();


    cout << endl
         << "--------IsEmpty, getKey and hasnext ---------" << endl;

    Sequence<int, int> testemptyandkey;

    cout << "Test 8.1:  " << (testemptyandkey.isEmpty()== true ? "true" : "false") << endl;
    testemptyandkey.insertAtEnd(0, 0);
    cout << "Test 8.2:  " << (testemptyandkey.itsNodeEmpty(1)== false ? "true" : "false") << endl;
    testemptyandkey.insertAtEnd(1, 1);
    testemptyandkey.insertAtEnd(2, 2);
    testemptyandkey.insertAtEnd(3, 3);
    testemptyandkey.insertAtEnd(4, 4);
    testemptyandkey.insertAtEnd(5, 5);

    cout << "Test 8.3:  " << (testemptyandkey.isEmpty()== false ? "true" : "false") << endl;
    cout << "Test 8.4:  " << (testemptyandkey.itsNodeEmpty(5)== true ? "true" : "false") << endl;
    cout << "Test 8.5:  " << (testemptyandkey.itsNodeEmpty(6)== false ? "true" : "false") << endl;



    cout << "Test 8.6:  " << (testemptyandkey.getKey(3) == 3 ? "true" : "false") << endl;
    cout << "Test 8.7:  " << (testemptyandkey.getKey(5) == 5 ? "true" : "false") << endl;
    cout << "Test 8.8:  " << (testemptyandkey.getKey(0) == 0 ? "true" : "false") << endl;


}

template <typename Key, typename Info>
Sequence<Key, Info> merge_pos(Sequence<Key, Info> &seq1, int start_pos1, int len1, Sequence<Key, Info> &seq2, int start_pos2, int len2, int count)
{

    Sequence<int, int> temp;
    int indexSeq1=0;
    int indexSeq2=0;


    if (count > 0  )
    {


        while (start_pos1 != 0 && seq1.itsNodeEmpty(indexSeq1))
        {
            start_pos1--;
            indexSeq1++;
        }
        while (start_pos2 != 0 && seq2.itsNodeEmpty(indexSeq2))
        {
            indexSeq2++;
            start_pos2--;
        }

        while (count != 0)
        {

            int lenght1 = len1;
            int length2 = len2;
            while (lenght1 != 0 && seq1.itsNodeEmpty(indexSeq1))
            {

                temp.insertAtEnd(seq1.getKey(indexSeq1), seq1.getInfo(indexSeq1));

                indexSeq1++;
                lenght1--;
            }

            while (length2 != 0 && seq2.itsNodeEmpty(indexSeq2))
            {

                temp.insertAtEnd(seq2.getKey(indexSeq2), seq2.getInfo(indexSeq2));
                indexSeq2++;
                length2--;
            }

            count--;
        }
    }




    return temp;
}


template <typename Key, typename Info>
Sequence<Key, Info> merge_key(Sequence<Key, Info> &seq1, const Key &start_key1, int start_occ1, int len1, Sequence<Key, Info> &seq2, const Key &start_key2, int start_occ2, int len2, int count)
{

    Sequence<int, int> temp;
    int indexSeq1=0;
    int indexSeq2=0;
    int originalOcc1 = start_occ1;
    int originalOcc2 = start_occ2;


    if (count > 0  )
    {


        while (start_occ1 != 0 && seq1.itsNodeEmpty(indexSeq1))
        {
            if (seq1.getKey(indexSeq1) == start_key1)
            {
                start_occ1--;
            }
            if (start_occ1 != 0)
            {
                indexSeq1++;
            }


        }
        while (start_occ2 != 0 && seq2.itsNodeEmpty(indexSeq2))
        {
            if (seq2.getKey(indexSeq2) == start_key2)
            {
                start_occ2--;
            }
            if (start_occ2 != 0)
            {
                indexSeq2++;
            }
        }

        while (count != 0)
        {

            int lenght1 = len1;
            int length2 = len2;
            while (lenght1 != 0 && seq1.itsNodeEmpty(indexSeq1) && originalOcc1 > 0)
            {

                temp.insertAtEnd(seq1.getKey(indexSeq1), seq1.getInfo(indexSeq1));

                indexSeq1++;
                lenght1--;
            }

            while (length2 != 0 && seq2.itsNodeEmpty(indexSeq2)&& originalOcc2 > 0)
            {

                temp.insertAtEnd(seq2.getKey(indexSeq2), seq2.getInfo(indexSeq2));
                indexSeq2++;
                length2--;
            }

            count--;
        }
    }

    return temp;
}
