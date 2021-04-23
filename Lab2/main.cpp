#include <QCoreApplication>
#include "ring.cpp"
#include <iostream>
#include <vector>
using namespace std;
void print(const vector<int>& x);
void testAll();
void testMerge();
template <typename Key, typename Info>
Ring <Key, Info> merge_pos (const Ring <Key, Info>& ring1, int start_pos1, bool direct1, int len1,const Ring <Key, Info>& ring2, int start_pos2, bool direct2, int len2,int count);
template <typename Key, typename Info>
Ring <Key, Info> merge_key (const Ring <Key, Info>& ring1, const Key& start_key1, int occ1, bool direct1, int len1,const Ring <Key, Info>& ring2, const Key& start_key2, int occ2, bool direct2, int len2,int count);

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
    Ring<int, string>::Iterator i2seqtr(a);
    //iseqtr.associeteWith(d);

    //iseqtr uses elements of a
    *iseqtr = string("testing");
    string c = iseqtr.getKey();
    iseqtr.getKey() = string ("newKey");
     iseqtr = c.begin();
    iseqtr = b.begin();


    Ring<int, int> a;
    a.insertAtBeg(1,1,true);
    a.insertAtEnd(2,2,true);

    Ring<int, int>::Iterator it1;
    it1=a.begin();
    cout <<it1.getKey()<<endl;
    it1++;
    cout <<it1.getKey()<<endl;
    it1++;
    cout <<it1.getKey()<<endl;
    */
    testMerge();
  //  testAll();
    return 0;

}
template <typename Key, typename Info>
Ring <Key, Info> merge_pos (const Ring <Key, Info>& ring1, int start_pos1, bool direct1, int len1,const Ring <Key, Info>& ring2, int start_pos2, bool direct2, int len2,int count){


    Ring<Key, Info> temp;
    int indexSeq1=0;
    int indexSeq2=0;

    typename Ring<Key, Info>::const_Iterator it1;
    it1=ring1.beginConst();

    typename Ring<Key, Info>::const_Iterator it2;
    it2=ring2.beginConst();



    if (count > 0  )
    {


        while (start_pos1 != 0)
        {
            start_pos1--;
            it1++;
            indexSeq1++;
        }
        while (start_pos2 != 0)
        {
            indexSeq2++;
            it2++;
            start_pos2--;
        }

        while (count != 0)
        {
            int lenght1 = len1;
            int length2 = len2;
            while (lenght1 != 0)
            {
                temp.insertAtEnd(it1.getKey(), it1.getInfo(),true);

                it1++;
                lenght1--;
            }

            while (length2 != 0)
            {
                temp.insertAtEnd(it2.getKey(), it2.getInfo(),true);
                it2++;
                length2--;
            }

            count--;
        }
    }



    return temp;
}


template <typename Key, typename Info>
Ring <Key, Info> merge_key (const Ring <Key, Info>& ring1, const Key& start_key1, int occ1, bool direct1, int len1,const Ring <Key, Info>& ring2, const Key& start_key2, int occ2, bool direct2, int len2,int count){
/*
    Ring<Key, Info> temp;
    int indexSeq1=0;
    int indexSeq2=0;
    int originalOcc1 = occ1;
    int originalOcc2 = occ2;


    if (count > 0  )
    {


        while (occ1 != 0 && seq1.itsNodeEmpty(indexSeq1))
        {
            if (seq1.getKey(indexSeq1) == start_key1)
            {
                occ1--;
            }
            if (occ1 != 0)
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
    */
}


void print(const vector<int>& x){
    for (vector<int>::const_iterator i = x.begin();i!=x.end() ;i++ ) {
        cout <<*i<<", ";
        cout<<endl;
    }
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

        test1MergePos.print2(true);
        test1MergePos2.print2(true);
        cout<<endl;

        Ring<int, int> test1MergePosOut = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,true, 2, 4);
   //     cout << "Test 6.2: " << (test1MergePosOut.AssertEquals("[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90]") == 1 ? "true" : "false") << endl;
        test1MergePosOut.print2(true);

        Ring<int, int> test1MergePosOut2 = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,true, 2, 0);
      //  cout << "Test 6.3(0count): " << (test1MergePosOut2.AssertEquals("[]") == 1 ? "true" : "false") << endl;
        test1MergePosOut2.print2(true);

        Ring<int, int> test1MergePosOut3 = merge_pos(test1MergePos, 3,true, 1, test1MergePos2, 2,true, 2, 20);
        //cout << "Test 6.4(bigcount): " << (test1MergePosOut3.AssertEquals("[3,3][2,20][3,30][4,4][4,40][5,50][5,5][6,60][7,70][6,6][8,80][9,90][7,7][8,8][9,9]") == 1 ? "true" : "false") << endl;
        test1MergePosOut3.print2(true);

        Ring<int, int> test1MergePosOut4 = merge_pos(test1MergePos, 3,true, 0, test1MergePos2, 2,true, 0, 8);
        //cout << "Test 6.5(0length): " << (test1MergePosOut4.AssertEquals("[]") == 1 ? "true" : "false") << endl;
        test1MergePosOut4.print2(true);

        Ring<int, int> test1MergePosOut5 = merge_pos(test1MergePos, 20,true, 1, test1MergePos2, 20,true, 2, 8);
        //cout << "Test 6.6(bigstartpos): " << (test1MergePosOut5.AssertEquals("[]") == 1 ? "true" : "false") << endl;
        test1MergePosOut5.print2(true);

        Ring<int, int> test1MergePosOut6 = merge_pos(test1MergePos, 0,true, 1, test1MergePos2, 0, 2,true, 10);
        //cout << "Test 6.7:(0startpos) " << (test1MergePosOut6.AssertEquals("[0,0][0,0][1,10][1,1][2,20][3,30][2,2][4,40][5,50][3,3][6,60][7,70][4,4][8,80][9,90][5,5][6,6][7,7][8,8][9,9]") == 1 ? "true" : "false") << endl;
        test1MergePosOut6.print2(true);

        Ring<int, int> test1Mergetest;
        Ring<int, int> test1Mergetest2;

        Ring<int, int> test1MergePosOut7 = merge_pos(test1Mergetest, 0,true, 1, test1Mergetest2, 0,true, 2, 10);
        //cout << "Test 6.8:(nullRings) " << (test1MergePosOut7.AssertEquals("[]") == 1 ? "true" : "false") << endl;
        test1MergePosOut7.print2(true);

        Ring<int, int> test1MergePosOut8 = merge_pos(test1Mergetest, -5,true, -4, test1Mergetest2, -5,true, -2, -10);
        //cout << "Test 6.9:(negatives) " << (test1MergePosOut8.AssertEquals("[]") == 1 ? "true" : "false") << endl;
        test1MergePosOut8.print2(true);

        Ring<int, int> test1MergePosOut9 = merge_pos(test1MergePos, 4,true, 1, test1MergePos2, -1,true, -2, 3);
        //cout << "Test 6.10(onenegative):  " << (test1MergePosOut9.AssertEquals("[4,4][5,5][6,6]") == 1 ? "true" : "false") << endl;
        test1MergePosOut9.print2(true);
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
