//#include "Jogador.h"
//#include "ElementoBase.cpp"
//#include "Arma.cpp"
//#include <random>
//
//using namespace std;
//
//class Jogador : public ElementoBase
//{
//public:
//	Jogador() {
//
//	}
//
//	void setAlibiLista(string alibi) {
//		setLista(alibi);
//	}
//
//	list<string> getAlibiLista() {
//		return getLista();
//	}
//
//	string fraseAlibi() {
//		string frases[3];
//		frases[0] = "Posso lhe asegurar de que nao eh o seguinte: ";
//		frases[1] = "Voce pode estar no caminho errado, afirmo a voce que nao foi ";
//		frases[2] = "Pense melhor, porque nao eh ";
//
//		random_device rd;
//		mt19937 generator(rd());
//
//		// distribuição uniforme dentro do intervalo
//		uniform_int_distribution<int> distribution(0, 2);
//
//		string fraseAleatoria = frases[distribution(generator)];
//
//		return fraseAleatoria;
//	}
//
//private:
//
//};
//
