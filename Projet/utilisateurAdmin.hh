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

        void acheterTicket(std::string nomEvenement);
        void vendreTicket(std::string nomEvenement);
        void annulerTicket(std::string nomEvenement);
        void modifierTicket(std::string nomEvenement);
        void consulterTicket(std::string nomEvenement);
        void consulterListeTickets();
        void consulterListeTicketsVIP();
        void consulterListeTicketsEvenement();
        void consulterListeTicketsDate();
        void consulterListeTicketsLieu();
        void consulterListeTicketsType();
        void consulterListeTicketsPrix();

};