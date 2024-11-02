--[[
ler um numero n
criar e preencher dois vetores de 0 a n
somar cruzada em outro vetor: soma de um de 0 a n com o oposto de n a 0
exibir vetor resultante 
--]]
local metatabela = {
    __newindex = function(tabela, chave, valor)
        -- Verifica se a chave é uma string válida
        if type(chave) ~= "string" then --chave tem que ser string
            error("chave deve ser uma string") --se nao for da erro
        end

        -- Se a chave ainda não existir na tabela
        if rawget(tabela, chave) == nil then --rawget acessa o campo passado sem engatilhar o __index, podendo assim ver se o campo passado é nulo
            print("adicionando nova chave: " .. chave)
            rawset(tabela, chave, {}) -- adiciona ou altera um campo de uma tabela de forma direta, sem o engatilhamento do metodo __index
        end
        
        -- Verifica se o valor é do tipo esperado (neste caso, um número)
        if type(valor) ~= "number" then --type diz qual o tipo de dado presente em uma variavel
            error("valor deve ser um número")
        end

        -- Adiciona o valor à tabela correspondente à chave
        table.insert(tabela[chave], valor) --função que recebe parametros, e insere o valor dado no ponto da tabela informado ou no final caso nao seja informado uma posição
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


local function exibir(vetor, controle)
    local num2=controle;
    local i =1;
    os.execute("clear")
    while num2>=1 do --uma variavel vai de 1 a n e outra vai de n a 1
       io.write(vetor[3][i].." eh a soma de >"..vetor[1][i].."< + >"..vetor[2][num2].."<\n"); --mesma aritimetica da soma
       i=i+1;
       num2=num2-1;
    end
    print("\n")
end

local function soma(vetor, controle) --fazer a soma
--soma
local num2=controle;
local i =1;
    while num2>=1 do
        if vetor[1][i] ~=nil and vetor[2][num2]~=nil then --se os vlaores nos indices não forem nulos, 
            vetor[3][i]=vetor[1][i]+vetor[2][num2]; --faz a opração cruzada, primeiro com ultimo do outro e assim vai
        else
            print("erro de indice em vetor[1]["..i.."] ou vetor[2]["..num2.."]");
            return;
        end
        i=i+1;
        num2=num2-1;
    end
end

local function preencher(vetor, controle)
    print("preencher***");
    for i=1, 2 do
        print("*** fileira "..i.."***")
        for j=1, controle do
            --ler os numeros das duas fileiras
            io.write("insira "..j.."º elemento: ");
            local aux=0;                           --zera a variavel auxiliar
            aux=io.read("n");
            if aux~=nil then                       --se o valor da variavel auxiliar nao for 0, transfere pro vetor
                vetor[i][j]=aux;
                                                 --io.write("\n echo: "..vetor[i][j].."\n");
            else
                j=j-1;  
                io.write("inserir"..j.."novamente");
            end
        end
    end
end
local function main()

    local controle=0;--controle para numero de colunas
    local vetor=setmetatable({}, metatabela);--confuso
    io.write("insira tamanho dos array: ");
    controle=io.read("n");
    os.execute("clear");--limpar tela
    preencher(vetor, controle)
    soma(vetor, controle);
    exibir(vetor, controle);
    
end
main()