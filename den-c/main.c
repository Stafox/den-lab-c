#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int lineLength = 200;
const char separator[] = " ";
FILE *inputFile, *outputFile;
int storage[25][25];
int rows = 0, cols = 0;
char *element;

int main(void)
{
    if(NULL != (inputFile = fopen("h1.txt", "r"))) {
        char *line[lineLength];
        while(NULL != fgets(line, lineLength, inputFile)) {
            element = strtok(line, separator);
            cols = 0;
            while(NULL != element) {
                storage[rows][cols] = atoi(element);
                cols++;
                element = strtok(NULL, separator);

            }
            rows++;
        }
        fclose(inputFile);
    } else {
    }

    if (NULL != (outputFile = fopen("f2.txt", "w+"))) {
        int i, j;
        double value;

        for (j = 0; j < rows; j++) {
            for (i = 0; i < cols; i++) {
                int key = (i + 2 >= cols) ? i + 2 - cols : i + 2;
                value = storage[j][i] / (1 + pow(storage[j][key], 2));
                printf("%f ", value);
                fprintf(outputFile, "%f ", value);
            }
            printf("\n", value);
            fprintf(outputFile, "\n");
        }
        fclose(outputFile);
    } else {
    }
    return 0;
}
