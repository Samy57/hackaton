#pragma once

#include <vector>
#include <string>
#include <memory>
#include "objet.hpp"

class Personnage{
    virtual int avancer_x(const int pas) = 0;

    virtual int avancer_y(const int pas)=0;

    virtual void print_sante()=0;

    virtual void recevoir_objet( const std::shared_ptr<Objet> objet)=0;

    std::vector<int> get_position();

    std::string get_symbole();

};

class Joueur : public Personnage{
    int avancer_x(int pas );
    int avancer_y(int pas);
    void recevoir_objet(const std::shared_ptr<Objet> objet);
    void print_sante();
};








