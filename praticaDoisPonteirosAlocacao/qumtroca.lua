--[[
ler dois numeros 
enviar ponteiros pra uma função
trocar valores
devolver 
e imprimir trocados e originais
--]]
local function troca(numN)
    local aux=numN["numero1"];
    numN["numero1"]=numN["numero2"];
    numN["numero2"]=aux;
end
local function main ()
    local numN={};
    local mt= {
        __newindex=function (t, chave, valor)
            print("novo valor adicionado");
            rawset(t, chave, valor)
        end
    }
    io.write("\ninserir valor n1: ");
    numN["numero1"]=io.read("n");
    io.write("\ninserir valor n1: ");
    numN["numero2"]=io.read("n");
    print("\nnumeros originais: "..numN["numero1"].." e "..numN["numero2"]);
    troca(numN);
    print("\nnumeros alterados: "..numN["numero1"].." e "..numN["numero2"]);

end
main();