	//			||	Funcion Entrada de Usuario	||

/*
	------------------------------------------------------------------------------------------
	Descripción del archivo.
	
	Uso de variables:
	
		Las variables se nombran de la siguiente manera: 
				
				(Tipo-de-variable)(Tipo-dato)_(palabra_en_funcion_del_uso_de_la_variable)  
	
				Global  = g		int   = i	* Al momento de declararla se requiere hacer una	
				funcion = f 	float = f		descripción de su uso dentro del programa.
								char  = c
				
		Al momento de declararla, por ejemplo:
					
						int fi_contadorUsuario 	// Contador del número que ingresa el usuario 
						int fi_contadorPc;	// Contador del número génerado por el pc.
				
		* Las variables que tienen la finalidad de actuar cómo contadores dentro de un 
		ciclo, son i, j, k y l. (En ese orden conforme se este trabajando).
			
	Uso de funciónes:
	
		Las funciónes se nombran de acuerdo con el siguiente criterio:
		
			(Tipo-de-funcion)_(descripción_Cada_palabra_inicil_con_mayuscula)
			
			void	= v			* Al momento de declararla se requiere hacer una
			int		= i				descripción de su uso dentro del programa.
				
		Al momento de declararla, por ejemplo:
		
						i_SumaDatos , v_RestaResultados , i_ImprimirDatos 	
	
	------------------------------------------------------------------------------------------
*/

/*		1- Librerias		*///--------------------------------------------------------------

	#include <stdio.h>
	#include <string.h>
	#include <float.h>
	
/*--	1- Librerias   	  --*/
							
/*		2- Manejo de variables Globales		*///----------------------------------------------

	union entradaDeUsuario
	{
		//	-------------------------------------------------------------------------------------------------------------
		char c_caracter;							//	|	   ( 0 ) 	   | 	char				 |		  1			|	
		unsigned char unc_caracter ;				//	|	   ( 1 )	   |	unsigned char		 |		  1			|
		short int shi_num;							//	|	   ( 2 )	   |	short int			 |		  2			|
		unsigned short int unshi_num;				//	|	   ( 3 )	   |	unsigned short int	 |		  2			|
		int i_num;									//	|	   ( 4 )	   |	int					 |		  4			|
		unsigned int uni_num;						//	|	   ( 5 )	   |	unsigned int		 |		  4			|
		long int loi_num;							//	|	   ( 6 )	   |	long int			 |		  4			|
		unsigned long int unloi_num;				//	|	   ( 7 )	   |	unsigned long int	 |		  4			|
		char array_fifty[50];						//	|	   ( 8 )	   |	char array[50]		 |	*	  50	*	|	
		float f_num;								//  |	   ( 9 )	   |	float 			 	 |		  4			|
		//	-------------------------------------------------------------------------------------------------------------							
	} ;

/*--	2- Manejo de variables Glovales   	  --*/

/*		3- Prototipado de funciones		*///--------------------------------------------------
	
	union entradaDeUsuario eDU_AnalizarEntrada( unsigned short sh_configuracion , unsigned short sh_numeroDeVeces );
	
/*--	3- Prototipado de funciones 	  --*/

/*		4- Función principal (Descripción de uso)	*///--------------------------------------
	void main()
	{
		
		union entradaDeUsuario DatosDeEntrada, a, b;
		unsigned char usc_configuracion, usc_oportunidades;
		
		printf("\n\t%c Ingresa el tipo de configuraci%cn: " , 219, 162);
		a = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3 );
		printf("\n\t%c Ingresa el n%cmero de oportunidades: ", 219, 163);
		b = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3 );
		printf("\n\t------------------------------------------------\n\tIngresa el dato: ", 163);
		
		DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ a.unc_caracter , /*Intentos*/ b.unc_caracter);
		
		printf("\n\t%c%c VALOR INGRESADO %f %c%c\n\n" , 219, 219, DatosDeEntrada.f_num , 219, 219 );
		
		system ("pause");
	}
/*--	4- Función principal 	--*/

/*		5- Manejo de funciones		*///------------------------------------------------------
	
	union entradaDeUsuario eDU_AnalizarEntrada( unsigned short sh_configuracion , unsigned short sh_numeroDeVeces )
	{
		/*
			Configuración de la función de entrada:
			
			| Valor de entrada | 	Valor que devuelve	 |	Tamaño 	(bytes)	|
			-----------------------------------------------------------------
			|	   ( 0 ) 	   | 	char				 |		  1			|	
			|	   ( 1 )	   |	unsigned char		 |		  1			|
			|	   ( 2 )	   |	short int			 |		  2			|
			|	   ( 3 )	   |	unsigned short int	 |		  2			|
			|	   ( 4 )	   |	int					 |		  4			|
			|	   ( 5 )	   |	unsigned int		 |		  4			|
			|	   ( 6 )	   |	long int			 |		  4			|
			|	   ( 7 )	   |	unsigned long int	 |		  4			|
			|	   ( 8 )	   |	char array[50]		 |	*	  50	*	|	
			|	   ( 9 )	   |	float 			 	 |		  4			|														
			-----------------------------------------------------------------						
		
		*/
		short i, sh_parametroDeSalida = 0, sh_numeroDeVecesIngresadas = 0, s_cortaFuego;
		union entradaDeUsuario AnalisisDeEntrada;
		char c_textoDePaso[20];
		int paso, dio, k;
		float f_ppaso;
		char texa[11], texa2[11];
		long int loi_sizefloat;
		
		do{
		
		// Se resive el valor de entrada del usuario como texto:		
			fgets( c_textoDePaso, 20, stdin );
			fflush(stdin);
			
				switch( sh_configuracion )
				{
					case 0  : // | 	char				 |-----------------------------------------
						// Se analizá que el valor sea el correcto.
						
						if( (int)c_textoDePaso[1] > 33  )
						{
							printf("\n\t%c Se ha ingresado m%cs de un c%cracter.", 219, 160, 160);
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 s%clo c%cracter (Tiene %i intentos) : " , 219, 162, 160, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 s%clo c%cracter (Tiene %i intento) : " , 219, 162, 160, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.c_caracter = 'X';
							break;	
						}
						else if ( (int)c_textoDePaso[0] > 32 )
						{
							AnalisisDeEntrada.c_caracter = c_textoDePaso[0];
							// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						}else printf("\n\t%c Valor no valido", 219);
						
						AnalisisDeEntrada.c_caracter = 'X';						
						break;
						
					case 1  : // |	unsigned char		 | -----------------------------------------
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						int i_paso = atoi(c_textoDePaso);
						unsigned char unc_paso = atoi(c_textoDePaso);
						
						for ( i = 0 ; i < 3 ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							//printf("El paso es de %i", paso);

							if ( paso > 57 || paso < 48 && paso > 10 )
							{
								printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
								s_cortaFuego++;
								break;
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else 	if ( i_paso > 255 || i_paso < 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unc_caracter = unc_paso;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						}
						break;	
				
					case 2  : // |	short int			 |-----------------------------------------
						//  RANGO -32768 a 32767 
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						long int loi_paso = atoi(c_textoDePaso);
						short int si_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 10 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 10 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.shi_num = 0;
							break;	
						} else 	if ( loi_paso < -32768 || loi_paso > 32767 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.shi_num = si_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.shi_num = 0;
							break;	
						}
						break;
						
					case 3  : // |	unsigned short int	 |-----------------------------------------
							  // 0 a 65535
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						unsigned short int unshi_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						} else 	if ( loi_paso < 0 || loi_paso > 65535 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unshi_num = unshi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						}
						break;
						
					case 4  : // |	int					 |-----------------------------------------	
						// -32768 a 32767
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						i_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						} else 	if ( loi_paso < -32768 || loi_paso > 32767 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.i_num = i_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						}
						break;

					case 5  :  //|	unsigned int		 |-----------------------------------------
							   //|  0 a 65535			 |
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						unsigned int uni_paso = atoi(c_textoDePaso);
						short j;
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						} else 	if ( loi_paso < 0 || loi_paso > 65535 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.uni_num = uni_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						}
						break;
						
					case 6  : // |	long int			 |-----------------------------------------
						      // | -2147483648 a 2147483647
						      //   12345678901   1234567890
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						double d_paso = atoi(c_textoDePaso);
						loi_paso = atoi(c_textoDePaso);
						unsigned char uc_j = 0 , uc_i = 0 ;
						
						for ( i = 0 ; i < 11 /*|| uc_j == 1*/ ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							uc_i++;
						}
						
												
						
						if ( c_textoDePaso[0] == '-' )
						{
							uc_i = 0;
							
							char ca_paso[3];
							for ( i = 1 ;  i < 4 ; i++ ) ca_paso[i-1] = c_textoDePaso[i];
							short int up = atoi(ca_paso);
							
							if ( (int)c_textoDePaso[10] > 47 && (int)c_textoDePaso[10] < 58 )
							{
								if ( up > 214 )uc_i++; 
								else if ( up == 214 )
								{
									j = 0 ;
									for ( i = 4 ;  i < 7 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
									up = atoi(ca_paso);
									
									if ( up > 748 )uc_i++;
									else if ( up == 748 )
									{
										j = 0 ;
										for ( i = 7 ;  i < 10 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 364 ) uc_i++;
										else if ( up == 364 ) if ( (int)c_textoDePaso[10] - 48 > 8 ) uc_i++;
									}
								}
							
							}
																				
							if ( uc_i == 0 )for ( i = 1 ; i < 11 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									//break;
								}							
							}							
						} else {
							
							uc_i = 0;
											
							char ca_paso[3];
							for ( i = 0 ;  i < 3 ; i++ ) ca_paso[i] = c_textoDePaso[i];
							short int up = atoi(ca_paso);
							
							if ( (int)c_textoDePaso[9] > 47 && (int)c_textoDePaso[9] < 58 )
							{
									if ( up > 214 )uc_i++; 
									else if ( up == 214 )
									{
										j = 0 ;
										for ( i = 3 ;  i < 6 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 748 )uc_i++;
										else if ( up == 748 )
										{
											j = 0 ;
											for ( i = 6 ;  i < 9 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
											up = atoi(ca_paso);
											
											if ( up > 364 ) uc_i++;
											else if ( up == 364 ) if ( (int)c_textoDePaso[9] - 48 > 7 ) uc_i++;
										}
									}
																
								}
								
								
							for ( i = 0 ; i < 10 ; i++)
								{
									paso = (int)c_textoDePaso[i] ;
		
									if ( paso > 57 || paso < 48 && paso > 32 )
									{
										printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
										s_cortaFuego++;
										break;
									}							
								}
									
							}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
							
						//-2147483648
							
						} else 	if ( uc_i > 0 || d_paso > 2147483647 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.loi_num = loi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
						}
						break;
						
					case 7  :  // |	unsigned long int	 |-----------------------------------------
						//   0 a 4294967295
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						d_paso = atoi(c_textoDePaso);
						unsigned long int unloi_paso = atoi(c_textoDePaso);
						uc_j = 0 , uc_i = 0 ;
						
						for ( i = 0 ; i < 11 /*|| uc_j == 1*/ ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							uc_i++;
						}
						
						if ( c_textoDePaso[0] == '-' )
						{
							uc_i ++;
														
						} else {
							
							uc_i = 0;
											
							char ca_paso[3];
							for ( i = 0 ;  i < 3 ; i++ ) ca_paso[i] = c_textoDePaso[i];
							short int up = atoi(ca_paso);// 429 496 729 5
							
							if ( (int)c_textoDePaso[9] > 47 && (int)c_textoDePaso[9] < 58 )
							{
								if ( up > 429 )uc_i++; 
								else if ( up == 429 )
								{
									j = 0 ;
									for ( i = 3 ;  i < 6 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
									up = atoi(ca_paso);
									
									if ( up > 496 )uc_i++;
									else if ( up == 496 )
									{
										j = 0 ;
										for ( i = 6 ;  i < 9 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 729 ) uc_i++;
										else if ( up == 729 ) if ( (int)c_textoDePaso[9] - 48 > 5 ) uc_i++;
									}
								}
							}
							
							for ( i = 0 ; i < 10 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 4294967295  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
							
						} else 	if ( uc_i > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unloi_num = unloi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
						}						
						break;
					case 8 : 
						
						dio = strlen( c_textoDePaso );
						
						c_textoDePaso[dio-1] = '\0' ;

						strcpy( AnalisisDeEntrada.array_fifty , c_textoDePaso );
						sh_parametroDeSalida = sh_numeroDeVeces;
						
						break;
					
					case 9 : // | 		flat	 	|----------------------------------------------------------|
						// 1.17549e-038  3.40282e+038
						// 4 bites
						dio = strlen( c_textoDePaso );
						char texb[10] ;
						char texc[10] ;
						dio = dio - 1 ;
						s_cortaFuego = 0;
						short l;
						j = 0, k = 0;
						float f_pa, f_pb , f_pc ;
						
						// Esta parte descarta o analiza el valor si es negativo.------------------------------|
						
						if( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < dio ; i++ )
							{
								paso = (int)c_textoDePaso[i] ;
								
								if ( paso > 57 || paso < 46 && paso > 32 )
								{
									if( paso == 47 )s_cortaFuego++;
									s_cortaFuego++;
									break;
								}
		
								// El valor de j indica la posicion del punto dentro del arreglo. -------------|
								
								if ( (int)c_textoDePaso[i] != 46 && k == 0 ) 
								{
									j++;
								}else if ( (int)c_textoDePaso[i] == 46 ){
									k++;	
								}
								// K es el control para verificar que no exista más de un punto. --------------|
							}
							j++;
						
						if ( s_cortaFuego > 0 || k > 1 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;	
							
						} else if ( (int)c_textoDePaso[0] < 33 && j == 0  && k == 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;		
						} 							
							if ( k == 0 && s_cortaFuego == 0 ) // Si el valor del arreglo no contiene punto, se pasará directo.-----|
							{
								f_pa = atoi(c_textoDePaso);
								AnalisisDeEntrada.f_num = f_pa;
								break;
							}
							
							// Sí el valor de k es igual a 1, se tomará de partida el calculo de dos valores de 
							// punto flotante.
							
							if ( k == 1 && s_cortaFuego == 0 ) 						
							{
								loi_sizefloat = j ;
								
								for ( i = 0 ;  i < loi_sizefloat ; i++ ) texa[i] = c_textoDePaso[i] ;
								f_pa = atoi(texa);
								
								loi_sizefloat ++;
								j++;
								l = 0 ;
								
								for ( i = loi_sizefloat ; i < dio ; i++)
								{
									texb[l] = c_textoDePaso[i];	
									l++;
								 } 
								f_pb = atoi(texb);
								
								for ( i = 0 ; (int)texb[i] < 47 && (int)texb[i] > 58 ; i++) l++;
								
								for ( i = 0 ; i < l ; i++) f_pb = f_pb * 0.1 ;
								f_pc = f_pa - f_pb ;
								
								AnalisisDeEntrada.f_num = f_pc;
								sh_parametroDeSalida = sh_numeroDeVeces;
								break;	
							}
							
						} else
						{
							for ( i = 0 ; i < dio ; i++ )
							{
								paso = (int)c_textoDePaso[i] ;
								if ( paso > 57 || paso < 46 && paso > 32 )
								{
									if( paso == 47 )s_cortaFuego++;
									s_cortaFuego++;
									break;
								}
									
								// El valor de j indica la posicion del punto dentro del arreglo. -------------|
								
								if ( (int)c_textoDePaso[i] != 46 && k == 0 ) 
								{
									j++;
								}else if ( (int)c_textoDePaso[i] == 46 ){
									k++;	
								}
								// K es el control para verificar que no exista más de un punto. --------------|
							}
							
						if ( s_cortaFuego > 0 || k > 1 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;	
							
						} else if ( (int)c_textoDePaso[0] < 33 && j == 0  && k == 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;		
						} 
							
							printf("\n\tFuera del For--------- Valor de k %i ", k);
							
							if ( k == 0 && s_cortaFuego == 0 ) // Si el valor del arreglo no contiene punto, se pasará directo.-----|
							{
								f_pa = atoi(c_textoDePaso);
								AnalisisDeEntrada.f_num = f_pa;
								sh_parametroDeSalida = sh_numeroDeVeces;
								break;
								
							}
							
							// Sí el valor de k es igual a 1, se tomará de partida el calculo de dos valores de 
							// punto flotante.
							
							if ( k == 1 && s_cortaFuego == 0 ) 						
							{
								loi_sizefloat = j ;
								
								for ( i = 0 ;  i < loi_sizefloat ; i++ ) texa[i] = c_textoDePaso[i] ;
								f_pa = atoi(texa);
								
								loi_sizefloat ++;
								j++;
								l = 0 ;
								
								for ( i = loi_sizefloat ; i < dio ; i++)
								{
									texb[l] = c_textoDePaso[i];	
									l++;
								 } 
								f_pb = atoi(texb);
								for ( i = 0 ; (int)texb[i] < 47 && (int)texb[i] > 58 ; i++) l++;
								
								for ( i = 0 ; i < l ; i++) f_pb = f_pb * 0.1 ;
								f_pc = f_pa + f_pb ;
								
								AnalisisDeEntrada.f_num = f_pc;
								sh_parametroDeSalida = sh_numeroDeVeces;
								break;
								
							}					
														
						}
						
						break;
						
					default : 
					
						printf("\t\nFuncion eDU_AnalizarEntrada: Valor ingresado en sh_configuracion no valido");

						break;
				}
		
			sh_numeroDeVecesIngresadas++;
			if( sh_numeroDeVecesIngresadas == sh_numeroDeVeces ) sh_parametroDeSalida = sh_numeroDeVeces;
						
		}while( sh_parametroDeSalida != sh_numeroDeVeces );		
		
		return AnalisisDeEntrada;
	}
								
/*--	5- Manejo de funciones 	  --*/

/*
		||		Datos Generales del archivo:		||
	------------------------------------------------------------------------------------------
	Universidad Nacional Autónoma de México
	Facultad de Ingeniería
	1227 Estructura de Datos y Algoritmos
	Grupo: 09
	 
	Autor: José Luis Bautista Rodríguez
	Fecha de inicio: 25-27 && 8 /03/2018
	Lugar: San Miguel de Allende, Guanajuato.
	------------------------------------------------------------------------------------------	||

*/
