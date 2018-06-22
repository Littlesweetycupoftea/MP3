#include <stdio.h> 
#include <windows.h> 
#include <io.h> 
#include <string.h> 
#include <stdlib.h> 

void switcher(int sign); 
void Welcome(); 
void ShowMusic(); 
void StopMusic(); 

int main (void) { 
Welcome(); 
ShowMusic(); 
char sign; 
mkdir("YourMusic"); 


while(sign != 'Q') { 
printf("Enter command: \n"); 
scanf("%s", &sign); 
if(sign == 'L') { 
ShowMusic(); 
continue; 
} 
if(sign == 'S') { 
StopMusic(); 
continue; 
} 
switcher(sign); 
} 

return 0; 
} 


void switcher(int sign) { 
switch (sign) { 
case '1': 
printf("Playing: Billy Idol - Rebel Yell\n"); 
mciSendString("play YourMusic/Billy_Idol_-_Rebel_Yell.mp3", NULL, 0, NULL); 
break; 

case '2': 
printf("Playing: Brahms Johannes - Hungarian dance 5\n"); 
mciSendString("play YourMusic/Brahms_Johannes_-_Hungarian_dance_5.mp3", NULL, 0, NULL); 
break; 

case '3': 
printf("Playing: Nauchno-Technicheskiy rap - C\n"); 
mciSendString("play YourMusic/Nauchno-Technicheskiy_rap_-_C.mp3", NULL, 0, NULL); 
break; 

case '4': 
printf("Playing: RSAC - Tak sebe obmen\n"); 
mciSendString("play YourMusic/RSAC_-_Tak_sebe_obmen.mp3", NULL, 0, NULL); 
break; 

case '5': 
printf("Playing: Simple Plan - Astronaut\n"); 
mciSendString("play YourMusic/Simple_Plan_-_Astronaut.mp3", NULL, 0, NULL); 
break; 

case '6': 
printf("Playing: The Offspring - Dirty Magic\n"); 
mciSendString("play YourMusic/The_Offspring_-_Dirty_Magic.mp3", NULL, 0, NULL); 
break; 

default: 
break; 
} 
} 

void ShowMusic() { 
printf("******************************\n"); 
printf("List\n"); 
WIN32_FIND_DATA FindFileData; 
HANDLE hf = FindFirstFile("YourMusic/*", &FindFileData); 
char fileNames[200][MAX_PATH]; 
int i = 1; 
if (hf==INVALID_HANDLE_VALUE){ 
puts("Path not found"); 
} 
FindNextFile(hf,&FindFileData); 
while (FindNextFile(hf,&FindFileData)) { 
strcpy(fileNames[i], FindFileData.cFileName); 
printf("%i.%s\n",i ,fileNames[i]); 
i++; 
} 
FindClose(hf); 
printf("******************************\n"); 
} 

void Welcome() { 
printf("******************************\n"); 
printf("* Welcome to MP3 player *\n"); 
printf("* L - Show Music *\n"); 
printf("* S - Stop Music *\n"); 
printf("* 1, 2... - number of song *\n"); 
printf("* Q - Quit *\n"); 
} 

void StopMusic() { 
printf("playing paused\n"); 
mciSendString("pause YourMusic/Nauchno-Technicheskiy_rap_-_C.mp3", NULL, 0, NULL); 
mciSendString("pause YourMusic/Billy_Idol_-_Rebel_Yell.mp3", NULL, 0, NULL); 
mciSendString("pause YourMusic/RSAC_-_Tak_sebe_obmen.mp3", NULL, 0, NULL); 
mciSendString("pause YourMusic/The_Offspring_-_Dirty_Magic.mp3", NULL, 0, NULL); 
mciSendString("pause YourMusic/Brahms_Johannes_-_Hungarian_dance_5.mp3", NULL, 0, NULL); 
mciSendString("pause YourMusic/Simple_Plan_-_Astronaut.mp3", NULL, 0, NULL); 
}
