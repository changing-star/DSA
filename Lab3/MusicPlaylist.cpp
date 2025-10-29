#include <iostream>
using namespace std;

class MusicItem{
    public:
        int position;
        string songName;
        MusicItem* next;

        MusicItem (int position, string songName){
            this->position = position;
            this->songName = songName;
            next = nullptr;
        }
};

class MusicPlaylist{
    private:
        MusicItem* head;
        MusicItem* tail;
        MusicItem* current;
        int size;
        
    public:
        MusicPlaylist() {
            head = nullptr;
            tail = nullptr;
            current = nullptr;
            size = 0;
        }

        void addSong(int pos, string songName){
            MusicItem* newNode = new MusicItem(pos, songName);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                tail->next = head;
                current = head;
            } else {
                tail->next = newNode;
                newNode->next = head;
                tail = newNode;
            }
            size++;
        }

        void playNext(){
            if(current == nullptr) return;
            cout << "Now playing: " << current->songName << " (Position: " << current->position << ")\n";
            current = current->next;
        }
        void display(){
            if (head == nullptr) return;
            MusicItem *t = head;
            do {
                cout << t->position << " -> ";
                t = t->next;
            } while (t != head);
            cout << "(back to head)\n";
        }

};

int main(){
    MusicPlaylist playlist;

    playlist.addSong(1, "ee");
    playlist.addSong(2, "eeee");

    for (int i = 0; i < 4; i++) {
        playlist.playNext();
    }
    
    playlist.display();
}