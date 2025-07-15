#include "LinkedList.hpp"
#include "BinaryTree.hpp"

int main() {
    Song s1("Numb", "Linkin Park");
    Song s2("Blinding Lights", "The Weeknd");
    Song s3("Bohemian Rhapsody", "Queen");

    // Linked List Test
    LinkedList playlist;
    playlist.add(s1);
    playlist.add(s2);
    playlist.add(s3);

    cout << "Linked List Playlist:\n";
    Iterator* it1 = playlist.getIterator();
    while (it1->hasNext()) {
        it1->next().display();
    }
    delete it1;

    // Binary Tree Test
    BinaryTree songTree;
    songTree.insert(s1);
    songTree.insert(s2);
    songTree.insert(s3);

    cout << "\nBinary Tree Playlist (In-Order):\n";
    Iterator* it2 = songTree.getIterator();
    while (it2->hasNext()) {
        it2->next().display();
    }
    delete it2;

    return 0;
}
