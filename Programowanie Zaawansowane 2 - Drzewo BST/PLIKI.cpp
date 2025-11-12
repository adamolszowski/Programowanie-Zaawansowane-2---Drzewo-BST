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

