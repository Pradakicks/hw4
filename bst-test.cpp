#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    // BinarySearchTree<char,int> bt;
    // // bt.insert(std::make_pair('a',1));
    // // bt.insert(std::make_pair('a',1));
    // bt.insert(std::make_pair('b',2));
    // bt.insert(std::make_pair('a',1));
    // bt.insert(std::make_pair('c',3));
    // bt.insert(std::make_pair('e',4));
    // bt.insert(std::make_pair('d',3));
    // // bt.insert(std::make_pair('f',5));
    // bt.print();
    // // cout << "Is Balanced? " << bt.isBalanced() << endl;
    // bt.remove('c');
    // // cout << "Binary Search Tree contents:" << endl;
    // // for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
    // //     cout << it->first << " " << it->second << endl;
    // // }

    // bt.print();

//     if(bt.find('b') != bt.end()) {
//         cout << "Found b" << endl;
//     }
//     else {
//         cout << "Did not find b" << endl;
//     }
//     cout << "Erasing b" << endl;
//     bt.remove('b');
//     bt.print();

//   if(bt.find('b') != bt.end()) {
//         cout << "Found b" << endl;
//     }
//     else {
//         cout << "Did not find b" << endl;
//     }


    // BinarySearchTree<int, double> bst;
	// bst.insert(std::make_pair(1, 1.0));
	// bst.insert(std::make_pair(2, 1.0));
	// bst.insert(std::make_pair(3, 1.0));
    // // bst.print();
    // cout << "Removing 1" << endl; 
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << endl;
	// bst.remove(1);
    // bst.print();
    // // AVL Tree Tests
    // AVLTree<char,int> at;
    // at.insert(std::make_pair('b',1));
    // at.insert(std::make_pair('a',2));
    // at.insert(std::make_pair('e',3));
    // at.insert(std::make_pair('c',4));
    // at.insert(std::make_pair('h',5));
    // at.insert(std::make_pair('f',6));
    // at.insert(std::make_pair('y',7));
	// at.print();
	// // at.remove('a');
	// // at.print();


    // cout << "\nAVLTree contents:" << endl;
    // for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(at.find('b') != at.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // at.remove('b');
	// if(at.find('b') != at.end()) {
	// 		cout << "Found b" << endl;
	// 	}
	// 	else {
	// 		cout << "Did not find b" << endl;
	// 	}


    AVLTree<int,double> at;
	at.insert(std::make_pair(-77, 1.0));
	at.insert(std::make_pair(-89, 1.0));
	at.insert(std::make_pair(-96, 1.0));
	at.insert(std::make_pair(-64, 1.0));
	at.insert(std::make_pair(-73, 1.0));
	at.insert(std::make_pair(-61, 1.0));
	at.remove(-61);
	at.remove(-64);
	cout << "\nAVLTree contents:" << endl;
    for(AVLTree<int,double>::iterator it = at.begin(); it != at.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
	at.print();
	at.remove(1);


	// AVLTree<int, std::string> b, c, d;
	// std::pair<int, std::string> item5(5, "five");
	// std::pair<int, std::string> item3(3, "three");
	// std::pair<int, std::string> item7(7, "seven");
	// std::pair<int, std::string> item4(4, "four");
	// std::pair<int, std::string> item6(6, "six");
	// std::pair<int, std::string> item9(9, "nine");
	// std::pair<int, std::string> item10(10, "ten");
	// std::pair<int, std::string> item2(2, "two");
	// std::pair<int, std::string> item8(8, "eight");
	// std::pair<int, std::string> item13(13, "thirteen");
	// std::pair<int, std::string> item11(11, "eleven");
	// std::pair<int, std::string> item12(12, "twelve");
	// std::pair<int, std::string> item15(15, "fifteen");
	// std::pair<int, std::string> item14(14, "fourteen");
	// std::pair<int, std::string> item16(16, "sixteen");
	// std::pair<int, std::string> item17(17, "seventeen");


	// b.insert(item5);

	// b.remove(7);

	// b.remove(5);

	// b.insert(item5);
	// b.insert(item3);

	// b.remove(5);

	// b.remove(3);


	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);

	// b.remove(5);

	// b.remove(7);

	// b.remove(3);

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.print();

	// b.remove(5);

	// b.clear();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);

	// b.remove(6);

	// b.remove(4);

	// b.clear();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);

	// b.remove(5);

	// b.remove(7);

	// b.remove(6);

	// b.clear();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);
	// b.insert(item10);

	// b.remove(5);

	// b.remove(9);

	// b.remove(3);

	// b.remove(7);

	// b.remove(4);

	// b.remove(10);

	// b.remove(10);

	// b.remove(6);

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);
	// b.insert(item10);
	// b.insert(item2);
	// b.insert(item8);

	// b.insert(item13);

	// b.insert(item12);

	// b.insert(item11);

	// b.remove(13);

	// b.remove(12);

	// b.remove(10);
	// b.remove(13);
	// b.remove(7);
	// b.remove(8);
	// b.remove(7);


	// d.insert(item10);
	// d.insert(item3);
	// d.insert(item2);
	// d.insert(item15);
	// d.insert(item12);
	// d.insert(item11);
	// d.insert(item14);
	// d.insert(item13);
	// d.insert(item16);
	// d.insert(item17);


	// d.remove(15);


	// d.remove(10);

	// c.insert(item5);
	// c.insert(item3);
	// c.insert(item7);
	// c.insert(item4);
	// c.insert(item6);
	// c.insert(item9);
	// c.insert(item10);
	// c.insert(item2);
	// c.insert(item8);
	// c.insert(item15);
	// c.insert(item11);
	// c.insert(item14);
	// c.insert(item13);
	// c.insert(item12);

	// c.remove(15);
	// c.remove(14);


    // BinarySearchTree<int, std::string> b, c, d;
	// std::pair<int, std::string> item5(5, "five");
	// std::pair<int, std::string> item3(3, "three");
	// std::pair<int, std::string> item7(7, "seven");
	// std::pair<int, std::string> item4(4, "four");
	// std::pair<int, std::string> item6(6, "six");
	// std::pair<int, std::string> item9(9, "nine");
	// std::pair<int, std::string> item10(10, "ten");
	// std::pair<int, std::string> item2(2, "two");
	// std::pair<int, std::string> item8(8, "eight");
	// std::pair<int, std::string> item13(13, "thirteen");
	// std::pair<int, std::string> item11(11, "eleven");
	// std::pair<int, std::string> item12(12, "twelve");
	// std::pair<int, std::string> item15(15, "fifteen");
	// std::pair<int, std::string> item14(14, "fourteen");
	// std::pair<int, std::string> item16(16, "sixteen");
	// std::pair<int, std::string> item17(17, "seventeen");


	// b.insert(item5);

	// b.remove(7);

	// b.remove(5);

	// b.insert(item5);
	// b.insert(item3);

	// b.remove(5);

	// b.remove(3);


	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);

	// b.remove(5);

	// b.remove(7);

	// b.remove(3);

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);

	// b.remove(5);

	// b.clear();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);

	// b.remove(6);

	// b.remove(4);

	// b.clear();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);

	// b.remove(5);

	// b.remove(7);

	// b.remove(6);

	// b.clear();

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);
	// b.insert(item10);

	// b.remove(5);

	// b.remove(9);

	// b.remove(3);

	// b.remove(7);

	// b.remove(4);

	// b.remove(10);

	// b.remove(10);

	// b.remove(6);

	// b.insert(item5);
	// b.insert(item3);
	// b.insert(item7);
	// b.insert(item4);
	// b.insert(item6);
	// b.insert(item9);
	// b.insert(item10);
	// b.insert(item2);
	// b.insert(item8);

	// b.insert(item13);

	// b.insert(item12);

	// b.insert(item11);

	// b.remove(13);

	// b.remove(12);

	// b.remove(10);
	// b.remove(13);
	// b.remove(7);
	// b.remove(8);
	// b.remove(7);

	// d.insert(item10);
	// d.insert(item3);
	// d.insert(item2);
	// d.insert(item15);
	// d.insert(item12);
	// d.insert(item11);
	// d.insert(item14);
	// d.insert(item13);
	// d.insert(item16);
	// d.insert(item17);

	// d.remove(15);


	// d.remove(10);

	// c.insert(item5);
	// c.insert(item3);
	// c.insert(item7);
	// c.insert(item4);
	// c.insert(item6);
	// c.insert(item9);
	// c.insert(item10);
	// c.insert(item2);
	// c.insert(item8);
	// c.insert(item15);
	// c.insert(item11);
	// c.insert(item14);
	// c.insert(item13);
	// c.insert(item12);

	// c.remove(15);
	// c.remove(14);



  	// AVL Tree Tests
    // AVLTree<int,int> at;
    // at.insert(std::make_pair(10,1));
    // at.insert(std::make_pair(20,1));
    // at.insert(std::make_pair(30,1));
    // at.insert(std::make_pair(15,1));
    // at.insert(std::make_pair(25,1));
    // at.insert(std::make_pair(12,1));
    // // at.insert(std::make_pair(5,1));
    // // at.insert(std::make_pair(3,1));
    // // at.insert(std::make_pair(8,1));
	// // at.remove('a');
	// at.print();


    // cout << "\nAVLTree contents:" << endl;
    // for(AVLTree<int,int>::iterator it = at.begin(); it != at.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(at.find('b') != at.end()) {

    return 0;
}
