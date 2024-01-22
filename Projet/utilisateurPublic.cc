#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurPublic.hh"

void UtilisateurPublic::consulterListeTickets(){
    std::cout << "Liste des tickets : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << std::endl;
    }
}