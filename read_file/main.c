
#include "read_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 150


int main(int argc, const char * argv[]) {
    int  i, j;
    int f=0;
    char g = 'g';
    char h ='h';
    char e='e';
    char b = 'b';
    char d = 'd';
    struct variables index[N];
    Read_File(index);
    while(d != 3)
    {
    printf("Παρακαλώ κάντε την επίλογη που επιθυμείτε \n1)Αναζήτηση\n2)Εύρεση Παράξενων Κληρώσεων\n3)Έξοδος\t");
    d=getchar();
    getchar();
       // getchar();
    switch (d)
        {
        case '1':{
            printf("\n--------------->ΑΝΑΖΗΤΗΣΗ<-------------\n");
            printf("\nΚάντε αναζήτηση είτε κλήρωσης με βάση την Hμερομηνία με το κουμπί 1,\nείτε με βάση τον Aριθμό Kληρώσης με το κουμπί 2 :\n");
            b=getchar();
            getchar();
            switch (b)
            {
                case '1':
                    Search_Date(index);
                    break;
                case '2':
                    Search_Number(index);
                    break;
                default:
                    printf("\nΛαθος επιλογή,Ξαναπροσπαθήστε...\n");
                    break;
            }
            break;
        }
        case '2':
                printf("\n------------>ΕΥΡΕΣΗ ΠΑΡΑΞΕΝΩΝ ΚΛΗΡΩΣΕΩΝ<-------------\n");
                printf("\nΕπιλογή παράξενων κληρώσεων: \n\t1)τουλάχιστον τρεις αριθμούς συνεχόμενους\n\t2)τουλάχιστον τέσσερις αριθμούς σε μια δεκάδα\n\t3)τουλάχιστον τρεις αριθμούς σε ένα λήγοντα");
                e=getchar();
                getchar();
                switch (e){
                    case '1':
                        //τουλάχιστον τρεις αριθμούς συνεχόμενους
                        Three_in_Row(index);
                        break;
                    case '2':
                        //τουλάχιστον τέσσερις αριθμούς σε μια δεκάδα
                        Four_in_ten(index);
                        break;
                    case '3':
                        //τουλάχιστον τρεις αριθμούς σε ένα λήγοντα
                        Three_same_end(index);
                        break;
                    default:
                        printf("\nΛαθος επιλογή,Ξαναπροσπαθήστε...\n");
                        break;
                }
            break;

        case '3':
                printf("\n------------>ΕΥΧΑΡΙΣΤΟΥΜΕ<-------------\n");
            return 0;

        default:
            printf("\n------------>ΛΑΘΟΣ ΕΠΙΛΟΓΗ,ΞΑΝΑΠΡΟΣΠΑΘΗΣΤΕ<-------------\n");
                break;
        }
        printf("\n");
    }
    printf("\n\n");
    
    exit(1);
}


