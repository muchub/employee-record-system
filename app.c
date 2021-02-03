#include <stdio.h>
#include <string.h>
#include <windows.h>

#define dataLength 30
#define dataColumn 4

FILE *fp;
char setName[dataLength], setAge[dataLength], setPhone[dataLength], setSalary[dataLength], option[10], back[1] = {""};
char exportDataEmployee[dataLength];
int head = 0, tail = 1, k, cName = 0, cAge = 1, cPhone = 2, cSalary = 3, a = 0, b = 0, c = 0, d = 0;
int nub;

struct EMP
{
    char Name[dataLength][20];
    char Age[dataLength][20];
    char Salary[dataLength][20];
    char Phone[dataLength][20];
    char Data[dataLength][20];
} emp;

char filename[10] = "data.txt";

void exportData();
void displayData();
void empDetail();
void importData();
void Clear();

int main()
{
    do
    {
        system("cls");
        exportData();
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
                printf("Enter Name: ");
                scanf("%s", &setName);
                printf("Enter Age: ");
                scanf("%s", &setAge);
                printf("Enter Phone Number: ");
                scanf("%s", &setPhone);
                printf("Enter Salary(RM): ");
                scanf("%s", &setSalary);

                for (int i = head; i < tail; i++)
                {
                    strcpy(emp.Name[head], setName);
                    strcpy(emp.Age[head], setAge);
                    strcpy(emp.Phone[head], setPhone);
                    strcpy(emp.Salary[head], setSalary);
                    importData();
                    printf("Your data has been inserted\nEnter Y for insert another data: ");
                    head++;
                    tail++;
                    break;
                }
                scanf("%s", &back);
                if (strcmp(back, "Y") != 0)
                {
                    head = 0;
                    tail = 1;
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
                        if (strcmp(emp.Name[dataID - 1], "") != 0)
                        {
                            printf("Enter new name: ");
                            scanf("%s", setName);
                            strcpy(emp.Name[dataID - 1], setName);
                        }
                        break;
                    }
                    if (cType == 2)
                    {
                        if (strcmp(emp.Age[dataID - 1], "") != 0)
                        {
                            printf("Enter new age: ");
                            scanf("%s", setAge);
                            strcpy(emp.Age[dataID - 1], setAge);
                        }
                        break;
                    }
                    if (cType == 3)
                    {
                        if (strcmp(emp.Phone[dataID - 1], "") != 0)
                        {
                            printf("Enter new phone number: ");
                            scanf("%s", setPhone);
                            strcpy(emp.Phone[dataID - 1], setPhone);
                        }
                        break;
                    }
                    if (cType == 4)
                    {
                        if (strcmp(emp.Salary[dataID - 1], "") != 0)
                        {
                            printf("Enter new salary: ");
                            scanf("%s", setSalary);
                            strcpy(emp.Salary[dataID - 1], setSalary);
                        }
                        break;
                    }
                }
                importData();

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
                    strcpy(emp.Name[i], emp.Name[i + 1]);
                    strcpy(emp.Age[i], emp.Age[i + 1]);
                    strcpy(emp.Phone[i], emp.Phone[i + 1]);
                    strcpy(emp.Salary[i], emp.Salary[i + 1]);

                    strcpy(emp.Name[tail], "");
                    strcpy(emp.Age[tail], "");
                    strcpy(emp.Phone[tail], "");
                    strcpy(emp.Salary[tail], "");

                    if (head > 0 && tail > 1)
                    {
                        k = k - 3;
                        head--;
                        tail--;
                    }
                }
                importData();

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

void exportData()
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
        fscanf(fp, "%s", exportDataEmployee);
        strcpy(emp.Data[k], exportDataEmployee);
        k++;
    }
    fclose(fp);

    //sort data by category/column
    for (int i = 0; i < k; i++)
    {
        if (i == cName)
        {
            strcpy(emp.Name[a++], emp.Data[cName]);
            cName = cName + dataColumn;
        }
        else if (i == cAge)
        {
            strcpy(emp.Age[b++], emp.Data[cAge]);
            cAge = cAge + dataColumn;
        }
        else if (i == cPhone)
        {
            strcpy(emp.Phone[c++], emp.Data[cPhone]);
            cPhone = cPhone + dataColumn;
        }
        else if (i == cSalary)
        {
            strcpy(emp.Salary[d++], emp.Data[cSalary]);
            cSalary = cSalary + dataColumn;
        }
    }

    //Check last record
    for (int i = 0; i < k / dataColumn; i++)
    {
        if (strcmp(emp.Name[i], "") != 0)
        {
            head = i + 1;
            tail = i + 2;
            nub = i; //use for debug
        }
    }
}

void displayData()
{
    //printf("k is %d nub is = %d Head is %d Tail is %d\n", k, nub, head, tail);
    printf("ID\tName\t\tAge\t\tPhone \t\t\tSalary\n");
    printf("======================================================================\n");

    for (int i = 0; i < k; i++)
    {
        if (strcmp(emp.Name[i], "") != 0)
        {
            printf("%d\t%s\t\t%s\t\t%s\t\t\tRM %s\n", i + 1, emp.Name[i], i, emp.Age[i], emp.Phone[i], emp.Salary[i]);
        }
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

void importData()
{
    fp = fopen(filename, "w+");
    for (int j = 0; j < tail; j++)
    {
        if (strcmp(emp.Name[j], "") != 0)
        {
            fprintf(fp, "\n");
            fprintf(fp, emp.Name[j]);
            fprintf(fp, " ");
            fprintf(fp, emp.Age[j]);
            fprintf(fp, " ");
            fprintf(fp, emp.Phone[j]);
            fprintf(fp, " ");
            fprintf(fp, emp.Salary[j]);
        }
    }
    fclose(fp);
}

void Clear()
{
    for (int i = 0; i < dataLength; i++)
    {
        strcpy(emp.Name[i], "");
        strcpy(emp.Age[i], "");
        strcpy(emp.Phone[i], "");
        strcpy(emp.Salary[i], "");
    }
}