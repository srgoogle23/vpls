#include <string>
#include <iostream>

using namespace std;

class Conta{
	double saldo;
	public:
		Conta();
		void imprimeSaldo();
		virtual void sacar(double valor) = 0;
		virtual void depositar(double valor) = 0;
		double getSaldo();
		void setSaldo(double s);
};

Conta::Conta(){
	saldo = 0;
}

void Conta::imprimeSaldo(){
	cout << "Saldo: " << saldo << endl;
}

double Conta::getSaldo(){
	return saldo;
}

void Conta::setSaldo(double s){
	saldo = s;
}

class Poupanca: public Conta{
	double taxa;
	public:
		Poupanca();
		void setTaxa(double t);
		void CalculaRendimento();
		virtual void sacar(double valor) override;
		virtual void depositar(double valor) override;
};

Poupanca::Poupanca(){
	taxa = 0;
}

void Poupanca::setTaxa(double t){
	taxa = t;
}

void Poupanca::CalculaRendimento(){
	double rendimento = getSaldo() * taxa;
	setSaldo(getSaldo() + rendimento);
}

void Poupanca::sacar(double valor){
	if (valor > getSaldo()){
		cout << "Saldo insuficiente" << endl;
	}
	else{
		setSaldo(getSaldo() - valor);
	}
}
void Poupanca::depositar(double valor){
	if(valor > 0){
		setSaldo(getSaldo() + valor);
	} else {
		cout << "Valor invalido" << endl;
	}
}

class ContaCorrente: public Conta
{
	private:
		double taxa;
	public:
		ContaCorrente();
		void setTaxa(double t);
		double getTaxa();
		virtual void sacar(double valor) override;
		virtual void depositar(double valor) override;
};

ContaCorrente::ContaCorrente(){
	taxa = 0;
}

void ContaCorrente::setTaxa(double t){
	taxa = t;
}

double ContaCorrente::getTaxa(){
	return taxa;
}

void ContaCorrente::sacar(double valor){
	if (valor > getSaldo()){
		cout << "Saldo insuficiente" << endl;
	}
	else{
		valor += getTaxa();
		setSaldo(getSaldo() - valor);
	}
}
void ContaCorrente::depositar(double valor){
	if(valor > 0){
		setSaldo((getSaldo() - getTaxa() ) + valor);
	} else {
		cout << "Valor invalido" << endl;
	}
}

int main()
{
	// testa conta corrente
	ContaCorrente cc;
	cc.setSaldo(100);
	cc.setTaxa(0.01);
	cc.sacar(50);
	cc.depositar(100);
	cc.imprimeSaldo();
	// testa conta poupança
	Poupanca cp;
	cp.setSaldo(100);
	cp.setTaxa(0.01);
	cp.sacar(50);
	cp.depositar(100);
	cp.CalculaRendimento();
	cp.imprimeSaldo();
	return 0;
}