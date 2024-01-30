#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurVIP.hh"

int UtilisateurVIP::acheterTicket(Evenement evenement) {
    if (evenement.getType() == "VIP") {
        listeTicketsVIP.push_back(evenement);
        std::cout << "Ticket VIP achete" << std::endl;
        return 1;
    } else {
        listeTickets.push_back(evenement);
        std::cout << "Ticket achete" << std::endl;
        return 2;
    }
}

int UtilisateurVIP::annulerTicket(Evenement evenement) {
    if (evenement.getType() == "VIP") {
        for (u_int i = 0; i < listeTicketsVIP.size(); i++) {
            if (listeTicketsVIP[i].getNom() == evenement.getNom()) {
                listeTicketsVIP.erase(listeTicketsVIP.begin() + i);
                return 1;
            }
        }
    } else {
        for (u_int i = 0; i < listeTickets.size(); i++) {
            if (listeTickets[i].getNom() == evenement.getNom()) {
                listeTickets.erase(listeTickets.begin() + i);
                return 2;
            }
        }
    }
    return 0;
}

void UtilisateurVIP::consulterListeTicketsVIP() {
    std::cout << "Liste de vos tickets VIP : " << std::endl;
    for (u_int i = 0; i < listeTicketsVIP.size(); i++) {
        std::cout << listeTicketsVIP[i].getNom() << "\n" << listeTicketsVIP[i].getDate() << "\n"
                  << listeTicketsVIP[i].getLieu() << "\n" << listeTicketsVIP[i].getDescription() << "\n"
                  << listeTicketsVIP[i].getType() << "\n------------------------------" << std::endl;
    }
}

bool UtilisateurVIP::operator==(const UtilisateurVIP &other) const {
    return nom == other.nom &&
           prenom == other.prenom &&
           mail == other.mail &&
           telephone == other.telephone &&
           login == other.login &&
           mdp == other.mdp &&
           type == other.type;
}

std::ostream &operator<<(std::ostream &os, const UtilisateurVIP &user) {
    os << "Nom : " << user.nom << "\n"
       << "Prenom : " << user.prenom << "\n"
       << "Mail : " << user.mail << "\n"
       << "Telephone : " << user.telephone << "\n"
       << "Login : " << user.login << "\n"
       << "Mot de passe : " << user.mdp << "\n"
       << "Type : " << user.type << std::endl;
    return os;
}