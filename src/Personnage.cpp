#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "objet.hpp"
#include "Personnage.hpp"

class Personnage{
    public:
    //Personnage(std::string nom, int x, int y) : nom_{nom}, x_{x}, y_{y}{};

    virtual int avancer_x(const int pas)=0;

    virtual int avancer_y(const int pas)=0;

    virtual void print_sante()=0;

    virtual void recevoir_objet( const std::shared_ptr<Objet> objet)=0;
    virtual void suivre(const std::shared_ptr<Personnage> perso)=0;
    virtual void change_attribut(std::string nom_attribut, int nouvelle_valeur)=0;

    void attaque(const std::shared_ptr<Personnage> attaquant, std::shared_ptr<Personnage> attaque){
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
    };

    std::vector<int> get_position(){
        std::vector<int> position{x_,y_};
        return position;
    };
    std::string get_symbole(){
        return symbole_;
    };


    protected:
    std::string nom_;
    int sante_;
    std::string symbole_;
    int x_;
    int y_;
    int defense_;
    int attaque_;
  

};




class Joueur : public Personnage {
    public:
    Joueur(std::string nom, int x, int y): nom_{nom}, x_{x}, y_{y}{};

    virtual int avancer_x(const int pas){
        return x_+=pas;
    }
    virtual int avancer_y(const int pas){
        return y_+=pas;
    }

    virtual void change_attribut( std::string nom_attribut, int nouvelle_valeur){
        if (nom_attribut=="sante_"){
            sante_=nouvelle_valeur;
        }
        else if (nom_attribut=="defense_"){
            defense_=nouvelle_valeur;
        }
        else {
            attaque_=nouvelle_valeur;
        }
    }

    

    virtual void recevoir_objet(const std::shared_ptr<Objet> objet){
        sante_+=objet ->sante;
        defense_+=objet ->defense;

    }




    virtual void print_sante(){
        std::cout<<sante_<<std::endl;
    }



    protected:
    std::string nom_;
    int sante_{5};
    std::string symbole_{"@"};
    int x_;
    int y_;
    int defense_{};
    int attaque_{};


};


class Ennemi : public Personnage {
    public:
    Ennemi (std::string nom, int x, int y) : nom_{nom}, x_{x}, y_{y}{};

    virtual void suivre(){

    }

    virtual void change_attribut(std::string nom_attribut, int nouvelle_valeur){
        if (nom_attribut=="sante_"){
            sante_=nouvelle_valeur;
        }
        else if (nom_attribut=="defense_"){
            defense_=nouvelle_valeur;
        }
        else {
            attaque_=nouvelle_valeur;
        }
    }

    protected:
    int x_;
    int y_;
    int sante_;
    std::string symbol_;
    std::string nom_;
    int defense_;
    int attaque_;
};