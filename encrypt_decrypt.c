#include <stdio.h>

int main() {
    FILE *input, *output;
    char inputFile[100], outputFile[100];
    int key;
    int ch;
    
    printf("=== FILE ENCRYPTION (XOR) ===\n\n");
    
    printf("Enter input filename: ");
    scanf("%s", inputFile);
    
    printf("Enter output filename: ");
    scanf("%s", outputFile);
    
    printf("Enter key (number 1-255): ");
    scanf("%d", &key);
    
    input = fopen(inputFile, "rb");  
    if(input == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }
    
    output = fopen(outputFile, "wb");
    if(output == NULL) {
        printf("Error: Cannot create output file!\n");
        fclose(input);
        return 1;
    }
    
    // Encrypt using XOR
    while((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;  // XOR with key
        fputc(ch, output);
    }
    
    fclose(input);
    fclose(output);
    
    printf("\nFile encrypted successfully!\n");
    printf("Run with the SAME key to decrypt\n");
    
    return 0;
}