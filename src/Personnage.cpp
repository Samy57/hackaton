#include <iostream>
#include <string>
#include <memory>
#include <vector>
// #include "objet.hpp"

#include "Personnage.hpp"

std::vector<int> Personnage::get_position()
{
  std::vector<int> position{this->x_, this->y_};
  return position;
}

std::string Personnage::get_symbole()
{
  return this->symbole_;
}

Joueur::Joueur(std::string nom, int x, int y)
{
  this->nom_ = nom;
  this->x_ = x;
  this->y_ = y;
}

int Joueur::avancer_x(const int pas)
{
  return x_ += pas;
}
int Joueur::avancer_y(const int pas)
{
  return y_ += pas;
}

void Joueur::print_sante()
{
  std::cout << "SANTE : " << sante_ << std::endl;
}
