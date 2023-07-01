#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <windows.h>
using namespace std;

char saberlado(int x){
	char y;
	if(x == 0){
			y = 'D';
		} else if(x == 1){
			y = 'F';
		} else if(x == 2){
			y = 'R';
		} else if(x == 3){
			y = 'L';
		} else if(x == 4){
			y = 'B';
		} else if(x == 5){
			y = 'U';
		}
	return y;
}

void vira_face(char a[][3][3],int face){
	int troca;
	
	troca = a[face][0][0];
	a[face][0][0] = a[face][2][0];
	a[face][2][0] = a[face][2][2];
	a[face][2][2] = a[face][0][2];
	a[face][0][2] = troca;
	//cantos
	troca = a[face][0][1];
	a[face][0][1] = a[face][1][0];
	a[face][1][0] = a[face][2][1];
	a[face][2][1] = a[face][1][2];
	a[face][1][2] = troca;
	//lados
}

void vira_face_down(char a[][3][3]){
	int troca, x;
	
	for(x = 0; x < 3; x++){
		troca = a[1][2][x];
		a[1][2][x] = a[3][2][x];
		a[3][2][x] = a[4][2][x];
		a[4][2][x] = a[2][2][x];
		a[2][2][x] = troca;
	}
	vira_face(a,0);
}

void vira_face_up(char a[][3][3]){
	int troca, x;
	
	for(x = 0; x < 3; x++){
		troca = a[1][0][x];
		a[1][0][x] = a[2][0][x];
		a[2][0][x] = a[4][0][x];
		a[4][0][x] = a[3][0][x];
		a[3][0][x] = troca;
	}
	vira_face(a,5);	
}

void vira_face_front(char a[][3][3]){
	int troca, x;
	for(x = 0; x < 3; x++){   
		troca = a[5][2][x];
		a[5][2][x] = a[3][2-x][2];
		a[3][2-x][2] = a[0][0][2-x];
		a[0][0][2-x] = a[2][x][0];
		a[2][x][0] = troca;
	}
	vira_face(a,1);
}

void vira_face_back(char a[][3][3]){
	int troca, x;
	for(x = 0; x < 3; x++){
		troca = a[5][0][x];
		a[5][0][x] = a[2][2-x][2];
		a[2][2-x][2] = a[0][2][x];
		a[0][2][x] = a[3][x][0];
		a[3][x][0] = troca;
	}
	vira_face(a,4);	
}

void vira_face_right(char a[][3][3]){
	int troca, x;
	
	for(x = 0; x < 3; x++){
		troca = a[5][2-x][2];
		a[5][2-x][2] = a[1][2-x][2];
		a[1][2-x][2] = a[0][2-x][2];
		a[0][2-x][2] = a[4][x][0];
		a[4][x][0] = troca;
	}
	vira_face(a,2);
}

void vira_face_left(char a[][3][3]){
	int troca, x;
	
	for(x = 0; x < 3; x++){
		troca = a[5][x][0];
		a[5][x][0] = a[4][2-x][2];
		a[4][2-x][2] = a[0][x][0];
		a[0][x][0] = a[1][x][0];
		a[1][x][0] = troca;
	}
	vira_face(a,3);
}

void textcolor(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*
Coordenadas
	0 - down, 5 - up
	1 - front, 4 - back
	2 - right, 3 - left

troca = a[][0][0];
		a[][0][0] = a[][2][0];
		a[][2][0] = a[][2][2];
		a[][2][2] = a[][0][2];
		a[][0][2] = troca;
		//cantos
		troca = a[][1][0];
		a[][1][0] = a[][2][1];
		a[][2][1] = a[][1][2];
		a[][1][2] = a[][0][1];
		a[][0][1] = troca;
		//lados
*/

int main(){
	setlocale(LC_ALL,"Portuguese");
	SetConsoleTitle("Super Montador de Cubo Mágico");
	int face, y, x, i, escolha, validade, clockwise;
	char lado;
	char cubo[6][3][3];
	bool vdd = true;
	cout << "Digite as peças do cubo mágico\n\n";
	//cubo pode ter elementos do tipo Y - yellow, W - white, R - red, O - orange, G - green, B - blue
	/*Nas coordenadas
	0 - down, 5 - up
	1 - front, 4 - back
	2 - right, 3 - left
	*/
	for(face = 0; face < 6; face++){
		lado = saberlado(face);
		cout << "Na face " << lado << endl;
		for(y = 0; y < 3; y++){
			for(x = 0; x < 3; x++){
				cout << "Digite a peça" << endl;
				cin >> cubo[face][y][x];
				cubo[face][y][x] = toupper(cubo[face][y][x]);
				while(cubo[face][y][x] != 'W' &&
					cubo[face][y][x] != 'Y' &&
					cubo[face][y][x] != 'R' &&
					cubo[face][y][x] != 'O' &&
					cubo[face][y][x] != 'B' &&
					cubo[face][y][x] != 'G'){
						cout << "Peça inválida, tente novamente" << endl;
						cin >> cubo[face][y][x];
						cubo[face][y][x] = toupper(cubo[face][y][x]);
					}
			}
		}
		system("cls");
	}
	cout << "Aguardando confirmação\n";
	system("pause");
	cout << endl;
	for(face = 0; face < 6; face++){
		lado = saberlado(face);
		cout << "Na face " << lado << endl;
		for(y = 0; y < 3; y++){
			for(x = 0; x < 3; x++){
				switch(cubo[face][y][x]){
							case 'W':
								textcolor(255);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'Y':
								textcolor(238);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'R':
								textcolor(204);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'B':
								textcolor(153);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'G':
								textcolor(170);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'O':
								textcolor(221);
								cout << setw(3) << cubo[face][y][x];
							break;
						}
				textcolor(15);
			}
			cout << endl;
		}
		cout << endl;
	}
	clockwise = 0;
	while(vdd){
		cout << "Próximo passo:\n0. Anti-horário: " << clockwise 
		<< "\n1. Girar UP\n2. Girar DOWN\n3. Girar FRONT\n4. Girar BACK\n"
		<< "5. Girar RIGHT\n6. Girar LEFT\n7. EXIT\n\nDigite aqui: ";
		cin >> escolha;
		validade = 0;
		switch(escolha){
			case 0:
				if(clockwise){
					clockwise = 0;
				} else {
					clockwise = 1;
				}
			break;
			case 1:
				if(clockwise){
					for(i = 0; i < 3; i++){
						vira_face_up(cubo);
					}
				} else {
					vira_face_up(cubo);
				}
			break;
			case 2:
				if(clockwise){
					for(i = 0; i < 3; i++){
						vira_face_down(cubo);
					}
				} else {
					vira_face_down(cubo);
				}
			break;
			case 3:
				if(clockwise){
					for(i = 0; i < 3; i++){
						vira_face_front(cubo);
					}
				} else {
					vira_face_front(cubo);
				}
			break;
			case 4:
				if(clockwise){
					for(i = 0; i < 3; i++){
						vira_face_back(cubo);
					}
				} else {
					vira_face_back(cubo);
				}
			break;
			case 5:
				if(clockwise){
					for(i = 0; i < 3; i++){
						vira_face_right(cubo);
					}
				} else {
					vira_face_right(cubo);
				}
			break;
			case 6:
				if(clockwise){
					for(i = 0; i < 3; i++){
						vira_face_left(cubo);
					}
				} else {
					vira_face_left(cubo);
				}
			break;
			case 7:
				return 0;
			break;
			default:
				validade = 1;
			break;
		}
		if(validade){
			cout << "Este comando não é válido, tente novamente!\n";
		} else {
			system("cls");
		
			cout << "Aguardando confirmação\n";
			system("pause");
			cout << endl;
			for(face = 0; face < 6; face++){
				lado = saberlado(face);
				cout << "Na face " << lado << endl;
				for(y = 0; y < 3; y++){
					for(x = 0; x < 3; x++){
						switch(cubo[face][y][x]){
							case 'W':
								textcolor(255);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'Y':
								textcolor(238);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'R':
								textcolor(204);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'B':
								textcolor(153);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'G':
								textcolor(170);
								cout << setw(3) << cubo[face][y][x];
							break;
							case 'O':
								textcolor(221);
								cout << setw(3) << cubo[face][y][x];
							break;
						}
						textcolor(15);
					}
					cout << endl;
				}
				cout << endl;
			}
		}
	}
}


