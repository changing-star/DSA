#include <iostream>
#include <string>

using namespace std;

class Product{
    public:
        int id;
        string name;
        double price;

        Product(int id, string name, double price){
            this->id = id;
            this->name = name;
            this->price = price;
        }

        void display(){
            cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
        }
};

class ProductNode{
    public:
        Product data;
        ProductNode *right, *left;

        ProductNode(Product product) : data(product), left(nullptr), right(nullptr) {
        }
    };

class ProductBST{
    private:
        int size;
        ProductNode* root;

        ProductNode *insertHelper(ProductNode* node, Product product){
            if(node == nullptr){
                size++;
                return new ProductNode(product);
            }

            if(product.id < node->data.id){
                node->left = insertHelper(node->left, product);
            } else if (product.id > node->data.id){
                node->right = insertHelper(node->right, product);
            }

            return node;
        }

        void preOrderHelper(ProductNode* node){
            if(node != nullptr){
                node->data.display();
                preOrderHelper(node->left);
                preOrderHelper(node->right);
            }
        }

        void inOrderHelper(ProductNode* node){
            if(node != nullptr){
                inOrderHelper(node->left);
                node->data.display();
                inOrderHelper(node->right);
            }
        }

        void postOrderHelper(ProductNode* node){
            if(node != nullptr){
                postOrderHelper(node->left);
                postOrderHelper(node->right);
                node->data.display();
            }
        }

        Product* searchHelper(ProductNode *node, int id){
            if(node == NULL){
                return nullptr;
            } else if (id == node->data.id){
                return &(node->data);
            } else if(id > node->data.id){
                return searchHelper(node->right, id);
            } else if(id < node->data.id){
                return searchHelper(node->left, id);
            }
            return nullptr;
        }

    public:
        ProductBST(){
            size = 0;
            root = nullptr;
        }

        void insert(Product product){
            root = insertHelper(root, product);
        }

        void preOrder(){
            cout << "Preorder traversal:\n";
            preOrderHelper(root);
        }

        void inOrder(){
            cout << "Inorder traversal:\n";
            inOrderHelper(root);
        }

        void postOrder(){
            cout << "Postorder traversal:\n";
            postOrderHelper(root);
        }

        Product* search(int id){
            return searchHelper(root, id);
        }

        int getSize(){
            return size;
        }

        ProductNode* getRoot(){
            return root;
        }
};

int main(){
    ProductBST productTree;

    Product p1(101, "Laptop", 999.99);
    Product p2(205, "Mouse", 25.50);
    Product p3(150, "Keyboard", 75.00);
    Product p4(300, "Monitor", 299.99);
    Product p5(180, "Headphones", 89.99);
    Product p6(120, "Webcam", 45.00);
    Product p7(250, "USB Hub", 15.99);
    Product p8(90, "Speakers", 55.50);

    productTree.insert(p1);
    productTree.insert(p2);
    productTree.insert(p3);
    productTree.insert(p4);
    productTree.insert(p5);
    productTree.insert(p6);
    productTree.insert(p7);
    productTree.insert(p8);

    cout << "Product List BST - Exercise 4\n";
    cout << "Total products: " << productTree.getSize() << "\n\n";

    productTree.inOrder();
    cout << "\n";
    productTree.preOrder();
    cout << "\n";
    productTree.postOrder();
    cout << "\n";

    cout << "\nSearching for products by ID:\n";
    int searchIds[] = {101, 180, 999, 90, 300};
    
    for(int id : searchIds){
        Product* found = productTree.search(id);
        if(found != nullptr){
            cout << "Found product: ";
            found->display();
        } else {
            cout << "Product with ID " << id << " not found.\n";
        }
    }

    return 0;
}