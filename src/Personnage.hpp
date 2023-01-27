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
  virtual void change_attribut(std::string nom_attribut, int nouvelle_valeur)=0;
  virtual void suivre()=0;

  // virtual void recevoir_objet( const std::shared_ptr<Objet> objet)=0;

  std::vector<int> get_position();

  std::string get_symbole();
  void attaque(const std::shared_ptr<Personnage> attaquant, std::shared_ptr<Personnage> attaque);

protected:
  std::string nom_;
  int sante_;
  std::string symbole_;
  int x_;
  int y_;
  int defense_;
  int attaque_;
};

class Joueur : public Personnage
{
public:
  Joueur(std::string name, int x, int y);
  int avancer_x(int pas);
  int avancer_y(int pas);
  // void recevoir_objet(const std::shared_ptr<Objet> objet);
  void print_sante();
  void change_attribut(std::string nom_attribut, int nouvelle_valeur);

};

class Ennemi : public Personnage
{
    public:
    Ennemi(std::string nom, int x, int y);
    virtual void suivre(std::shared_ptr<Personnage> perso);
    virtual void change_attribut(std::string nom_attribut, int nouvelle_valeur);

};
