#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurPublic.hh"
#include "utilisateur.hh"

UtilisateurPublic::UtilisateurPublic() {
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

int UtilisateurPublic::acheterTicket(Evenement evenement) {
    if (evenement.getType() == "VIP") {
        std::cout << "Vous ne pouvez pas acheter de ticket pour un evenement VIP" << std::endl;
        return 0;
    } else {
        listeTickets.push_back(evenement);
        std::cout << "Ticket achete" << std::endl;
        return 1;
    }
}

int UtilisateurPublic::annulerTicket(Evenement evenement) {
    for (u_int i = 0; i < listeTickets.size(); i++) {
        if (listeTickets[i].getNom() == evenement.getNom()) {
            listeTickets.erase(listeTickets.begin() + i);
            return 1;
        }
    }
    return 0;
}

void UtilisateurPublic::consulterTicket(Evenement evenement) {
    std::cout << "Nom : " << evenement.getNom() << "\n" << "Date : " << evenement.getDate() << "\n" << "Lieu : "
              << evenement.getLieu() << "\n" << "Description : " << evenement.getDescription() << "\n" << "Type : "
              << evenement.getType() << std::endl;
}

void UtilisateurPublic::consulterListeTickets() {
    std::cout << "Liste des tickets : " << std::endl;
    for (u_int i = 0; i < listeTickets.size(); i++) {
        std::cout << listeTickets[i].getNom() << "\n" << listeTickets[i].getDate() << "\n" << listeTickets[i].getLieu()
                  << "\n" << listeTickets[i].getDescription() << "\n" << listeTickets[i].getType() << std::endl;
    }
}

bool UtilisateurPublic::operator==(const UtilisateurPublic &other) const {
    return nom == other.nom &&
           prenom == other.prenom &&
           mail == other.mail &&
           telephone == other.telephone &&
           login == other.login &&
           mdp == other.mdp &&
           type == other.type;
}

std::ostream &operator<<(std::ostream &os, const UtilisateurPublic &user) {
    os << "Nom: " << user.nom << "\n"
       << "Prenom: " << user.prenom << "\n"
       << "Mail: " << user.mail << "\n"
       << "Telephone: " << user.telephone << "\n"
       << "Login: " << user.login << "\n"
       << "Mdp: " << user.mdp << "\n"
       << "Type: " << user.type;
    return os;
}