// DetetiveCpp.ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

list<string> listaSuspeitos;
list<string> listaArmas;
list<string> listaLocais;
list<string> alibis;

string topSecret[3];
string jogadores[6][4];

string nomeJogador;
int opcao;
int duracao_segundos = 300;
string suspeito, arma, localAtual;
bool possivelAcerto = false, fimJogo = false;

// Declaração dos métodos =====================
void iniciarListas();
void definirTopSecret();
string obterAleatorio(list<string> lista);
void iniciarJogadores(string nomeLido);
string lerNomeJogador();
void apresentarTítulo();
void distribuirAlibisCadaJogador();
void embaralharListaAlibis();
void visitarLocal();
void apresentarOpcoesNoLocal();
void interrgorarAcusarSair();
void interrogar();
void verificarAlibi(string jogadores[6][4]);
string gerarFraseAlibiAleatoria();
void acusar();
//void timer_thread();
//==============================================

int main()
{
    iniciarListas();
	definirTopSecret();
	apresentarTítulo();
	iniciarJogadores(lerNomeJogador());
	distribuirAlibisCadaJogador();
	//timer_thread();
	visitarLocal();
	do
	{
		apresentarOpcoesNoLocal();
		interrgorarAcusarSair();

	} while (!fimJogo);	

	system("exit");

	return 0;
}
void iniciarListas() {
	// suspeitos
	listaSuspeitos.push_back("Cel. MOSTARDA");
	listaSuspeitos.push_back("Sr. MARINHO");
	listaSuspeitos.push_back("Srta ROSA");
	listaSuspeitos.push_back("Profa. VIOLETA");
	listaSuspeitos.push_back("Sra. BRANCA");

	// armas
	listaArmas.push_back("REVOLVER");
	listaArmas.push_back("FACA");
	listaArmas.push_back("CANO DE CHUMBO");
	listaArmas.push_back("CORDA");
	listaArmas.push_back("CANDELABRO");
	listaArmas.push_back("CHAVE INGLESA");

	// locais
	listaLocais.push_back("HALL DE ENTRADA");
	listaLocais.push_back("SALA DE ESTAR");
	listaLocais.push_back("SALA DE JANTAR");
	listaLocais.push_back("COZINHA");
	listaLocais.push_back("SALAO DE BAILE");
	listaLocais.push_back("BIBLIOTECA");
	listaLocais.push_back("SALAO DE JOGOS");
	listaLocais.push_back("CONSERVATORIO");
	listaLocais.push_back("SALA DE MUSICA");
}
void definirTopSecret() {

	// suspeito	
	topSecret[0] = obterAleatorio(listaSuspeitos);
	listaSuspeitos.remove(topSecret[0]);

	// arma	
	topSecret[1] = obterAleatorio(listaArmas);
	listaArmas.remove(topSecret[1]);

	// local	
	topSecret[2] = obterAleatorio(listaLocais);
	listaLocais.remove(topSecret[2]);
}
string obterAleatorio(list<string> lista) {

	// Inicializa a semente do gerador de números aleatórios com o tempo atual
	srand(static_cast<unsigned int>(time(nullptr)));

	// Converte a lista em um vetor para facilitar o embaralhamento
	std::vector<std::string> vetor(lista.begin(), lista.end());

	// Embaralha a lista aleatoriamente
	random_shuffle(vetor.begin(), vetor.end());

	// Acessa o primeiro elemento da lista (agora aleatório)
	return vetor.front();	
}
void iniciarJogadores(string nomeLido) {
	jogadores[0][0] = nomeLido;
	jogadores[1][0] = "Cel. MOSTARDA";
	jogadores[2][0] = "Sr. MARINHO";
	jogadores[3][0] = "Srta ROSA";
	jogadores[4][0] = "Profa. VIOLETA";
	jogadores[5][0] = "Sra. BRANCA";
}
string lerNomeJogador() {	
	cout << "Ola detetive, identifique-se: \n\n"
		<< "> ";
	cin >> nomeJogador;

	system("cls");
	return nomeJogador;
}
void apresentarTítulo() {

	cout << "DETETIVE C++\n\n" << endl << "> ";
	system("pause");
	system("cls");
}
void distribuirAlibisCadaJogador() {
	
	alibis.insert(alibis.end(), listaArmas.begin(), listaArmas.end());
	alibis.insert(alibis.end(), listaLocais.begin(), listaLocais.end());
	alibis.insert(alibis.end(), listaSuspeitos.begin(), listaSuspeitos.end());	
	
	embaralharListaAlibis();	

	// para cada jogador, distriubuir álibis
	for (int i = 0; i < 6; i++)
	{		
		for (int j = 1; j < 4; j++)
		{
			if (alibis.size() == 0)
				break;

			jogadores[i][j] = alibis.front();
			alibis.pop_front();
		}		
	}
	// 1 fornecer o primeiro dessa lista para o jogar1,
	// 2 excluir este item da lista
	// 3 mudar para o proximo jogador
	// repetir 1 2 3 para todos os jogadores
}
void embaralharListaAlibis() {

	vector<std::string> vetor(alibis.begin(), alibis.end());
	random_shuffle(vetor.begin(), vetor.end());
	alibis.clear();
	alibis.insert(alibis.end(), vetor.begin(), vetor.end());	
}
void visitarLocal() {
	cout << "" << nomeJogador << ", digite o numero de um local a visitar:\n\n"
		<< "1. HALL DE ENTRADA\n"
		<< "2. SALA DE ESTAR\n"
		<< "3. SALA DE JANTAR\n"
		<< "4. COZINHA\n"
		<< "5. SALAO DE BAILE\n"
		<< "6. BIBLIOTECA\n"
		<< "7. SALAO DE JOGOS\n"
		<< "8. CONSERVATORIO\n"
		<< "9. SALA DE MUSICA\n"
		<< "\n> ";

	string leitura;
	cin >> leitura;
	int result = stoi(leitura);
	switch (result)
	{
		case 1: localAtual = "HALL DE ENTRADA"; break;
		case 2: localAtual = "SALA DE ESTAR"; break;
		case 3: localAtual = "SALA DE JANTAR"; break;
		case 4: localAtual = "COZINHA"; break;
		case 5: localAtual = "SALAO DE BAILE"; break;
		case 6: localAtual = "BIBLIOTECA"; break;
		case 7: localAtual = "SALAO DE JOGOS"; break;
		case 8: localAtual = "CONSERVATORIO"; break;
		case 9: localAtual = "SALA DE MUSICA"; break;
		default: break;
	}
	system("cls");
}
void apresentarOpcoesNoLocal() {
	cout << "Caro(a) " << nomeJogador << "," << endl
		<< "no momento, voce esta no(a) " << localAtual << endl
		<< "digite o que deseja fazer?\n\n"
		<< "1. Interrogar\n"
		<< "2. Acusar\n"
		<< "3. Sair deste local\n\n"
		<< "> ";

	string leitura;
	cin >> leitura;
	opcao = stoi(leitura);	
	system("cls");
}
void interrgorarAcusarSair() {
	
	switch (opcao)
	{
		case 1: interrogar();
			break;
		case 2: acusar();
			break;
		case 3: visitarLocal();
		default:
			break;
	}
}
void interrogar() {
	cout << "INTERROGAR:" << endl
		<< "Local: " << localAtual << endl
		<< "Digite o numero referente a seu suspeito:\n" << endl
		<< "1. Cel. MOSTARDA\n"
		<< "2. Sr. MARINHO\n"
		<< "3. Srta ROSA\n"
		<< "4. Profa. VIOLETA\n"
		<< "5. Sra. BRANCA\n\n"
		<< "> ";
	
	string leitura;
	cin >> leitura;
	int result = stoi(leitura);
	switch (result)
	{
		case 1: suspeito = "Cel. MOSTARDA"; break;
		case 2: suspeito = "Sr. MARINHO"; break;
		case 3: suspeito = "Srta ROSA"; break;
		case 4: suspeito = "Profa. VIOLETA"; break;
		case 5: suspeito = "Sra. BRANCA"; break;
		default: break;
	}	
	system("cls");

	cout << "INTERROGAR:" << endl
		<< "Local: " << localAtual << endl
		<< "Suspeito: " << suspeito << endl
		<< "Digite o numero referente a arma do crime:\n" << endl
		<< "1. REVOLVER\n"
		<< "2. FACA\n"
		<< "3. CANO DE CHUMBO\n"
		<< "4. CORDA\n"
		<< "5. CANDELABRO\n"
		<< "5. CHAVE INGLESA\n\n"
		<< "> ";
	
	cin >> leitura;
	result = stoi(leitura);
	switch (result)
	{
		case 1: arma = "REVOLVER"; break;
		case 2: arma = "FACA"; break;
		case 3: arma = "CANO DE CHUMBO"; break;
		case 4: arma = "CORDA"; break;
		case 5: arma = "CANDELABRO"; break;
		case 6: arma = "CHAVE INGLESA"; break;
		default: break;
	}

	system("cls");	

	cout << "INTERROGAR:" << endl
		<< "Local: " << localAtual << endl
		<< "Suspeito: " << suspeito << endl
		<< "Arma: " << arma << endl
		<< "\n> ";

	system("pause");
	system("cls");

	verificarAlibi(jogadores);	
}
void acusar() {
	cout << "ACUSAR:" << endl
		<< "Caso sua acusacao esteja errada, voce sai do caso e o jogo termina.\n" << endl
		<< "Local: " << localAtual << endl
		<< "Digite o numero referente a seu suspeito:\n" << endl
		<< "1. Cel. MOSTARDA\n"
		<< "2. Sr. MARINHO\n"
		<< "3. Srta ROSA\n"
		<< "4. Profa. VIOLETA\n"
		<< "5. Sra. BRANCA\n\n"
		<< "> ";

	string leitura;
	cin >> leitura;
	int result = stoi(leitura);
	switch (result)
	{
		case 1: suspeito = "Cel. MOSTARDA"; break;
		case 2: suspeito = "Sr. MARINHO"; break;
		case 3: suspeito = "Srta ROSA"; break;
		case 4: suspeito = "Profa. VIOLETA"; break;
		case 5: suspeito = "Sra. BRANCA"; break;
	default: break;
	}
	system("cls");

	cout << "ACUSAR:" << endl
		<< "Local: " << localAtual << endl
		<< "Suspeito: " << suspeito << endl
		<< "Digite o numero referente a arma do crime:\n" << endl
		<< "1. REVOLVER\n"
		<< "2. FACA\n"
		<< "3. CANO DE CHUMBO\n"
		<< "4. CORDA\n"
		<< "5. CANDELABRO\n"
		<< "5. CHAVE INGLESA\n\n"
		<< "> ";

	cin >> leitura;
	result = stoi(leitura);
	switch (result)
	{
		case 1: arma = "REVOLVER"; break;
		case 2: arma = "FACA"; break;
		case 3: arma = "CANO DE CHUMBO"; break;
		case 4: arma = "CORDA"; break;
		case 5: arma = "CANDELABRO"; break;
		case 6: arma = "CHAVE INGLESA"; break;
		default: break;
	}
	system("cls");	

	cout << "ACUSAR:" << endl
		<< "Local: " << localAtual << endl
		<< "Suspeito: " << suspeito << endl
		<< "Arma: " << arma << endl
		<< "\n> ";

	system("pause");
	system("cls");

	verificarAlibi(jogadores);

	if (possivelAcerto) {
		cout << "Parabens detetive " << nomeJogador << ". Voce desvendou o crime!\n\n"
			<< "FIM DE JOGO.\n\n";

		system("pause");
		fimJogo = true;
	}
	else 
	{
		cout << "Detetive " << nomeJogador << "," << endl
			<< "infelizmente voce fez uma acusacao errada e sera afastado deste caso!\n\n"
			<< "FIM DE JOGO.\n\n"
			<< "> ";

		system("pause");
		fimJogo = true;
	}
}
void verificarAlibi(string jogadores[6][4]) {
	bool parar = false;
	bool semMAnifestacao = false;
	for (int i = 0; i < 6; i++)
	{
		if (!parar) {
			for (int j = 1; j < 4; j++)
			{
				if (jogadores[i][j] == suspeito || jogadores[i][j] == arma || jogadores[i][j] == localAtual) {
					cout << "" << jogadores[i][0] << " diz: " << gerarFraseAlibiAleatoria() << endl
						<< jogadores[i][j] << "\n\n";

					parar = true;
					semMAnifestacao = false;

					system("pause");
					system("cls");

					break;
				}
				else
					semMAnifestacao = true;
			}
		}
		else
			break;
	}

	if (semMAnifestacao)
	{
		cout << "Nenhum dos detetives se manifestou...\n\n"
			<< "> ";
		system("pause");
		system("cls");
		possivelAcerto = true;
	}
}
string gerarFraseAlibiAleatoria() {
	list<string> frases;

	frases.push_back("- Creio que esteja no caminho errado!");
	frases.push_back("- Tente olhar para isso por um angulo diferente!");
	frases.push_back("- Tente outra abordagem!");
	frases.push_back("- Nem sempre a resposta obvia e a correta!");
	frases.push_back("- Pense melhor!");
	frases.push_back("- Posso lhe assegurar que nao e o seguinte:");
	frases.push_back("- As vezes, um passo para tras leva a dois passos a frente!");
	frases.push_back("- Pode estar cometendo um erro!");
	frases.push_back("- Dou-lhe certeza de que nao foi o seguinte:");
	frases.push_back("- Existe um alibi para sua suposicao!");

	return obterAleatorio(frases);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
