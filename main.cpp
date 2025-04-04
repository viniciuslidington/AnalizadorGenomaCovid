#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Estrutura para armazenar cada segmento e sua contagem
struct TabelaNodo {
    string segmento;
    int frequencia;
};

// Classe da Tabela Hash usando encadeamento externo
class TabelaHash {
private:
    static const int TAMANHO_TABELA = 10007; // Tamanho primo para reduzir colisões
    vector<list<TabelaNodo>> tabela;

    // Função de espalhamento usando método de Horner
    int funcaoEspalhamento(const string& segmento) {
        int hash = 0;
        for (char caractere : segmento) {
            hash = (hash * 31 + caractere) % TAMANHO_TABELA;
        }
        return hash;
    }

public:
    TabelaHash() : tabela(TAMANHO_TABELA) {}

    void inserir(const string& segmento) {
        int indice = funcaoEspalhamento(segmento);
        for (auto& nodo : tabela[indice]) {
            if (nodo.segmento == segmento) {
                nodo.frequencia++;
                return;
            }
        }
        tabela[indice].push_back({segmento, 1});
    }

    void escreverArquivo(const string& nomeArquivo) {
        ofstream arquivo(nomeArquivo);
        if (!arquivo) {
            cerr << "Erro ao abrir arquivo de saída!" << endl;
            return;
        }
        for (const auto& balde : tabela) {
            for (const auto& nodo : balde) {
                arquivo << nodo.segmento << " " << nodo.frequencia << endl;
            }
        }
        arquivo.close();
    }
};

// Função para processar o arquivo do genoma
void processarArquivoGenoma(const string& nomeEntrada, const string& nomeSaida) {
    ifstream arquivo(nomeEntrada);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo do genoma!" << endl;
        return;
    }

    TabelaHash tabelaHash;
    string linha;

    while (getline(arquivo, linha)) {
        if (linha.size() < 60) continue; // Ignora a última linha incompleta

        for (size_t i = 0; i + 6 <= linha.size(); i += 6) {
            string segmento = linha.substr(i, 6);
            tabelaHash.inserir(segmento);
        }
    }

    arquivo.close();
    tabelaHash.escreverArquivo(nomeSaida);
}

void criarArquivoSaidaSeNaoExistir(const string& nomeArquivo) {
    ifstream arquivoTeste(nomeArquivo);
    if (!arquivoTeste) { // Arquivo não existe
        ofstream novoArquivo(nomeArquivo);
        if (!novoArquivo) {
            cerr << "Erro ao criar o arquivo de saída!" << endl;
            return;
        }
        novoArquivo.close();
    }
}

int main() {
    string nomeArquivoEntrada = "genoma.txt";  // Arquivo de entrada
    string nomeArquivoSaida = "saida.txt"; // Arquivo de saída

    // Verifica se o arquivo de saída já existe e cria se não existir
    criarArquivoSaidaSeNaoExistir(nomeArquivoSaida);
    // Processa o arquivo de genoma
    processarArquivoGenoma(nomeArquivoEntrada, nomeArquivoSaida);

    cout << "Processamento concluído! Verifique o arquivo " << nomeArquivoSaida << endl;
    return 0;
}
