#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
#define TO_DEL " \t\r\n\a\""

ssize_t myno_arg(char *ccmd);
void mypars_cmd(char *ccmd, ssize_t rr, char ***avv);
int mmy_cd(char **aarcgs);
int mmy_env(char **aarcgs);
int mmy_exit(char **aarcgs);
int mybu_path(char **avv, char **aaa);
int myenv_path(char **avv, char **aaa);
char *mylocation(char *ppath, char **avv);
void myfree_list(char ***avv);
int myis_char(char *tt);
void myerror_msg(char **aaa, char **avv);
int mypwdp(char *ccmd);
/*string function*/
int _strlen(const char *cmd);
int _strcmp(const char *cmd, const char *c);
char *_strdup(char *cmd);
char *_strcat(char *des, char *src);
char *_strcpy(char *des, char *src);
char *_strchr(const char *des, const char *src);
char *_strtok(char *cmd, const char *de);

char *_mygetenv(const char *nname);
int _myatoi(const char *ccmd);

/*creat by Alaa  */
#endif
