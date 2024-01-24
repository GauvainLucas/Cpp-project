cmake_minimum_required(VERSION 3.26)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(Projet

        applicationJO.hh
        IBilleterie.hh
        evenement.hh
        evenementCeremonie.hh
        evenementSportif.hh
        utilisateur.hh
        utilisateurAdmin.hh
        utilisateurPublic.hh
        utilisateurVIP.hh evenement.cc evenement.cc utilisateur.cc utilisateur.cc applicationJO.cc utilisateurPublic.cc pageEvenements.cc pageEvenements.hpp evenementSportif.cc evenementSportif.cc utilisateurVIP.cc utilisateurVIP.cc utilisateurAdmin.cc)

# Lier les bibliothèques SFML à votre exécutable
target_link_libraries(Projet PRIVATE sfml-graphics sfml-window sfml-system)