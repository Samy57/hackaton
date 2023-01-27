#include <iostream>
#include <string>

using namespace std;

class Objet {
    public :
        Objet (string nom, char symbole, int sante, int force, int defense, int argent) {
            this->nom = nom;
            this->symbole = symbole;
            this->sante = sante;
            this->force = force;
            this->defense = defense;
            this->argent = argent;
        }
    protected :
        string nom;
        char symbole;
        int sante;
        int force;
        int defense;
        int argent;
};

// potions 
Objet petite_potion("petite_potion", 'j', 5, 0, 0, 0);
Objet grande_potion("grande_potion", 'J', 10, 0, 0, 0);

// armures
Objet casque("casque", 'c', 0, 0, 5, 0);
Objet armure("armure", 'a', 0, 0, 10, 0);
Objet botes("bottes", 'b', 0, 0, 3, 0);

// armes
Objet vieille_epee("vieille_epee", 'e', 0, 5, 0, 0);
Objet epee("epee", 'E', 0, 10, 0, 0);
Objet epee_de_la_mort("epee_de_la_mort", 'M', 0, 20, 0, 0);

// argent
Objet piece("piece", '*', 0, 0, 0, 5);
Objet sac_de_piece("sac_de_piece", '$', 0, 0, 0, 20);