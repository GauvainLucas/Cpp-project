#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"

class UtilisateurPublic : public Utilisateur{
    public:
        UtilisateurPublic();
        UtilisateurPublic(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type);

        void acheterTicket();
        void annulerTicket();
        void consulterTicket();
        void consulterListeTickets();
        void consulterListeTicketsEvenement();
        void consulterListeTicketsDate();
        void consulterListeTicketsLieu();
        void consulterListeTicketsType();
        void consulterListeTicketsPrix();
};