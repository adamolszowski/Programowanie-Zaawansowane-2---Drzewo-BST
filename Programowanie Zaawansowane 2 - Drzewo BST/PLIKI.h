#pragma once
/**
 * @file PLIKI.h
 * @brief Deklaracja klasy PLIKI odpowiedzialnej za zapis i odczyt drzew BST z plikow.
 *
 * Klasa udostepnia metody do zapisu oraz wczytywania struktury drzewa BST
 * w formacie tekstowym oraz binarnym. Metody sa statyczne,
 * dzieki czemu mozna z nich korzystac bez tworzenia obiektu klasy.
 */

#pragma once
#include <string>

class BST;

/**
 * @class PLIKI
 * @brief Klasa pomocnicza do obslugi plikow tekstowych i binarnych dla drzewa BST.
 *
 * Klasa zawiera zestaw metod statycznych, ktore umozliwiaja:
 * - wczytanie danych liczbowych z pliku tekstowego i utworzenie drzewa BST,
 * - zapis aktualnego drzewa BST do pliku tekstowego,
 * - zapis drzewa w formacie binarnym (surowe bajty),
 * - ponowne odczytanie danych binarnych do drzewa BST.
 */

class PLIKI {
public:
    /**
     * @brief Wczytuje liczby calkowite z pliku tekstowego i dodaje je do drzewa BST.
     *
     * Plik moze zawierac liczby oddzielone spacjami, tabulatorami lub nowymi liniami.
     * Funkcja wstawia kazda z nich do istniejacego lub pustego drzewa.
     *
     * @param tree Referencja do drzewa BST, do ktorego maja zostac dodane elementy.
     * @param filepath Sciezka do pliku tekstowego.
     * @return true jesli wczytywanie przebieglo pomyslnie, false w przypadku bledu lub pustego pliku.
     */
    static bool wczytajTxt(BST& tree, const std::string& filepath);

    /**
     * @brief Zapisuje zawartosc drzewa BST do pliku tekstowego w kolejnosci preorder.
     *
     * Kazdy wezel drzewa jest zapisywany jako liczba calkowita oddzielona spacja.
     * Format jest czytelny i mozliwy do ponownego wczytania metoda wczytajTxt().
     *
     * @param tree Stala referencja do drzewa BST, ktore ma byc zapisane.
     * @param filepath Sciezka do pliku tekstowego, do ktorego dane zostana zapisane.
     * @return true jesli zapis sie powiodl, false jesli pliku nie udalo sie otworzyc.
     */
    static bool zapiszTxt(const BST& tree, const std::string& filepath);

    /**
     * @brief Zapisuje drzewo BST w postaci binarnej (preorder, surowe bajty typu int).
     *
     * Kazdy wezel jest zapisywany jako 4 bajty (dla standardowego typu int),
     * bez konwersji do tekstu. Format nie jest przeznaczony do edycji w edytorze tekstu.
     *
     * @param tree Stala referencja do drzewa BST.
     * @param filepath Sciezka do pliku binarnego, w ktorym zostanie zapisane drzewo.
     * @return true jesli zapis zakonczyl sie powodzeniem, false w przypadku bledu.
     */
    static bool zapiszBinarnie(const BST& tree, const std::string& filepath);

    /**
     * @brief Wczytuje drzewo BST z pliku binarnego zapisanego metoda zapiszBinarnie().
     *
     * Funkcja odczytuje kolejne liczby calkowite (po 4 bajty) i wstawia je do drzewa BST
     * w tej samej kolejnosci, w jakiej byly wczesniej zapisane (preorder).
     *
     * @param tree Referencja do drzewa BST, do ktorego maja zostac wczytane dane.
     * @param filepath Sciezka do pliku binarnego.
     * @return true jesli odczyt zakonczyl sie sukcesem, false w przypadku bledu.
     */
    static bool wczytajBinarnie(BST& tree, const std::string& filepath);
};