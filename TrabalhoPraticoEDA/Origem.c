#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "Header.h"


Operation* readJobs(Operation* jobs)
{
	setlocale(LC_ALL, "English");
	FILE* fp;
	int name, num, time;
	Operation* readjob;
	readjob = jobs;
	fp = fopen("Operation.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d%*c%d%*c%d", &name, &num, &time);
			printf("");
			readjob = insertJobs(readjob, name, num, time);
		}
		return(readjob);
	}
	else
		return(jobs);
}


Operation* insertJobs(Operation* jobs, int name, int num, int tempo)
{
	Operation* newoperation = (Operation*)malloc(sizeof(struct OperationRegistration));
	newoperation->name = name;
	newoperation->numero = num;
	newoperation->time = tempo;
	newoperation->next = jobs;
	return(newoperation);
}


Operation* removeJobs(Operation* jobs, int number)
{
	setlocale(LC_ALL, "English");
	Operation* aux = jobs, aux2;
	while ((aux != NULL))
	{
		if (aux->numero != number)
		{

			aux = aux->next;

		}
		else if (aux->numero == number)
		{
			free(aux);

		}

	}
	if (aux == NULL)
	{
		printf("Operation to be deleted was not found.\n");
		return (jobs);
	}

	return(jobs);

}


Operation* changeData(Operation* jobs, int number)
{
	setlocale(LC_ALL, "English");
	Operation* aux = jobs;
	int op = -1, nameChange, numChange, timeChange;
	while (jobs != NULL)
	{
		if (number == jobs->name)
		{
			printf("\nName: %d", jobs->name);
			printf("\nMachine Number: %d", jobs->numero);
			printf("\nMMachine Time: %d", jobs->time);

			printf("\nEnter the new data!\n");
			printf("New Name: ");
			scanf("%d", &nameChange);
			printf("New Machine Number: ");
			scanf("%d", &numChange);
			printf("New Machine Time: ");
			scanf("%d", &timeChange);

			// Atualizar dados na struct
			jobs->name = nameChange;
			jobs->name = numChange;
			jobs->time = timeChange;
			break;
		}
	}
	return (aux);
}




void listsJobs(Operation* jobs)
{
	system("CLS");
	setlocale(LC_ALL, "English");
	if (jobs != NULL)
	{
		while (jobs != NULL)
		{
			printf("___________________________________\n");
			printf("Name: %d\n", jobs->name);
			printf("Machine Number: %d\n", jobs->numero);
			printf("Machine Time: %d\n\n\n", jobs->time);
			jobs = jobs->next;
		}
	}
	else
	{
		system("CLS");
		printf("No Jobs on List\n");


	}

}


void saveJobs(Operation* jobs)
{
	FILE* fp;
	fp = fopen("Jobs.txt", "a");
	if (fp != NULL)
	{
		while (jobs != NULL)
		{
			fprintf(fp, "%d.%d.%d\n", jobs->name, jobs->numero, jobs->time);
			jobs = jobs->next;
		}
	}
	fclose(fp);
}



void main()
{
	setlocale(LC_ALL, "English");
	int op, name, num, tempo, number;
	Operation* jobs = NULL;
	do
	{
		op = menuJobs();
		switch (op)
		{
		case 1:
			printf("Insert the Number of Job:\n");
			scanf("%d", &name);
			printf("Insert the Number Machine:\n");
			scanf("%d", &num);
			printf("Insert the Time Machine:\n");
			scanf("%d", &tempo);
			system("CLS");
			jobs = insertJobs(jobs, name, num, tempo);
			if (jobs)
			{
				printf("Inserted!\n");
			}
			else
			{
				printf("Not Inserted\n", 227);
			}
			break;
		case 2:
			listsJobs(jobs);
			break;
		case 3:
			printf("Number to remove : ");
			scanf("%d", &num);
			jobs = removeJobs(jobs, num);
			printf(" Operation successfully removed!\n", 225);
			printf("___________________________________\n");
			break;
		case 4:
			printf("Name of Job to change: ", 250);
			scanf("%d", &number);
			jobs = changeData(jobs, number);
			printf("___________________________________\n");
			break;
		case 5:
			MaximumTime(jobs);
			printf("___________________________________\n");
			break;
		case 6:
			MinimumTime(jobs);
			printf("-----------------------------------\n");
			break;
		case 7:
			AverageTime(jobs);
			printf("-----------------------------------\n");
			break;
		case 8:
			saveJobs(jobs);
			printf("-----------------------------------\n");
			break;
		case 9:
			jobs = readJobs(jobs);
			printf("-----------------------------------\n");
			break;
		case 0:
			exit(0);
			break;
		default:
			system("CLS");
			printf("Invalid option\n");
		}
	} while (op != 0);
	printf("\n Concluded\n");
}

// Implementações
int menuJobs()
{
	setlocale(LC_ALL, "English");
	int op;
	printf("Registration Flexible Job Shop Problem");
	printf("\nSelect an option:");
	printf("\n1. Insert Operation");
	printf("\n2. Lists Operation");
	printf("\n3. Remove Operation");
	printf("\n4. Change Operation");
	printf("\n5. Maximum Time of Job");
	printf("\n6. Minimum Time of Job");
	printf("\n7. Average Time of Job");
	printf("\n8. Save Data");
	printf("\n9. Load Data");
	printf("\n0. Leave");
	printf("\nOption: ");
	scanf("%d", &op);
	return (op);
}

void MaximumTime(Operation* jobs)
{



}
void MinimumTime(Operation* jobs)
{


}
void AverageTime(Operation* jobs)
{


}


