#include <iostream> 
#include <fstream> 
#include <string>
#include <sstream>

// Programa Desenvolvido para ler o arquivo 'matriz.txt', com uma matriz quadrática 5x5 de números inteiros,
// e multiplicar a diagonal principal por 2 e, posteriormente, cada valor par por 3,
// e retornar um arquivo 'nova_matriz.txt' com a matriz operada .

// Ambos os arquivos tem cada termo da matriz separado por virgula, sem espaços,
// e cada linha da matriz em uma sua respctiva linha no arquivo.

using namespace std;
int main () {
	
	// LEITURA DA MATRIZ
	
	ifstream arquivo; // abre o arquivo no modo de leitura
	arquivo.open("matriz.txt"); // seleciona o arquivo matriz.txt para abrir 
	
	int matriz[5][5] = {}; // cria matriz uma de inteiros 5x5
	
	// ler a matriz do arquivo com cada termo separado por virgula
	if(arquivo.is_open()){ // verifica se o arquivo abriu
		int a = 0;
		int b = 0;
		string carac;
		string linha; 
		
		while (getline(arquivo, linha)) {  // laço percorre todas as linhas adicionando o conteude de cada em 'linha'
			
			for(int x = 0; x<linha.length(); x++){ // laço percorre cada caracter na linha
				carac = linha.at(x); // adiciona o caracter a variavel carac
				
				if(carac !=","){ // verifica se carac é diferente da virgula
					stringstream inteiro(carac); // altera carac de string para inteiro
					inteiro >> matriz[a][b]; // adiciona carac a matriz 5x5
					b++; // desloca uma coluna
				}
				
			}
			
		b=0; // deloca para a primeira coluna
		a++; // desloca para proxima linha
		}
	
	arquivo.close(); // fecha o arquivo
	cout << "----- 	Matriz lida -----";
	cout << endl;
	
	}else{ // em caso de erro
		cout << "Nao foi possivel abrir o arquivo";
		cout << "confira se o arquivo se encontra no mesmo diretorio e tente novamente";
	}
		
	// OPERAÇÃO COM A MATRIZ
	
	int matriz2[5][5] = {}; // cria uma matriz auxiliar de inteiros 5x5
	
	// laços verificam se o elemento pertencem a diagonal principal e multiplica por 2
	for(int i = 0; i<5; i++){  
		for(int j = 0; j<5; j++){
			
			if(i==j){ // se o número da coluna for igual ao da linha, então o elemento pertece a diagonal principal
				matriz2[i][j] = (matriz[i][j] * 2);
			}else{
				matriz2[i][j] = matriz[i][j];
			}
	
		}
	}
	cout << "----- 	Diagonal multiplicada -----";
	cout << endl;
	
	// laços verificam se o elemento é par e multiplica por 3
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			
			if(matriz2[i][j]%2==0){ // se o resto da divisao do elemento por 2 for igual a zero, então o numero é par
				matriz2[i][j] = (matriz2[i][j] * 3);
			}
		
		}
	}
	cout << "----- 	Numeros pares multiplicados -----";
	cout << endl;
	
	// ESCRITA DA NOVA MATRIZ 
	
	ofstream arquivo_novo; // abre o arquivo no modo de escrita
	arquivo_novo.open("nova_matriz.txt"); // cria o arquivo para adicionar a matriz2
	
	// imprime cada termo da matriz com as operaçoes com cada termo separado po virgula
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			arquivo_novo << matriz2[i][j];
			
			if(j!=4){ // impede que coloque virgula após o último caracter de cada linha
				arquivo_novo << ",";
			}
		
		}
		arquivo_novo << endl;
	}
	
	arquivo_novo.close(); // fecha o novo arquivo
	cout << "----- 	Novo arquivo criado -----";
	cout << endl;
	cout << "-----   Programa executado com sucesso ----";
	cout << endl;

	return 0;
}
