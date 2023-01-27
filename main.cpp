#include "keyboard-event.h"
#include"deque"
#include<cmath>
#include <iomanip>
#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{
    
    string chemin_fichier;
    string nom_perso;
    
    cout<<"Comment veux-tu t'appeler petit personnage"<<endl;
    cin>>nom_perso;
    cout<<"Quelle map veux-tu jouer ?"<<endl;
    cin>>chemin_fichier;
    chemin_fichier="./"+chemin_fichier+".txt";
    Game jeu(chemin_fichier,nom_perso);
    char key = 'l';
    bool continuer=true;
    while (continuer)
    {   
        
        
        std::cin >> key;
        

        jeu.update(key);
        if (key == 'q') 
        {
            continuer=false;
            
            
            
        }
       
    }
    std::cout << "Au revoir jeune aventurier" << std::endl;
    return 0;
}