# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "struct.h"

//----------------------------------------------------------------- DECLARAÇÃO DE FUNÇÕES
int menu1(Perfil *p);
int menu2(Perfil *p, int x);
int menu3(Perfil *p, int x, int y);
int validaOpcao(); 
int validaData(int dia, int mes, int ano);
Perfil criarPerfil(int *contaPerfil); 
int listarPerfil(Perfil *p, int counter); 
void escolherPerfil(Perfil *p, int counter, int x); 
void publicarMensagem(Perfil *p, int x, int y);
int checkCaracter(char *a);
int checkString(char *a);
int calculateAge(int dia, int mes, int ano);
void backup(Perfil *p,int a);
void restore(Perfil *p);
int login(Perfil *p, int x);