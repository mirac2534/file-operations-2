#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 30

FILE* openFileForUptade();//function is for our reading, writing, deleting or updating
FILE* addContact(FILE* ,int,char**);//function is for our adding
FILE* listContact(FILE* ,int,char**);//function is for our listing
FILE* deleteContact(FILE* ,int,char**);//function is for our deleting
FILE* exportContact(FILE* ,int,char**);//function is for our exporting
FILE* updateContacts(FILE* ,int,char **);//function is for our updating
FILE* searchContacts(FILE* ,int,char **);//function is for our searching

typedef struct
{
    int id;
    int inlinePhone;
    char name[STR_SIZE];
    char lname[STR_SIZE];
    char depertment[STR_SIZE];
}Contact;


int main(int argc,char* argv[])//argc is number of arguments and argv is a arrays of pointers that indicate the arguments themselves.
{
    if(argc==1)
    {
        printf("This program needs command line arguments..");
        return 0;
    }

    FILE* fptr=openFileForUptade();

    if(argv[1][0]=='a')//if you select a, you can add
    {
    addContact(fptr,argc,argv);
    }

    else if(argv[1][0]=='l')//if you select l, you can list
    {
    listContact(fptr,argc,argv);
    }

    else if(argv[1][0]=='e')//if you select e, you can export
    {
    exportContact(fptr,argc,argv);
    }

    else if(argv[1][0]=='u')//if you select u, you can update
    {
    updateContacts(fptr,argc,argv);
    }

    else if(argv[1][0]=='d')//if you select d, you can delete
    {
    deleteContact(fptr,argc,argv);
    }

    else if(argv[1][0]=='s')// if you select s, you can search
    {
    searchContacts(fptr,argc,argv);
    }

    else //if you select another arguments, you can not do
    {
        printf("incorretc arguments..See the homework");
    }

    fclose(fptr);

    return 0;
}

FILE* openFileForUptade()//function is for our reading, writing, deleting or updating
{
    FILE* fptr=fopen("phoneBook.dat","rb+");
    if(fptr==NULL)
    {
        printf("Cannot open the file..trying to creative it now");
        fptr=fopen("phoneBook.dat","wb+");
        if(fptr==NULL)
        {
            printf("Cannot create the file..\n");
            exit(1);
        }
    }
    return fptr;
}

FILE* addContact(FILE* fptr,int argc,char** argv)//function is for our adding
{
    Contact contact;
    if(argc!=7)//Control of the Number of Arguments
    {
        printf("incorrect arguments: adding a contact to our file require 7 arguments");
        exit(EXIT_FAILURE);
    }

    contact.id=atoi(argv[2]);//ID       atoi function converts a string of characters (char *) to an integer (int)
    contact.inlinePhone=atoi((argv[3]));//phone number
    strcpy(contact.name,argv[4]);//name
    strcpy(contact.lname,argv[5]);//last name
    strcpy(contact.depertment,argv[6]);//depertment

    if(contact.id>0)
    {
        fseek(fptr,sizeof(Contact)*(contact.id-1),SEEK_SET);
        fwrite(&contact,sizeof(Contact),1,fptr);
    }
    else
    {
        printf("contact ids should be greater than 0.. exitting");
        exit(EXIT_FAILURE);//exit(0)
    }
    return fptr;
}

FILE* listContact(FILE* fptr ,int argc ,char** argv)//function is for our listing
{
    Contact contact;
    if(argc!=2)//Control of the Number of Arguments
    {
        printf("incorrect arguments: listing needs 2 arguments");
        exit(EXIT_FAILURE);
    }

    rewind(fptr);
    printf("Your phone book\n");
    printf("...............\n");
    fread(&contact,sizeof(Contact),1,fptr);

    while(!feof(fptr))
    {
        if(contact.id>0)
        {
            printf("\nid:%d\n inlinePhone:%d\n, name:%s\n, lastName:%s\n, depertment=%s\n",contact.id,
                                                                                         contact.inlinePhone,
                                                                                         contact.name,
                                                                                         contact.lname,
                                                                                         contact.depertment);
         printf("..........\n");
        }
    fread(&contact,sizeof(Contact),1,fptr);
    }

return fptr;
}



FILE* deleteContact(FILE* fptr,int argc,char** argv)//function is for our deleting
{
    Contact contact;

    if(argc!=3)//Control of the Number of Arguments
    {
        printf("incorrect arguments: adding a contact to our file require 3 arguments");
        exit(EXIT_FAILURE);
    }
        fseek(fptr,sizeof(Contact)*(contact.id-1),SEEK_SET);
        fread(&contact,sizeof(Contact),1,fptr);


    if(contact.inlinePhone==atoi(argv[2]))
    {
        contact.depertment[0]='\0';
        contact.name[0]='\0';
        contact.lname[0]='\0';
        contact.inlinePhone=0;
        contact.id=0;

        fseek(fptr,(contact.id-1)*sizeof(Contact),SEEK_SET);
        fwrite(&contact,sizeof(Contact),1,fptr);
        printf("The contact has been deleted.");
    }else
        fprintf(stdout,"No contact has been found to delete.");

    return fptr;
}

FILE* exportContact(FILE* fptr,int argc,char** argv)
//this exportContact function is a function that reads the data in the Contact structure from one file and writes it to another file
{
    Contact contact;
    FILE* contacts;

    if((contacts=fopen("random.txt","w"))==NULL)//open another file for we can export
    {
         printf("CANNOT OPEN THE FILE");
        exit(1) ;
    }

    fprintf(contacts,"%30s%30s%8d%20s\n",
            "name",
            "lastname",
            "phone",
            "department");
    rewind(fptr);
    fread(&contact, sizeof(Contact), 1, fptr);
    while(!feof(fptr))
    {
        if(contact.inlinePhone!=0)
        {
            fprintf(contacts,
                    "%30s%30s%8d%20s\n",
                    contact.name,
                    contact.lname,
                    contact.inlinePhone,
                    contact.depertment);
        }
        fread(&contact, sizeof(Contact), 1, fptr);
    }
    fclose(contacts);

    return fptr;

}
FILE* updateContacts(FILE *fptr,int argc, char **argv)//function is for our updating
{

    Contact contact;
    rewind(fptr);
    fread(&contact,sizeof(Contact),1,fptr);

    if(argc!=3)//Control of the Number of Arguments
    {
        printf("Incorrect arguments..");
        exit(EXIT_FAILURE);
    }



         if(contact.inlinePhone=atoi(argv[2]))
    {
        printf("Old name: %s\n",contact.name);
        printf("Enter new name:");//enter new name
        scanf("%s", contact.name);

        printf("Old last name: %s\n",contact.lname);
        printf("Enter new last name:");//enter new last name
        scanf("%s", contact.lname);

        printf("Old department: %s\n",contact.depertment);
        printf("Enter new department:");//enter new depertment
        scanf("%s", contact.depertment);

        printf("Contact updated successfully.\n");
        fseek(fptr,sizeof(Contact), SEEK_SET);
        fwrite(&contact, sizeof(Contact), 1, fptr);


    }

    else
    {
        printf("Contact with phone number not found..\n");
        exit(1);
    }




return fptr;

}



FILE* searchContacts(FILE *fptr,int argc,char **argv)//function is for our searching
{
    rewind(fptr);
    Contact contact;
    if(argc!=4)//Control of the Number of Arguments
    {
        printf("Incorrect arguments..\n");
        exit(EXIT_FAILURE);

    }
    fread(&contact,sizeof(Contact),1,fptr);
    //This determines which criteria the call will be made according to (name, lastname, phone, department).
    if(argv[2][0]=='n'||argv[2][0]=='l'||argv[2][0]=='p'||argv[2][0]=='d')
    {
          while(!feof(fptr))
          {
              if(argv[2][0]=='n'&& *contact.name==argv[3][0])
              {
                printf("id: %d\ninlinePhone: %d\nname: %s\nlastname: %s\ndepartment: %s\n",contact.id,contact.inlinePhone,
                   contact.name,contact.lname,contact.depertment);
                   printf(".............\n");
              }
              else if(argv[2][0]=='l'&& *contact.lname==argv[3][0])
              {
                printf("id: %d\ninlinePhone: %d\nname: %s\nlastname: %s\ndepartment: %s\n",contact.id,contact.inlinePhone,
                   contact.name,contact.lname,contact.depertment);
                   printf(".............\n");
              }
              else if(argv[2][0]=='p'&& contact.inlinePhone == atoi(argv[3]))
              {
                printf("id: %d\ninlinePhone: %d\nname: %s\nlastname: %s\ndepartment: %s\n",contact.id,contact.inlinePhone,
                   contact.name,contact.lname,contact.depertment);
                   printf(".............\n");
              }
              else if(argv[2][0]=='d'&& *contact.depertment==argv[3][0])
              {
                printf("id: %d\ninlinePhone: %d\nname: %s\nlastname: %s\ndepartment: %s\n",contact.id,contact.inlinePhone,
                   contact.name,contact.lname,contact.depertment);
                   printf(".............\n");
              }
              fread(&contact,sizeof(Contact),1,fptr);

          }


    }


    else
    {
        printf("Incorrect arguments..\n");

    }
 return fptr;
}

