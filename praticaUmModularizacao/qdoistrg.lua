--[[

### Exercício 2: Ciclo Trigonométrico
1. Leia um valor real R representando o ângulo em graus.
2. Implemente uma função que:
   - Calcule o número de voltas inteiras que o ângulo completa (R dividido por 360).
   - Determine o quadrante em que o ângulo se encontra.
3. Exiba o quadrante e o número de voltas no formato:
   ```
   QUADRANTE: <quadrante>
   QUANTIDADE DE VOLTAS: <número de voltas
   
   Q1 = 0 a 90, Q2= 90 a 180, Q3= 180 a 270, Q4= 270 a 360
   funcoes:
            lerNumero();
            calcularVoltar();
            calcularQuadrante();
            outEmTela();

--]]
local function calcularQuadrante(voltas)

end

local function calcularVoltas(voltas)
    if voltas.vUm>360 then
        voltas.vUm =voltas.vUm-360;
    end
end
local function lerNumero(voltas)
    print("ler numero de votas: ")
    while 1 do
        ::continue::
        io.write("\ninserir numero: ");
        local temp =0.0;
        temp=io.read("*n");--ler numero
        if temp <0.1 and temp <=1000000.1 then
            voltas.vUm = temp;
            break;
        else
            goto continue
        end        
    end
end
local function main()
    local voltas ={vUm =0.0, quadrante =0}

end
