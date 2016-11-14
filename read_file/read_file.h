


#ifndef read_file_h
#define read_file_h

#endif /* read_file_h */

typedef struct variables *var;

struct variables {
    int a, b, c, d, e; //antistoixoun se kathe arithmo tis kathe kliirwsis (1-1)
    int tzoker;         //arithmos tzoker
    int draw;
    char date[11];
};

int Read_File(struct variables index[]);
int Search_Date (struct variables index[]);
int Search_Number (struct variables index[]);
int Three_in_Row(struct variables index[]);
int Four_in_ten(struct variables index[]);
int Three_same_end(struct variables index[]);
int One_Date_Game(struct variables index[]);
int Dates_Game(struct variables index[]);
int Width_System(struct variables index[]);
//int One_Date_System(struct variables index[]);
//int Search_Game_Date(struct variables index[]);