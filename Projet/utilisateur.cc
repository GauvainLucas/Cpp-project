#include <iostream>
#include <string>
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

Utilisateur::Utilisateur(const Utilisateur &user){
    nom = user.nom;
    prenom = user.prenom;
    mail = user.mail;
    telephone = user.telephone;
    login = user.login;
    mdp = user.mdp;
    type = user.type;
}

/*int Utilisateur::annulerTicket(Evenement evenement){
    for (int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == evenement.getNom()){
            listeTickets.erase(listeTickets.begin() + i);
            return 1;
        }
    }
    return 0;
}*/


void Utilisateur::consulterTicket(Evenement evenement) {
    std::cout << "Nom : " << evenement.getNom() << "\n" << "Date : " << evenement.getDate() << "\n" << "Lieu : "
              << evenement.getLieu() << "\n" << "Description : " << evenement.getDescription() << "\n" << "Type : "
              << evenement.getType() << std::endl;
}
void Utilisateur::consulterListeTickets(){
    std::cout << "Liste de vos tickets : " << std::endl;
    for (u_int i = 0; i < listeTickets.size(); i++){
        std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "\n------------------------------" << std::endl;
    }
}

void Utilisateur::consulterListeTicketsEvenement(std::string nomEvenement){
    std::cout << "Liste de vos tickets pour l'évènement " << nomEvenement << " : " << std::endl;
    for (u_int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getNom() == nomEvenement){
            std::cout << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "\n------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTicketsDate(std::string dateEvenement){
    std::cout << "Liste de vos tickets pour le " << dateEvenement << " : " << std::endl;
    for (u_int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getDate() == dateEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "\n------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTicketsLieu(std::string lieuEvenement){
    std::cout << "Liste de vos tickets pour le lieu " << lieuEvenement << " : " << std::endl;
    for (u_int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getLieu() == lieuEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << "\n------------------------------" << std::endl;
        }
    }
}

void Utilisateur::consulterListeTicketsType(std::string typeEvenement){
    std::cout << "Liste de vos tickets pour le sport " << typeEvenement << " : " << std::endl;
    for (u_int i = 0; i < listeTickets.size(); i++){
        if (listeTickets[i].getType() == typeEvenement){
            std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu() << "\n" << listeTickets[i].getDescription() << "\n------------------------------" << std::endl;
        }
    }
}

int Utilisateur::annulerTicket(Evenement evenement) {
    for (u_int i = 0; i < listeTickets.size(); i++) {
        if (listeTickets[i].getNom() == evenement.getNom()) {
            listeTickets.erase(listeTickets.begin() + i);
            return 1;
        }
    }
    return 0;
}

void Utilisateur::modifierNom(std::string nom){
    this->nom = nom;
}

void Utilisateur::modifierPrenom(std::string prenom){
    this->prenom = prenom;
}

void Utilisateur::modifierMail(std::string mail){
    this->mail = mail;
}

void Utilisateur::modifierTelephone(std::string telephone){
    this->telephone = telephone;
}

void Utilisateur::modifierLogin(std::string login){
    this->login = login;
}

void Utilisateur::modifierMdp(std::string mdp){
    this->mdp = mdp;
}

void Utilisateur::modifierType(std::string type){
    this->type = type;
}


