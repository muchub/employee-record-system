#include <stdio.h>
#include <string.h>
#include <windows.h>

#define dataLength 30
#define dataColumn 4

FILE *fp;
char listName[dataLength][20], listAge[dataLength][20], listSalary[dataLength][20], listPhone[dataLength][20], listData[dataLength][20];
char setName[dataLength], setAge[dataLength], setPhone[dataLength], setSalary[dataLength], option[10], back[1] = {""};
char dataEmployee[dataLength], dataName[dataLength], dataAge[dataLength], dataPhone[dataLength], dataSalary[dataLength];
int head = 0, tail = 1, k, cName = 0, cAge = 1, cPhone = 2, cSalary = 3, a = 0, b = 0, c = 0, d=0;

char filename[10] = "data.txt";

void dataEmp();
void displayData();
void empDetail();
void exportData();

int main()
{
    do
    {
        system("cls");

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
            //Insert Data
            while (1)
            {
                system("cls");
                empDetail();

                for (int i = head; i < tail; i++)
                {
                    strcpy(listName[head], setName);
                    strcpy(listAge[head], setAge);
                    strcpy(listPhone[head], setPhone);
                    strcpy(listSalary[head], setSalary);
                    exportData();
                    printf("Your data has been inserted\nEnter Y for insert another data: ");
                    head++;
                    tail++;
                    break;
                }
                scanf("%s", &back);
                if (strcmp(back, "Y") != 0)
                {
                    break;
                }
            }
        }
        else if (strcmp(option, "2") == 0)
        {
            //Edit data
            int dataID, cType;
            while (1)
            {
                system("cls");
                displayData();
                printf("\nEnter data ID 0 for cancel: ");
                scanf("%d", &dataID);
                if (dataID == 0)
                {
                    break;
                }
                printf("\nEnter 1-Name, 2-Age, 3-Phone number, 4-Salary : ");
                scanf("%d", &cType);
                //empDetail();
                while (1)
                {
                    if (cType == 1)
                    {
                        printf("Enter new name: ");
                        scanf("%s", setName);
                        strcpy(listName[dataID - 1], setName);
                        break;
                    }
                    if (cType == 2)
                    {
                        printf("Enter new age: ");
                        scanf("%s", setAge);
                        strcpy(listAge[dataID - 1], setAge);
                        break;
                    }
                    if (cType == 3)
                    {
                        printf("Enter new phone number: ");
                        scanf("%s", setPhone);
                        strcpy(listPhone[dataID - 1], setPhone);
                        break;
                    }
                    if (cType == 4)
                    {
                        printf("Enter new salary: ");
                        scanf("%s", setSalary);
                        strcpy(listSalary[dataID - 1], setSalary);
                        break;
                    }
                }
                exportData();
                printf("\n\nData changed\nEnter Y for edit another data: ");
                scanf("%s", back);
                if (strcmp(back, "Y") != 0)
                {
                    break;
                }
            }
        }
        else if (strcmp(option, "3") == 0)
        {
            //Delete data
            int dataID;
            while (1)
            {
                system("cls");
                displayData();
                printf("\nEnter ID to delete 0 for cancel: ");
                scanf("%d", &dataID);
                if (dataID == 0)
                {
                    break;
                }
                for (int i = dataID - 1; i < tail; i++)
                {
                    strcpy(listName[i], listName[i + 1]);
                    strcpy(listAge[i], listAge[i + 1]);
                    strcpy(listPhone[i], listPhone[i + 1]);
                    strcpy(listSalary[i], listSalary[i + 1]);
                }
                exportData();

                printf("\nData deleted\nEnter Y to delete another data: ");
                scanf("%s", back);
                if (strcmp(back, "Y") != 0)
                {
                    break;
                }
            }
        }
        else if (strcmp(option, "4") == 0)
        {
            while (1)
            {
                system("cls");
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
        else if (i == cAge)
        {
            strcpy(listAge[b++], listData[cAge]);
            cAge = cAge + dataColumn;
        }
        else if (i == cPhone)
        {
            strcpy(listPhone[c++], listData[cPhone]);
            cPhone = cPhone + dataColumn;
        }
        else if (i == cSalary)
        {
            strcpy(listSalary[d++], listData[cSalary]);
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
    printf("ID\tName\t\tAge\t\tPhone \t\t\tSalary\n");
    printf("======================================================================\n");

    for (int i = 0; i < k / dataColumn; i++)
    {
        printf("%d\t%s\t\t%s\t\t%s\t\t\tRM %s\n", i + 1, listName[i],listAge[i], listPhone[i], listSalary[i]);
    }
}

void empDetail()
{
    printf("Enter Name: ");
    scanf("%s", &setName);
    printf("Enter Age: ");
    scanf("%s", &setAge);
    printf("Enter Phone Number: ");
    scanf("%s", &setPhone);
    printf("Enter Salary(RM): ");
    scanf("%s", &setSalary);
}

void exportData()
{
    fp = fopen(filename, "w+");
    for (int j = 0; j < tail; j++)
    {
        if (strcmp(listName[j], "") != 0)
        {
            fprintf(fp, "\n");
            fprintf(fp, listName[j]);
            fprintf(fp, " ");
            fprintf(fp, listAge[j]);
            fprintf(fp, " ");
            fprintf(fp, listPhone[j]);
            fprintf(fp, " ");
            fprintf(fp, listSalary[j]);
        }
    }
    fclose(fp);
}