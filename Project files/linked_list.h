//Liberaries
#include<stdio.h>
#include<stdlib.h>
#include"typedef.h"
#include<string.h>

//Gaurd
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#endif

//1. Patient linked list

	
struct Pateints{
	int id;
	int age;
	char name[50];
	char gender[6];
	struct Pateints* next;
	
};

//Head
struct Pateints* head = NULL;

//Functions prototype
int Find(int ID);
void Insert_end(int ID, int AGE ,char* NAME,char* GENDER);
void Edit_pos(int ID, int AGE ,char* NAME,char* GENDER);
void Delete_pos(int ID);
void View_pos(int ID);

// find pateint
int Find(int ID){
	if(head == NULL){
		return 0;
	}
	else{
		struct Pateints* patient = (struct Pateints*)malloc(sizeof(struct Pateints));
		patient = head;
		while((patient->next != NULL) && (ID != patient->id)){
			patient = patient->next;
		}
		if(ID != patient->id){
			return 0;
		}
		else{
			return 1;
		}
	}
}

//Add patient function
void Insert_end(int ID, int AGE ,char* NAME,char* GENDER)
{
	struct Pateints* patient = (struct Pateints*)malloc(sizeof(struct Pateints));
	
	//Entering patient's data
	patient->id = ID; 
	patient->age = AGE; 
	strcpy(patient->name,NAME); 
	strcpy(patient->gender,GENDER); 
	patient->next = NULL;
	
	//If linked list is empty
	if(head==NULL)	{
		head = patient;
	}
	//Add pateint in the end
	else{
		struct Pateints* temp = (struct Pateints*)malloc(sizeof(struct Pateints));
		temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = patient;
	}
}

//View pateint's Data
void View_pos(int ID)
{
	//If linked list is empty
	if(head==NULL)
	{
		printf("\nPateint not found\n");
		return;
	}
	else{
		struct Pateints* patient = (struct Pateints*)malloc(sizeof(struct Pateints));
		patient = head;
		while((ID != patient->id) && (patient->next != NULL)){
			patient = patient->next;
		}
		if(ID == patient->id){
			printf("\nPatient found!\nPatient Data: ");
			printf("\nPateint id: %d",patient->id);
			printf("\nPateint age: %d",patient->age);
			printf("\nPateint name: %s",patient->name);
			printf("\nPateint gender: %s\n",patient->gender);
		}
		else{
			printf("\nPatient Not Found\n");
		}
	}
} 

// Editing pateints by id
void Edit_pos(int ID, int AGE ,char* NAME,char* GENDER)
{	
	//If linked list is empty
	if(head==NULL)	{
		printf("\nPatient Not Found");
		return;
	}
	else
	{
		struct Pateints* patient = head;
		while((ID != patient->id) && (patient->next != NULL)){
			patient = patient->next;
		}
		if(ID == patient->id){
			patient->age = AGE; 
			strcpy(patient->name,NAME); 
			strcpy(patient->gender,GENDER); 
		}
		else{
			printf("\n22Patient Not Found");
		}
	}
} 

// Delete patient 
void Delete_pos(int ID)
{ 
	//If linked list is empty
	if(head==NULL)
	{
		printf("Pateint not found!\n"); 
		return;
	}
	else
	{
		struct Pateints* patient = (struct Pateints*)malloc(sizeof(struct Pateints));
		patient = head;  
		struct Pateints* temp = (struct Pateints*)malloc(sizeof(struct Pateints));
		while((ID != patient->id) && (patient->next != NULL)){
			temp = patient;
			patient = patient->next;
		}
		temp->next = patient->next;
		head = temp;
		free(patient);
	}
}

