# Sistema DataJud Interativo

Programa em C que lê uma base de processos judiciais do **TJDFT**, extraída do [DataJud](https://www.cnj.jus.br/sistemas/datajud/) (base nacional de dados do Poder Judiciário, mantida pelo CNJ), e responde perguntas sobre esses dados por meio de um menu interativo no terminal.

Projeto acadêmico desenvolvido no curso de Ciência da Computação da Universidade Católica de Brasília (UCB).

## O que o sistema faz

Ao iniciar, o programa carrega o arquivo `data/TJDFT_filtrado.csv` em memória e oferece as seguintes consultas:

- Último órgão julgador de um processo
- Processo com a data de recebimento mais antiga
- Quantidade de processos por tipo de causa: violência doméstica, feminicídio, causas ambientais, quilombolas, indígenas e infância e juventude
- Duração de um processo, em dias, calculada a partir das datas de recebimento e de resolução
- Percentual de cumprimento da Meta 1 do CNJ
- Exportação dos processos julgados para um novo arquivo CSV

## Como compilar e executar

Pré-requisito: compilador C (gcc ou clang).

```bash
gcc main.c processo.c -o datajud
./datajud
```

O arquivo `TJDFT_filtrado.csv` precisa estar dentro da pasta `data/`.

## Estrutura

```
├── data/          # base de processos do TJDFT (CSV)
├── main.c         # loop principal e menu
├── processo.h     # struct Processo e declarações das funções
└── processo.c     # leitura do CSV, consultas e cálculos de datas
```

## Conceitos praticados

- Leitura e parsing de arquivo CSV em C
- `struct` para modelar os registros e alocação dinâmica de memória
- Cálculo de intervalos entre datas, incluindo anos bissextos
- Modularização com arquivos `.h` e `.c`
