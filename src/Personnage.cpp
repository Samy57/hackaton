#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "objet.hpp"

class Personnage{
    public:
    //Personnage(std::string nom, int x, int y) : nom_{nom}, x_{x}, y_{y}{};

    virtual int avancer_x(const int pas)=0;

    virtual int avancer_y(const int pas)=0;

    virtual void print_sante()=0;

    virtual void recevoir_objet( const std::shared_ptr<Objet> objet)=0;

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
    int defense_;


};