#include <iostream>
#include"Personnage.hpp"

std::vector<int> deplacement (){
    std::vector<int> deplace;
char input = std::cin.get();
        if(input == '\x1b') {
            std::cin.get();
            char arrow = std::cin.get();
            if(arrow == 'D') {
                deplace.push_back(-1);
                deplace.push_back(0);
                return deplace;
            }
            else if(arrow == 'A') {
                deplace.push_back(0);
                deplace.push_back(-1);
                return deplace;
            }
            else if(arrow == 'B') {
                deplace.push_back(0);
                deplace.push_back(1);
                return deplace;
            }

            else {
                deplace.push_back(1);
                deplace.push_back(0);
                return deplace;

            }
        }
    
}

bool autorisation_deplacement(int x,int y,std::vector<int> deplacement){
    int deplacement_x =deplacement.front();
    int deplacement_y =deplacement.back();
    if (map[x+15*y+deplacement_x+15*deplacement_y]=="|"){
        return false;
    }

    if (map[x+15*y+deplacement_x+15*deplacement_y]=="-"){
        return false;
    }

    return true;

}
