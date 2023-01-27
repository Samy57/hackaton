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

bool is_in(string nom, vector<Objet> armure_equiped) {
    for (int i = 0; i< static_cast<int>(armure_equiped.size()); i++) {
        if (armure_equiped[i].nom == nom) {
            return true;
        }
    }
    return false;
}

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

class Inventaire {
    public :
        Inventaire() {}
        Inventaire(vector<Objet> arme_inventaire, Objet arme_equiped, vector<Objet> armure_inventaire, vector<Objet> armure_equiped) {
            this->arme_inventaire = arme_inventaire;
            this->arme_equiped = arme_equiped;
            this->armure_inventaire = armure_inventaire;
            this->armure_equiped = armure_equiped;
        }
        vector<Objet> arme_inventaire;
        Objet arme_equiped;
        vector<Objet> armure_inventaire;
        vector<Objet> armure_equiped;
        void equipe_arme(Objet arme) {
            this->arme_equiped = arme;
        }
        void equipe_armure(Objet armure) {
            armure_equiped.push_back(armure);
        }
};

int main(){
    Inventaire inventaire;
    inventaire.arme_inventaire.push_back(vieille_epee);
    inventaire.arme_inventaire.push_back(epee);
    inventaire.arme_inventaire.push_back(epee_de_la_mort);
    inventaire.equipe_arme(vieille_epee);
    inventaire.armure_inventaire.push_back(casque);
    inventaire.armure_inventaire.push_back(armure);
    inventaire.armure_inventaire.push_back(botes);
    for (int i = 0; i< static_cast<int>(inventaire.arme_inventaire.size()); i++) {
        if (inventaire.arme_inventaire[i].nom == inventaire.arme_equiped.nom) {
            cout << "V ";
        }
        else {cout << "X ";}
        cout << inventaire.arme_inventaire[i].nom << "  ";
    }
    cout << endl;

    for (int i = 0; i< static_cast<int>(inventaire.armure_inventaire.size()); i++) {
        if (is_in(inventaire.armure_inventaire[i].nom, inventaire.armure_equiped)){
            cout << "V ";
        }
        else {cout << "X ";}
        cout << inventaire.armure_inventaire[i].nom << "  ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}