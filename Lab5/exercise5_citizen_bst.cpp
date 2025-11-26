#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ostream>

using namespace std;

class CitizenNode{
    public:
        string citizenId;
        CitizenNode *right, *left;

        CitizenNode(string id){
            this->citizenId = id;
            this->left = this->right = nullptr;
        }
};

class CitizenBST{
    private:
        int size;
        CitizenNode* root;

        CitizenNode *insertHelper(CitizenNode* node, string id){
            if(node == nullptr){
                size++;
                return new CitizenNode(id);
            }

            if(id < node->citizenId){
                node->left = insertHelper(node->left, id);
            } else if (id > node->citizenId){
                node->right = insertHelper(node->right, id);
            }

            return node;
        }

        void preOrderHelper(CitizenNode* node, ostream& out){
            if(node != nullptr){
                out << node->citizenId << "\n";
                preOrderHelper(node->left, out);
                preOrderHelper(node->right, out);
            }
        }

        void inOrderHelper(CitizenNode* node, ostream& out){
            if(node != nullptr){
                inOrderHelper(node->left, out);
                out << node->citizenId << "\n";
                inOrderHelper(node->right, out);
            }
        }

        void postOrderHelper(CitizenNode* node, ostream& out){
            if(node != nullptr){
                postOrderHelper(node->left, out);
                postOrderHelper(node->right, out);
                out << node->citizenId << "\n";
            }
        }

        bool searchHelper(CitizenNode *node, string id){
            if(node == NULL){
                return false;
            } else if (id == node->citizenId){
                return true;
            } else if(id > node->citizenId){
                return searchHelper(node->right, id);
            } else if(id < node->citizenId){
                return searchHelper(node->left, id);
            }
            return false;
        }

    public:
        CitizenBST(){
            size = 0;
            root = nullptr;
        }

        void insert(string id){
            root = insertHelper(root, id);
        }

        void preOrder(string filename = ""){
            if(filename.empty()){
                cout << "Preorder traversal:\n";
                preOrderHelper(root, cout);
            } else {
                ofstream out(filename);
                preOrderHelper(root, out);
                out.close();
            }
        }

        void inOrder(string filename = ""){
            if(filename.empty()){
                cout << "Inorder traversal:\n";
                inOrderHelper(root, cout);
            } else {
                ofstream out(filename);
                inOrderHelper(root, out);
                out.close();
            }
        }

        void postOrder(string filename = ""){
            if(filename.empty()){
                cout << "Postorder traversal:\n";
                postOrderHelper(root, cout);
            } else {
                ofstream out(filename);
                postOrderHelper(root, out);
                out.close();
            }
        }

        bool search(string id){
            return searchHelper(root, id);
        }

        int getSize(){
            return size;
        }

        CitizenNode* getRoot(){
            return root;
        }
};

string generateCitizenID(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(100000000, 999999999);
    return to_string(dis(gen));
}

void generateCitizenIDs(string filename, int count){
    ofstream file(filename);
    if(!file.is_open()){
        cout << "Error: Cannot create file " << filename << endl;
        return;
    }

    cout << "Generating " << count << " citizen IDs..." << endl;
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < count; i++){
        string id = generateCitizenID();
        file << id << "\n";
        
        if((i + 1) % 100000 == 0){
            cout << "Generated " << (i + 1) << " IDs..." << endl;
        }
    }

    file.close();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
    
    cout << "Successfully generated " << count << " citizen IDs in " << duration.count() << " seconds." << endl;
}

void loadCitizenIDsFromCSV(string filename, CitizenBST& bst, int maxLoad = 100000){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }

    cout << "Loading citizen IDs from " << filename << " (max " << maxLoad << ")..." << endl;
    auto start = chrono::high_resolution_clock::now();

    string id;
    int loaded = 0;
    
    while(getline(file, id) && loaded < maxLoad){
        bst.insert(id);
        loaded++;
        
        if(loaded % 10000 == 0){
            cout << "Loaded " << loaded << " IDs into BST..." << endl;
        }
    }

    file.close();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
    
    cout << "Successfully loaded " << loaded << " citizen IDs into BST in " << duration.count() << " seconds." << endl;
}

int main(){
    const string CSV_FILE = "citizen_ids.csv";
    const int TOTAL_IDS = 1000000;
    const int MAX_LOAD = 100000;

    cout << "=== Exercise 5: Large Scale Citizen ID BST ===\n\n";

    cout << "Step 1: Generating " << TOTAL_IDS << " citizen IDs\n";
    generateCitizenIDs(CSV_FILE, TOTAL_IDS);

    cout << "\nStep 2: Building BST with citizen IDs (limited to " << MAX_LOAD << " for performance)\n";
    CitizenBST citizenTree;
    loadCitizenIDsFromCSV(CSV_FILE, citizenTree, MAX_LOAD);

    cout << "\nBST Statistics:\n";
    cout << "Total citizens in BST: " << citizenTree.getSize() << endl;

    cout << "\nStep 3: Testing traversals (saving to files)\n";
    citizenTree.preOrder("preorder_traversal.txt");
    citizenTree.inOrder("inorder_traversal.txt");
    citizenTree.postOrder("postorder_traversal.txt");
    cout << "Traversals saved to text files.\n";

    cout << "\nStep 4: Testing search functionality\n";
    string testIds[] = {"123456789", "987654321", "555555555", "111111111", "999999999"};
    
    for(string id : testIds){
        bool found = citizenTree.search(id);
        cout << "Search for " << id << ": " << (found ? "Found" : "Not found") << endl;
    }

    cout << "\nStep 5: Interactive search\n";
    string searchId;
    char choice;
    
    do {
        cout << "Enter citizen ID to search (or 'quit' to exit): ";
        cin >> searchId;
        
        if(searchId == "quit") break;
        
        bool found = citizenTree.search(searchId);
        cout << "Citizen ID " << searchId << ": " << (found ? "Found in BST" : "Not found in BST") << endl;
        
        cout << "Search another? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    cout << "\nExercise 5 completed successfully!\n";
    return 0;
}