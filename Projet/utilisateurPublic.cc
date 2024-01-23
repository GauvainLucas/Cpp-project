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

UtilisateurPublic::UtilisateurPublic(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type){
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->telephone = telephone;
    this->login = login;
    this->mdp = mdp;
    this->type = type;
}
/*
void UtilisateurPublic::consulterListeTickets(){
    std::cout << "Liste des tickets : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << std::endl;
    }
}*/