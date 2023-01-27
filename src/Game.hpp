#pragma once

#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <utility>
#include "sys/ioctl.h"

#include "Personnage.hpp"
#include "objet.hpp"

class Game
{

public:
  Game(std::string nom_carte, std::string nom_joueur);
  void affichage;
  bool update(char user_cmd); // qui appelera affichage

protected:
  std::vector<std::shared_ptr<Objet>> objets;
  std::vector<std::string> carte;
  std::vector<bool> visibilite;
  int carte_y; // taille de la carte en x
  int carte_x; //  -   -  -    -     en y
  std::shared_ptr<Joueur> joueur;
  std::vector<std::shared_ptr<Ennemi>> ennemis;
};