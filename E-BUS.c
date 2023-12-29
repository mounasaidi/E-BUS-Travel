#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define functions like creerVoyageur, enregistrerVoyageur, creerDate, creerReservation, enregistrerReservation, and ModifierReservation here.
// Structure pour représenter une date
typedef struct {
	char j[10];
	char m[10];
	char a[10];
	int h,min;

} Date;
// Structure pour représenter un voyageur
typedef struct {

    char nom[50];
    char prenom[50];

} Voyageur;

// Structure pour représenter un bus
typedef struct {
    int numero;
    char destination[50];
    int capacite;

} Bus;

// Structure pour représenter une réservation
typedef struct {
    int numero_reservation;
    int numero_bus;
    Date date_reservation;
    Voyageur voyageur;

} Reservation;

// Fonction pour enregistrer un voyageur dans un fichier
void enregistrerVoyageur(Voyageur Voyageur, FILE *fichier1) {
    fichier1 = fopen("Voyageur.txt", "ab");
    if (fichier1 == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");

    }
    fwrite(&Voyageur, sizeof(Voyageur), 1, fichier1);
    fclose(fichier1);
}

// Fonction pour enregistrer un bus dans un fichier
void enregistrerBUS(Bus Bus, FILE *fichier) {
    fichier = fopen("Bus.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");

    }
    fprintf(fichier, "%d  | %s  | %d\n", Bus.numero, Bus.destination, Bus.capacite);
    fclose(fichier);
}
// Fonction pour enregistrer une reservation dans un fichier
void enregistrerReservation(Reservation reservation, FILE *fichier2) {
    fichier2 = fopen("Reservation.txt", "w");
    if (fichier2 == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");

    }
    fprintf(fichier2, "%d | %d | %s | %s | %s | %s \n", reservation.numero_reservation, reservation.numero_bus,
            reservation.date_reservation.j, reservation.date_reservation.m, reservation.date_reservation.a,
            reservation.voyageur.nom, reservation.voyageur.prenom);
    fclose(fichier2);
}
// fontion por créer une date
Date creerDate() {
	Date nouvelleDate;
	printf("entrer le jour, le mois et l'année (format : jj/mm/aaaa): ");
	scanf("%s/%s/%s",nouvelleDate.j,nouvelleDate.m,nouvelleDate.a);
	printf("enter l'heure et les minutes (format : hh:mm): ");
	scanf("%d:%d", &nouvelleDate.h , &nouvelleDate.min);

	return nouvelleDate;
}

// Fonction pour créer un nouveau compte voyageur et l'enregistrer
Voyageur creerVoyageur() {
    Voyageur nouveauVoyageur;
    printf("Nom du voyageur : ");
    scanf("%s", nouveauVoyageur.nom);
    printf("Prénom du voyageur : ");
    scanf("%s", nouveauVoyageur.prenom);

    return nouveauVoyageur;

}



// Fonction pour créer une nouvelle réservation
Reservation creerReservation(int numero_reservation, int numero_bus, Date date_reservation, Voyageur voyageur) {
    Reservation nouvelleReservation;
    nouvelleReservation.numero_reservation = numero_reservation;
    nouvelleReservation.numero_bus = numero_bus;
    nouvelleReservation.date_reservation = date_reservation;
    nouvelleReservation.voyageur = voyageur;

    return nouvelleReservation;

}

// Fonction pour modifier les détails d'une réservation
void ModifierReservation(Reservation *reservation) {
    printf("Numéro de réservation : %d\n", reservation->numero_reservation);
    printf("Numéro du bus : %d\n", reservation->numero_bus);
    printf("Date de reservation : %s/%s/%s %d:%d\n", reservation->date_reservation.j, reservation->date_reservation.m,
           reservation->date_reservation.a, reservation->date_reservation.h, reservation->date_reservation.min);
    printf("Voyageur : %s %s\n", reservation->voyageur.prenom, reservation->voyageur.nom);
}


int main() {
    char rep1[4]; // Used to store "oui" or "non"
    char rep2[4]; // Used to store "oui" or "non"
    char rep3[4]; // Used to store "oui" or "non"
    char rep4[4]; // Used to store "oui" or "non"
    char rep5[4]; // Used to store "oui" or "non"
    char rep6[4]; // Used to store "oui" or "non"
    int numero_reservation, numero_bus;
    char ligne[50];
    char ligne1[50];
    char ligne2[50];
    FILE *fichier1;
    FILE *fichier2;
    Voyageur voyageur, voyageur1;
    Reservation reservation;
    FILE *fichier;
    Date date_reservation;
    Reservation res;
    Reservation reservation1;

     // Open files for writing and append mode if needed
    	//le contenu du fichier voyageur
	fichier1 = fopen("Voyageur.txt", "w");
    if (fichier1 == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");
        return 1;
    }
    fprintf(fichier1, "Nom      | Prenom      |\n");
    fprintf(fichier1, "hammami  | mahdi     |\n");
    fprintf(fichier1, "jlassi   | mariem    |\n");
    fprintf(fichier1, "founi    | zaineb   |\n");

    fclose(fichier1);

    	//le contenu du fichier Bus
	fichier = fopen("Bus.txt", "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");
        return 1;
    }
    fprintf(fichier, "numBus | Destination | NbrPlaces\n");
    fprintf(fichier, "101    | Nabeul      | 51\n");
    fprintf(fichier, "112    | Zaghouan    |32\n");
    fprintf(fichier, "301    | Monastir    | 45\n");
    fprintf(fichier, "206    | Bizerte     | 28\n");
    fprintf(fichier, "408    | Gabes       | 51\n");
    fprintf(fichier, "520    | Djerba      | 32\n");
    fprintf(fichier, "608    | Mednine     | 45\n");
    fclose(fichier);


    //le contenu du fichier reservation
    fichier2 = fopen("Reservation.txt", "w");
    if (fichier2 == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");
        return 1;
    }

    fprintf(fichier2, "numRes|NumBus|DateRes          |Voyageur \n");
    fprintf(fichier2, "1002  |301   |12/12/2023 15:30 |fakhfekh maya\n");
    fprintf(fichier2, "1105  |408   |03/02/2023 06.25 |majri asma\n");
    fprintf(fichier2, "1205  |520   |07/10/2023 08.45 |belgacem aziz\n");
    fprintf(fichier2, "1346  |608   |17/05/2023 11.20 |souissi halim\n");
    fprintf(fichier2, "1078  |206   |09/01/2023 12.50 |chtourou nour\n");
    fprintf(fichier2, "2001  |301   |12/12/2023 17.25 |damak aymen\n");
    fprintf(fichier2, "2073  |408   |29/11/2023 19.25 |asker eya\n");
    fclose(fichier2);



    while (1) {
        printf("Voulez-vous créer un nouveau compte voyageur (Répondez par oui ou non) : ");
        scanf("%3s", rep1);

        if (strcmp(rep1, "oui") == 0) {
            voyageur = creerVoyageur();
            enregistrerVoyageur(voyageur, fichier1);
        } else if (strcmp(rep1, "non") == 0) {
            break;
        }
    }

    while (1) {
        printf("Voulez-vous créer une nouvelle réservation (Répondez par oui ou non) : ");
        scanf("%3s", rep2);

        if (strcmp(rep2, "oui") == 0) {
            printf("Donnez le numéro de réservation : ");
            scanf("%d", &numero_reservation);
            printf("Donnez le numéro de bus : ");
            scanf("%d", &numero_bus);

            voyageur1 = creerVoyageur();
            date_reservation = creerDate();

            reservation1 = creerReservation(numero_reservation, numero_bus, date_reservation, voyageur1);
            enregistrerReservation(reservation1, fichier2);
        } else if (strcmp(rep2, "non") == 0) {
            break;
        }
    }

    // Afficher les comptes voyageurs
    printf("Voulez-vous voir les détails des voyageurs (Répondez par oui ou non) : ");
    scanf("%s", rep6);
    if (strcmp(rep6, "oui") == 0) {
        // Open and read "voyageur.txt" file in read mode
        FILE *fichier1 = fopen("Voyageur.txt", "r");
        if (fichier1 == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier en lecture.\n");
            return 1;
        }

        while (fgets(ligne1, sizeof(ligne1), fichier1) != NULL) {
            printf("_____________________________________________\n");
            printf("%s", ligne1);
        }

        fclose(fichier1);
    }

    //affichage les details des bus
        printf("Voulez-vous voir les détails des bus (Répondez par oui ou non) : ");
        scanf("%s", rep3);
        if (strcmp(rep3, "oui") == 0) {
            // Open and read "bus.txt" file
            FILE *fichier = fopen("Bus.txt", "r");
            if (fichier == NULL) {
                fprintf(stderr, "Erreur lors de l'ouverture du fichier en lecture.\n");
                return 1;
            }

            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                printf("_____________________________________________\n");
                printf("%s", ligne);
            }

            fclose(fichier);
        }	
	 

    //affichage des details des reservations

        printf("Voulez-vous afficher les détails d'une réservation (Répondez par oui ou non) : ");
        scanf("%3s", rep4); // Limit input to 3 characters (oui or non)

        if (strcmp(rep4, "oui") == 0) {
            // Open and read "reservation.txt" file
            fichier2 = fopen("Reservation.txt", "r");
            if (fichier2 == NULL) {
                fprintf(stderr, "Erreur lors de l'ouverture du fichier en lecture.\n");
                return 1;
            }

            while (fgets(ligne2, sizeof(ligne2), fichier2) != NULL) {
                printf("________________________________________________\n");
                printf("%s", ligne2);
            }

            fclose(fichier2);
        }

    while (1) {
        printf("Voulez-vous modifier les détails d'une réservation (Répondez par oui ou non) : ");
        scanf("%3s", rep5);

        if (strcmp(rep5, "oui") == 0) {
            printf("Numéro de réservation à modifier : ");
            scanf("%d", &res.numero_reservation);
            printf("Numéro du bus : ");
            scanf("%d", &res.numero_bus);
            res.date_reservation = creerDate();
            res.voyageur = creerVoyageur();

            fichier2 = fopen("Reservation.txt", "a");
            if (fichier2 == NULL) {
                fprintf(stderr, "Erreur lors de l'ouverture du fichier en écriture.\n");
                return 1;
            }

            ModifierReservation(&res);

            fclose(fichier2);
        } else if (strcmp(rep5, "non") == 0) {
            break;
        }
    }
    //affichage des details des reservations

        printf("Voulez-vous afficher les détails d'une réservation (Répondez par oui ou non) : ");
        scanf("%3s", rep4); // Limit input to 3 characters (oui or non)

        if (strcmp(rep4, "oui") == 0) {
            // Open and read "reservation.txt" file
            fichier2 = fopen("Reservation.txt", "r");
            if (fichier2 == NULL) {
                fprintf(stderr, "Erreur lors de l'ouverture du fichier en lecture.\n");
                return 1;
            }

            while (fgets(ligne2, sizeof(ligne2), fichier2) != NULL) {
                printf("________________________________________________\n");
                printf("%s", ligne2);
            }

            fclose(fichier2);
        }

    return 0;
}
