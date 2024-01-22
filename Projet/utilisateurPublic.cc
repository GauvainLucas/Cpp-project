#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurPublic.hh"

void UtilisateurPublic::acheterTicket(std::string nomEvenement){

}

void UtilisateurPublic::annulerTicket(std::string nomEvenement){
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == nomEvenement){
            listeTickets.erase(listeTickets.begin() + i);
        }
    }
}