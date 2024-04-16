//Liberaries
#include<stdio.h>
#include<stdlib.h>
#include"typedef.h"
#include <string.h>

//Gaurd
#ifndef RESERVATION_H
#define RESERVATION_H
#endif

//2. Reservation linked list
	
struct reservation{
	int id;
	char slots[10];
	int slot;
	//free slot --> 0
	// 2 - 2:30 --> 1
	// 2:30 - 3 --> 2
	// 3 - 3:30 --> 3
	// 4 - 4:30 --> 4
	// 4:30 - 5 --> 5
	struct reservation* next;
	
};

//Head
struct reservation* Head = NULL;

//Functions prototype
void Insert_res(int ID, int SLOT);
void Available_res(int ID);
void Cancel_res(int ID);
void View_res(int ID);

int Slots = 5;

//Add reservation function
void Insert_res(int ID, int SLOT)
{
	Slots--;
	struct reservation* res = (struct reservation*)malloc(sizeof(struct reservation));
	
	//Entering reservation's data
	res->id = ID; 
	res->slot = SLOT;
	switch(SLOT){
		case 1:
			strcpy(res->slots,"2-2:30"); 
			break;
		case 2:
			strcpy(res->slots,"2:30-3"); 
			break;
		case 3:
			strcpy(res->slots,"3-3:30"); 
			break;
		case 4:
			strcpy(res->slots,"4-4:30"); 
			break;
		case 5:
			strcpy(res->slots,"4:30-5"); 
			break;
	}
	res->next = NULL;
	
	//If linked list is empty
	if(Head==NULL)	{
		Head = res;
	}
	//Add pateint in the end
	else{
		struct reservation* temp = (struct reservation*)malloc(sizeof(struct reservation));
		temp = Head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = res;
	}
}

//View available reservations
void Available_res(int ID)
{
	if(Slots == 0)
	{
		printf("\nSorry no slots available!");
		return;
	}
    else{
		struct reservation* res = (struct reservation*)malloc(sizeof(struct reservation));
		res = Head;
		int arr[5] = {0,0,0,0,0};
		int i = 0;
		while(res != NULL){
			arr[i] = res->slot;
			res = res->next;
			i++;
		}
		int k = 0;
		int flag;
		char new[5][8];
		printf("\nThe available slots: ");
		for(i = 1 ; i <= 5 ; i++){
			flag =0;
			for(int j = 0 ; j <5 ;j++){
				if(arr[j] == i){
					flag = 1;
					break;
				}
			}
			if(!flag){
				switch(i){
					case 1:
						strcpy(new[k],"2-2:30"); 
						break;
					case 2:
						strcpy(new[k],"2:30-3"); 
						break;
					case 3:
						strcpy(new[k],"3-3:30"); 
						break;
					case 4:
						strcpy(new[k],"4-4:30"); 
						break;
					case 5:
						strcpy(new[k],"4:30-5"); 
						break;
				}
				printf("\n%d. %s",k+1,new[k]);
				k++;
			}
		}
		int s;
		label5:
		printf("\nEnter Number: ");
		scanf("%d",&s);
		if(s <= k){
			if(strcmp(new[s-1], "2-2:30")==0)
				Insert_res(ID,1);
			if(strcmp(new[s-1], "2:30-3")==0)
				Insert_res(ID,2);
			if(strcmp(new[s-1], "3-3:30")==0)
				Insert_res(ID,3);
			if(strcmp(new[s-1], "4-4:30")==0)
				Insert_res(ID,4);
			if(strcmp(new[s-1], "4:30-5")==0)
				Insert_res(ID,5);
			printf("\nReservation completed successfully!");
		}
		else{
			printf("\n Wrong number!");
			goto label5;
		}
	}
}

//View pateint's reservations
void View_res(int ID)
{
	//If linked list is empty
	if(Head==NULL)
	{
		printf("\nYou do not have a reservation\n");
		return;
	}
	else{
		struct reservation* res = (struct reservation*)malloc(sizeof(struct reservation));
		res = Head;
		int flag = 0;
		while((res != NULL)){
			if(ID == res->id){
				printf("\nYou have a reservation at: %s",res->slots);
				flag = 1;
			}
			res = res->next;
		}
		if(!flag){
			printf("\nYou do not have a reservation\n");
		}
	}
} 

//Cancel reservation
void Cancel_res(int ID)
{ 
	//If linked list is empty
	if(Head==NULL || Slots == 5)
	{
		printf("The patient does not have a reservation\n"); 
		return;
	}
	else
	{
		struct reservation* res = (struct reservation*)malloc(sizeof(struct reservation));
		res = Head;
		int flag = 0;
		int i = 0;
		int arr[5]={0,0,0,0,0};
		while((res != NULL)){
			if(ID == res->id){
				printf("\nPatient has a reservation at: ");
				break;
			}
			res = res->next;
		}
		res = Head;
		while((res != NULL)){
			if(ID == res->id){
				printf("\n%d. %s",i+1,res->slots);
				arr[i] = res->slot;
				i++;
				flag = 1;
			}
			res = res->next;
		}
		if(!flag){
			printf("\nPatient has not a reservation\n");
		}
		else{
			int s;
			label5:
			printf("\nEnter number: ");
			scanf("%d",&s);
			if(s <= i){ 
				struct reservation* prev = (struct reservation*)malloc(sizeof(struct reservation));
				res = Head;
				while(res != NULL){
					if(arr[s-1] == res->slot)
						break;
					prev = res;
					res = res->next;
				}
				if(arr[s-1] == res->slot){
					if(res == Head){
						Head = Head->next;
						res = Head;
					}
					else
						prev->next = res->next;
					free(res);		
					Slots++;					
				}
			}
			else{
				printf("\n Wrong number!");
				goto label5;
			}
		}
		
	}
}
