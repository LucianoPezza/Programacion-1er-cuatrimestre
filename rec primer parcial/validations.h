#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

int getOption(int);
void getUnvalidatedString(char[], char[]);
int getString(char[], char[]);
int getInt(char[]);
int itsNumeric(char[]);
int getStringNumbers(char[], char[]);
int itsTitle(char title[]);
int getTitleValidated(char text[], char input[]);
int confirmChanges(int);
//int loadedMovie(sMovie movieList[], int len);


int isTitle(char* inputData);
int isLetter(char inputData);

#endif // VALIDATIONS_H_INCLUDED
