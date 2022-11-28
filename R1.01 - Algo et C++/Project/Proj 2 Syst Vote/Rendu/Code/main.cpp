#include <iostream>
#include <vector>
using namespace std;

void resultat(vector<string> & Candidat, vector <float> & Points){
    /*
    Entree :
        - Candidat --> Vecteur de String contenant les divers candidats
        - Points --> Vecteur de Float contenant les scores des candidats

    Sortie console :
        - En cas d'égalité : Pas de vainqueur par cause d'égalité.
        - En cas d'une victoire d'un candidat X : Le vainqueur est : X avec x points.

    */
    string Vainqueur = Candidat[0]; // on définie par défaut le premier candidat comme vainqueur
    float Svainqueur = Points[0];
    bool Egalite = false; // afin de verifier si il y a une égalité on definie ce bool par false par defaut

    for (unsigned i = 1; i<=Points.size()-1;++i){ // Pour chaque score des candidats :
        if (Points[i]>Svainqueur){ // Si le score est superieur à celui enregistrer alors on change de vainqueur et on définie l'égalité à false
            Svainqueur=Points[i];
            Vainqueur=Candidat[i];
            Egalite=false;
        }
        else if (Points[i]==Svainqueur){ // si le score est equivalent à celui du vainqueur alors l'égalité devient true
            Egalite=true;
        }
    }

    if (Egalite){ // si il y a égalité on affiche une réponse
        cout<<"Pas de vainqueur par cause d'égalité."<<endl;
    }
    else{ // si il n'y a pas d'égalité il y a donc un vaiqueur, on affiche le vainqueur
        cout<<endl<<"Le vainqueur est : "<<Vainqueur<<" avec "<<Svainqueur<<" points."<<endl;
    }

}

void MethodeBorda(vector<string> & Candidat, vector<vector<int>> & Vote){
    /*
    Entree :
        - Candidat --> Vecteur de String contenant les divers candidats
        - Vote --> Vecteur de Vecteur de int contenant les différents votes

    Principe :
        Chaque votant peut voter entre 0 (blanc) et le nombre de condidats (bornes inclues).
        Les votants donnent par ordre de priorité les candidats qu'ils préfèrent.
        Le premier reçois 1 point, les autres reçoivent 1-(la position après le premier-1)/(le nombre de candidats).

    But de la procédure :
        Envoyer la liste des points selon les votes à la procédure résultat.
    */
    cout<<"Début du vote Methode Borda"<<endl<<endl;

    vector <float> Points (Candidat.size()); // on déclare le vecteur de Float Points pour stocker les scores gagnés par les candidats
    for (unsigned i = 0; i<=Vote.size()-1;++i){ // pour chaque vote :
        for (unsigned j = 0; j<=Vote[i].size()-1;++j){ // on regarde dans l'ordre les différentes préférences
            if (Vote[i][j]!=-1){ // si le vote n'est pas un vote blanc (donc ne contient pas -1)
                Points[Vote[i][j]]+=1-float(j)/float(Candidat.size()); // on ajoute dans Points le score voulue.
            }
        }
    }
    resultat(Candidat,Points); // on envoye les Points dans la procédure resultat
}

void ScrutinUninominalMajoritaireUnTour(vector<string> & Candidat,vector<int> & Vote){
    /*
    Entree :
        - Candidat --> Vecteur de String contenant les divers candidats
        - Vote --> Vecteur de int contenant les différents votes

    Principe :
        Chaque votant donne soit un vote blanc soit un candidat pour lui ajouter un point.

    But de la procédure :
        Envoyer la liste des points selon les votes à la procédure résultat.
    */
    cout<<"Début du vote uninominatif majoritaire en un tour"<<endl<<endl;
    vector <float> Points (Candidat.size()); // on déclare le vecteur de Float Points pour stocker les scores gagnés par les candidats

    for (unsigned i = 0; i<=Vote.size()-1;i++){
        if (Vote[i]!=-1){ // pour chaque vote non blanc on ajoute un point (vote blanc = -1).
            Points[Vote[i]]++;
        }
    }
    resultat(Candidat,Points); // on envoie les Points dans la procédure résultat.
}

void negativVote(vector<string> & Candidat,vector<vector<int>> &Vote){
    /*
    Entree :
        - Candidat --> Vecteur de String contenant les divers candidats
        - Vote --> Vecteur de Vecteur de int contenant les différents votes sous forme {candidat,ajout_ou_réduction}

    Principe :
        Chaque votant donne soit un vote blanc soit un candidat pour lui ajouter un point ou enlever un point.

    But de la procédure :
        Envoyer la liste des points selon les votes à la procédure résultat.
    */
    cout<<"Début du vote negativ"<<endl;
    vector <float> Points (Candidat.size()); // on déclare le vecteur de Float Points pour stocker les scores gagnés par les candidats

    for (unsigned i = 0; i<=Vote.size()-1;i++){
        if (Vote[i][0]!=-1){ // pour chaque vote non blanc :
            if (Vote[i][1]==1){ // si la deuxième valeur vaux 1 alors on ajoute un point au candidat
                Points[Vote[i][0]]++;
            }
            else { // sinon on enlève un point au candidat (on choisira 0 par défaut lors des entrées)
                Points[Vote[i][0]]--;
            }
        }
    }
    resultat(Candidat,Points);// on envoie les Points dans la procédure résultat.
}

void alternatif(vector<string> & Candidat,vector<vector<int>> &Vote){
    /*
    Entree :
        - Candidat --> Vecteur de String contenant les divers candidats
        - Vote --> Vecteur de Vecteur de int contenant les différents votes sous forme {candidat1,candidat2,...,candidatX}

    Principe :
        Chaque votant donne soit un vote blanc soit la liste de tous les candidats par ordre de préférences.
        On prend les premiers de chaque liste de vote, on leurs rajoute 1 point pour chaque vote et si aucun n'obtient la majorité on supprime le moins voté de chaque vote.
        Puis on répète la même chose.
        de cette façon la procédure s'arrête quand un candidat obtient la majorité sauf dans des cas particulier dégalité où le moins et plus voté ont autant de vote.

    Sortie console :
        - En cas d'égalité : Pas de vainqueur par cause d'égalité.
        - En cas d'une victoire d'un candidat X : Le vainqueur est : X avec x points.
    */
    cout<<"Début du vote alternatif"<<endl;

    vector<int> Lelimine; // afin de ne pas regarder les candidats éliminé on créer ce vecteur de int correspondant aux candidats

    while(true){ // on répeteras toutes la suite de la procédure tant qu'on a pas de résultat.
        vector <float> Points (Candidat.size()); // on déclare le vecteur de Float Points pour stocker les scores gagnés par les candidats.
        for (unsigned i = 0; i<Vote.size();++i){ // pour chaque vote non blanc (-1) on ajoute un point.
            if (Vote[i][0]!=-1){
                Points[Vote[i][0]]++;
            }
            else{ // pour éviter des erreurs de comptage de majorité on supprime les votes blancs de la liste de vote
                Vote.erase(Vote.begin()+i);
                --i; // dû au fonctionnement de erase le prochains vote est passé sur la position i actuel donc nous devons reculer
            }
        }

        for (unsigned i=0;i<Lelimine.size();++i){ // si le candidat est dans la liste des éliminés alors son score est initialisé à -1.
            Points[Lelimine[i]]=-1;
        }

        string vainqueur = Candidat[0]; // on définie par défaut le premier candidat comme vainqueur
        float Svainqueur = Points[0];
        bool egalite = false; // bool permetant de verifier si on a une égalité : par défaut false

        for (unsigned i = 1; i<=Points.size()-1;++i){ // pour chaque score dans points.
            if (Points[i]>Svainqueur){ // si on a un score supérieur a celui du vainqueur on change de vainqueur et on met égalité à false
                Svainqueur=Points[i];
                vainqueur=Candidat[i];
                egalite=false;
            }
            else if (Points[i]==Svainqueur){ // si on a un score équivalent à celui du vainqueur on met égalité à true
                egalite=true;
            }
        }

        //cout<<Svainqueur<<" "<<Vote.size()<<endl;

        if (Svainqueur>Vote.size()/2 and egalite==false){ // si le vainqueur à la majorité des votes non blanc et qu'il n'a pas d'égalité afficher vainqueur
            cout<<endl<<"Le vainqueur est : "<<vainqueur<<" avec "<<Svainqueur<<" points."<<endl<<endl;
            break; // on arrête la procédure
        }
        else{

            int elimine = -2; // on définie par défaut un candidat fantome pour le moins voté
            int Selimine;
            for (unsigned i = 0; i<=Points.size()-1;++i){ // pour chaque score :
                if ((elimine==-2 and Points[i]!=-1)  or (Points[i]<Selimine and Points[i]!=-1)){ // si le score ne vaux pas -1 et (que le elimine est -2 ou que le score est plus petit que elimine)
                    Selimine=Points[i];// on change le elimine et son score
                    elimine=i;
                }
            }
            if (Selimine==Svainqueur){ // si le score du prétendu éliminé est équivalent à celui du plus voté alors on stop le programme pour égalité.
                cout<<endl<<"Pas de vainqueur par cause d'égalité."<<endl;
                break;
            }
            Lelimine.push_back(elimine); // sinon on rajoute l'éliminé à la liste
            vector<vector<int>> NewVote; // on initialise une nouvelle liste de Vote
            for (unsigned i=0;i<Vote.size();++i){ // pour chaque vote on le rajoute dans NewVote sans le nouveau éliminé
                vector<int> ListPref;
                for (unsigned j=0;j<Vote[i].size();++j){
                    if (Vote[i][j]!=elimine){
                        ListPref.push_back(Vote[i][j]);
                    }
                }
                NewVote.push_back(ListPref);
            }
            Vote=NewVote;// on change Vote par NewVote
        }
    }
}


int main(){

    string Str,Nom; // str --> ligne du doc | Nom --> string correspondant aux noms des votants
    vector<string> Candidats {"Counter strike","Street Fighter II","Civilization VI","Mario Kart"}; // listes des 4 candidats de la SAE
    unsigned compteur=0; // compteur permettant de verifier sur quel ligne nous sommes
    vector<string> Profils; // liste de string des différents noms et prénoms des votant

    // on définie une liste pour chaque vote différent
    vector<int> voteNominal;
    vector<vector<int>> VoteBorda;
    vector<vector<int>> VoteNegatif;
    vector<vector<int>> VoteAlternatif;

    while (true)
    {
        getline(cin,Str); // on prend la ligne du doc
        if (cin.eof()) break; // si tabulation alors on sort de la boucle

        if (compteur==0){ // si le compteur vaux 0 alors c'est un nom
            Nom=Str;
            ++compteur; // on rajoute 1 à compteur
        }
        else if (compteur==1){ // si le compteur vaux 1 alors on ajoute dans profile le Nom précédent + la ligne donc le prénom
            Profils.push_back(Nom+" "+Str);
            ++compteur; // on ajoute 1 au compteur
        }
        else if (compteur==2){ // si le compteur vaux 2 alors on ajoute dans le vecteur des votes nominal le int de la ligne
            voteNominal.push_back(stoi(Str));
            ++compteur; // on ajoute 1 au compteur
        }
        else if (compteur==3){ // si le compteur vaux 3 alors on ajoute dans le vecteur des votes Borda les int de la ligne sous forme de vecteur<int>
            vector<int> Vsave;
            string Elem="";
            for (unsigned j=0;j<Str.size();++j){
                if (Str[j]==' '){
                    Vsave.push_back(stoi(Elem));
                    Elem="";
                }
                else{
                    Elem+=Str[j];
                }
            }
            if (Elem!=""){
                Vsave.push_back(stoi(Elem));
            }

            VoteBorda.push_back(Vsave);
            ++compteur; // on ajoute 1 au compteur
        }
        else if (compteur==4){ // si le compteur vaux 4 alors on ajoute dans le vecteur des votes negatif les int de la ligne sous forme de vecteur<int>
            vector<int> Vsave;
            string Elem="";
            for (unsigned j=0;j<Str.size();++j){
                if (Str[j]==' '){
                    Vsave.push_back(stoi(Elem));
                    Elem="";
                }
                else{
                    Elem+=Str[j];
                }
            }
            if (Elem!=""){
                Vsave.push_back(stoi(Elem));
            }
            VoteNegatif.push_back(Vsave);
            ++compteur; // on ajoute 1 au compteur
        }
        else if (compteur==5){ // si le compteur vaux 5 alors on ajoute dans le vecteur des votes Alternatif les int de la ligne sous forme de vecteur<int>
            vector<int> Vsave;
            string Elem="";
            for (unsigned j=0;j<Str.size();++j){
                if (Str[j]==' '){
                    Vsave.push_back(stoi(Elem));
                    Elem="";
                }
                else{
                    Elem+=Str[j];
                }
            }
            if (Elem!=""){
                Vsave.push_back(stoi(Elem));
            }
            VoteAlternatif.push_back(Vsave);
            compteur=0; // on remet le compteur à 0
        }
    }


    // affichage de tous les résultats
    cout<<"----------------------------------"<<endl;
    ScrutinUninominalMajoritaireUnTour(Candidats,voteNominal);
    cout<<"----------------------------------"<<endl;
    MethodeBorda(Candidats,VoteBorda);
    cout<<"----------------------------------"<<endl;
    negativVote(Candidats,VoteNegatif);
    cout<<"----------------------------------"<<endl;
    alternatif(Candidats,VoteAlternatif);
    cout<<"----------------------------------"<<endl;
    return 0;
}
