#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
void add_player();
void delete_player();
void edit_player();
void player_details();
void read_index();
void read_player();
void write_PIndex();
void write_player();
int search_player();

typedef struct
{
        char PFName[30];
        char PLName[30];
        int DOB;
        int PHeight;
        char PPosition[5];
        char PAddress[50];
        int PTelephone;
}Member;

int sresult;
int PIndex;
Member player[30];


int main()
{
	int choice;
	system("color F0");
	PIndex = 0;

	do
	{
		system("cls");
		printf("\t\t\tWELCOME TO THE FOUNDATION BASKETBALL CAMP\n\t\t\t\t'Where stars are raised'\n\t\t\t\tprogrammed by TRAVIS BROWN\n");
		printf("\n\n\n\t\t\t\tMAIN MENU\n");
	    printf("\n\t\t\t\t1. Add Player \n\t\t\t\t2. View Player Details \n\t\t\t\t3. Edit Player Details \n\t\t\t\t4. Delete Player \n\t\t\t\t5. Exit\n\n");
	    printf("\t\t\tEnter your choice:\t");
	    scanf("%d", &choice);

	    switch(choice)
		{
	    case 1: system("cls");
				add_player();
	            getch();
	            break;

		case 2: system("cls");
				player_details();
	            getch();
	            break;

		case 3: system("cls");
				edit_player();
	            getch();
	            break;

		case 4: system("cls");
				delete_player();
	            getch;
	            break;

		case 5: system("cls");
				printf("Thank you for using Foundation Files, Ball is life\n");
	            getch();
	            break;

	    default: system("cls");
				 printf("That option does not exist\n");
	             getch();
	             break;
	    }
	}

     while (choice != 5);
     return 0;
}

void add_player()
{
    int ans;

    read_index();

    FILE *PlayerPtr;

    PlayerPtr = fopen("PlayerInfo.txt","a");

    if (PlayerPtr == NULL)
	{
            printf("File Cannot Open\n");
            getch();
    }
    else
    {
            if (PIndex == 30)
			{
                printf("Maximum number of players registered\n");
                getch();
            }
            else
        	{
                do
                {
                    system("cls");
					printf("Enter first name of player\n");
	                scanf("%s",player[PIndex].PFName);

	                printf("\nEnter last name of player\n");
	                scanf("%s",player[PIndex].PLName);

	                printf("\nEnter Date of birth (ddmmyyyy)\n");
	                scanf("%d",&player[PIndex].DOB);

	                printf("\nEnter Height of player (cm)\n");
	                scanf("%d",&player[PIndex].PHeight);

	                printf("\nEnter position(s) of player\n");
	                scanf("%s",player[PIndex].PPosition);

	                printf("\nEnter address of player\n");
	                fflush(stdin);
	                gets(player[PIndex].PAddress);

	                printf("\nEnter telephone number of player\n");
	                scanf("%d",&player[PIndex].PTelephone);

	                fprintf(PlayerPtr,"%s \n",player[PIndex].PFName);
	                fprintf(PlayerPtr,"%s \n",player[PIndex].PLName);
	                fprintf(PlayerPtr,"%d \n",player[PIndex].DOB);
	                fprintf(PlayerPtr,"%d \n",player[PIndex].PHeight);
	                fprintf(PlayerPtr,"%s \n",player[PIndex].PPosition);
	                fprintf(PlayerPtr,"%s \n",player[PIndex].PAddress);
	                fprintf(PlayerPtr,"%d \n \n",player[PIndex].PTelephone);

	                PIndex ++;

	                system("cls");
					printf("\nWould you like to continue? (type '1' for no and '2' for yes)\n");
	                fflush(stdin);
					scanf("%d", &ans);

				}while ((ans != 1) && (PIndex < 30));

				system("cls");
				printf("Player has been added");
				getch();

				write_PIndex();
			}
	}

	fclose(PlayerPtr);
}


int search_player()
{
	read_player();
	read_index();

	char TFName[30];
	char TLName[30];
	int compare1;
	int compare2;
	int i;

	printf("Enter first name\n");
	scanf ("%s",TFName);

	printf("\nEnter last name\n");
	scanf("%s",TLName);

	for (i = 0; i < PIndex; i++)
	 {
		compare1 = strcmp (TFName, player[i].PFName);
		compare2 = strcmp (TLName, player[i].PLName);

		if ((compare1 == 0) && (compare2 == 0))
		{
        	return i;
		}
    }
	return -1;
}

void player_details()
{
	sresult = search_player();

	system("cls");

	if (sresult == -1)
    {
        printf("Player was not found\n");
        getch();
    }
	else
    {
		printf("Player's Information: \n'");
		printf("\tName: %s ", player[sresult].PFName);
        printf("%s\n", player[sresult].PLName);
        printf("\tDate of Birth (ddmmyyyy): %d\n", player[sresult].DOB);
        printf("\tPlayer's Height(cm): %d\n", player[sresult].PHeight);
        printf("\tPlayer's Position: %s\n", player[sresult].PPosition);
        printf("\tPlayer's Address: %s", player[sresult].PAddress);
        printf("\n\tPlayer's Telephone Number: %d", player[sresult].PTelephone);
	}
}

void edit_player()
{
    int choice2;
    int EditAns;
    char nFName[30];
    char nLName[30];
    int nDOB;
    int nHeight;
    char nPosition[5];
    char nAddress[50];
    int nTelephone;

	sresult = search_player();

	system("cls");
	if (sresult == -1)
	{
       printf("Player was not found\n");
       getch();
    }
	else
    {
		do
        {
            system("cls");
			printf("What would you like to edit?\n");
            printf("\n\t1. First name \n\t2. Last name \n\t3. Date of Birth(ddmmyyyy) \n\t4. Height(cm) \n\t5. Position \n\t6. Home Address \n\t7. Telephone Number\n");
            printf("\nEnter your choice: \n");
            scanf("%d", &choice2);

            switch(choice2)
            {
				case 1: system("cls");
						printf("\t Please enter the new first name\n");
						scanf("%s",nFName);
						strcpy(player[sresult].PFName, nFName);
						getch();
						break;

				case 2: system("cls");
						printf("\t Please enter the new last name\n");
						scanf("%s",nLName);
						strcpy(player[sresult].PLName, nLName);
						getch();
						break;

				case 3: system("cls");
						printf("\t Please enter the new Date of Birth (ddmmyyyy)\n");
						scanf("%d", &nDOB);
						player[sresult].DOB = nDOB;
						getch();
						break;

	            case 4: system("cls");
						printf("\t Please enter the new height in centimeters\n");
						scanf("%d",&nHeight);
						player[sresult].PHeight = nHeight;
						getch();
						break;

				case 5: system("cls");
						printf("\t Please enter the new position\n");
						scanf("%s",nPosition);
						strcpy(player[sresult].PPosition, nPosition);
						getch();
						break;

				case 6: system("cls");
						printf("\t Please enter the new home address\n");
						gets(nAddress);
						strcpy(player[sresult].PAddress, nAddress);
						getch();
						break;

				case 7: system("cls");
						printf("\t Please enter the new telephone number\n");
						scanf("%d",&nTelephone);
						player[sresult].PTelephone = nTelephone;
						getch();
						break;

				default: system("cls");
						 printf("That option does not exist\n");
		                 getch();
		                 break;
            }

            system("cls");
            printf("Would you like to edit again? 1 for yes and 2 for no\n");
            scanf("%d", &EditAns);

        }while (EditAns != 2);

        write_player();
    }
}


void delete_player()
{
	int i;
	FILE *PlayerPtr;
	PlayerPtr = fopen("PlayerInfo.txt", "w");
	if (PlayerPtr == NULL)
    {
        printf("File Cannot Open");
        getch();
    }
    else
    {
    	sresult = search_player();

		if (sresult == -1)
		{
			printf("Player was not found");
			getch();
		}
		else
		{
			for (i = 0; i <= PIndex - 1; i++)
			{
				if (i != sresult)
				{
						fprintf(PlayerPtr,"%s \n",player[i].PFName);
		            	fprintf(PlayerPtr,"%s \n",player[i].PLName);
		                fprintf(PlayerPtr,"%d \n",player[i].DOB);
		                fprintf(PlayerPtr,"%d \n",player[i].PHeight);
		                fprintf(PlayerPtr,"%s \n",player[i].PPosition);
		                fprintf(PlayerPtr,"%s \n",player[i].PAddress);
		                fprintf(PlayerPtr,"%d \n \n",player[i].PTelephone);
				}
			}
			PIndex--;
			write_PIndex;
		}
	}
	fclose(PlayerPtr);
}


void read_index()
{
    FILE *PlayernumPtr;
    PlayernumPtr = fopen("PIndex.txt","r");
    if (PlayernumPtr == NULL)
    {
        printf("File Cannot Open");
        getch();
    }
    else
    {
    	fscanf(PlayernumPtr,"%d", &PIndex);
    }
	fclose(PlayernumPtr);
}

void write_PIndex()
{
    FILE *PlayernumPtr;
    PlayernumPtr = fopen("PIndex.txt","w");
    if (PlayernumPtr == NULL)
    {
    	printf("File Cannot Open\n");
    	getch();
    }
    else
    {
    	fprintf(PlayernumPtr,"%d", PIndex);
    }
	fclose(PlayernumPtr);
}

void read_player()
{
    int i;
	FILE *PlayerPtr;
    PlayerPtr = fopen("PlayerInfo.txt","r");
    if ("PlayerPtr.txt" == NULL)
    {
        printf("File Cannot Open\n");
        getch();
    }
    else
    {
        for (i = 0; i < PIndex; i++);
        {
            fscanf(PlayerPtr,"%s \n",player[i].PFName);
            fscanf(PlayerPtr,"%s \n",player[i].PLName);
            fscanf(PlayerPtr,"%d \n",&player[i].DOB);
            fscanf(PlayerPtr,"%d \n",&player[i].PHeight);
            fscanf(PlayerPtr,"%s \n",player[i].PPosition);
            fgets(player[i].PAddress, 30, PlayerPtr);
            fscanf(PlayerPtr,"%d \n",&player[i].PTelephone);
        }
	}
	fclose(PlayerPtr);
}

void write_player()
{
    int i;
    FILE *PlayerPtr;
    PlayerPtr = fopen("PlayerInfo.txt","w");
    if (PlayerPtr == NULL)
    {
        printf("File Cannot Open\n");
        getch();
    }
    else
    {
        for (i = 0; i < PIndex; i++);
        {
            fprintf(PlayerPtr,"%s \n",player[PIndex].PFName);
            fprintf(PlayerPtr,"%s \n",player[PIndex].PLName);
            fprintf(PlayerPtr,"%d \n",player[PIndex].DOB);
            fprintf(PlayerPtr,"%d \n",player[PIndex].PHeight);
            fprintf(PlayerPtr,"%s \n",player[PIndex].PPosition);
            fprintf(PlayerPtr,"%s \n",player[PIndex].PAddress);
            fprintf(PlayerPtr,"%d \n\n",player[PIndex].PTelephone);
        }
    }
    fclose(PlayerPtr);
}

