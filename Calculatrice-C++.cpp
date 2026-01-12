#include <iostream>
#include <limits>

class Calculatrice
{
private:
    double x{}, y{};
    char operation{};

public:
    void input()
    {
        do
        {
            std::cout << "Entrez l'operation (+ - * /) : ";
            std::cin >> operation;
        }
        while (operation != '+' && operation != '-' &&
               operation != '*' && operation != '/');

        std::cout << "Entrez le premier nombre  : ";
        while (!(std::cin >> x))
        {
            std::cout << "Entree invalide. Reessayez : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Entrez le deuxieme nombre : ";
        while (!(std::cin >> y))
        {
            std::cout << "Entree invalide. Reessayez : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    double calcul() const
    {
        switch (operation)
        {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/':
                if (y == 0)
                {
                    std::cout << "Erreur : division par zero\n";
                    return 0;
                }
                return x / y;
            default:
                return 0;
        }
    }

    void result() const
    {
        switch (operation)
        {
            case '+': 
                std::cout << "Somme    : "; 
                break;
            case '-': 
                std::cout << "Reste    : "; 
                break;
            case '*': 
                std::cout << "Produit  : "; 
                break;
            case '/': 
                std::cout << "Quotient : "; 
                break;
        }
        std::cout << calcul() << '\n';
    }
};

int main()
{
    Calculatrice calculatrice;
    calculatrice.input();
    calculatrice.result();
    return 0;
}
