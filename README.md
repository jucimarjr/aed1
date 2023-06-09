# Padrão de Codificação em C

Este documento define um padrão de codificação em linguagem C que visa promover a legibilidade, organização e clareza do código. O padrão segue as boas práticas amplamente adotadas na comunidade de desenvolvimento em C.

## Nomenclatura de Arquivos

- Utilize letras minúsculas para o nome do arquivo.
- Separe as palavras com underscores ("_") para maior clareza e legibilidade.
- O nome do arquivo deve refletir o propósito ou conteúdo do código contido nele.

Exemplo: `meu_programa.c`, `utilidades_matematicas.c`

## Comentário de Identificação

- Cada arquivo de código deve começar com um comentário de identificação.
- O comentário deve conter informações como o nome do curso, disciplina, nome completo do aluno e sua matrícula.

Exemplo:
```c
/* 
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados
   Aluno: Caio Rolando da Rocha
   Matrícula: 123456789
*/
```

## Função `main`

- Utilize a seguinte assinatura para a função `main`: `int main(int argc, char *argv[])`.

Exemplo:
```c
int main(int argc, char *argv[])
{
    // Código da função main

    return 0;
}
```

## Nomenclatura de Variáveis e Funções

- Utilize letras minúsculas para o nome das variáveis e funções.
- Separe as palavras com underscores ("_") para maior clareza e legibilidade.
- Escolha nomes descritivos e significativos que indiquem claramente o propósito ou conteúdo da variável ou função.
- Evite nomes genéricos, como `x`, `temp`, `var1`, pois eles não fornecem informações suficientes sobre o uso da variável ou função.
- Seja consistente no uso de singular ou plural para nomes de variáveis, dependendo do contexto.
- Evite o uso de abreviações excessivas que possam comprometer a clareza do código.

Exemplo (variáveis):
```c
int idade;
float preco_unitario;
char nome_completo[50];
```

Exemplo (funções):
```c
void calcular_media();
int obter_tamanho_array(int[] array);
```

## Nomenclatura de Constantes e Defines

- Utilize letras maiúsculas para o nome das constantes e defines.
- Separe as palavras com underscores ("_") para maior clareza e legibilidade.
- Escolha nomes descritivos e significativos que indiquem claramente o propósito ou valor da constante ou define.

Exemplo:
```c
#define TAMANHO_MAXIMO 100
const float PI = 3.14159;
```

## Chaves de Delimitação de Código

- Utilize as chaves `{}` somente quando houver mais de uma instrução dentro de um bloco de código.
- Coloque as chaves em uma nova linha, logo abaixo da instrução que as precede.
- Utilize uma linha em branco antes e depois das chaves para separar claramente o bloco de código.

Exemplo (uma instrução):
```c
if (idade >= 18)
    printf("Você é maior de idade.\n");
```

Exemplo (várias instruções):
```c
for (int i = 0; i < tamanho; i++)
{
    printf("%d\n", array[i]);
    printf("Iteração %d\n", i);
}
```

## Definição de Vetor

- Os colchetes `[]` devem ser colocados do lado direito do nome da variável ao definir um vetor.

Exemplo:
```c
int numeros[10];
float matriz[3][3];
```

## Instruções de Controle (if, for, while)

- Utilize espaços entre os elementos para melhorar a legibilidade do código.
- Coloque os parênteses em torno da condição das instruções `if` para maior clareza.
- Utilize chaves `{}` somente quando houver mais de uma instrução dentro do bloco.

Exemplo (if):
```c
if (idade >= 18)
    printf("Você é maior de idade.\n");
else
    printf("Você é menor de idade.\n");
```

Exemplo (for):
```c
for (int i = 0; i < tamanho; i++)
    printf("%d\n", array[i]);
```

Exemplo (while):
```c
while (contador < limite)
{
    printf("Contador: %d\n", contador);
    contador++;
}
```

## Linhas em Branco

- Utilize linhas em branco para separar claramente blocos de código relacionados.
- Adicione uma linha em branco entre declarações de variáveis, funções, instruções de controle (if, for, while) e blocos de código relacionados.
- Isso ajuda a melhorar a legibilidade e a clareza do código, tornando-o mais organizado e fácil de entender.

Exemplo:
```c
int idade;

void calcular_media()
{
    // Implementação da função calcular_media
}

if (idade >= 18)
    printf("Você é maior de idade.\n");
else
    printf("Você é menor de idade.\n");
```

## Comentários

- Utilize comentários para explicar o propósito e o funcionamento do código.
- Adicione comentários relevantes em trechos de código complexos, algoritmos importantes ou partes obscuras que possam dificultar a compreensão.
- Mantenha os comentários atualizados conforme o código for evoluindo e mudando.

Exemplo:
```c
// Calcula a média dos elementos do vetor
float calcular_media(int vetor[], int tamanho)
{
    // Variável para armazenar a soma dos elementos
    int soma = 0;

    // Itera sobre o vetor e soma os elementos
    for (int i = 0; i < tamanho; i++)
        soma += vetor[i];

    // Calcula a média e retorna o valor
    float media = (float)soma / tamanho;
    
    return media;
}
```

Esse padrão de codificação segue as melhores práticas para escrever código em linguagem C, tornando-o mais legível, organizado e fácil de manter.
