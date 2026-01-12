class Calculatrice:
    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        self.operation = ""

    def input(self):
        while self.operation not in ['+', '-', '*', '/']:
            self.operation = input("Entrez l'operation (+ - * /) : ")

        while True:
            try:
                self.x = float(input("Entrez le premier nombre  : "))
                self.y = float(input("Entrez la deuxième nombre : "))
                break
            except ValueError:
                print("Erreur, ce n'est pas un nombre. Reessayez.")

    def calcul(self):
        match self.operation:
            case '+': return self.x + self.y
            case '-': return self.x - self.y
            case '*': return self.x * self.y
            case '/':
                if self.y == 0:
                    print("Erreur : division par 0")
                    return None
                return self.x / self.y

    def result(self):
        res = self.calcul()
        if res is None:
            return
        match self.operation:
            case '+': print("Somme    : ", end="")
            case '-': print("Reste    : ", end="")
            case '*': print("Produit  : ", end="")
            case '/': print("Quotient : ", end="")
        print(f"{res:g}")


def main():
    calculatrice = Calculatrice()
    calculatrice.input()
    calculatrice.result()


if __name__ == '__main__':
    main()
