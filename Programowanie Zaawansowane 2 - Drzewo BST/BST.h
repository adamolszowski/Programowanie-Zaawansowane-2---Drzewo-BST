/**
 * @file BST.h
 * @brief Deklaracja prostej implementacji drzewa BST (Binary Search Tree) dla liczb calkowitych.
 *
 * Drzewo przechowuje wartosci typu int i wspiera operacje:
 * - wstawianie (insert),
 * - usuwanie (remove),
 * - czyszczenie calej struktury (clear),
 * - wypisywanie w porzadkach: preorder / inorder / postorder,
 * - proste rysowanie drzewa w konsoli (drawTree),
 * - wypisanie sciezki od korzenia do podanej wartosci (findPath).
 *
 */

#pragma once

 /**
  * @class BST
  * @brief Prosta klasa BST (Binary Search Tree) dla wartosci typu int.
  *
  * Implementacja oparta o wskazniki. Pamiec zaalokowana dla wezlow jest zwalniana
  * w destruktorze poprzez wywolanie metody clear() (RAII � brak wyciekow pamieci).
  */

class BST {
public:
	/**
	 * @brief Tworzy puste drzewo BST.
	 */
	BST() = default;

	/**
	 * @brief Destruktor � zwalnia wszystkie wezly drzewa.
	 *
	 * Wola wewnetrznie clear(), dzieki czemu po zniszczeniu obiektu BST
	 * nie pozostaja zadne niezwracone zasoby pamieci.
	 */
	~BST();

	/**
	 * @brief Wstawia wartosc do drzewa BST.
	 *
	 * Wartosci mniejsze trafiaja do lewego poddrzewa, wieksze do prawego.
	 * Duplikaty sa ignorowane (brak wstawienia, zwracane false).
	 *
	 * @param value Wartosc do wstawienia.
	 * @return true jesli wstawiono nowy wezel; false jesli wartosc juz istniala.
	 *
	 */
	bool insert(int value);

	/**
	 * @brief Usuwa z drzewa wezel o podanej wartosci (jesli istnieje).
	 *
	 * Obslugiwane sa trzy przypadki:
	 * - wezel-lisc (0 dzieci),
	 * - wezel z 1 dzieckiem,
	 * - wezel z 2 dziecmi (podmiana wartosci na nastepnika in-order, a nastepnie usuniecie nastepnika).
	 *
	 * @param value Szukana wartosc do usuniecia.
	 * @return true jesli wezel zostal znaleziony i usuniety; false w przeciwnym razie.
	 *
	 */
	bool remove(int value);

	/**
	 * @brief Usuwa wszystkie wezly drzewa (postorder) i ustawia root na nullptr.
	 *
	 * Po wywolaniu drzewo jest puste.
	 *
	 */
	void clear();

	/**
	 * @brief Wypisuje wartosci drzewa w porzadku preorder (korzen, lewo, prawo).
	 *
	 * Wynik trafia na standardowe wyjscie (std::cout), wartosci sa rozdzielone spacja,
	 * a po zakonczeniu wypisywania dodawany jest znak nowej linii.
	 */
	void printPreOrder() const;

	/**
	 * @brief Wypisuje wartosci drzewa w porzadku inorder (lewo, korzen, prawo).
	 *
	 * Dla poprawnego BST otrzymujemy ciag wartosci rosnaco.
	 * Wynik trafia na std::cout, zakonczony znakiem nowej linii.
	 */
	void printInOrder() const;

	/**
	 * @brief Wypisuje wartosci drzewa w porzadku postorder (lewo, prawo, korzen).
	 *
	 * Wynik trafia na std::cout, zakonczony znakiem nowej linii.
	 */
	void printPostOrder() const;

	/**
	 * @brief Rysuje drzewo znakowo w konsoli (prosty widok: prawa galaz �nad� lewa).
	 *
	 * Funkcja pomocna do szybkiej wizualnej inspekcji struktury drzewa.
	 * Kazdy poziom jest wciety stala liczba spacji.
	 */
	void drawTree() const;

	/**
	 * @brief Wypisuje sciezke od korzenia do pierwszego napotkanego wezla o wartosci `value`.
	 *
	 * Jesli wartosc nie istnieje, wypisywany jest komunikat �Nie istnieje�.
	 *
	 * @param value Szukana wartosc.
	 * @return true jesli wartosc zostala znaleziona; false w przeciwnym razie.
	 *
	 * @note Sciezka wypisywana jest w formacie: a -> b -> c.
	 */
	bool findPath(int value) const;

private:
	friend class PLIKI;

	/**
	 * @struct Node
	 * @brief Pojedynczy wezel drzewa BST.
	 *
	 * Przechowuje wartosc typu int oraz wskazniki do lewego i prawego dziecka.
	 */
	struct Node {
		int value; /**< Przechowywana wartosc. */
		Node* left; /**< Wskaznik na lewe dziecko (mniejsze wartosci). */
		Node* right; /**< Wskaznik na prawe dziecko (wieksze wartosci). */

		/**
		 * @brief Tworzy wezel z dana wartoscia i pustymi dziecmi.
		 * @param v Wartosc poczatkowa wezla.
		 */
		explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
	};

	/**
	 * @brief Wskaznik na korzen drzewa (nullptr, gdy drzewo puste).
	 */
	Node* root = nullptr;


};