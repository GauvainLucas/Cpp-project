#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurPublic.hh"
#include "utilisateur.hh"

UtilisateurPublic::UtilisateurPublic(){
    nom = "";
    prenom = "";
    mail = "";
    telephone = "";
    login = "";
    mdp = "";
    type = "";
}

/*UtilisateurPublic::UtilisateurPublic(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type){
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->telephone = telephone;
    this->login = login;
    this->mdp = mdp;
    this->type = type;
}*/

int UtilisateurPublic::acheterTicket(Evenement evenement){
    if (evenement.getType() == "VIP"){
        std::cout << "Vous ne pouvez pas acheter de ticket pour un evenement VIP" << std::endl;
        return 0;
    }
    else{
        listeTickets.push_back(evenement);
        std::cout << "Ticket achete" << std::endl;
        return 1;
    }
}

void UtilisateurPublic::annulerTicket(Evenement evenement){
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == evenement.getNom()){
            listeTickets.erase(listeTickets.begin()+i);
        }
    }
}

void UtilisateurPublic::consulterTicket(Evenement evenement) {
    std::cout << "Nom : " << evenement.getNom() << "\n" << "Date : " << evenement.getDate() << "\n" << "Lieu : "
              << evenement.getLieu() << "\n" << "Description : " << evenement.getDescription() << "\n" << "Type : "
              << evenement.getType() << std::endl;
}

void UtilisateurPublic::consulterListeTickets() {
    std::cout << "Liste des tickets : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++) {
        std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu()
                  << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << std::endl;
    }
}
/*void UtilisateurPublic::acheterTicket(Evenement evenement){
    if (evenement.getType() == "VIP"){
        std::cout << "Vous ne pouvez pas acheter de ticket pour un evenement VIP" << std::endl;
        return;
    }
    else{
        listeTickets.push_back(evenement);
        std::cout << "Ticket achete" << std::endl;
        return;
    }
}*/