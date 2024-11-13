//Rahul Patel
//Sarah Cole
#include "BST.hpp"
#include "Book.hpp"
#include "Library.hpp"
#include <iostream>
using namespace std;

int main() {
//	 Testing book comparisons;
     Book b1("Acorns","Shmoe, Joe",1975,"Science Books",12345,3.5);
     Book b2("Birch Trees","Shmoe, Joe",1970,"Science Books",34567,4.0);
     Book b3("Dogs Are My Best Friend","David, Alex",2010,"Books for Children",22222,4.0);
	 cout << (b1 < b1);
	 cout << (b1 < b2);
	 cout << (b1 < b3);
	 cout << (b1 == b1);
	 cout << (b1 == b2);
	 cout << (b1 != b3);
	 cout << (b1 > b1);
	 cout << (b1 > b2);
	 cout << (b1 > b3);
	 cout << (b1 <= b1);
	 cout << (b1 <= b2);
	 cout << (b1 <= b3);
	 cout << (b1 >= b1);
	 cout << (b1 >= b2);
	 cout << (b1 >= b3);

	Library library("C:\\Users\\thund\\CLionProjects\\Project2\\halloween.txt");
	library.menu();
//    BST *b = new BST("Something Wicked This Way Comes", "Bradbury, Ray", 2001, "Bookspan", 9780965020459, 3.94);
//    BSTNode *a = new BSTNode("Something Wicked This Way Comes", "Bradbury, Ray", 2001, "Bookspan", 9780965020459, 3.94);
//    cout << "Testing find" << endl;
//    b->find("Frankenstein","Shelley, Mary Wollstonecraft", a);
    //"C:\\Users\\Leighanne\\Dropbox\\school\\cisc220\\BST_23F\\halloween.txt"
    //C:\\Users\\thund\\CLionProjects\\Project2\\halloween.txt"
	return 0;

}
