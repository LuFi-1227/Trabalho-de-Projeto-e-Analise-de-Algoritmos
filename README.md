# Verificar Tempo que código leva para rodar em C:
Obs.: Feito no UBUNTU, mas roda em qualquer Linux;
## Escrita de código:
- Não é novidade para ninguém que se deve escrever o código para se verificar em quanto tempo ele roda. Isto é o básico que se deve saber para que se escreva bons algoritmos, por isso, escreva seu arquivo main.c da forma como desejar testá-lo.

## Compilar o Código:
- O próximo passo é compilar o seu arquivo main.c em um arquivo que possa ser executado, neste caso, basta digitar:
```
    g++ main.c
```
- Este comando vai compilar o código e gerar na sua pasta um arquivo chamado "a.out" que poderá ser executado pelo sistema, conforme seu código. Feito isso, basta ver o próximo passo.

## Testar o tempo que o código leva para terminar:
- Por fim, basta digitar no seu terminal a palavra "time" seguida do arquivo que seu sistema operacional deve executar, da seguinte forma:
```
    time ./a.out
```
- Observe que "a.out" foi o arquivo que compilamos anteriormente, e a depender de como você compilou seu arquivo, o nome do executável pode necessitar ser modificado para teste.
- Por fim, você vai perceber no eu terminal a impressão de quanto tempo o código lecou para rodar.