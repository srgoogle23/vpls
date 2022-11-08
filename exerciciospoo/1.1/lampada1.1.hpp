#ifndef __LAMPADA_HPP__
#define __LAMPADA_HPP__

class Lampada
{
	private:
		int watts;
		float preco;

	public:
		Lampada();
		Lampada(int watts, float preco);
		Lampada(int watts);

};

#endif