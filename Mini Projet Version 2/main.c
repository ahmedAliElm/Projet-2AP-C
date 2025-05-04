 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MAX_VOITURES 100
 #define MAX_CLIENTS 100
 #define PRIX_KILOMETRE 0.5

 #define RESET   "\033[0m"
 #define RED     "\033[31m"
 #define GREEN   "\033[32m"
 #define YELLOW  "\033[33m"
 #define BLUE    "\033[34m"
 #define MAGENTA "\033[35m"
 #define CYAN    "\033[36m"

 /*** STRUCTURE DES VOITURES ***/

 typedef struct {
    char marque[50];
    char matricule[20];
    float kilometrage;
    int disponibilite; // 1 pour disponible et 0 pour lou�e
 } Voiture;

 /*** STRUCTURE DES CLIENTS ***/

 typedef struct {
    char nom[50];
    char cin[20];
    char telephone[20];
    float avance;
    float prix_a_payer;
 } Client;

 /** On d�clare globalement deux tableaux avec leur taille **/

 Voiture voitures[MAX_VOITURES];
 int nbVoitures = 0;

 Client clients[MAX_CLIENTS];
 int nbClients = 0;


                    /***** TRAITEMENT VOITURES *****/


 /*** FONCTION D'AJOUT ***/

 void ajouterVoiture() {
    int a;
    if(nbVoitures >= MAX_VOITURES)
       printf("\n Le nombre maximum de voitures est atteint.\n");
    Voiture nouvelleVoiture;
    printf("\n Marque : ");
    scanf("%s", nouvelleVoiture.marque);
    printf("\n Matricule : ");
    scanf("%s", nouvelleVoiture.matricule);
    printf("\n Kilometrage : ");
    scanf("%f", &nouvelleVoiture.kilometrage);
    nouvelleVoiture.disponibilite = 1; // Disponible par d�faut
    voitures[nbVoitures] = nouvelleVoiture;
    nbVoitures++;
    if(nbVoitures >= 2){
       do { for(int i = 0; i < nbVoitures; i++){
               if(strcmp(nouvelleVoiture.matricule, voitures[i].matricule) == 0){
                  a = 1;
                  printf("\n Ce matricule existe deja, veuillez saisir un autre : ");
                  scanf("%s",nouvelleVoiture.matricule); }
               else { a = 0; }
            }
       } while(a == 1);
    }
    printf("\n La voiture a ete ajoutee avec succes.\n");
 }

 /*** FONCTION D'AFFICHAGE (1) ***/

 void afficherVoiture(Voiture voiture){
    printf(YELLOW"\n Marque : %s\n"RESET, voiture.marque);
    printf(YELLOW"\n Matricule : %s\n"RESET, voiture.matricule);
    printf(YELLOW"\n Kilometrage : %.2f\n"RESET, voiture.kilometrage);
    printf(YELLOW"\n Disponibilite : %s\n"RESET, (voiture.disponibilite == 1) ? "Disponible" : "Louee");
 }

 /*** FONCTION D'AFFICHAGE ***/

 void afficherVoitures(){
    if(nbVoitures == 0)
       printf(RED"\n Il n'y a aucune voiture, veuillez saisir au minimum une.\n"RESET);
    for(int i = 0; i < nbVoitures; i++){
           afficherVoiture(voitures[i]);
        printf("\n ---------------------\n");
    }
 }

 /*** FONCTION DE TRI ***/

 void tri(Voiture voitures[],int nbVoitures){
      int i,j,min; Voiture temp;
      for(i = 0; i<nbVoitures-1; i++){
         min = i;
         for(j = i+1; j < nbVoitures; j++){
            if(voitures[j].kilometrage < voitures[min].kilometrage)
               min = j;
         }
         temp = voitures[min];
         voitures[min] = voitures[i];
         voitures[i] = temp;
      }
 }

 /*** FONCTION DE MODIFICATION ***/

 void modifierVoiture(char matricule[]){
    for(int i = 0; i < nbVoitures; i++){
        if(strcmp(voitures[i].matricule, matricule) == 0){
            printf("\n Nouvelle marque : ");
            scanf("%s", voitures[i].marque);
            printf("\n Nouveau kilometrage : ");
            scanf("%f", &voitures[i].kilometrage);
            printf("\n Nouvelle disponibilite (1 : Disponible, 0 : Louee) : ");
            scanf("%d", &voitures[i].disponibilite);
            printf("\n Les informations de la voiture ont ete modifiees avec succes.\n");
            return;
        }
    }

    printf("\n Aucune voiture avec le matricule specifie n'a ete trouvee.\n");
 }

 /*** FONCTION DE SUPPRESSION ***/

 void supprimerVoiture(char matricule[]){
    for(int i = 0; i < nbVoitures; i++){
        if(strcmp(voitures[i].matricule, matricule) == 0){
            for(int j = i; j < nbVoitures - 1; j++){
                voitures[j] = voitures[j + 1];
            }
            nbVoitures--;
            printf("\n La voiture a ete supprimee avec succes.\n");
            return;
        }
    }

    printf("\n Aucune voiture avec le matricule specifie n'a ete trouvee.\n");
 }


                    /***** TRAITEMENT CLIENTS *****/


 /*** FONCTION D'AJOUT ***/

 void ajouterClient(){
    int a = 1,i = 0;
    if(nbClients >= MAX_CLIENTS){
        printf("\n Le nombre maximum de clients est atteint.\n");
        return;}
    Client nouveauClient;
    printf("\n Nom : ");
    scanf("%s", nouveauClient.nom);
    printf("\n CIN : ");
    scanf("%s", nouveauClient.cin);
    printf("\n Telephone : ");
    scanf("%s", nouveauClient.telephone);
    printf("\n Avance : ");
    scanf("%f", &nouveauClient.avance);
    printf("\n Prix a payer : ");
    scanf("%f", &nouveauClient.prix_a_payer);
    clients[nbClients] = nouveauClient;
    nbClients++;
    if(nbClients >= 2){
       do { for(int i = 0; i < nbClients; i++){
               if(strcmp(nouveauClient.cin, clients[i].cin) == 0){
                   a = 1;
                   printf("\n Ce CIN existe deja, veuillez saisir un autre : ");
                   scanf("%s",nouveauClient.cin); }
               else { a = 0; }
            }
       } while(a == 1);
    }
    printf("\n Le client a ete ajoute avec succes.\n");
 }

 /*** FONCTION D'AFFICHAGE (1) ***/

 void afficherClient(Client client){
    printf(YELLOW"\n Nom : %s\n"RESET, client.nom);
    printf(YELLOW"\n CIN : %s\n"RESET, client.cin);
    printf(YELLOW"\n Telephone : %s\n"RESET, client.telephone);
    printf(YELLOW"\n Avance : %.2f\n"RESET, client.avance);
    printf(YELLOW"\n Prix a payer : %.2f\n"RESET, client.prix_a_payer);
 }

 /*** FONCTION D'AFFICHAGE ***/

 void afficherClients(){
    for(int i = 0; i < nbClients; i++){
        afficherClient(clients[i]);
        printf("\n ---------------------\n");
    }
 }

 /*** FONCTION DE MODIFICATION ***/

 void modifierClient(char cin[]){
    for(int i = 0; i < nbClients; i++){
        if(strcmp(clients[i].cin, cin) == 0){
            printf("\n Nouveau nom : ");
            scanf("%s", clients[i].nom);
            printf("\n Nouveau telephone : ");
            scanf("%s", clients[i].telephone);
            printf("\n Nouvelle avance : ");
            scanf("%f", &clients[i].avance);
            printf("\n Nouveau prix a payer : ");
            scanf("%f", &clients[i].prix_a_payer);

            printf("\n Les informations du client ont ete modifiees avec succes.\n");
            return;
        }
    }

    printf("\n Aucun client avec le CIN specifie n'a ete trouve.\n");
 }

 /*** FONCTION DE SUPPRESSION ***/

 void supprimerClient(char cin[]){
    for(int i = 0; i < nbClients; i++){
        if(strcmp(clients[i].cin, cin) == 0){
            for(int j = i; j < nbClients - 1; j++){
                clients[j] = clients[j +1];
            }
        }
            nbClients--;
            printf("\n Le client a ete supprime avec succes.\n");
            return;
    }
    printf("\n Aucun client avec le CIN specifie n'a ete trouve.\n");
 }

 /*** FONCTION DE LOCATION ***/

 void louerVoiture(char matricule[],char cin[]){
    Voiture *voitureLouee = NULL;
    Client *client = NULL;
    // Recherche de la voiture
    for(int i = 0; i < nbVoitures; i++){
        if(strcmp(voitures[i].matricule, matricule) == 0){
            voitureLouee = &voitures[i];
            break;
        }
    }
    // Recherche du client
    for(int i = 0; i < nbClients; i++){
        if(strcmp(clients[i].cin, cin) == 0){
            client = &clients[i];
            break;
        }
    }

    if(voitureLouee == NULL || client == NULL){
        printf("\n Impossible de proceder a la location. Voiture ou client introuvable.\n");
        return;
    }

    if(voitureLouee->disponibilite == 0){
        printf("\n La voiture demandee n'est pas disponible.\n");
        return;
    }

    // Calcul du prix � payer
    float distance;
    printf("\n Distance parcourue (en kilometres) : ");
    scanf("%f", &distance);

    float prix = PRIX_KILOMETRE * distance;
    client->prix_a_payer = prix;
    voitureLouee->disponibilite = 0; // La voiture est maintenant lou�e

    printf("\n Location effectuee avec succes. Le prix a payer est de %.2f DH.\n", prix);
 }

 /*** FONCTION DE RENDRE UN VOITURE LOUEE ***/

 void rendreVoiture(char matricule[], char cin[]){
    Voiture *voitureRendue = NULL;
    Client *client = NULL;
    // Recherche de la voiture
    for(int i = 0; i < nbVoitures; i++){
        if(strcmp(voitures[i].matricule, matricule) == 0){
            voitureRendue = &voitures[i];
            break;
        }
    }
    // Recherche du client
    for(int i = 0; i < nbClients; i++){
        if(strcmp(clients[i].cin, cin) == 0){
            client = &clients[i];
            break;
        }
    }

    if(voitureRendue == NULL || client == NULL){
        printf("\n Impossible de proceder au retour de la voiture. Voiture ou client introuvable.\n");
        return;
    }

    float distance;
    printf("\n Distance parcourue (en kilometres) : ");
    scanf("%f", &distance);

    // Mise � jour du kilom�trage de la voiture
    voitureRendue->kilometrage += distance;

    // Calcul du prix � payer
    float prix = PRIX_KILOMETRE * distance;
    client->prix_a_payer += prix;
    voitureRendue->disponibilite = 1; // La voiture est maintenant disponible

    printf("\n Voiture rendue avec succes. Le prix a payer est de %.2f DH.\n", prix);
 }

 main(){
    int choix1,choix2,choix3,choix4; char matr[30],cin[30];
    do {
       system("cls"); printf(RED"\n ----- MENU : -----\n"RESET);
       printf(CYAN"\n 1."RESET " Gestion des voitures\n");
       printf(CYAN"\n 2."RESET " Gestion des locations\n");
       printf(CYAN"\n 3."RESET " Quitter\n");
       printf(RED"\n\t Votre choix : "RESET);
       scanf("%d", &choix1);
       switch(choix1){
          case 1 : system("cls"); printf("\n\n ----- GESTION DES VOITURES : -----\n");
                   printf(CYAN"\n 1."RESET " Ajouter une voiture\n");
                   printf(CYAN"\n 2."RESET " Afficher les voitures\n");
                   printf(CYAN"\n 3."RESET " Modifier une voiture\n");
                   printf(CYAN"\n 4."RESET " Supprimer une voiture\n");
                   printf(CYAN"\n 5."RESET " Retour au menu principal\n");
                   printf(CYAN"\n\t "RESET " Votre choix : ");
                   scanf("%d",&choix2);
                   switch(choix2){
                      case 1 : system("cls"); do { ajouterVoiture();
                                    do { printf("\n Voulez-vous ajouter une autre voiture? Oui(1) Non(0) : ");
                                         scanf("%d",&choix3);
                                    } while(choix3 != 1 && choix3 != 0);
                               } while(choix3 == 1);
                               break;
                      case 2 : system("cls"); tri(voitures,nbVoitures);
                               afficherVoitures();
                               break;
                      case 3 : system("cls"); printf("\n Matricule de la voiture a modifier : ");
                               scanf("%s", matr);
                               modifierVoiture(matr); break;
                      case 4 : system("cls"); printf("\n Matricule de la voiture a supprimer : ");
                               scanf("%s", matr);
                               supprimerVoiture(matr); break;
                      case 5 : // Retour au menu principal
                               break;
                      default : printf("\n Choix invalide.\n"); break;
                   }
        break;
        case 2 : system("cls"); printf("\n\n ----- GESTION DES LOCATIONS : -----\n");
                 printf("\n 1. Ajouter un client\n");
                 printf("\n 2. Afficher les clients\n");
                 printf("\n 3. Modifier un client\n");
                 printf("\n 4. Supprimer un client\n");
                 printf("\n 5. Louer une voiture\n");
                 printf("\n 6. Rendre une voiture\n");
                 printf("\n 7. Retour au menu principal\n");
                 printf("\n\t Votre choix : ");
                 scanf("%d", &choix2);
                 switch(choix2){
                    case 1 : system("cls"); do { ajouterClient();
                                  do { printf("\n Voulez-vous ajouter un autre client? Oui(1) Non(0) : ");
                                       scanf("%d",&choix3);
                                  } while(choix3 != 1 && choix3 != 0);
                             } while(choix3 == 1);
                             break;
                    case 2 : system("cls"); afficherClients(); break;
                    case 3 : system("cls"); printf("\n CIN du client a modifier : ");
                             scanf("%s",cin);
                             modifierClient(cin); break;
                    case 4 : system("cls"); printf("\n CIN du client a supprimer : ");
                             scanf("%s",cin);
                             supprimerClient(cin); break;
                    case 5 : system("cls"); printf("\n Matricule de la voiture a louer : ");
                             scanf("%s",matr);
                             printf("\n CIN du client : ");
                             scanf("%s",cin);
                             louerVoiture(matr,cin); break;
                    case 6 : system("cls"); printf("\n Matricule de la voiture a rendre : ");
                             scanf("%s",matr);
                             printf("\n CIN du client : ");
                             scanf("%s",cin);
                             rendreVoiture(matr,cin); break;
                    case 7 : // Retour au menu principal
                             break;
                    default : printf("\n Choix invalide.\n"); break;
                }
        break;
        case 3 : printf(GREEN "\n Au revoir !\n" RESET); break;
        default : printf("\n Choix invalide.\n"); break;
        }
        do { printf(GREEN"\n Voulez-vous effectuer une autre gestion? Oui(1) Non(0) : "RESET);
             scanf("%d",&choix4);
        } while(choix4 != 1 && choix4 != 0);
    } while(choix4 == 1);
    printf(MAGENTA"\n\n FIN DU TRAITEMENT\n\n"RESET);
 }

