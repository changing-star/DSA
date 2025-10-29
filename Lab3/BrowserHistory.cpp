#include <iostream>
#include <string>
using namespace std;

class WebPage{
    public:
        string url;
        WebPage* next;
        WebPage* prev;
        
        WebPage(string url){
            this->url = url;
            next = nullptr;
            prev = nullptr;
        }
};

class BrowserHistory{
    private:
        WebPage* head;
        WebPage* tail;
        WebPage* current;
        int size;

    public:
        BrowserHistory(){
            head = nullptr;
            tail = nullptr;
            current = nullptr;
            size = 0;
        }

        void visitSite(string url){
            WebPage* newPage = new WebPage(url);

            if(head == nullptr){
                head = newPage;
                tail = newPage;
            } else {
                current->next = newPage;
                newPage->prev = current;
                tail = newPage;
            }

            current = newPage;
            size++;
        }

        bool back(){
            if(current==nullptr || current->prev==nullptr){
                return false;
            }
            current = current->prev;
            return true;
        }

        bool forward(){
            if (current == nullptr || current->next == nullptr) {
                return false;
            }
            current = current->next;
            return true;
        }
};