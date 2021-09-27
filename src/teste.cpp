#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void ler(vector <int>& arr){
    std::ifstream mapa;
    std::string linha;
    std::string matriz;
    std::string token;
    int p =0;
    mapa.open("../map/tileMap.txt",std::ios::in);
    if(mapa.is_open()){
        int mPos;
        while(std::getline(mapa,linha)){
            matriz += linha;
        }
    }
    //cout << matriz << endl;
    while((p = matriz.find(",")) != std::string::npos){
        token = matriz.substr(0,p);
        arr.push_back(stoi(token));
        //std::cout << token << std::endl;
        matriz.erase(0,p+1);
    }
    
    //std::cout << matriz << std::endl;
}

int main(){
    vector <int> arr;
    ler(arr);
    arr.erase(arr.begin(),arr.begin()+3);
    for(int i=0; i< 3;++i){
        cout << arr[i] << endl;
    }
    return 0;
}