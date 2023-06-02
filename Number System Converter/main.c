#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>

typedef struct{
    long int binary;
    int decimal;
    int octal;
    int hexadecimal;
    char hex[32];
}NumberSystem;

NumberSystem numSystem;

void print_menu();
void print_binary_menu();
int bi_to_dec(int);
void print_bi_to_dec();
void calculate_bi_to_oct();
void calculate_bi_to_hex();
void bi_choices(int);
void print_decimal_menu();
void calculate_dec_to_bi();
void calculate_dec_to_oct();
void calculate_dec_to_hex();
void dec_choices(int);
void print_octal_menu();
void calculate_oct_to_bi();
void calculate_oct_to_dec();
void calculate_oct_to_hex();
void oct_choices(int);
void print_hex_menu();
void calculate_hex_to_bi();
void calculate_hex_to_dec();
void calculate_hex_to_octal();
void hex_choices(int);

int main()
{
    char choice;
    int convert;

    while(1)
    {
        print_menu();
        printf("\n\t\t\tEnter your Number System choice:--> ");
        scanf(" %c", &choice);

        if(toupper(choice) == 'B')
        {
            bi_choices(convert);
        }
        else if(toupper(choice) == 'D')
        {
            dec_choices(convert);
        }
        else if(toupper(choice) == 'O')
        {
            oct_choices(convert);
        }
        else if(toupper(choice) == 'H')
        {
            hex_choices(convert);
        }
        else if(toupper(choice) == 'E')
        {
            exit(1);
        }
        printf("\n\npress any key to continue...");
        getch();
    }

    return 0;
}
void print_menu()
{
    system("cls");
    printf("\033[0;32m");//color of text
    printf("\n\n\t\t\t========== WELCOME TO NUMBER SYSTEM CONVERTION ==========\n");
    printf("\t\t\t||                                                     ||\n");
    printf("\t\t\t||\t\t   \033[0;37m[B] BINARY                          \033[0;32m||\n");
    printf("\t\t\t||\t\t   \033[0;36m[D] DECIMAL                         \033[0;32m||\n");
    printf("\t\t\t||\t\t   \033[0;31m[O] OCTAL                           \033[0;32m||\n");
    printf("\t\t\t||\t\t   \033[0;33m[H] HEXADECIMAL                     \033[0;32m||\n");
    printf("\t\t\t||\t\t   [E] Exit                            ||\n");
    printf("\t\t\t||                                                     ||\n");
    printf("\t\t\t=========================================================\n\n");
}

void print_hex_menu()
{
    system("cls");
    printf("\033[0;33m");//color of text
    printf("\n\n\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|         HEXADECIMAL CONVERSION MENU           |\n");
    printf("\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|\t    [1] HEXADECIMAL TO BINARY           |\n");
    printf("\t\t\t|\t    [2] HEXADECIMAL TO DECIMAL          |\n");
    printf("\t\t\t|\t    [3] HEXADECIMAL TO OCTAL            |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t+_______________________________________________+\n\n\n");
}

void hex_choices(int convert)
{
    print_hex_menu();
        printf("\t\t\tEnter your choice to convert:--> ");
        scanf("%d", &convert);

        if(convert == 1)
        {
            calculate_hex_to_bi();
        }
        else if(convert == 2)
        {
            calculate_hex_to_dec();
        }
        else if(convert == 3)
        {
            calculate_hex_to_octal();
        }
        else
        {
            printf("\t\t\tEnter a valid choice");
        }
}

void calculate_hex_to_bi()
{
    numSystem.hex[32];

    system("cls");
    printf("========================= HEXADECIMAL TO BINARY CONVERSION =========================\n\n");
    printf("\t\t\tEnter an hexadecimal number:--> ");
    scanf("%s", &numSystem.hex);

    int x = 0;
    char binary[128] = "";
    for (x = 0; x < strlen(numSystem.hex); x++) {
        switch (numSystem.hex[x]) {
        case '0':
            strcat(binary, "0000");
            break;
        case '1':
            strcat(binary, "0001");
            break;
        case '2':
            strcat(binary, "0010");
            break;
        case '3':
            strcat(binary, "0011");
            break;
        case '4':
            strcat(binary, "0100");
            break;
        case '5':
            strcat(binary, "0101");
            break;
        case '6':
            strcat(binary, "0110");
            break;
        case '7':
            strcat(binary, "0111");
            break;
        case '8':
            strcat(binary, "1000");
            break;
        case '9':
            strcat(binary, "1001");
            break;
        case 'A':
        case 'a':
            strcat(binary, "1010");
            break;
        case 'B':
        case 'b':
            strcat(binary, "1011");
            break;
        case 'C':
        case 'c':
            strcat(binary, "1100");
            break;
        case 'D':
        case 'd':
            strcat(binary, "1101");
            break;
        case 'E':
        case 'e':
            strcat(binary, "1110");
            break;
        case 'F':
        case 'f':
            strcat(binary, "1111");
            break;
        default:
            printf("\n Invalid hexadecimal digit %c ", numSystem.hex[x]);
        }
    }

    printf("\n\n\t\t\tEquivalent Binary Number:--> %s\n", binary);

    // Writing the result to a CSV file
    FILE* file;
    file = fopen("hexToBin.csv", "w");
    fprintf(file, "Hexadecimal,Binary\n"); // Write the header
    fprintf(file, "%s,%s\n", numSystem.hex, binary); // Write the data
    fclose(file);
}

void calculate_hex_to_dec()
{
    numSystem.decimal = 0;
    int i;
    int cnt = 0; /*for power index*/
    int dig; /*to store digit*/

    system("cls");
    printf("========================= HEXADECIMAL TO DECIMAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter an hexadecimal number:--> ");
    scanf("%s", &numSystem.hex);

    for (i = (strlen(numSystem.hex) - 1); i >= 0; i--) {
        switch (numSystem.hex[i]) {
        case 'A':
            dig = 10;
            break;
        case 'B':
            dig = 11;
            break;
        case 'C':
            dig = 12;
            break;
        case 'D':
            dig = 13;
            break;
        case 'E':
            dig = 14;
            break;
        case 'F':
            dig = 15;
            break;
        default:
            dig = numSystem.hex[i] - 0x30;
        }
        numSystem.decimal = numSystem.decimal + (dig)*pow((double)16, (double)cnt);
        cnt++;
    }

    printf("\n\n\t\t\tEquivalent Decimal Number:--> %d", numSystem.decimal);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("hexToDecimal.csv", "w");
    fprintf(file, "Hexadecimal,Decimal\n");// Write the header
    fprintf(file, "%s,%d\n", numSystem.hex, numSystem.decimal);// Write the data
    fclose(file);
}

void calculate_hex_to_octal()
{
    int x,length,numbers=0,powered=0,decimal=0,remainder[100];

    system("cls");
    printf("========================= HEXADECIMAL TO OCTAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter an hexadecimal number:--> ");
    scanf("%s", &numSystem.hex);

    for(x=strlen(numSystem.hex)-1;x>=0;x--)
    {
        if(numSystem.hex[x]=='A'||numSystem.hex[x]=='a')
        {
            numbers=10;
        }
        else if(numSystem.hex[x]=='B'||numSystem.hex[x]=='b')
        {
            numbers=11;
        }
        else if(numSystem.hex[x]=='C'||numSystem.hex[x]=='c')
        {
            numbers=12;
        }
        else if(numSystem.hex[x]=='D'||numSystem.hex[x]=='d')
        {
            numbers=13;
        }
        else if(numSystem.hex[x]=='E'||numSystem.hex[x]=='e')
        {
            numbers=14;
        }
        else if(numSystem.hex[x]=='F'||numSystem.hex[x]=='f')
        {
            numbers=15;
        }
        else
        {
            numbers=numSystem.hex[x]-48;
        }

        decimal=decimal+numbers*pow(16,powered);
        powered++;
    }

    x=0,length=0;
    while(decimal!=0)
    {
        remainder[x]=decimal%8;
        decimal=decimal/8;
        x++;
        length++;
    }
    printf("\n\n\t\t\tEquivalent Octal Number:--> ");
    for(x=length-1;x>=0;x--)
    {
        printf("%d",remainder[x]);
    }

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("hexToOct.csv", "w");
    fprintf(file, "HEXADECIMAL,OCTAL\n"); // Write the header
    fprintf(file, "%s,%d\n", numSystem.hex, remainder[x]); // Write the data
    fclose(file);
}

void print_octal_menu()
{
    system("cls");
    printf("\033[0;31m");//text color
    printf("\n\n\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|           OCTAL CONVERSION MENU               |\n");
    printf("\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|\t    [1] OCTAL TO BINARY                 |\n");
    printf("\t\t\t|\t    [2] OCTAL TO DECIMAL                |\n");
    printf("\t\t\t|\t    [3] OCTAL TO HEXADECIMAL            |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t+_______________________________________________+\n\n\n");
}

void oct_choices(int convert)
{
    print_octal_menu();
        printf("\t\t\tEnter your choice to convert:--> ");
        scanf("%d", &convert);
        if(convert == 1)
        {
            calculate_oct_to_bi();
        }
        else if(convert == 2)
        {
            calculate_oct_to_dec();
        }
        else if(convert == 3)
        {
            calculate_oct_to_hex();
        }
        else
        {
            printf("\t\t\tEnter a valid choice");
        }
}
void calculate_oct_to_bi()
{
    numSystem.octal = 0;
    numSystem.binary = 0;
    int remainder[50],length=0,x=0,numbers,answers;

    system("cls");
    printf("========================= OCTAL TO BINARY CONVERSION =========================\n\n");
    printf("\t\t\tEnter an octal number:--> ");
    scanf("%d", &numSystem.octal);

    int temp = numSystem.octal;
    while( numSystem.octal!=0)
    {
        answers= numSystem.octal % 10;
        numSystem.binary = numSystem.binary + answers * pow(8,x);
        x++;
         numSystem.octal =  numSystem.octal/10;
    }

    x=0;
    do
    {
        remainder[x]=numSystem.binary%2;
        numSystem.binary=numSystem.binary/2;
        x++;
        length++;
    }
    while(numSystem.binary!=0);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("octToBin.csv", "w");
    fprintf(file, "OCTAL,BINARY\n"); // Write the header
    fprintf(file, "%d,", temp); // Write the data

    printf("\n\n\t\t\tEquivalent Binary Number:--> ");
    for(x=length-1;x>=0;x--)
    {
        printf("%d",remainder[x]);
        fprintf(file, "%d", remainder[x]);
    }

    fclose(file);
}

void calculate_oct_to_dec()
{
    numSystem.decimal = 0;
    numSystem.octal = 0;
    int base = 1;

    system("cls");
    printf("========================= OCTAL TO DECIMAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter an octal number: ");
    scanf("%d", &numSystem.octal);

    int temp = numSystem.octal;
    while (numSystem.octal > 0) {
        int lastDigit = numSystem.octal % 10;
        numSystem.decimal += lastDigit * base;
        base *= 8;
        numSystem.octal /= 10;
    }

    printf("\n\n\t\t\tEquivalent Decimal Number:--> %d", numSystem.decimal);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("octToDec.csv", "w");
    fprintf(file, "OCTAL,DECIMAL\n"); // Write the header
    fprintf(file, "%d,%d\n", temp, numSystem.decimal); // Write the data
    fclose(file);
}

void calculate_oct_to_hex()
{
    numSystem.octal = 0;
    numSystem.hexadecimal = 0;
    int remainder[50], length = 0, x = 0, numbers, answers = 0;

    system("cls");
    printf("========================= OCTAL TO HEXADECIMAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter an octal number: ");
    scanf("%d", &numSystem.octal);

    long originalOctal = numSystem.octal; // Save the original octal number

    while (numSystem.octal != 0) {
        answers = numSystem.octal % 10;
        numSystem.hexadecimal = numSystem.hexadecimal + answers * pow(8, x);
        x++;
        numSystem.octal = numSystem.octal / 10;
    }
    x = 0;
    while (numSystem.hexadecimal != 0) {
        remainder[x] = numSystem.hexadecimal % 16;
        numSystem.hexadecimal = numSystem.hexadecimal / 16;
        x++;
        length++;
    }

    printf("\n\n\t\t\tEquivalent Hexadecimal Number:--> ");
    FILE* file;
    file = fopen("octToHex.csv", "w");

    fprintf(file, "Octal,Hexadecimal\n"); // Write the header
    fprintf(file, "%d,", originalOctal); // Write the octal number

    for (x = length - 1; x >= 0; x--) {
        switch (remainder[x]) {
        case 10:
            fprintf(file, "A");
            printf("A");
            break;
        case 11:
            fprintf(file, "B");
            printf("B");
            break;
        case 12:
            fprintf(file, "C");
            printf("C");
            break;
        case 13:
            fprintf(file, "D");
            printf("D");
            break;
        case 14:
            fprintf(file, "E");
            printf("E");
            break;
        case 15:
            fprintf(file, "F");
            printf("F");
            break;
        default:
            fprintf(file, "%d", remainder[x]);
            printf("%d", remainder[x]);
        }
    }

    fprintf(file, "\n");
    fclose(file);
}

void print_decimal_menu()
{
    system("cls");
    printf("\033[0;36m");//text color
    printf("\n\n\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|           DECIMAL CONVERSION MENU             |\n");
    printf("\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|\t    [1] DECIMAL TO BINARY               |\n");
    printf("\t\t\t|\t    [2] DECIMAL TO OCTAL                |\n");
    printf("\t\t\t|\t    [3] DECIMAL TO HEXADECIMAL          |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t+_______________________________________________+\n\n\n");
}

void dec_choices(int convert)
{
    print_decimal_menu();
        printf("\t\t\tEnter choice to convert:--> ");
        scanf("%d", &convert);

        if(convert == 1)
        {
            calculate_dec_to_bi();
        }
        else if(convert == 2)
        {
            calculate_dec_to_oct();
        }
        else if(convert == 3)
        {
            calculate_dec_to_hex();
        }
        else
        {
            printf("\t\t\tEnter a valid choice");
        }
}

void calculate_dec_to_bi()
{
    numSystem.decimal = 0;
    int remainder[50], x = 0, length=0;

    system("cls");
    printf("========================= DECIMAL TO BINARY CONVERSION =========================\n\n");
    printf("\t\t\tEnter a decimal number: ");
    scanf("%d", &numSystem.decimal);

    int dec = numSystem.decimal;

    do
    {
        remainder[x] = numSystem.decimal%2;
        numSystem.decimal = numSystem.decimal/2;
        x++;
        length++;
    }
    while(numSystem.decimal!=0);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("decToBin.csv", "w");
    fprintf(file, "DECIMAL,BINARY\n"); // Write the header
    fprintf(file, "%d,", dec); // Write the data

    printf("\n\n\t\t\tEquivalent Binary Number:--> ");
    for(x=length-1;x>=0;x--)
    {
        printf("%d",remainder[x]);
        fprintf(file,"%d",remainder[x]);
    }


    fclose(file);
}

void calculate_dec_to_oct()
{
    numSystem.decimal = 0;
    int remainder[50], x = 0, length=0;

    system("cls");
    printf("========================= DECIMAL TO OCTAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter a decimal number: ");
    scanf("%d", &numSystem.decimal);

    int temp = numSystem.decimal;

    do
    {
        remainder[x] = numSystem.decimal%8;
        numSystem.decimal = numSystem.decimal/8;
        x++;
        length++;
    }
    while(numSystem.decimal!=0);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("decToOct.csv", "w");
    fprintf(file, "DECIMAL,OCTAL\n"); // Write the header
    fprintf(file, "%d,", temp); // Write the data

    printf("\n\n\t\t\tEquivalent Octal Number:--> ");
    for(x=length-1;x>=0;x--)
    {
        printf("%d",remainder[x]);
        fprintf(file,"%d",remainder[x]);
    }

    fclose(file);
}

void calculate_dec_to_hex()
{
    numSystem.decimal = 0;
    int cnt, i;

    system("cls");
    printf("========================= DECIMAL TO HEXADECIMAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter decimal number: ");
    scanf("%d", &numSystem.decimal);

    int dec = numSystem.decimal;
    cnt = 0; /*initialize index to zero*/
    while (numSystem.decimal > 0) {
        switch (numSystem.decimal % 16) {
        case 10:
            numSystem.hex[cnt] = 'A';
            break;
        case 11:
            numSystem.hex[cnt] = 'B';
            break;
        case 12:
            numSystem.hex[cnt] = 'C';
            break;
        case 13:
            numSystem.hex[cnt] = 'D';
            break;
        case 14:
            numSystem.hex[cnt] = 'E';
            break;
        case 15:
            numSystem.hex[cnt] = 'F';
            break;
        default:
            numSystem.hex[cnt] = (numSystem.decimal % 16) + 0x30; /*converted into char value*/
        }
        numSystem.decimal = numSystem.decimal / 16;
        cnt++;
    }

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("decToHex.csv", "w");
    fprintf(file, "DECIMAL,HEXDECIMAL\n"); // Write the header
    fprintf(file, "%d,", dec); // Write the data

    /*print value in reverse order*/
    printf("\n\n\t\t\tEquivalent Hexadecimal Number:--> ");
    for (i = (cnt - 1); i >= 0; i--)
    {
        printf("%c", numSystem.hex[i]);
        fprintf(file, "%c", numSystem.hex[i]);
    }

    fclose(file);
}

void print_binary_menu()
{
    system("cls");
    printf("\033[0;37m"); //text color
    printf("\n\n\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|           BINARY CONVERSION MENU              |\n");
    printf("\t\t\t+_______________________________________________+\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|\t    [1] BINARY TO DECIMAL               |\n");
    printf("\t\t\t|\t    [2] BINARY TO OCTAL                 |\n");
    printf("\t\t\t|\t    [3] BINARY TO HEXADECIMAL           |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t+_______________________________________________+\n\n\n");
}

void bi_choices(int convert)
{
        print_binary_menu();
        printf("\t\t\tEnter a choice to convert:--> ");
        scanf("%d", &convert);
        if(convert == 1)
        {
            print_bi_to_dec();
        }
        else if(convert == 2)
        {
            calculate_bi_to_oct();
        }
        else if(convert == 3)
        {
            calculate_bi_to_hex();
        }
        else
        {
            printf("\t\t\tEnter a valid choice");
        }
}

int bi_to_dec(int binaryNum)
{
    int decimalNum = 0;
    int base = 1;

    while (binaryNum > 0) {
        int lastDigit = binaryNum % 10;
        decimalNum += lastDigit * base;
        base *= 2;
        binaryNum /= 10;
    }

    return decimalNum;
}

void print_bi_to_dec()
{
    long int bi;

    system("cls");
    printf("========================= BINARY TO DECIMAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter Binary Number:--> ");
    scanf("%ld", &bi);

    numSystem.binary = bi_to_dec(bi);

    printf("\n\n\t\t\tEquivalent Decimal Number:--> %d", numSystem.binary);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("binToDec.csv", "w");
    fprintf(file, "BINARY,DECIMAL\n"); // Write the header
    fprintf(file, "%ld,%ld\n", bi, numSystem.binary); // Write the data
    fclose(file);
}

void calculate_bi_to_oct()
{
    numSystem.binary = 0;
    numSystem.octal = 0;
    int i = 1;
    int rem = 0;

    system("cls");
    printf("========================= BINARY TO OCTAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter binary number: ");
    scanf("%ld", &numSystem.binary);

    long int temp = numSystem.binary;

    while (numSystem.binary != 0) {
        rem = numSystem.binary % 10;
         numSystem.octal =  numSystem.octal + rem * i;

        i = i * 2;
        numSystem.binary = numSystem.binary / 10;
    }

    printf("\n\n\t\t\tEquivalent Octal Number:--> %o", numSystem.octal);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("binToOct.csv", "w");
    fprintf(file, "BINARY,OCTAL\n"); // Write the header
    fprintf(file, "%ld,%o\n", temp, numSystem.octal); // Write the data
    fclose(file);
}

void calculate_bi_to_hex()
{
    numSystem.binary = 0;
    numSystem.hexadecimal = 0;
    int i = 1;
    int rem = 0;

    system("cls");
    printf("========================= BINARY TO HEXADECIMAL CONVERSION =========================\n\n");
    printf("\t\t\tEnter binary number: ");
    scanf("%ld", &numSystem.binary);

    long int temp = numSystem.binary;
    while (numSystem.binary != 0) {
        rem = numSystem.binary % 10;
        numSystem.hexadecimal = numSystem.hexadecimal + rem * i;

        i = i * 2;
        numSystem.binary = numSystem.binary / 10;
    }

    printf("\n\n\t\t\tEquivalent Hexadecimal Number:--> %x", numSystem.hexadecimal);

    // Writing the result to a CSV file
    FILE *file;
    file = fopen("binToHex.csv", "w");
    fprintf(file, "BINARY,HEXDECIMAL\n"); // Write the header
    fprintf(file, "%ld,%x\n", temp, numSystem.hexadecimal); // Write the data
    fclose(file);
}
