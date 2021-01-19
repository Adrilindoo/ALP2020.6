#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

//Dados dos alunos - STRUCT
struct Aluno{
  char nome[50], sexo, tipo_imc;
  int idade, qtd_treinos;
  float altura, peso, imc;
};

//Calcular o imc - FUNÇÃO
float imc(Aluno dados){
  float imc;
  imc = dados.peso/pow(dados.altura, 2);
  return imc;
}

//Calcular o tipo do imc - FUNÇÃO
char Tipoimc(Aluno dados){
  char clas;
  if (dados.imc < 18){
    clas = 'A';
  }
  else{
    if (dados.imc < 25){
      clas = 'N';
    }
    else{
      if (dados.imc < 30){
        clas = 'S';
      }
      else{
        if (dados.imc < 35){
          clas = 'O';
        }
        else{
          clas = 'E';
        }
      }
    }
  }
  return clas;
}

//Calcular a quantidade de treinos por semana - FUNÇÃO
int Qtdtreinos(Aluno dados){
  int qtd;
  if (dados.imc < 18){
    qtd = 5;
  }
  else{
    if (dados.imc < 25){
      qtd = 4;
    }
    else{
      if (dados.imc < 30){
        qtd = 5;
      }
      else{
        if (dados.imc < 35){
          qtd = 6;
        }
        else{
          qtd = 7;
        }
      }
    }
  }
  return qtd;
}

//Preenchendo os dados dos alunos - FUNÇÃO
void Cadastrar_Aluno(){
  Aluno dados;
  ofstream escrever("Alunos.txt", ios::app);
  cout << "Nome: ";
  do{
    cin.getline(dados.nome, 50);
  } while (strlen(dados.nome) == 0);
  escrever << "Nome: " << dados.nome << " | ";
  cout << "Sexo [M/F]: ";
  cin >> dados.sexo;
  if (dados.sexo == 'm'){
    dados.sexo = 'M';
  }
  if (dados.sexo == 'f'){
    dados.sexo = 'F';
  }
  escrever << "Sexo: " << dados.sexo << " | ";
  cout << "Idade: ";
  cin >> dados.idade;
  escrever << "Idade: " << dados.idade << " anos | ";
  cout << "Altura: ";
  cin >> dados.altura;
  escrever << "Altura: " << dados.altura << "m | ";
  cout << "Peso: ";
  cin >> dados.peso;
  cout << endl;
  escrever << "Peso: " << dados.peso << "Kg | ";
  dados.imc = imc(dados);
  escrever << "IMC: " << dados.imc << "Kg/m2 | ";
  dados.qtd_treinos = Qtdtreinos(dados);
  escrever << "Quantidade de treinos recomendada: " << dados.qtd_treinos << " | ";
  dados.tipo_imc = Tipoimc(dados);
  switch (dados.tipo_imc){
    case 'A':
      escrever << "Classificação IMC: Abaixo";
      break;
    case 'N':
      escrever << "Classificação IMC: Normal";
      break;
    case 'S':
      escrever << "Classificação IMC: Sobrepeso";
      break;
    case 'O':
      escrever << "Classificação IMC: Obesidade";
      break;
    case 'E':
      escrever << "Classificação IMC: Obesidade Elevada";
      break;
  }
  escrever << endl;
  escrever.close();
}

//Listar todas as informações de todos os alunos - FUNÇÃO
void Listar_Alunos(){
  cout << endl;
  ifstream ler;
  char linha[1000];
  ler.open ("Alunos.txt");
  if (ler.is_open()){
    while(ler.getline(linha, 1000)){
      for (int i = 0; i < strlen(linha); i++){
      cout << linha[i];
      }
      cout << endl;
    }
  }
}

//Dados dos Funcionários - STRUCT
struct Funcionário{
  char nome[50], funcao, sexo;
  int idade;
};

//Preenchimento dos dados dos funcionários - FUNÇÃO
void Cadastrar_Funcionario(){
  Funcionário dados;
  ofstream escrever("Funcionários.txt", ios::app);
  cout << "\nNome: ";
  do{
    cin.getline(dados.nome, 50);
  } while (strlen(dados.nome) == 0);
  escrever << "Nome: " << dados.nome << " | ";
  cout << "Sexo: [M/F]";
  if (dados.sexo == 'm'){
    dados.sexo = 'M';
  }
  if (dados.sexo == 'f'){
    dados.sexo = 'F';
  }
  cin >> dados.sexo;
  escrever << "Sexo: " << dados.sexo << " | ";
  cout << "Idade: ";
  cin >> dados.idade;
  escrever << "Idade: " << dados.idade << " | ";
  cout << "Função: \n";
  cout << "[Z] Zelador(a)\n";
  cout << "[P] Professor(a)\n";
  cout << "[R] Recepcionista\n";
  cin >> dados.funcao;
  switch (dados.funcao){
    case 'Z':
    case 'z':
      if (dados.sexo == 'M' || dados.sexo == 'm'){
        escrever << "Função: Zelador";
      }
      else{
        escrever << "Função: Zeladora";
      }
      break;
    case 'P':
    case 'p':
      if (dados.sexo == 'M' || dados.sexo == 'm'){
        escrever << "Função: Professor";
      }
      else{
        escrever << "Função: Professora";
      }
      break;
    case 'R':
    case 'r':
      escrever << "Função: Recepcionista";
      break;
  }
  escrever << endl;
  escrever.close();
}

//Listar todos os funcionários - FUNÇÃO
void Listar_Funcionarios(){
  cout << endl;
  ifstream ler;
  char linha[1000];
  ler.open ("Funcionários.txt");
  if (ler.is_open()){
    while(ler.getline(linha, 1000)){
      for (int i = 0; i < strlen(linha); i++){
      cout << linha[i];
      }
      cout << endl;
    }
  }
}

//Dados da academia - STRUCT
struct Academia{
  char nome[50];
  int abrir_semana, fechar_semana, abrir_fds, fechar_fds;
  float area;
  int qtd_max;
};

//Calculando a quantidade máxima de pessoas ao mesmo tempo - FUNÇÃO
int Calc_max(Academia dados){
  int qtd = dados.area/4;
  return qtd;
}

//Preenchimento dos dados da academia - FUNÇÃO
void Cadastrar_Academia(){
  Academia dados;
  ofstream escrever ("Academia.txt");
  cout << "Nome: ";
  do {
    cin.getline(dados.nome, 50);
  } while (strlen(dados.nome) == 0);
  escrever << "----- Academia " << dados.nome << " -----" << endl;
  escrever << "--- Para você ficar no SHAPE--- \n";
  cout << "Horário de abrir durante a semana: ";
  cin >> dados.abrir_semana;
  cout << "Horário de fechar durante a semana: ";
  cin >> dados.fechar_semana;
  escrever << "Durante a semana abrimos às " << dados.abrir_semana << "H:00 e fechamos às " << dados.fechar_semana << "H:00\n";
  cout << "Horário de abrir durante finais de semana e feriados: ";
  cin >> dados.abrir_fds;
  cout << "Horário de fechar durante finais de semana e feriados: ";
  cin >> dados.fechar_fds;
  escrever << "Finais de semana e feriados abrimos às " << dados.abrir_fds << "H:00 e fechamos às " << dados.fechar_fds << "H:00\n";
  cout << "Área da academia (m2): ";
  cin >> dados.area;
  dados.qtd_max = Calc_max(dados);
  escrever << "\nOBS: Respeitando as normas de biossegurança visando a prevenção contra o COVID-19, a academia possui área de " << dados.area << "m2 e portanto a ocupação máxima é de " << dados.qtd_max << " pessoas";
  escrever.close();
}

int main(){
  int acao = 1;
  ifstream ler1;
  char linhas[1000];
  ler1.open("Academia.txt");
  if (ler1.is_open()){
    while (ler1.getline(linhas, 1000)){
      for (int i = 0; i < strlen(linhas); i++){
        cout << linhas[i];
      }
      cout << endl;
    }
    cout << endl;
  }
  else{
    cout << "Arquivo não encontrado";
  }
  while (acao != 0){
    cout << "\nO que deseja fazer? \n";
    cout << "[1] Cadastrar Aluno\n";
    cout << "[2] Cadastrar Funcionário\n";
    cout << "[3] Cadastrar Academia\n";
    cout << "[4] Listar Alunos\n";
    cout << "[5] Listar Funcionários\n";
    cout << "[0] Sair\n";
    cin >> acao;
    switch (acao){
      case 0:
        break;
      case 1:
        int n;
        cout << "Quantos alunos deseja cadastrar? ";
        cin >> n;
        for (int i = 0; i < n; i++){
          Cadastrar_Aluno();
        }
        break;
      case 2:
        int j;
        cout << "Quantos funcionários deseja cadastrar? ";
        cin >> j;
        for (int i = 0; i < j; i++){
          Cadastrar_Funcionario();
        }
        break;
      case 3:
        Cadastrar_Academia();
        break;
      case 4:
        Listar_Alunos();
        break;
      case 5:
        Listar_Funcionarios();
    }
  }
  cout << "Obrigado por utilizar nosso software\n";
  cout << "Se puder avaliá-lo com 5 estrelas(ou 10 pontinhos), os devs agradecem imensamente :D \n";
  cout << "Bom dia, boa tarde, boa noite\n";
  cout << ":)\n";
  return 0;
}