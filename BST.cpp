//Rahul Patel
//Sarah Cole
#include "BST.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

BST::BST() {
    root = nullptr;
}

BST::BST(string title, string author, int yr, string pub, long long isbn, float rate) {
    BSTNode *n = new BSTNode(title, author, yr, pub, isbn, rate);
    root = n;
}

BST::~BST() {
	clearTree();
}
void BST::insert(string title, string author, int yr, string pub, long long isbn, float rate) {
    BSTNode *node = new BSTNode(title, author, yr, pub, isbn, rate);
    BSTNode *temp = root;
    if(root == nullptr){
        root = node;
    }
    else{
        while(temp != nullptr) {
            if (*(node->book) < *(temp->book)) {
                if (temp->left == nullptr) {
                    temp->left = node;
                    node->parent = temp;
                    temp = nullptr;
                } else {
                    temp = temp->left;
                }
            }
            else if (*(node->book) >= *(temp->book)) {
                if (temp->right == nullptr) {
                    temp->right = node;
                    node->parent = temp;
                    temp = nullptr;
                } else {
                    temp = temp->right;
                }
            }
        }
        setHeight(node);
    }
}

BSTNode *BST::find(string title, string author) {
    BSTNode *temp = root;
    if(root == nullptr){
        return NULL;
    }
    while(temp != nullptr){
        if(author < temp->book->author){
            temp = temp->left;

        }
        else if(author > temp->book->author){
            temp = temp->right;

        }
        else if((author == temp->book->author) && (title != temp->book->title)){
            if(title < temp->book->title){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        if ((author == temp->book->author) && (title == temp->book->title)){
            return temp;
        }
        else if((temp->left == nullptr) && (temp->right == nullptr)){
            return nullptr;
        }
    }
    return nullptr;
}


BSTNode *BST::find(string title, string author, BSTNode *start) {
	BSTNode *temp = start;
    if(start == nullptr){
        return nullptr;
    }
    while(temp != nullptr) {
        if (author < temp->book->author) {
            temp = temp->left;
        } else if (author > temp->book->author) {
            temp = temp->right;

        } else if ((author == temp->book->author) && (title != temp->book->title)) {
            if (title < temp->book->title) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        if ((author == temp->book->author) && (title == temp->book->title)) {
            return temp;
        } else if ((temp->left == nullptr) && (temp->right == nullptr)) {
            return nullptr;
        }
    }
    return NULL;
}


void BST::printTreeIO() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl << "Printing In-Order:" << endl;
		printTreeIO(root);
	}
}

void BST::printTreeIO(BSTNode *node) {
    if(node == nullptr){
        return;
    }
    printTreeIO(node->left);
    node->printNode(false);
    printTreeIO(node->right);
}

void BST::printTreePre() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl << "Printing Pre-Order:" << endl;
		printTreePre(root);
	}
}

void BST::printTreePre(BSTNode *node) {

//    printTreePre();
    if (node == nullptr){
        return;
    }
    node->printNode(false);
    printTreePre(node->left);
    printTreePre(node->right);
}

void BST::printTreePost() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing Post-Order:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePost(BSTNode *node) {
    if (node == nullptr){
        return;
    }
    printTreePost(node->left);
    printTreePost(node->right);
    node->printNode(false);

}

void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void BST::clearTree(BSTNode *node) {
	if (node == NULL) {
		return;
	}
	else {
		clearTree(node->left);
		node->left = NULL;
		clearTree(node->right);
		node->right = NULL;
		node->printNode(true);
		delete node;
	}
}

bool BST::checkOut(string title, string author) {
    if(root == nullptr){
        return false;
    }
    BSTNode *temp = root;
    find(title, author,root);
    while(temp != nullptr){
        find(title, author, root);
        if((temp->book->title == title) && (temp->book->author == author) && (temp->book->checked_out == false)){
            temp->book->checked_out = true;
            return true;
        }
        else if(author < temp->book->author){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
	return false;
}
bool BST::checkIn(string title, string author) {
    if(root == nullptr){
        return false;
    }
    BSTNode *temp = root;
    find(title, author,root);
    while(temp != nullptr){
        find(title, author, root);
        if((temp->book->title == title) && (temp->book->author == author) && (temp->book->checked_out == true)){
            temp->book->checked_out = false;
            return true;
        }
        else if(author < temp->book->author){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
void BST::updateRating(string title, string author, float newRating) {
    if(find(title, author) == nullptr){
        return;
    }
    BSTNode *temp = find(title, author);
    if(temp != nullptr){
        temp->book->rating = newRating;
    }
    while(true){
        temp = find(title, author, temp->right);
        if(temp == nullptr){
            return;
        }
        temp->book->rating = newRating;
    }
}


BSTNode *BST::removeNoKids(BSTNode *node) {
	BSTNode *temp = node;
    if(root == nullptr){
        setHeight(node);
        return nullptr;
    }
    if((root->left == nullptr) && (root->right == nullptr) && (root == node)){
        root = nullptr;
        setHeight(node);
        return temp;
    }
    if((node->left == nullptr) && (node->right == nullptr)){
        if(node->parent->left == node){
            node->parent->left = nullptr;
        }
        else if(node->parent->right == node){
            node->parent->right = nullptr;
        }
        setHeight(node);
        return temp;
    }
    setHeight(node);
    return NULL;
}

BSTNode *BST::removeOneKid(BSTNode *node, bool leftFlag) {
    BSTNode *temp;
    if (leftFlag) {
        temp = node->left;
    } else {
        temp = node->right;
    }
    if (node->parent == nullptr){
        temp->parent = nullptr;
        root = temp;
    } else if (node-> parent-> left == node){
        node->parent->left = temp;
        temp->parent = node->parent;
        node->parent = nullptr;
    } else if (node->parent->right == node) {
        node->parent->right = temp;
        temp->parent = node->parent;
        node-> parent = nullptr;
    }
    if (node->left == temp){
        node->left = nullptr;
    } else if (node->right == temp){
        node->right = nullptr;
    }
    setHeight(temp);
    return node;
}
BSTNode *BST::remove(string title, string author) {
    BSTNode *node = find(title, author);
    if (node == nullptr) {
        return nullptr;
    }
    bool left = (node->left == nullptr);
    bool right = (node->right == nullptr);
    if (left && right) {
        return removeNoKids(node);
    } else if (left) {
        return removeOneKid(node, false);
    } else if (right) {
        return removeOneKid(node, true);
    }

    BSTNode *temp = node->right;
    while (temp->left != nullptr) {
        temp = temp->left;
    }

    if (temp->left == nullptr && temp->right == nullptr) {
        if (temp->parent->left ==temp) {
            temp->parent->left = nullptr;
            setHeight(temp->parent);
            temp->parent = nullptr;
        } else if (temp->parent->right == temp) {
            temp->parent->right = nullptr;
            setHeight(temp->parent);
            temp->parent = nullptr;
        }
        if (node->parent == nullptr){
            temp->parent = nullptr;
            root = temp;
        } else if (node->parent->left == node) {
            temp->parent = node->parent;
            node->parent->left = temp;
            node->parent = nullptr;
        } else if (node->parent->right == node) {
            temp->parent = node->parent;
            node->parent->right = temp;
            node->parent = nullptr;
        }
        if (node->right != nullptr) {
            node->right->parent = temp;
            temp->right = node->right;
            node->right = nullptr;
        }
        if (node->left != nullptr) {
            node->left->parent = temp;
            temp->left = node->left;
            node->left = nullptr;
        }
        setHeight(temp);
        return node;
    }

    if (temp->right != nullptr) {
        BSTNode *kid = temp->right;
        if (temp->parent->left ==temp) {
            temp->parent->left = kid;
            kid->parent = temp->parent;
            setHeight(kid);
            temp->parent = nullptr;
            temp->right = nullptr;
        } else if (temp->parent->right == temp) {
            temp->parent->right = kid;
            kid->parent = temp->parent;
            setHeight(kid);
            temp->parent = nullptr;
            temp->right = nullptr;
        }
        if (node->parent == nullptr) {
            temp->parent = nullptr;
            root = temp;
        }else if (node->parent->left == node) {
            temp->parent = node->parent;
            node->parent->left = temp;
            node->parent = nullptr;
        } else if (node->parent->right == node) {
            temp->parent = node->parent;
            node->parent->right = temp;
            node->parent = nullptr;
        }
        if (node->right != nullptr) {
            node->right->parent = temp;
            temp->right = node->right;
            node->right = nullptr;
        }
        if (node->left != nullptr) {
            node->left->parent = temp;
            temp->left = node->left;
            node->left = nullptr;
        }
        setHeight(temp);
        return node;
    }
    return nullptr;
}

void BST::setHeight(BSTNode *node){
    if (node->left == nullptr && node->right == nullptr) {
        node->height = 1;
    } else if (node->left == nullptr) {
        node->height = node->right->height + 1;
    } else if (node->right == nullptr) {
        node->height = node->left->height + 1;
    } else if (node->left->height > node->right->height) {
        node->height = node->left->height + 1;  //2
    } else {
        node->height = node->right->height + 1;  //3
    }
    if (node->parent != nullptr) {
        setHeight(node->parent);
    }
}

