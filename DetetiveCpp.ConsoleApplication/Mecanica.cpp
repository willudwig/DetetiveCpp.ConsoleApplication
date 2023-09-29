//#include "Mecanica.h"
//#include <string>
//#include <random>
//#include <list>
//#include "Arma.cpp"
//#include "Local.cpp"
//#include "Suspeito.cpp"
//#include "Jogador.cpp"
//#include "TopSecret.cpp"
//
//using namespace std;
//
//class Mecanica
//{
//public:
//	Mecanica() {
//		iniciarListaTudo();
//		distribuirAlibis();
//	}
//
//	Jogador jogador1;
//	Jogador jogador2;
//	Jogador jogador3;
//	Jogador jogador4;
//	Jogador jogador5;
//	Jogador jogador6;
//
//	void identificarJogadores(string nomeJogador1) {
//		jogador1.setIdentificacao(nomeJogador1);
//		jogador2.setIdentificacao("Cel. Mostarda");
//		jogador3.setIdentificacao("Sr. Marinho");
//		jogador4.setIdentificacao("Srta, Rosa");
//		jogador5.setIdentificacao("Profa. Violeta");
//		jogador6.setIdentificacao("Sra. Branca");
//	}
//	
//	void distribuirAlibis() {
//
//		while (listaTudo.size() > 0)
//		{
//			jogador1.setAlibiLista( fornecerAlibi(listaTudo) );
//			jogador2.setAlibiLista( fornecerAlibi(listaTudo) );
//			jogador3.setAlibiLista( fornecerAlibi(listaTudo) );
//			jogador4.setAlibiLista( fornecerAlibi(listaTudo) );
//			jogador5.setAlibiLista( fornecerAlibi(listaTudo) );
//			jogador6.setAlibiLista( fornecerAlibi(listaTudo) );
//		}
//	}	
//
//	void iniciarListaTudo() {
//		Arma arma;
//		Local local;
//		Suspeito suspeito;
//
//		listaTudo = arma.getLista();
//		listaTudo = listaTudo, local.getLista();
//		listaTudo = listaTudo, suspeito.getLista();
//
//		listaTudo.sort();
//	}
//
//private:
//	list<string> listaTudo;
//
//	 string fornecerAlibi(list<string> lista) {
//		TopSecret tp;
//		string resultado = lista.front();
//
//		if (resultado != tp.arma.getIdentificacao() and resultado != tp.local.getIdentificacao() and resultado != tp.suspeito.getIdentificacao()) {
//			lista.pop_front();
//			return resultado;
//		}
//		else
//			fornecerAlibi;
//	}
//
//};
//
