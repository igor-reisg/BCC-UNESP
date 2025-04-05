//Igor dos Reis Gomes

#include<stdio.h>
#include<cc50.h>

int
main(void)
{
	char inicio;
	do
	{
	printf("Digite E para encriptar ou D para decriptar:\n");
	inicio = GetChar();
	}
	while (inicio != 'D' && inicio != 'd' && inicio != 'E' && inicio != 'e');
	
	//Encriptação
	if (inicio == 'E' || inicio == 'e')
	{
	int i;
	
	printf("Digite uma mensagem para encriptar: ");
	string mensagem = GetString();
	
	printf("Digite uma chave: ");
	int chave = GetInt();
	chave = chave%26;
	
	for (i = 0; mensagem[i] != '\0'; i++)
	{
		int ch = mensagem[i];
		
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch + chave;
			
			if (ch > 'z')
			{
			ch = ch - 26;
			}
			mensagem[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + chave;
			
			if (ch > 'Z')
			{
			ch = ch - 26;
			}
			mensagem[i] = ch;
		}
	}
	
	printf("Mensagem encriptada: %s\n", mensagem);
	
	
	return 0;
	}
	
	//Decriptação
	else if (inicio == 'D' || inicio == 'd')
	{
	int i;
	
	printf("Digite uma mensagem para decriptar: ");
	string mensagem = GetString();
	
	printf("Digite uma chave: ");
	int chave = GetInt();
	chave = chave%26;
	
	for (i = 0; mensagem[i] != '\0'; i++)
	{
		int ch = mensagem[i];
		
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - chave;
			
			if (ch < 'a')
			{
			ch = ch + 26;
			}
			mensagem[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch - chave;
			
			if (ch < 'A')
			{
			ch = ch + 26;
			}
			mensagem[i] = ch;
		}
	}
	
	printf("Mensagem decriptada: %s\n", mensagem);
	
	
	}

}
