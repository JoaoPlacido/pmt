
# PMT

Pmt é uma ferramenta para busca de padrões num arquivo ou um conjunto de arquivos,
similar ao [GNU grep](http://www.gnu.org/software/grep/) com interface em linha de
comando(*command line interface - CLI*).





## Instalação
Abra o terminal no diretorio **/pmt/src** e digite o comando:
```
$ make install
```
Após a instalação, o executavel vai se encontrar em um diretorio recem criado **/bin** no diretorio **/pmt**.

Para que o pmt possa rodar em qualquer diretorio, basta colocar o executavel em um diretorio pertencente a **PATH** do sistema,
ou colocar o diretorio em que ele se localiza com parte do **PATH**([link](https://duzeru.org/pt/blog/como-definir-a-variavel-path-no-linux)).

Também pode usar:
```
$ PATH="$PATH:<caminho/para/bin>"
```
Esse metodo so funciona até o terminal ser fechado, caso isso aconteça basta reescrever o comando.
## Uso
Sua sintaxe básica deve ser:
```
$ pmt [options] pattern textfile [textfile...]
```
Fazendo que o padrão *pattern* seja procurado no(s) arquivo(s)
textfile.

## Opções

**-e, --edit *emax*:** Localiza todas as ocorrências aproximadas
do padrão a uma distância de edição máxima *emax*.

**-p, --pattern:** Trata o argumento *pattern* como um arquivo
e realiza uma busca em todos os padrões contido nele.(O arquivo deve ter um padrão por linha).

**-a, --algorithm algorithm_name:** Realiza a busca de padrão
usando o algoritmo. Use -h/--help para ver a lista de algoritmos.

**-c, --count:** Imprime apenas a quantidade total de ocorrências
do(s) padrão(ões) contidas no(s) arquivo(s) de texto.
