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
            
            emax = std::strtol(optarg, &char_part, 10);
            
            if(char_part){
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


