#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"

/*Utilisateur::Utilisateur(){
    nom = "";
    prenom = "";
    mail = "";
    telephone = "";
    login = "";
    mdp = "";
    type = "";
}*/

Utilisateur::Utilisateur(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type){
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->telephone = telephone;
    this->login = login;
    this->mdp = mdp;
    this->type = type;
}


