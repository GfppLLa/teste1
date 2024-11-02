--[[
ler n numero de elementos em dois vetores
preencher os vetores
fazer soma de vetor um e dois onde 0 pra n
solicitar inteiro para definir o maximo de colunas na exibição
adaptar e exibir matrix dessa forma
Mapa:
    4. exibir
    3. somar
    2. preencher
    1. main
--]]
local function setTextColor(color)
    local colors = {
        reset = "\27[0m",
        red = "\27[31m",
        green = "\27[32m",
        yellow = "\27[33m",
        blue = "\27[34m",
        magenta = "\27[35m",
        cyan = "\27[36m",
        white = "\27[37m"
    }
    return colors[color] or colors.reset
end
local metatabela = {
    __newindex = function(tabela, chave, valor)
        if type(chave) ~= "string" then
            error("A chave deve ser uma string")
        end
        if type(valor) ~= "number" then
            error("O valor deve ser um número")
        end
        rawset(tabela, chave, valor)  -- Armazena diretamente o valor--função que recebe parametros, e insere o valor dado no ponto da tabela informado ou no final caso nao seja informado uma posição
    end,
    __index = function(tabela, chave)
        -- Retorna uma tabela vazia se a chave não existir
        if rawget(tabela, chave) ==nil then 
            --print("chave não encontrada: " .. chave.." criando chave");
            rawset(tabela, chave, {});
        end
        return rawget(tabela, chave);
    end
}--cria uma tabela vazia e associa a metatabela a ela, aplicando os comportamentos definidos
local function exibir(vetor, controle) --total /colunas
    local superVetor=setmetatable({}, metatabela)
    local linhasA=0.0
    local linhasB=0
    --linhasA=controle["elementos"]/controle["colunas"]
    linhasB=controle["colunas"]--math.ceil(linhasA)
    local k=1--controle dos indices do vetor de saida
        for i =1, controle["elementos"] do--percorre o total de elemtos
            --for j=1, linhasB do--percorre o total de colunas
                io.write(" ")io.write(vetor[3][i])
                if k==linhasB then
                    io.write("\n")
                    k=0
                end
                i=i+1
                k=k+1
               
            --end
            
        end
        print("")
end
local function soma(vetor, controle)
    local i=1
    while i<=controle["preencher"] do
        if vetor[1][i] ~= nil and vetor [2][i]~=nil then
            vetor[3][i]=vetor[1][i]+vetor[2][i]
            if controle["elementos"]==nil then
                controle["elementos"]=1
            else

                controle["elementos"]=controle["elementos"]+1
            end
        else
            error("algum dos vetores na soma esta vazio", 4)
        end
        i=i+1
    end
end

local function preencher(vetor, controle)
    print("preencher")
    local forfor =tonumber(controle["preencher"])
    print(controle["preencher"])
    for i=1, 2 do
        print(i.."º fileira\n")--imprimir fileira
        for j=1, forfor do
            local aux=0
            io.write("\ninsira o "..j.."º elemento: ")
            aux=io.read("n")
            if(aux==nil) then
                j=j-1
                print("inserir valor valido")
            else
                vetor[i][j]=aux;
            end
        end
    end
end
local function main()
    local vetor=setmetatable({}, metatabela)
    local controle=setmetatable({}, metatabela)
    controle["elementos"]=0--inicializa o indice em zero para evitar situações desagradaveis
    print("inserir numero de elementos dos vetores: ")
    local entrada = io.read()
    local numero = tonumber(entrada)  -- Converte a entrada para número

if numero then  -- Verifica se a conversão foi bem-sucedida
    controle["preencher"] = tonumber(numero)
    print("Número "..numero.. " de elementos a serem preenchidos:", controle["preencher"])
else
    print("Erro: A entrada deve ser um número válido.")
end
    --controle["preencher"]=io.read("n");

    local status, err=pcall(function() --argumentos, por função e nao apenas o nome da funcao
        preencher(vetor, controle)
        end)
        if not status then
            print(setTextColor("red").."erro ao executar a funcao preencher: ",err,setTextColor("reset"))
            os.exit()
        end

        local status2, err2=pcall(function() --argumentos, por função e nao apenas o nome da funcao
            soma(vetor, controle)
            end)
            if not status2 then
                print(setTextColor("red").."erro ao executar a funcao soma: ",err2,setTextColor("reset"))
                os.exit()
            end

    print("numero de colunas a serem exibidas: ")
    controle["colunas"]=io.read("n");

        local status3, err3=pcall(function() --argumentos, por função e nao apenas o nome da funcao
            exibir(vetor, controle)
            end)
            if not status3 then
                print(setTextColor("red").."erro ao executar a funcao soma: ",err3,setTextColor("reset"))
                os.exit()
            end


end

main();