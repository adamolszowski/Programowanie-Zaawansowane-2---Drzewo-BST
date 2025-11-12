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

bool BST::remove(int value) {
	//przetrzymujemy wskazniki bierzacego wezla oraz jego rodzica
	Node* parent = nullptr;
	Node* current = root;

	// znajdujemy wezel do usuniecia oraz jego rodzica
	while (current && current->value != value) {
		parent = current;
		if (value < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// jak nie ma takiego wezla to przerywamy
	if (!current) {
		return false;
	}

	//    Gdy wêze³ ma i lewe, i prawe dziecko, nie da siê go „po prostu” od³¹czyæ bez z³amania porz¹dku.
	//    Standardowy trik: znajdujemy NASTÊPNIKA in-order (najmniejszy w prawym poddrzewie),
	//    kopiujemy jego wartoœæ do current, a potem usuwamy „oryginalny” wêze³ nastêpnika,
	//    który ma co najwy¿ej JEDNO dziecko. Dziêki temu redukujemy problem do prostszego przypadku.


	if (current->left && current->right) {
		Node* successorParent = current; // rodzic nastêpnika (na start: current)
		Node* successor = current->right; // nastêpnik jest w prawym poddrzewie, skrajnie w lewo

		// Idziemy maksymalnie w lewo — to da nam najmniejszy element w prawym poddrzewie.
		while (successor->left)
		{
			successorParent = successor;
			successor = successor->left;
		}
		// Kopiujemy wartoœæ nastêpnika do bie¿¹cego wêz³a.
		// Struktury nie przepinamy tutaj — tylko wartoœæ.
		current->value = successor->value;

		// A teraz chcemy fizycznie usun¹æ „successora”, który ma 0 lub 1 dziecko.
		// Przestawiamy wskaŸniki pomocnicze, ¿eby poni¿szy kod (dla 0/1 dziecka) dzia³a³ na nim.
		parent = successorParent;
		current = successor;
	}

	// 4) PRZYPADEK „0 lub 1 dziecko”:
	//    W tym miejscu current ma co najwy¿ej jedno dziecko (albo jest liœciem po kroku 3).
	//    Wybieramy to jedyne dziecko (jeœli brak — child = nullptr).
	Node* child = (current->left) ? current->left : current->right;

	// 5) Przepinanie wskaŸników u rodzica:
	//    - Jeœli usuwamy KORZEÑ (parent == nullptr), to po prostu root = child.
	//    - W przeciwnym razie podpinamy child po lewej/prawej stronie rodzica, w miejsce current.
	if (!parent) {
		// Usuwany by³ korzeñ — nowe „wejœcie do drzewa” to to, co by³o jedynym dzieckiem (lub nullptr).
		root = child;
	}
	else if (parent->left == current) {
		parent->left = child;
	}
	else {
		parent->right = child;
	}

	// 6) Sprz¹tanie pamiêci po usuwanym wêŸle.
	delete current;
	return true;
}

void BST::clear() {
	struct clearing {
		static void run(Node* node) {
			if (!node) //nie ma wezlow
			{
				return;
			}

			run(node->left); //lewa galaz
			run(node->right); //prawa galaz
			delete node;
		}
	};
	clearing::run(root);
	root = nullptr; //po czyszczeniu podwezlow, czyscimy korzen
}

BST::~BST() {
	// podczas destrukcji uzywamy cleara do posprzatania pamieci uzytej dla
	// elementow drzewa
	clear();
}

void BST::printPreOrder() const {
	// Preorder (korzeñ -> lewo -> prawo)
	struct printingPreOrder {
		static void run(const Node* node) {
			if (!node) {
				return;
			}

			cout << node->value << " ";
			run(node->left);
			run(node->right);
		}
	};

	printingPreOrder::run(root);
	cout << endl;
}

void BST::printInOrder() const {
	// Inorder (lewo -> korzeñ -> prawo) wypisze wartoœci rosn¹co
	struct printingInOrder {
		static void run(const Node* node) {
			if (!node) {
				return;
			}

			run(node->left);
			cout << node->value << " ";
			run(node->right);
		}
	};

	printingInOrder::run(root);
	cout << endl;
}

void BST::printPostOrder() const {
	// Postorder (lewo -> prawo -> korzeñ)
	struct printingPostOrder {
		static void run(const Node* node) {
			if (!node) {
				return;
			}

			run(node->left);
			run(node->right);
			cout << node->value << " ";
		}
	};

	printingPostOrder::run(root);
	cout << endl;
}
