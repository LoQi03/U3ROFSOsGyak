#include <stdio.h>

int main() {
    FILE *file = fopen("NagyMate.txt","w");
    fprintf(file,"Név: Nagy Máté \nSzak: Programtervező informatikus \nNeptunkod: U3ROFS");
    fclose(file);
    return 0;
}
