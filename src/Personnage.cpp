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

void Joueur::change_attribut( std::string nom_attribut, int nouvelle_valeur){
        if (nom_attribut=="sante_"){
            this -> sante_=nouvelle_valeur;
        }
        else if (nom_attribut=="defense_"){
            this -> defense_=nouvelle_valeur;
        }
        else {
            this -> attaque_=nouvelle_valeur;
        }
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




Ennemi::Ennemi (std::string nom, int x, int y) { 
    this ->nom_=nom;
    this -> x_ =x;
    this -> y_=y;
    }


void Ennemi::suivre(){

    }

void Ennemi::change_attribut(std::string nom_attribut, int nouvelle_valeur){
        if (nom_attribut=="sante_"){
            this -> sante_=nouvelle_valeur;
        }
        else if (nom_attribut=="defense_"){
            this -> defense_=nouvelle_valeur;
        }
        else {
            this -> attaque_=nouvelle_valeur;
        }
    }

void Personnage::attaque(const std::shared_ptr<Personnage> attaquant, std::shared_ptr<Personnage> attaque){
        int s1; //santé attaquant
        int s2; //santé attaqué
        int a1; //attaque de l'attaquant
        int d2; //défense de l'attaqué
        s1=attaquant -> sante_;
        s2=attaque -> sante_;
        a1=attaquant ->attaque_;
        d2=attaque -> defense_;
        s2= s2 - a1 *( 20 - d2)/20;
        attaque->change_attribut("sante_", s2);
    }