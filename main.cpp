#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// função responsável pela comparação para descobrir o vencedor
int jogada(int playerChoice, int computerChoice)
{
	/*
	-1 = computador venceu
	0 = empate
	1 = jogador venceu
    ----------------------
	0 = pedra
	1 = papel
	2 = tesoura
	3 = lagarto
	4 = spock
	*/
	int res;

	if(playerChoice == 0) // caso a escolha do jogador tenha sido pedra
	{
		if(computerChoice == 0)
			res = 0;
		else if(computerChoice == 1)
		{
			cout << "PAPEL EMBRULHA PEDRA!" << endl;
			res = -1;
		}
		else if(computerChoice == 2)
		{
			cout << "PEDRA QUEBRA TESOURA!" << endl;
			res = 1;
		}
		else if(computerChoice == 3)
		{
			cout << "PEDRA ESMAGA LAGARTO!" << endl;
			res = 1;
		}
		else if(computerChoice == 4)
		{
			cout << "SPOCK VAPORIZA PEDRA!" << endl;
			res = -1;
		}
	}
	else if(playerChoice == 1) // caso a escolha do jogador tenha sido papel
	{
		if(computerChoice == 0)
		{
			cout << "PAPEL EMBRULHA PEDRA" << endl;
			res = 1;
		}
		else if(computerChoice == 1)
		{
			res = 0;
		}
		else if(computerChoice == 2)
		{
			cout << "TESOURA CORTA PAPEL!" << endl;
			res = -1;
		}
		else if(computerChoice == 3)
		{
			cout << "LAGARTO COME PAPEL!" << endl;
			res = -1;
		}
		else if(computerChoice == 4)
		{
			cout << "PAPEL REFUTA SPOCK!" << endl;
			res = 1;
		}
	}
	else if(playerChoice == 2) // caso a escolha tenha sido tesoura
	{
		if(computerChoice == 0)
		{
			cout << "PEDRA QUEBRA TESOURA!" << endl;
			res = -1;
		}
		else if(computerChoice == 1)
		{
			cout << "TESOURA CORTA PAPEL!" << endl;
		}
		else if(computerChoice == 2)
		{
			cout << "TESOURA CORTA PAPEL!" << endl;
			res = -1;
		}
		else if(computerChoice == 3)
		{
			cout << "LAGARTO COME PAPEL!" << endl;
			res = -1;
		}
		else if(computerChoice == 4)
		{
			cout << "PAPEL REFUTA SPOCK!" << endl;
			res = 1;
		}
	}
	else if(playerChoice == 3) // caso a escolha tenha sido lagarto
	{
		if(computerChoice == 0)
		{
			cout << "PEDRA ESMAGA LAGARTO" << endl;
			res = -1;
		}
		else if(computerChoice == 1)
		{
			cout << "LAGARTO COME PAPEL" << endl;
			res = 1;
		}
		else if(computerChoice == 2)
		{
			cout << "TESOURA DECAPITA LAGARTO" << endl;
			res = -1;
		}
		else if(computerChoice == 3)
		{
			res = 0;
		}
		else if(computerChoice == 4)
		{
			cout << "LAGARTO ENVENENA SPOCK!" << endl;
			res = 1;
		}
	}
	else	// caso a escolha tenha sido spock
	{
		if(computerChoice == 0)
		{
			cout << "SPOCK VAPORIZA PEDRA!" << endl;
			res = 1;
		}
		else if(computerChoice == 1)
		{
			cout << "PAPEL REFUTA SPOCK!" << endl;
			res = -1;
		}
		else if(computerChoice == 2)
		{
			cout << "SPOCK DERRETE TESOURA!" << endl;
			res = 1;
		}
		else if(computerChoice == 3)
		{
			cout << "LAGARTO ENVENENA SPOCK!" << endl;
			res = -1;
		}
		else if(computerChoice == 4)
		{
			res = 0;
		}
	}

	return res;
}

//função responsável pela escolha da jogada do computador
int random()
{
	int escolha;
	unsigned seed = time(0);

	srand(seed);
	escolha = rand() % 5;

	return escolha;
}

int main()
{
	int playerChoice; // escolha do jogador
	int computerChoice; // escolha do computador
	int resultado; // resultado para saber quem ganhou

	// inicialização do jogo e escolha do usuário
	cout << "[0]PEDRA \n[1]PAPEL \n[2]TESOURA \n[3]LAGARTO \n[4]SPOCK" << endl;
	do
	{
		cout << "ESCOLHA SUA JOGADA: ";
		cin >> playerChoice; // escolha do jogador
	}
	// validando a entrada
	while(playerChoice != 0 && playerChoice != 1 && playerChoice != 2 && playerChoice != 3 && playerChoice != 4);

	// estrutura para mostrar a jogada do jogador
	switch(playerChoice)
	{
	case 0:
		cout << "VOCE ESCOLHEU PEDRA!" << endl;
		break;
	case 1:
		cout << "VOCE ESCOLHEU PAPEL!" << endl;
		break;
	case 2:
		cout << "VOCE ESCOLHEU TESOURA!" << endl;
		break;
	case 3:
		cout << "VOCE ESCOLHEU LAGARTO!" << endl;
		break;
	case 4:
		cout << "VOCE ESCOLHEU SPOCK!" << endl;
		break;
	}

	// chamada da função para fazer a jogada do computador
	computerChoice = random();

	// estrutura para mostrar a jogada do computador
	switch(computerChoice)
	{
	case 0:
		cout << "COMPUTADOR ESCOLHEU PEDRA!" << endl;
		break;
	case 1:
		cout << "COMPUTADOR ESCOLHEU PAPEL!" << endl;
		break;
	case 2:
		cout << "COMPUTADOR ESCOLHEU TESOURA!" << endl;
		break;
	case 3:
		cout << "COMPUTADOR ESCOLHEU LAGARTO!" << endl;
		break;
	case 4:
		cout << "COMPUTADOR ESCOLHEU SPOCK!" << endl;
		break;
	}

	cout << "===================================" << endl;
	// chamada da função para saber quem ganhou
	resultado = jogada(playerChoice, computerChoice);

	// saída do resultado
	if(resultado == 0)
		cout << "EMPATE!" << endl;
	else if(resultado == 1)
		cout << "VOCE VENCEU!" << endl;
	else
		cout << "COMPUTADOR VENCEU!" << endl;

	return 0;
}
