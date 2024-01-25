#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurVIP.hh"

int UtilisateurVIP::acheterTicket(Evenement evenement){
    if (evenement.getType() == "VIP"){
        listeTicketsVIP.push_back(evenement);
        std::cout << "Ticket VIP achete" << std::endl;
        return 1;
    }
    else{
        listeTickets.push_back(evenement);
        std::cout << "Ticket achete" << std::endl;
        return 2;
    }
}

void UtilisateurVIP::consulterListeTicketsVIP(){
    std::cout << "Liste de vos tickets VIP : " << std::endl;
    for (int i = 0; i < listeTicketsVIP.size(); i++){
        std::cout << listeTicketsVIP[i].getNom() << "\n" << listeTicketsVIP[i].getDate() << "\n" << listeTicketsVIP[i].getLieu() << "\n" << listeTicketsVIP[i].getDescription() << "\n" << listeTicketsVIP[i].getType() << "\n------------------------------" << std::endl;
    }
}