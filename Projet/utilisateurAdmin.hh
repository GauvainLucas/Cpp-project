#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurVIP.hh"

class UtilisateurAdmin : public UtilisateurVIP{
    public:
        UtilisateurAdmin();
        UtilisateurAdmin(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type):UtilisateurVIP(nom, prenom, mail, telephone, login, mdp, type){};

        void vendreTicket(Evenement evenement);
        void modifierTicketNom(Evenement &evenement, std::string nom);
        void modifierTicketDate(Evenement &evenement, std::string date);
        void modifierTicketLieu(Evenement &evenement, std::string lieu);
        void modifierTicketDescription(Evenement &evenement, std::string description);
        void modifierTicketType(Evenement &evenement, std::string type);

        void modifierNomAutre(std::string nom, Utilisateur &user);
        void modifierPrenomAutre(std::string prenom, Utilisateur &user);
        void modifierMailAutre(std::string mail, Utilisateur &user);
        void modifierTelephoneAutre(std::string telephone, Utilisateur &user);
        void modifierLoginAutre(std::string login, Utilisateur &user);
        void modifierMdpAutre(std::string mdp, Utilisateur &user);
        void modifierTypeAutre(std::string type, Utilisateur &user);

};