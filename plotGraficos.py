import openpyxl

entradas = [1000, 10000, 50000, 100000]
algoritmosIndice = ["Buble Sort", "Selection Sort", "Insertion Sort", "Heap Sort", "Quick Sort", "Merge Sort"]
vetorIndice = ["vetorDesordenado", "vetorCrescente", "vetorDecrescente"]
tipoDado = ["trocas", "comparacoes", "tempo"]

algoritmos = {
    "Buble Sort" : {
        "vetorDesordenado": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorCrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorDecrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        }
    },

    "Insertion Sort" : {
        "vetorDesordenado": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorCrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorDecrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        }
    },

    "Selection Sort" : {
        "vetorDesordenado": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorCrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorDecrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        }
    },
    "Heap Sort" : {
        "vetorDesordenado": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorCrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorDecrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        }
    },
    "Quick Sort" : {
        "vetorDesordenado": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorCrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorDecrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        }
    },
    "Merge Sort" : {
        "vetorDesordenado": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorCrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        },
        "vetorDecrescente": {
            "trocas": [],
            "comparacoes": [],
            "tempo": []
        }
    }
}

workbook = openpyxl.open('Registros Trabalho de PAA.xlsx')

sheet = workbook.active
j = 0
k = 0
i = 0
for coluna in sheet:
    for celula in coluna:
        aux = str(celula).split(".")
        if aux[1].find("41")!=-1 or aux[1].find("42")!=-1 or aux[1].find("43")!=-1 or aux[1].find("44")!=-1 or aux[1].find("45")!=-1 or aux[1].find("46")!=-1:
            if aux[1].find("41")!=-1:
                i = 0
            elif aux[1].find("42")!=-1:
                i = 1
            elif aux[1].find("43")!=-1:
                i = 2
            elif aux[1].find("44")!=-1:
                i = 3
            elif aux[1].find("45")!=-1:
                i = 4
            elif aux[1].find("46")!=-1:
                i = 5
            if aux[1].find('B')!=-1 or aux[1].find('C')!=-1 or aux[1].find('I')!=-1 or aux[1].find('J')!=-1 or aux[1].find('P')!=-1 or aux[1].find('Q')!=-1 or aux[1].find('D')!=-1 or aux[1].find('K')!=-1 or aux[1].find('R')!=-1:
                if aux[1].find('C')!=-1 or aux[1].find('J')!=-1 or aux[1].find('Q')!=-1:
                    k=1
                elif aux[1].find('B')!=-1 or aux[1].find('I')!=-1 or aux[1].find('P')!=-1:
                    k=0
                elif aux[1].find('D')!=-1 or aux[1].find('K')!=-1 or aux[1].find('R')!=-1:
                    k = 2
                if aux[1].find('B')!=-1 or aux[1].find('C')!=-1:
                    j = 0
                elif aux[1].find('I')!=-1 or aux[1].find('J')!=-1:
                    j = 1
                elif aux[1].find('P')!=-1 or aux[1].find('Q')!=-1:
                    j = 2
                if type(celula) != None and celula.value != "None":
                    if str(celula.value).find("=CONCATENATE")!=-1:
                        string = str(celula.value).replace('","', "")
                        string = string.replace(")", "")
                        string = string.replace(",,", ",")
                        string = string.replace(" ", "")
                        string = string.replace("=CONCATENATE(", "")
                        string = string.split(",")
                        for B in string:
                            aux = sheet[B]
                            algoritmos[algoritmosIndice[i]][vetorIndice[j]][tipoDado[k]].append(float(aux.value))

print(algoritmos)
import matplotlib.pyplot as plt

for j in range(3):
    for i in range(3):
        for keys in algoritmos:
            plt.legend()
            plt.xticks(entradas)
            plt.plot(entradas, algoritmos.get(keys)[vetorIndice[i]][tipoDado[j]], label=str(keys), marker='o')
            plt.title(vetorIndice[i]+" "+tipoDado[j])
            plt.xlabel('Número de Entradas')
            plt.ylabel('Execução do algoritmo')
        plt.show()