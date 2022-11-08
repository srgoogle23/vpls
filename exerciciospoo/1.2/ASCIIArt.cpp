#include <string>
#include <iostream>

using namespace std;

class ASCIIArt
{
	public:
		static void print(string s){
			for (int i = 0; i < (s.length() + 3); i++)
			{
				cout << "-";
				if ((i+1) == (s.length() + 3))
					cout << endl << "- " << s << " -" << endl;
			}
			for (int i = 0; i < (((s.length() + 3) / 2) - 1); i++)
			{
				cout << "-";
				if ((i+1) == (((s.length() + 3) / 2) - 1))
					cout << "\\/";
			}
			for (int i = 0; i < (((s.length() + 3) / 2) - 1); i++){
				cout << "-";
			}
		}

		static void print(char c){
			for (int i = 0; i < 13; i++){
				cout << c;
				if ((i+1) == 13)
					cout << endl << c << " ASCII ART " << c << endl;
			}

			for (int i = 0; i < 4; i++){
				cout << c;
				if ((i+1) == 4)
					cout << "\\/";	
			}	
			
			for (int i = 0; i < 7; i++){
				cout << c;
			}
		}

		static void print(int c){
			for(int i = 0; i < c; i++){
				cout << " O  ";
				if ((i+1) == c)
					cout << endl;
			}
			
			
			for(int i = 0; i < c; i++){
				cout << "/|\\ ";
				if ((i+1) == c)
					cout << endl;
			}

			for(int i = 0; i < c; i++){
				cout << "/-\\ ";
			}
		}
};

int main()
{

	ASCIIArt::print("código");
	cout << endl;
	cout << endl;
	ASCIIArt::print('m');
	cout << endl;
	cout << endl;
	ASCIIArt::print(3);
}