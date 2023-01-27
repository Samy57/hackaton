#include "game.h"
#include "playboard.h"
#include"deque"
#include<cmath>
#include <iomanip>
#include <iostream>
using namespace std;

deque <int> positions;

void play_game()
{
    
    string chemin_fichier;
    string nom_perso;
    
    cout<<"Comment veux-tu t'appeler petit personnage"<<endl;
    cin>>nom_perso;
    cout<<"Quelle map veux-tu jouer"<<endl;
    cin>>chemin_fichier;
    chemin_fichier="./"+chemin_fichier+".txt";
    Game jeu(chemin_fichier,nom_perso);
    // le jeu est une boucle sans fin
    // qu'on temporise d'un 'delay' de ms entre deux mouvements du serpent
    // (on règle comme cela la vitesse du serpent)

    // la clé qui sera entrée au clavier
    char key = 'l';
    while (true)
    {   
        
        
        // on temporise un tour jei

        // si un caractère a été entré
        // on le lit sinon ça continue
        if (keyEvent())
        {
            std::cin >> key;
        }

        Game.update(key);
        if (key == 'q') // on veut quitter la partie
        {
            backgroundClear();
            std::cout << "see you soon little snake !" << std::endl;
            exit(1);
        }
       
        
        // et là on fait les actions...
        // déplacement du serpent...
        // le serpent mange la pomme
    }
}