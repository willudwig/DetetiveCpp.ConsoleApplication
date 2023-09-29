//#include "Apresentacao.h"
//#include <iostream>
//#include "TopSecret.cpp"
//#include "Mecanica.cpp"
//
//using namespace std;
//
//class Apresentacao
//{
//public:
//	TopSecret topSecret;	
//	Mecanica mecanica;
//	Jogador jogador;
//
//	Apresentacao() {
//	
//	}
//
//	void apresentarTitulo() {
//		cout << "DETETIVE C++" << endl << "> ";
//		system("pause");
//		system("cls");
//	}
//
//	void identificarJogador() {
//		string nome;
//		cout << "Qual seu nome detetive? > ";
//		cin >> nome;	
//
//		mecanica.identificarJogadores(nome);		
//	}
//
//	void Interrgogar(string nomeJogador1) {
//		topSecret.definirTopSecret();
//		mecanica.distribuirAlibis();
//		jogador.getLista();
//
//		string suspeito, arma, local;
//		int opcao;
//		cout << "Digite o numero do suspeito:\n\n"
//			<< "1. Cel. MOSTARDA\n"
//			<< "2. Sr. MARINHO\n"
//			<< "3. Srta ROSA\n"
//			<< "4. Profa. VIOLETA\n"
//			<< "5. Sra. BRANCA\n\n"
//			<< "> ";
//			cin >> opcao;
//			switch (opcao)
//			{
//				case 1: suspeito = "Cel. MOSTARDA";
//					break;
//				case 2: suspeito = "Sr. MARINHO";
//					break;
//				case 3: suspeito = "Srta ROSA";
//					break;
//				case 4: suspeito = "Profa. VIOLETA";
//					break;
//				case 5: suspeito = "Sra. BRANCA";
//					break;	
//			}
//			
//			cout << "Digite o numero da arma:\n\n"
//				<< "1. REVOLVER\n"
//				<< "2. FACA\n"
//				<< "3. CANO DE CHUMBO\n"
//				<< "4. CORDA\n"
//				<< "5. CANDELABRO\n\n"
//				<< "6. CHAVE INGLESA\n\n"
//				<< "> ";
//			cin >> opcao;
//			switch (opcao)
//			{
//				case 1: arma = "REVOLVER";
//					break;
//				case 2: arma = "FACA";
//					break;
//				case 3: arma = "CANO DE CHUMBO";
//					break;
//				case 4: arma = "CORDA";
//					break;
//				case 5: arma = "CANDELABRO";
//					break;
//				case 6: arma = "CHAVE INGLESA";
//					break;
//			}
//
//			cout << "Digite o numero do local:\n\n"
//				<< "1. HALL DE ENTRADA\n"
//				<< "2. SALA DE ESTAR\n"
//				<< "3. SALA DE JANTAR\n"
//				<< "4. COZINHA\n"
//				<< "5. SALAO DE BAILE\n\n"
//				<< "6. BIBLIOTECA\n\n"
//				<< "7. SALAO DE JOGOS\n\n"
//				<< "8. CONSERVATORIO\n\n"
//				<< "9. SALA DE MUSICA\n\n"
//				<< "> ";
//			cin >> opcao;
//			switch (opcao)
//			{
//			case 1: arma = "HALL DE ENTRADA";
//				break;
//			case 2: arma = "SALA DE ESTAR";
//				break;
//			case 3: arma = "SALA DE JANTAR";
//				break;
//			case 4: arma = "COZINHA";
//				break;
//			case 5: arma = "SALÃO DE BAILE";
//				break;
//			case 6: arma = "BIBLIOTECA";
//				break;
//			case 7: arma = "SALÃO DE JOGOS";
//				break;
//			case 8: arma = "CONSERVATORIO";
//				break;
//			case 9: arma = "SALA DE MUSICA";
//				break;
//			}
//				
//			//validarAlibi
//	}
//
//
//private:
//
//	void validarAlibi() {
//	}
//
//};
//
