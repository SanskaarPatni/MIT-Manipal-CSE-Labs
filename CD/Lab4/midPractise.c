#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row = 1, column = 1;
int symbolTableIndex = -1;
int lexemeIndex = 0;
char buff[80];
char dbuf[80] = "none";
struct Token
{
    char *token_name;
    int row, col; //Line numbers.
};
//Node is a 2d array of structure
struct Node
{
    char lexeme[20];
    int size;
    char type[50];
} symboltable[10][100];

char symboltablename[10][100];
int symboltablesize[10];

//keywords
//obv because array of string duh
//const char * keyword[]={"",""}
//datatypes
//special Characters
//for this only char specialSymbol[]
const char *keywords[] = {
    "auto",
    "break",
    "case",
    "char",
    "continue",
    "do",
    "default",
    "const",
    "double",
    "else",
    "enum",
    "extern",
    "for",
    "if",
    "include",
    "goto",
    "float",
    "int",
    "long",
    "register",
    "return",
    "signed",
    "static",
    "sizeof",
    "short",
    "struct",
    "switch",
    "typedef",
    "union",
    "void",
    "while",
    "volatile",
    "unsigned",
    "printf",
    "scanf",
    "bool"};
const char *dataTypes[] = {
    "int", "void", "char", "float", "bool"};

const char specialsymbols[] = {'?', ';', ':', ',', '(', ')', '[', ']', '{', '}'};

int isKeyword(char *id)
{
    for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++)
    {
        if (strcmp(id, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int isDataType(char *id)
{
    for (int i = 0; i < sizeof(dataTypes) / sizeof(char *); i++)
    {
        if (strcmp(id, dataTypes[i]) == 0)
            return 1;
    }
    return 0;
}
int isspecialSymbol(char id)
{
    for (int i = 0; i < sizeof(specialsymbols) / sizeof(char); i++)
    {
        if (id == specialsymbols[i])
            return 1;
    }
    return 0;
}
int isAlpha(char in)
{
    if ((in >= (int)('A') && in <= (int)('Z')) || (in >= (int)('a') && in <= (int)('z')))
        return 1;
    return 0;
}

int isDigit(char in)
{
    if ((in >= (int)('0') && in <= (int)('9')))
        return 1;
    return 0;
}

/*Functions for Token*/
//passing a structure
void printToken(struct Token tk)
{
    printf("< %s , %d , %d >\n", tk.token_name, tk.row, tk.col);
}

//passing a pointer to a structure
void fillToken(struct Token *tok, char *token_name, int row, int col)
{
    tok->token_name = token_name;
    tok->row = row;
    tok->col = col;
}

/*Functions for Symbol Table*/
void printLexeme(int i, int j)
{
    printf(" %d \t", j + 1);
    printf(" %s \t\t", symboltable[i][j].lexeme);
    printf(" %s \t", symboltable[i][j].type);
    printf(" %d \n", symboltable[i][j].size);
}
void printSymbolTable()
{
    int i, j;
    for (i = 0; i <= symbolTableIndex; i++)
    {
        printf("------------------------------------------------------------\n");
        printf("Symbol Table for %s:\n", symboltablename[i]);
        printf("   \t Lexeme_name \t Type \t Size \n");
        for (j = 0; j < symboltablesize[i]; j++)
        {
            printLexeme(i, j);
        }
    }
}
void createSymbolTable(char *buf)
{
    symbolTableIndex++;
    lexemeIndex = 0;
    strcpy(symboltablename[symbolTableIndex], buf);
    // printf("Symbol table index%d\n",symboltableindex);
    // printf("Lexeme index%d\n",lexemeindex);
}