#include <iostream>
#include "BST.h"
#include "PLIKI.h"
using namespace std;


int main() {

    bool programRunning = true;
    BST tree;

    while (programRunning) {

        int userSelection;
        cout << "\n -------- Menu --------" << endl;
        cout << "1 - Dodaj element" << endl;
        cout << "2 - Usun element" << endl;
        cout << "3 - Wyczysc cale drzewo" << endl;
        cout << "4 - Szukaj drogi do danego elementu" << endl;
        cout << "5 - Wyswietl [preorder]" << endl;
        cout << "6 - Wyswietl [inorder]" << endl;
        cout << "7 - Wyswietl [postorder]" << endl;
        cout << "8 - Wczytaj z pliku txt" << endl;
        cout << "9 - Zapisz do pliku txt" << endl;
        cout << "10 - Wczytaj z pliku [binarnie]" << endl;
        cout << "11 - Zapisz do pliku [binarnie]" << endl;
        cout << "12 - Wyjdz" << endl;
        cin >> userSelection;

        switch (userSelection) {
        case 1:
            int elementToInsert;
            cout << "Wpisz wartosc elementu do wstawienia: ";
            cin >> elementToInsert;

            if (tree.insert(elementToInsert))
            {
                cout << "Udalo sie wstawic element " << elementToInsert << endl;
            }
            else {
                cout << "Wstawianie nie powiodlo sie";
            }
            break;

        case 2:
            int elementToRemove;
            cout << "Wpisz wartosc elementu do usuniecia: ";
            cin >> elementToRemove;

            if (tree.remove(elementToRemove))
            {
                cout << "Udalo sie usunac element " << elementToRemove << endl;
            }
            else {
                cout << "Usuwanie nie powiodlo sie";
            }

            break;

        case 3:
            tree.clear();
            break;

        case 4:
            int element;
            cout << "Wpisz wartosc szukanego elementu: ";
            cin >> element;
            tree.findPath(element);
            break;

        case 5:
            cout << "\n[Drzewo]" << endl;
            tree.drawTree();
            cout << "\n[preorder]" << endl;
            tree.printPreOrder();
            break;

        case 6:
            cout << "\n[Drzewo]" << endl;
            tree.drawTree();
            cout << "\n[inorder]" << endl;
            tree.printInOrder();
            break;

        case 7:
            cout << "\n[Drzewo]" << endl;
            tree.drawTree();
            cout << "\n[postorder]" << endl;
            tree.printPostOrder();
            break;

        case 8: {
            cout << "\nPodaj sciezke pliku txt do wczytania: \n";
            string filePath;
            cin >> filePath;
            PLIKI::wczytajTxt(tree, filePath);
            break;
        }

        case 9: {
            cout << "\nPodaj sciezke pliku TXT do zapisania: ";
            string filePath;
            cin >> filePath;
            if (PLIKI::zapiszTxt(tree, filePath))
                cout << "Zapisano TXT.\n";
            else
                cout << "Zapis TXT nie powiodl sie.\n";
            break;
        }

        case 10: {
            cout << "\nPodaj sciezke pliku BIN do wczytania: ";
            string filePath;
            cin >> filePath;
            if (PLIKI::wczytajBinarnie(tree, filePath))
                cout << "Wczytano BIN.\n";
            else
                cout << "Wczytanie BIN nie powiodlo sie.\n";
            break;
        }

        case 11: {
            cout << "\nPodaj sciezke pliku BIN do zapisania: ";
            string filePath;
            cin >> filePath;
            if (PLIKI::zapiszBinarnie(tree, filePath))
                cout << "Zapisano BIN.\n";
            else
                cout << "Zapis BIN nie powiodl sie.\n";
            break;
        }

        case 12:
            cout << "wybrales 12" << endl;
            programRunning = false;
            break;
        }
    }

    return 0;
}


