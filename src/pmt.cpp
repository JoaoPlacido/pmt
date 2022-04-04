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
    }

    if (p){
        try{
            patterns = get_pattern_list(pattern);
        }
        catch(...){
            cout << "Arquivo "<< pattern << " nao encontrado" << endl;
            exit(0);
        }
    }
    else{
        patterns.push_back(pattern);
    }
    // busca aproximada    
    if (emax > 0){
        
    }
    //busca exata   
    else{
        if(p){
            vector<vector<int>> go_to;
            vector<vector<int>> occ;
            vector<int> fails;
            vector<int> count((int)patterns.size(),0);
            build_fsm(patterns,go_to,occ,fails);
            for(int i = 0; i < (int)textfiles.size();i++){
                ifstream text(textfiles[i]);
                string line;
                for(int n_line = 1;!text.eof();n_line++){
                    getline(text,line);
                    int find = aho_corasick(line,count,go_to,occ,fails);
                    if(find>0 and !c){
                        cout << n_line << ":" << line << endl;
                    }
                }
            }
            if(c)for(int i = 0; i<(int)count.size();i++) cout<<patterns[i]<<":"<<count[i]<<endl;
        }
        else{
            //busca padrão
            int patlen = pattern.size();
            vector<int> lps(patlen,0);
            lpscompute(pattern,patlen,lps);
            int count = 0;
            for(int i = 0; i < (int)textfiles.size();i++){
                ifstream text(textfiles[i]);
                string line;
                for(int n_line = 1;!text.eof(); n_line++){
                    getline(text,line);
                    int linecount = kmp(line,pattern,lps);
                    if(linecount> 0 and !c){
                        cout << n_line << ":" << line << endl;
                    }
                    count += linecount;
                }
            }
            if (c) cout<<count<<endl;
        }
    }
}