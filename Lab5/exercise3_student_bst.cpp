#include <iostream>
#include <string>

using namespace std;

class StudentNode{
    public:
        string name;
        StudentNode *right, *left;

        StudentNode(string name){
            this->name = name;
            this->left = this->right = nullptr;
        }
};

class StudentBST{
    private:
        int size;
        StudentNode* root;

        StudentNode *insertHelper(StudentNode* node, string name){
            if(node == nullptr){
                size++;
                return new StudentNode(name);
            }

            if(name < node->name){
                node->left = insertHelper(node->left, name);
            } else if (name > node->name){
                node->right = insertHelper(node->right, name);
            }

            return node;
        }

        void preOrderHelper(StudentNode* node){
            if(node != nullptr){
                cout << node->name << " ";
                preOrderHelper(node->left);
                preOrderHelper(node->right);
            }
        }

        void inOrderHelper(StudentNode* node){
            if(node != nullptr){
                inOrderHelper(node->left);
                cout << node->name << " ";
                inOrderHelper(node->right);
            }
        }

        void postOrderHelper(StudentNode* node){
            if(node != nullptr){
                postOrderHelper(node->left);
                postOrderHelper(node->right);
                cout << node->name << " ";
            }
        }

        bool searchHelper(StudentNode *node, string name){
            if(node == NULL){
                return false;
            } else if (name == node->name){
                return true;
            } else if(name > node->name){
                return searchHelper(node->right, name);
            } else if(name < node->name){
                return searchHelper(node->left, name);
            }
            return false;
        }

    public:
        StudentBST(){
            size = 0;
            root = nullptr;
        }

        void insert(string name){
            root = insertHelper(root, name);
        }

        void preOrder(){
            preOrderHelper(root);
        }

        void inOrder(){
            inOrderHelper(root);
        }

        void postOrder(){
            postOrderHelper(root);
        }

        bool search(string name){
            return searchHelper(root, name);
        }

        int getSize(){
            return size;
        }

        StudentNode* getRoot(){
            return root;
        }
};

int main(){
    StudentBST studentTree;

    studentTree.insert("Alice");
    studentTree.insert("Bob");
    studentTree.insert("Charlie");
    studentTree.insert("David");
    studentTree.insert("Eve");
    studentTree.insert("Frank");
    studentTree.insert("Grace");
    studentTree.insert("Henry");

    cout << "Student Names BST - Exercise 3\n";
    cout << "Preorder traversal: ";
    studentTree.preOrder();
    cout << "\nInorder traversal: ";
    studentTree.inOrder();
    cout << "\nPostorder traversal: ";
    studentTree.postOrder();
    cout << "\n\n";

    cout << "Searching for students:\n";
    cout << "Alice: " << (studentTree.search("Alice") ? "Found" : "Not found") << endl;
    cout << "Henry: " << (studentTree.search("Henry") ? "Found" : "Not found") << endl;
    cout << "Zoe: " << (studentTree.search("Zoe") ? "Found" : "Not found") << endl;
    cout << "Bob: " << (studentTree.search("Bob") ? "Found" : "Not found") << endl;

    return 0;
}