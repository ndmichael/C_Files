#include <stdio.h>
#include <stdlib.h>

void main() {
    /*  initialize identifiers */
    FILE *filePointer;
    char dataRead[200], ch;
    int lines, characters, words;

    /* assign identifiers */
    lines = characters = words = 0;


    char paragraph[] = "For a long time it puzzles me how something so expensive so leading edge, \n \
    would be so useless. And then it occurered to me that a computer is a stupid machine \n \
    with the ability to do incredibly smart things, while computer programmers are \n \
    smart people with the ability to do incredibly stupid things. They are in short , a perfect match";

    filePointer = fopen("narry.txt", "w");


    // Terminates if null
    if(filePointer == NULL){
        printf("File failed to load");
        exit(EXIT_FAILURE);
    } else {

        printf("File successfully opened \n");

        //printf("the size of an array is %d", sizeof(paragraph)/ sizeof(paragraph[0]));


            fputs(paragraph, filePointer);
            fputs("\n", filePointer);

        fclose(filePointer);
        printf("data successfully written \n");
    }
    filePointer = fopen("narry.txt", "r");

    if(filePointer == NULL){
        printf("file is empty");
    }
    else{
            while(fgets (dataRead, 100, filePointer) != NULL){
                printf("%s \n", dataRead);
            }
            printf("data successfully read \n");
            // take the cursor back to beginning
            rewind(filePointer);
    }


    if(filePointer == NULL){
        printf("FILE FAILED TO PARSE \n");
        exit(EXIT_FAILURE);
    }else {
        /* loop through the file and calculate words */
        for (ch = getc(filePointer); ch != EOF; ch = getc(filePointer)){
            characters++;
            if(ch == '\0' || ch == '\n')
                lines = lines + 1;

            if (ch==' ' || ch=='\t' || ch=='\n')
                words++;
        }
    }

    fclose(filePointer);
    printf("Numbers of lines %d \n", lines);
    printf("Numbers of words %d \n", words);
    printf("Numbers of characters %d \n", characters);

}
