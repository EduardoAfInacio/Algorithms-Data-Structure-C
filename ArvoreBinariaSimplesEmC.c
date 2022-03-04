#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#include <locale.h>

struct arvoreNo { 
   struct arvoreNo *esqPtr; 
   int data; 
   struct arvoreNo *dirPtr; 
};

typedef struct arvoreNo ArvoreNo; 
typedef ArvoreNo *ArvoreNoPtr; 

void insertNo( ArvoreNoPtr *arvorePtr, int value );
void inOrdem( ArvoreNoPtr arvorePtr );
void preOrdem( ArvoreNoPtr arvorePtr );
void postOrdem( ArvoreNoPtr arvorePtr );
int altura ( ArvoreNoPtr arvorePtr );


int main( void )
{ 
   setlocale(LC_ALL,"ptb");
   int i; 
   int item; 
   ArvoreNoPtr rootPtr = NULL; 

   srand( time( NULL ) ); 
   printf( "Os números que serão inseridos na árvore são:\n" );

   for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 15;
      printf( "%3d", item );
      insertNo( &rootPtr, item );
   }

   
   printf( "\n\nTravessia preOrdem:\n" );
   preOrdem( rootPtr );

  
   printf( "\n\nTravessia inOrdem:\n" );
   inOrdem( rootPtr );

  
   printf( "\n\nTravessia postOrdem:\n" );
   postOrdem( rootPtr );
   
  
   printf( "\n\nAltura da árvore: %d\n", altura( rootPtr ));
   getchar();
   return 0; 
} 


void insertNo( ArvoreNoPtr *arvorePtr, int value )
{ 
   
   if ( *arvorePtr == NULL ) 
   {   
      *arvorePtr = (ArvoreNo*) malloc( sizeof( ArvoreNo ) );

      if ( *arvorePtr != NULL ) 
	   { 
         ( *arvorePtr )->data = value;
         ( *arvorePtr )->esqPtr = NULL;
         ( *arvorePtr )->dirPtr = NULL;
       } 
      else 
	  {
         printf( "%d Não inserido. Não há memória disponível.\n", value );
      } 
   } 
   else 
   { 
      
      if ( value < ( *arvorePtr )->data ) 
	   {
           insertNo( &( ( *arvorePtr )->esqPtr ), value );
       } 

      
      else if ( value > ( *arvorePtr )->data ) 
	   {
              insertNo( &( ( *arvorePtr )->dirPtr ), value );
       } 
          else 
		  { 
             printf( "dup" );
          } 
   } 
} 


void inOrdem( ArvoreNoPtr arvorePtr )
 { 
   
   if ( arvorePtr != NULL ) 
   { 
      inOrdem( arvorePtr->esqPtr );
      printf( "%3d", arvorePtr->data );
      inOrdem( arvorePtr->dirPtr );
   }
 } 


void preOrdem( ArvoreNoPtr arvorePtr )
{ 
   
   if ( arvorePtr != NULL ) 
    { 
       printf( "%3d", arvorePtr->data );
       preOrdem( arvorePtr->esqPtr );
       preOrdem( arvorePtr->dirPtr );
    } 
} 


void postOrdem( ArvoreNoPtr arvorePtr )
 { 
   
   if ( arvorePtr != NULL ) 
    { 
       postOrdem( arvorePtr->esqPtr );
       postOrdem( arvorePtr->dirPtr );
       printf( "%3d", arvorePtr->data );
    } 
 } 


int altura (ArvoreNoPtr arvorePtr ) 
 {
   if ( arvorePtr == NULL) 
        return -1; 
   else 
     {
        int he = altura (arvorePtr->esqPtr);
        int hd = altura (arvorePtr->dirPtr);
        if (he < hd) 
		     return hd + 1;
        else 
		     return he + 1;
   }
 }

