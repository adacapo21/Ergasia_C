#include "read_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//loading and reading File

#define N 150


int Read_File(struct variables index[])
{
    int  i=0;
    char* numbers[N];
    double atof ( const char * str );
    char line[N];  /* declare a char array */
    
    FILE *fp;  /* declare a FILE pointer  */
    if ((fp = fopen("/Users/aggeloskappos/Desktop/read_file/arxeioKlhrwsewn.txt", "r")) == NULL) {
        printf("\nFile did not open");
        return -10;
    }
    else{
        while(fgets(line, sizeof line, fp)!=NULL) {
            numbers[i]=line;
            //printf("\t%d ,%s",i,line);
            fscanf(fp, "%d %s %d, %d, %d, %d, %d %d", &index[i].draw, &index[i].date, &index[i].a, &index[i].b, &index[i].c, &index[i].d, &index[i].e, &index[i].tzoker);
            i++;
        }
        printf("\n'-->File loaded to the buffer....<---'\n ");
        
        fclose(fp);
    }
    printf("\n");
    return 0;
}
int Search_Date (struct variables index[]){
    int i = 0, aux = 1;
    char date[11];
    
    printf("\nΔώστε μία από τις εξής ημερομηνίες(από %s εώς %s): ", index[N - 1].date, index[0].date);
    gets(date);
    while (aux != 0 && i < 150) {
        aux = strcmp(index[i].date, date);
        i++;
    }
    if (i == 150 && aux != 0) {
        printf("\nΚαμία κλήρωση σε αυτην την ημερομηνία δεν είναι γνωστή...\n\n");
        return -1;
    }
    printf("\nΓια την ημερομηνία που δώσατε,οι αριθμοί που κερδίζουν είναι : %d,%d,%d,%d,%d me Tzoker:%d\n\n", index[i - 1].a, index[i - 1].b, index[i - 1].c, index[i - 1].d, index[i - 1].e, index[i - 1].tzoker);
    //    exit(1);
    return aux;
}


int Search_Number (struct variables index[]){
    int number, temp;
    
    printf("\nΔώστε έναν αριθμό κλήρωσης (από %d έως %d): ", index[N - 1].draw, index[0].draw);
    scanf("%d", &number);
    getchar();
    if (number < index[N - 1].draw || number > index[0].draw) {
        printf("\nΔεν υπάρχει αυτός ο αριθμός\n\n");
        return -1;
    }
    temp = index[0].draw - number;
    printf("\nΟι αριθμοί που κερδίζουν για την κλήρωση αυτή είναι:%d,%d,%d,%d,%d με Τζόκερ:%d\n\n", index[temp].a, index[temp].b, index[temp].c, index[temp].d, index[temp].e, index[temp].tzoker);
    return temp;
    //exit(1);
    return number;
    
    
}
/*********------>Παράξενες κληρώσεις<-------********/
int Three_in_Row(struct variables index[]){
    int j, counter = 0;
    //Ελέγχω 3 φορές τους αριθμούς της κλήρωσης τον έναν με τον άλλον
    for (j = 0; j < N; j++)
    {
        if ((index[j].a+2 == index[j].c) && (index[j].b+1 == index[j].c))
        {
            printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[j].draw, index[j].date, index[j].a, index[j].b, index[j].c, index[j].d, index[j].e, index[j].tzoker);
            printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[j].a, index[j].b, index[j].c);
            counter++;
        }
        else if ((index[j].b+2 == index[j].d) && (index[j].c+1 == index[j].d ))
        {
            printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[j].draw, index[j].date, index[j].a, index[j].b, index[j].c, index[j].d, index[j].e, index[j].tzoker);
            printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[j].b, index[j].c, index[j].d);
            counter++;
        }
        else if ((index[j].c+2 == index[j].e) && (index[j].d+1 == index[j].e ))
        {
            printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[j].draw, index[j].date, index[j].a, index[j].b, index[j].c, index[j].d, index[j].e, index[j].tzoker);
            printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[j].c, index[j].d, index[j].e);
            counter++;
        }
    }
    if (counter == 0) {
        printf("\n\nΔυστυχώς δεν υπάρχει τίποτα σχετικό.\n\n");
    }
    else {
        printf("\n\nΣύνολο κληρώσεων είναι :%d\n\n", counter);
    }
    
    return 1;
}

int Four_in_ten(struct variables index[]){
    int i, j, A, B, counter = 0;
    
    printf("\n\nα)Αρχικά ορίζω δυο αριθμούς Συνορα (Α,Β),μετά ελεγχω ανα 4,αν κάθε τετράδα αριθμών ανήκει στην δεκάδα αυτών\nβ)Έπειτα αφού ελεγξω κάθε πιθανή τετράδα αυξάνω κατα 10 τους αριθμούς Σύνορα\n");
    for (i = 0; i < N; i++)
    {
        A = 0;
        B = 11;
        for (j = 0; j < 4; j++)
        {
            if ((A < index[i].a && index[i].a < B) && (A < index[i].b && index[i].b < B) && (A < index[i].c && index[i].c < B) && (A < index[i].d && index[i].d < B)) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d,%d", index[i].a, index[i].b, index[i].c, index[i].d);
                counter++;
            }
            else if ((A < index[i].b && index[i].b < B) && (A < index[i].c && index[i].c < B) && (A < index[i].d && index[i].d < B) && (A < index[i].e && index[i].e < B)) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d,%d", index[i].b, index[i].c, index[i].d, index[i].e);
                counter++;
            }
            A = A + 10;
            B = B + 10;
        }
    }
    if (counter == 0) {
        printf("\n\nΔυστυχώς δεν υπάρχει τίποτα σχετικό.\n\n");
    }
    else {
        printf("\n\nΣύνολο κληρώσεων είναι :%d\n\n", counter);
    }
    
    return 1;
}
int Three_same_end(struct variables index[]){
    
    int i, counter = 0, end;
    printf("\n\nΑφαιρούμε τους αριθμούς μεταξύ τους και αν το υπόλοιπο τους διαρώντας το δια 10 ειναι μηδέν τότε έχουν ίδιο λήγοντα\n\n");
    for (i = 0; i < N; i++)
    {
        end = 0;
        if ((index[i].e - index[i].d) % 10 == 0)
        {
            if ((index[i].e - index[i].c) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].c, index[i].d, index[i].e);
                counter++;
                end++;
            }
            else if ((index[i].e - index[i].b) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].b, index[i].d, index[i].e);
                counter++;
                end++;
            }
            else if ((index[i].e - index[i].a) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].a, index[i].d, index[i].e);
                counter++;
                end++;
            }
        }
        if ((end == 0) && ((index[i].e - index[i].c) % 10 == 0))
        {
            if ((index[i].e - index[i].b) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].b, index[i].c, index[i].e);
                counter++;
                end++;
            }
            else if ((index[i].e - index[i].a) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].a, index[i].c, index[i].e);
                counter++;
                end++;
            }
        }
        if ((end == 0) && ((index[i].e - index[i].b) % 10 == 0) && ((index[i].e - index[i].a) % 10 == 0))
        {
            printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
            printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].a, index[i].b, index[i].e);
            counter++;
            end++;
        }
        if ((end == 0) && ((index[i].d - index[i].c) % 10 == 0))
        {
            if ((index[i].d - index[i].b) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].b, index[i].c, index[i].d);
                counter++;
                end++;
            }
            else if ((index[i].d - index[i].a) % 10 == 0) {
                printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
                printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].a, index[i].c, index[i].d);
                counter++;
                end++;
            }
        }
        if ((end == 0) && ((index[i].c - index[i].b) % 10 == 0) && ((index[i].c - index[i].a) % 10 == 0))
        {
            printf("\n\nΚλήρωση:%d\t Ημερομηνία:%s\t Αριθμοί:%d,%d,%d,%d,%d\tΤζόκερ:%d", index[i].draw, index[i].date, index[i].a, index[i].b, index[i].c, index[i].d, index[i].e, index[i].tzoker);
            printf("\nΑριθμοί στην σειρά είναι: %d,%d,%d", index[i].a, index[i].b, index[i].c);
            counter++;
        }
    }
    if (counter == 0) {
        printf("\n\nΔυστυχώς δεν υπάρχει τίποτα σχετικό.\n\n");
    }
    else {
        printf("\n\nΣύνολο κληρώσεων είναι :%d\n\n", counter);
    }
    return 1;
}

//***** Παιχνίδι******//

int One_Date_Game(struct variables index[]){
    int i, flag, numbers[6], counter = 0, tzoker = 0;
    
    do {
        printf("\nΕπιλέξτε τους 5 + 1 αριθμούς που θέλετε να παιξετε ");
        scanf("%d %d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5]);
        getchar();
    }
    //μέχρι να βρει αριθμούς που ξεπερνάνε τα όρια του παιχνιδιού (1-45),τζοκερ (1-20)
    while (numbers[0] < 1 || numbers[0]>45 || numbers[1] < 1 || numbers[1]>45 || numbers[2] < 1 || numbers[2]>45 || numbers[3] < 1 || numbers[3]>45 || numbers[4] < 1 || numbers[4]>45 || numbers[5] < 1 || numbers[5]>20);
    flag = Search_Date(index);
    printf("flag: %d" , flag);
    if (flag < 0) {
        return -50;
    }
    else
    {
        printf("επιλέξατε και εσείς τους αριθμους:");
        for (i = 0; i < 5; i++)
        {
            if (numbers[i] == index[flag].a || numbers[i] == index[flag].b || numbers[i] == index[flag].c || numbers[i] == index[flag].d || numbers[i] == index[flag].e) {
                printf("%d , %d",numbers[i],index[flag].a );
                printf(" %d", numbers[i]);
                counter++;
            }
        }
        if (numbers[5] == index[flag].tzoker) {
            printf("\nκαι τον αριθμό τζοκερ %d", numbers[5]);
            tzoker++;
        }
        if ((counter > 0 && tzoker == 1) || counter>2) {
            printf("\n\nΣυγχαρητηρια! Κατηγορία:%d", counter);
            if (tzoker == 1) {
                printf(" + 1");
            }
        }
        else {
            printf("\n\nΔεν πειράζει...Την επόμενη φορά θα είστε πιο τυχερός\n\n");
        }
    }
    return 0;
    
}

int Dates_Game(struct variables index[]){
    int  i, j,  numbers[6], arxi = -1, telos = -1 ,counter, tzoker;
    
    while (arxi < 0) {
        arxi = Search_Game_Date(index);
    }
    while (telos < 0) {
        telos = Search_Game_Date(index);
    }
    do {
        printf("\nΕπιλέξτε τους 5 + 1 αριθμούς που θέλετε να παιξετε :");
        scanf("%d %d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5]);
        getchar();
    }     //μέχρι να βρει αριθμούς που ξεπερνάνε τα όρια του παιχνιδιού (1-45),τζοκερ (1-20)
    while (numbers[0] < 1 || numbers[0]>45 || numbers[1] < 1 || numbers[1]>45 || numbers[2] < 1 || numbers[2]>45 || numbers[3] < 1 || numbers[3]>45 || numbers[4] < 1 || numbers[4]>45 || numbers[5] < 1 || numbers[5]>20);
    for (j = telos; j <= arxi; j++)
    {
        counter = 0;
        tzoker = 0;
        printf("\nΗμερομηνία:%s -> %d,%d,%d,%d,%d\t%d", index[j].date, index[j].a, index[j].b, index[j].c, index[j].d, index[j].e, index[j].tzoker);
        printf("\nΠετυχατε τους αριθμούς");
        for (i = 0; i < 5; i++)
        {
            if (numbers[i] == index[j].a || numbers[i] == index[j].b || numbers[i] == index[j].c || numbers[i] == index[j].d || numbers[i] == index[j].e) {
                printf(" %d", numbers[i]);
                counter++;
            }
        }
        if (numbers[5] == index[j].tzoker) {
            printf("\nΑριθμός τζοκερ %d", numbers[5]);
            tzoker++;
        }
        if ((counter > 0 && tzoker == 1) || counter>2) {
            printf("\n\nΣυγχαρητηρια! Κατηγορία:%d", counter);
            if (tzoker == 1) {
                printf(" + 1");
            }
            printf("\n\n");
        }
        else {
            printf("\n\nΔεν πειράζει...Την επόμενη φορά θα είστε πιο τυχερός\n\n");
        }
    }
    return 0;
    
}



int Search_Game_Date (struct variables index[]){
    int i = 0, aux = 1;
    char date[11];
    
    printf("\nΔώστε μία από τις εξής ημερομηνίες(από %s εώς %s): ", index[N - 1].date, index[0].date);
    gets(date);
    while (aux != 0 && i < 150) {
        aux = strcmp(index[i].date, date);
        i++;
    }
    if (i == 150 && aux != 0) {
        printf("\nΚαμία κλήρωση σε αυτην την ημερομηνία δεν είναι γνωστή...\n\n");
        return -1;
    }
    
    return aux;
}
