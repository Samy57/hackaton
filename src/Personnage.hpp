#pragma once

#include <vector>
#include <string>
#include <memory>
// #include "objet.hpp"

class Personnage
{
public:
  virtual int avancer_x(const int pas) = 0;

  virtual int avancer_y(const int pas) = 0;

  virtual void print_sante() = 0;

  // virtual void recevoir_objet( const std::shared_ptr<Objet> objet)=0;

  std::vector<int> get_position();

  std::string get_symbole();

protected:
  std::string nom_;
  int sante_;
  std::string symbole_;
  int x_;
  int y_;
  int defense_;
};

class Joueur : public Personnage
{
public:
  Joueur(std::string name, int x, int y);
  int avancer_x(int pas);
  int avancer_y(int pas);
  // void recevoir_objet(const std::shared_ptr<Objet> objet);
  void print_sante();
};

class Ennemi : public Personnage
{
};
