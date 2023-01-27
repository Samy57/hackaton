#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <utility>
#include "sys/ioctl.h"
const char *cmd_clear = "clear";

#include "personnage.hpp"
#include "objet.hpp"

Game::Game(std::string nom_carte, std::string nom_joueur)
{
  // Chargement de la carte
  std::ifstream fichier(nom_carte, ios::in); // on ouvre le fichier en lecture

  if (fichier) // si l'ouverture a réussi
  {
    fichier.get(this->carte_x);
    fichier.get(this->carte_y);
    int spawn_x;
    int spawn_y;
    fichier.get(spawn_x);
    fichier.get(spawn_y);
    char a;
    for (int i = 0, i < this->carte_x * this->carte_y, i++)
    {
      fichier.get(a);
      this->carte.push_back(a);
      this->visibilite.push_back(false); // au départ toutes les cases sont cachées
    }

    fichier.close(); // on ferme le fichier
  }
  else // sinon
    std::cout << "Impossible d'ouvrir le fichier carte " << nom_carte << std::endl;

  // Création du joueur
  this->joueur = std::make_shared<Joueur>(nom_joueur, spawn_x, spawn_y);
}

void Game::affichage()
{
  // background clear
  int out = system(cmd_clear);
  if (out != 0)
  {
    std::cerr << "clear command failed" << std::endl;
    exit(1);
  }

  std::vector<std::string> carte_affiche{this->carte};

  carte_affiche[this->joueur.get_position[0] + this->carte_x * this->joueur.get_position[1]] = joueur.get_symbole();

  for (auto e : ennemis)
  {
    carte_affiche[this->e.get_position[0] + this->carte_x * this->e.get_position[1]] = e.get_symbole();
  }

  for (int i = 0, i < this->carte_x, i++)
  {
    std::cout << "▬"
  }

  this->Joueur->AFFICHE_ETATS
}

bool Game::update(char a)
{

  this->affichage();

  return True;
}