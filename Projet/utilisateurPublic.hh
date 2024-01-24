#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"


class UtilisateurPublic : public Utilisateur{
    public:
        UtilisateurPublic();

        //UtilisateurPublic(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type);
        // getters
        std::string getNom(){return nom;};
        std::string getPrenom(){return prenom;};
        void acheterTicket(Evenement evenement);
        void annulerTicket(Evenement evenement);
        void consulterTicket(Evenement evenement);
        void consulterListeTickets();
        void consulterListeTicketsEvenement(std::string nomEvenement);
        void consulterListeTicketsDate(std::string dateEvenement);
        void consulterListeTicketsLieu(std::string lieuEvenement);
        void consulterListeTicketsType(std::string typeEvenement);

        void modifierNom(std::string nom){this->nom = nom;};
        void modifierPrenom(std::string prenom){this->prenom = prenom;};
        void modifierMail(std::string mail){this->mail = mail;};
        void modifierTelephone(std::string telephone){this->telephone = telephone;};
        void modifierLogin(std::string login){this->login = login;};
        void modifierMdp(std::string mdp){this->mdp = mdp;};

       UtilisateurPublic(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type):Utilisateur(nom, prenom, mail, telephone, login, mdp, type){};


};