#include <stdio.h>
#include <string.h>

#define dataLength 30
#define dataColumn 3

FILE *fp;
char listName[dataLength][20], listSalary[dataLength][20], listPhone[dataLength][20], listData[dataLength][20];
char setName[dataLength], setPhone[dataLength], setSalary[dataLength], option[10], back[1] = {""};
char dataEmployee[dataLength], dataName[dataLength], dataPhone[dataLength], dataSalary[dataLength];
int head = 0, tail = 1, k, cName = 0, cPhone = 1, cSalary = 2, a = 0, b = 0, c = 0;

char filename[10] = "data.txt";

void dataEmp()
{
    //check if file not exist create file
    if (!fopen(filename, "r+"))
    {
        fopen(filename, "w+");
    }

    k = 0;
    //Read all data from file
    fp = fopen(filename, "r+");
    while (!feof(fp))
    {
        fscanf(fp, "%s", dataEmployee);
        strcpy(listData[k], dataEmployee);
        k++;
    }
    fclose(fp);

    //sort data by category/column
    for (int i = 0; i < k; i++)
    {
        if (i == cName)
        {
            strcpy(listName[a++], listData[cName]);
            cName = cName + dataColumn;
        }
        else if (i == cPhone)
        {
            strcpy(listPhone[b++], listData[cPhone]);
            cPhone = cPhone + dataColumn;
        }
        else if (i == cSalary)
        {
            strcpy(listSalary[c++], listData[cSalary]);
            cSalary = cSalary + dataColumn;
        }
    }

    //Check last record
    for (int i = 0; i < k / dataColumn; i++)
    {
        head++;
        tail++;
    }
}

void displayData()
{
    printf("Name\t\tPhone \t\t\tSalary\n");
    printf("==============================================\n");

    for (int i = 0; i < k / dataColumn; i++)
    {
        printf("%s\t\t%s\t\t\tRM %s\n", listName[i], listPhone[i], listSalary[i]);
    }
}

int main()
{
    do
    {
        dataEmp();

        printf("[+]========================[+]\n");
        printf(" |  Employee record system  |\n");
        printf("[+]========================[+]\n\n");
        printf("1. Insert Record\n2. Edit record\n3. Delete record\n4. Display employee list\n");
        printf("\nPress E for exit program\n");
        printf("\nChoose Option: ");
        scanf("%s", &option);
        if (strcmp(option, "1") == 0)
        {
            printf("Enter Name: ");
            scanf("%s", &setName);
            printf("Enter Phone Number: ");
            scanf("%s", &setPhone);
            printf("Enter Salary(RM): ");
            scanf("%s", &setSalary);
            for (int i = head; i < tail; i++)
            {
                fp = fopen(filename, "w+");
                strcpy(listName[head], setName);
                strcpy(listPhone[head], setPhone);
                strcpy(listSalary[head], setSalary);
                for (int j = 0; j < tail; j++)
                {
                    fprintf(fp, "\n");
                    fprintf(fp, listName[j]);
                    fprintf(fp, " ");
                    fprintf(fp, listPhone[j]);
                    fprintf(fp, " ");
                    fprintf(fp, listSalary[j]);
                }
                fclose(fp);
                break;
            }
        }
        else if (strcmp(option, "2") == 0)
        {
            while (1)
            {
                printf("Under const");
                printf("\n\nPress any key to back: ");
                scanf("%s", back);
                if (strcmp(back, "") == 0 || strcmp(back, "") != 0)
                {
                    break;
                }
            }
        }
        else if (strcmp(option, "3") == 0)
        {
            int dataDel;
            while (1)
            {
                //printf("Under const");
                while (1)
                {
                    printf("Enter data to delete: ");
                    scanf("%d", &dataDel);
                    if (dataDel == 1)
                    {
                        printf("Data %d has been deleted", dataDel);
                        break;
                    }
                }
                printf("\n\nPress any key to back: ");
                scanf("%s", back);
                if (strcmp(back, "") == 0 || strcmp(back, "") != 0)
                {
                    break;
                }
            }
        }
        else if (strcmp(option, "4") == 0)
        {
            while (1)
            {
                displayData();
                
                printf("\n\nPress any key to back: ");
                scanf("%s", back);
                if (strcmp(back, "") == 0 || strcmp(back, "") != 0)
                {
                    break;
                }
            }
        }
    } while (strcmp(option, "E") != 0);
}