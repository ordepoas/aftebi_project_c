# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

//----------------------------------------------------------------- DECLARAÇÃO DE CONSTANTES
# define MAX_USERS 10 //numero maximo de perfis
# define MAX_LENGTH_200 200 //tamanha maximo das mensagens do mural (incluido na estrutura Perfil)
# define MAX_LENGTH_50 50 //tamanho maximo do campo email (estrutura Perfil)
# define MAX_LENGTH_25 25 //tamanho maximo dos campos nome e sobrenome (estrutura Perfil)
# define MAX_MSG 50 //tamanho maximo de mensagens permitidas por perfil

int contaPerfil = 0; //contador de perfis criados
int contarMensagens [MAX_USERS] = {0};

//----------------------------------------------------------------- DECLARAÇÃO DE FUNÇÕES
int menu1(Perfil *p);
int menu2(Perfil *p);
int menu3(Perfil *p, int x, int contarMensagens[]);
int validaOpcao(); 
int validaData(int dia, int mes, int ano);
Perfil criarPerfil(int *contaPerfil); 
void listarPerfil(Perfil *p, int counter); 
void escolherPerfil(Perfil *p, int counter, int contarMensagens[]); 
void publicarMensagem(Perfil *p, int x, int contarMensagens[]); 

