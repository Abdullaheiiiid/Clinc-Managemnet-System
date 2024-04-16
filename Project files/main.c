//Libraries
#include<stdio.h>
#include<stdlib.h>
#include"typedef.h"
#include"linked_list.h"
#include"reservation.h"
#include<string.h>

//Global variables
int logIn = 1;

//Functions prototype
void welcome_interface();
void admin_mode();
void admin();
int login();
void add_new_patient();
void edit_patient();
void reserve_slot();
void cancel();
int return_to_admin_or_exit();
void user_mode();
void view_patient();
void View_today_reservations();
int return_to_user_or_exit();

//Main
int main(){
	welcome_interface();
	if(!logIn)
		return 0;
	return 0;
}

//Welcome interface function
void welcome_interface(){
	system("cls");
	//Welcome
	printf("\n***********************************************************************************");
	printf("\n***********************************************************************************");
	printf("\n\n\t\t\t Welcome to Clinic Management System\n");
	printf("\n***********************************************************************************");
	printf("\n***********************************************************************************");
	
	//Choosing mode
	label:
	printf("\n\nPlease choose mode:" );
	printf("\n1. Admin mode.");
	printf("\n2. User mode.");
	printf("\n3. Exit.");
	printf("\nEnter number: ");
	int mode;
	scanf("%d",&mode);
	switch(mode){
	case 1:
		admin_mode();
		if(!logIn)
			return;
		break;
	case 2:
		user_mode();
		break;
	case 3:
		_Exit(0);
	default:
		printf("\nInvalid Character!");
		goto label;
	}
}

//Admin mode function
void admin_mode(){
	system("cls");	
	//Welcome
	printf("\n***********************************************************************************");
	printf("\n\t\t\t\t Welcome to Admin Mode");
	printf("\n***********************************************************************************");
	
	//Check login
	if(!login()){
		return;
	}
	else{
		admin();
	}
}

//Login function
int login(){
	
	//Variables
	int const PW = 123;
	int pass_count = 0;
	int password;
	
	printf("\n\nPlease enter the password: ");
	while(pass_count < 3){
		if(pass_count != 0){
			system("cls");
			printf("Incorect password!, please enter the password again: ");
		}
		scanf("%d" , &password);
		if(password != PW){
			pass_count++;
		}
		else{
			system("cls");
			logIn = 1;
			return 1;
		}
	}
	if(pass_count == 3){
		system("cls");
		printf("Incorrect password for 3 times, no more tries");
		logIn = 0;
		return 0;
	}
} 

//Admin function
void admin(){
	system("cls");
	//Variables
	int p;
	
	printf("\n Welcome admin!, Here are some processes you can do: ");
	printf("\n1. Add new patient record.");
	printf("\n2. Edit patient record.");
	printf("\n3. Reserve a slot with the doctor.");
	printf("\n4. Cancel reservation.");
	printf("\n5. Return.");
	printf("\n6. Exit.");
	label1:
	printf("\nEnter process number: ");
	scanf("%d",&p);
	switch(p){
		case 1:
			add_new_patient();
			break;
		case 2:
			edit_patient();
			break;
		case 3:
			reserve_slot();
			break;
		case 4:
			cancel();
			break;
		case 5:
			welcome_interface();
			break;
		case 6:
			_Exit(0);
		default:
			printf("\nWrong number!");
			goto label1;
	}
}
//add new patient function
void add_new_patient(){
	system("cls");
	//variables
	int id;
	
	label3:
	printf("Enter patient id: ");
	scanf("%d",&id);
	if(Find(id)){
		printf("patient is already exist!\n");
		goto label3;
	}
	else{
		//Variables
		int age;
		char name[50];
		char gender[6];
		printf("Enter patient data: ");
		printf("\nage: ");
		scanf("%d",&age);
		printf("name: ");
		scanf("%s",name);
		printf("gender: ");
		scanf("%s",gender);
		Insert_end(id,age,name,gender);
		printf("Patient was added successfully.\n");
	}
	return_to_admin_or_exit();
}

//edit patient's data function
void edit_patient(){
	system("cls");
	//variables
	int id;
	
	label3:
	printf("Enter patient id: ");
	scanf("%d",&id);
	if(!Find(id)){
		printf("Wrong id!,enter valid id\n");
		goto label3;
	}
	else{
		//Variables
		int age;
		char name[50];
		char gender[6];
		
		printf("Enter patient new data: ");
		printf("\nage: ");
		scanf("%d",&age);
		printf("name: ");
		scanf("%s",name);
		printf("gender: ");
		scanf("%s",gender);
		Edit_pos(id,age,name,gender);
		printf("Patient data was edited successfully.\n");
	}
	return_to_admin_or_exit();
}

//reserve slot with doctor function
void reserve_slot(){
	system("cls");
		//variables
	int id;
	
	label6:
	printf("Enter patient id: ");
	scanf("%d",&id);
	if(!Find(id)){
		printf("Wrong id!,enter valid id\n");
		goto label6;
	}
	else{
		Available_res(id);
	}
	return_to_admin_or_exit();
}

//cancel reservation function
void cancel(){
	system("cls");
	int id;
	
	label6:
	printf("Enter patient id: ");
	scanf("%d",&id);
	if(!Find(id)){
		printf("Wrong id!,enter valid id\n");
		goto label6;
	}
	else{
		Cancel_res(id);
	}
	return_to_admin_or_exit();
}

//Return or exit function
int return_to_admin_or_exit(){
	int press;
	label4:
	printf("\n1. Return");
	printf("\n2. Exit\n");
	printf("\nEnter number: ");
	scanf("%d",&press);
	switch(press){
		case 1:  admin();
			break;
		case 2: _Exit(0);
		default : printf("\n Wrong number!");
		goto label4;
	}
}

//user mode function
void user_mode(){
	system("cls");
	//Variables
	int p;
	
	printf("\n***********************************************************************************");
	printf("\n\t\t\t Welcome to User Mode");
	printf("\n***********************************************************************************");	
	printf("\nHere are some processes you can do: ");
	printf("\n1. View patient record.");
	printf("\n2. View today reservations.");
	printf("\n3. Return.");
	printf("\n4. Exit.");
	
	
	label2:
	printf("\nEnter process number: ");
	scanf("%d",&p);
	switch(p){
		case 1:
			view_patient();
			break;
		case 2:
			View_today_reservations();
			break;
		case 3:
			welcome_interface();
			break;
		case 4:
			_Exit(0);
		default:
			printf("\nWrong number!");
			goto label2;
	}
}

// view patient record function
void view_patient(){
	system("cls");
	//variables
	int id;
	
	label3:
	printf("Enter patient id: ");
	scanf("%d",&id);
	if(!Find(id)){
		printf("Wrong id!,enter valid id\n");
		goto label3;
	}
	else{
		View_pos(id);
		printf("Patient data was shown successfully.\n");
	}
	return_to_user_or_exit();
}

// view today's reservations function
void View_today_reservations(){
	system("cls");
		//variables
	int id;
	
	label3:
	printf("Enter patient id: ");
	scanf("%d",&id);
	if(!Find(id)){
		printf("Wrong id!,enter valid id\n");
		goto label3;
	}
	else{
		View_res(id);
	}
	return_to_user_or_exit();
}

//Return or exit function
int return_to_user_or_exit(){
	int press;
	label4:
	printf("\n1. Return");
	printf("\n2. Exit\n");
	printf("\nEnter number: ");
	scanf("%d",&press);
	switch(press){
		case 1:  user_mode();
			break;
		case 2: _Exit(0);
		default : printf("\n Wrong number!");
		goto label4;
	}
}



