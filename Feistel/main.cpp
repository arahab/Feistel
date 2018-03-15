#include <time.h>
#include <conio.h>
#include <Windows.h>
#include"bitFunction.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	char text[41] = { "Не плюй в колодец: вылетит - не поймаешь" }; // text
	char key[8] = { "Аркадий" }; //key
	int a = 0;
	string R[20], L[20]; // dividing the text into blocks and sub - blocks
	for (int i = 0; i < 40; i = i + 2) {
		R[a] = per(text[i]);
		L[a] = per(text[i + 1]);
		a++;
	}
	cout << "Text:" << endl << text << endl << "Key:" << endl << key << endl;
	cout << "Enter - encrypt, Tab - decrypt, Esc - exit" << endl;

	string K[16];
	for (int i = 0; i < 16; i++) //  creating keys 
		K[i] = per(key[0 + rand() % 7]);

	string C;
	int p = 0;
	char sym = _getch();
	while (sym != 27) {
		sym = _getch();
		switch (sym)
		{
		case 13:
			cout << "Encrypted text: " << endl;

			p = 1;
			for (int h = 0; h < 20; h++)//Encrypted text
			{
				for (int i = 0; i < 16; i++)
					if (i != 15) {
						C = xr (R[h], (xr (L[h], K[i])));
						R[h] = L[h];
						L[h] = C;
					}
					else
						R[h] = xr (R[h], (xr (L[h], K[i])));
			}

			for (int i = 0; i < 20; i++)// output values
			{
				char M = bitset<8>(R[i]).to_ulong();
				char N = bitset<8>(L[i]).to_ulong();
				cout << M << N;
			}
			cout << endl;

			break;
		case 9:
			cout << "Decrypted text: " << endl;

			if (p == 1) { //Decrypted text
				for (int h = 0; h < 20; h++)
				{
					for (int i = 15; i >= 0; i--)
						if (i != 0) {
							C = C = xr (R[h], (xr (L[h], K[i])));
							R[h] = L[h];
							L[h] = C;
						}
						else
							R[h] = xr (R[h], (xr (L[h], K[i])));
				}
				for (int i = 0; i < 20; i++)
				{
					char M1 = bitset<8>(R[i]).to_ulong();
					char N1 = bitset<8>(L[i]).to_ulong();
					cout << M1 << N1;
				}
				cout << endl;
			}
			else
				cout << "Error" << endl;

			break;
		}
	}
	return 0;
}
