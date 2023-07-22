#include "data.h"

void pre_asembler(char* file_name)
{
 copyFile(inputFilename,outputFilename);
 removeEmptyLines(outputFilename);
 removeComments(outputFilename);
 removeMcroLines(outputFilename);


}
void copyFile(const char* inputFilename, const char* outputFilename) {
    FILE* inputFile = fopen(inputFilename, "r");
    FILE* outputFile = fopen(outputFilename, "w");
    char ch;

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void removeEmptyLines(const char* filename) {
FILE* file;
    FILE* tempFile;
    char line[1000];
    int i;

    /* Open the input file */
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    /* Open a temporary file for writing */
    tempFile = tmpfile();
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    /* Copy the input file to the temporary file, excluding empty lines */
    while (fgets(line, sizeof(line), file) != NULL) {
        int isEmpty = 1;  /* Flag to check if the line is empty or contains only whitespace characters */

        for (i = 0; line[i] != '\0'; i++) {
            if (!isspace(line[i])) {
                isEmpty = 0;
                break;
            }
        }

        if (!isEmpty) {
            fputs(line, tempFile);
        }
    }

    /* Close the input file */
    fclose(file);

    /* Reset the file position indicator of the temporary file */
    rewind(tempFile);

    /* Open the input file for writing */
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        fclose(tempFile);
        return;
    }

    /* Copy the contents from the temporary file back to the input file */
    while (fgets(line, sizeof(line), tempFile) != NULL) {
        fputs(line, file);
    }

    /* Close the temporary file */
    fclose(tempFile);

    /* Close the input file */
    fclose(file);

    printf("Empty lines removed successfully from the file.\n");
}
void removeComments(const char* fileName) {
    FILE* file;
    FILE* temp;
    char line[1000];

    /* Open the input file */
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    /* Create a temporary file */
    temp = tmpfile();
    if (temp == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    /* Remove lines starting with a semicolon from the input file */
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] != ';') {
            fputs(line, temp);
        }
    }

    /* Reset the file position indicator of the temporary file */
    rewind(temp);

    /* Open the input file for writing */
    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        fclose(temp);
        return;
    }

    /* Copy the contents from the temporary file back to the input file */
    while (fgets(line, sizeof(line), temp) != NULL) {
        fputs(line, file);
    }

    /* Close the input file */
    fclose(file);

    /* Close the temporary file */
    fclose(temp);
}

void list_init(List* list)
{
    list->first.next = NULL;
    list->head = &list->first;
}

char *getLine(FILE *fp)
{
    char temp[SIZE_OF_ROW];
    
    fgets(temp, SIZE_OF_ROW, fp);
    temp[strlen(temp) - 1] = '\0';
    return strdup(temp);
}

//in main make arry of hash table with pointer
 void hashTable(char *hashAdrese, NODE arryOfNodes[SIZE_OF_ROW], NODE *p)
{
    hashAdrese =  (ptr->mcroName / SIZE_OF_ROW) % 10;
    arryOfNodes[hashAdrese] = p;
}

void list_add_lines(List * ptr, FILE *in_fp)
{
    
    FILE *fp_deleteLine;
    fp_deleteLine = fopen("file.txt", "wt");
    int flagFindMcro  = 0;
    //FILE *in_fp;
    //in_fp = fopen("file.dat", "rt");
    /* if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    */
    
    //first creat memory for NODE
    NODE newNode = malloc(size_t(NODE));
    
    //first check if the name of the mcro existing
    
    if (newNode->mcroName == '0')
    {
         while (fscanf(in_fp, "%s", newNode->mcroName ) == "MCRO" && flagFindMcro)
         {
            fscanf(in_fp, "%s", newNode->mcroName ); 
            printf("%s\n", newNode->mcroName);
            hashTable(newNode->mcroName);
            flagFindMcro = 1;
         }

    }
    
    if (newNode->mcroSentences == NULL)
    {
        newNode->mcroSentences = malloc(size_t(NODE) * SIZE_OF_ROW);
        if (newNode->mcroSentences == NULL)
        {
            printf("there is't space");
            exit(1);
        }
        
        newNode->mcroSentence = *getLine(in_fp);
        
    }
    else
    {
        int i = 1;
        while (!flagFindMcro)
        {
            
        newNode->mcroSentences = realloc(size_t(NODE) * SIZE_OF_ROW);
        if (newNode->mcroSentences == NULL)
        {
            printf("there is't space");
            exit(1);
        }
        
        if (fscanf(in_fp, "%s", newNode->mcroSentences) == "endmcro")
        {
            //delete all lines that be reading 
            deleteLines(fp_deleteLine);
            flagFindMcro = 0;
        }    
        newNode->mcroSentence[i] = *getLine(in_fp);
        i++;
        }
        
    }
    
    newNode->next = NULL;    
    for (ptr = ptr->head; ptr->next != NULL; ptr = ptr->next)
    {
        
    }
    
    ptr->next = newNode;
    
    
    //moving the pointer to the last position like the reading pointer
    fp_deleteLine = in_fp;
    
    }
    
    
    void findMcroInMain(char hashTable,const char fileName)
    {
        char buffer[SIZE_MAX_NAME_MCRO];
        FILE *fp, *out_fp;
        fp = fopen("file.txt", "r");
        out_fp = fopen("file.txt", "w");
        
        while(ch = getc(fp) != EOF)
        {
            fscanf(fp, "%s", buffer);
            
            if(arryOfNodes[hashTable(getLine(fp))]->mcroName ==  buffer)
            {
                //write all lines of NODE
                fprintf(out_fp,"%s",arryOfNodes[hashTable(getLine(fp))]->mcroSentences);
                
            }
        }
       
}

void removeMcroLines(const char* filename) {
    FILE* file;
    FILE* tempFile;
    char line[1000];
    int i;
    int isMacro = 0;     /* Flag to check if the line is macro */
    int doneMacro = 0;   /* Flag to check if the line is endmacro */

    /* Open the input file */
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    /* Open a temporary file for writing */
    tempFile = fopen("tempfile.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    /* Copy the input file to the temporary file, excluding macro lines */
    while (fgets(line, sizeof(line), file) != NULL) {
        doneMacro = 0;
        for (i = 0; line[i] != '\0'; i++) {
            if (strncmp(&line[i], "mcro", 4) == 0) {
                isMacro = 1;
                break;
            }
            if (strncmp(&line[i], "endmcro", 7) == 0) {
                isMacro = 0;
                doneMacro = 1;
                break;
            }
        }

        if (!isMacro && !doneMacro) {
            fputs(line, tempFile);
        }
    }

    /* Close the input file */
    fclose(file);

    /* Close the temporary file */
    fclose(tempFile);

    /* Remove the original file and rename the temporary file */
    remove(filename);
    rename("tempfile.txt", filename);

    printf("Macro lines removed successfully from the file.\n");
}
