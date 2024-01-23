#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"

Utilisateur::Utilisateur(){
    nom = "";
    prenom = "";
    mail = "";
    telephone = "";
    login = "";
    mdp = "";
    type = "";
}

Utilisateur::Utilisateur(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type){
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->telephone = telephone;
    this->login = login;
    this->mdp = mdp;
    this->type = type;
}

void Utilisateur::annulerTicket(std::string nomEvenement){
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == nomEvenement){
            listeTickets.erase(listeTickets.begin() + i);
        }
    }
}

void Utilisateur::consulterTicket(std::string nomEvenement){
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == nomEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTickets(){
    std::cout << "Liste de vos tickets : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "------------------------------" << std::endl;
    }
}

void Utilisateur::consulterListeTicketsEvenement(std::string nomEvenement){
    std::cout << "Liste de vos tickets pour l'évènement " << nomEvenement << " : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == nomEvenement){
            std::cout << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTicketsDate(std::string dateEvenement){
    std::cout << "Liste de vos tickets pour le " << dateEvenement << " : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getDate() == dateEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTicketsLieu(std::string lieuEvenement){
    std::cout << "Liste de vos tickets pour le lieu " << lieuEvenement << " : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getLieu() == lieuEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTicketsType(std::string typeEvenement){
    std::cout << "Liste de vos tickets pour le sport " << typeEvenement << " : " << std::endl;
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getType() == typeEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "------------------------------" << std::endl;
        }
    }
}


