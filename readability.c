#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float calcula_media_letras_palavras(float palavras, int letras);
float calcula_media_sentencas_palavras(float palavras, int sentencas);

int main()
{
    // Obter texto
    string texto = get_string("Digite o seu texto:\n");

    // Obter tamanho do texto digitado
    int tam_texto = strlen(texto);

    float total_palavras = 0;
    int total_sentenca = 0;
    int total_letras = 0;
    float indice = 0;

    // se algo foi digitado, então inicializar com 1 palavra
    if (tam_texto > 0)
    {
        total_palavras = 1;
    }

    for (int i = 0; i <= tam_texto - 1; i++)
    {
        // Separar as palavras
        if (texto[i] == 32)
        {
            total_palavras += 1;
        }
        // Separar as sentenças
        else if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            total_sentenca += 1;
        }
        // considera somente as letras, sem caracteres especiais ou outros
        else if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z'))
        {
            total_letras += 1;
        }
    }

    float media_letras_palavras = calcula_media_letras_palavras(total_palavras, total_letras);
    float media_sentenca_palavras = calcula_media_sentencas_palavras(total_palavras, total_sentenca);

    // Calcula o nível de acordo com a fórmula Coleman-Liau
    indice = round(0.0588 * media_letras_palavras - 0.296 * media_sentenca_palavras - 15.8);

    if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (indice < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", indice);
    }
}

float calcula_media_letras_palavras(float palavras, int letras)
{
    return (letras / palavras) * 100;
}

float calcula_media_sentencas_palavras(float palavras, int sentencas)
{
    return (sentencas / palavras) * 100;
}
