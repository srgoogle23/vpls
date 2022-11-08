#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// create an array of 1000 cards
#define BUFSZ 4096
#define MAX_CARDS 1000
int idCard[MAX_CARDS];
char colunaCard[MAX_CARDS][BUFSZ];
char dataCard[MAX_CARDS][BUFSZ];
char nomeCard[MAX_CARDS][BUFSZ];
int finalCard;

void preencheVazio();
void saveData(int idCartao, char *coluna, char *dataCartao, char *nomeCartao, int tipo);

void preencheVazio()
{
	for (int i = 0; i < MAX_CARDS; i++)
	{
		idCard[i] = -1;
		strcpy(colunaCard[i], "");
		strcpy(dataCard[i], "");
		strcpy(nomeCard[i], "");
	}
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void exibeCartoesPorPessoa(char *nomeCartao)
{
	// verficar se a coluna existe
	int existe = 0, idExistente = -1;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if(idCard[i] == -1)
		{
			break;
		}
		else if (strcmp(nomeCard[i], nomeCartao) == 0)
		{
			idExistente = i;
			existe = 1;
			break;
		}
	}

	if (existe == 0)
	{
		return;
	}

	int *array = (int *)malloc(sizeof(int));
	int j = 0;
	for(int i = idExistente; i < MAX_CARDS; i++)
	{
		if (strcmp(nomeCard[i], nomeCartao) == 0)
		{
			array[j] = idCard[i];
			j++;
		}
		else if(idCard[i] == -1)
		{
			break;
		}
	}

	selectionSort(array, j);
	for(int i = 0; i < j; i++)
	{
		for (int k = 0; k < MAX_CARDS; k++)
		{
			if (idCard[k] == array[i])
			{
				printf("%d %s %s %s\n", idCard[k], colunaCard[k], dataCard[k], nomeCard[k]);
				break;
			}
		}
	}
	
}

void exibeCartoesPorColuna(char *colunaCartao)
{
	// verficar se a coluna existe
	int existe = 0, idExistente = -1;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if(idCard[i] == -1)
		{
			break;
		}
		else if (strcmp(colunaCard[i], colunaCartao) == 0)
		{
			idExistente = i;
			existe = 1;
			break;
		}
	}

	if (existe == 0)
	{
		return;
	}

	int *array = (int *)malloc(sizeof(int));
	int j = 0;
	for(int i = idExistente; i < MAX_CARDS; i++)
	{
		if (strcmp(colunaCard[i], colunaCartao) == 0)
		{
			array[j] = idCard[i];
			j++;
		}
		else if(idCard[i] == -1)
		{
			break;
		}
	}

	selectionSort(array, j);
	for(int i = 0; i < j; i++)
	{
		for (int k = 0; k < MAX_CARDS; k++)
		{
			if (idCard[k] == array[i])
			{
				printf("%d %s %s %s\n", idCard[k], colunaCard[k], dataCard[k], nomeCard[k]);
				break;
			}
		}
	}
	
}

void exibeCartoesAtrasados(char *dataCartao)
{
	int dia1, mes1, ano1;
	char *token = strtok(dataCartao, "-");
	dia1 = atoi(token);
	token = strtok(NULL, "-");
	mes1 = atoi(token);
	token = strtok(NULL, "-");
	ano1 = atoi(token); 
	
	int *array = (int *)malloc(sizeof(int));
	int j = 0;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if(idCard[i] == -1)
			break;

		// somente se a colunaCard == Fazendo ou Pendente
		if (strcmp(colunaCard[i], "Fazendo") != 0 && strcmp(colunaCard[i], "Pendente") != 0)
			continue;

		char *clone;
		clone = strdup(dataCard[i]);
		int dia2, mes2, ano2;
		char *token2 = strtok(clone, "-");
		dia2 = atoi(token2);
		token2 = strtok(NULL, "-");
		mes2 = atoi(token2);
		token2 = strtok(NULL, "-");
		ano2 = atoi(token2); 

		// compara as datas
		if (ano1 > ano2)
		{
			array[j] = idCard[i];
			j++;
		}
		else if (ano1 == ano2)
		{
			if (mes1 > mes2)
			{
				array[j] = idCard[i];
				j++;
			}
			else if (mes1 == mes2)
			{
				if (dia1 > dia2)
				{
					array[j] = idCard[i];
					j++;
				}
			}
		}
	}

	selectionSort(array, j);
	for(int i = 0; i < j; i++)
	{
		for (int k = 0; k < MAX_CARDS; k++)
		{
			if (idCard[k] == array[i])
			{
				printf("%d %s %s %s\n", idCard[k], colunaCard[k], dataCard[k], nomeCard[k]);
				break;
			}
		}
	}
}

void verificaNomeVazio()
{
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (strcmp(nomeCard[i], "") == 0)
		{
			strcpy(nomeCard[i], "");
		}
	}
}

void salvarArquivo(char *nomeArquivo2)
{
	FILE *arquivo2;
	arquivo2 = fopen(nomeArquivo2, "w+");
	if (arquivo2 == NULL)
	{
		printf("Erro ao abrir o arquivo %s teste", nomeArquivo2);
		exit(1);
	}
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if(idCard[i] != -1)
		{			
			fprintf(arquivo2, "%d %s %s %s\n", idCard[i], colunaCard[i], dataCard[i], nomeCard[i]);
		}
	}
	fclose(arquivo2);
}

int main(int argc, char *argv[])
{
	preencheVazio();
	if(0 == 0)
	{
		char *nomeArquivo = argv[1];
		// abre o arquivo de entrada
		FILE *arquivo = fopen(nomeArquivo, "r");
		// verifica se o arquivo foi aberto
		if (arquivo == NULL)
		{
			printf("Erro ao abrir o arquivo de entrada!");
			return 1;
		}

		// preenche o array usando saveData
		int id;
		char *coluna = malloc(10 * sizeof(char));
		char *data = malloc(10 * sizeof(char));
		char *nome = malloc(100 * sizeof(char));
		
		// le toda a linha usando buffer
		char *buffer = malloc(BUFSZ * sizeof(char));
		while (fgets(buffer, BUFSZ, arquivo) != NULL)
		{
			// identifica uma linha vazia
			if (strcmp(buffer, "") == 0)
			{
				continue;
			}
			// conta quantos espaços existem na linha
			int espacos = 0;
			for (int i = 0; i < strlen(buffer); i++)
			{
				if (buffer[i] == ' ')
				{
					espacos++;
				}
			}

			if(espacos != 3)
			{
				// se nao tiver 3 espaços, nao possui nome
				sscanf(buffer, "%d %s %s", &id, coluna, data);
				strcpy(nome, "");
			}
			else
			{
				// separa os dados da linha
				char *token = strtok(buffer, " ");
				id = atoi(token);
				token = strtok(NULL, " ");
				strcpy(coluna, token);
				token = strtok(NULL, " ");
				strcpy(data, token);
				token = strtok(NULL, " ");

				if (token[strlen(token) - 1] == '\n')
				{
					token[strlen(token) - 1] = '\0';
				}
				strcpy(nome, token);
			}

			// salva os dados no array
			saveData(id, coluna, data, nome, 0);
		}
		verificaNomeVazio();
	}

	int comando;
	scanf("%d", &comando);
	while (comando > 0 && comando <= 7)
	{
		if (comando == 1)
		{
			// le o nome do arquivo
			char *nomeArquivo2 = malloc(100 * sizeof(char));
			scanf("%s", nomeArquivo2);
			salvarArquivo(nomeArquivo2);
			return 0;
		}

		if(comando == 2)
		{
			int id;
			char *coluna = malloc(10 * sizeof(char));
			char *data = malloc(10 * sizeof(char));
			char *nome = malloc(100 * sizeof(char));
			nome = "";
			coluna = "Pendente";
			scanf("%d %s", &id, data);
			saveData(id, coluna, data, nome, 0);
		}

		if(comando == 3)
		{
			int id;
			char *coluna = malloc(10 * sizeof(char));
			char *data = malloc(10 * sizeof(char));
			char *nome = malloc(100 * sizeof(char));
			scanf("%d %s", &id, nome);
			coluna = "Fazendo";
			data = "";
			saveData(id, coluna, data, nome, 1);
		}

		if(comando == 4)
		{
			int id;
			char *coluna = malloc(10 * sizeof(char));
			char *data = malloc(10 * sizeof(char));
			char *nome = malloc(100 * sizeof(char));
			scanf("%d", &id);
			coluna = "Finalizado";
			data = "";
			nome = "";
			saveData(id, coluna, data, nome, 2);
		}

		if(comando == 6)
		{
			char *nome = malloc(100 * sizeof(char));
			scanf("%s", nome);
			if (strcmp(nome, "") == 0)
			{
				return 0;
			}
			exibeCartoesPorPessoa(nome);
		}

		if(comando == 5)
		{
			char *coluna = malloc(100 * sizeof(char));
			scanf("%s", coluna);

			// se a coluna for vazia, sai do programa
			if (strcmp(coluna, "") == 0)
			{
				return 0;
			}
			exibeCartoesPorColuna(coluna);
		}

		if(comando == 7)
		{
			char *data = malloc(100 * sizeof(char));
			scanf("%s", data);

			if (strcmp(data, "") == 0)
			{
				return 0;
			}

			exibeCartoesAtrasados(data);

		}

		scanf("%d", &comando);
	}
	return 0;
}

int verificaCondicao(int idCartao)
{
	int existe = 0;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (idCard[i] == idCartao)
		{
			existe = 1;
		}
	}

	if(existe == 0)
		return 0;

	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (idCard[i] == idCartao)
		{
			if (strcmp(colunaCard[i], "Finalizado") == 0)
			{
				return 0;
			}

			if (strcmp(colunaCard[i], "Pendente") == 0)
			{
				return 1;
			}

			if (strcmp(colunaCard[i], "Fazendo") == 0)
			{
				return 0;
			}
		}
	}

}

int verificaCondicao2(int idCartao)
{
	int existe = 0, fazendo = 0;
	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (idCard[i] == idCartao)
		{
			existe = 1;
			// verifica se o cartao ja esta em "Fazendo"
			if (strcmp(colunaCard[i], "Fazendo") == 0)
			{
				fazendo = 1;
			}
			break;
		}
	}
	if(existe == 1 && fazendo == 1)
		return 1;
	else
		return 0;
}

// create a function to save the data in the file "123 Fazendo 20-11-22 Jorge"
void saveData(int idCartao, char *coluna, char *dataCartao, char *nomeCartao, int tipo)
{
	if(tipo == 2)
	{
		if(verificaCondicao2(idCartao) == 0)
		{
			printf("Operacao Invalida\n");
			return;
		}

		for (int i = 0; i < MAX_CARDS; i++)
		{
			if (idCard[i] == idCartao)
			{
				strcpy(colunaCard[i], coluna);
				return;
			}
		}

	}
	else if(tipo == 1)
	{
		if(verificaCondicao(idCartao) == 0)
		{
			printf("Operacao Invalida\n");
			return;
		}

		for (int i = 0; i < MAX_CARDS; i++)
		{
			if (idCard[i] == idCartao)
			{
				strcpy(colunaCard[i], coluna);
				strcpy(nomeCard[i], nomeCartao);
			
				return;
			}
		}

	}
	else if(tipo == 0)
	{
		for (int i = 0; i < MAX_CARDS; i++)
		{
			if (idCard[i] == -1)
			{
				idCard[i] = idCartao;
				strcpy(colunaCard[i], coluna);
				strcpy(dataCard[i], dataCartao);
				strcpy(nomeCard[i], nomeCartao);
				return;
			}
		}
	}
}