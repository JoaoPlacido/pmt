#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "pmt.hpp"
#include <getopt.h>

#define no_argument 0
#define required_argument 1 
#define optional_argument 2

using namespace std;
using std::cout; using std::endl;
using std::cin; using std::string;
using std::vector;

void help_msg(){
    cout<<"pmt: \tpmt [-a ALGORITHM] [-e EMAX] [-p] [-c] PATTERN TEXTFILE [TEXTFILE...]"<<endl;
    cout<<"\tProcura o padrão PATTERN no(s) arquivo(s) TEXTFILE."<<endl<<endl;
    cout<<"\tPor padrão imprime as linhas do(s) texto(s) em que o padrão PATTERN \n\taparece."<<endl<<endl;
    cout<<"\tOpções:\n"<<endl;
    cout<<"\t-a/--algorithm\t"<<"\tescolhe um algoritmo especifico para realizar a\n\t\t\t\tbusca de padrão(ões)." <<endl;
    cout<<"\n\t-e/--edit\t"<<"\tlocaliza todas ocorrências do(s) padrão(ões)\n\t\t\t\tno(s) texto(s) em uma distância de erro maximo.\n\t\t\t\t(Usado apenas nos algoritmos de busca aproximada)"<<endl;
    cout<<"\n\t-p/--pattern\t"<<"\trealiza a busca em todos os padrões em um\n\t\t\t\tarquivo dado em PATTERN."<<endl;
    cout<<"\n\t-c/--count\t"<<"\timprime apenas a quantidade total de ocorrências\n\t\t\t\tdo(s) padrão(ões) condida no(s) arquivo(s) de\n\t\t\t\ttexto."<<endl<<endl;
    cout<<"\tArgumentos:\n"<<endl;
    cout<<"\tALGORITHM\t"<<"\tnome do algoritmo que vai realiazar a busca de\n\t\t\t\tpadrões."<<endl;
    cout<<"\n\tEMAX\t"<<"\t\tvalor inteiro maior que 0 do erro maximo, usado para\n\t\t\t\tbusca aproximada(deve ser dado em caso de usar um\n\t\t\t\talgoritmo de busca aproximada)"<<endl;
    cout<<"\n\tPATTERN\t"<<"\t\tpadrão a ser procurado no(s) texto(s). Caso usado '-p'\n\t\t\t\tPATTERN é um arquivo contendo os padrões a serem procurados(cada padrão por linha)."<<endl;
    cout<<"\n\tTEXTFILE\t"<<"\ttexto em que vai ser procurado o(s) padrão(ões)\n\t\t\t\t(pode ser dado mais de um texto)."<<endl;
    cout<<"\nLista de algoritmos implementados:"<<endl<<endl;
    cout<<"nome                     | tipo de busca | representação(ALGORITHM) "<<endl;
    cout<<"-------------------------|---------------|-------------------------"<<endl;
    cout<<"Knuth-Morris-Pratt       | padrão        | kmp"<<endl;
    cout<<"-------------------------|---------------|-------------------------"<<endl;
    cout<<"Aho-Corasick             | padrão        | ahocor"<<endl;
    cout<<"-------------------------|---------------|-------------------------"<<endl;
    cout<<"Shift-Or                 | padrão        | shift-or"<<endl;
    cout<<"-------------------------|---------------|-------------------------"<<endl;
    cout<<"Needleman-Wunsch-Sellers | aproximado    | sellers"<<endl;
    cout<<"-------------------------|---------------|-------------------------"<<endl;
    cout<<"Wu-Manber                | aproximado    | wu-manber"<<endl;
}
    
void interface(int argc, char *argv[]){
   
    char *char_part = nullptr;
    
    int emax = 0;               //distância de edição para busca aproximada
    string pattern ="";         //padrão a ser procurado nos textos, pode ser o nome de um arquivo contendo padroes
    string algorithm = "";      //nome do algoritmo a ser usado
    bool p = false;             //flag caso a opção -p for usada
    bool a = false;             //flag caso a opção -a for usada
    bool c = false;             //flag caso a opção -c for usada
    vector <string> textfiles;  //local para amazenar os nomes e/ou local dos textos

    // estrutura para definir as expressões longas
    const struct option longopts[] =
    {
        {"help",        no_argument,        0,  'h'},
        {"edit",        required_argument,  0,  'e'},
        {"pattern",     required_argument,  0,  'p'},
        {"algorithm",   required_argument,  0,  'a'},
        {"count",       no_argument,        0,  'c'}
    };
    int index;
    //tratando e pegando todas opções
    for (int opt = getopt_long(argc, argv, "he:pa:c",longopts,&index); opt != -1;
     opt = getopt_long(argc, argv, "he:pa:c",longopts,&index))
    {
        
        switch (opt)
        {

        case 'e':
            emax = (int)std::strtol(optarg, &char_part, 10);
            if(emax<=0){
                cout<< "-e: o valor do argumento tem que ser maior que 0.";
            } 
            if(string(char_part) != ""){
                cout << "'-e': argumento invalido" <<endl;
                exit(0);
            }

            break;

        case 'p':

            p = true;
            break;

        case 'a':

            algorithm = optarg;
            a = true;
            break;

        case 'c':

            c = true;
            break;

        case 'h':
            help_msg();
            exit(0);
            break;

        default:
            
            cout << "-" << (char)opt <<" nao e uma opcao valida!" << endl;
            exit(0);
            break;
        
        }
    }

    if(optind<argc){
        pattern = argv[optind];
        optind++;
    }
    else{
        cout << "Esta faltando argumentos" << endl;
        exit(0);
    }   
    
    for(;optind < argc;optind++){
        textfiles.push_back(argv[optind]);
    }
    if(textfiles.size() == 0){
        cout <<"Esta faltando argumentos" << endl;
        exit(0);
    }
    
    pmt(emax,p,a,c,pattern,algorithm,textfiles);

}

int main(int argc, char *argv[])
{
    interface(argc,argv);
}


