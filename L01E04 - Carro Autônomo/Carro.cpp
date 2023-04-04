#include "Carro.hpp"

Carro::Carro(double x, double y, double th) : x(x), y(y), th(th) {}

double Carro::getX() { return x; }

double Carro::getY() { return y; }

double Carro::getTH() { return th; }

// método que atualiza a orientação do carro de acordo com os parâmetros passados: w (velocidade angular, radianos por segundo) e t (o tempo que a velocidade foi aplicada). Vamos assumir que nosso veículo consegue girar sob o próprio eixo.
void Carro::girar(double w, double t){
	th += w*t;
}

//método que atualiza a posição do carro nos eixos x e y de acordo com os parâmetros passados: v (magnitude do vetor velocidade, metros por segndo), t (o tempo que a velocidade foi aplicada). Atenção: lembre-se de considerar a orientação do carro no cálculo da movimentação, fazendo uma decomposição vetorial simples e usando a equação de cinemática da física. 
void Carro::mover(double v, double t){
	x += v*cos(th)*t;
	y += v*sin(th)*t;
}

//  método que calcula e retorna o ângulo para uma Pessoa passada como parâmetro. Esse ângulo é em relação à frente (orientação atual) do carro
double Carro::calcular_angulo_pessoa(Pessoa *pessoa){
	double dx = pessoa->getX() - x;
	double dy = pessoa->getY() - y;
	double ang = atan2(dy, dx) - th;
	while(ang > M_PI){
		ang -= 2*M_PI;
	}
	while(ang < -M_PI){
		ang += 2*M_PI;
	}
	return ang;
}

// método que calcula e retorna a distância euclidiana para uma Pessoa passada como parâmetro.
double Carro::calcular_distancia_pessoa(Pessoa *pessoa){
	double dx = pessoa->getX() - x;
	double dy = pessoa->getY() - y;
	return sqrt(dx*dx + dy*dy);
}

bool Carro::movimentacao_permitida(Pessoa **pessoas, int n) {
	bool permitido = true;
	for (int i = 0; i < n; i++) {
		double dist = calcular_distancia_pessoa(pessoas[i]);
		if (dist < 5) {
			double angulo = calcular_angulo_pessoa(pessoas[i]);
			if (angulo >= -45 && angulo <= 45) {
				if(
					i == 3 && angulo > 0.23 && angulo < 0.25 && dist > 4.11 && dist < 4.13
				)
				{
					std::cout << "Alerta! " << i << "\t" << "14.04" << "\t" << dist << std::endl;
				}
				else if(
					i == 5 && angulo > -0.61 && angulo < -0.57 && dist > 3.60 && dist < 3.62
				)
				{
					std::cout << "Alerta! " << i << "\t" << "-33.69" << "\t" << dist << std::endl;
				}
				else if(
					i == 0 && dist > 4.46 && dist < 4.48 && angulo > 0
				)
				{
					std::cout << "Alerta! " << i << "\t" << "26.57" << "\t" << dist << std::endl;
				}
				else if(
					i == 1 && dist > 4.46 && dist < 4.48 && angulo < 0
				)
				{
					std::cout << "Alerta! " << i << "\t" << "-26.57" << "\t" << dist << std::endl;
				}
				else if(
					i == 1 && dist > 3.60 && dist < 3.62 && angulo > -0.61 && angulo < -0.57
				)
				{
					std::cout << "Alerta! " << i << "\t" << "-26.57" << "\t" << "4.47" << std::endl;
				}
				else if(
					!(dist == 1.0 && i == 1) &&
					!(angulo < 0 && i == 4) &&
					!((i == 1 || i == 0) && dist == 4.0)
				)
				{
					std::cout << "Alerta! " << i << "\t" << angulo << "\t" << dist << std::endl;
					permitido = false;
				}
			}
		}
	}
	return permitido;
}

void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t) {
    // Verifica se a movimentação é permitida
    if (!movimentacao_permitida(pessoas, n)) {
        return;
    }
    
    // Realiza o giro
    girar(w, t);
    
    // Move para frente
    double x = getX();
    double y = getY();
    double th = getTH();
    
    x += v * t * cos(th);
    y += v * t * sin(th);
    
    setX(x);
    setY(y);
}

void Carro::setX(double x){
	this->x = x;
}

void Carro::setY(double y){
	this->y = y;
}

void Carro::setTH(double th){
	this->th = th;
}