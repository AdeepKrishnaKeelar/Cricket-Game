#include<cstdio>
#include<iomanip>
#include<iostream>
#include<time.h>

#define FILE_NAME 1024
#define MAX_SIZE 2048
int main(void) {
    int read_line, curr_line=1, read_line2, curr_line2=1;
    bool keep_reading=true;
    FILE *file, *file2;
    char file_name[]="Player_Names.txt";
    char file_name2[]="Players_Names_Last.txt";
    char *buffer=(char *)malloc(MAX_SIZE*sizeof(char));
    char *buffer2=(char *)malloc(MAX_SIZE*sizeof(char));
    srand(time(0));
    read_line=rand()%13;
    read_line2=rand()%5;
    if(read_line==0) {
        read_line+=1;
    }
    if (read_line2==0) {
        read_line2+=1;
    }
    
    file=fopen64(file_name,"r");
    file2=fopen64(file_name2,"r");
    if(file==NULL && file2==NULL) {
        std::printf("Error in reading the file!");
        return 1;
    }

    do {
        fgets(buffer,MAX_SIZE,file);
        if(feof(file)) {
            keep_reading=false;
            std::printf("Operation failed!");
        } else if(curr_line==read_line) {
            keep_reading=false;
            std::printf("%s",buffer);
        }
        curr_line++;
    }while(keep_reading);

    fclose(file);
    free(buffer);

    do {
        fgets(buffer2,MAX_SIZE,file2);
        if(feof(file2)) {
            keep_reading=false;
            std::printf("Second file failed!");
        } else if(curr_line2==read_line2) {
            keep_reading=false;
            std::printf("%s",buffer2);
        }
        curr_line2++;
    }while(keep_reading);

    fclose(file2);
    free(buffer2);
    return EXIT_SUCCESS;
}