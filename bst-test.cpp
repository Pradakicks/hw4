#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    BinarySearchTree<char,int> bt;
    // bt.insert(std::make_pair('a',1));
    // bt.insert(std::make_pair('a',1));
    bt.insert(std::make_pair('b',2));
    bt.insert(std::make_pair('a',1));
    bt.insert(std::make_pair('c',3));
    bt.insert(std::make_pair('e',4));
    bt.insert(std::make_pair('d',3));
    // bt.insert(std::make_pair('f',5));
    bt.print();
    // cout << "Is Balanced? " << bt.isBalanced() << endl;
    bt.remove('c');
    // cout << "Binary Search Tree contents:" << endl;
    // for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }

    bt.print();

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
    // AVL Tree Tests
    // AVLTree<char,int> at;
    // at.insert(std::make_pair('a',1));
    // at.insert(std::make_pair('b',2));

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


    return 0;
}
