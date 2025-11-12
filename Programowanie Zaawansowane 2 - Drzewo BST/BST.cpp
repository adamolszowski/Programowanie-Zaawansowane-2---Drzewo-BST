#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

bool BST::insert(int value) {
	if (root == nullptr) // jesli drzewo puste to robimy korzen
	{
		root = new Node(value);
		return true;
	}

	Node* current = root; // jesli drzewo nie puste to ustawiamy roota na badany element
	while (true)
	{
		if (value == current->value) { // zapobiegamy utworzeniu dwóch takich samych elementow
			return false;
		}

		else if (value < current->value) { // idziemy w lewo jesli mniejsze
			if (current->left)
			{
				current = current->left; // jesli obecny ma lewy to ustawiamy obecnego na jego lewego
			}
			else { // jesli z lewej pusto to robimy nowy element
				current->left = new Node(value);
				return true;
			}
		}

		else { // idziemy nie w lewo to w prawo
			if (current->right)
			{
				current = current->right; // jesli obecny ma prawy to ustawiamy obecnego na jego prawego
			}
			else { // jesli z prawej pusto to robimy nowy element
				current->right = new Node(value);
				return true;
			}
		}
	}
}

