/**
 *
 * @file    nsUtil.h
 * 
 * @author  A. Casali
 *
 * @date    10/11/2014
 *
 * @brief   3 fonctions pour utiliser des flux 
 *
 **/
#ifndef __NSUTIL_H__
#define __NSUTIL_H__
#include <vector>
#include <string>

namespace nsUtil
{
	/*
	 * fonction permettant de charger un fichier texte dans un vecteur de string
	 * 1 ligne du fichier texte correspond à une case du vecteur 
	 */
	std::vector <std::string> FileToVectString (const std::string & FileName);

    /*
     * fonction permettant de charger un fichier texte dans un vecteur de string
     * 1 ligne du fichier texte correspond à une case du vecteur
     * chaque ligne est précédée de son nombre d'élément et se termine par le caractère Car
     */
    void EditVStringV2 (const std::vector <std::string> & VString, const char & Car = '|');

    /*
     * fonction permettant de charger un fichier texte dans un vecteur de string
     * 1 ligne du fichier texte correspond à une case du vecteur
     * Chaque ligne est précéde de son numéro
     */
    void EditVStringV3 (const std::vector <std::string> & VString);


	/*
	 * fonction permettant d'afficher à l'écran le contenu d'un vecteur de string
	 */
	
	void EditVString (const std::vector <std::string> & VString);

	/*
	 * fonction permettant de mettre le contenu d'un vecteur dans un fichier texte
	 * a raison d'un element par ligne
	 */
	
	void VectStringToFile (const std::vector <std::string> & VString, 
                               const std::string & FileName);
	
} // nsUtil

#endif /* __NSUTIL_H__ */


