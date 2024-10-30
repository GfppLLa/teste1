--[[
comentarios 

receber a b e c
se a = 0 sair
calcular_raizes func()
a maior que 0 e menor que 10.0
b <= -1000.0
c <= 1000.0

\/
raizQuadrada();//calcular raiz
discriminantes();//calcular o discriminante
obterRAizes();//calcular raiz x1 e x2
obeterValores();//obter a,b e c
main();//main

__index = ação padrao quando algo nao ta deifinido na metatabela
setmetatable=concatena {[tabela], [outra tabela]}
--]]
local function raiz_quadrada(numero)
    local tolerancia =0.0000001;
    local chute = numero/2.0;
    local proximo_chute=0.0;
        while 1 do
            proximo_chute=0.5*(chute+(numero/chute));
            if ((chute - proximo_chute) < tolerancia and (chute - proximo_chute) > -tolerancia) then
                break;
            end
            chute=proximo_chute;
        end
    return chute;
end
local function discriminante(var)
    local retorno =0.0;
    retorno=((math.pow(var.B, 2))-(4 * (var.A * var.C)));
    if retorno<0 then
        --sair pos da erro
        error("discriminante nao pode ser negativo", 1)
    end
    return retorno;
end
    
local function obterRAizes(var, raizes) 

        --chamar calcular discriminante
        local varDiscriminante = 0.0;
        varDiscriminante=discriminante(var);

        --if
        if(varDiscriminante==-1) then
            error("impossivel calcular: disciminante -1",2)
  
        else
            local raiz_discriminante=raiz_quadrada(varDiscriminante);--raiz do discminante 
            raizes.Um = ((((-var.B)+raiz_discriminante)/(2*var.A))); --raiz um +
            raizes.Dois = ((((-var.B)-raiz_discriminante)/(2*var.A))); --raiz dois -
        end
end

local function obterValores(var)--passgaem de tabelas é referencia 
        while 1 do
            print("***inserir valores***")
                while 1 do
                    --inserir A
                    ::continue::
                    io.write("\ninerir A: ");
                    local varTemp=io.read("*n");
                        if varTemp<=0 then --se A for menor que 0
                            goto continue
                        else
                            if varTemp>1 then
                                --atribuir a var.A
                                var.A=varTemp;
                                break;
                            end
                        end
                end
                while 1 do
                    --inserir b
                    ::continuedois::
                    io.write("\ninserir B: ");
                    local varTemp=io.read("*n");
                        if varTemp <=-1000.0 or varTemp>=1000.1 then
                            -- mandar pro inico de inserir b 
                            goto continuedois
                        else 
                                --atribuir a var.b
                                var.B=varTemp;
                            break;
                        end 
                end
                while 1 do
                    --inserir C
                    ::continuetres::
                    io.write("\ninserir C: ");
                    local varTemp=io.read("*n");
                        if varTemp<=-1000.0 or varTemp>=1000.1 then
                            --mandar pro inicio de inserir B
                            goto continuetres;
                        else
                            var.C=varTemp;
                            break;
                        end
                end
                break;
        end
end
    

local function main()
--ler a,b e c
    local var={A=0.0, B=0.0, C =0.0} --unica estrutura é tabela
    local raizes={Um=0.0, Dois=0.0}
    --io.wrire()
    --=io.read()
    obterValores(var);
    obterRAizes(var, raizes);
    print("\n***saida:***");
    io.write("\nraiz um: "..raizes.Um);
    io.write("\nraiz Dois: "..raizes.Dois.."\n");
end
main();