#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define NONE      "\033[0m"
#define RED       "\x1b[31m"
#define GRAY      "\e[0;37m"
#define BLACK     "\033[30m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"

#define func bubleSort

long int compMerge = 0, trocMerge = 0;
long int compQuick = 0, trocQuick = 0;
long int compHeap = 0, trocHeap = 0;

void printVetor(int *A, int n){
    printf("[");
    for(int i=0; i<n-1; i++){
        printf("%d, ", A[i]);
    }
    printf("%d]", A[n-1]);
}

void printFunc(long int comp, long int troc){
    printf(BLUE "Numero de comparações feito: %ld\n",comp);
    printf("Numero de trocas feito: %ld\n" NONE, troc);
}

void bubleSort(int *A, int n){
    printf(YELLOW "\n\n\nExecução do BubleSort\n\n\n" NONE);
    long int comp = 2;
    long int troc = 0;
    for(int i=0; i<n; i++){
        comp++;
        for(int j=n; j>i; j--){
            comp++;
            if(A[j]<A[j-1]){
                int aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                troc++;
            }
            comp++;
        }
    }
    printFunc(comp, troc);
}

void selectionSort(int* A, int n){
    printf(YELLOW "\n\n\nExecução do selection sort\n\n\n" NONE);
    int smallest = 0;
    long int comp = 2;
    long int troc = 0;
    for(int i=0; i<n-1; i++){
        comp++;
        smallest = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[smallest]){
                smallest = j;
            }
            comp++;
        }
        int aux = A[smallest];
        A[smallest] = A[i];
        A[i] = aux;
        troc++;
    }
    printFunc(comp, troc);
}

void insertionSort(int* A, int n){
    printf(YELLOW "\n\n\nExecução do Insertion Sort\n\n\n" NONE);
    long int comp = 1;
    long int troc = 0;
    for(int j=1; j<n; j++){
        comp++;
        int key = A[j];
        int i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
            comp = comp+2;
        }
        A[i+1] = key;
        troc++;
    }
    printFunc(comp, troc);
}

void merge(int arr[], int left, int mid, int right) {
    long int comp = 6;
    long int troc = 0;
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++){
        comp++;
        leftArr[i] = arr[left + i];
        troc++;
    }
    for (j = 0; j < n2; j++){
        comp++;
        rightArr[j] = arr[mid + 1 + j];
        troc++;
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            troc++;
            i++;
        }
        else {
            arr[k] = rightArr[j];
            troc++;
            j++;
        }
        comp+=3;
        k++;
    }
    while (i < n1) {
        comp++;
        arr[k] = leftArr[i];
        troc++;
        i++;
        k++;
    }
    while (j < n2) {
        comp++;
        arr[k] = rightArr[j];
        troc++;
        j++;
        k++;
    }
    compMerge += comp;
    trocMerge += troc;
}

void mergeSort1(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort1(arr, left, mid);
        mergeSort1(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int left, int right) {
    printf(YELLOW "\n\n\nExecução do Merge Sort\n\n\n" NONE);
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort1(arr, left, mid);
        mergeSort1(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    printFunc(compMerge, trocMerge);
}

void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
    trocQuick++;
}

int particiona(int vet[], int inicio, int fim){
	int pivo, pivo_indice, i;
	pivo = vet[fim];
	pivo_indice = inicio;
	compQuick++;
	for(i = inicio; i < fim; i++)
	{
		if(vet[i] <= pivo)
		{
			troca(vet, i, pivo_indice);
			pivo_indice++;
		}
        compQuick +=2;
	}
    troca(vet, pivo_indice, fim);
	return pivo_indice;
}

int particiona_random(int vet[], int inicio, int fim){
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	troca(vet, pivo_indice, fim);
	return particiona(vet, inicio, fim);
}

void quick_sort1(int vet[], int inicio, int fim){
	if(inicio < fim){
		int pivo_indice = particiona_random(vet, inicio, fim);
		quick_sort1(vet, inicio, pivo_indice - 1);
		quick_sort1(vet, pivo_indice + 1, fim);
	}
    compQuick++;
}

void quick_sort(int vet[], int inicio, int fim)
{
    printf(YELLOW "\n\n\nExecução do Quick Sort\n\n\n" NONE);
	if(inicio < fim)
	{
		int pivo_indice = particiona_random(vet, inicio, fim);
		quick_sort1(vet, inicio, pivo_indice - 1);
		quick_sort1(vet, pivo_indice + 1, fim);
	}
    compQuick++;
    printFunc(compQuick, trocQuick);
}

void sorteiaVetorAleatorio(int n){
    char string[100];
    srand(time(NULL));
    sprintf(string, "vetor de %d posicoes.txt", n);
    FILE *F = fopen(string, "w+");
    for(int i=0; i<n; i++){
        char *num = (char*)malloc(sizeof(char)*20);
        sprintf(num, "%d\n", rand()%100);
        fprintf(F, "%s", num);
    }
    fclose(F);
}

void preencheVetor(int *V, int n){
    char string[100];
    char num[20];
    sprintf(string, "vetor de 100000 posicoes.txt");
    FILE *F = fopen(string, "r");
    for(int i=0; i<n-1; i++){
        fgets(num, 20, F);
        V[i] = atoi(num);
    }
    fclose(F);
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
        compHeap+=2;
		if (raiz*2 == fundo) {
            compHeap++;
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
            compHeap++;
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
        compHeap++;
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
        trocHeap++;
    }
	else {
      pronto = 1;
	}
  }
}

void heapsort(int *vet, int n) {
    printf(YELLOW "\n\n\nExecução do Heap Sort\n\n\n" NONE);
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
        compHeap++;
		peneira(vet, i, n - 1);
	}
    compHeap++;

	for (i = n-1; i >= 1; i--) {
        compHeap++;
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
        trocHeap++;
		peneira(vet, 0, i-1);
	}
    compHeap++;
    printFunc(compHeap, trocHeap);
}

int main(){
    int vet[] = {1000, 10000, 50000, 100000};
    clock_t t; //Variável que recebe o tempo inicial
    int *vetor = (int*)malloc(sizeof(int)*(vet[0]));
    sorteiaVetorAleatorio(100000); //Sorteio será feito com valor máximo de elementos

    int TAM; //Definição do tamanho do vetor
    printf(RED "Vetor desordenado:\n\n" NONE);
    for(int i=0; i<4; i++){
        TAM = vet[i];
        if(i>0){
            vetor = (int*)realloc(vetor, sizeof(int)*TAM);
        }

        preencheVetor(vetor, TAM);

        t = clock();
        //printVetor(vetor, TAM);
        func(vetor, TAM);
        //printVetor(vetor, TAM);
        t = clock() - t;

        printf(GREEN "\n\nTempo de execucao para vetor de %d posicoes: %lf milisegundos\n\n" NONE, TAM, ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    }

    printf(RED "Vetor Crescente:\n\n" NONE);
    for(int i=0; i<4; i++){
        TAM = vet[i];
        vetor = (int*)realloc(vetor, sizeof(int)*TAM);

        for(int j=0; j<TAM; j++){
            vetor[j] = j;
        }

        t = clock();
        //printVetor(vetor, TAM);
        func(vetor, TAM);
        //printVetor(vetor, TAM);
        t = clock() - t;

        printf(GREEN "\n\nTempo de execucao para vetor de %d posicoes: %lf milisegundos\n\n" NONE, TAM, ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    }

    printf(RED "Vetor Decrescente:\n\n" NONE);
    for(int i=0; i<4; i++){
        TAM = vet[i];
        vetor = (int*)realloc(vetor, sizeof(int)*TAM);

        int k=0;
        for(int j=TAM; j>=0; j--){
            vetor[k] = j;
            k++;
        }

        t = clock();
        //printVetor(vetor, TAM);
        func(vetor, TAM);
        //printVetor(vetor, TAM);
        t = clock() - t;

        printf(GREEN "\n\nTempo de execucao para vetor de %d posicoes: %lf milisegundos\n\n" NONE, TAM, ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    }
}