# include "struct.h"

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

