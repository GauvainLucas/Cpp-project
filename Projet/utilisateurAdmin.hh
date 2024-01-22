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
        void consulterListeTicketsEvenement(std::string nomEvenement);
        void consulterListeTicketsDate(std::string dateEvenement);
        void consulterListeTicketsLieu(std::string lieuEvenement);
        void consulterListeTicketsType(std::string typeEvenement);

        void modifierNom(std::string nom);
        void modifierPrenom(std::string prenom);
        void modifierMail(std::string mail);
        void modifierTelephone(std::string telephone);
        void modifierLogin(std::string login);
        void modifierMdp(std::string mdp);

        void modifierNomAutre(std::string nom, std::string loginUser);
        void modifierPrenomAutre(std::string prenom, std::string loginUser);
        void modifierMailAutre(std::string mail, std::string loginUser);
        void modifierTelephoneAutre(std::string telephone, std::string loginUser);
        void modifierLoginAutre(std::string login, std::string loginUser);
        void modifierMdpAutre(std::string mdp, std::string loginUser);
        void modifierTypeAutre(std::string type, std::string loginUser);

};