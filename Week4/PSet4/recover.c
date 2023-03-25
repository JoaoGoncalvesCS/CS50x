#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Checking if the argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //Oppening the file to read
    FILE *input_file = fopen(argv[1], "r");

    //Checking if the input_file is valid
    if (input_file == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    //Store the blocks of 512bytes into an array
    unsigned char buffer[512];

    //Tracking the number of images generated
    int count_image = 0;

    //File pointer for the recovered images
    FILE *output_file = NULL;

    //File name of 8bytes
    char *filename = malloc(8 * sizeof(char));

    //Read the blocks of 512bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //Check if initial bytes indicate a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
          //Write the JPEG filenames
          sprintf(filename, "%03i.jpg", count_image);

          //Open the output files for writting
          output_file = fopen(filename, "w");

          //Count the number of images found
          count_image++;
        }
        //Check if the output has been used for a valid input
        if (output_file != NULL)
        {
          fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);
    return 0;
}