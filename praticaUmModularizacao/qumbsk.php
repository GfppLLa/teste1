<?php
//### Exercício 1: Bhaskara
//1. Leia três valores de ponto flutuante: A, B e C.
//2. Implemente uma função `calcularRaizes` que:
//   - Verifique se A está entre 0.1 e 10.0 e se B e C estão entre -1000.0 e 1000.0.
//   - Se A for zero ou o discriminante (B² - 4AC) for negativo, exiba "Impossível calcular".
//   - Caso contrário, calcule as raízes reais com 5 casas decimais e exiba.
//3. Fórmula:  
//   \[
//   x_1 = \frac{-B + \sqrt{∆}}{2A}, \quad x_2 = \frac{-B - \sqrt{∆}}{2A}
//  \]  
//   onde ∆ = B² - 4AC.
//
function imprimirEmTela(&$raizUm, &$raizDois)
{
    echo"\nraiz um: ".$raizUm."\nraiz dois: ".$raizDois."\n";
}
function raizQuadrada(&$discriminante)
{
    $tolerancia = 0.0000001;
    $chute = $discriminante/2.0;
    $proximo_chute=0.0;
    while(1)
    {
        $proximo_chute =0.5*($chute+($discriminante/$chute));
        //pegar valor absoluto
        if (abs($chute - $proximo_chute) < $tolerancia && ($chute - $proximo_chute) > -$tolerancia)
        {
            break;
        }
        $chute=$proximo_chute;
    }
    return $chute;
}
function discriminante(&$varA,&$varB,&$varC)
{
    $discriminante=(pow($varB,2))-(4*($varA*$varC));
    return $discriminante;
}
function calcularRaizes(&$varA,&$varB,&$varC, &$raizUm,&$raizDois)
{
    $discriminante=discriminante($varA,$varB,$varC);
    $raiz_discriminante=raizQuadrada($discriminante);
    if($discriminante>=0)
    {
        //sair por sem improvavel
        echo ">discriminante nao pode ser 0<";
        exit();
    }

    $raizUm=(((-$varB)+$raiz_discriminante)/(2*$varA));
    $raizDois=(((-$varB)-$raiz_discriminante)/(2*$varA));
}

function obterValores(&$varA,&$varB,&$varC)
{
    $varAux=0.0;
    echo "\n***inserir valores***";
    while(1)
    {   
        while(1)   
        {
            echo"\n***inserir A: ";
            $varA=floatval(trim(fgets(STDIN)));
            if($varA>=0.1 && $varA<=10.0)
            {
                break;
            }else{$varA=0;echo"\n>nao pode ser zero<\n";}
        }
        while(1)
        {
            echo"\n****inserir B: ";
            //cast para float
            $varB=floatval(trim(fgets(STDIN)));
                if($varB <=-1000.0 || $varB >=1000.0)
                {
                    echo"\n>fora do intervalo<\n";
                    continue;
                }else{
                    break;
                }
        }
        while(1)
        {
            echo"\n****inserir C: ";
            $varC=floatval(trim(fgets(STDIN)));
                if($varC <=-1000.0 || $varC >=1000.0)
                {
                    echo"\n>fora do intervalo<";
                    continue;
                }else{
                    break;
                }
        }
        break;

    }
}
function main()
{
    $varA = 0.0;
    $varB = 0.0;
    $varC = 0.0;
    $raizUm =0.0;
    $raizDois =0.0;

    obterValores($varA,$varB,$varC);
    calcularRaizes($varA,$varB,$varC,$raizUm,$raizDois);
    imprimirEmTela($raizUm, $raizDois);


}
main();

?>