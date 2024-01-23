#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurPublic.hh"

void UtilisateurPublic::acheterTicket(Evenement evenement){
    if (evenement.getType() == "VIP"){
        std::cout << "Vous ne pouvez pas acheter de ticket pour un evenement VIP" << std::endl;
        return;
    }
    else{
        listeTickets.push_back(evenement);
        std::cout << "Ticket achete" << std::endl;
        return;
    }
}