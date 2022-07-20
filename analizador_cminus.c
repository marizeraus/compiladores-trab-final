#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM_TOKENS 50

typedef struct
{
	char valor[50];
	char tipo[50];
} Token;

Token lista_token[MAX_NUM_TOKENS];

int i = 0;

int main(int argc, char *argv[])
{

	FILE *arq;
	char linha[200];
	char *result;
	int estado = 0;

	if (argc == 1)
	{
		printf("Nenhum arquivo selecionado.\n");
		return;
	}

	arq = fopen(argv[1], "rt");

	if (arq == NULL)
	{
		printf("Problemas na abertura do arquivo.\n");
		return;
	}

	Token tokens[MAX_NUM_TOKENS];
	Token analisaToken;

	strcpy(analisaToken.valor, "");
	strcpy(analisaToken.tipo, "");

	while (!feof(arq))
	{
		result = fgetc(arq);

		if (result)
		{
			// printf("%c\n",result);
			analisador(result, &analisaToken, &estado);
			// tokens[i] = analisaToken;
		}
		if (estado == 0)
		{
			analisaToken.valor[50] = "";
			analisaToken.tipo[50] = "";
		}
	}
	strcpy(lista_token[i].tipo, "EMPTY");
	strcpy(lista_token[i].valor, "end");
	imprimeTokens();
	fclose(arq);

	FILE *f = fopen("temp1.txt", "w");
	for (int j = 0; j < i + 1; j++)
	{
		fprintf(f, "%s %s\n", lista_token[j].tipo, lista_token[j].valor);
	}
	fclose(f);

	// int n = sizeof(tokens) / sizeof(tokens[0]);

	// imprimeTokens(&tokens, n);

	return 0;
}

void imprimeTokens()
{
	printf("========================================= IMPRIME TOKENS =======================================================\n");

	for (int it = 0; it <= MAX_NUM_TOKENS; it++)
	{
		// printf("%s: %s\n", tokens[i]->tipo, tokens[i]->valor);
		printf("====== TOKEN %d =========", it);
		printf("%s\n", lista_token[it].tipo);
		printf("%s\n\n", lista_token[it].valor);
	}

	printf("================================================================================================================\n");
}

bool is_digit(char c)
{
	return c >= '0' && c <= '9';
}

bool is_letter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_simbol(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == ',' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == ';';
}

bool is_simbol_comparative(char c)
{
	return c == '<' || c == '=' || c == '!' || c == '>';
}

bool is_delimiter(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\0';
}

Token inicializaToken()
{
	Token t;
	strcpy(t.valor, "");
	strcpy(t.tipo, "");

	return t;
}

void analisador(char c, Token *token, int *estado)
{

	// printf("Entra função linha\n\n");
	switch (*estado)
	{
	case 0:
		if (c == 'e')
		{
			*estado = 1;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (c == 'i')
		{
			*estado = 5;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (c == 'r')
		{
			*estado = 9;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (c == 'v')
		{
			*estado = 15;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (c == 'w')
		{
			*estado = 19;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (c == '/')
		{
			*estado = 24;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if ((is_letter(c) && c != 'e' && c != 'r' && c != 'v' && c != 'w' && c != '/'))
		{
			*estado = 29;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (is_digit(c))
		{
			*estado = 30;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			// return c == '+' || c == '-' || c == '*' || c == '/' || c == ',' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_delimiter(c))
		{
			*estado = 0;
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (c == -1)
		{
			printf("FIM DE ARQUIVO");
		}
		else
		{
			printf("ERRO LÉXICO 0 - %i \n", c);
		}
		break;
	case 1:
		if (c == 'l')
		{
			printf("%c", c);
			*estado = 2;
			strncat(token->valor, &c, 1);
		}
		else if (is_digit(c) || is_delimiter(c))
		{
			printf("%c", c);
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 1\n");
		}
		break;
	case 2:
		if (c == 's')
		{
			*estado = 3;
			strncat(token->valor, &c, 1);
		}
		else if (is_digit(c) || is_delimiter(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 2\n");
		}
		break;
	case 3:
		if (c == 'e')
		{
			*estado = 4;
			strncat(token->valor, &c, 1);
		}
		else if (is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 31;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 3\n");
		}
		break;
	case 4:
		if (is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "ELSE");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 4\n");
		}
		break;
	case 5:
		if (c == 'f')
		{
			*estado = 6;
			strncat(token->valor, &c, 1);
		}
		else if (c == 'n')
		{
			*estado = 7;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 5\n");
		}
		break;
	case 6:
		if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "IF");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			strcpy(token->tipo, "IF");
			printf("%s: %s\n", token->tipo, token->valor);
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 6\n");
		}
		break;
	case 7:
		if (c = 't')
		{
			*estado = 8;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 7\n");
		}
		break;
	case 8:
		if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "INT");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 8\n");
		}
		break;
	case 9:
		if (c = 'e')
		{
			*estado = 10;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 9\n");
		}
		break;
	case 10:
		if (c = 't')
		{
			*estado = 11;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 10\n");
		}
		break;
	case 11:
		if (c = 'u')
		{
			*estado = 12;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 11\n");
		}
		break;
	case 12:
		if (c = 'r')
		{
			*estado = 13;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 12\n");
		}
		break;
	case 13:
		if (c = 'n')
		{
			*estado = 14;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 13\n");
		}
		break;
	case 14:
		if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "RETURN");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 14\n");
		}
		break;
	case 15:
		if (c = 'o')
		{
			*estado = 16;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 15\n");
		}
		break;
	case 16:
		if (c = 't')
		{
			*estado = 17;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 16\n");
		}
		break;
	case 17:
		if (c = 'd')
		{
			*estado = 18;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 17\n");
		}
		break;
	case 18:
		if (is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "VOID");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 18\n");
		}
		break;
	case 19:
		if (c = 'h')
		{
			*estado = 20;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 19\n");
		}
		break;
	case 20:
		if (c = 'i')
		{
			*estado = 21;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 20\n");
		}
		break;
	case 21:
		if (c = 'l')
		{
			*estado = 22;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 21\n");
		}
		break;
	case 22:
		if (c = 'e')
		{
			*estado = 23;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c) || is_digit(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 22\n");
		}
		break;
	case 23:
		if (is_letter(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 0;

			strcpy(token->tipo, "WHILE");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_simbol(c))
		{
			*estado = 0;

			strcpy(token->tipo, "WHILE");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;

			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 0;

			strcpy(token->tipo, "WHILE");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;

			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 23\n");
		}
		break;
	case 24:
		if (c = '*')
		{
			*estado = 25;
			strncat(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 24\n");
		}
		break;
	case 25:
		if (is_delimiter(c) || is_digit(c) || is_letter(c) || is_simbol(c))
		{
			*estado = 26;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 25\n");
		}
		break;
	case 26:
		if ((is_delimiter(c) || is_digit(c) || is_letter(c) || is_simbol(c)) && c != '*')
		{
			*estado = 26;
			strncat(token->valor, &c, 1);
		}
		else if (c == '*')
		{
			*estado = 27;
			strncat(token->valor, &c, 1);
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 26\n");
		}
		break;
	case 27:
		if (c == '/')
		{
			*estado = 28;
			strncat(token->valor, &c, 1);
			memset(token->tipo, 0, 50);
		}
		else
		{
			printf("ERRO LÉXICO 27\n");
		}
		break;
	case 28:
		if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_simbol(c))
		{
			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 28\n");
		}
		break;
	case 29:
		if (is_letter(c))
		{
			*estado = 29;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "IDENTIFICADOR");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_simbol(c))
		{
			*estado = 0;
			strcpy(token->tipo, "IDENTIFICADOR");
			strncat(token->valor, &c, 1);
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;

			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			*estado = 40;
			strcpy(token->tipo, "IDENTIFICADOR");
			printf("%s: %s\n", token->tipo, token->valor);
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 29\n");
		}
		break;
	case 30:
		if (is_digit(c))
		{
			*estado = 30;
			strncat(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "CONSTANTE");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_simbol(c))
		{
			strcpy(token->tipo, "CONSTANTE");
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			printf("%s: %s\n", token->tipo, token->valor);
			*estado = 0;
			i++;

			if (c == '+')
			{
				*estado = 0;
				strcpy(token->tipo, "MAIS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '-')
			{
				*estado = 0;
				strcpy(token->tipo, "MENOS");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '*')
			{
				*estado = 0;
				strcpy(token->tipo, "MULT");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '/')
			{
				*estado = 0;
				strcpy(token->tipo, "DIV");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ',')
			{
				*estado = 0;
				strcpy(token->tipo, "VIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '(')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ')')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSEPAREN");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '[')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ']')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECHAVES");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '{')
			{
				*estado = 0;
				strcpy(token->tipo, "OPENCOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == '}')
			{
				*estado = 0;
				strcpy(token->tipo, "CLOSECOLCHETE");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
			else if (c == ';')
			{
				*estado = 0;
				strcpy(token->tipo, "PONTOVIRGULA");
				memset(token->valor, 0, 50);
				strncpy(token->valor, &c, 1);
				printf("%s: %s\n", token->tipo, token->valor);
				strcpy(lista_token[i].tipo, token->tipo);
				strcpy(lista_token[i].valor, token->valor);
				i++;
			}
		}
		else if (is_simbol_comparative(c))
		{
			strcpy(token->tipo, "CONSTANTE");
			printf("%s: %s\n", token->tipo, token->valor);
			*estado = 40;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else
		{
			printf("ERRO LÉXICO 30\n");
		}
		break;

	case 40:
		if (c == '=')
		{
			*estado = 0;
			strcpy(token->tipo, "OPERADOR");
			strncat(token->valor, &c, 1);
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else if (is_digit(c))
		{
			*estado = 30;
			strcpy(token->tipo, "OPERADOR");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (is_letter(c))
		{
			*estado = 29;
			strcpy(token->tipo, "OPERADOR");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
			memset(token->valor, 0, 50);
			strncpy(token->valor, &c, 1);
		}
		else if (is_delimiter(c))
		{
			*estado = 0;
			strcpy(token->tipo, "OPERADOR");
			printf("%s: %s\n", token->tipo, token->valor);
			strcpy(lista_token[i].tipo, token->tipo);
			strcpy(lista_token[i].valor, token->valor);
			i++;
		}
		else
		{
			printf("ERRO LÉXICO 40\n");
		}

	default:
		// printf("ERRO character: %c   ", c);
		break;
	}
}