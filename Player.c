#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>

void switcher(char *);
void Welcome();
void ShowMusic(char *);
void PauseMusic();
void StopMusic();
void GetDir();

char fileNames[MAX_PATH][MAX_PATH];
char dir[MAX_PATH];
int _sign=-1;
char ispaused=0;


int main(void) {
    Welcome();

    char sign[2];
    sign[0]=0;

    char s_char[2]="s";
    char p_char[2]="p";
    char d_char[2]="d";
    char q_char[2]="q";

    while (strcmp(sign,q_char) != 0)
    {
        printf("Enter command: \n");
        scanf("%s", sign);

        if (strcmp(sign,s_char) == 0) {
            StopMusic();
            continue;
        }

        if (strcmp(sign,p_char) == 0) {
            PauseMusic();
            continue;
        }

        if (strcmp(sign,d_char) == 0) {
            GetDir();
            continue;
        }

        if (strcmp(sign,q_char) != 0) {
            switcher(sign);
            continue;
        }
    }

    return 0;
}


void switcher(char *sign) {
    if(_sign!=-1 && ispaused!=1) {
            StopMusic();
    }
    ispaused=0;
    _sign = atoi(sign);
    printf("Playing: %s\n",fileNames[_sign]);
    char command[MAX_PATH];
    sprintf(command,"play %s/%s",dir,fileNames[_sign]);
    mciSendString(command, NULL, 0, NULL);
}

void ShowMusic(char *str) {
    printf("******************************\n");
    printf("List\n");
    WIN32_FIND_DATA FindFileData;
    char path[MAX_PATH];
    sprintf(path,"%s/*",str);
    HANDLE hf = FindFirstFile(path, & FindFileData);

    int i = 1;
    if (hf == INVALID_HANDLE_VALUE) {
        puts("Path not found");
    }
    FindNextFile(hf, & FindFileData);
    while (FindNextFile(hf, & FindFileData)) {
        strcpy(fileNames[i], FindFileData.cFileName);
        printf("%i.%s\n", i, fileNames[i]);
        i++;
    }
    FindClose(hf);
    printf("******************************\n");
}

void Welcome() {
    printf("******************************\n");
    printf("* Welcome to MP3 player *\n");
    printf("* d - Choose a directory with music *\n");
    printf("* p - Pause Music *\n");
    printf("* s - Stop Music *\n");
    printf("* 1, 2... - number of song *\n");
    printf("* q - Quit *\n");
}

void PauseMusic() {
    printf("playing paused\n");
    ispaused=1;
    char command[MAX_PATH];
    sprintf(command,"pause %s/%s",dir,fileNames[_sign]);
    mciSendString(command, NULL, 0, NULL);
}

void StopMusic() {
    printf("playing stopped\n");
    ispaused=0;
    char command[MAX_PATH];
    sprintf(command,"stop %s/%s",dir,fileNames[_sign]);
    mciSendString(command, NULL, 0, NULL);
}

void GetDir() {
    printf("Type a directory with music\n");
    scanf("%s",dir);
    ShowMusic(dir);
}

