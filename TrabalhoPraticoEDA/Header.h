#pragma once


// Protótipos

typedef struct OperationRegistration
{
	int name;
	int numero;
	int time;
	struct OperationRegistration* next;
}Operation;


int menuJobs();
Operation* readJobs(Operation* jobs);
void saveJobs(Operation* jobs);
Operation* insertJobs(Operation* jobs, int name, int num, int time);
Operation* removeJobs(Operation* jobs, int number);
Operation* changeData(Operation* jobs, int number);
void listsJobs(Operation* jobs);
void MaximumTime(Operation* jobs);
void MinimumTime(Operation* jobs);
void AverageTime(Operation* jobs);



