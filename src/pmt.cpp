#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "pmt.hpp"
#include "algorithms/algorithms.hpp"

using namespace std;
using std::cout; using std::endl;
using std::cin; using std::string;

vector<string> get_pattern_list(string patternfile){
    string line;
    vector <string> patterns;
    ifstream file (patternfile);
    if(!file.is_open()) throw ("File not found");
    else{
        while(!file.eof()){
            getline(file,line);
            if(line.size()>0) patterns.push_back(line);
        }
        file.close();
        return patterns;
    }
    
}

void check_txtfiles(vector<string> textfiles){
    for (int i = 0; i< (int)textfiles.size();i++){
        ifstream file (textfiles[i]);
        if(!file.is_open()) throw(textfiles[i] + " nao foi encontrado!");
        file.close();
    }
}

void pmt(int emax, bool p, bool a,bool c, string pattern, string algorithm,vector<string> textfiles){
    
    //lista de patterns
    vector <string> patterns;

    //checar se dar pra abrir os txts
    try{
        check_txtfiles(textfiles);
    }catch(string erro){
        cout << erro << endl;
        exit(0);
    }

    //faz um lista de padroes com o arquivo dado
    if (p){
        try{
            patterns = get_pattern_list(pattern);
        }
        //caso o arquivo não exista ou possa ser acessado
        catch(...){
            cout << "Arquivo "<< pattern << " nao encontrado" << endl;
            exit(0);
        }
    }
    else{
        //bota o padrao dado sozinho na lista, para simplificar a chamada dos metodos dos algoritmos
        patterns.push_back(pattern);
    }

    //realizando busca com um algoritmo especifico
    if(a){
        if(algorithm == "kmp"){
            run_kmp(textfiles,patterns,c);
        }else if(algorithm == "ahocor"){
            run_aho_corasik(textfiles,patterns,c);
        }else if(algorithm == "sellers"){
            if(emax>0){
            run_sellers(textfiles,patterns,c,emax);
            }
            else{
                cout<<"por favor use a opcao -e/--edit para colocar o valor de erro maximo."<<endl;
                exit(0);
            }
        }else if(algorithm == "shift-or"){
            run_shift_or(textfiles,patterns,c);
        }else if(algorithm == "wu-manber"){
            if(emax>0){
            run_wu_manber(textfiles,patterns,c,emax);
            }
            else{
                cout<<"por favor use a opcao -e/--edit para colocar o valor de erro maximo."<<endl;
                exit(0);
            }
        }else{
            cout<<"O algoritmo "<< algorithm <<"não existe ou não foi implementado.";
            exit(0);
        }
    }
    //busca padrão
    else{
        //busca aproximada
        if(emax>0) run_sellers(textfiles,patterns,c,emax);
        //busca exata
        else{
            //caso for um mais de um padrão
            if(p) run_aho_corasik(textfiles,patterns,c);
            //caso for apenas um padrao
            else run_kmp(textfiles,patterns,c);
        }
    }    
}