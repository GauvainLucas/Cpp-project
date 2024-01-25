#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "evenement.hh"
#include "evenementSportif.hh"
#include "evenementCeremonie.hh"
#include "utilisateur.hh"
#include "utilisateurAdmin.hh"
#include "utilisateurPublic.hh"
#include "utilisateurVIP.hh"
#include "IBilleterie.hh"

// Create user John Doe VIP
extern UtilisateurVIP johnDoe;
extern UtilisateurPublic janeDoe;
extern Utilisateur *utilisateurCourant;


class ApplicationJO {
    public:

};

