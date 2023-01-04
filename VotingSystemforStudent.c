//Disclaimer
//Every Funtion is Available now task is think about features and design ur Project
    // If any query or if you want to contact with me.
    //Email: shahporanshanto23@gmail.com
    //Thank You;)
    
#include<stdio.h>
FILE *Student;
FILE *Authority;
FILE *Vote;
FILE *Publish;

//Structure For Student
typedef struct infoStudent
{
    char name[20];
    char id[20];
    char depertment[20];
    char phone[20];
    char age[20];
    char gender[20];
    char username[20];
    char pass[20];
} infoS;

//Structure for Cadidate
typedef struct Candidate
{
    char name[20];
    char id[20];
    char depertment[20];
    int vote;
} infoC;
void voteYourCadidate();

//Cadidate Selector Function
void SelectCandidate()
{
    Authority = fopen("Candidate.txt","w");
    if(Authority==NULL)
    {
        printf("File isn't Created.");
    }
    else
    {
        infoC CandidateInfo[3];
        printf("Provide Three Selected Candidate's Information\n\n");
        for(int i=0; i<3; ++i)
        {
            printf("Candidate %d:\n",i+1);
            printf("Name: ");
            scanf("%s",&CandidateInfo[i].name);
            printf("Student Id: ");
            scanf("%s",&CandidateInfo[i].id);
            printf("Depertment: ");
            scanf("%s",&CandidateInfo[i].depertment);
            printf("\n");
        }
        for(int i=0; i<3; ++i)
            fprintf(Authority,"\n%s\n%s\n%s",CandidateInfo[i].name,CandidateInfo[i].id,CandidateInfo[i].depertment);

        Vote = fopen("CountingVote.txt","w");
        if(Vote==NULL)
        {
            printf("File isn't Created");
        }
        else
        {
            for(int i=0; i<3; ++i)
                CandidateInfo[i].vote=0;

            for(int i=0; i<3; ++i)
                fprintf(Vote,"\n%d",CandidateInfo[i].vote);
        }

        printf("***Updated Successfully***");

    }
}

//Display Fucntion (Info Cadidate)
void DisplayCandidate()
{
    infoC CandidateInfo[3];
    Authority = fopen("Candidate.txt","r");
    for(int i=0; i<3; ++i)
        fscanf(Authority,"\n%s\n%s\n%s",&CandidateInfo[i].name,&CandidateInfo[i].id,&CandidateInfo[i].depertment);
    printf("***Cadidate Information***\n");
    for(int i=0; i<3; ++i)
    {
        printf("Candidate %d:\n",i+1);
        printf("Name: %s\n",CandidateInfo[i].name);
        printf("Student Id: %s\n",CandidateInfo[i].id);
        printf("Depertment: %s\n",CandidateInfo[i].depertment);
        printf("\n");
    }

    ///voteYourCadidate()

}

/// Vote Cadidate
void voteYourCadidate()
{
    int option;
    printf("\nVote Your Cadidate: ");
    scanf("%d",&option);
    infoC CandidateInfo[3];
    Vote = fopen("CountingVote.txt","r");
    for(int i=0; i<3; ++i)
        fscanf(Vote,"\n%d",&CandidateInfo[i].vote);

    if(option==1)
    {
        CandidateInfo[0].vote+=1;
    }
    else if(option==2)
    {
        CandidateInfo[1].vote+=1;
    }
    else
    {
        CandidateInfo[2].vote+=1;
    }

    Vote = fopen("CountingVote.txt","w");
    if(Vote==NULL)
    {
        printf("File isn't Created");
    }
    else
    {
        for(int i=0; i<3; ++i)
            fprintf(Vote,"\n%d",CandidateInfo[i].vote);
    }

    printf("***Thank You***");

}

//Election Result
void ElectionResult()
{

    Publish = fopen("Publish.txt","r");
    int yes=100;
    fscanf(Publish,"\n%d",&yes);

    if(yes==1)
    {
        infoC CandidateInfo[3];
        Vote = fopen("CountingVote.txt","r");
        for(int i=0; i<3; ++i)
            fscanf(Vote,"\n%d",&CandidateInfo[i].vote);
        int winner=0;
        int maxVote=0;
        for(int i=0; i<3; ++i)
        {
            if(maxVote<CandidateInfo[i].vote)
            {
                maxVote=CandidateInfo[i].vote;
                winner=i;
            }
        }
        Authority = fopen("Candidate.txt","r");
        for(int i=0; i<3; ++i)
            fscanf(Authority,"\n%s\n%s\n%s",&CandidateInfo[i].name,&CandidateInfo[i].id,&CandidateInfo[i].depertment);

        printf("Our Winner: %s", CandidateInfo[winner].name);
        printf("\nID: %s",CandidateInfo[winner].id);
        printf("\nDepertment: %s", CandidateInfo[winner].depertment);
    }
    else
    {

        printf("Result is not Publish Yet");
    }

}

//Publish Result(power of authority)
void publishResult()
{
    Publish = fopen("Publish.txt","w");
    if(Publish==NULL)
    {
        printf("File isn't Created");
    }
    else
    {
        char yes[20];
        printf("Do you want to publish result? \n Yes or No: ");
        scanf("%s",&yes);
        int ok=1;
            int no=0;
        if(strcmp(yes,"yes")==0)
        {
            fprintf(Publish,"\n%d",ok);
            printf("Result Published");
        }
        else
        {
            fprintf(Publish,"\n%d",no);
            printf("Election Result Postpond");
        }


    }
}


//SignUp for Student
void SignUp()
{
    Student = fopen("Student.txt","a");
    if(Student==NULL)
    {
        printf("File isn't Created.");
    }
    else
    {
        infoS Ex[2];

        printf("Please Provide Your Information Below\n\n");
        printf("Name: ");
        scanf("%s",&Ex[0].name);
        printf("Student Id: ");
        scanf("%s",&Ex[0].id);
        printf("Depertment: ");
        scanf("%s",&Ex[0].depertment);
        printf("Phone Number: ");
        scanf("%s",&Ex[0].phone);
        printf("Age: ");
        scanf("%s",&Ex[0].age);
        printf("Gender: ");
        scanf("%s",&Ex[0].gender);
        printf("User Name: ");
        scanf("%s",&Ex[0].username);
        printf("Password: ");
        scanf("%s",&Ex[0].pass);
        fprintf(Student,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",Ex[0].name,Ex[0].id,Ex[0].depertment,Ex[0].phone,Ex[0].age,Ex[0].gender,Ex[0].username,Ex[0].pass);

    }
    printf("**Signed Up Successfully**");
}

//Log in User(Student)
void LogInStudent()
{
    infoS Ex[1000];
     Student = fopen("Student.txt","r");
    fscanf(Student,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",&Ex[0].name,&Ex[0].id,&Ex[0].depertment,&Ex[0].phone,&Ex[0].age,&Ex[0].gender,&Ex[0].username,&Ex[0].pass);
    char username[20];
    char password[20];
    printf("\nUsername: ");
    scanf("%s",&username);
    printf("Password: ");
    scanf("%s",&password);

    for(int i=0; i<500; ++i)
    {
        if(strcmp(username,Ex[i].username)==0 && strcmp(password,Ex[i].pass)==0)
        {
            DisplayCandidate();
            printf("YES");
            break;
        }

    }
}

//Log in Authority
void LogInAuthority()
{
    char username[20];
    char password[20];
    printf("\n\nUsername: ");
    scanf("%s",&username);
    printf("Password: ");
    scanf("%s",&password);
    if(strcmp(username,"Admin")==0 && strcmp(password,"7193x")==0)
    {
       // printf("YES");
       SelectCandidate();
       publishResult();
        ///Select Candidate
        ///Publish

    }
}

int main()
{

    //Every Funtion is Available now task is think about features and design ur Project
    // If any query or if you want to contact with me.
    //Email: shahporanshanto23@gmail.com
    //Thank You;)
    int option;

 //LogInAuthority();
    LogInStudent();
     //SelectCandidate();
     //DisplayCandidate();
    //SignUp();
   // voteYourCadidate();
    //publishResult();
    //ElectionResult();

    return 0;
}
