#include "task2.h"

float rotunjire2(float var) {
    float value = (float)((int)(var * TWO_DECIMALS + ROUND));
    value /= (float) TWO_DECIMALS;
    return value;
}

void afisare_student(student stud, char **campuri, int nrcampuri) {
    for (int k = 0; k < nrcampuri; k++) {
        if (strcmp(campuri[k], "*") == 0) {
            printf("%d %s %d %c %0.2f", stud.id, stud.nume,
            stud.an_studiu, stud.statut, stud.medie_generala);
        } else if (strcmp(campuri[k], "id") == 0) {
            printf("%d", stud.id);
        } else if (strcmp(campuri[k], "nume") == 0) {
            printf("%s", stud.nume);
        } else if (strcmp(campuri[k], "an_studiu") == 0) {
            printf("%d", stud.an_studiu);
        } else if (strcmp(campuri[k], "statut") == 0) {
            printf("%c", stud.statut);
        } else if (strcmp(campuri[k], "medie_generala") == 0) {
            printf("%0.2f", stud.medie_generala);
        }
        if (k != nrcampuri - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void afisare_materie(materie mat, char **campuri, int nrcampuri) {
    for (int k = 0; k < nrcampuri; k++) {
        if (strcmp(campuri[k], "*") == 0) {
            printf("%d %s %s", mat.id, mat.nume,
            mat.nume_titular);
        } else if (strcmp(campuri[k], "id") == 0) {
            printf("%d", mat.id);
        } else if (strcmp(campuri[k], "nume") == 0) {
            printf("%s", mat.nume);
        } else if (strcmp(campuri[k], "nume_titular") == 0) {
            printf("%s", mat.nume_titular);
        }
        if (k != nrcampuri - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void afisare_inrolare(inrolare inr, char **campuri, int nrcampuri) {
    for (int k = 0; k < nrcampuri; k++) {
        if (strcmp(campuri[k], "*") == 0) {
            printf("%d %d %.2f %.2f %.2f", inr.id_student,
            inr.id_materie, inr.note[0], inr.note[1],
            inr.note[2]);
        } else if (strcmp(campuri[k], "id_student") == 0) {
            printf("%d", inr.id_student);
        } else if (strcmp(campuri[k], "id_materie") == 0) {
            printf("%d", inr.id_materie);
        } else if (strcmp(campuri[k], "note") == 0) {
            printf("%.2f %.2f %.2f", inr.note[0],
            inr.note[1], inr.note[2]);
        }
        if (k != nrcampuri - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int verif_sir(char *sir1, char *operator, char *sir2) {
    if (strcmp(operator, "=") == 0 && strcmp(sir1, sir2) == 0) {
        return 1;
    } else if (strcmp(operator, "<") == 0 && strcmp(sir1, sir2) < 0) {
        return 1;
    } else if (strcmp(operator, ">") == 0 && strcmp(sir1, sir2) > 0) {
        return 1;
    } else if (strcmp(operator, "<=") == 0 && strcmp(sir1, sir2) <= 0) {
        return 1;
    } else if (strcmp(operator, ">=") == 0 && strcmp(sir1, sir2) >= 0) {
        return 1;
    } else if (strcmp(operator, "!=") == 0 && strcmp(sir1, sir2) != 0) {
        return 1;
    }
    return 0;
}

int verif_int(int x, char *operator, int y) {
    if (strcmp(operator, "=") == 0 && x == y) {
        return 1;
    } else if (strcmp(operator, "<") == 0 && x < y) {
        return 1;
    } else if (strcmp(operator, ">") == 0 && x > y) {
        return 1;
    } else if (strcmp(operator, "<=") == 0 && x <= y) {
        return 1;
    } else if (strcmp(operator, ">=") == 0 && x >= y) {
        return 1;
    } else if (strcmp(operator, "!=") == 0 && x != y) {
        return 1;
    }
    return 0;
}

int verif_caracter(char x, char *operator, char y) {
    if (strcmp(operator, "=") == 0 && x == y) {
        return 1;
    } else if (strcmp(operator, "<") == 0 && x < y) {
        return 1;
    } else if (strcmp(operator, ">") == 0 && x > y) {
        return 1;
    } else if (strcmp(operator, "<=") == 0 && x <= y) {
        return 1;
    } else if (strcmp(operator, ">=") == 0 && x >= y) {
        return 1;
    } else if (strcmp(operator, "!=") == 0 && x != y) {
        return 1;
    }
    return 0;
}

int verif_float(float x, char *operator, float y) {
    if (strcmp(operator, "=") == 0 && x == y) {
        return 1;
    } else if (strcmp(operator, "<") == 0 && x < y) {
        return 1;
    } else if (strcmp(operator, ">") == 0 && x > y) {
        return 1;
    } else if (strcmp(operator, "<=") == 0 && x <= y) {
        return 1;
    } else if (strcmp(operator, ">=") == 0 && x >= y) {
        return 1;
    } else if (strcmp(operator, "!=") == 0 && x != y) {
        return 1;
    }
    return 0;
}

void interogare_student(student *studenti, int nrstudenti, int *afisari) {
    char *p = strtok(NULL, " ");
    p = strtok(NULL, " ");
    if (strcmp(p, "id") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        int id = atoi(p);
        for (int j = 0; j < nrstudenti; j++) {
            afisari[j] = verif_int(studenti[j].id, operator, id);
        }
    }
    if (strcmp(p, "nume") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        char *nume = malloc((strlen(p) + 1) * sizeof(char));
        snprintf(nume, strlen(p) + 1, "%s", p);
        for (int j = 0; j < nrstudenti; j++) {
            afisari[j] = verif_sir(studenti[j].nume, operator, nume);
        }
    }

    if (strcmp(p, "an_studiu") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        int an_studiu = atoi(p);
        for (int j = 0; j < nrstudenti; j++) {
            afisari[j] = verif_int(studenti[j].an_studiu, operator, an_studiu);
        }
    }
    if (strcmp(p, "statut") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        char statut = p[0];
        for (int j = 0; j < nrstudenti; j++) {
            afisari[j] = verif_caracter(studenti[j].statut, operator, statut);
        }
    }
    if (strcmp(p, "medie_generala") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        float medie_generala = (float) atof(p);
        for (int j = 0; j < nrstudenti; j++) {
            afisari[j] = verif_float(studenti[j].medie_generala, operator, medie_generala);
        }
    }
}

void interogare_materie(materie *materii, int nrmaterii, int *afisari) {
    char *p = strtok(NULL, " ");
    p = strtok(NULL, " ");
    if (strcmp(p, "id") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        int id = atoi(p);
        for (int j = 0; j < nrmaterii; j++) {
            afisari[j] = verif_int(materii[j].id, operator, id);
        }
    } else if (strcmp(p, "nume") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        char *nume = malloc((strlen(p) + 1) * sizeof(char));
        snprintf(nume, strlen(p) + 1, "%s", p);
        for (int j = 0; j < nrmaterii; j++) {
            afisari[j] = verif_sir(materii[j].nume, operator, nume);
        }
    } else {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        char *nume_titular = malloc((strlen(p) + 1) * sizeof(char));
        snprintf(nume_titular, strlen(p) + 1, "%s", p);
        for (int j = 0; j < nrmaterii; j++) {
            afisari[j] = verif_sir(materii[j].nume_titular, operator, nume_titular);
        }
    }
}

void interogare_inrolare(inrolare *inrolari, int nrinrolari, int *afisari) {
    char *p = strtok(NULL, " ");
    p = strtok(NULL, " ");
    if (strcmp(p, "id_student") == 0) {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        int id_student = atoi(p);
        for (int j = 0; j < nrinrolari; j++) {
            afisari[j] = verif_int(inrolari[j].id_student, operator, id_student);
        }
    } else {
        char *operator = strtok(NULL, " ");
        p = strtok(NULL, " ;");
        int id_materie = 0;
        id_materie = atoi(p);
        for (int j = 0; j < nrinrolari; j++) {
            afisari[j] = verif_int(inrolari[j].id_materie, operator, id_materie);
        }
    }
}

void update_studenti(student *studenti, int nrstudenti, int complex) {
    int *conditie1 = malloc(nrstudenti * sizeof(int));
    int *conditie2 = malloc(nrstudenti * sizeof(int));
    for (int i = 0; i < nrstudenti; i++) {
        conditie2[i] = 1;
    }
    char *p = strtok(NULL, " ;");
    char *camp = strtok(NULL, " ;");
    p = strtok(NULL, " ;");
    char *valoare = strtok(NULL, " ;\"");
    if (strcmp(camp, "nume") == 0) {
        char *nume = malloc(MAX_STUDENT_NAME * sizeof(char));
        snprintf(nume, strlen(valoare) + 1, "%s", valoare);
        char *prenume = strtok(NULL, " ;\"");
        snprintf(nume + strlen(nume), strlen(" ") + 1, "%s", " ");
        snprintf(nume + strlen(nume), strlen(nume) + strlen(prenume) + 1, "%s", prenume);
        snprintf(valoare, strlen(nume) + 1, "%s", nume);
        free(nume);
    }
    interogare_student(studenti, nrstudenti, conditie1);
    if (complex) {
        interogare_student(studenti, nrstudenti, conditie2);
    }
    for (int i = 0; i < nrstudenti; i++) {
        if (conditie1[i] && conditie2[i]) {
            if (strcmp(camp, "nume") == 0) {
                snprintf(studenti[i].nume, strlen(valoare) + 1, "%s", valoare);
            } else if (strcmp(camp, "an_studiu") == 0) {
                studenti[i].an_studiu = atoi(valoare);
            } else if (strcmp(camp, "statut") == 0) {
                studenti[i].statut = valoare[0];
            } else {
                studenti[i].medie_generala = (float) atof(valoare);
            }
        }
    }
    free(conditie1);
    free(conditie2);
}

void update_materii(materie *materii, int nrmaterii, int complex) {
    int *conditie1 = malloc(nrmaterii * sizeof(int));
    int *conditie2 = malloc(nrmaterii * sizeof(int));
    for (int i = 0; i < nrmaterii; i++) {
        conditie2[i] = 1;
    }
    char *p = strtok(NULL, " ;");
    char *camp = strtok(NULL, " ;");
    p = strtok(NULL, " ;");
    char *valoare = strtok(NULL, " ;\"");
    interogare_materie(materii, nrmaterii, conditie1);
    if (complex) {
        interogare_materie(materii, nrmaterii, conditie2);
    }
    for (int i = 0; i < nrmaterii; i++) {
        if (conditie1[i] && conditie2[i]) {
            if (strcmp(camp, "nume") == 0) {
                snprintf(materii[i].nume, strlen(valoare) + 1, "%s", valoare);
            } else {
                snprintf(materii[i].nume_titular, strlen(valoare) + 1, "%s", valoare);
            }
        }
    }
    free(conditie1);
    free(conditie2);
}

void update_inrolari(inrolare *inrolari, int nrinrolari, int complex, secretariat *sec) {
    int *conditie1 = malloc(nrinrolari * sizeof(int));
    int *conditie2 = malloc(nrinrolari * sizeof(int));
    float nota1 = 0, nota2 = 0, nota3 = 0;
    for (int i = 0; i < nrinrolari; i++) {
        conditie2[i] = 1;
    }
    char *p = strtok(NULL, " ;");
    char *camp = strtok(NULL, " ;");
    char *valoare = p;
    p = strtok(NULL, " ;");
    if (strcmp(camp, "note") == 0) {
        p = strtok(NULL, " ;");
        nota1 = (float) atof(p);
        p = strtok(NULL, " ;");
        nota2 = (float) atof(p);
        p = strtok(NULL, " ;");
        nota3 = (float) atof(p);
    } else {
        valoare = strtok(NULL, " ;");
    }
    interogare_inrolare(inrolari, nrinrolari, conditie1);
    if (complex) {
        interogare_inrolare(inrolari, nrinrolari, conditie2);
    }
    for (int i = 0; i < nrinrolari; i++) {
        if (conditie1[i] && conditie2[i]) {
            if (strcmp(camp, "id_student") == 0) {
                inrolari[i].id_student = atoi(valoare);
            } else if (strcmp(camp, "id_materie") == 0) {
                inrolari[i].id_materie = atoi(valoare);
            } else {
                inrolari[i].note[0] = nota1;
                inrolari[i].note[1] = nota2;
                inrolari[i].note[2] = nota3;
            }
        }
    }
    student *studenti = sec -> studenti;
    int nrstudenti = sec -> nr_studenti;
    for (int i = 0; i < nrstudenti; i++) {
        int nrmaterii = 0;
        studenti[i].medie_generala = 0;
        for (int j = 0; j < nrinrolari; j++) {
            if (inrolari[j].id_student == studenti[i].id) {
                nrmaterii++;
            }
        }
        if (nrmaterii != 0) {
            for (int j = 0; j < nrinrolari; j++) {
                if (inrolari[j].id_student == studenti[i].id) {
                    studenti[i].medie_generala += inrolari[j].note[0] + inrolari[j].note[1]
                    + inrolari[j].note[2];
                }
            }
            studenti[i].medie_generala = roundf(studenti[i].medie_generala * TWO_DECIMALS) / TWO_DECIMALS;
            // studenti[i].medie_generala = rotunjire2(studenti[i].medie_generala);
            studenti[i].medie_generala /= (float) nrmaterii;
            studenti[i].medie_generala = roundf(studenti[i].medie_generala * TWO_DECIMALS) / TWO_DECIMALS;
            // studenti[i].medie_generala = rotunjire2(studenti[i].medie_generala);
        }
    }
    free(conditie1);
    free(conditie2);
}

void delete_studenti(student *studenti, int *nrstudenti, int complex) {
    int n = (*nrstudenti), k = 0;
    int *conditie1 = malloc(n * sizeof(int));
    int *conditie2 = malloc(n * sizeof(int));
    student *studenti2 = calloc(n, sizeof(student));
    for (int i = 0; i < n; i++) {
        conditie2[i] = 1;
    }
    interogare_student(studenti, *nrstudenti, conditie1);
    if (complex) {
        interogare_student(studenti, *nrstudenti, conditie2);
    }
    for (int i = 0; i < n; i++) {
        if (conditie1[i] && conditie2[i]) {
        } else {
            studenti2[k] = studenti[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++) {
        studenti[i] = studenti2[i];
    }
    (*nrstudenti) = k;
    free(studenti2);
    free(conditie1);
    free(conditie2);
}

void delete_materii(materie *materii, int *nrmaterii, int complex) {
    int n = (*nrmaterii), k = 0;
    int *conditie1 = malloc(n * sizeof(int));
    int *conditie2 = malloc(n * sizeof(int));
    materie *materii2 = calloc(n, sizeof(materie));
    for (int i = 0; i < n; i++) {
        conditie2[i] = 1;
    }
    interogare_materie(materii, *nrmaterii, conditie1);
    if (complex) {
        interogare_materie(materii, *nrmaterii, conditie2);
    }
    for (int i = 0; i < n; i++) {
        if (conditie1[i] && conditie2[i]) {
        } else {
            materii2[k] = materii[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++) {
        materii[i] = materii2[i];
    }
    (*nrmaterii) = k;
    free(materii2);
    free(conditie1);
    free(conditie2);
}

void delete_inrolari(inrolare *inrolari, int *nrinrolari, int complex) {
    int n = (*nrinrolari), k = 0;
    int *conditie1 = malloc(n * sizeof(int));
    int *conditie2 = malloc(n * sizeof(int));
    inrolare *inrolari2 = calloc(n, sizeof(inrolare));
    for (int i = 0; i < n; i++) {
        conditie2[i] = 1;
    }
    interogare_inrolare(inrolari, *nrinrolari, conditie1);
    if (complex) {
        interogare_inrolare(inrolari, *nrinrolari, conditie2);
    }
    for (int i = 0; i < n; i++) {
        if (conditie1[i] && conditie2[i]) {
        } else {
            inrolari2[k] = inrolari[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++) {
        inrolari[i] = inrolari2[i];
    }
    (*nrinrolari) = k;
    free(inrolari2);
    free(conditie1);
    free(conditie2);
}

int main(int argc, char *argv[]) {
    secretariat *sec = citeste_secretariat(argv[1]);
    student *studenti = sec->studenti;
    materie *materii = sec->materii;
    inrolare *inrolari = sec->inrolari;
    int nrstudenti = sec->nr_studenti;
    int nrmaterii = sec->nr_materii;
    int nrinrolari = sec->nr_inrolari;
    char *line = calloc(LINE, sizeof(char));
    int n = 0, nrcampuri = 0;

    scanf("%d\n", &n);
    char **campuri = calloc(MAX_LENGTH, sizeof(char *));
    for (int i = 0; i < MAX_LENGTH; i++) {
        campuri[i] = calloc(MAX_LENGTH, sizeof(char));
    }
    for (int t = 0; t < n; t++) {
        fgets(line, LINE, stdin);
        line[strlen(line) - 1] = '\0';
        nrcampuri = 0;
        if (strstr(line, "SELECT")) {
            int complex = 0, filtrare = 0;
            if (strstr(line, "WHERE")) {
                filtrare = 1;
            }
            if (strstr(line, "AND")) {
                complex = 1;
            }
            char *p = strtok(line, " ");
            p = strtok(NULL, ", ");
            while (strcmp(p, "FROM") != 0) {
                snprintf(campuri[nrcampuri], strlen(p) + 1, "%s", p);
                nrcampuri++;
                p = strtok(NULL, ", ");
            }
            p = strtok(NULL, " ;");
            if (strcmp(p, "studenti") == 0) {
                int *afisari = malloc(nrstudenti * sizeof(int));
                int *afisari2 = malloc(nrstudenti * sizeof(int));
                for (int i = 0; i < nrstudenti; i++) {
                    afisari[i] = 1;
                    afisari2[i] = 1;
                }
                if (filtrare) {
                    interogare_student(studenti, nrstudenti, afisari);
                }
                if (complex) {
                    interogare_student(studenti, nrstudenti, afisari2);
                }
                for (int j = 0; j < nrstudenti; j++) {
                    if (afisari[j] && afisari2[j]) {
                        afisare_student(studenti[j], campuri, nrcampuri);
                    }
                }
                free(afisari);
                free(afisari2);
            } else if (strcmp(p, "materii") == 0) {
                int *afisari = malloc(nrmaterii * sizeof(int));
                int *afisari2 = malloc(nrmaterii * sizeof(int));
                for (int i = 0; i < nrmaterii; i++) {
                    afisari[i] = 1;
                    afisari2[i] = 1;
                }
                if (filtrare) {
                    interogare_materie(materii, nrmaterii, afisari);
                }
                if (complex) {
                    interogare_materie(materii, nrmaterii, afisari2);
                }
                for (int j = 0; j < nrmaterii; j++) {
                    if (afisari[j] && afisari2[j]) {
                        afisare_materie(materii[j], campuri, nrcampuri);
                    }
                }
                free(afisari);
                free(afisari2);
            } else {
                int *afisari = malloc(nrinrolari * sizeof(int));
                int *afisari2 = malloc(nrinrolari * sizeof(int));
                for (int i = 0; i < nrinrolari; i++) {
                    afisari[i] = 1;
                    afisari2[i] = 1;
                }
                if (filtrare) {
                    interogare_inrolare(inrolari, nrinrolari, afisari);
                }
                if (complex) {
                    interogare_inrolare(inrolari, nrinrolari, afisari2);
                }
                for (int j = 0; j < nrinrolari; j++) {
                    if (afisari[j] && afisari2[j]) {
                        afisare_inrolare(inrolari[j], campuri, nrcampuri);
                    }
                }
                free(afisari);
                free(afisari2);
            }
        } else if (strstr(line, "UPDATE")) {
            int complex = 0;
            if (strstr(line, "AND")) {
                complex = 1;
            }
            char *p = strtok(line, " ");
            p = strtok(NULL, ", ");
            if (strcmp(p, "studenti") == 0) {
                update_studenti(studenti, nrstudenti, complex);
            } else if (strcmp(p, "materii") == 0) {
                update_materii(materii, nrmaterii, complex);
            } else {
                update_inrolari(inrolari, nrinrolari, complex, sec);
            }
        } else {
            int complex = 0;
            if (strstr(line, "AND")) {
                complex = 1;
            }
            char *p = strtok(line, " ");
            p = strtok(NULL, " ");
            p = strtok(NULL, " ");
            if (strcmp(p, "studenti") == 0) {
                delete_studenti(studenti, &nrstudenti, complex);
            } else if (strcmp(p, "materii") == 0) {
                delete_materii(materii, &nrmaterii, complex);
            } else {
                delete_inrolari(inrolari, &nrinrolari, complex);
                for (int i = 0; i < nrstudenti; i++) {
                    int nrmaterii = 0;
                    studenti[i].medie_generala = 0;
                    for (int j = 0; j < nrinrolari; j++) {
                        if (inrolari[j].id_student == studenti[i].id) {
                            nrmaterii++;
                        }
                    }
                    if (nrmaterii != 0) {
                        for (int j = 0; j < nrinrolari; j++) {
                            if (inrolari[j].id_student == studenti[i].id) {
                                studenti[i].medie_generala += inrolari[j].note[0] + inrolari[j].note[1]
                                + inrolari[j].note[2];
                            }
                        }
                        studenti[i].medie_generala = roundf(studenti[i].medie_generala * TWO_DECIMALS) / TWO_DECIMALS;
                        // studenti[i].medie_generala = rotunjire2(studenti[i].medie_generala);
                        studenti[i].medie_generala /= (float) nrmaterii;
                        studenti[i].medie_generala = roundf(studenti[i].medie_generala * TWO_DECIMALS) / TWO_DECIMALS;
                        // studenti[i].medie_generala = rotunjire2(studenti[i].medie_generala);
                    }
                }
            }
        }
    }
    free(line);
    for (int i = 0; i < MAX_LENGTH; i++) {
        free(campuri[i]);
    }
    free(campuri);
    elibereaza_secretariat(&sec);
    return 0;
}
