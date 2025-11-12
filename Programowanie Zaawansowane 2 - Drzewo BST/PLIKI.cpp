#include "PLIKI.h"
#include "BST.h"
#include <fstream>
#include <iostream>

bool PLIKI::wczytajTxt(BST& tree, const std::string& filepath) {
	std::ifstream in(filepath); // otwieramy plik do czytania, spacje i entery sa jako separatory
	if (!in)
	{
		std::cout << "Nie mozna otworzyc pliku" << filepath << "\n";
		return false;
	}

	int count = 0; // licznik ilosci liczb w pliku
	int x;

	while (in >> x) // czytanie liczb z pliku
	{
		tree.insert(x); // dodawanie liczb do drzewa z uzyciem metody klasy BST
		++count;
	}

	if (count == 0)
	{
		std::cout << "Plik otwarto, ale nie znaleziono liczb calkowitych" << std::endl;
		return false;
	}

	std::cout << "Wczytano liczby z \"" << filepath << "\"." << std::endl;
	return true;
}

bool PLIKI::zapiszTxt(const BST& tree, const std::string& filepath) {
	std::ofstream out(filepath); // otwarcie lub zalozenie nowego pliku
	if (!out) {
		return false;
	}

	struct W {
		static void run(BST::Node* node, std::ofstream& out) { //metoda rekurencyjne przechodzi po drzewie
			if (!node) {
				return;
			}

			out << node->value << ' '; // dzialanie jak preorder, liczby oddzielone spacjami
			run(node->left, out); // dzialanie jak preorder
			run(node->right, out); // dzialanie jak preorder
		}
	};
	W::run(tree.root, out); // zaczynamy od roota drzewa
	return true;
}

bool PLIKI::zapiszBinarnie(const BST& tree, const std::string& filepath) {
	std::ofstream out(filepath, std::ios::binary);
	if (!out) {
		return false;
	}

	struct W {
		static void run(const BST::Node* node, std::ofstream& out) {
			if (!node) {
				return;
			}

			int v = node->value; // dzialanie jak preorder
			out.write(reinterpret_cast<const char*>(&v), sizeof(v)); //zapisujemy wszystkie bajty 
			//które s¹ pod adresem na który
			//wskazuje &v, reinterpret_cast pozwala patrzec na to co wskazuje 
			// &v jak tablice bajtow, traktujemy pamiec v jako ciag bajtow
			//aby write moglo to zapisac
			run(node->left, out); // dzialanie jak preorder
			run(node->right, out); // dzialanie jak preorder
		}
	};

	W::run(tree.root, out);
	return true;
}

bool PLIKI::wczytajBinarnie(BST& tree, const std::string& filepath) {
	std::ifstream in(filepath, std::ios::binary);
	if (!in) {
		return false;
	}

	int v;
	while (in.read(reinterpret_cast<char*>(&v), sizeof(v))) { //wczytuj dopoki udaje sie 
		//odczytywac wszystkie bajty danej liczby do v
		//traktujemy ten adres (&v) jak wskaznik na ciag bajtow, 
		// dzieku temu read kopiuje do v te bajty
		tree.insert(v);  // dopisuje do istniej¹cego drzewa z uzyciem metody klasy BST
	}
	return true;
}