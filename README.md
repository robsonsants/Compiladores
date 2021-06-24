# 🚀 Robson Santos - Compiladores - Flex Bison - LOONEY TUNES🚀 
Linguagem de programação LOONEY TUNES que está sendo desenvolvida na disciplina de compiladores.

# MARCADORES DE INICIO E FIM DE PROGRAMA 

```
start
	#código
      	#….
end
```
# COMENTÁRIOS

#para fazer um comentário, adicione um # no início da linha que deseja comentar

# TIPOS E DECLARAÇÕES DE VARIÁVEIS

inteiro: aceita um número inteiro


```
inteiro nota1, nota2 = 2
inteiro media 
inteiro nota = 10

```
real: aceita um número real

```
real nota1, nota2 = 8.0
real media 
real nota = 10.0

```

string: aceita uma string entre as "aspas"

```
string a, b =  "nome"
string teste = "nome"

```

vetor: aceita declarações dos tipos reais, inteiros e string

```
inteiro vetor[1]
real vetor[2]
string vetor[3]

```

# ATRIBUIÇÃO DE VALORES

Para fazer uma atribuição de valores adicione símbolo de igual depois da variável: "=".

```
int  nota1 = 10 
int nota2 = 9
soma = nota1 + nota2

```
# OPERAÇÃO DE ESCRITA 

Para escrever na tela é necessário usar o comando >>escreva

```
>>escreva ("sua media foi", media)
>>escreva (media)

```

# OPERAÇÃO DE LEITURA

Para receber informação na tela é necessário usar o comando <<leia

```
real num1
>>escreva "sua primeira nota"
num1 <<leia 

```
								   
# OPERAÇÕES MATEMÁTICAS

Para utilizar as operações matemáticas é necessário seguir os exemplos abaixo

```
>>escreva("Soma: ")
>>escreva(a + b)

>>escreva("Subtração: ")
>>escreva(a - b)

>>escreva("Multiplicação: ")
>>escreva(a * b)

>>escreva("Divisão: ")
>>escreva(a / b)

>>escreva("Exponenciação: ")
>>escreva(a ^ b)

>>escreva("Radiciação: ")
>>escreva(raiz(a))


```
# EXPRESSÕES MATEMÁTICAS E PRECEDÊNCIA

Parênteses, Exponenciação, Multiplicação e Divisão possui o mesmo grau de precedência.
Soma e subtração possui o mesmo grau de precedência.

```
TESTE = ((1+2)^(4*2)) 

```
# ESTRUTURAS CONDICIONAIS IF, IF ELSE E OPERADOR TERNARIO

IF

```
if>> (media >= 7.0){
    >>escreva("Aluno Aprovado.", "\n")
}
```

IF ELSE 

```
if>> (media >= 7.0){
    escreva("Aluno Aprovado.", "\n")
}
else>>{
  >>escreva("Aluno Reprovado")
}
```
O ternário funciona  como um if. Se n >= 0 então n++, se não n--.


```
>>escreva("Digite um numero")
<<leia(n)
numero >= 0 ? n++ : n--;
>>escreva(n)

```
# ESTRUTURAS DE REPETIÇÃO FOR, WHILE

FOR

```
for>> ( i=0; i<=10; i++) {
    <<leia(i)
}

```
WHILE 

```
while>>(a * a > b){  
      a-- 
      escreva("a", "\n")
    }

```

# FUNÇÃO


```
void function(){
  #... 
}

```
# 💻  EXEMPLO


💻  Os exemplos a seguir foi feito a partir de questão 1005 do URI

```
start 

real nota1, nota2, media

>>escreva("Escreva a primeira nota:", "\n")
<<leia(nota1)
>>escreva("Escreva a segunda nota:", "\n")
<<leia(nota2)

media = (( nota1 * 3.5 + nota2 * 7.5)/ (3.5 + 7.5))
>>escreva("MEDIA = ", media, "\n")

end

```
# 💻  EXEMPLO 2 
	
💻  O exemplo a seguir foi feito a partir para testar as estruturas de repetição
	
```
start 

inteiro a = 10
inteiro b = 2
inteiro c = 30

  if>>(a > b){ 
    while>>(a * a > b){  
      a-- 
      >>escreva("Valor a ", "\n")
    }
  }else>>{
    >>escreva("Valor b")
  }

  inteiro d 
  for>> (d = 1; d <= 10; d++) {  
    >>escreva(d, "\n")
  } 

end 

```
                                                                                                  
                                                                   
