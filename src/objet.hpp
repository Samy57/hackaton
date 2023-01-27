#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Objet {
    public :
        Objet() {}
        Objet (string nom, char symbole, int sante, int force, int defense, int argent) {
            this->nom = nom;
            this->symbole = symbole;
            this->sante = sante;
            this->force = force;
            this->defense = defense;
            this->argent = argent;
        }
        string nom;
        char symbole;
        int sante;
        int force;
        int defense;
        int argent;
};