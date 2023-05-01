#include "siga.h"
#include "tools.h"

void print_menu()
{
    cout << "SIGA - Sistema de Gestão Acadêmica" << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Inserir estudante" << endl;
    cout << "2. Buscar estudante" << endl;
    cout << "3. Sair" << endl;
    cout << "Digite sua opção: ";
}

void print_busca()
{
    int opcao_busca;

   do{
        cout << "SIGA - Sistema de Gestão Acadêmica" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Buscar por matrícula" << endl;
        cout << "2. Buscar por nome" << endl;
        cout << "3. Voltar" << endl;
        cout << "Digite sua opção: "; 
        cin >> opcao_busca;
        switch(opcao_busca)
        {
            case 1:
                int matricula;
                cout << "Digite a matrícula: ";
                cin >> matricula;
                int idx = siga.PesquisaPorMatricula(matricula);
                if(idx>=0){
                    Estudante estudante = siga.ObterEstudante(idx);
                    estudante.Imprimir();
                }
               
                break;
                        
            case 2:
                std::string nome;
                cout << "Digite o nome: ";
                cin >> nome;
                int idx = siga.PesquisaPorNome(nome.c_str());
                if(idx>=0){
                    Estudante estudante = siga.ObterEstudante(idx);
                    estudante.Imprimir();
                }
                break;
            case 3:
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }while(opcao_busca!=3);
}


Estudante print_read_estudante()
{
    Estudante estudante;
    int matricula;
    std::string nome;
    int curso;
    int ano_ingresso;
    int semestre_ingresso;
    float ira;

    cout << "Digite a matrícula: ";
    cin >> matricula;
    cout << "Digite o nome: ";
    cin >> nome;
    cout << "Digite o curso: ";
    cin >> curso;
    cout << "Digite o ano de ingresso: ";
    cin >> ano_ingresso;
    cout << "Digite o semestre de ingresso: ";
    cin >> semestre_ingresso;
    cout << "Digite o IRA: ";
    cin >> ira;
    return Estudante(matricula, nome.c_str(), ano_ingresso, semestre_ingresso, curso, ira);
}


int main(int argc, const char* argv[])
{

    Siga::Siga siga;
    siga.InitDatabase("estudantes");

    int opcao = 0;
    do{
        print_menu();
        cin >> opcao;
        switch(opcao)
        {
            case 1:
                 Estudante estudante = print_read_estudante();
                siga.InserirEstudante(estudante);
                break;
            case 2:
                print_busca();
                break;
            case 3:
                break;
            default:   
                cout << "Opção inválida!" << endl;
                break;
        }
    }while(opcao!=3)
    return 0;
}
