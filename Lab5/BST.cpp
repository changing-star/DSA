#include <iostream>

using namespace std; 

class Node{
    public:
        int data;
        Node *right, *left;

        Node(int data){
            this->data = data;
            this->left = this->right = nullptr;
        }
};

class BinarySearchTree{
    private:
        int size;
        Node* root;

        Node *insertHelper(Node* node, int data){
              if(node==nullptr){
                size++;
                return new Node(data);
            }

            if(data < node->data){
                node->left = insertHelper(node->left, data);
            } else if (data > node->data){
                node->right = insertHelper(node->right, data);
            }

            return node;
        }

        void preOrderHelper(Node* node){
            if(node != nullptr){
                cout << node->data << " ";
                preOrderHelper(node->left);
                preOrderHelper(node->right);
            }
        }

        void inOrderHelper(Node* node){
            if(node != nullptr){
                inOrderHelper(node->left);
                cout << node->data << " ";
                inOrderHelper(node->right);
            }
        }

        void postOrderHelper(Node* node){
            if(node != nullptr){
                postOrderHelper(node->left);
                postOrderHelper(node->right);
                cout << node->data << " ";
            }
        }

        bool searchHelper(Node *node, int data){
            if(node==NULL){
                return false;
            } else if (data == node->data){
                return true;
            } else if(data > node->data){
                return searchHelper(node->right, data);
            } else if(data < node->data){
                return searchHelper(node->left, data);
            }
            return false;
        }

    public:
        BinarySearchTree(int data){
            size = 1;
            root = new Node(data);
        }

        BinarySearchTree(){
            size = 0;
            root = nullptr;
        }

        void insert(int data){
            root = insertHelper(root, data);
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

        bool search(int data){
            return searchHelper(root, data);
        }

        int getSize(){
            return size;
        }

        Node* getRoot(){
            return root;
        }

};  

int main(){
    BinarySearchTree bst(50);

    bst.insert(17);
    bst.insert(72);

    bst.insert(12);
    bst.insert(23);
    bst.insert(9);
    bst.insert(14);
    bst.insert(19);

    bst.insert(54);
    bst.insert(76);
    bst.insert(67);




    cout << "Preorder \n";
    bst.preOrder();
    cout << "\nInorder \n";
    bst.inOrder();
    cout << "\nPostorder \n";
    bst.postOrder();

    

    return 0;
}