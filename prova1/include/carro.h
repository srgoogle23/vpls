#ifndef PDS2_CARRO_H
#define PDS2_CARRO_H

class Carro {
  private:
    unsigned int _linha;
    unsigned int _coluna;
    int _velocidade;
  public:
    Carro(
      unsigned int linha, unsigned int coluna,
      int velocidade
    );
    bool mover();
    unsigned int get_coluna();
    unsigned int get_linha();
    int get_velocidade();
};

#endif