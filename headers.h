# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "struct.h"

//----------------------------------------------------------------- DECLARAÇÃO DE FUNÇÕES
int menu1(Perfil *p);
int menu2(Perfil *p);
int menu3(Perfil *p, int x);
int validaOpcao(); 
int validaData(int dia, int mes, int ano);
Perfil criarPerfil(int *contaPerfil); 
void listarPerfil(Perfil *p, int counter); 
void escolherPerfil(Perfil *p, int counter); 
void publicarMensagem(Perfil *p, int x);
int checkCaracter(char *a);
int checkString(char *a);
int calculateAge(int dia, int mes, int ano);
void  backup(Perfil *p,int a);
void restore(Perfil *p, int a);