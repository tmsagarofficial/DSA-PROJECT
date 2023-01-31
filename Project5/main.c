#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<windows.h>

//generic-stuff
int bid = 1001;

int authstat = 0;
void table();//done
void display(struct node*);//done
void waitprint(char []);//done
char str1[100] = "Logging in............\n";

//staff
void staffdisplay();
void stafflogin();//done
int slogin();//done

//citizen
void citizendisplay();
void citizenlogin();//done
int slogin();//done

//doctor
void doctorlogin();//done
int dlogin();//done
void doctordisplay();


//structure
struct node
{
    char* name[25];
    int age;
    char* address[30];
    int phone[13];
    char bloodgroup[3];
    int id;
    int priority;
    struct node* next;
};

struct node* start = NULL;
struct node* insert(struct node*);
struct node* delete(struct node*);


int main()
{
    int ch;
    system("COLOR A0");
    label1:
    printf("\t\t\t-------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t   WELCOME TO v3 HOSPITAL!\n");
    printf("\t\t\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t-------------------------------\n");
    printf("\t\t\t\t   LOGIN  \n\n");
    printf("\t\t\t[1].Staff[2].Citizen[3].Doctor\n\n");
    printf("\t\t\t         [4].Exit   \t\n\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        stafflogin();
        break;

    case 2:
        citizenlogin();
        break;

    case 3:
        doctorlogin(); 
            break;
    case 4:exit(0);
        break;
    default:
        printf("\nEnter valid choice..!\n");
        goto label1;
    }
}





//staff
void stafflogin() {
    system("cls");
    printf("STAFF-LOGIN-PAGE");
    if (slogin()) {
        waitprint(str1);
        staffdisplay();
    }
    else {
        main();
    }
}
int slogin() {
    int i;
    FILE* fp;
    fp = fopen("pws.txt", "r");
    char uname[10], pass[10], data[10], input[10],ch[10];
    printf("\nUSERNAME:");
    scanf("%s", uname);
    printf("\nPASSWORD:");
	for (i = 0; i < 8; i++)
	{
        char ch;
		ch = getch();
		input[i] = ch;
		ch = '*';
		printf("%c", ch);
	}
    input[i] = '\0';
    fscanf(fp, "%s", data);
    if (strcmp(data, input) == 0)
    {
        system("cls");
        printf("\nAuthentication Succesfull.\n");
        authstat = 1;
    }
    else
    {
        printf("\nAuthentication unsuccesful.\n");

    }
    fclose(fp);
    return authstat;
}
void staffdisplay()
{
    int option;
    system("cls");
    printf("\t\t\t1.ADD A PATIENT\n");
    printf("\t\t\t2.DELETE A RECORD\n");
    printf("\t\t\t3.DISPLAY ALL APPOINTMENTS\n");
    printf("\t\t\t4.EXIT\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        start = insert(start);
        getchar();
        system("cls");
        break;
    case 2:
        start = delete(start);
        getchar();
        system("cls");
        break;
    case 3:
        display(start);
        getchar();
        system("cls");
        break;
    case 4:
        exit(0);
        break;
    }
}



//citizen
void citizenlogin() {
    system("cls");
    printf("CITIZEN-LOGIN-PAGE");
    if (clogin()) {
        waitprint(str1);
        citizendisplay();
    }
    else {
        main();
    }
    
}
int clogin() {
    FILE* fp;
    int i;
    fp = fopen("pwc.txt", "r");
    char uname[10], pass[10], data[10], input[10];
    printf("\nUSERNAME:");
    scanf("%s", uname);
    printf("\nPASSWORD:");
    for (i = 0; i < 8; i++)
    {
        char ch;
        ch = getch();
        input[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    input[i] = '\0';
    fscanf(fp, "%s", data);
    if (strcmp(data, input) == 0)
    {
        system("cls");
        printf("\nAuthentication Succesfull.\n");
        authstat = 1;
    }
    else
    {
        printf("\nAuthentication unsuccesful.\n");

    }
    fclose(fp);
    return authstat;
}
void citizendisplay()
{
    int option;
    system("cls");
    printf("\t\t\t1.BOOK APPOINTMENT\n");
    printf("\t\t\t2.DELETE AN APPOINTMENT\n");
    printf("\t\t\t3.DISPLAY ALL APPOINTMENTS\n");
    printf("\t\t\t4.EXIT\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        start = insert(start);
        getchar();
        system("cls");
        break;
    case 2:
        start = delete(start);
        getchar();
        system("cls");
        break;
    case 3:
        display(start);
        getchar();
        system("cls");
        break;
    case 4:
        exit(0);
        break;
    }
}


//doctor
void doctorlogin() {
    system("cls");
    printf("DOCTOR-LOGIN-PAGE");
    if (dlogin()) {
        waitprint(str1);
        doctordisplay();
    }
    else {
        main();
    }
    
}
int dlogin() {
    FILE* fp;
    int i;
    fp = fopen("pwd.txt", "r");
    char uname[10], pass[10], data[10], input[10];
    printf("\nUSERNAME:");
    scanf("%s", uname);
    printf("\nPASSWORD:");
    for (i = 0; i < 8; i++)
    {
        char ch;
        ch = getch();
        input[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    input[i] = '\0';
    fscanf(fp, "%s", data);
    if (strcmp(data, input) == 0)
    {
        system("cls");
        printf("\nAuthentication Succesfull.\n");
        authstat = 1;
    }
    else
    {
        printf("\nAuthentication unsuccesful.\n");

    }
    fclose(fp);
    return authstat;
}
void doctordisplay() {

}

//generic
void waitprint(char str[]) {
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        printf("%c", str[i]);
        Sleep(150);
    }
}

struct node* insert(struct node* start)
{
    int val2, val4, val6, pri;
    char val1, val3, val5;
    struct node* ptr, * p;
    char* name[100];
    char* address[100];
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter patient Name:");
    scanf(" %[^\n]*%c", ptr->name);
    printf("Enter the patient's age:");
    scanf("%d", &val2);
    printf("Enter your home address:");
    scanf(" %[^\n]*%c", ptr->address);
    printf("Enter your phone number:");
    scanf("%d", &val4);
    printf("Enter the blood group of Patient:");
    scanf(" %s", ptr->bloodgroup);
    printf("Your id no : %d",++bid);
    table();
    scanf("%d", &pri);
    //ptr->name=name;
    ptr->age = val2;
    //ptr->address=address;
    //ptr->phone = val4;
    ptr->id = bid;
    ptr->priority = pri;
    if ((start == NULL) || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != NULL && p->next->priority <= pri)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
};


struct node* delete(struct node* start)
{
    struct node* ptr;
    if (start == NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE");
        return;
    }
    else
    {
        ptr = start;
        printf("\n Deleted Record is : %d", ptr->id);
        start = start->next;
        free(ptr);
    }
    return start;
};


void display(struct node* start)
{
    struct node* ptr;
    ptr = start;
    if (start == NULL)
        printf("\nTHERE IS NO PATIENT");
    else
    {
        printf("\nPriority wise appointments are:");
        while (ptr != NULL)
        {
            printf("The name of patient is:%s\n", ptr->name);
            printf("The age of patient is:%d\n", ptr->age);
            printf("The address of patient is : %s\n", ptr->address);
            printf("Phone Number:%d\n", ptr->phone);
            printf("The blood group of patient is:%s\n", ptr->bloodgroup);
            printf("---------------------------------------------------\n");
            ptr = ptr->next;
        }
    }
    getchar();
}


void table()
{
    printf("\nPlease Refer this Table for your symptom//disease!\n");
    printf("[1].Heart attack\n");
    printf("[2].Severe wound/Bleeding\n");
    printf("[3].Cancer\n");
    printf("[4].Chest pain\n");
    printf("[5].Fracture\n");
    printf("[6].Diabetes Checkup\n");
    printf("[7].Infection\n");
    printf("[8].Viral Fever\n");
    printf("[9].Common Cold/Head ache\n");
}
