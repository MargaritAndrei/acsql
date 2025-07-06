#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

float rotunjire(float var) {
    float value = (float)((int)(var * TWO_DECIMALS + ROUND));
    value /= (float) TWO_DECIMALS;
    return value;
}

secretariat *citeste_secretariat(const char *nume_fisier) {
    char *line = calloc(LINE, sizeof(char));
    int nrstudenti = -1, nrmaterii = -1, nrinrolari = 0;
    FILE *fisier = fopen(nume_fisier, "r");
    FILE *g = fopen("test.out", "w");
    fgets(line, LINE, fisier);
    do {
        fgets(line, LINE, fisier);
        nrstudenti++;
    } while (line[0] != '[');

    do {
        fgets(line, LINE, fisier);
        nrmaterii++;
    } while (line[0] != '[');

    while (fgets(line, LINE, fisier)) {
        nrinrolari++;
    }

    struct student *studenti = malloc(nrstudenti * sizeof(struct student));
    struct materie *materii = malloc(nrmaterii * sizeof(struct materie));
    struct inrolare *inrolari = malloc(nrinrolari * sizeof(struct inrolare));
    secretariat *sec = malloc(sizeof(secretariat));

    fseek(fisier, 0, SEEK_SET);

    fgets(line, LINE, fisier);
    for (int i = 0; i < nrstudenti; i++) {
        fgets(line, LINE, fisier);
        int n = (int) strlen(line);
        line[n - 1] = '\0';
        char *p = strtok(line, ",");
        studenti[i].id = atoi(p);
        p = strtok(NULL, ",");
        p++;
        snprintf(studenti[i].nume, strlen(p) + 1, "%s", p);
        p = strtok(NULL, ",");
        p++;
        studenti[i].an_studiu = atoi(p);
        p = strtok(NULL, ",");
        p++;
        studenti[i].statut = p[0];
    }
    fgets(line, LINE, fisier);
    for (int i = 0; i < nrmaterii; i++) {
        fgets(line, LINE, fisier);
        int n = (int) strlen(line);
        line[n - 1] = '\0';
        char *p = strtok(line, ",");
        materii[i].id = atoi(p);
        p = strtok(NULL, ",");
        p++;
        materii[i].nume = malloc(strlen(p) + 1);
        snprintf(materii[i].nume, strlen(p) + 1, "%s", p);
        p = strtok(NULL, ",");
        p++;
        materii[i].nume_titular = malloc(strlen(p) + 1);
        snprintf(materii[i].nume_titular, strlen(p) + 1, "%s", p);
    }
    fgets(line, LINE, fisier);
    for (int i = 0; i < nrinrolari; i++) {
        fgets(line, LINE, fisier);
        int n = (int) strlen(line);
        line[n - 1] = '\0';
        char *p = strtok(line, ",");
        inrolari[i].id_student = atoi(p);
        p = strtok(NULL, ",");
        p++;
        inrolari[i].id_materie = atoi(p);
        p = strtok(NULL, ", ");
        inrolari[i].note[0] = (float) atof(p);
        p = strtok(NULL, " ");
        inrolari[i].note[1] = (float) atof(p);
        p = strtok(NULL, " ");
        inrolari[i].note[2] = (float) atof(p);
    }
    for (int i = 0; i < nrstudenti; i++) {
        int nrmaterii = 0;
        studenti[i].medie_generala = 0;
        for (int j = 0; j < nrinrolari; j++) {
            if (inrolari[j].id_student == studenti[i].id) {
                nrmaterii++;
            }
        }
        for (int j = 0; j < nrinrolari; j++) {
            if (inrolari[j].id_student == studenti[i].id) {
                studenti[i].medie_generala += inrolari[j].note[0] + inrolari[j].note[1]
                + inrolari[j].note[2];
            }
        }
        studenti[i].medie_generala = rotunjire(studenti[i].medie_generala);
        studenti[i].medie_generala /= (float) nrmaterii;
        studenti[i].medie_generala = rotunjire(studenti[i].medie_generala);
    }
    sec->studenti = studenti;
    sec->nr_studenti = nrstudenti;
    sec->materii = materii;
    sec->nr_materii = nrmaterii;
    sec->inrolari = inrolari;
    sec->nr_inrolari = nrinrolari;
    free(line);
    fclose(fisier);
    return sec;
}

void adauga_student(secretariat *s, int id, char *nume, int an_studiu, char statut, float medie_generala) {
    s->nr_studenti++;
    s->studenti[s->nr_studenti - 1].id = id;
    snprintf(s->studenti[s->nr_studenti - 1].nume, strlen(nume) + 1, "%s", nume);
    s->studenti[s->nr_studenti - 1].an_studiu = an_studiu;
    s->studenti[s->nr_studenti - 1].statut = statut;
    s->studenti[s->nr_studenti - 1].medie_generala = medie_generala;
}

void elibereaza_secretariat(secretariat **s) {
    free((*s)->studenti);
    for (int i = 0; i < (*s)->nr_materii; i++) {
        free((*s)->materii[i].nume);
        free((*s)->materii[i].nume_titular);
    }
    free((*s)->materii);
    free((*s)->inrolari);
    free(*s);
    *s = NULL;
}
