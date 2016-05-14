#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char course[4][20] = {"Software", "Math", "OS", ""}; //3 course name
char code[4][8]= {"CPS406","MTH304","CPS590"}; //3 course code
char project[4][20]; //3 project name, limit only 1 project per course
char pinfo[4][200]; //3 upload project info
char group[2][100]; //2 groups, 4 students in group max

char submissions[4][200];
char evaluations[4][200];

char msg[6][100] = {"","hello world","","goodbye"};
char slapstoall[100]; //slap statements to all
char slapstoins[100]; //slap statements to instructor

char students[4][20] = {"Andy", "James", "John"}; //3 students
char instructors[2][20]= {"instr"}; //1 instructor user name
char admins[2][20]= {"admin"}; //1 admin user name
char users[6][2][6] = { "andy", "pass",
                        "james", "gooo",
                        "john", "login",
                        "instr", "ipass",
                        "admin", "apass" }; //5 username +  5 password, 2 fields, 5 max characters
//1 instructor
//1 admin
//3 students
//1 for new user

char name[5];
char pass[5];

void createGUI()
{

    //student & instructor
    printf("Select an option by entering the specified number.\n");
    printf("View Messages: Press 1\n");
    printf("Create Message: Press 2\n");
    printf("View Courses: Press 3\n");
    printf("Logout: Press 4\n");
    //instructor
    int b = 0;
    for(b = 0; b < 2; b++)
    {
        if(strcmp(name,instructors[b])==0)
        {
            printf("Create new project: Press 5\n");
        }
        //admin
        if(strcmp(name,admins[b]) == 0)
        {
            printf("Create a course: Press 6\n");
            printf("Create SLAPs (Admin to ALl): Press 7\n");
            printf("Create SLAPs (Admin to Instructor): Press 8\n");
            printf("Reset Password: Press 9\n");
            printf("Change Password: Press 10\n");
        }
    }

}

void login()
{
    int a = 0;
    int accept = 0;
    int attempts = 0;
    int cancel = 0;
    int vname = 0; //valid username
    int vpass = 0; //valid password
    while(accept == 0)
    {
        printf("Enter Username: ");
        scanf("%s",&name);
        //gets(name);
        printf("Enter Password: ");
        scanf("%s", &pass);
        //gets(pass);
        for(a = 0; a < 5; a++)
        {
            if(strcmp(users[a][0],name) == 0)
            {
                vname = 1;
            }
            if(strcmp(users[a][1],pass) == 0)
            {
                vpass = 1;
            }
        }
        if(vname == 0 && vpass == 1)
        {
            printf("Invalid Username!\n");
        }
        else if(vpass == 0 && vname == 1)
        {
            printf("Invalid Password!\n");
        }
        else if(vname == 0 && vpass == 0)
        {
            printf("Invalid Username and Password!\n");
        }
        else
        {
            accept = 1;
            printf("\n");
        }
        attempts = attempts+1;
        if(attempts == 10)
        {
            accept = 1;
            printf("Unable to login!\n");
            exit(0);
        }
        if(attempts < 10 && accept == 0)
        {
            printf("Press 1 to Try Again or Press 2 to Cancel Login!\n");
            printf("Your Selection: ");
            scanf("%d", &cancel);
            printf("\n");
            if(cancel == 2)
            {
                accept = 1;
                exit(0);
            }
            else
                accept = 0;
        }
	   system("cls");
    }
}

int main(int argc, char *argv[])
{
    FILE *file;
    char *f;
    int i = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;
    int temp = 0;
    int choice = 0;
    int invalid = 0;
    int instructor = 0;
    int admin = 0;
    char mess[100];
    int stop = 0;
    int select = 0;

	system("cls");
    login();
    printf("Welcome to SLAP!\n");

    while(invalid == 0)
    {
        createGUI();
        printf("\n");
        printf("Your Selection: ");
        scanf("%d",&choice);
        printf("\n");
        if(choice == 1)
        {
            printf("Message: \n");
            for(i = 0; i < 5; i++)
            {
                if(strcmp(users[i][0],name) == 0)
                {
                    if(strcmp(msg[i],"")== 0)
                        printf("You have no message.\n");
                    else
                        printf("%s\n",msg[i]);
                }
            }
        }
        else if(choice == 2) //create message
        {
            for(i = 0; i < 5; i++)
            {
                if(strcmp(users[i][0],name) == 0)
                    temp = i;
            }
            printf("Type your message: ");
            scanf("%s", &mess);
            int v = 0;
            int n = 0;
            while(n == 0)
            {
                printf("Edit message: Press 1\n");
                printf("Cancel message: Press 2\n");
                printf("Select contacts: Press 3\n");
                printf("Your selection: ");
                scanf("%d", &v);
                printf("\n");
                if(v == 1)
                {
                    printf("Type your message: ");
                    scanf("%s", &mess);

                }
                else if(v == 2)
                {
                    n = 1;
                }
                else
                {
                    printf("Select contact by specified number:\n");
                    while(stop == 0)
                    {
                        for(x = 0; x < 6; x++)
                        {
                            if(strcmp(users[x][0], "")!= 0)
                            {
                                if(strcmp(users[x][0],name)!= 0)
                                printf("%s :Press %d\n", users[x][0], x);
                            }
                        }
                        printf("Your Selection: ");
                        scanf("%d", &select);
                        strcpy(msg[select],mess);
                        printf("Press 0 to select more contacts or Press 1 to continue to menu! \n");
                        printf("Your Selection: ");
                        scanf("%d", &stop);
                        printf("\n");
                    }
                    n = 1;
                }
                system("cls");
            }
            system("cls");
        }
        else if(choice == 3)
        //students
        //view courses
        //view project
        //submit
        //instructor
        //select project to assign groups
        //or upload instructions or view instructions
        //or view groups or edit project
        //or view submissions
        //or submit evaluations
        {
            int stud = 0;
            int p = 0;
            int s = 0;
            int g = 0;
            for(w = 0; w < 5; w++)
            {
                if(strcmp(instructors[w],name)== 0)
                {
                    stud = 1;
                }
            }
            for(w = 0; w < 5; w++) //print courses
            {
                if(strcmp(course[w],"")!= 0)
                {
                    printf("%s , %s : Press %d\n", course[w], code[w], w);
                }
            }
            printf("\n");
            if(stud == 0) //student
            {
                printf("View project: Press 1\n");
                printf("Submit assignment: Press 2\n");
                printf("Back to menu: Press 3\n");
                printf("Your selection: ");
                scanf("%d",&g);
                if(g == 1)
                {
                    printf("Select a course to view project by selecting the specified number.\n");
                    printf("Your selection: ");
                    scanf("%d", &p);
                    if(strcmp(project[p],"") != 0)
                        printf("Project for this course: %s \n", project[p]);
                    else
                        printf("No project in this course. \n");
                }
                else if(g == 2)
                {
                    for(w = 0; w < 5; w++) //print courses
                    {
                        if(strcmp(course[w],"")!= 0)
                        {
                            printf("%s , %s : Press %d\n", course[w], code[w], w);
                        }
                    }
                    printf("Select a course to submit assignment by selecting the specified number.\n");
                    printf("Your selection: ");
                    scanf("%d", &p);
                    printf("Submit your file: ");
                    scanf("%s", f);
                    file = fopen(f,"r");
                    while(!feof(file))
                    {
                        fscanf(file,"%s", &submissions[p]);
                    }
                    fclose(file);
                    printf("Your assignment has been submitted!\n");
                }
                else
                {
                    printf("\n");
                }
            }
            else
            {
            //select project to assign groups
            //or upload instructions or view instructions
            //or view groups or edit project
            //or view submissions
            //or submit evaluations
                int o = 0;
                int u = 0;
                int r = 0;
                int groups = 0;
                printf("View project: Press 1\n");
                printf("View submissions: Press 2\n");
                printf("Back to menu: Press 3\n");
                printf("Your selection: ");
                scanf("%d", &o);
                if(o == 1)
                {
                    printf("Select a course to view project by selecting the specified number.\n");
                    printf("Your selection: ");
                    scanf("%d", &p);
                    printf("Project for this course: %s \n", project[p]);
                    printf("\n");
                    printf("Assign Groups: Press 1\n");
                    printf("Upload Instructions: Press 2\n");
                    printf("View Instructions: Press 3\n");
                    printf("Submit Evalutaions: Press 4\n");
                    printf("Back to menu: Press 5\n");
                    printf("Your selection: ");
                    scanf("%d", &r);
                    if(r == 1)
                    {
                        groups = groups+1;
                        printf("Enter a group members' names: ");
                        scanf("%s", &group[groups-1]);
                    }
                    else if(r == 2)
                    {
                        printf("Select a course by selecting the specified number.\n");
                        printf("Your selection: ");
                        scanf("%d", &p);
                        printf("Upload instructions file: ");
                        scanf("%s", f);
                        file = fopen(f,"r");
                        while(!feof(file))
                        {
                            fscanf(file,"%s", &pinfo[p]);
                        }
                        fclose(file);
                        printf("Upload sucessful\n");
                    }
                }
                else if(r == 3)
                {
                    for(w = 0; w < 5; w++) //print courses
                    {
                        if(strcmp(course[w],"")!= 0)
                        {
                            printf("%s , %s : Press %d\n", course[w], code[w], w);
                        }
                    }
                    printf("Select a course to view project by selecting the specified number.\n");
                    printf("Your selection: ");
                    scanf("%d", &p);
                    if(strcmp(pinfo[p],"") == 0) //if not instructions
                        printf("No instructions available.\n");
                    else
                        printf("%s", pinfo[p]);
                        printf("\n");
                }
                else if(r == 4)
                {
                    int q = 0;
                    int l = 0;
                    printf("Select the name of student by the specified number.\n");
                    for(q = 0; q < 4; q++)
                    {
                        if(strcmp(students[q],"")!= 0)
                            printf("Name:%s Press %d", students[q], q);
                    }
                    printf("Your selection: ");
                    scanf("%d", &l);
                    printf("Enter evalutation: ");
                    scanf("%s", &evaluations[l]);
                    printf("Evalutaion submitted.\n");
                }
                else if(o == 2)
                {
                    int p = 0;
                    printf("Submissions: \n");
                    for(p = 0; p < 4; p++)
                    {
                        if(strcmp(submissions[p],"")!=0)
                        printf("Submission %d: %s \n", p, submissions[p]);
                    }
                }
                else
                    printf("\n");
            }
        }
        else if(choice == 4) //logout
        {
            int out = 0;
            printf("Are you sure you want to logout?\n");
            printf("Press 1 to LOGOUT or Press 2 to CANCEL\n");
            printf("Your Selection: ");
            scanf("%d", &out);
            if(out == 1)
                invalid = 1;
            else
            {
                printf("Logout cancelled.\n");
                printf("\n");
            }
        }
        else if(choice == 5) //create new project
        {
            int s = 0;
            printf("Course Name, Course Code: Choice Number\n");
            for(y = 0; y < 4; y++) //list courses
            {
                if(strcmp(course[y],"")!= 0)
                {
                    printf("%s , %s : Press %d\n", course[y], code[y], y);
                }
            }
            printf("Select a course by the specified number!\n");
            printf("Your selection: ");
            scanf("%d",&s);
            printf("Enter new project name: ");
            scanf("%s", &project[s]);
            printf("%s project is created for %s course!\n", project[s], course[s]);
        }
        else if(choice == 6) //create course
        {
            printf("Enter new course name: ");
            for(z = 0; z < 4; z++)
            {
                if(strcmp(course[z],"")== 0)
                {
                    scanf("%s",&course[z]);
                    printf("Enter new course code: ");
                    scanf("%s",&code[z]);
                    printf("A new course: %s is created with course code: %s \n", course[z], code[z]);
                }
            }
        }
        else if(choice == 7) //create SLAPs admin to all
        {
            printf("Enter your SLAP statement: ");
            scanf("%s", &slapstoall);
            printf("Your SLAP statement has been sent! \n");
        }
        else if(choice == 8) //create SLAPs admin to instructor
        {
            printf("Enter your SLAP statement: ");
            scanf("%s", &slapstoins);
            printf("Your SLAP statement has been sent! \n");
        }
        else if(choice == 9) //reset
        {
            int h = 0;
            char un[6];
            printf("Enter the Username of person to reseting password: ");
            scanf("%s",&un);
            for(h = 0; h < 6; h++)
            {
                if(strcmp(users[h][0],un)==0)
                    strcpy(users[h][1],"dftpwd");
            }
        }
        else if(choice == 10)
        {
            int h = 0;
            char un[6];
            char pw[6];
            printf("Enter the Username of person to reseting password: ");
            scanf("%s",&un);
            for(h = 0; h < 6; h++)
            {
                if(strcmp(users[h][0],un)==0)
                {
                    printf("Enter the new password: ");
                    scanf("%s",&pw);
                    strcpy(users[h][1],pw);
                }
            }
        }
        else
        {
            printf("Invalid Selection! Please select again.\n");
            createGUI();
        }
        Sleep(1500);
        system("cls");
    }
    return 0;
}

